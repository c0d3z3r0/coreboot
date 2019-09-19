/*
 * inteltool - dump all registers on an Intel CPU + chipset based system.
 *
 * Copyright (C) 2008-2010 by coresystems GmbH
 *  written by Stefan Reinauer <stepan@coresystems.de>
 * Copyright (C) 2017 secunet Security Networks AG
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <commonlib/helpers.h>
#include "inteltool.h"

static const io_register_t sunrise_io_registers[] = {
	/* Interrupt */
	{0x4D0, 1, "ELCR1"},
	{0x4D1, 1, "ELCR2"},

	/* Processor Interface */
	{0x061, 1, "NMI_STS_CNT"},
	{0x070, 1, "NMI_EN"},
	{0x092, 1, "PORT92"},
	{0xCF9, 1, "RST_CNT"},
};

int print_io(struct pci_dev *sb)
{
	size_t i, io_registers_size = 0;
	const io_register_t *io_registers;

	printf("\n========== I/O registers =========\n\n");

	switch (sb->device_id) {
	case PCI_DEVICE_ID_INTEL_H110:
	case PCI_DEVICE_ID_INTEL_H170:
	case PCI_DEVICE_ID_INTEL_Z170:
	case PCI_DEVICE_ID_INTEL_Q170:
	case PCI_DEVICE_ID_INTEL_Q150:
	case PCI_DEVICE_ID_INTEL_B150:
	case PCI_DEVICE_ID_INTEL_C236:
	case PCI_DEVICE_ID_INTEL_C232:
	case PCI_DEVICE_ID_INTEL_QM170:
	case PCI_DEVICE_ID_INTEL_HM170:
	case PCI_DEVICE_ID_INTEL_CM236:
	case PCI_DEVICE_ID_INTEL_HM175:
	case PCI_DEVICE_ID_INTEL_QM175:
	case PCI_DEVICE_ID_INTEL_CM238:
	case PCI_DEVICE_ID_INTEL_SUNRISEPOINT_LP_PRE:
	case PCI_DEVICE_ID_INTEL_SUNRISEPOINT_LP_U_BASE_SKL:
	case PCI_DEVICE_ID_INTEL_SUNRISEPOINT_LP_Y_PREM_SKL:
	case PCI_DEVICE_ID_INTEL_SUNRISEPOINT_LP_U_PREM_SKL:
	case PCI_DEVICE_ID_INTEL_SUNRISEPOINT_LP_U_BASE_KBL:
	case PCI_DEVICE_ID_INTEL_SUNRISEPOINT_LP_U_PREM_KBL:
	case PCI_DEVICE_ID_INTEL_SUNRISEPOINT_LP_Y_PREM_KBL:
	case PCI_DEVICE_ID_INTEL_SUNRISEPOINT_LP_U_IHDCP_BASE:
	case PCI_DEVICE_ID_INTEL_SUNRISEPOINT_LP_U_IHDCP_PREM:
	case PCI_DEVICE_ID_INTEL_SUNRISEPOINT_LP_Y_IHDCP_PREM:
		io_registers = sunrise_io_registers;
		io_registers_size = ARRAY_SIZE(sunrise_io_registers);
		break;

	default:
		printf("Error: Dumping I/O registers on this southbridge is"
			"not (yet) supported.\n");
		return 1;
	}

	for (i = 0; i < io_registers_size; i++) {
		switch (io_registers[i].size) {
		case 1:
			printf("0x%04x: 0x%02x       (%s)\n",
				io_registers[i].addr,
				inb(io_registers[i].addr),
				io_registers[i].name);
			break;
		default:
			printf("Error: register size %d not implemented.\n",
				io_registers[i].size);
			break;
		}
	}

	return 0;
}
