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
#include <arch/mmio.h>
#include <commonlib/helpers.h>
#include "inteltool.h"

#define IO_APIC_ADDR 0xfec00000

static const io_register_t sunrise_apic_registers[] = {
	{0x00, 4, "ID"},
	{0x01, 4, "VER"},
};

static u32 io_apic_read(volatile void *ioapic_base, u32 reg)
{
	write32(ioapic_base, reg);
	return read32(ioapic_base + 0x10);
}

int print_apic(struct pci_dev *const sb)
{
	u64 reg64;
	size_t i, registers_size;
	size_t rte_entries = 0, rte_step_size = 1, rte_offset;
	const io_register_t *apic_registers;

	printf("\n========== APIC =========\n\n");

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
		apic_registers = sunrise_apic_registers;
		registers_size = ARRAY_SIZE(sunrise_apic_registers);
		rte_entries = 120;
		rte_step_size = 2;
		rte_offset = 0x10;
		break;

	default:
		printf("Error: Dumping APIC on this southbridge is not (yet) supported.\n");
		return 1;
	}

	const size_t apicbase_size = 32;
	volatile void *apicbase = map_physical(IO_APIC_ADDR, apicbase_size);
	if (!apicbase) {
		perror("Error mapping APICBASE");
		return 1;
	}

	for (i=0; i < registers_size; i++) {
		switch (apic_registers[i].size) {
		case 4:
			printf("apicbase+0x%04x: 0x%08x         (%s)\n",
				apic_registers[i].addr,
				io_apic_read(apicbase, apic_registers[i].addr),
				apic_registers[i].name);
			break;
		default:
			printf("Error: register size %d not implemented.\n",
				apic_registers[i].size);
			break;
		}
	}

	for (i=0; i < rte_entries; i++) {
		reg64 = io_apic_read(apicbase, rte_offset + i * rte_step_size);
		reg64 |= ((uint64_t)(io_apic_read(apicbase, rte_offset + i * rte_step_size + 4)) << 32);

		printf("apicbase+0x%04zx: 0x%016" PRIx64 " (RTE%zu)\n",
			(rte_offset + i * rte_step_size), reg64, i);
	}

	unmap_physical((void *)apicbase, apicbase_size);

	return 0;
}
