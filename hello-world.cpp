#define WIN32_LEAN_AND_MEAN
#include <windows.h>

extern "C" __declspec(dllexport)
DWORD WINAPI MessageBoxThread(LPVOID lpParam) {
  MessageBox(NULL, "Hello world, 69!", "Hello World!", NULL);
  return 69;
}

extern "C" __declspec(dllexport)
BOOL APIENTRY DllMain(HMODULE hModule,
                      DWORD ul_reason_for_call,
                      LPVOID lpReserved) {
  switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
      CreateThread(NULL, NULL, MessageBoxThread, NULL, NULL, NULL);
      break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
      break;
  }
  return TRUE;
}
