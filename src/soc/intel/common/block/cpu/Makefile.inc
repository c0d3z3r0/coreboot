bootblock-$(CONFIG_SOC_INTEL_COMMON_BLOCK_CAR) += car/cache_as_ram.S
bootblock-$(CONFIG_SOC_INTEL_COMMON_BLOCK_CAR) += ../../../../../cpu/x86/early_reset.S
postcar-$(CONFIG_SOC_INTEL_COMMON_BLOCK_CAR) += car/exit_car.S

bootblock-$(CONFIG_SOC_INTEL_COMMON_BLOCK_CPU) += cpulib.c
romstage-$(CONFIG_SOC_INTEL_COMMON_BLOCK_CPU) += cpulib.c
ramstage-$(CONFIG_SOC_INTEL_COMMON_BLOCK_CPU) += cpulib.c
ramstage-$(CONFIG_SOC_INTEL_COMMON_BLOCK_CPU_MPINIT) += mp_init.c
