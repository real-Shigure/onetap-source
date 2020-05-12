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
    0x8ff800,
0x3f20b0,
0x1cf010,
0x1cf1d0,
0x2e8c53,
0x1be020,
0x30aae0,
0x298c31,
0x3a3640,
0x3a4080,
0x1d64d0,
0x3a2c40,
0x37842d,
0x34f7e9,
0x3a5a25,
0x2fef01,
0x240fbe,
0x67e9df,
0x3dbc90,
0x3b1d3c,
0x38e450,
0x38e4a7,
0x3e2ae0,
0x34af79,
0x2ac3f0,
0x4ba790,
0x254428,
0x4bf720,
0x377b95,
0x4fb7c0,
0x3a36a4,
0x000000,
0x1b81f5,
0x1b7ef9,
0x19cdf0,
0x21bdf0,
0x6b56b0,
0x1ef250,
0x19d780,
0x6189c0,
0x24d730,
0x1cf380,
0x194940,
0x1cfc90,
0x3f6d6f,
0x711c80,
0x7115d0,
0x1b7ee0,
0x3f2a20,
0x3f6ce0,
0x19d640,
0x2cbbdf,
0x1c3139,
0x35309a,
0x3ca862,
0x3a3686,
0x3f6d29,
0x61837e,
0x618650,
0x000000,
0x1ce41c,
0x3c07c3,
0x1b8d90,
0x3e5be8,
0x610dfc,
0x197a5d,
0x184853,
0x8f4027,
0x2a2247,
0x1ce090,
0x29ba70,
0x346285,
0x000000,
0x000000,
0x000000,
0x3b1d4a,
0x38e450,
0x000000,
0x000000,
0x1982b4,
0x8f6cf0,
0x8f73f0,
0x24e2a7,
0x1ce4a8,
0x33b130,
0x1b6af0,
};

};