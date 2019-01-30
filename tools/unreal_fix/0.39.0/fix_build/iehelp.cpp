#include "std.h"

#include "emul.h"
#include "vars.h"
#include "draw.h"
#include "iehelp.h"

#include "util.h"

static HMODULE hMSHTML = nullptr, hURLMON = nullptr;


typedef HRESULT (WINAPI *tCreateURLMoniker)(IMoniker*,WCHAR*,IMoniker**);
typedef HRESULT (WINAPI *tShowHTMLDialog)(HWND,IMoniker*,VARIANT*,WCHAR*,VARIANT*);

void init_ie_help() { }

void done_ie_help()
{
    if(hMSHTML)
    {
        FreeLibrary(hMSHTML);
        hMSHTML = nullptr;
    }
    if(hURLMON)
    {
        FreeLibrary(hURLMON);
        hURLMON = nullptr;
    }
}

void showhelppp(const char *anchor) //Alone Coder 0.36.6
{
   if (!hMSHTML) hMSHTML = LoadLibrary("MSHTML.DLL");
   if (!hURLMON) hURLMON = LoadLibrary("URLMON.DLL");

   tShowHTMLDialog Show = hMSHTML? (tShowHTMLDialog)GetProcAddress(hMSHTML, "ShowHTMLDialog") : nullptr;
   tCreateURLMoniker CreateMoniker = hURLMON? (tCreateURLMoniker)GetProcAddress(hURLMON, "CreateURLMoniker") : nullptr;

   HWND fgwin = GetForegroundWindow();
   if (!Show || !CreateMoniker)
   { MessageBox(fgwin, "Install IE4.0 or higher to view help", nullptr, MB_ICONERROR); return; }

   char dst[0x200];
   GetTempPath(sizeof dst, dst); strcat(dst, "us_help.htm");

   FILE *ff = fopen(helpname, "rb"), *gg = fopen(dst, "wb");
   if(ff == nullptr)
   {
       return;
   }
   if(gg == nullptr)
   {
       fclose(ff);
       return;
   }

   for (;;)
   {
      int x = getc(ff);
      if (x == EOF) break;
      if (x == '{')
      {
         char tag[0x100]; size_t r = 0;
         while (r < sizeof(tag)-1 && !feof(ff) && (x = getc(ff)) != '}')
             tag[r++] = char(x);
         tag[r] = 0;
         if (tag[0] == '?')
         {
            RECT rc;
            GetWindowRect(fgwin, &rc);
            if (tag[1] == 'x')
                fprintf(gg, "%ld", rc.right-rc.left-20);
            if (tag[1] == 'y')
                fprintf(gg, "%ld", rc.bottom-rc.top-20);
         }
         else
         {
            char res[0x100]; GetPrivateProfileString("SYSTEM.KEYS", tag, "not defined", res, sizeof res, ininame);
            char *comment = strchr(res, ';'); if (comment) *comment = 0;
            size_t len; //Alone Coder 0.36.7
            for (/*int*/ len = strlen(res); len && res[len-1] == ' '; res[--len] = 0);
            for (len = 0; res[len]; len++) if (res[len] == ' ') res[len] = '-';
            fprintf(gg, "%s", res);
         }
      } else putc(x, gg);
   }
   fclose(ff);
   fclose(gg);

   char url[0x200];
   sprintf(url, "file://%s%s%s", dst, anchor?"#":nil, anchor?anchor:nil);
   WCHAR urlw[0x200];
   MultiByteToWideChar(AreFileApisANSI()? CP_ACP : CP_OEMCP, MB_USEGLYPHCHARS, url, -1, urlw, _countof(urlw));
   IMoniker *pmk = nullptr;
   CreateMoniker(nullptr, urlw, &pmk);

   if (pmk)
   {
      bool restore_video = false;
      if(!(temp.rflags & (RF_GDI | RF_CLIP | RF_OVR | RF_16 | RF_32)))
      {
          temp.rflags = temp.rflags | RF_GDI;
          set_video();
          restore_video = true;
      }
      Show(fgwin, pmk, nullptr, nullptr, nullptr);
      pmk->Release();

      if(dbgbreak)
      {
          temp.rflags = RF_MONITOR;
          set_video();
      }
      else
      {
          if(restore_video)
              apply_video();
      }
   }

   DeleteFile(dst);
}

