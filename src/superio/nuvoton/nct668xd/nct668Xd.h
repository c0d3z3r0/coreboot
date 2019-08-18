/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2016 Omar Pakker <omarpakker+coreboot@gmail.com>
 * Copyright (C) 2019 Michael Niewöhner <foss@mniewoehner.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef SUPERIO_NUVOTON_NCT668XD_H
#define SUPERIO_NUVOTON_NCT668XD_H

/* WARNING!
 * NCT668XD is a "new generation" SuperIO, which implements parts of its
 * functionality in firmware. That means one should check if the desired
 * function/register is mentioned in the EC Space datasheet before trying
 * to modify any registers in HW.
 * Both datasheets (HW and EC Space) are available on request from Nuvoton.
 *
 * These are the warnings from the datasheet that apply to LDN 7 and 9 (GPIO)
 * 1. All GPIO pin functions should always be customized by firmware. BIOS /
 *    Driver should not touch all configuration registers here and related IO
 *    ports unless firmware opens them.
 * 2. Under any situations, CR30h should always be controlled by EC and never
 *    be opened for BIOS / Drivers !!
 * 3. Some GPIO pin functions were configured when related SW functions of EC
 *    Space were enabled. For such situations BIOS or application programs
 *    should not alter these setting to avoid abnormal function of underlying
 *    firmware. Please refer to EC Space Specification before going to change
 *    any configuration setting of GPIO pins.
 */

/* Logical Device Numbers (LDN) */
#define NCT668XD_PP			0x01 /* Parallel Port */
#define NCT668XD_SP1			0x02 /* UART A */
#define NCT668XD_SP2			0x03 /* UART B, IR */
#define NCT668XD_KBC			0x05 /* Keyboard Controller */
#define NCT668XD_CIR			0x06 /* Consumer IR */
#define NCT668XD_GPIO01234567		0x07 /* GPIO 0-7 */
#define NCT668XD_PORT80			0x08 /* Port 80 UART */
#define NCT668XD_GPIO89			0x09 /* GPIO 8-9, GPIO 1-8 Alternate \
					      * Func., GPIO 0-1 Enhance Group \
					      */
#define NCT668XD_ACPI			0x0A /* ACPI */
#define NCT668XD_EC			0x0B /* EC Space */
#define NCT668XD_DSLP_PWRFAULT		0x0D /* Deep Sleep, Power Fault */
#define NCT668XD_FAN_ASSIGN		0x0E /* Fan Assignment */

/* Virtual LDNs */
#define NCT668XD_WDT1		((0 << 8) | NCT668XD_WDT1_WDTMEM_GPIO01)
#define NCT668XD_WDTMEM		((4 << 8) | NCT668XD_WDT1_WDTMEM_GPIO01)
#define NCT668XD_GPIO0		((0 << 8) | NCT668XD_GPIO01234567)
#define NCT668XD_GPIO1		((1 << 8) | NCT668XD_GPIO01234567)
#define NCT668XD_GPIO2		((2 << 8) | NCT668XD_GPIO01234567)
#define NCT668XD_GPIO3		((3 << 8) | NCT668XD_GPIO01234567)
#define NCT668XD_GPIO4		((4 << 8) | NCT668XD_GPIO01234567)
#define NCT668XD_GPIO5		((5 << 8) | NCT668XD_GPIO01234567)
#define NCT668XD_GPIO6		((6 << 8) | NCT668XD_GPIO01234567)
#define NCT668XD_GPIO7		((7 << 8) | NCT668XD_GPIO01234567)
#define NCT668XD_GPIO8		((0 << 8) | NCT668XD_GPIO89)
#define NCT668XD_GPIO9		((1 << 8) | NCT668XD_GPIO89)
#define NCT668XD_DS5		((0 << 8) | NCT668XD_DS)
#define NCT668XD_DS3		((1 << 8) | NCT668XD_DS)
#define NCT668XD_PCHDSW		((3 << 8) | NCT668XD_DS)
#define NCT668XD_DSWWOPT	((4 << 8) | NCT668XD_DS)
#define NCT668XD_DS3OPT		((5 << 8) | NCT668XD_DS)
#define NCT668XD_DSDSS		((6 << 8) | NCT668XD_DS)
#define NCT668XD_DSPU		((7 << 8) | NCT668XD_DS)


#endif /* SUPERIO_NUVOTON_NCT668XD_H */
