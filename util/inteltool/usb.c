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

static const io_register_t sunrise_usb_cfg_registers[] = {
	{0x00, 2, "VID"},
	{0x02, 2, "DID"},
	{0x04, 2, "CMD"},
	{0x06, 2, "STS"},
	{0x08, 1, "RID"},
	{0x09, 1, "PI"},
	{0x0A, 1, "SCC"},
	{0x0B, 1, "BCC"},
	{0x0D, 1, "MLT"},
	{0x0E, 1, "HT"},
	{0x10, 8, "MBAR"},
	{0x2C, 2, "SSVID"},
	{0x2E, 2, "SSID"},
	{0x34, 1, "CAP_PTR"},
	{0x3C, 1, "ILINE"},
	{0x3D, 1, "IPIN"},
	{0x40, 4, "XHCC1"},
	{0x44, 4, "XHCC2"},
	{0x50, 4, "XHCLKGTEN"},
	{0x58, 4, "AUDSYNC"},
	{0x60, 1, "SBRN"},
	{0x61, 1, "FLADJ"},
	{0x62, 1, "BESL"},
	{0x70, 1, "PM_CID"},
	{0x71, 1, "PM_NEXT"},
	{0x72, 2, "PM_CAP"},
	{0x74, 2, "PM_CS"},
	{0x80, 1, "MSI_CID"},
	{0x81, 1, "MSI_NEXT"},
	{0x82, 2, "MSI_MCTL"},
	{0x84, 4, "MSI_MAD"},
	{0x88, 4, "MSI_MUAD"},
	{0x8C, 2, "MSI_MD"},
	{0x94, 4, "VSHDR"},
	{0xA2, 2, "PCE_REG"},
	{0xA4, 4, "HSCFG2"},
	{0xB0, 4, "U2OCM#0"},
	{0xB4, 4, "U2OCM#1"},
	{0xB8, 4, "U2OCM#2"},
	{0xBC, 4, "U2OCM#3"},
	{0xC0, 4, "U2OCM#4"},
	{0xC4, 4, "U2OCM#5"},
	{0xC8, 4, "U2OCM#6"},
	{0xCC, 4, "U2OCM#7"},
	{0xD0, 4, "U3OCM#0"},
	{0xD4, 4, "U3OCM#1"},
	{0xD8, 4, "U3OCM#2"},
	{0xDC, 4, "U3OCM#3"},
	{0xE0, 4, "U3OCM#4"},
	{0xE4, 4, "U3OCM#5"},
	{0xE8, 4, "U3OCM#6"},
	{0xEC, 4, "U3OCM#7"},
};

