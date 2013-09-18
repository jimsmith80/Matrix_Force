/* Copyright (c) 2012-2013, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <linux/init.h>
#include <linux/platform_device.h>
#include <mach/kgsl.h>
#include <mach/msm_bus_board.h>
#include <mach/board.h>
#include <mach/socinfo.h>

#include "devices.h"
#include "board-8960.h"

#ifdef CONFIG_GPU_CONTROL

static struct platform_device device_kgsl_3d0 = {
	.name = "kgsl-3d0",
	.id = 0,
	.num_resources = ARRAY_SIZE(kgsl_3d0_resources),
	.resource = kgsl_3d0_resources,
	.dev = {
		.platform_data = &kgsl_3d0_pdata,
	},
};

static struct kgsl_device_platform_data kgsl_3d0_pdata = {
	.pwrlevel = {
		{
			.gpu_freq = 400000000,
			.bus_freq = 4,
			.io_fraction = 0,
		},
		{
			.gpu_freq = 325000000,
			.bus_freq = 3,
			.io_fraction = 33,
		},
		{
			.gpu_freq = 300000000,
			.bus_freq = 2,
			.io_fraction = 66,
		},
		{
			.gpu_freq = 200000000,
			.bus_freq = 1,
			.io_fraction = 100,
		},
		{
			.gpu_freq = 128000000,
			.bus_freq = 0,
		},
	},
	.init_level = 1,
	.num_levels = 5,
	.set_grp_async = NULL,
	.idle_timeout = HZ/12,
	.nap_allowed = true,
	.strtstp_sleepwake = false,
	.clk_map = KGSL_CLK_CORE | KGSL_CLK_IFACE | KGSL_CLK_MEM_IFACE,
#ifdef CONFIG_MSM_BUS_SCALING
	.bus_scale_table = &grp3d_bus_scale_pdata,
#endif
	.iommu_data = kgsl_3d0_iommu_data,
	.iommu_count = ARRAY_SIZE(kgsl_3d0_iommu_data),
};
#endif
