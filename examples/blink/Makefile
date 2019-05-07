# Makefile for user application

# Specify this directory relative to the current application.
TOCK_USERLAND_BASE_DIR = ../..

# Which files to compile.
C_SRCS := $(wildcard *.c)

# Include userland master makefile. Contains rules and flags for actually
# building the application.
include $(TOCK_USERLAND_BASE_DIR)/AppMakefile.mk


ff: build/rv32imac/rv32imac.bin
	openocd -f arty-openocd-digilent.cfg \
		-c "init; jtagspi_init 0 bscan_spi_xc7a35t.bit; jtagspi_program $< 0x400000; shutdown"
