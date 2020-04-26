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
        0x8fee60,
0x3f1a10,
0x1cef70,
0x1cf130,
0x2e8ab3,
0x1bdf80,
0x30a930,
0x298ac1,
0x3a3510,
0x3a3f50,
0x1d6440,
0x3a2b10,
0x37830d,
0x34f699,
0x3a58f5,
0x2fed51,
0x240eee,
0x67dfcf,
0x3dba50,
0x3b1bfc,
0x38e320,
0x38e377,
0x3e28a0,
0x34ae09,
0x2ac270,
0x4ba050,
0x254318,
0x4beec0,
0x377a75,
0x4faf20,
0x3a3574,
0x1b615c,
0x1b8155,
0x1b7e69,
0x19cd30,
0x21bd80,
0x6b4d00,
0x1ef220,
0x19d6e0,
0x618030,
0x24d610,
0x1cf2e0,
0x194840,
0x1cfbf0,
0x3f66cf,
0x7112e0,
0x710c30,
0x1b7e50,
0x3f2380,
0x3f6640,
0x19d5a0,
0x2cba3f,
0x1c3099,
0x352f4a,
0x3ca642,
0x3a3556,
0x3f6689,
0x6179ee,
0x617cc0,
0x000000,
0x1ce37c,
0x3c05c3,
0x1b8cf0,
0x3e59b8,
0x61045c,
0x19795d,
0x184763,
0x8f3677,
0x2a20c7,
0x1cdff0,
0x29b900,
0x346125,
0x000000,
0x000000,
0x000000,
0x3b1c0a,
0x38e320,
0x000000,
0x000000,
0x1981a4,
0x8f6340,
0x8f6a40,
0x24e187,
0x1ce408,
0x33afc0,
0x1b6a60,
    };

};