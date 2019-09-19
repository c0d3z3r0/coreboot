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

static const io_register_t sunrise_i2c_cfg_registers[] = {
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

static const io_register_t sunrise_i2c_registers[] = {
	{0x000, 4, "IC_CON"},
	{0x004, 4, "IC_TAR"},
	{0x00C, 4, "IC_HS_MADDR"},
	{0x010, 4, "IC_DATA_CMD"},
	{0x014, 4, "IC_SS_SCL_HCNT"},
	{0x018, 4, "IC_SS_SCL_LCNT"},
	{0x01C, 4, "IC_FS_SCL_HCNT"},
	{0x020, 4, "IC_FS_SCL_LCNT"},
	{0x02C, 4, "IC_INTR_STAT"},
	{0x030, 4, "IC_INTR_MASK"},
	{0x034, 4, "IC_RAW_INTR_STAT"},
	{0x038, 4, "IC_RX_TL"},
	{0x03C, 4, "IC_TX_TL"},
	{0x040, 4, "IC_CLR_INTR"},
	{0x044, 4, "IC_CLR_RX_UNDER"},
	{0x048, 4, "IC_CLR_RX_OVER"},
	{0x04C, 4, "IC_CLR_TX_OVER"},
	{0x050, 4, "IC_CLR_RD_REQ"},
	{0x054, 4, "IC_CLR_TX_ABRT"},
	{0x058, 4, "IC_CLR_RX_DONE"},
	{0x05C, 4, "IC_CLR_ACTIVITY"},
	{0x060, 4, "IC_CLR_STOP_DET"},
	{0x064, 4, "IC_CLR_START_DET"},
	{0x068, 4, "IC_CLR_GEN_CALL"},
	{0x06C, 4, "IC_ENABLE"},
	{0x070, 4, "IC_STATUS"},
	{0x074, 4, "IC_TXFLR"},
	{0x078, 4, "IC_RXFLR"},
	{0x07C, 4, "IC_SDA_HOLD"},
	{0x080, 4, "IC_TX_ABRT_SOURCE"},
	{0x088, 4, "IC_DMA_CR"},
	{0x08C, 4, "IC_DMA_TDLR"},
	{0x090, 4, "IC_DMA_RDLR"},
	{0x098, 4, "IC_ACK_GENERAL_CALL"},
	{0x09C, 4, "IC_ENABLE_STATUS"},
	{0x0A0, 4, "IC_FS_SPKLEN"},
	{0x0A8, 4, "IC_CLR_RESTRART_DET"},
	{0x204, 4, "RESETS"},
	{0x210, 4, "ACTIVELTR_VALUE"},
	{0x214, 4, "IDLELTR_VALUE"},
	{0x218, 4, "TX_ACK_COUNT"},
	{0x21C, 4, "RX_BYTE_COUNT"},
	{0x220, 4, "TX_COMPLETE_INTR_STAT"},
	{0x224, 4, "TX_COMPLETE_INTR_CLR"},
	{0x228, 4, "SW_SCRATCH_0"},
	{0x22C, 4, "SW_SCRATCH_1"},
	{0x230, 4, "SW_SCRATCH_2"},
	{0x234, 4, "SW_SCRATCH_3"},
	{0x238, 4, "CLOCK_GATE"},
	{0x240, 4, "REMAP_ADDR_LO"},
	{0x244, 4, "REMAP_ADDR_HI"},
	{0x24C, 4, "DEVIDLE_CONTROL"},
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

int print_i2c(struct pci_dev *sb, struct pci_access *pacc)
{
	size_t i, i2c_cfg_registers_size, i2c_registers_size;
	uint64_t i2cbase_phys = 0;
	const io_register_t *i2c_cfg_registers;
	const io_register_t *i2c_registers;
	struct pci_dev *i2c = NULL;

	for (int i2cnum = 0; i2cnum < 4; i2cnum++){
		printf("\n========== I2C[%d] =========\n\n", i2cnum);

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
			i2c = pci_get_dev(pacc, sb->domain, sb->bus, 0x15, i2cnum);
			if (!i2c) {
				printf("I2C device not found.\n");
				return 1;
			}
			i2cbase_phys = pci_read_long(i2c, 0x10) & ~0xfff;
			if (i2cbase_phys == 0xfffff000) {
				printf("device disabled.\n");
				pci_free_dev(i2c);
				continue;
			}

			i2c_cfg_registers = sunrise_i2c_cfg_registers;
			i2c_registers = sunrise_i2c_registers;
			i2c_cfg_registers_size = ARRAY_SIZE(sunrise_i2c_cfg_registers);
			i2c_registers_size = ARRAY_SIZE(sunrise_i2c_registers);
			break;

		default:
			printf("Error: Dumping I2C on this southbridge is not (yet) supported.\n");
			return 1;
		}

		for (i = 0; i < i2c_cfg_registers_size; i++) {
			switch (i2c_cfg_registers[i].size) {
			case 4:
				printf("0x%04x: 0x%08x (%s)\n",
					i2c_cfg_registers[i].addr,
					pci_read_long(i2c, i2c_cfg_registers[i].addr),
					i2c_cfg_registers[i].name);
				break;
			default:
				printf("Error: register size %d not implemented.\n",
					i2c_cfg_registers[i].size);
				break;
			}
		}

		if (i2c)
			pci_free_dev(i2c);

		if (i2cbase_phys) {
			const size_t i2cbase_size = 4 * KiB;
			volatile const uint8_t *const i2cbase =
				map_physical(i2cbase_phys, i2cbase_size);
			if (!i2cbase) {
				perror("Error mapping I2CBASE");
				return 1;
			}

			printf("\n=========== I2CBASE[%d] ===========\n\n", i2cnum);
			printf("BAR = 0x%08" PRIx64 " (MEM)\n\n", i2cbase_phys);

			for (i = 0; i < i2c_registers_size; i++) {
				switch (i2c_registers[i].size) {
				case 4:
					printf("i2cbase+0x%04x: 0x%08x (%s)\n",
						i2c_registers[i].addr,
						read32(i2cbase + i2c_registers[i].addr),
						i2c_registers[i].name);
					break;
				default:
					printf("Error: register size %d not implemented.\n",
						i2c_registers[i].size);
					break;
				}
			}
			unmap_physical((void *)i2cbase, i2cbase_size);
		}
	}

	return 0;
}