static const io_register_t sunrise_usb_registers[] = {
	{0x0000, 1, "CAPLENGTH"},
	{0x0002, 2, "HCIVERSION"},
	{0x0004, 4, "HCSPARAMS1"},
	{0x0008, 4, "HCSPARAMS2"},
	{0x000C, 4, "HCSPARAMS3"},
	{0x0010, 4, "HCCPARAMS"},
	{0x0014, 4, "DBOFF"},
	{0x0018, 4, "RTSOFF"},
	{0x0080, 4, "USBCMD"},
	{0x0084, 4, "USBSTS"},
	{0x0088, 4, "PAGESIZE"},
	{0x0094, 4, "DNCTRL"},
	{0x0098, 4, "CRCR_LO"},
	{0x009C, 4, "CRCR_HI"},
	{0x00B0, 4, "DCBAAP_LO"},
	{0x00B4, 4, "DCBAAP_HI"},
	{0x0480, 4, "PORTSCN#1"},
	{0x0490, 4, "PORTSCN#2"},
	{0x04A0, 4, "PORTSCN#3"},
	{0x04B0, 4, "PORTSCN#4"},
	{0x04C0, 4, "PORTSCN#5"},
	{0x04D0, 4, "PORTSCN#6"},
	{0x04E0, 4, "PORTSCN#7"},
	{0x04F0, 4, "PORTSCN#8"},
	{0x0500, 4, "PORTSCN#9"},
	{0x0510, 4, "PORTSCN#10"},
	{0x0520, 4, "PORTSCN#11"},
	{0x0530, 4, "PORTSCN#12"},
	{0x0540, 4, "PORTSCN#13"},
	{0x0550, 4, "PORTSCN#14"},
	{0x0484, 4, "PORTPMSCN#1"},
	{0x0494, 4, "PORTPMSCN#2"},
	{0x04A4, 4, "PORTPMSCN#3"},
	{0x04B4, 4, "PORTPMSCN#4"},
	{0x04C4, 4, "PORTPMSCN#5"},
	{0x04D4, 4, "PORTPMSCN#6"},
	{0x04E4, 4, "PORTPMSCN#7"},
	{0x04F4, 4, "PORTPMSCN#8"},
	{0x0504, 4, "PORTPMSCN#9"},
	{0x0514, 4, "PORTPMSCN#10"},
	{0x0524, 4, "PORTPMSCN#11"},
	{0x0534, 4, "PORTPMSCN#12"},
	{0x0544, 4, "PORTPMSCN#13"},
	{0x0554, 4, "PORTPMSCN#14"},
	{0x048C, 4, "PORTHLPMCN#1"},
	{0x049C, 4, "PORTHLPMCN#2"},
	{0x04AC, 4, "PORTHLPMCN#3"},
	{0x04BC, 4, "PORTHLPMCN#4"},
	{0x04CC, 4, "PORTHLPMCN#5"},
	{0x04DC, 4, "PORTHLPMCN#6"},
	{0x04EC, 4, "PORTHLPMCN#7"},
	{0x04FC, 4, "PORTHLPMCN#8"},
	{0x050C, 4, "PORTHLPMCN#9"},
	{0x051C, 4, "PORTHLPMCN#10"},
	{0x052C, 4, "PORTHLPMCN#11"},
	{0x053C, 4, "PORTHLPMCN#12"},
	{0x054C, 4, "PORTHLPMCN#13"},
	{0x055C, 4, "PORTHLPMCN#14"},

	{0x0580, 4, "PORTSCXUSB3#1"},
	{0x0590, 4, "PORTSCXUSB3#2"},
	{0x05A0, 4, "PORTSCXUSB3#3"},
	{0x05B0, 4, "PORTSCXUSB3#4"},
	{0x05C0, 4, "PORTSCXUSB3#5"},
	{0x05D0, 4, "PORTSCXUSB3#6"},
	{0x05E0, 4, "PORTSCXUSB3#7"},
	{0x05F0, 4, "PORTSCXUSB3#8"},
	{0x0600, 4, "PORTSCXUSB3#9"},
	{0x0610, 4, "PORTSCXUSB3#10"},
	{0x0584, 4, "PORTPMSCX#1"},
	{0x0594, 4, "PORTPMSCX#2"},
	{0x05A4, 4, "PORTPMSCX#3"},
	{0x05B4, 4, "PORTPMSCX#4"},
	{0x05C4, 4, "PORTPMSCX#5"},
	{0x05D4, 4, "PORTPMSCX#6"},
	{0x05E4, 4, "PORTPMSCX#7"},
	{0x05F4, 4, "PORTPMSCX#8"},
	{0x0604, 4, "PORTPMSCX#9"},
	{0x0614, 4, "PORTPMSCX#10"},
	{0x0584, 4, "PORTPMSCX#1"},
	{0x0594, 4, "PORTPMSCX#2"},
	{0x05A4, 4, "PORTPMSCX#3"},
	{0x05B4, 4, "PORTPMSCX#4"},
	{0x05C4, 4, "PORTPMSCX#5"},
	{0x05D4, 4, "PORTPMSCX#6"},
	{0x05E4, 4, "PORTPMSCX#7"},
	{0x05F4, 4, "PORTPMSCX#8"},
	{0x0604, 4, "PORTPMSCX#9"},
	{0x0614, 4, "PORTPMSCX#10"},
	{0x0588, 4, "PORTLIX#1"},
	{0x0598, 4, "PORTLIX#2"},
	{0x05A8, 4, "PORTLIX#3"},
	{0x05B8, 4, "PORTLIX#4"},
	{0x05C8, 4, "PORTLIX#5"},
	{0x05D8, 4, "PORTLIX#6"},
	{0x05E8, 4, "PORTLIX#7"},
	{0x05F8, 4, "PORTLIX#8"},
	{0x0608, 4, "PORTLIX#9"},
	{0x0618, 4, "PORTLIX#10"},
	{0x2000, 4, "MFINDEX"},
	{0x2020, 4, "IMAN0"},
	{0x2040, 4, "IMAN1"},
	{0x2060, 4, "IMAN2"},
	{0x2080, 4, "IMAN3"},
	{0x20A0, 4, "IMAN4"},
	{0x20C0, 4, "IMAN5"},
	{0x20E0, 4, "IMAN6"},
	{0x2100, 4, "IMAN7"},
	{0x2024, 4, "IMOD0"},
	{0x2044, 4, "IMOD1"},
	{0x2064, 4, "IMOD2"},
	{0x2084, 4, "IMOD3"},
	{0x20A4, 4, "IMOD4"},
	{0x20C4, 4, "IMOD5"},
	{0x20E4, 4, "IMOD6"},
	{0x2104, 4, "IMOD7"},
	{0x2028, 4, "ERSTSZ0"},
	{0x2048, 4, "ERSTSZ1"},
	{0x2068, 4, "ERSTSZ2"},
	{0x2088, 4, "ERSTSZ3"},
	{0x20A8, 4, "ERSTSZ4"},
	{0x20C8, 4, "ERSTSZ5"},
	{0x20E8, 4, "ERSTSZ6"},
	{0x2108, 4, "ERSTSZ7"},
	{0x2030, 4, "ERSTBA_LO0"},
	{0x2050, 4, "ERSTBA_LO1"},
	{0x2070, 4, "ERSTBA_LO2"},
	{0x2090, 4, "ERSTBA_LO3"},
	{0x20B0, 4, "ERSTBA_LO4"},
	{0x20D0, 4, "ERSTBA_LO5"},
	{0x20F0, 4, "ERSTBA_LO6"},
	{0x2110, 4, "ERSTBA_LO7"},
	{0x2034, 4, "ERSTBA_HI0"},
	{0x2054, 4, "ERSTBA_HI1"},
	{0x2074, 4, "ERSTBA_HI2"},
	{0x2094, 4, "ERSTBA_HI3"},
	{0x20B4, 4, "ERSTBA_HI4"},
	{0x20D4, 4, "ERSTBA_HI5"},
	{0x20F4, 4, "ERSTBA_HI6"},
	{0x2114, 4, "ERSTBA_HI7"},
	{0x2038, 4, "ERDP_LO0"},
	{0x2058, 4, "ERDP_LO1"},
	{0x2078, 4, "ERDP_LO2"},
	{0x2098, 4, "ERDP_LO3"},
	{0x20B8, 4, "ERDP_LO4"},
	{0x20D8, 4, "ERDP_LO5"},
	{0x20F8, 4, "ERDP_LO6"},
	{0x2118, 4, "ERDP_LO7"},
	{0x203C, 4, "ERDP_HI0"},
	{0x205C, 4, "ERDP_HI1"},
	{0x207C, 4, "ERDP_HI2"},
	{0x209C, 4, "ERDP_HI3"},
	{0x20BC, 4, "ERDP_HI4"},
	{0x20DC, 4, "ERDP_HI5"},
	{0x20FC, 4, "ERDP_HI6"},
	{0x211C, 4, "ERDP_HI7"},
	{0x3000, 4, "DB0"},
	{0x3004, 4, "DB1"},
	{0x3008, 4, "DB2"},
	{0x300C, 4, "DB3"},
	{0x3010, 4, "DB4"},
	{0x3014, 4, "DB5"},
	{0x3018, 4, "DB6"},
	{0x301C, 4, "DB7"},
	{0x3020, 4, "DB8"},
	{0x3024, 4, "DB9"},
	{0x3028, 4, "DB10"},
	{0x302C, 4, "DB11"},
	{0x3030, 4, "DB12"},
	{0x3034, 4, "DB13"},
	{0x3038, 4, "DB14"},
	{0x303C, 4, "DB15"},
	{0x3040, 4, "DB16"},
	{0x3044, 4, "DB17"},
	{0x3048, 4, "DB18"},
	{0x304C, 4, "DB19"},
	{0x3050, 4, "DB20"},
	{0x3054, 4, "DB21"},
	{0x3058, 4, "DB22"},
	{0x305C, 4, "DB23"},
	{0x3060, 4, "DB24"},
	{0x3064, 4, "DB25"},
	{0x3068, 4, "DB26"},
	{0x306C, 4, "DB27"},
	{0x3070, 4, "DB28"},
	{0x3074, 4, "DB29"},
	{0x3078, 4, "DB30"},
	{0x307C, 4, "DB31"},
	{0x8000, 4, "XECP_SUPP_USB2_0"},
	{0x8004, 4, "XECP_SUPP_USB2_1"},
	{0x8008, 4, "XECP_SUPP_USB2_2"},
	{0x8010, 4, "XECP_SUPP_USB2_3"},
	{0x8014, 4, "XECP_SUPP_USB2_4"},
	{0x8018, 4, "XECP_SUPP_USB2_5"},
	{0x8020, 4, "XECP_SUPP_USB3_0"},
	{0x8024, 4, "XECP_SUPP_USB3_1"},
	{0x8028, 4, "XECP_SUPP_USB3_2"},
	{0x8030, 4, "XECP_SUPP_USB3_3"},
	{0x8034, 4, "XECP_SUPP_USB3_4"},
	{0x8038, 4, "XECP_SUPP_USB3_5"},
	{0x803C, 4, "XECP_SUPP_USB3_6"},
	{0x8040, 4, "XECP_SUPP_USB3_7"},
	{0x8044, 4, "XECP_SUPP_USB3_8"},
	{0x8048, 4, "XECP_SUPP_USB3_9"},
	{0x8094, 4, "HOST_CTRL_SCH_REG"},
	{0x80A4, 4, "PMCTRL_REG"},
	{0x80B0, 4, "HOST_CTRL_MISC_REG"},
	{0x80B4, 4, "HOST_CTRL_MISC_REG2"},
	{0x80B8, 4, "SSPE_REG"},
	{0x80D8, 4, "DUAL_ROLE_CFG_REG0"},
	{0x80E0, 4, "AUX_CTRL_REG1"},
	{0x80EC, 4, "HOST_CTRL_PORT_LINK_REG"},
	{0x80F0, 4, "USB2_LINK_MGR_CTRL_REG1"},
	{0x80FC, 4, "USB2_LINK_MGR_CTRL_REG4"},
	{0x8140, 4, "PWR_SCHED_CTRL0"},
	{0x8144, 4, "PWR_SCHED_CTRL2"},
	{0x8154, 4, "AUX_CTRL_REG2"},
	{0x8164, 4, "USB2_PHY_PMC"},
	{0x816C, 4, "XHCI_AUX_CCR"},
	{0x8174, 4, "XLTP_LTV1"},
	{0x817C, 4, "XLTP_HITC"},
	{0x8180, 4, "XLTP_MITC"},
	{0x8184, 4, "XLTP_LITC"},
	{0x8190, 4, "XECP_CMDM_CTRL_REG2"},
	{0x81B8, 4, "LFPSONCOUNT_REG"},
	{0x81C4, 4, "USB2PMCTRL_REG"},
	{0x8420, 4, "STRAP2_REG"},
	{0x846C, 4, "USBLEGSUP"},
	{0x84F4, 4, "PDO_CAPABILITY"},
	{0x84F8, 4, "USB2PDO"},
	{0x84FC, 4, "USB3PDO"},
	{0x8700, 4, "DCID"},
	{0x8900, 4, "SSIC_PROFILE_CAPABILITY_ID_REG"},
	{0x8904, 4, "PORT1_REGISTER_ACCESS_CONTROL"},
	{0x8908, 4, "PORT1_REGISTER_ACCESS_STATUS"},
	{0x890C, 4, "PORT1_PROFILE_ATTRIBUTES_REG0"},
	{0x8910, 4, "PORT1_PROFILE_ATTRIBUTES_REG1"},
	{0x8914, 4, "PORT1_PROFILE_ATTRIBUTES_REG2"},
	{0x8918, 4, "PORT1_PROFILE_ATTRIBUTES_REG3"},
	{0x891C, 4, "PORT1_PROFILE_ATTRIBUTES_REG4"},
	{0x8920, 4, "PORT1_PROFILE_ATTRIBUTES_REG5"},
	{0x8924, 4, "PORT1_PROFILE_ATTRIBUTES_REG6"},
	{0x8928, 4, "PORT1_PROFILE_ATTRIBUTES_REG7"},
	{0x892C, 4, "PORT1_PROFILE_ATTRIBUTES_REG8"},
	{0x8930, 4, "PORT1_PROFILE_ATTRIBUTES_REG9"},
	{0x8934, 4, "PORT1_PROFILE_ATTRIBUTES_REG10"},
	{0x8938, 4, "PORT1_PROFILE_ATTRIBUTES_REG11"},
	{0x893C, 4, "PORT1_PROFILE_ATTRIBUTES_REG12"},
	{0x8940, 4, "PORT1_PROFILE_ATTRIBUTES_REG13"},
	{0x8944, 4, "PORT1_PROFILE_ATTRIBUTES_REG14"},
	{0x8948, 4, "PORT1_PROFILE_ATTRIBUTES_REG15"},
	{0x894C, 4, "PORT1_PROFILE_ATTRIBUTES_REG16"},
	{0x8950, 4, "PORT1_PROFILE_ATTRIBUTES_REG17"},
	{0x8954, 4, "PORT1_PROFILE_ATTRIBUTES_REG18"},
	{0x8958, 4, "PORT1_PROFILE_ATTRIBUTES_REG19"},
	{0x895C, 4, "PORT1_PROFILE_ATTRIBUTES_REG20"},
	{0x8960, 4, "PORT1_PROFILE_ATTRIBUTES_REG21"},
	{0x8964, 4, "PORT1_PROFILE_ATTRIBUTES_REG22"},
	{0x8968, 4, "PORT1_PROFILE_ATTRIBUTES_REG23"},
	{0x896C, 4, "PORT1_PROFILE_ATTRIBUTES_REG24"},
	{0x8970, 4, "PORT1_PROFILE_ATTRIBUTES_REG25"},
	{0x8974, 4, "PORT1_PROFILE_ATTRIBUTES_REG26"},
	{0x8978, 4, "PORT1_PROFILE_ATTRIBUTES_REG27"},
	{0x897C, 4, "PORT1_PROFILE_ATTRIBUTES_REG28"},
	{0x8980, 4, "PORT1_PROFILE_ATTRIBUTES_REG29"},
	{0x8984, 4, "PORT1_PROFILE_ATTRIBUTES_REG30"},
	{0x8988, 4, "PORT1_PROFILE_ATTRIBUTES_REG31"},
	{0x898C, 4, "PORT1_PROFILE_ATTRIBUTES_REG32"},
	{0x8990, 4, "PORT1_PROFILE_ATTRIBUTES_REG33"},
	{0x8994, 4, "PORT1_PROFILE_ATTRIBUTES_REG34"},
	{0x8998, 4, "PORT1_PROFILE_ATTRIBUTES_REG35"},
	{0x899C, 4, "PORT1_PROFILE_ATTRIBUTES_REG36"},
	{0x89A0, 4, "PORT1_PROFILE_ATTRIBUTES_REG37"},
	{0x89A4, 4, "PORT1_PROFILE_ATTRIBUTES_REG38"},
	{0x89A8, 4, "PORT1_PROFILE_ATTRIBUTES_REG39"},
	{0x89AC, 4, "PORT1_PROFILE_ATTRIBUTES_REG40"},
	{0x89B0, 4, "PORT1_PROFILE_ATTRIBUTES_REG41"},
	{0x89B4, 4, "PORT1_PROFILE_ATTRIBUTES_REG42"},
	{0x89B8, 4, "PORT1_PROFILE_ATTRIBUTES_REG43"},
	{0x89BC, 4, "PORT1_PROFILE_ATTRIBUTES_REG44"},
	{0x89C0, 4, "PORT1_PROFILE_ATTRIBUTES_REG45"},
	{0x89C4, 4, "PORT1_PROFILE_ATTRIBUTES_REG46"},
	{0x89C8, 4, "PORT1_PROFILE_ATTRIBUTES_REG47"},
	{0x89CC, 4, "PORT1_PROFILE_ATTRIBUTES_REG48"},
	{0x89D0, 4, "PORT1_PROFILE_ATTRIBUTES_REG49"},
	{0x89D4, 4, "PORT1_PROFILE_ATTRIBUTES_REG50"},
	{0x89D8, 4, "PORT1_PROFILE_ATTRIBUTES_REG51"},
	{0x89DC, 4, "PORT1_PROFILE_ATTRIBUTES_REG52"},
	{0x89E0, 4, "PORT1_PROFILE_ATTRIBUTES_REG53"},
	{0x89E4, 4, "PORT1_PROFILE_ATTRIBUTES_REG54"},
	{0x89E8, 4, "PORT1_PROFILE_ATTRIBUTES_REG55"},
	{0x89EC, 4, "PORT1_PROFILE_ATTRIBUTES_REG56"},
	{0x89F0, 4, "PORT1_PROFILE_ATTRIBUTES_REG57"},
	{0x89F4, 4, "PORT1_PROFILE_ATTRIBUTES_REG58"},
	{0x89F8, 4, "PORT1_PROFILE_ATTRIBUTES_REG59"},
	{0x89FC, 4, "PORT1_PROFILE_ATTRIBUTES_REG60"},
	{0x8A00, 4, "PORT1_PROFILE_ATTRIBUTES_REG61"},
	{0x8A04, 4, "PORT1_PROFILE_ATTRIBUTES_REG62"},
	{0x8A08, 4, "PORT1_PROFILE_ATTRIBUTES_REG63"},
	{0x8A14, 4, "PORT2_REGISTER_ACCESS_CONTROL"},
	{0x8A18, 4, "PORT2_REGISTER_ACCESS_STATUS"},
	{0x8A1C, 4, "PORT2_PROFILE_ATTRIBUTES_REG0"},
	{0x8A20, 4, "PORT2_PROFILE_ATTRIBUTES_REG1"},
	{0x8A24, 4, "PORT2_PROFILE_ATTRIBUTES_REG2"},
	{0x8A28, 4, "PORT2_PROFILE_ATTRIBUTES_REG3"},
	{0x8A2C, 4, "PORT2_PROFILE_ATTRIBUTES_REG4"},
	{0x8A30, 4, "PORT2_PROFILE_ATTRIBUTES_REG5"},
	{0x8A34, 4, "PORT2_PROFILE_ATTRIBUTES_REG6"},
	{0x8A38, 4, "PORT2_PROFILE_ATTRIBUTES_REG7"},
	{0x8A3C, 4, "PORT2_PROFILE_ATTRIBUTES_REG8"},
	{0x8A40, 4, "PORT2_PROFILE_ATTRIBUTES_REG9"},
	{0x8A44, 4, "PORT2_PROFILE_ATTRIBUTES_REG10"},
	{0x8A48, 4, "PORT2_PROFILE_ATTRIBUTES_REG11"},
	{0x8A4C, 4, "PORT2_PROFILE_ATTRIBUTES_REG12"},
	{0x8A50, 4, "PORT2_PROFILE_ATTRIBUTES_REG13"},
	{0x8A54, 4, "PORT2_PROFILE_ATTRIBUTES_REG14"},
	{0x8A58, 4, "PORT2_PROFILE_ATTRIBUTES_REG15"},
	{0x8A5C, 4, "PORT2_PROFILE_ATTRIBUTES_REG16"},
	{0x8A60, 4, "PORT2_PROFILE_ATTRIBUTES_REG17"},
	{0x8A64, 4, "PORT2_PROFILE_ATTRIBUTES_REG18"},
	{0x8A68, 4, "PORT2_PROFILE_ATTRIBUTES_REG19"},
	{0x8A6C, 4, "PORT2_PROFILE_ATTRIBUTES_REG20"},
	{0x8A70, 4, "PORT2_PROFILE_ATTRIBUTES_REG21"},
	{0x8A74, 4, "PORT2_PROFILE_ATTRIBUTES_REG22"},
	{0x8A78, 4, "PORT2_PROFILE_ATTRIBUTES_REG23"},
	{0x8A7C, 4, "PORT2_PROFILE_ATTRIBUTES_REG24"},
	{0x8A80, 4, "PORT2_PROFILE_ATTRIBUTES_REG25"},
	{0x8A84, 4, "PORT2_PROFILE_ATTRIBUTES_REG26"},
	{0x8A88, 4, "PORT2_PROFILE_ATTRIBUTES_REG27"},
	{0x8A8C, 4, "PORT2_PROFILE_ATTRIBUTES_REG28"},
	{0x8A90, 4, "PORT2_PROFILE_ATTRIBUTES_REG29"},
	{0x8A94, 4, "PORT2_PROFILE_ATTRIBUTES_REG30"},
	{0x8A98, 4, "PORT2_PROFILE_ATTRIBUTES_REG31"},
	{0x8A9C, 4, "PORT2_PROFILE_ATTRIBUTES_REG32"},
	{0x8AA0, 4, "PORT2_PROFILE_ATTRIBUTES_REG33"},
	{0x8AA4, 4, "PORT2_PROFILE_ATTRIBUTES_REG34"},
	{0x8AA8, 4, "PORT2_PROFILE_ATTRIBUTES_REG35"},
	{0x8AAC, 4, "PORT2_PROFILE_ATTRIBUTES_REG36"},
	{0x8AB0, 4, "PORT2_PROFILE_ATTRIBUTES_REG37"},
	{0x8AB4, 4, "PORT2_PROFILE_ATTRIBUTES_REG38"},
	{0x8AB8, 4, "PORT2_PROFILE_ATTRIBUTES_REG39"},
	{0x8ABC, 4, "PORT2_PROFILE_ATTRIBUTES_REG40"},
	{0x8AC0, 4, "PORT2_PROFILE_ATTRIBUTES_REG41"},
	{0x8AC4, 4, "PORT2_PROFILE_ATTRIBUTES_REG42"},
	{0x8AC8, 4, "PORT2_PROFILE_ATTRIBUTES_REG43"},
	{0x8ACC, 4, "PORT2_PROFILE_ATTRIBUTES_REG44"},
	{0x8AD0, 4, "PORT2_PROFILE_ATTRIBUTES_REG45"},
	{0x8AD4, 4, "PORT2_PROFILE_ATTRIBUTES_REG46"},
	{0x8AD8, 4, "PORT2_PROFILE_ATTRIBUTES_REG47"},
	{0x8ADC, 4, "PORT2_PROFILE_ATTRIBUTES_REG48"},
	{0x8AE0, 4, "PORT2_PROFILE_ATTRIBUTES_REG49"},
	{0x8AE4, 4, "PORT2_PROFILE_ATTRIBUTES_REG50"},
	{0x8AE8, 4, "PORT2_PROFILE_ATTRIBUTES_REG51"},
	{0x8AEC, 4, "PORT2_PROFILE_ATTRIBUTES_REG52"},
	{0x8AF0, 4, "PORT2_PROFILE_ATTRIBUTES_REG53"},
	{0x8AF4, 4, "PORT2_PROFILE_ATTRIBUTES_REG54"},
	{0x8AF8, 4, "PORT2_PROFILE_ATTRIBUTES_REG55"},
	{0x8AFC, 4, "PORT2_PROFILE_ATTRIBUTES_REG56"},
	{0x8B00, 4, "PORT2_PROFILE_ATTRIBUTES_REG57"},
	{0x8B04, 4, "PORT2_PROFILE_ATTRIBUTES_REG58"},
	{0x8B08, 4, "PORT2_PROFILE_ATTRIBUTES_REG59"},
	{0x8B0C, 4, "PORT2_PROFILE_ATTRIBUTES_REG60"},
	{0x8B10, 4, "PORT2_PROFILE_ATTRIBUTES_REG61"},
	{0x8B14, 4, "PORT2_PROFILE_ATTRIBUTES_REG62"},
	{0x8B18, 4, "PORT2_PROFILE_ATTRIBUTES_REG63"},
	{0x8E10, 4, "GLOBAL_TIME_SYNC_CAP_REG"},
	{0x8E14, 4, "GLOBAL_TIME_SYNC_CTRL_REG"},
	{0x8E18, 4, "MICROFRAME_TIME_REG"},
	{0x8E20, 4, "ALWAYS_RUNNING_TIME_LOW"},
	{0x8E24, 4, "ALWAYS_RUNNING_TIME_HIGH"},
};

