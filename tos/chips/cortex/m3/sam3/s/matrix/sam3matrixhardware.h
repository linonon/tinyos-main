/**
 * "Copyright (c) 2009 The Regents of the University of California.
 * All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without written agreement
 * is hereby granted, provided that the above copyright notice, the following
 * two paragraphs and the author appear in all copies of this software.
 *
 * IN NO EVENT SHALL THE UNIVERSITY OF CALIFORNIA BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
 * OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE UNIVERSITY
 * OF CALIFORNIA HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * THE UNIVERSITY OF CALIFORNIA SPECIFICALLY DISCLAIMS ANY WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND THE UNIVERSITY OF CALIFORNIA HAS NO OBLIGATION TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
 */

/**
 * Bus Matrix register definitions.
 *
 * @author Thomas Schmid
 */

#ifndef _SAM3SMATRIXHARDWARE_H
#define _SAM3SMATRIXHARDWARE_H

#include "matrixhardware.h"


/**
 * System I/O Configuration Register
 */
typedef union
{
    uint32_t flat;
    struct
    {
        uint32_t reserved0  :  4;
        uint32_t sysio4     :  1;
        uint32_t sysio5     :  1;
        uint32_t sysio6     :  1;
        uint32_t sysio7     :  1;
        uint32_t reserved1  :  2;
        uint32_t sysio10    :  1;
        uint32_t sysio11    :  1;
        uint32_t sysio12    :  1;
        uint32_t reserved2  : 19;
    }__attribute__((__packed__)) bits;
} ccfg_sysio_t;

/**
 * SMC NAND Flash Chip select Configuration Register
 */
typedef union
{
    uint32_t flat;
    struct
    {
        uint32_t smc_nfcs0   :  1;
        uint32_t smc_nfcs1   :  1;
        uint32_t smc_nfcs2   :  1;
        uint32_t smc_nfcs3   :  1;
        uint32_t reserved    : 28;
    }__attribute__((__packed__)) bits;
} ccfg_smcnfcs_t;


/**
 * Bus Matrix Register definitions,  AT91 ARM Cortex-M3 based Microcontrollers
 * SAM3S Series, Preliminary, p. 352
 */
typedef struct matrix
{
    volatile matrix_mcfg_t mcfg0; // master configuration register 0
    volatile matrix_mcfg_t mcfg1; // master configuration register 1
    volatile matrix_mcfg_t mcfg2; // master configuration register 2
    volatile matrix_mcfg_t mcfg3; // master configuration register 3
    uint32_t reserved0[12];
    volatile matrix_scfg_t scfg0; // slave confgiruation register 0
    volatile matrix_scfg_t scfg1; // slave confgiruation register 1
    volatile matrix_scfg_t scfg2; // slave confgiruation register 2
    volatile matrix_scfg_t scfg3; // slave confgiruation register 3
    volatile matrix_scfg_t scfg4; // slave confgiruation register 4
    uint32_t reserved1[11];
    volatile matrix_pras_t pras0; // priority register A for slave 0
    uint32_t reserved2;
    volatile matrix_pras_t pras1; // priority register A for slave 0
    uint32_t reserved3;
    volatile matrix_pras_t pras2; // priority register A for slave 0
    uint32_t reserved4;
    volatile matrix_pras_t pras3; // priority register A for slave 0
    uint32_t reserved5;
    volatile matrix_pras_t pras4; // priority register A for slave 0
    uint32_t reserved6[28];
    volatile ccfg_sysio_t sysio; // System I/O Configuration register
    uint32_t reserved7;
    volatile ccfg_smcnfcs_t smcnfcs; // SMC Chip Select NAND Flash Assignment Register
    uint32_t reserved8[49];
    volatile matrix_wpmr_t wpmr; // Write Protect Mode Register
    volatile matrix_wpsr_t wpsr; // Write Protect Status Register
} matrix_t;

/**
 * Memory mapping for the MATRIX
 */
volatile matrix_t* MATRIX = (volatile matrix_t*) 0x400E0200; // MATRIX Base Address

#endif // _SAM3SMATRIXHARDWARE_H