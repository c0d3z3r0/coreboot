/*
 * This file is part of the coreboot project.
 *
 * Copyright 2016 Google Inc.
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
#include <bootblock_common.h>
#include <soc/gpio.h>
#include "gpio.h"
//#include <superio/aspeed/common/aspeed.h>
//#include <superio/aspeed/ast2400/ast2400.h>
#include <device/pnp_ops.h>
#include <device/pnp.h>
#include <superio/nuvoton/common/nuvoton.h>
#include <superio/nuvoton/nct6683d/nct6683d.h>
#include <delay.h>
#include <console/uart.h>
#include <console/console.h>
#include <halt.h>
#include <intelblocks/lpc_lib.h>
#include <soc/pch.h>
#include <soc/pci_devs.h>
#include <device/pci_ops.h>
#include <soc/bootblock.h>

#define LPC_IO_ENABLES			0x82

#define SERIAL_DEV PNP_DEV(0x2e, NCT6683D_SP1)
#define LPC_DEV PCI_DEV(0, 0x1f, 0)

static void early_config_gpio(void)
{
	/* This is a hack for FSP because it does things in MemoryInit()
	 * which it shouldn't do. We have to prepare certain gpios here
	 * because of the brokenness in FSP. */
	gpio_configure_pads(early_gpio_table, ARRAY_SIZE(early_gpio_table));
}


static void print_reg(u8 dev, u8 reg) {
	printk(BIOS_DEBUG, "0x%x: %x\n", reg, pnp_read_config(dev, reg));
}

static void early_config_superio(void)
{
	/*
	 * at this point any ec/sio lpc address deconding must be enabled in the
	 * chipset registers. relevant registers are 0x80, 0x82, 0x84
	 */

	//lpc_soc_init(SERIAL_DEV);
	//enable_lpc();
	//pch_early_iorange_init();
	//uint16_t l = pci_read_config16(PCH_DEV_LPC, 0x82);

	uint16_t pcipnptmp = pci_read_config16(PCH_DEV_LPC, 0x80);
	pci_write_config16(PCH_DEV_LPC, ..., pcipnptmp | ...);

	if (CONFIG(CONSOLE_SERIAL)) {
		//const pnp_devfn_t serial_dev = PNP_DEV(0x2e, NCT6683D_SP1);
		//nuvoton_enable_serial(serial_dev, CONFIG_TTYS0_BASE);
		pnp_devfn_t dev = PNP_DEV(0x2e, 0);
		u8 pnptmp;

		nuvoton_pnp_enter_conf_state(dev);

		/*
		 * I reverse engineered the initialization phase from
		 * NCT6685DPeiInit (lenovo UEFI image).
		 * Most of this should be moved to the sio driver
		 * while keeping anything related to uart early init here
		 */

		pnp_set_logical_device(dev);
		pnptmp = pnp_read_config(dev, 0x1d);
		pnp_write_config(dev, 0x1d, (pnptmp & 0xf7) | 0x08);
		pnptmp = pnp_read_config(dev, 0x13);
		pnp_write_config(dev, 0x13, (pnptmp & 0xf3) | 0x0c);
		pnp_write_config(dev, 0x15, 0xf0);
		pnp_write_config(dev, 0x1a, 0x03);
		pnptmp = pnp_read_config(dev, 0x1b);
		pnp_write_config(dev, 0x1b, (pnptmp & 0x0f) | 0xf0);
		pnp_write_config(dev, 0x1d, 0x00);
		pnp_write_config(dev, 0x14, 0x00);
		pnp_write_config(dev, 0x1e, 0xf0);
		pnp_write_config(dev, 0x1f, 0xf0);
		pnptmp = pnp_read_config(dev, 0x22);
		pnp_write_config(dev, 0x22, (pnptmp & 0x43) | 0xbc);
		pnptmp = pnp_read_config(dev, 0x23);
		pnp_write_config(dev, 0x23, (pnptmp & 0x20) | 0xdf);
		pnptmp = pnp_read_config(dev, 0x24);
		print_reg(dev, 0x1b);
		print_reg(dev, 0x1d);
		print_reg(dev, 0x24);
		pnp_write_config(dev, 0x24, (pnptmp & 0x06) | 0x81);
		pnp_write_config(dev, 0x25, 0xff);
		pnp_write_config(dev, 0x26, 0x00);
		pnptmp = pnp_read_config(dev, 0x27);
		pnp_write_config(dev, 0x27, (pnptmp & 0xc0) | 0xbe);
		pnp_write_config(dev, 0x28, 0x00);
		pnp_write_config(dev, 0x29, 0xed);
		pnptmp = pnp_read_config(dev, 0x2a);
		pnp_write_config(dev, 0x2a, (pnptmp & 0x40) | 0x8f);
		pnp_write_config(dev, 0x2b, 0x00);
		pnptmp = pnp_read_config(dev, 0x27);
		pnp_write_config(dev, 0x27, (pnptmp & 0x3f) | 0xc0);
		pnptmp = pnp_read_config(dev, 0x1b);
		pnp_write_config(dev, 0x1b, (pnptmp & 0xf7) | 0x00);
		pnptmp = pnp_read_config(dev, 0x24);
		pnp_write_config(dev, 0x24, (pnptmp & 0xf9) | 0x00);
		pnptmp = pnp_read_config(dev, 0x2a);
		pnp_write_config(dev, 0x2a, (pnptmp & 0xbf) | 0x40);
		dev = PNP_DEV(0x2e, 0x05);
		pnp_set_logical_device(dev);
		pnp_set_iobase(dev, PNP_IDX_IO0, 0x0060);
		pnp_set_iobase(dev, PNP_IDX_IO1, 0x0064);
		pnp_set_irq(dev, PNP_IDX_IRQ0, 0x01);
		pnp_set_irq(dev, PNP_IDX_IRQ1, 0x0c);
		pnp_set_enable(dev, 0x01);
		dev = PNP_DEV(0x2e, 0x03);
		pnp_set_logical_device(dev);
		pnp_set_iobase(dev, PNP_IDX_IO0, 0x03f8);
		pnp_set_enable(dev, 0x01);
		dev = PNP_DEV(0x2e, 0x0b);
		pnp_set_logical_device(dev);
		pnp_set_iobase(dev, PNP_IDX_IO0, 0x0a20);
		pnp_set_enable(dev, 0x01);
		dev = PNP_DEV(0x2e, 0x00);
		pnptmp = pnp_read_config(dev, 0x1b);
		pnp_write_config(dev, 0x1b, pnptmp | 0x08);
		nuvoton_pnp_exit_conf_state(dev);
	}
}


void bootblock_mainboard_early_init(void)
{
	early_config_gpio();
	early_config_superio();
}
