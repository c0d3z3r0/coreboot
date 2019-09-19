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

static const io_register_t sunrise_smbus_cfg_registers[] = {
	{0x00, 2, "VID"},
	{0x02, 2, "DID"},
	{0x04, 2, "CMD"},
	{0x06, 2, "DS"},
	{0x08, 1, "RID"},
	{0x09, 1, "PI"},
	{0x0a, 1, "SCC"},
	{0x0b, 1, "BCC"},
	{0x10, 4, "SMBBAR_31_0"},
	{0x14, 4, "SMBBAR_63_32"},
	{0x20, 4, "SBA"},
	{0x2c, 2, "SVID"},
	{0x2e, 2, "SID"},
	{0x3c, 1, "INTLN"},
	{0x3d, 1, "INTPN"},
	{0x40, 1, "HCFG"},
	{0x50, 4, "TCOBASE"},
	{0x54, 4, "TCOCTL"},
	{0x64, 4, "HTIM"},
	{0x80, 4, "SMBSM"},
};

static const io_register_t sunrise_smbus_registers[] = {
	{0x00, 1, "HSTS"},
	{0x02, 1, "HCTL"},
	{0x03, 1, "HCMD"},
	{0x04, 1, "TSA"},
	{0x05, 1, "HD0"},
	{0x06, 1, "HD1"},
	{0x07, 1, "HBD"},
	{0x08, 1, "PEC"},
	{0x09, 1, "RSA"},
	{0x0a, 2, "SD"},
	{0x0c, 1, "AUXS"},
	{0x0d, 1, "AUXC"},
	{0x0e, 1, "SMLC"},
	{0x0f, 1, "SMBC"},
	{0x10, 1, "SSTS"},
	{0x11, 1, "SCMD"},
	{0x14, 1, "NDA"},
	{0x16, 1, "NDLB"},
	{0x17, 1, "NDHB"},
};

static const io_register_t sunrise_smbus_tco_registers[] = {
	{0x0,  2, "TRLD"},
	{0x2,  1, "TDI"},
	{0x3,  1, "TDO"},
	{0x4,  2, "TSTS1"},
	{0x6,  2, "TSTS2"},
	{0x8,  2, "TCTL1"},
	{0xA,  2, "TCTL2"},
	{0xC,  2, "TMSG"},
	{0xE,  1, "TWDS"},
	{0x10, 1, "LE"},
	{0x12, 2, "TTMR"},
};

int print_smbus(struct pci_dev *sb, struct pci_access *pacc)
{
	size_t i, registers_size = 0, cfg_registers_size = 0, tco_registers_size = 0;
	uint16_t smbbase, tcobase;
	const io_register_t *smbus_cfg_registers;
	const io_register_t *smbus_registers;
	const io_register_t *smbus_tco_registers;
	struct pci_dev *smbus = NULL;

	printf("\n========== SMBUS =========\n\n");

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
		smbus = pci_get_dev(pacc, sb->domain, sb->bus, sb->dev, 4);
		if (!smbus) {
			printf("SMBUS device not found.\n");
			return 1;
		}
		smbbase = pci_read_word(smbus, 0x20) & ~0x1f;
		tcobase = pci_read_word(smbus, 0x50) & ~0x1f;

		smbus_cfg_registers = sunrise_smbus_cfg_registers;
		smbus_registers = sunrise_smbus_registers;
		smbus_tco_registers = sunrise_smbus_tco_registers;
		cfg_registers_size = ARRAY_SIZE(sunrise_smbus_cfg_registers);
		registers_size = ARRAY_SIZE(sunrise_smbus_registers);
		tco_registers_size = ARRAY_SIZE(sunrise_smbus_tco_registers);
		break;

	default:
		printf("Error: Dumping smbus on this southbridge is not (yet) supported.\n");
		return 1;
	}

	for (i = 0; i < cfg_registers_size; i++) {
		switch (smbus_cfg_registers[i].size) {
		case 4:
			printf("0x%04x: 0x%08x (%s)\n",
				smbus_cfg_registers[i].addr,
				pci_read_long(smbus, smbus_cfg_registers[i].addr),
				smbus_cfg_registers[i].name);
			break;
		case 2:
			printf("0x%04x: 0x%04x     (%s)\n",
				smbus_cfg_registers[i].addr,
				pci_read_word(smbus, smbus_cfg_registers[i].addr),
				smbus_cfg_registers[i].name);
			break;
		case 1:
			printf("0x%04x: 0x%02x       (%s)\n",
				smbus_cfg_registers[i].addr,
				pci_read_byte(smbus, smbus_cfg_registers[i].addr),
				smbus_cfg_registers[i].name);
			break;
		default:
			printf("Error: register size %d not implemented.\n",
				smbus_cfg_registers[i].size);
			break;
		}
	}

	if (smbus)
		pci_free_dev(smbus);

	if (registers_size) {
		printf("\n=========== SMBBASE ===========\n\n");
		printf("SBA = 0x%04x (IO)\n\n", smbbase);
	}

	for (i = 0; i < registers_size; i++) {
		switch (smbus_registers[i].size) {
		case 2:
			printf("smbbase+0x%04x: 0x%04x     (%s)\n",
				smbus_registers[i].addr,
				inw(smbbase+smbus_registers[i].addr),
				smbus_registers[i].name);
			break;
		case 1:
			printf("smbbase+0x%04x: 0x%02x       (%s)\n",
				smbus_registers[i].addr,
				inb(smbbase+smbus_registers[i].addr),
				smbus_registers[i].name);
			break;
		default:
			printf("Error: register size %d not implemented.\n",
				smbus_registers[i].size);
			break;
		}
	}

	if (tco_registers_size) {
		printf("\n=========== TCOBASE ===========\n\n");
		printf("TCOBA = 0x%04x (IO)\n\n", tcobase);
	}

	for (i = 0; i < tco_registers_size; i++) {
		switch (smbus_tco_registers[i].size) {
		case 2:
			printf("tcobase+0x%04x: 0x%04x     (%s)\n",
				smbus_tco_registers[i].addr,
				inw(tcobase+smbus_tco_registers[i].addr),
				smbus_tco_registers[i].name);
			break;
		case 1:
			printf("tcobase+0x%04x: 0x%02x       (%s)\n",
				smbus_tco_registers[i].addr,
				inb(tcobase+smbus_tco_registers[i].addr),
				smbus_tco_registers[i].name);
			break;
		default:
			printf("Error: register size %d not implemented.\n",
				smbus_tco_registers[i].size);
			break;

		}
	}

	return 0;
}
