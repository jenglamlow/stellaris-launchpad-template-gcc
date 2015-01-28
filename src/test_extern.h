/*
 * =====================================================================================
 *
 *       Filename:  test_extern.h
 *
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/25/2015 02:57:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Low Jeng Lam (jeng), jenglamlow@gmail.com
 *   Organization:  Malaysia
 *
 * =====================================================================================
 */


#ifndef TEST_E_H
#define TEST_E_H

extern int abu;

typedef struct
{
    int a;
    int b;
    int c;
} test_struct_t;

extern test_struct_t test_table[];
#if 0
typedef int (*pfnCmdLine)(int argc, char *argv[]);

//*****************************************************************************
//
//! Structure for an entry in the command list table.
//
//*****************************************************************************
typedef struct
{
    //
    //! A pointer to a string containing the name of the command.
    //
    const char *pcCmd;

    //
    //! A function pointer to the implementation of the command.
    //
    pfnCmdLine pfnCmd;

    //
    //! A pointer to a string of brief help text for the command.
    //
    const char *pcHelp;
}
tCmdLineEntry;

//*****************************************************************************
//
//! This is the command table that must be provided by the application.
//
//*****************************************************************************
extern tCmdLineEntry g_sCmdTable[];

int
CmdLineProcess(char *pcCmdLine);
#endif
void pewpew(void);
#endif
