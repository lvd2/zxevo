# to be run from 'quartus' directory as current

Q_PREFIX ?= wine
Q_PATH ?= ~/.wine/drive_c/altera/72/quartus/bin/
Q_EXE ?= quartus_sh.exe

top.rbf top.sof: ../top.v
top.rbf top.sof: ../video/video_sync_h.v
top.rbf top.sof: ../video/video_outmux.v
top.rbf top.sof: ../video/video_addrgen.v
top.rbf top.sof: ../video/video_fetch.v
top.rbf top.sof: ../video/video_vga_double.v
top.rbf top.sof: ../video/video_modedecode.v
top.rbf top.sof: ../video/video_top.v
top.rbf top.sof: ../video/video_render.v
top.rbf top.sof: ../video/video_fontrom.v
top.rbf top.sof: ../video/video_sync_v.v
top.rbf top.sof: ../video/video_palframe.v
top.rbf top.sof: ../video/video_vga_sync_h.v
top.rbf top.sof: ../spihub/spihub.v
top.rbf top.sof: ../spihub/spi2.v
top.rbf top.sof: ../vg93/fapch_counter.v
top.rbf top.sof: ../vg93/fapch_zek.v
top.rbf top.sof: ../vg93/vg93.v
top.rbf top.sof: ../slave/slavespi.v
top.rbf top.sof: ../sound/sound.v
top.rbf top.sof: ../include/tune.v
top.rbf top.sof: ../mem/atm_pager.v
top.rbf top.sof: ../sim_top/tb_top.v
top.rbf top.sof: ../sim_top/spitest_avr.v
top.rbf top.sof: ../sim_top/nmitest_rom.v
top.rbf top.sof: ../sim_top/zxevo_rom.v
top.rbf top.sof: ../sim_top/pixer.v
top.rbf top.sof: ../sim_top/rom_top.v
top.rbf top.sof: ../sim_top/spitest_rom.v
top.rbf top.sof: ../sim_top/gate/flex10ke_atoms.v
top.rbf top.sof: ../sim_top/testrom.v
top.rbf top.sof: ../sim_top/spitest_print.v
top.rbf top.sof: ../dram/arbiter.v
top.rbf top.sof: ../dram/dram.v
top.rbf top.sof: ../z80/zports.v
top.rbf top.sof: ../z80/znmi.v
top.rbf top.sof: ../z80/zdos.v
top.rbf top.sof: ../z80/zint.v
top.rbf top.sof: ../z80/zbreak.v
top.rbf top.sof: ../z80/zkbdmus.v
top.rbf top.sof: ../z80/zclock.v
top.rbf top.sof: ../z80/zbus.v
top.rbf top.sof: ../z80/zwait.v
top.rbf top.sof: ../z80/zmem.v
top.rbf top.sof: ../common/resetter.v
top.rbf top.sof: top.qsf
	$(Q_PREFIX) $(Q_PATH)$(Q_EXE) --flow compile top.qsf


clean:
	rm -rf top.rbf top.sof top.pin *.rpt *.smsg *.done *.summary db

