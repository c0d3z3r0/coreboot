/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2011 Advanced Micro Devices, Inc.
 * Copyright (C) 2014 Felix Held <felix-coreboot@felixheld.de>
 * Copyright (C) 2014 Edward O'Callaghan <eocallaghan@alterapraxis.com>
 * Copyright (C) 2015 Matt DeVillier <matt.devillier@gmail.com>
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

#include <device/device.h>
#include <device/pnp.h>
#include <pc80/keyboard.h>
#include <stdlib.h>
#include <superio/conf_mode.h>

#include "nct668Xd.h"


static void nct668Xd_init(struct device *dev)
{
	if (!dev->enabled)
		return;

	switch (dev->path.pnp.device) {
	case NCT668XD_KBC:
		pc_keyboard_init(NO_AUX_DEVICE);
		break;
	}
}

static struct device_operations ops = {
	.read_resources   = pnp_read_resources,
	.set_resources    = pnp_set_resources,
	.enable_resources = pnp_enable_resources,
	.enable           = pnp_alt_enable,
	.init             = nct668Xd_init,
	.ops_pnp_mode     = &pnp_conf_mode_8787_aa,
};

static struct device_operations ops_noenable = ops;
ops_noenable.enable_resources = DEVICE_NOOP;

static struct pnp_info pnp_dev_info[] = {
	{ NULL, NCT668XD_PP, PNP_IO0 | PNP_IRQ0 | PNP_DRQ0,
		0x0ff8, },
	{ NULL, NCT668XD_SP1, PNP_IO0 | PNP_IRQ0,
		0x0ff8, },
	{ NULL, NCT668XD_SP2, PNP_IO0 | PNP_IRQ0,
		0x0ff8, },
	{ NULL, NCT668XD_KBC, PNP_IO0 | PNP_IO1 | PNP_IRQ0 | PNP_IRQ1,
		0x0fff, 0x0fff, },
	{ NULL, NCT668XD_CIR, PNP_IO0 | PNP_IRQ0,
		0x0ff8, },
	{ NULL, NCT668XD_PORT80},
	{ NULL, NCT668XD_ACPI},
	{ NULL, NCT668XD_EC, PNP_IO0 | PNP_IRQ0,
		0x0ff8, },
	{ NULL, NCT668XD_DSLP_PWRFAULT},
	{ NULL, NCT668XD_FAN_ASSIGN},
	{ NULL, NCT668XD_WDT1},
	{ NULL, NCT668XD_WDTMEM},
	{ &ops_noenable, NCT668XD_GPIO0},
	{ &ops_noenable, NCT668XD_GPIO1},
	{ &ops_noenable, NCT668XD_GPIO2},
	{ &ops_noenable, NCT668XD_GPIO3},
	{ &ops_noenable, NCT668XD_GPIO4},
	{ &ops_noenable, NCT668XD_GPIO5},
	{ &ops_noenable, NCT668XD_GPIO6},
	{ &ops_noenable, NCT668XD_GPIO7},
	{ &ops_noenable, NCT668XD_GPIO8},
	{ &ops_noenable, NCT668XD_GPIO9},
	{ NULL, NCT668XD_DS5},
	{ NULL, NCT668XD_DS3},
	{ NULL, NCT668XD_PCHDSW},
	{ NULL, NCT668XD_DSWWOPT},
	{ NULL, NCT668XD_DS3OPT},
	{ NULL, NCT668XD_DSDSS},
	{ NULL, NCT668XD_DSPU},
};

static void enable_dev(struct device *dev)
{
	pnp_enable_devices(dev, &ops, ARRAY_SIZE(pnp_dev_info), pnp_dev_info);
}

struct chip_operations superio_nuvoton_nct668Xd_ops = {
	CHIP_NAME("NUVOTON NCT668XD Super I/O")
	.enable_dev = enable_dev,
};
