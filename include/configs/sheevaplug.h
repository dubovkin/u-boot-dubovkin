/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * (C) Copyright 2009-2014
 * Gerald Kerma <dreagle@doukki.net>
 * Marvell Semiconductor <www.marvell.com>
 * Written-by: Prafulla Wadaskar <prafulla@marvell.com>
 */

#ifndef _CONFIG_SHEEVAPLUG_H
#define _CONFIG_SHEEVAPLUG_H

#include "mv-common.h"

/*
 *  Environment variables configurations
 */
/*
 * max 4k env size is enough, but in case of nand
 * it has to be rounded to sector size
 */
/*
 * Environment is right behind U-Boot in flash. Make sure U-Boot
 * doesn't grow into the environment area.
 */
#define CONFIG_BOARD_SIZE_LIMIT		CONFIG_ENV_OFFSET

/*
 * Default environment variables
 */

#define CONFIG_EXTRA_ENV_SETTINGS	"x_bootargs=console"	\
	"=ttyS0,115200 mtdparts="CONFIG_MTDPARTS_DEFAULT	\
	"x_bootcmd_kernel=nand read 0x6400000 0x100000 0x400000\0" \
	"x_bootcmd_usb=usb start\0" \
	"x_bootargs_root=root=/dev/mtdblock3 rw rootfstype=jffs2\0"

/*
 * Ethernet Driver configuration
 */
#ifdef CONFIG_CMD_NET
#define CONFIG_MVGBE_PORTS	{1, 0}	/* enable port 0 only */
#define CONFIG_PHY_BASE_ADR	0
#endif /* CONFIG_CMD_NET */

/*
 * SATA driver configuration
 */
#ifdef CONFIG_SATA
#define CONFIG_SYS_SATA_MAX_DEVICE	2
#define CONFIG_LBA48
#endif /* CONFIG_SATA */

#endif /* _CONFIG_SHEEVAPLUG_H */
