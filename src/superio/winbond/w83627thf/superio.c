/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2000 AG Electronics Ltd.
 * Copyright (C) 2003-2004 Linux Networx
 * Copyright (C) 2004 Tyan
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
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

#include <arch/io.h>
#include <device/device.h>
#include <device/pnp.h>
#include <console/console.h>
#include <string.h>
#include <bitops.h>
#include <uart8250.h>
#include <pc80/keyboard.h>
#include <stdlib.h>
#include "chip.h"
#include "w83627thf.h"

static void w83627thf_enter_ext_func_mode(device_t dev)
{
	outb(0x87, dev->path.pnp.port);
	outb(0x87, dev->path.pnp.port);
}

static void w83627thf_exit_ext_func_mode(device_t dev)
{
	outb(0xaa, dev->path.pnp.port);
}

static void w83627thf_init(device_t dev)
{
	struct superio_winbond_w83627thf_config *conf = dev->chip_info;
	struct resource *res0, *res1;

	if (!dev->enabled)
		return;

	switch(dev->path.pnp.device) {
	case W83627THF_SP1:
		res0 = find_resource(dev, PNP_IDX_IO0);
		init_uart8250(res0->base, &conf->com1);
		break;
	case W83627THF_SP2:
		res0 = find_resource(dev, PNP_IDX_IO0);
		init_uart8250(res0->base, &conf->com2);
		break;
	case W83627THF_KBC:
		res0 = find_resource(dev, PNP_IDX_IO0);
		res1 = find_resource(dev, PNP_IDX_IO1);
		pc_keyboard_init(&conf->keyboard);
		break;
	}
}

static void w83627thf_set_resources(device_t dev)
{
	w83627thf_enter_ext_func_mode(dev);
	pnp_set_resources(dev);
	w83627thf_exit_ext_func_mode(dev);
}

static void w83627thf_enable_resources(device_t dev)
{
	w83627thf_enter_ext_func_mode(dev);
	pnp_enable_resources(dev);
	w83627thf_exit_ext_func_mode(dev);
}

static void w83627thf_enable(device_t dev)
{
	w83627thf_enter_ext_func_mode(dev);
	pnp_enable(dev);
	w83627thf_exit_ext_func_mode(dev);
}

static struct device_operations ops = {
	.read_resources   = pnp_read_resources,
	.set_resources    = w83627thf_set_resources,
	.enable_resources = w83627thf_enable_resources,
	.enable           = w83627thf_enable,
	.init             = w83627thf_init,
};

static struct pnp_info pnp_dev_info[] = {
	{ &ops, W83627THF_FDC,  PNP_IO0 | PNP_IRQ0 | PNP_DRQ0, { 0x07f8, 0}, },
	{ &ops, W83627THF_PP,   PNP_IO0 | PNP_IRQ0 | PNP_DRQ0, { 0x07f8, 0}, },
	{ &ops, W83627THF_SP1,  PNP_IO0 | PNP_IRQ0, { 0x7f8, 0 }, },
	{ &ops, W83627THF_SP2,  PNP_IO0 | PNP_IRQ0, { 0x7f8, 0 }, },
	{ &ops, W83627THF_KBC,  PNP_IO0 | PNP_IO1 | PNP_IRQ0 | PNP_IRQ1, { 0x7ff, 0 }, { 0x7ff, 0x4}, },
	{ &ops, W83627THF_CIR, PNP_IO0 | PNP_IRQ0, { 0x7f8, 0 }, },
	{ &ops, W83627THF_GAME_MIDI_GPIO1, PNP_IO0 | PNP_IO1 | PNP_IRQ0, { 0x7ff, 0 }, {0x7fe, 4} },
	/* { W83627THF_GPIO2,}, */
	/* { W83627THF_GPIO3,}, */
	{ &ops, W83627THF_ACPI, PNP_IRQ0,  },
	{ &ops, W83627THF_HWM,  PNP_IO0 | PNP_IRQ0, { 0xff8, 0 } },
};

static void enable_dev(device_t dev)
{
	pnp_enable_devices(dev, &ops, ARRAY_SIZE(pnp_dev_info), pnp_dev_info);
}

struct chip_operations superio_winbond_w83627thf_ops = {
	CHIP_NAME("Winbond W83627THF Super I/O")
	.enable_dev = enable_dev,
};
