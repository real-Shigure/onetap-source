#pragma once

#include "Utils.h"

#define SEGMENT_LIBRARY_RVA 0xA9A400
#define SEGMENT_INFO_HEADER_SIZE 0x18C
#define SEGMENT_FUNCTION_HOOK_RVA 0x3B30

//Legacy segment function.
typedef int (__fastcall *OriginalFunctionHook) (int* vTable, int index);

static OriginalFunctionHook OriginalFunctionHookCaller;

class SegmentUtils {

public:

    void CreateInfoTable (DWORD pointer, const char* nick);

    void UpdateNetVars (DWORD pointer);

    void CreateHook (DWORD pointer);

    //Legacy segment custom function.
    static int __fastcall CustomFunctionHook(int* vTable, int index) {
        if (index >= 89) {
            index += 2;
            if (index >= 256) index++;
            if (index >= 300) index += 2;
            if (index >= 300) index++;
        }
       return OriginalFunctionHookCaller (vTable, index);
    }

protected:

    struct NetVar {
        //Offset to patch function.
        int rva;
        //Set value.
        int new_value;
    };
    
    //Netvars are offsets to parent variables in valve sdk.
    std::vector<NetVar> netvars = {
       //m_IsScope.
       NetVar ({0x95A250, 0x3914 })
    };

    std::vector<const char*> libraries = {
       "client_panorama.dll",
       "vguimatsurface.dll",
       "shaderapidx9.dll",
       "vstdlib.dll"
    };

    
std::vector<DWORD> offsets = {
0x8ff140,
0x3f1a10,
0x1cef20,
0x1cf0e0,
0x2e8ab3,
0x1bdf10,
0x30a930,
0x298a71,
0x3a3510,
0x3a3f50,
0x1d6400,
0x3a2b10,
0x37830d,
0x34f699,
0x3a58f5,
0x2fed51,
0x240e8e,
0x67e21f,
0x3dba50,
0x3b1bfc,
0x38e320,
0x38e377,
0x3e28a0,
0x34ae09,
0x2ac240,
0x4ba0b0,
0x2542a8,
0x4bf040,
0x377a75,
0x4fb0c0,
0x3a3574,
0x000000,
0x1b80d5,
0x1b7dd9,
0x19ccf0,
0x21bd20,
0x6b4f20,
0x1ef1c0,
0x19d680,
0x618220,
0x24d5b0,
0x1cf290,
0x194850,
0x1cfba0,
0x3f66cf,
0x711560,
0x710eb0,
0x1b7dc0,
0x3f2380,
0x3f6640,
0x19d540,
0x2cba1f,
0x1c3049,
0x352f4a,
0x3ca642,
0x3a3556,
0x3f6689,
0x617bde,
0x617eb0,
0x000000,
0x1ce32c,
0x3c05c3,
0x1b8c70,
0x3e59b8,
0x61064c,
0x19796d,
0x184763,
0x8f3967,
0x2a2087,
0x1cdfa0,
0x29b8c0,
0x346125,
0x000000,
0x000000,
0x000000,
0x3b1c0a,
0x38e320,
0x000000,
0x000000,
0x1981b4,
0x8f6630,
0x8f6d30,
0x24e127,
0x1ce3b8,
0x33afc0,
0x1b69d0, 
};
};
