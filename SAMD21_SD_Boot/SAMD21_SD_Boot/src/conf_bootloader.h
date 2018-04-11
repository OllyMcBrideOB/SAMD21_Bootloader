/**
 * \file
 *
 * \brief Bootloader specific configuration.
 *
 * Copyright (c) 2013 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#ifndef CONF_BOOTLOADER_H_INCLUDED
#define CONF_BOOTLOADER_H_INCLUDED

#include "conf_board.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
//			S Y M B O L I C      C O N S T A N T S
////////////////////////////////////////////////////////////////////////////////////////////////////

#define APP_START_ADDRESS          0x00008000	// Configurable start address !!!!.
#define BOOT_LED                   PIN_PA17     // BOOT LED connection PIN		// TODO
#define BOOT_LOAD_PIN              12      // BOOT LOAD PIN					// TODO
#define GPIO_BOOT_PIN_MASK         (1U << (BOOT_LOAD_PIN & 0x1F)) // BOOT MASK
#define MAX_BUF_SIZE		  256                // Block size of each NVM write
#define MAX_CODE_SIZE         0x10000            // Maximum available free space in SAMD (excluding Boot loader)         
#define CONF_BLINK_TIME       500				 // LED BLINK delay
#define MAX_SIZE_BLINK_DELAY  1000               // MAX SIZE Reached error delay (time delay based on least possible occurrence)
#define FILE_READ_BLINK_DELAY 2000               // FILE read error (corrupted, etc !!!).
#define SD_CARD_BLINK_DELAY   3000				 // SD card not initialized, damaged, etc.
#define FILE_OPEN_BLINK_DELAY 4000				 // FILE not found, file open access error.
#define DEFAULT_BLINK_DELAY   5000               // For any new undefined errors (for future purpose).
#define DEFAULT_BAUD_RATE     9600				 // Baud rate for debug options.

#endif /* CONF_BOARD_H_INCLUDED */
