/*
* Copyright (c) 2012, Mauro Scomparin
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in the
*       documentation and/or other materials provided with the distribution.
*     * Neither the name of Mauro Scomparin nor the
*       names of its contributors may be used to endorse or promote products
*       derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY Mauro Scomparin ``AS IS'' AND ANY
* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL Mauro Scomparin BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
* File:			main.c.
* Author:		Mauro Scomparin <http://scompoprojects.worpress.com>.
* Version:		1.0.0.
* Description:	Main sample file.
*/

#include "inc/hw_ints.h"
#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/timer.h"

#include "test_extern.h"
#include "cmdline.h"

// Basically here I'm checking that everything works fine.
volatile unsigned long count;
long var_init = 2;
int abc[] = {1,2,3};
int apa = 4;
int abu = 5;

test_struct_t test_table[] =
{
    {1,1,1},
    {2,1,2},
    {3,1,3},
    {0,1,0}
};

typedef int (*pfCmdLine)(int argc, char *argv[]);
typedef void(*pVoid)(void);

const char text[] = "jeng";

typedef struct 
{
    const char* pChar;
    const char* pChar2;
    pVoid pVFunc;
    pfCmdLine fn;
} char_struct_t;

const char cmd1[] = "cmd1";
const char cmd2[] = "cmd2";
const char cmd3[] = "cmd3";

void void_function(void)
{

}


int process_cmd1(int argc, char *argv[])
{
    return 0;
}
int process_cmd2(int argc, char *argv[])
{
    return 0;
}
int process_cmd3(int argc, char *argv[])
{
    return 0;
}

char_struct_t ctable[] = 
{
    {cmd1, cmd1, void_function, process_cmd1},
    {"testtest", cmd2, void_function, process_cmd2},
    {cmd3, cmd3, void_function, process_cmd3},
    {0, 0, 0, 0}
};

#if 1
tCmdLineEntry g_sCmdTable[] = 
{
    {"ss", process_cmd1, "ss"},
    {"jj", process_cmd2, "ss"},
    {"mm", process_cmd3, "ss"},
    {0, 0, 0}
};
#endif

// An interrupt function.
void Timer1A_ISR(void);

// main function.
int main(void) {
        const char *pText = &text[0];
        char_struct_t *ptr = &ctable[0];
        abc[0] = 5;
        apa = 6;
	SysCtlClockSet(SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);
	TimerConfigure(TIMER1_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PERIODIC);
	TimerControlStall(TIMER1_BASE, TIMER_A, true);
	TimerLoadSet(TIMER1_BASE, TIMER_A, 2111);
	TimerIntRegister(TIMER1_BASE, TIMER_A, Timer1A_ISR);
	TimerIntEnable(TIMER1_BASE, TIMER_TIMA_TIMEOUT);
	count=3;
	TimerEnable(TIMER1_BASE, TIMER_A);
    while(1)
    {	
                pewpew();
		var_init++;
                CmdLineProcess("cmd1");
    }
}

// The interrupt function definition.
void Timer1A_ISR(void){
	TimerIntClear(TIMER1_BASE, TIMER_TIMA_TIMEOUT);
	count++;
}
