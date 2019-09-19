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

static const io_register_t sunrise_gspi_cfg_registers[] = {
	{0x00, 4, "DVVENDID"},
	{0x04, 4, "STATUSCOMMAND"},
	{0x08, 4, "REVCLASSCODE"},
	{0x0c, 4, "CLLATHEADERBIST"},
	{0x10, 4, "BAR"},
	{0x14, 4, "BAR_HIGH"},
	{0x18, 4, "BAR1"},
	{0x1c, 4, "BAR1_HIGH"},
	{0x2c, 4, "SUBSYSTEMID"},
	{0x30, 4, "EXPANSION_ROM_BASEADDR"},
	{0x34, 4, "CAPABILITYPTR"},
	{0x3c, 4, "INTERRUPTREG"},
	{0x80, 4, "POWERCAPID"},
	{0x84, 4, "PMECTRLSTATUS"},
	{0x90, 4, "PCIDEVIDLE_CAP_RECORD"},
	{0x98, 4, "D0I3_CONTROL_SW_LTR_MMIO_REG"},
	{0x9c, 4, "DEVICE_IDLE_POINTER_REG"},
	{0xa0, 4, "D0I3_MAX_POW_LAT_PG_CONFIG"},
};

static const io_register_t sunrise_gspi_registers[] = {
	{0x000, 4, "SSCR0"},
	{0x004, 4, "SSCR1"},
	{0x008, 4, "SSSR"},
	{0x010, 4, "SSDR"},
	{0x028, 4, "SSTO"},
	{0x044, 4, "SITF"},
	{0x048, 4, "SIRF"},
	{0x200, 4, "CLOCKS"},
	{0x204, 4, "RESETS"},
	{0x210, 4, "ACTIVELTR_VALUE"},
	{0x214, 4, "IDLELTR_VALUE"},
	{0x218, 4, "TX_BIT_COUNT"},
	{0x21C, 4, "RX_BIT_COUNT"},
	{0x220, 4, "SSP_REG"},
	{0x224, 4, "SPI_CS_CONTROL"},
	{0x228, 4, "SW_SCRATCH"},
	{0x238, 4, "CLOCK_GATE"},
	{0x240, 4, "REMAP_ADDR_LO"},
	{0x244, 4, "REMAP_ADDR_HI"},
	{0x24C, 4, "DEVIDLE_CONTROL"},
	{0x250, 4, "DEL_RX_CLK"},
	{0x2FC, 4, "CAPABLITIES"},
	{0x800, 4, "SAR_LO0"},
	{0x804, 4, "SAR_HI0"},
	{0x808, 4, "DAR_LO0"},
	{0x80C, 4, "DAR_HI0"},
	{0x810, 4, "LLP_LO0"},
	{0x814, 4, "LLP_HI0"},
	{0x818, 4, "CTL_LO0"},
	{0x81C, 4, "CTL_HI0"},
	{0x820, 4, "SSTAT0"},
	{0x828, 4, "DSTAT0"},
	{0x830, 4, "SSTATAR_LO0"},
	{0x834, 4, "SSTATAR_HI0"},
	{0x838, 4, "DSTATAR_LO0"},
	{0x83C, 4, "DSTATAR_HI0"},
	{0x840, 4, "CFG_LO0"},
	{0x844, 4, "CFG_HI0"},
	{0x848, 4, "SGR0"},
	{0x850, 4, "DSR0"},
	{0xAC0, 4, "RawTfr"},
	{0xAC8, 4, "RawBlock"},
	{0xAD0, 4, "RawSrcTran"},
	{0xAD8, 4, "RawDstTran"},
	{0xAE0, 4, "RawErr"},
	{0xAE8, 4, "StatusTfr"},
	{0xAF0, 4, "StatusBlock"},
	{0xAF8, 4, "StatusSrcTran"},
	{0xB00, 4, "StatusDstTran"},
	{0xB08, 4, "StatusErr"},
	{0xB10, 4, "MaskTfr"},
	{0xB18, 4, "MaskBlock"},
	{0xB20, 4, "MaskSrcTran"},
	{0xB28, 4, "MaskDstTran"},
	{0xB30, 4, "MaskErr"},
	{0xB38, 4, "ClearTfr"},
	{0xB40, 4, "ClearBlock"},
	{0xB48, 4, "ClearSrcTran"},
	{0xB50, 4, "ClearDstTran"},
	{0xB58, 4, "ClearErr"},
	{0xB60, 4, "StatusInt"},
	{0xB98, 4, "DmaCfgReg"},
	{0xBA0, 4, "ChEnReg"},
};

int print_gspi(struct pci_dev *sb, struct pci_access *pacc)
{
	size_t i, gspi_cfg_registers_size = 0, gspi_registers_size = 0;
	uint64_t gspibase_phys = 0;
	const io_register_t *gspi_cfg_registers;
	const io_register_t *gspi_registers;
	struct pci_dev *gspi = NULL;

	printf("\n========== GSPI =========\n\n");

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
		gspi = pci_get_dev(pacc, sb->domain, sb->bus, 0x1e, 2);
		if (!gspi) {
			printf("gspi device not found.\n");
			return 1;
		}
		gspibase_phys = pci_read_long(gspi, 0x10) & ~0xfff;
		if (gspibase_phys == 0xfffff000) {
			printf("device disabled.\n");
			pci_free_dev(gspi);
			return 0;
		}

		gspi_cfg_registers = sunrise_gspi_cfg_registers;
		gspi_registers = sunrise_gspi_registers;
		gspi_cfg_registers_size = ARRAY_SIZE(sunrise_gspi_cfg_registers);
		gspi_registers_size = ARRAY_SIZE(sunrise_gspi_registers);
		break;

	default:
		printf("Error: Dumping GSPI on this southbridge is not (yet) supported.\n");
		return 1;
	}

	for (i = 0; i < gspi_cfg_registers_size; i++) {
		switch (gspi_cfg_registers[i].size) {
		case 4:
			printf("0x%04x: 0x%08x (%s)\n",
				gspi_cfg_registers[i].addr,
				pci_read_long(gspi, gspi_cfg_registers[i].addr),
				gspi_cfg_registers[i].name);
			break;
		default:
			printf("Error: register size %d not implemented.\n",
				gspi_cfg_registers[i].size);
			break;
		}
	}

	if (gspi)
		pci_free_dev(gspi);

	if (gspibase_phys) {
		const size_t gspibase_size = 4 * KiB;
		volatile const uint8_t *const gspibase =
			map_physical(gspibase_phys, gspibase_size);
		if (!gspibase) {
			perror("Error mapping gspiBASE");
			return 1;
		}

		printf("\n=========== GSPIBASE ===========\n\n");
		printf("BAR = 0x%08" PRIx64 " (MEM)\n\n", gspibase_phys);

		for (i = 0; i < gspi_registers_size; i++) {
			switch (gspi_registers[i].size) {
			case 4:
				printf("gspibase+0x%04x: 0x%08x (%s)\n",
					gspi_registers[i].addr,
					read32(gspibase + gspi_registers[i].addr),
					gspi_registers[i].name);
				break;
			default:
				printf("Error: register size %d not implemented.\n",
					gspi_registers[i].size);
				break;
			}
		}
		unmap_physical((void *)gspibase, gspibase_size);
	}

	return 0;
}
