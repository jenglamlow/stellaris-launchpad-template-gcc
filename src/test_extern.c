/*
 * =====================================================================================
 *
 *       Filename:  test_extern.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/25/2015 02:56:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Low Jeng Lam (jeng), jenglamlow@gmail.com
 *   Organization:  Malaysia
 *
 * =====================================================================================
 */


#include "test_extern.h"

void pewpew(void)
{
    int gg = abu;
    gg++;

    test_struct_t* group = &test_table[0];

    group->a = 33;
    group->b = 44;

}

/* int */
/* CmdLineProcess(char *pcCmdLine) */
/* { */
/*     tCmdLineEntry *pCmdEntry; */

/*     pCmdEntry = &g_sCmdTable[0]; */

/* } */
