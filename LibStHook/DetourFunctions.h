#pragma once


typedef HDC(WINAPI* fnGetDC)(HWND hWnd);
typedef HDC(WINAPI* fnCreateDCW)(LPCWSTR pwszDriver, LPCWSTR pwszDevice, LPWSTR pszPort, const DEVMODEW* pdm);
typedef BOOL(WINAPI* fnSetWindowPos)(HWND hWnd, HWND hWndInsertAfter, int  X, int  Y, int  cx, int  cy, UINT uFlags);
typedef int(WINAPI* fnGetDIBits)(HDC hdc, HBITMAP hbm, UINT start, UINT cLines, LPVOID lpvBits, LPBITMAPINFO lpbmi, UINT usage);

typedef int(*fnTDMasterInitHook)(HWND hWnd, UINT msg, int a3);

extern fnGetDC fpGetDC;
extern fnCreateDCW fpCreateDCW;
extern fnSetWindowPos fpSetWindowPos;
extern fnGetDIBits fpGetDIBits;

extern fnTDMasterInitHook TDMasterInitHook;
extern fnTDMasterInitHook fpTDMasterInitHook;

HDC WINAPI DetourGetDC(HWND hWnd);
HDC WINAPI DetourCreateDCW(LPCWSTR pwszDriver, LPCWSTR pwszDevice, LPWSTR pszPort, const DEVMODEW* pdm);
BOOL WINAPI DetourSetWindowPos(HWND hWnd, HWND hWndInsertAfter, int  X, int  Y, int  cx, int  cy, UINT uFlags);
int WINAPI DetourGetDIBits(HDC hdc, HBITMAP hbm, UINT start, UINT cLines, LPVOID lpvBits, LPBITMAPINFO lpbmi, UINT usage);
int DetourTDMasterInitHook(HWND hWnd, UINT msg, int a3);
