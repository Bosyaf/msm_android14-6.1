# Minimal UAG governor build: Qualcomm + WALT core only.

obj-$(CONFIG_OPLUS_CPU_FREQ_GOV_UAG) += cpufreq_uag.o
cpufreq_uag-y := cpufreq_uag_main.o
cpufreq_uag-$(CONFIG_UAG_NONLINEAR_FREQ_CTL) += nonlinear_opp_cap.o
# Keep the source directory available for the UAG local headers.
ccflags-y += -I$(src)

# Select the Qualcomm code path used by cpufreq_uag_main.c.
# This define is local to this UAG directory's compilation.
ccflags-y += -DCONFIG_OPLUS_SYSTEM_KERNEL_QCOM=1