int print_usb(struct pci_dev *sb, struct pci_access *pacc)
{
	size_t i, usb_cfg_registers_size, usb_registers_size;
	uint64_t usbbase_phys = 0;
	const io_register_t *usb_cfg_registers;
	const io_register_t *usb_registers;
	struct pci_dev *usb = NULL;

	printf("\n========== USB =========\n\n");

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
		usb = pci_get_dev(pacc, sb->domain, sb->bus, 0x14, 0);
		if (!usb) {
			printf("USB device not found.\n");
			return 1;
		}
		usbbase_phys = pci_read_long(usb, 0x10) & ~0xfff;

		usb_cfg_registers = sunrise_usb_cfg_registers;
		usb_registers = sunrise_usb_registers;
		usb_cfg_registers_size = ARRAY_SIZE(sunrise_usb_cfg_registers);
		usb_registers_size = ARRAY_SIZE(sunrise_usb_registers);
		break;

	default:
		printf("Error: Dumping USB on this southbridge is not (yet) supported.\n");
		return 1;
	}

	for (i = 0; i < usb_cfg_registers_size; i++) {
		switch (usb_cfg_registers[i].size) {
		case 8:
			printf("0x%04x: 0x%08x (%s)\n"
			       "        0x%08x\n",
				usb_cfg_registers[i].addr,
				pci_read_long(usb, usb_cfg_registers[i].addr),
				usb_cfg_registers[i].name,
				pci_read_long(usb, usb_cfg_registers[i].addr + 4));
			break;
		case 4:
			printf("0x%04x: 0x%08x (%s)\n",
				usb_cfg_registers[i].addr,
				pci_read_long(usb, usb_cfg_registers[i].addr),
				usb_cfg_registers[i].name);
			break;
		case 2:
			printf("0x%04x: 0x%04x     (%s)\n",
				usb_cfg_registers[i].addr,
				pci_read_word(usb, usb_cfg_registers[i].addr),
				usb_cfg_registers[i].name);
			break;
		case 1:
			printf("0x%04x: 0x%02x       (%s)\n",
				usb_cfg_registers[i].addr,
				pci_read_byte(usb, usb_cfg_registers[i].addr),
				usb_cfg_registers[i].name);
			break;
		default:
			printf("Error: register size %d not implemented.\n",
				usb_cfg_registers[i].size);
			break;
		}
	}

	if (usb)
		pci_free_dev(usb);


	if (usbbase_phys) {
		const size_t usbbase_size = 4 * KiB;
		volatile const uint8_t *const usbbase =
			map_physical(usbbase_phys, usbbase_size);
		if (!usbbase) {
			perror("Error mapping USBBASE");
			return 1;
		}

		printf("\n=========== USBBASE ===========\n\n");
		printf("BAR = 0x%08" PRIx64 " (MEM)\n\n", usbbase_phys);

		for (i = 0; i < usb_registers_size; i++) {
			switch (usb_registers[i].size) {
			case 4:
				printf("usbbase+0x%04x: 0x%08x (%s)\n",
					usb_registers[i].addr,
					read32(usbbase + usb_registers[i].addr),
					usb_registers[i].name);
				break;
			case 2:
				printf("usbbase+0x%04x: 0x%04x     (%s)\n",
					usb_registers[i].addr,
					read16(usbbase + usb_registers[i].addr),
					usb_registers[i].name);
				break;
			case 1:
				printf("usbbase+0x%04x: 0x%02x       (%s)\n",
					usb_registers[i].addr,
					read8(usbbase + usb_registers[i].addr),
					usb_registers[i].name);
				break;
			default:
				printf("Error: register size %d not implemented.\n",
					usb_registers[i].size);
				break;
			}
		}
		unmap_physical((void *)usbbase, usbbase_size);
	}

	return 0;
}
