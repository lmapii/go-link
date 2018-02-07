/**
 *  \file wrap_sline.h
 *
 * \brief Short description of the module.
 */

#ifndef _WRAP_LIB_H_
#define _WRAP_LIB_H_

/**************************************************************************************************
 * Includes
 *************************************************************************************************/

/**************************************************************************************************
 * Definitions
 *************************************************************************************************/

typedef int (*t_wrap_tx_handler) (char b);

/**************************************************************************************************
 * Functions
 *************************************************************************************************/

/**
 * \brief Module initialization function
 */
int wrap_init (t_wrap_tx_handler hdl_tx);

#endif /* _WRAP_LIB_H_ */

// EOF
