################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
RTE_Source/RTEScheduler/%.obj: ../RTE_Source/RTEScheduler/%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: PRU Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-pru_2.3.1/bin/clpru" -v3 --include_path="C:/ti/ccsv8/ccs_base/pru/include" --include_path="C:/Users/76612/workspace_v8/RTEScheduler/RTE_Source" --include_path="C:/Users/76612/workspace_v8/RTEScheduler/RTE_Source/RTEScheduler" --include_path="C:/Users/76612/Documents/Kim/Docs/BeagleBone/pru-software-support-package/include/am335x" --include_path="C:/Users/76612/Documents/Kim/Docs/BeagleBone/pru-software-support-package/include" --include_path="C:/Users/76612/workspace_v8/RTEScheduler" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-pru_2.3.1/include" --define=am3358 --define=pru0 -g --diag_warning=225 --diag_wrap=off --display_error_number --endian=little --hardware_mac=on --preproc_with_compile --preproc_dependency="RTE_Source/RTEScheduler/$(basename $(<F)).d_raw" --obj_directory="RTE_Source/RTEScheduler" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


