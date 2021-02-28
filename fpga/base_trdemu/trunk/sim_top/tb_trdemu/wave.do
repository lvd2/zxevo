onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -height 15 -group tb /tb/fclk
add wave -noupdate -height 15 -group tb /tb/clkz_out
add wave -noupdate -height 15 -group tb /tb/clkz_in
add wave -noupdate -height 15 -group tb /tb/iorq_n
add wave -noupdate -height 15 -group tb /tb/mreq_n
add wave -noupdate -height 15 -group tb /tb/rd_n
add wave -noupdate -height 15 -group tb /tb/wr_n
add wave -noupdate -height 15 -group tb /tb/m1_n
add wave -noupdate -height 15 -group tb /tb/rfsh_n
add wave -noupdate -height 15 -group tb /tb/res
add wave -noupdate -height 15 -group tb /tb/ziorq_n
add wave -noupdate -height 15 -group tb /tb/zmreq_n
add wave -noupdate -height 15 -group tb /tb/zrd_n
add wave -noupdate -height 15 -group tb /tb/zwr_n
add wave -noupdate -height 15 -group tb /tb/zm1_n
add wave -noupdate -height 15 -group tb /tb/zrfsh_n
add wave -noupdate -height 15 -group tb /tb/int_n
add wave -noupdate -height 15 -group tb /tb/wait_n
add wave -noupdate -height 15 -group tb /tb/nmi_n
add wave -noupdate -height 15 -group tb /tb/zint_n
add wave -noupdate -height 15 -group tb /tb/zwait_n
add wave -noupdate -height 15 -group tb /tb/znmi_n
add wave -noupdate -height 15 -group tb /tb/za
add wave -noupdate -height 15 -group tb /tb/zd
add wave -noupdate -height 15 -group tb /tb/zd_dut_to_z80
add wave -noupdate -height 15 -group tb /tb/reset_pc
add wave -noupdate -height 15 -group tb /tb/reset_sp
add wave -noupdate -height 15 -group tb /tb/csrom
add wave -noupdate -height 15 -group tb /tb/romoe_n
add wave -noupdate -height 15 -group tb /tb/romwe_n
add wave -noupdate -height 15 -group tb /tb/rompg0_n
add wave -noupdate -height 15 -group tb /tb/dos_n
add wave -noupdate -height 15 -group tb /tb/rompg2
add wave -noupdate -height 15 -group tb /tb/rompg3
add wave -noupdate -height 15 -group tb /tb/rompg4
add wave -noupdate -height 15 -group tb /tb/rd
add wave -noupdate -height 15 -group tb /tb/ra
add wave -noupdate -height 15 -group tb /tb/rwe_n
add wave -noupdate -height 15 -group tb /tb/rucas_n
add wave -noupdate -height 15 -group tb /tb/rlcas_n
add wave -noupdate -height 15 -group tb /tb/rras0_n
add wave -noupdate -height 15 -group tb /tb/rras1_n
add wave -noupdate -height 15 -group tb /tb/ide_d
add wave -noupdate -height 15 -group tb /tb/hsync
add wave -noupdate -height 15 -group tb /tb/vsync
add wave -noupdate -height 15 -group tb /tb/red
add wave -noupdate -height 15 -group tb /tb/grn
add wave -noupdate -height 15 -group tb /tb/blu
add wave -noupdate -height 15 -group tb /tb/sdcs_n
add wave -noupdate -height 15 -group tb /tb/sddo
add wave -noupdate -height 15 -group tb /tb/sddi
add wave -noupdate -height 15 -group tb /tb/sdclk
add wave -noupdate -height 15 -group tb /tb/spick
add wave -noupdate -height 15 -group tb /tb/spidi
add wave -noupdate -height 15 -group tb /tb/spido
add wave -noupdate -height 15 -group tb /tb/spics_n
add wave -noupdate -height 15 -group tb /tb/zrst_n
add wave -noupdate -height 15 -group tb /tb/mreq_wr_n
add wave -noupdate -height 15 -group tb /tb/iorq_wr_n
add wave -noupdate -height 15 -group tb /tb/full_wr_n
add wave -noupdate -height 15 -group tb /tb/rma14
add wave -noupdate -height 15 -group tb /tb/rma15
add wave -noupdate -height 15 -group tb /tb/rpag
add wave -noupdate -height 15 -group tb /tb/fe_write
add wave -noupdate -height 15 -group tb /tb/cmos_addr
add wave -noupdate -height 15 -group tb /tb/cmos_read
add wave -noupdate -height 15 -group tb /tb/cmos_write
add wave -noupdate -height 15 -group tb /tb/cmos_rnw
add wave -noupdate -height 15 -group tb /tb/cmos_req
add wave -noupdate -height 15 -group DUT /tb/DUT/fclk
add wave -noupdate -height 15 -group DUT /tb/DUT/clkz_out
add wave -noupdate -height 15 -group DUT /tb/DUT/clkz_in
add wave -noupdate -height 15 -group DUT /tb/DUT/iorq_n
add wave -noupdate -height 15 -group DUT /tb/DUT/mreq_n
add wave -noupdate -height 15 -group DUT /tb/DUT/rd_n
add wave -noupdate -height 15 -group DUT /tb/DUT/wr_n
add wave -noupdate -height 15 -group DUT /tb/DUT/m1_n
add wave -noupdate -height 15 -group DUT /tb/DUT/rfsh_n
add wave -noupdate -height 15 -group DUT /tb/DUT/int_n
add wave -noupdate -height 15 -group DUT /tb/DUT/nmi_n
add wave -noupdate -height 15 -group DUT /tb/DUT/wait_n
add wave -noupdate -height 15 -group DUT /tb/DUT/res
add wave -noupdate -height 15 -group DUT /tb/DUT/d
add wave -noupdate -height 15 -group DUT /tb/DUT/a
add wave -noupdate -height 15 -group DUT /tb/DUT/csrom
add wave -noupdate -height 15 -group DUT /tb/DUT/romoe_n
add wave -noupdate -height 15 -group DUT /tb/DUT/romwe_n
add wave -noupdate -height 15 -group DUT /tb/DUT/rompg0_n
add wave -noupdate -height 15 -group DUT /tb/DUT/dos_n
add wave -noupdate -height 15 -group DUT /tb/DUT/rompg2
add wave -noupdate -height 15 -group DUT /tb/DUT/rompg3
add wave -noupdate -height 15 -group DUT /tb/DUT/rompg4
add wave -noupdate -height 15 -group DUT /tb/DUT/iorqge1
add wave -noupdate -height 15 -group DUT /tb/DUT/iorqge2
add wave -noupdate -height 15 -group DUT /tb/DUT/iorq1_n
add wave -noupdate -height 15 -group DUT /tb/DUT/iorq2_n
add wave -noupdate -height 15 -group DUT /tb/DUT/rd
add wave -noupdate -height 15 -group DUT /tb/DUT/ra
add wave -noupdate -height 15 -group DUT /tb/DUT/rwe_n
add wave -noupdate -height 15 -group DUT /tb/DUT/rucas_n
add wave -noupdate -height 15 -group DUT /tb/DUT/rlcas_n
add wave -noupdate -height 15 -group DUT /tb/DUT/rras0_n
add wave -noupdate -height 15 -group DUT /tb/DUT/rras1_n
add wave -noupdate -height 15 -group DUT /tb/DUT/vred
add wave -noupdate -height 15 -group DUT /tb/DUT/vgrn
add wave -noupdate -height 15 -group DUT /tb/DUT/vblu
add wave -noupdate -height 15 -group DUT /tb/DUT/vhsync
add wave -noupdate -height 15 -group DUT /tb/DUT/vvsync
add wave -noupdate -height 15 -group DUT /tb/DUT/vcsync
add wave -noupdate -height 15 -group DUT /tb/DUT/ay_clk
add wave -noupdate -height 15 -group DUT /tb/DUT/ay_bdir
add wave -noupdate -height 15 -group DUT /tb/DUT/ay_bc1
add wave -noupdate -height 15 -group DUT /tb/DUT/beep
add wave -noupdate -height 15 -group DUT /tb/DUT/ide_a
add wave -noupdate -height 15 -group DUT /tb/DUT/ide_d
add wave -noupdate -height 15 -group DUT /tb/DUT/ide_dir
add wave -noupdate -height 15 -group DUT /tb/DUT/ide_rdy
add wave -noupdate -height 15 -group DUT /tb/DUT/ide_cs0_n
add wave -noupdate -height 15 -group DUT /tb/DUT/ide_cs1_n
add wave -noupdate -height 15 -group DUT /tb/DUT/ide_rs_n
add wave -noupdate -height 15 -group DUT /tb/DUT/ide_rd_n
add wave -noupdate -height 15 -group DUT /tb/DUT/ide_wr_n
add wave -noupdate -height 15 -group DUT /tb/DUT/vg_clk
add wave -noupdate -height 15 -group DUT /tb/DUT/vg_cs_n
add wave -noupdate -height 15 -group DUT /tb/DUT/vg_res_n
add wave -noupdate -height 15 -group DUT /tb/DUT/vg_hrdy
add wave -noupdate -height 15 -group DUT /tb/DUT/vg_rclk
add wave -noupdate -height 15 -group DUT /tb/DUT/vg_rawr
add wave -noupdate -height 15 -group DUT /tb/DUT/vg_a
add wave -noupdate -height 15 -group DUT /tb/DUT/vg_wrd
add wave -noupdate -height 15 -group DUT /tb/DUT/vg_side
add wave -noupdate -height 15 -group DUT /tb/DUT/step
add wave -noupdate -height 15 -group DUT /tb/DUT/vg_sl
add wave -noupdate -height 15 -group DUT /tb/DUT/vg_sr
add wave -noupdate -height 15 -group DUT /tb/DUT/vg_tr43
add wave -noupdate -height 15 -group DUT /tb/DUT/rdat_b_n
add wave -noupdate -height 15 -group DUT /tb/DUT/vg_wf_de
add wave -noupdate -height 15 -group DUT /tb/DUT/vg_drq
add wave -noupdate -height 15 -group DUT /tb/DUT/vg_irq
add wave -noupdate -height 15 -group DUT /tb/DUT/vg_wd
add wave -noupdate -height 15 -group DUT /tb/DUT/sdcs_n
add wave -noupdate -height 15 -group DUT /tb/DUT/sddo
add wave -noupdate -height 15 -group DUT /tb/DUT/sdclk
add wave -noupdate -height 15 -group DUT /tb/DUT/sddi
add wave -noupdate -height 15 -group DUT /tb/DUT/spics_n
add wave -noupdate -height 15 -group DUT /tb/DUT/spick
add wave -noupdate -height 15 -group DUT /tb/DUT/spido
add wave -noupdate -height 15 -group DUT /tb/DUT/spidi
add wave -noupdate -height 15 -group DUT /tb/DUT/spiint_n
add wave -noupdate -height 15 -group DUT /tb/DUT/dos
add wave -noupdate -height 15 -group DUT /tb/DUT/zclk
add wave -noupdate -height 15 -group DUT /tb/DUT/zpos
add wave -noupdate -height 15 -group DUT /tb/DUT/zneg
add wave -noupdate -height 15 -group DUT /tb/DUT/rst_n
add wave -noupdate -height 15 -group DUT /tb/DUT/rrdy
add wave -noupdate -height 15 -group DUT /tb/DUT/rddata
add wave -noupdate -height 15 -group DUT /tb/DUT/rompg
add wave -noupdate -height 15 -group DUT /tb/DUT/zports_dout
add wave -noupdate -height 15 -group DUT /tb/DUT/zports_dataout
add wave -noupdate -height 15 -group DUT /tb/DUT/porthit
add wave -noupdate -height 15 -group DUT /tb/DUT/csrom_int
add wave -noupdate -height 15 -group DUT /tb/DUT/kbd_data
add wave -noupdate -height 15 -group DUT /tb/DUT/mus_data
add wave -noupdate -height 15 -group DUT /tb/DUT/kbd_stb
add wave -noupdate -height 15 -group DUT /tb/DUT/mus_xstb
add wave -noupdate -height 15 -group DUT /tb/DUT/mus_ystb
add wave -noupdate -height 15 -group DUT /tb/DUT/mus_btnstb
add wave -noupdate -height 15 -group DUT /tb/DUT/kj_stb
add wave -noupdate -height 15 -group DUT /tb/DUT/kbd_port_data
add wave -noupdate -height 15 -group DUT /tb/DUT/kj_port_data
add wave -noupdate -height 15 -group DUT /tb/DUT/mus_port_data
add wave -noupdate -height 15 -group DUT /tb/DUT/wait_read
add wave -noupdate -height 15 -group DUT /tb/DUT/wait_write
add wave -noupdate -height 15 -group DUT /tb/DUT/wait_rnw
add wave -noupdate -height 15 -group DUT /tb/DUT/wait_start_gluclock
add wave -noupdate -height 15 -group DUT /tb/DUT/wait_start_comport
add wave -noupdate -height 15 -group DUT /tb/DUT/wait_end
add wave -noupdate -height 15 -group DUT /tb/DUT/gluclock_addr
add wave -noupdate -height 15 -group DUT /tb/DUT/comport_addr
add wave -noupdate -height 15 -group DUT /tb/DUT/waits
add wave -noupdate -height 15 -group DUT /tb/DUT/not_used0
add wave -noupdate -height 15 -group DUT /tb/DUT/not_used1
add wave -noupdate -height 15 -group DUT /tb/DUT/cfg_vga_on
add wave -noupdate -height 15 -group DUT /tb/DUT/modes_raster
add wave -noupdate -height 15 -group DUT /tb/DUT/mode_contend_type
add wave -noupdate -height 15 -group DUT /tb/DUT/mode_contend_ena
add wave -noupdate -height 15 -group DUT /tb/DUT/contend
add wave -noupdate -height 15 -group DUT /tb/DUT/fdd_mask
add wave -noupdate -height 15 -group DUT /tb/DUT/gen_nmi
add wave -noupdate -height 15 -group DUT /tb/DUT/clr_nmi
add wave -noupdate -height 15 -group DUT /tb/DUT/in_nmi
add wave -noupdate -height 15 -group DUT /tb/DUT/in_trdemu
add wave -noupdate -height 15 -group DUT /tb/DUT/set_nmi
add wave -noupdate -height 15 -group DUT /tb/DUT/imm_nmi
add wave -noupdate -height 15 -group DUT /tb/DUT/nmi_buf_clr
add wave -noupdate -height 15 -group DUT /tb/DUT/brk_ena
add wave -noupdate -height 15 -group DUT /tb/DUT/brk_addr
add wave -noupdate -height 15 -group DUT /tb/DUT/tape_in
add wave -noupdate -height 15 -group DUT /tb/DUT/ideout
add wave -noupdate -height 15 -group DUT /tb/DUT/idein
add wave -noupdate -height 15 -group DUT /tb/DUT/idedataout
add wave -noupdate -height 15 -group DUT /tb/DUT/zmem_dout
add wave -noupdate -height 15 -group DUT /tb/DUT/zmem_dataout
add wave -noupdate -height 15 -group DUT /tb/DUT/ayclk_gen
add wave -noupdate -height 15 -group DUT /tb/DUT/received
add wave -noupdate -height 15 -group DUT /tb/DUT/tobesent
add wave -noupdate -height 15 -group DUT /tb/DUT/intrq
add wave -noupdate -height 15 -group DUT /tb/DUT/drq
add wave -noupdate -height 15 -group DUT /tb/DUT/vg_wrFF_fclk
add wave -noupdate -height 15 -group DUT /tb/DUT/vg_rdwr_fclk
add wave -noupdate -height 15 -group DUT /tb/DUT/vg_ddrv
add wave -noupdate -height 15 -group DUT /tb/DUT/up_ena
add wave -noupdate -height 15 -group DUT /tb/DUT/up_paladdr
add wave -noupdate -height 15 -group DUT /tb/DUT/up_paldata
add wave -noupdate -height 15 -group DUT /tb/DUT/up_palwr
add wave -noupdate -height 15 -group DUT /tb/DUT/genrst
add wave -noupdate -height 15 -group DUT /tb/DUT/peff7
add wave -noupdate -height 15 -group DUT /tb/DUT/p7ffd
add wave -noupdate -height 15 -group DUT /tb/DUT/romrw_en
add wave -noupdate -height 15 -group DUT /tb/DUT/cpm_n
add wave -noupdate -height 15 -group DUT /tb/DUT/fnt_wr
add wave -noupdate -height 15 -group DUT /tb/DUT/cpu_req
add wave -noupdate -height 15 -group DUT /tb/DUT/cpu_rnw
add wave -noupdate -height 15 -group DUT /tb/DUT/cpu_wrbsel
add wave -noupdate -height 15 -group DUT /tb/DUT/cpu_strobe
add wave -noupdate -height 15 -group DUT /tb/DUT/cpu_addr
add wave -noupdate -height 15 -group DUT /tb/DUT/cpu_rddata
add wave -noupdate -height 15 -group DUT /tb/DUT/cpu_wrdata
add wave -noupdate -height 15 -group DUT /tb/DUT/cbeg
add wave -noupdate -height 15 -group DUT /tb/DUT/post_cbeg
add wave -noupdate -height 15 -group DUT /tb/DUT/pre_cend
add wave -noupdate -height 15 -group DUT /tb/DUT/cend
add wave -noupdate -height 15 -group DUT /tb/DUT/go
add wave -noupdate -height 15 -group DUT /tb/DUT/avr_lock_claim
add wave -noupdate -height 15 -group DUT /tb/DUT/avr_lock_grant
add wave -noupdate -height 15 -group DUT /tb/DUT/avr_sdcs_n
add wave -noupdate -height 15 -group DUT /tb/DUT/avr_sd_start
add wave -noupdate -height 15 -group DUT /tb/DUT/avr_sd_datain
add wave -noupdate -height 15 -group DUT /tb/DUT/avr_sd_dataout
add wave -noupdate -height 15 -group DUT /tb/DUT/zx_sdcs_n_val
add wave -noupdate -height 15 -group DUT /tb/DUT/zx_sdcs_n_stb
add wave -noupdate -height 15 -group DUT /tb/DUT/zx_sd_start
add wave -noupdate -height 15 -group DUT /tb/DUT/zx_sd_datain
add wave -noupdate -height 15 -group DUT /tb/DUT/zx_sd_dataout
add wave -noupdate -height 15 -group DUT /tb/DUT/tape_read
add wave -noupdate -height 15 -group DUT /tb/DUT/beeper_mux
add wave -noupdate -height 15 -group DUT /tb/DUT/atm_scr_mode
add wave -noupdate -height 15 -group DUT /tb/DUT/atm_turbo
add wave -noupdate -height 15 -group DUT /tb/DUT/beeper_wr
add wave -noupdate -height 15 -group DUT /tb/DUT/covox_wr
add wave -noupdate -height 15 -group DUT /tb/DUT/palcolor
add wave -noupdate -height 15 -group DUT /tb/DUT/int_turbo
add wave -noupdate -height 15 -group DUT /tb/DUT/cpu_next
add wave -noupdate -height 15 -group DUT /tb/DUT/cpu_stall
add wave -noupdate -height 15 -group DUT /tb/DUT/external_port
add wave -noupdate -height 15 -group DUT /tb/DUT/zclk_stall
add wave -noupdate -height 15 -group DUT /tb/DUT/dout_ram
add wave -noupdate -height 15 -group DUT /tb/DUT/ena_ram
add wave -noupdate -height 15 -group DUT /tb/DUT/dout_ports
add wave -noupdate -height 15 -group DUT /tb/DUT/ena_ports
add wave -noupdate -height 15 -group DUT /tb/DUT/border
add wave -noupdate -height 15 -group DUT /tb/DUT/drive_ff
add wave -noupdate -height 15 -group DUT /tb/DUT/drive_00
add wave -noupdate -height 15 -group DUT /tb/DUT/atm_palwr
add wave -noupdate -height 15 -group DUT /tb/DUT/atm_paldata
add wave -noupdate -height 15 -group DUT /tb/DUT/fontrom_readback
add wave -noupdate -height 15 -group DUT /tb/DUT/int_start
add wave -noupdate -height 15 -group DUT /tb/DUT/d_pre_out
add wave -noupdate -height 15 -group DUT /tb/DUT/d_ena
add wave -noupdate -height 15 -group DUT /tb/DUT/pager_off
add wave -noupdate -height 15 -group DUT /tb/DUT/pent1m_ROM
add wave -noupdate -height 15 -group DUT /tb/DUT/pent1m_page
add wave -noupdate -height 15 -group DUT /tb/DUT/pent1m_ram0_0
add wave -noupdate -height 15 -group DUT /tb/DUT/pent1m_1m_on
add wave -noupdate -height 15 -group DUT /tb/DUT/atmF7_wr_fclk
add wave -noupdate -height 15 -group DUT /tb/DUT/dos_turn_off
add wave -noupdate -height 15 -group DUT /tb/DUT/dos_turn_on
add wave -noupdate -height 15 -group DUT /tb/DUT/page
add wave -noupdate -height 15 -group DUT /tb/DUT/romnram
add wave -noupdate -height 15 -group DUT /tb/DUT/wrdisable
add wave -noupdate -height 15 -group DUT /tb/DUT/rd_pages
add wave -noupdate -height 15 -group DUT /tb/DUT/rd_ramnrom
add wave -noupdate -height 15 -group DUT /tb/DUT/rd_dos7ffd
add wave -noupdate -height 15 -group DUT /tb/DUT/rd_wrdisables
add wave -noupdate -height 15 -group DUT /tb/DUT/daddr
add wave -noupdate -height 15 -group DUT /tb/DUT/dreq
add wave -noupdate -height 15 -group DUT /tb/DUT/drnw
add wave -noupdate -height 15 -group DUT /tb/DUT/drddata
add wave -noupdate -height 15 -group DUT /tb/DUT/dwrdata
add wave -noupdate -height 15 -group DUT /tb/DUT/dbsel
add wave -noupdate -height 15 -group DUT /tb/DUT/drrdy
add wave -noupdate -height 15 -group DUT /tb/DUT/bw
add wave -noupdate -height 15 -group DUT /tb/DUT/video_addr
add wave -noupdate -height 15 -group DUT /tb/DUT/video_data
add wave -noupdate -height 15 -group DUT /tb/DUT/video_strobe
add wave -noupdate -height 15 -group DUT /tb/DUT/video_next
add wave -noupdate -height 15 -group DUT /tb/DUT/atm_pen2
add wave -noupdate -height 15 -group z80 /tb/z80/RESET_n
add wave -noupdate -height 15 -group z80 /tb/z80/CLK_n
add wave -noupdate -height 15 -group z80 /tb/z80/WAIT_n
add wave -noupdate -height 15 -group z80 /tb/z80/INT_n
add wave -noupdate -height 15 -group z80 /tb/z80/NMI_n
add wave -noupdate -height 15 -group z80 /tb/z80/BUSRQ_n
add wave -noupdate -height 15 -group z80 -color Yellow /tb/z80/IORQ_n
add wave -noupdate -height 15 -group z80 -color Yellow /tb/z80/WR_n
add wave -noupdate -height 15 -group z80 -color Yellow /tb/z80/RD_n
add wave -noupdate -height 15 -group z80 -color Cyan /tb/z80/M1_n
add wave -noupdate -height 15 -group z80 -color Cyan /tb/z80/MREQ_n
add wave -noupdate -height 15 -group z80 -color Cyan /tb/z80/RD_n
add wave -noupdate -height 15 -group z80 -color Cyan /tb/z80/WR_n
add wave -noupdate -height 15 -group z80 /tb/z80/RFSH_n
add wave -noupdate -height 15 -group z80 /tb/z80/HALT_n
add wave -noupdate -height 15 -group z80 /tb/z80/BUSAK_n
add wave -noupdate -height 15 -group z80 -radix hexadecimal /tb/z80/A
add wave -noupdate -height 15 -group z80 -radix hexadecimal /tb/z80/D
add wave -noupdate -height 15 -group z80 -radix hexadecimal /tb/z80/D_I
add wave -noupdate -height 15 -group z80 -radix hexadecimal /tb/z80/D_O
add wave -noupdate -height 15 -group z80 -radix hexadecimal /tb/z80/ResetPC
add wave -noupdate -height 15 -group z80 -radix hexadecimal /tb/z80/ResetSP
add wave -noupdate -height 15 -group z80 /tb/z80/CEN
add wave -noupdate -height 15 -group z80 /tb/z80/Reset_s
add wave -noupdate -height 15 -group z80 /tb/z80/IntCycle_n
add wave -noupdate -height 15 -group z80 /tb/z80/IORQ
add wave -noupdate -height 15 -group z80 /tb/z80/NoRead
add wave -noupdate -height 15 -group z80 /tb/z80/Write
add wave -noupdate -height 15 -group z80 /tb/z80/MREQ
add wave -noupdate -height 15 -group z80 /tb/z80/MReq_Inhibit
add wave -noupdate -height 15 -group z80 /tb/z80/Req_Inhibit
add wave -noupdate -height 15 -group z80 /tb/z80/RD
add wave -noupdate -height 15 -group z80 /tb/z80/MREQ_n_i
add wave -noupdate -height 15 -group z80 /tb/z80/IORQ_n_i
add wave -noupdate -height 15 -group z80 /tb/z80/RD_n_i
add wave -noupdate -height 15 -group z80 /tb/z80/WR_n_i
add wave -noupdate -height 15 -group z80 /tb/z80/RFSH_n_i
add wave -noupdate -height 15 -group z80 /tb/z80/BUSAK_n_i
add wave -noupdate -height 15 -group z80 -radix hexadecimal /tb/z80/A_i
add wave -noupdate -height 15 -group z80 -radix hexadecimal /tb/z80/DO
add wave -noupdate -height 15 -group z80 -radix hexadecimal /tb/z80/DI_Reg
add wave -noupdate -height 15 -group z80 /tb/z80/Wait_s
add wave -noupdate -height 15 -group z80 /tb/z80/MCycle
add wave -noupdate -height 15 -group z80 /tb/z80/TState
add wave -noupdate -height 15 -group zports /tb/DUT/zports/zclk
add wave -noupdate -height 15 -group zports /tb/DUT/zports/fclk
add wave -noupdate -height 15 -group zports /tb/DUT/zports/rst_n
add wave -noupdate -height 15 -group zports /tb/DUT/zports/zpos
add wave -noupdate -height 15 -group zports /tb/DUT/zports/zneg
add wave -noupdate -height 15 -group zports -radix hexadecimal /tb/DUT/zports/din
add wave -noupdate -height 15 -group zports /tb/DUT/zports/dout
add wave -noupdate -height 15 -group zports /tb/DUT/zports/dataout
add wave -noupdate -height 15 -group zports -radix hexadecimal /tb/DUT/zports/a
add wave -noupdate -height 15 -group zports /tb/DUT/zports/iorq_n
add wave -noupdate -height 15 -group zports /tb/DUT/zports/mreq_n
add wave -noupdate -height 15 -group zports /tb/DUT/zports/m1_n
add wave -noupdate -height 15 -group zports /tb/DUT/zports/rd_n
add wave -noupdate -height 15 -group zports /tb/DUT/zports/wr_n
add wave -noupdate -height 15 -group zports /tb/DUT/zports/porthit
add wave -noupdate -height 15 -group zports /tb/DUT/zports/external_port
add wave -noupdate -height 15 -group zports -radix hexadecimal /tb/DUT/zports/ideout
add wave -noupdate -height 15 -group zports -radix hexadecimal /tb/DUT/zports/idein
add wave -noupdate -height 15 -group zports /tb/DUT/zports/idedataout
add wave -noupdate -height 15 -group zports -radix hexadecimal /tb/DUT/zports/ide_a
add wave -noupdate -height 15 -group zports /tb/DUT/zports/ide_cs0_n
add wave -noupdate -height 15 -group zports /tb/DUT/zports/ide_cs1_n
add wave -noupdate -height 15 -group zports /tb/DUT/zports/ide_rd_n
add wave -noupdate -height 15 -group zports /tb/DUT/zports/ide_wr_n
add wave -noupdate -height 15 -group zports -radix hexadecimal /tb/DUT/zports/keys_in
add wave -noupdate -height 15 -group zports -radix hexadecimal /tb/DUT/zports/mus_in
add wave -noupdate -height 15 -group zports -radix hexadecimal /tb/DUT/zports/kj_in
add wave -noupdate -height 15 -group zports /tb/DUT/zports/border
add wave -noupdate -height 15 -group zports /tb/DUT/zports/dos
add wave -noupdate -height 15 -group zports /tb/DUT/zports/ay_bdir
add wave -noupdate -height 15 -group zports /tb/DUT/zports/ay_bc1
add wave -noupdate -height 15 -group zports -radix hexadecimal /tb/DUT/zports/p7ffd
add wave -noupdate -height 15 -group zports -radix hexadecimal /tb/DUT/zports/peff7
add wave -noupdate -height 15 -group zports /tb/DUT/zports/tape_read
add wave -noupdate -height 15 -group zports /tb/DUT/zports/vg_cs_n
add wave -noupdate -height 15 -group zports /tb/DUT/zports/vg_intrq
add wave -noupdate -height 15 -group zports /tb/DUT/zports/vg_drq
add wave -noupdate -height 15 -group zports /tb/DUT/zports/vg_wrFF_fclk
add wave -noupdate -height 15 -group zports /tb/DUT/zports/vg_rdwr_fclk
add wave -noupdate -height 15 -group zports /tb/DUT/zports/sd_cs_n_val
add wave -noupdate -height 15 -group zports /tb/DUT/zports/sd_cs_n_stb
add wave -noupdate -height 15 -group zports /tb/DUT/zports/sd_start
add wave -noupdate -height 15 -group zports -radix hexadecimal /tb/DUT/zports/sd_datain
add wave -noupdate -height 15 -group zports -radix hexadecimal /tb/DUT/zports/sd_dataout
add wave -noupdate -height 15 -group zports /tb/DUT/zports/gluclock_addr
add wave -noupdate -height 15 -group zports /tb/DUT/zports/comport_addr
add wave -noupdate -height 15 -group zports /tb/DUT/zports/wait_start_gluclock
add wave -noupdate -height 15 -group zports /tb/DUT/zports/wait_start_comport
add wave -noupdate -height 15 -group zports /tb/DUT/zports/wait_rnw
add wave -noupdate -height 15 -group zports /tb/DUT/zports/wait_write
add wave -noupdate -height 15 -group zports -radix hexadecimal /tb/DUT/zports/wait_read
add wave -noupdate -height 15 -group zports /tb/DUT/zports/atmF7_wr_fclk
add wave -noupdate -height 15 -group zports /tb/DUT/zports/atm_scr_mode
add wave -noupdate -height 15 -group zports /tb/DUT/zports/atm_turbo
add wave -noupdate -height 15 -group zports /tb/DUT/zports/atm_pen
add wave -noupdate -height 15 -group zports /tb/DUT/zports/atm_cpm_n
add wave -noupdate -height 15 -group zports /tb/DUT/zports/atm_pen2
add wave -noupdate -height 15 -group zports /tb/DUT/zports/romrw_en
add wave -noupdate -height 15 -group zports /tb/DUT/zports/pent1m_ram0_0
add wave -noupdate -height 15 -group zports /tb/DUT/zports/pent1m_1m_on
add wave -noupdate -height 15 -group zports -radix hexadecimal /tb/DUT/zports/pent1m_page
add wave -noupdate -height 15 -group zports /tb/DUT/zports/pent1m_ROM
add wave -noupdate -height 15 -group zports /tb/DUT/zports/atm_palwr
add wave -noupdate -height 15 -group zports -radix hexadecimal /tb/DUT/zports/atm_paldata
add wave -noupdate -height 15 -group zports /tb/DUT/zports/covox_wr
add wave -noupdate -height 15 -group zports /tb/DUT/zports/beeper_wr
add wave -noupdate -height 15 -group zports /tb/DUT/zports/clr_nmi
add wave -noupdate -height 15 -group zports /tb/DUT/zports/fnt_wr
add wave -noupdate -height 15 -group zports /tb/DUT/zports/pages
add wave -noupdate -height 15 -group zports /tb/DUT/zports/ramnroms
add wave -noupdate -height 15 -group zports /tb/DUT/zports/dos7ffds
add wave -noupdate -height 15 -group zports /tb/DUT/zports/wrdisables
add wave -noupdate -height 15 -group zports /tb/DUT/zports/palcolor
add wave -noupdate -height 15 -group zports -radix hexadecimal /tb/DUT/zports/fontrom_readback
add wave -noupdate -height 15 -group zports /tb/DUT/zports/up_ena
add wave -noupdate -height 15 -group zports /tb/DUT/zports/up_paladdr
add wave -noupdate -height 15 -group zports -radix hexadecimal /tb/DUT/zports/up_paldata
add wave -noupdate -height 15 -group zports /tb/DUT/zports/up_palwr
add wave -noupdate -height 15 -group zports /tb/DUT/zports/set_nmi
add wave -noupdate -height 15 -group zports /tb/DUT/zports/brk_ena
add wave -noupdate -height 15 -group zports /tb/DUT/zports/brk_addr
add wave -noupdate -height 15 -group zports /tb/DUT/zports/fdd_mask
add wave -noupdate -height 15 -group zports /tb/DUT/zports/port_wr
add wave -noupdate -height 15 -group zports /tb/DUT/zports/port_rd
add wave -noupdate -height 15 -group zports /tb/DUT/zports/iowr_reg
add wave -noupdate -height 15 -group zports /tb/DUT/zports/iord_reg
add wave -noupdate -height 15 -group zports /tb/DUT/zports/port_wr_fclk
add wave -noupdate -height 15 -group zports /tb/DUT/zports/port_rd_fclk
add wave -noupdate -height 15 -group zports /tb/DUT/zports/mem_wr_fclk
add wave -noupdate -height 15 -group zports /tb/DUT/zports/iowr_reg_fclk
add wave -noupdate -height 15 -group zports /tb/DUT/zports/iord_reg_fclk
add wave -noupdate -height 15 -group zports /tb/DUT/zports/memwr_reg_fclk
add wave -noupdate -height 15 -group zports /tb/DUT/zports/loa
add wave -noupdate -height 15 -group zports /tb/DUT/zports/ideout_hi_wr
add wave -noupdate -height 15 -group zports /tb/DUT/zports/idein_lo_rd
add wave -noupdate -height 15 -group zports /tb/DUT/zports/idehiin
add wave -noupdate -height 15 -group zports /tb/DUT/zports/ide_ports
add wave -noupdate -height 15 -group zports /tb/DUT/zports/ide_rd_trig
add wave -noupdate -height 15 -group zports /tb/DUT/zports/ide_rd_latch
add wave -noupdate -height 15 -group zports /tb/DUT/zports/ide_wrlo_trig
add wave -noupdate -height 15 -group zports /tb/DUT/zports/ide_wrhi_trig
add wave -noupdate -height 15 -group zports /tb/DUT/zports/ide_wrlo_latch
add wave -noupdate -height 15 -group zports /tb/DUT/zports/ide_wrhi_latch
add wave -noupdate -height 15 -group zports /tb/DUT/zports/idewrreg
add wave -noupdate -height 15 -group zports /tb/DUT/zports/iderdeven
add wave -noupdate -height 15 -group zports /tb/DUT/zports/iderdodd
add wave -noupdate -height 15 -group zports /tb/DUT/zports/pre_bc1
add wave -noupdate -height 15 -group zports /tb/DUT/zports/pre_bdir
add wave -noupdate -height 15 -group zports /tb/DUT/zports/gluclock_on
add wave -noupdate -height 15 -group zports /tb/DUT/zports/shadow_en_reg
add wave -noupdate -height 15 -group zports /tb/DUT/zports/romrw_en_reg
add wave -noupdate -height 15 -group zports /tb/DUT/zports/fntw_en_reg
add wave -noupdate -height 15 -group zports /tb/DUT/zports/shadow
add wave -noupdate -height 15 -group zports /tb/DUT/zports/portbdmux
add wave -noupdate -height 15 -group zports /tb/DUT/zports/up_lastwritten
add wave -noupdate -height 15 -group zports /tb/DUT/zports/portfd_wr
add wave -noupdate -height 15 -group zports /tb/DUT/zports/portf7_wr
add wave -noupdate -height 15 -group zports /tb/DUT/zports/portf7_rd
add wave -noupdate -height 15 -group zports /tb/DUT/zports/comport_wr
add wave -noupdate -height 15 -group zports /tb/DUT/zports/comport_rd
add wave -noupdate -height 15 -group zports /tb/DUT/zports/zxevbd_wr_fclk
add wave -noupdate -height 15 -group zports /tb/DUT/zports/portwe_wr_fclk
add wave -noupdate -height 15 -group zports /tb/DUT/zports/portfe_wr_fclk
add wave -noupdate -height 15 -group zports /tb/DUT/zports/p7ffd_int
add wave -noupdate -height 15 -group zports /tb/DUT/zports/peff7_int
add wave -noupdate -height 15 -group zports /tb/DUT/zports/p7ffd_rom_int
add wave -noupdate -height 15 -group zports /tb/DUT/zports/block7ffd
add wave -noupdate -height 15 -group zports /tb/DUT/zports/block1m
add wave -noupdate -height 15 -group zports /tb/DUT/zports/sdcfg_wr
add wave -noupdate -height 15 -group zports /tb/DUT/zports/sddat_wr
add wave -noupdate -height 15 -group zports /tb/DUT/zports/sddat_rd
add wave -noupdate -height 15 -group zports /tb/DUT/zports/atm77_wr_fclk
add wave -noupdate -height 15 -group zports /tb/DUT/zports/zxevbf_wr_fclk
add wave -noupdate -height 15 -group zports /tb/DUT/zports/up_select
add wave -noupdate -height 15 -group zports /tb/DUT/zports/up_wr
add wave -noupdate -height 15 -group zdos /tb/DUT/zdos/fclk
add wave -noupdate -height 15 -group zdos /tb/DUT/zdos/rst_n
add wave -noupdate -height 15 -group zdos /tb/DUT/zdos/dos_turn_on
add wave -noupdate -height 15 -group zdos /tb/DUT/zdos/dos_turn_off
add wave -noupdate -height 15 -group zdos /tb/DUT/zdos/cpm_n
add wave -noupdate -height 15 -group zdos /tb/DUT/zdos/dos
add wave -noupdate -height 15 -group zdos /tb/DUT/zdos/in_trdemu
add wave -noupdate -height 15 -group zdos /tb/DUT/zdos/clr_nmi
add wave -noupdate -height 15 -group zdos /tb/DUT/zdos/vg_rdwr_fclk
add wave -noupdate -height 15 -group zdos /tb/DUT/zdos/fdd_mask
add wave -noupdate -height 15 -group zdos /tb/DUT/zdos/vg_a
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/zclk
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/rst_n
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/fclk
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/vg_clk
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/vg_res_n
add wave -noupdate -height 15 -group vg93 -radix hexadecimal /tb/DUT/vgshka/din
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/intrq
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/drq
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/vg_wrFF_fclk
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/vg_hrdy
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/vg_rclk
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/vg_rawr
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/vg_a
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/vg_wrd
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/vg_side
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/step
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/vg_sl
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/vg_sr
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/vg_tr43
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/rdat_n
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/vg_wf_de
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/vg_drq
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/vg_irq
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/vg_wd
add wave -noupdate -height 15 -group vg93 -radix hexadecimal /tb/DUT/vgshka/vgclk_div7
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/vgclk_strobe7
add wave -noupdate -height 15 -group vg93 -radix hexadecimal /tb/DUT/vgshka/vgclk_div4
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/step_pulse
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/drq_pulse
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/step_pospulse
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/drq_pospulse
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/turbo_state
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/intrq_sync
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/drq_sync
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/sl_sync
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/sr_sync
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/tr43_sync
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/wd_sync
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/sl
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/sr
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/tr43
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/wd
add wave -noupdate -height 15 -group vg93 -radix hexadecimal /tb/DUT/vgshka/wrdelay_cnt
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/delay_end
add wave -noupdate -height 15 -group vg93 -radix hexadecimal /tb/DUT/vgshka/wrwidth_cnt
add wave -noupdate -height 15 -group vg93 /tb/DUT/vgshka/wrwidth_ena
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/rst_n}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/fclk}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/zpos}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/zneg}
add wave -noupdate -expand -group pager_0000 /tb/DUT/zclk
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/m1_n}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/mreq_n}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/rd_n}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/za}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/zd}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/pager_off}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/pent1m_ROM}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/pent1m_page}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/pent1m_ram0_0}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/pent1m_1m_on}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/in_nmi}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/in_trdemu}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/trdemu_wr_disable}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/wrdisable}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/atmF7_wr}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/dos}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/dos_turn_on}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/dos_turn_off}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/zclk_stall}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/page}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/romnram}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/rd_page0}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/rd_page1}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/rd_dos7ffd}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/rd_ramnrom}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/rd_wrdisables}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/ramnrom}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/dos_7ffd}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/wrdisables}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/mreq_n_reg}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/rd_n_reg}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/m1_n_reg}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/dos_exec_stb}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/ram_exec_stb}
add wave -noupdate -expand -group pager_0000 {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/stall_count}
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {119996445051 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 514
configure wave -valuecolwidth 100
configure wave -justifyvalue left
configure wave -signalnamewidth 0
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 17800
configure wave -gridperiod 35600
configure wave -griddelta 8
configure wave -timeline 1
configure wave -timelineunits ns
update
WaveRestoreZoom {162001374572 ps} {162004962918 ps}
