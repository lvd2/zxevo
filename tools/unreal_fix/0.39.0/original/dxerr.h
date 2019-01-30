#pragma once

#ifndef AUDCLNT_E_DEVICE_IN_USE
#define FACILITY_AUDCLNT 2185
#define AUDCLNT_ERR(n) MAKE_HRESULT(SEVERITY_ERROR, FACILITY_AUDCLNT, n)
#define AUDCLNT_E_DEVICE_IN_USE AUDCLNT_ERR(0x00a)
#endif

void printrdd(const char *pr, HRESULT r);
void printrmm(const char *pr, MMRESULT r);
void printrds(const char *pr, HRESULT r);
void printrdi(const char *pr, HRESULT r);
