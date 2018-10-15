#include "std.h"

#include "emul.h"
#include "vars.h"
#include "dx.h"
#include "dxovr.h"
#include "dxerr.h"
#include "init.h"

static DWORD colorkey=-1U;

void update_overlay()
{

   RECT rc_src, rc_dst;

   GetClientRect(wnd, &rc_dst);
   ClientToScreen(wnd, (POINT*)&rc_dst.left);
   ClientToScreen(wnd, (POINT*)&rc_dst.right);

   if (rc_dst.left == rc_dst.right || rc_dst.top == rc_dst.bottom) return;

   rc_src.left = rc_src.top = 0;
   rc_src.right = LONG(temp.ox);
   rc_src.bottom = LONG(temp.oy);

   if (wnd == GetForegroundWindow() && rc_dst.left >= 0 && rc_dst.top >= 0)
   {
      DDSURFACEDESC desc; desc.dwSize = sizeof desc;
      if (sprim->IsLost() == DDERR_SURFACELOST)
          sprim->Restore();
      HRESULT r = sprim->Lock(nullptr, &desc, DDLOCK_SURFACEMEMORYPTR | DDLOCK_WAIT | DDLOCK_READONLY, nullptr);
      if (r != DD_OK) { printrdd("IDirectDrawSurface2::Lock() [test]", r); exit(); }
      char *ptr = (char*)desc.lpSurface + rc_dst.top*desc.lPitch + rc_dst.left*LONG(desc.ddpfPixelFormat.dwRGBBitCount)/8;
      colorkey = *(unsigned*)ptr;
      sprim->Unlock(nullptr);
      if (desc.ddpfPixelFormat.dwRGBBitCount < 32)
         colorkey &= (1<<desc.ddpfPixelFormat.dwRGBBitCount)-1;
   }

   // use min and max stretch
   DDCAPS caps;
   caps.dwSize = sizeof caps;
   dd->GetCaps(&caps,nullptr);
   if ((rc_dst.right - rc_dst.left)*1000/int(temp.ox) > (int)caps.dwMaxOverlayStretch)
      rc_dst.right = rc_dst.left + LONG(temp.ox*caps.dwMaxOverlayStretch/1000);
   if ((rc_dst.bottom - rc_dst.top)*1000/int(temp.oy) > (int)caps.dwMaxOverlayStretch)
      rc_dst.bottom = rc_dst.top + LONG(temp.oy*caps.dwMaxOverlayStretch/1000);
   if ((rc_dst.right - rc_dst.left)*1000/int(temp.ox) < (int)caps.dwMinOverlayStretch)
      rc_dst.right = rc_dst.left + LONG(temp.ox*caps.dwMinOverlayStretch/1000);
   if ((rc_dst.bottom - rc_dst.top)*1000/int(temp.oy) < (int)caps.dwMinOverlayStretch)
      rc_dst.bottom = rc_dst.top + LONG(temp.oy*caps.dwMinOverlayStretch/1000);

   // setup boundaries for non-clipping overlay
   int mx = GetSystemMetrics(SM_CXSCREEN), my = GetSystemMetrics(SM_CYSCREEN);
   if(rc_dst.left < 0)
   {
       rc_src.left = -rc_dst.left * (rc_src.right - rc_src.left) / (rc_dst.right - rc_dst.left);
       rc_dst.left = 0;
   }
   if(rc_dst.top < 0)
   {
       rc_src.top = -rc_dst.top * (rc_src.bottom - rc_src.top) / (rc_dst.bottom - rc_dst.top);
       rc_dst.top = 0;
   }
   if(rc_dst.right > mx)
   {
       rc_src.right = rc_src.left + (mx - rc_dst.left) * (rc_src.right - rc_src.left) / (rc_dst.right - rc_dst.left);
       rc_dst.right = mx;
   }
   if(rc_dst.bottom > my)
   {
       rc_src.bottom = (my - rc_dst.top) * (rc_src.bottom - rc_src.top) / (rc_dst.bottom - rc_dst.top);
       rc_dst.bottom = my;
   }

   if (colorkey==-1U) return;
   if (rc_dst.left >= rc_dst.right || rc_dst.top >= rc_dst.bottom) return;
   if (rc_src.left >= rc_src.right || rc_src.top >= rc_src.bottom) return;

   DDOVERLAYFX fx = { sizeof fx };
   fx.dckDestColorkey.dwColorSpaceLowValue = fx.dckDestColorkey.dwColorSpaceHighValue = colorkey;

   for (;;) {
      HRESULT r = surf0->UpdateOverlay(&rc_src, sprim, &rc_dst, DDOVER_SHOW | DDOVER_DDFX | DDOVER_KEYDESTOVERRIDE, &fx);
      if (r == DD_OK) break;
      if (r == DDERR_SURFACELOST) {
         if (surf0->Restore() != DD_OK) set_vidmode(); // recreate overlay
         break; // another update_overlay in set_vidmode() -> UpdateWindow()
      }
      printrdd("IDirectDrawSurface2::UpdateOverlay()", r); exit();
   }
}
