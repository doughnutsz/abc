#include "../base/main/main.h"
#include "../base/cmd/cmd.h"
#include "../misc/extra/extra.h"
#include "testfirst.h"

static int TestFirst_CommandTestFirst   ( Abc_Frame_t * pAbc, int argc, char **argv ){
    int fVerbose;
    int c, result;
    // set defaults
    fVerbose = 0;
    // get arguments
    Extra_UtilGetoptReset(pAbc);
    while ((c = Extra_UtilGetopt (argc, argv, "vh") ) != EOF) {
        switch (c) {
            case 'v':
                fVerbose ^=1;
            break;
            case 'h':
                goto usage;
            default:
                goto usage;
            }
        }
    // call the main function
    result = TestFirst_FirstFunctionAbc(pAbc);
    // print verbose information if the verbose mode is on
    if (fVerbose){
        printf("\nVerbose mode is on.\n");
        if (result)
            printf("The command finished successfully.\n");
        else printf("The command execution has failed.\n");
        }
    return 0;
usage:
    printf("usage: firstcmd [-vh] \n");
    printf("\t Our first command in ABC. It prints information about the function read into ABC\n");
    printf("\t-v : toggle printing verbose information [default = $s]\n", fVerbose ? "yes" : "no");
    printf("\t-h : print the command usage\n");
    return 1;
}

void TestFirst_Init(Abc_Frame_t* pAbc) {
    Cmd_CommandAdd(pAbc, "Various", "firstcmd", TestFirst_CommandTestFirst, 0);
}