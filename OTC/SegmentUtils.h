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
    0x8ff240,
0x3f1b10,
0x1cef20,
0x1cf0e0,
0x2e8ab3,
0x1bdf10,
0x30a930,
0x298a81,
0x3a3510,
0x3a3f50,
0x1d6400,
0x3a2b10,
0x37830d,
0x34f699,
0x3a58f5,
0x2fed51,
0x240e8e,
0x67e28f,
0x3dbb30,
0x3b1bfc,
0x38e320,
0x38e377,
0x3e29a0,
0x34ae09,
0x2ac240,
0x4ba1b0,
0x2542a8,
0x4bf140,
0x377a75,
0x4fb1e0,
0x3a3574,
0x000000,
0x1b80d5,
0x1b7dd9,
0x19ccf0,
0x21bd20,
0x6b4f90,
0x1ef1c0,
0x19d680,
0x6182d0,
0x24d5b0,
0x1cf290,
0x194850,
0x1cfba0,
0x3f67df,
0x711610,
0x710f60,
0x1b7dc0,
0x3f2490,
0x3f6750,
0x19d540,
0x2cba1f,
0x1c3049,
0x352f4a,
0x3ca6c2,
0x3a3556,
0x3f6799,
0x617c8e,
0x617f60,
0x000000,
0x1ce32c,
0x3c0643,
0x1b8c70,
0x3e5ab8,
0x61070c,
0x19796d,
0x184763,
0x8f3a67,
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
0x8f6730,
0x8f6e30,
0x24e127,
0x1ce3b8,
0x33afc0,
0x1b69d0,
};

};