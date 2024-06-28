#include "../base/abc/abc.h"
#include "../base/main/main.h"
#include "stdio.h"

int TestFirst_FirstFunction(Abc_Ntk_t* pNtk){
    if(!Abc_NtkIsStrash(pNtk)) {
        printf("TestFirst_FirstFunction: This function is only applicable to strashed networks.\n");
        return 0;
    }

    printf("The network with name %s has:\n", Abc_NtkName(pNtk));
    printf("\t- %d primary inputs;\n", Abc_NtkPiNum(pNtk));
    printf("\t- %d primary outputs;\n", Abc_NtkPoNum(pNtk));
    printf("\t- %d AND gates.\n", Abc_NtkNodeNum(pNtk));
    return 1;
}

int TestFirst_FirstFunctionAbc(Abc_Frame_t* pAbc){
    Abc_Ntk_t* pNtk;
    int result;

    pNtk = Abc_FrameReadNtk(pAbc);

    if(pNtk == NULL) {
        printf("TestFirst_FirstFunctionAbc: Getting the target network has failed.\n");
        return 0;
    }

    result = TestFirst_FirstFunction(pNtk);
    return result;
}