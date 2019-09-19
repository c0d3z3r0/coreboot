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

static const io_register_t sunrise_thermal_cfg_registers[] = {
	{0x0, 2, "VID"},
	{0x2, 2, "DID"},
	{0x4, 2, "CMD"},
	{0x6, 2, "STS"},
	{0x8, 1, "RID"},
	{0x9, 1, "PI"},
	{0xA, 1, "SCC"},
	{0xB, 1, "BCC"},
	{0xC, 1, "CLS"},
	{0xD, 1, "LT"},
	{0xE, 1, "HTYPE"},
	{0x10, 4, "TBAR"},
	{0x14, 4, "TBARH"},
	{0x2C, 2, "SVID"},
	{0x2E, 2, "SID"},
	{0x34, 4, "CAP_PTR"},
	{0x3C, 1, "INTLN"},
	{0x3D, 1, "INTPN"},
	{0x40, 4, "TBARB"},
	{0x44, 4, "TBARBH"},
	{0x48, 1, "CB"},
	{0x50, 2, "PID"},
	{0x52, 2, "PC"},
	{0x54, 4, "PCS"},
	{0x80, 2, "MID"},
	{0x82, 2, "MC"},
	{0x84, 4, "MA"},
	{0x88, 4, "MD"},
};

static const io_register_t sunrise_thermal_registers[] = {
	{0x0, 2, "TEMP"},
	{0x4, 1, "TSC"},
	{0x6, 1, "TSS"},
	{0x8, 1, "TSEL"},
	{0xA, 1, "TSREL"},
	{0xC, 1, "TSMIC"},
	{0x10, 2, "CTT"},
	{0x14, 2, "TAHV"},
	{0x18, 2, "TALV"},
	{0x1C, 2, "TSPM"},
	{0x40, 4, "TL"},
	{0x50, 4, "TL2"},
	{0x60, 2, "PHL"},
	{0x62, 1, "PHLC"},
	{0x80, 1, "TAS"},
	{0x82, 1, "TSPIEN"},
	{0x84, 1, "TSGPEN"},
	{0xF0, 1, "TCFD"},
};

int print_thermal(struct pci_dev *sb, struct pci_access *pacc)
{
	size_t i, thermal_cfg_registers_size, thermal_registers_size;
	uint64_t thermalbase_phys = 0;
	const io_register_t *thermal_cfg_registers;
	const io_register_t *thermal_registers;
	struct pci_dev *thermal = NULL;

	printf("\n========== Thermal =========\n\n");

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
		thermal = pci_get_dev(pacc, sb->domain, sb->bus, 0x14, 2);
		if (!thermal) {
			printf("Thermal device not found.\n");
			return 1;
		}
		thermalbase_phys = pci_read_long(thermal, 0x10) & ~0xfff;

		thermal_cfg_registers = sunrise_thermal_cfg_registers;
		thermal_registers = sunrise_thermal_registers;
		thermal_cfg_registers_size = ARRAY_SIZE(sunrise_thermal_cfg_registers);
		thermal_registers_size = ARRAY_SIZE(sunrise_thermal_registers);
		break;

	default:
		printf("Error: Dumping Thermal on this southbridge is not (yet) supported.\n");
		return 1;
	}

	for (i = 0; i < thermal_cfg_registers_size; i++) {
		switch (thermal_cfg_registers[i].size) {
		case 4:
			printf("0x%04x: 0x%08x (%s)\n",
				thermal_cfg_registers[i].addr,
				pci_read_long(thermal, thermal_cfg_registers[i].addr),
				thermal_cfg_registers[i].name);
			break;
		case 2:
			printf("0x%04x: 0x%04x     (%s)\n",
				thermal_cfg_registers[i].addr,
				pci_read_word(thermal, thermal_cfg_registers[i].addr),
				thermal_cfg_registers[i].name);
			break;
		case 1:
			printf("0x%04x: 0x%02x       (%s)\n",
				thermal_cfg_registers[i].addr,
				pci_read_byte(thermal, thermal_cfg_registers[i].addr),
				thermal_cfg_registers[i].name);
			break;
		default:
			printf("Error: register size %d not implemented.\n",
				thermal_cfg_registers[i].size);
			break;
		}
	}

	if (thermal)
		pci_free_dev(thermal);

	if (thermalbase_phys) {
		const size_t thermalbase_size = 4 * KiB;
		volatile const uint8_t *const thermalbase =
			map_physical(thermalbase_phys, thermalbase_size);
		if (!thermalbase) {
			perror("Error mapping ThermalBASE");
			return 1;
		}

		printf("\n=========== ThermalBASE ===========\n\n");
		printf("BAR = 0x%08" PRIx64 " (MEM)\n\n", thermalbase_phys);

		for (i = 0; i < thermal_registers_size; i++) {
			switch (thermal_registers[i].size) {
			case 4:
				printf("thermalbase+0x%04x: 0x%08x (%s)\n",
					thermal_registers[i].addr,
					read32(thermalbase+thermal_registers[i].addr),
					thermal_registers[i].name);
				break;
			case 2:
				printf("thermalbase+0x%04x: 0x%04x     (%s)\n",
					thermal_registers[i].addr,
					read16(thermalbase+thermal_registers[i].addr),
					thermal_registers[i].name);
				break;
			case 1:
				printf("thermalbase+0x%04x: 0x%02x       (%s)\n",
					thermal_registers[i].addr,
					read8(thermalbase+thermal_registers[i].addr),
					thermal_registers[i].name);
				break;
			default:
				printf("Error: register size %d not implemented.\n",
					thermal_registers[i].size);
				break;
			}
		}
		unmap_physical((void *)thermalbase, thermalbase_size);
	}

	return 0;
}
