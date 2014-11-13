/*
 * template.c
 *
 * Implementation file
 *
 */

/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/

/* Third party libraries include */
#include <stdint.h>

/* Local includes */
#include "template.h"

/*----------------------------------------------------------------------------*/
/* Configuration                                                              */
/*----------------------------------------------------------------------------*/

#define CONFIG_1         (1U)

/*----------------------------------------------------------------------------*/
/* Private Types                                                              */
/*----------------------------------------------------------------------------*/

typedef uint32_t handle_t;

/*----------------------------------------------------------------------------*/
/* Private Data                                                               */
/*----------------------------------------------------------------------------*/

static uint32_t data;
static template_cb_t temp_cb;

/*----------------------------------------------------------------------------*/
/* Helper Functions                                                           */
/*----------------------------------------------------------------------------*/

static void helper(void)
{
}

/*----------------------------------------------------------------------------*/
/* Event call-backs                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* IRQ Handlers                                                               */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Services                                                                   */
/*----------------------------------------------------------------------------*/

static void template_start(template_cb_t template_cb)
{
    temp_cb = template_cb;
    helper();
}

/*----------------------------------------------------------------------------*/
/* Initialisation                                                             */
/*----------------------------------------------------------------------------*/

void template_init(template_services_t *temp)
{
    temp->start = template_start;
}
