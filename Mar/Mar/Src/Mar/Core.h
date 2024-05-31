#pragma once
#ifdef MAR_PLATFORM_WINDOWS
     #ifdef MAR_BUILD_DLL
        #define MAR_API _declspec(dllexport)
     #else
        #define MAR_API _declspec(dllimport)
     #endif
#else
    #error MAR only support Windows!
#endif // DEBUG
