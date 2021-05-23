onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -height 19 -group main_old /tb/DUT/zclock/zpos
add wave -noupdate -height 19 -group main_old /tb/DUT/zclock/zneg
add wave -noupdate -height 19 -group main_old /tb/z80/BUSRQ_n
add wave -noupdate -height 19 -group main_old /tb/z80/BUSAK_n
add wave -noupdate -height 19 -group main_old /tb/DUT/z80mem/r_mreq_n
add wave -noupdate -height 19 -group main_old /tb/DUT/external_port
add wave -noupdate -height 19 -group main_old /tb/clkz_in
add wave -noupdate -height 19 -group main_old /tb/iorq_n
add wave -noupdate -height 19 -group main_old /tb/mreq_n
add wave -noupdate -height 19 -group main_old /tb/rd_n
add wave -noupdate -height 19 -group main_old /tb/wr_n
add wave -noupdate -height 19 -group main_old /tb/m1_n
add wave -noupdate -height 19 -group main_old /tb/rfsh_n
add wave -noupdate -height 19 -group main_old /tb/int_n
add wave -noupdate -height 19 -group main_old /tb/nmi_n
add wave -noupdate -height 19 -group main_old /tb/wait_n
add wave -noupdate -height 19 -group main_old -radix hexadecimal /tb/za
add wave -noupdate -height 19 -group main_old -radix hexadecimal /tb/zd
add wave -noupdate -height 19 -group main_old -radix hexadecimal /tb/zd_dut_to_z80
add wave -noupdate -height 19 -group main_old /tb/csrom
add wave -noupdate -height 19 -group main_old /tb/romoe_n
add wave -noupdate -height 19 -group main_old /tb/romwe_n
add wave -noupdate -height 19 -group main_old -radix hexadecimal /tb/z80/u0/IR
add wave -noupdate -height 19 -group dut_old /tb/DUT/res
add wave -noupdate -height 19 -group dut_old /tb/DUT/fclk
add wave -noupdate -height 19 -group dut_old /tb/DUT/clkz_out
add wave -noupdate -height 19 -group dut_old /tb/DUT/clkz_in
add wave -noupdate -height 19 -group dut_old /tb/DUT/iorq_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/mreq_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/rd_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/wr_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/m1_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/rfsh_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/int_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/nmi_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/wait_n
add wave -noupdate -height 19 -group dut_old -radix hexadecimal /tb/DUT/d
add wave -noupdate -height 19 -group dut_old -radix hexadecimal /tb/DUT/a
add wave -noupdate -height 19 -group dut_old /tb/DUT/csrom
add wave -noupdate -height 19 -group dut_old /tb/DUT/romoe_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/romwe_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/rompg0_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/dos_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/rompg2
add wave -noupdate -height 19 -group dut_old /tb/DUT/rompg3
add wave -noupdate -height 19 -group dut_old /tb/DUT/rompg4
add wave -noupdate -height 19 -group dut_old /tb/DUT/iorqge1
add wave -noupdate -height 19 -group dut_old /tb/DUT/iorqge2
add wave -noupdate -height 19 -group dut_old /tb/DUT/iorq1_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/iorq2_n
add wave -noupdate -height 19 -group dut_old -radix hexadecimal /tb/DUT/rd
add wave -noupdate -height 19 -group dut_old -radix hexadecimal /tb/DUT/ra
add wave -noupdate -height 19 -group dut_old /tb/DUT/rwe_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/rucas_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/rlcas_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/rras0_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/rras1_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/vred
add wave -noupdate -height 19 -group dut_old /tb/DUT/vgrn
add wave -noupdate -height 19 -group dut_old /tb/DUT/vblu
add wave -noupdate -height 19 -group dut_old /tb/DUT/vhsync
add wave -noupdate -height 19 -group dut_old /tb/DUT/vvsync
add wave -noupdate -height 19 -group dut_old /tb/DUT/vcsync
add wave -noupdate -height 19 -group dut_old /tb/DUT/ay_clk
add wave -noupdate -height 19 -group dut_old /tb/DUT/ay_bdir
add wave -noupdate -height 19 -group dut_old /tb/DUT/ay_bc1
add wave -noupdate -height 19 -group dut_old /tb/DUT/beep
add wave -noupdate -height 19 -group dut_old /tb/DUT/ide_a
add wave -noupdate -height 19 -group dut_old /tb/DUT/ide_d
add wave -noupdate -height 19 -group dut_old /tb/DUT/ide_dir
add wave -noupdate -height 19 -group dut_old /tb/DUT/ide_rdy
add wave -noupdate -height 19 -group dut_old /tb/DUT/ide_cs0_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/ide_cs1_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/ide_rs_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/ide_rd_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/ide_wr_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/vg_clk
add wave -noupdate -height 19 -group dut_old /tb/DUT/vg_cs_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/vg_res_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/vg_hrdy
add wave -noupdate -height 19 -group dut_old /tb/DUT/vg_rclk
add wave -noupdate -height 19 -group dut_old /tb/DUT/vg_rawr
add wave -noupdate -height 19 -group dut_old /tb/DUT/vg_a
add wave -noupdate -height 19 -group dut_old /tb/DUT/vg_wrd
add wave -noupdate -height 19 -group dut_old /tb/DUT/vg_side
add wave -noupdate -height 19 -group dut_old /tb/DUT/step
add wave -noupdate -height 19 -group dut_old /tb/DUT/vg_sl
add wave -noupdate -height 19 -group dut_old /tb/DUT/vg_sr
add wave -noupdate -height 19 -group dut_old /tb/DUT/vg_tr43
add wave -noupdate -height 19 -group dut_old /tb/DUT/rdat_b_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/vg_wf_de
add wave -noupdate -height 19 -group dut_old /tb/DUT/vg_drq
add wave -noupdate -height 19 -group dut_old /tb/DUT/vg_irq
add wave -noupdate -height 19 -group dut_old /tb/DUT/vg_wd
add wave -noupdate -height 19 -group dut_old /tb/DUT/sdcs_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/sddo
add wave -noupdate -height 19 -group dut_old /tb/DUT/sdclk
add wave -noupdate -height 19 -group dut_old /tb/DUT/sddi
add wave -noupdate -height 19 -group dut_old /tb/DUT/spics_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/spick
add wave -noupdate -height 19 -group dut_old /tb/DUT/spido
add wave -noupdate -height 19 -group dut_old /tb/DUT/spidi
add wave -noupdate -height 19 -group dut_old /tb/DUT/spiint_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/dos
add wave -noupdate -height 19 -group dut_old /tb/DUT/zclk
add wave -noupdate -height 19 -group dut_old /tb/DUT/zpos
add wave -noupdate -height 19 -group dut_old /tb/DUT/zneg
add wave -noupdate -height 19 -group dut_old /tb/DUT/rst_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/rrdy
add wave -noupdate -height 19 -group dut_old /tb/DUT/rddata
add wave -noupdate -height 19 -group dut_old /tb/DUT/rompg
add wave -noupdate -height 19 -group dut_old /tb/DUT/zports_dout
add wave -noupdate -height 19 -group dut_old /tb/DUT/zports_dataout
add wave -noupdate -height 19 -group dut_old /tb/DUT/porthit
add wave -noupdate -height 19 -group dut_old /tb/DUT/csrom_int
add wave -noupdate -height 19 -group dut_old /tb/DUT/kbd_data
add wave -noupdate -height 19 -group dut_old /tb/DUT/mus_data
add wave -noupdate -height 19 -group dut_old /tb/DUT/kbd_stb
add wave -noupdate -height 19 -group dut_old /tb/DUT/mus_xstb
add wave -noupdate -height 19 -group dut_old /tb/DUT/mus_ystb
add wave -noupdate -height 19 -group dut_old /tb/DUT/mus_btnstb
add wave -noupdate -height 19 -group dut_old /tb/DUT/kj_stb
add wave -noupdate -height 19 -group dut_old /tb/DUT/kbd_port_data
add wave -noupdate -height 19 -group dut_old /tb/DUT/kj_port_data
add wave -noupdate -height 19 -group dut_old /tb/DUT/mus_port_data
add wave -noupdate -height 19 -group dut_old /tb/DUT/wait_read
add wave -noupdate -height 19 -group dut_old /tb/DUT/wait_write
add wave -noupdate -height 19 -group dut_old /tb/DUT/wait_rnw
add wave -noupdate -height 19 -group dut_old /tb/DUT/wait_start_gluclock
add wave -noupdate -height 19 -group dut_old /tb/DUT/wait_start_comport
add wave -noupdate -height 19 -group dut_old /tb/DUT/wait_end
add wave -noupdate -height 19 -group dut_old /tb/DUT/gluclock_addr
add wave -noupdate -height 19 -group dut_old /tb/DUT/comport_addr
add wave -noupdate -height 19 -group dut_old /tb/DUT/waits
add wave -noupdate -height 19 -group dut_old /tb/DUT/cfg_vga_on
add wave -noupdate -height 19 -group dut_old /tb/DUT/modes_raster
add wave -noupdate -height 19 -group dut_old /tb/DUT/mode_contend_type
add wave -noupdate -height 19 -group dut_old /tb/DUT/mode_contend_ena
add wave -noupdate -height 19 -group dut_old /tb/DUT/contend
add wave -noupdate -height 19 -group dut_old /tb/DUT/gen_nmi
add wave -noupdate -height 19 -group dut_old /tb/DUT/clr_nmi
add wave -noupdate -height 19 -group dut_old /tb/DUT/in_nmi
add wave -noupdate -height 19 -group dut_old /tb/DUT/set_nmi
add wave -noupdate -height 19 -group dut_old /tb/DUT/imm_nmi
add wave -noupdate -height 19 -group dut_old /tb/DUT/brk_ena
add wave -noupdate -height 19 -group dut_old /tb/DUT/brk_addr
add wave -noupdate -height 19 -group dut_old /tb/DUT/tape_in
add wave -noupdate -height 19 -group dut_old /tb/DUT/ideout
add wave -noupdate -height 19 -group dut_old /tb/DUT/idein
add wave -noupdate -height 19 -group dut_old /tb/DUT/idedataout
add wave -noupdate -height 19 -group dut_old /tb/DUT/zmem_dout
add wave -noupdate -height 19 -group dut_old /tb/DUT/zmem_dataout
add wave -noupdate -height 19 -group dut_old /tb/DUT/ayclk_gen
add wave -noupdate -height 19 -group dut_old /tb/DUT/received
add wave -noupdate -height 19 -group dut_old /tb/DUT/tobesent
add wave -noupdate -height 19 -group dut_old /tb/DUT/intrq
add wave -noupdate -height 19 -group dut_old /tb/DUT/drq
add wave -noupdate -height 19 -group dut_old /tb/DUT/up_ena
add wave -noupdate -height 19 -group dut_old /tb/DUT/up_paladdr
add wave -noupdate -height 19 -group dut_old /tb/DUT/up_paldata
add wave -noupdate -height 19 -group dut_old /tb/DUT/up_palwr
add wave -noupdate -height 19 -group dut_old /tb/DUT/genrst
add wave -noupdate -height 19 -group dut_old /tb/DUT/peff7
add wave -noupdate -height 19 -group dut_old /tb/DUT/p7ffd
add wave -noupdate -height 19 -group dut_old /tb/DUT/romrw_en
add wave -noupdate -height 19 -group dut_old /tb/DUT/cpm_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/fnt_wr
add wave -noupdate -height 19 -group dut_old /tb/DUT/cpu_req
add wave -noupdate -height 19 -group dut_old /tb/DUT/cpu_rnw
add wave -noupdate -height 19 -group dut_old /tb/DUT/cpu_wrbsel
add wave -noupdate -height 19 -group dut_old /tb/DUT/cpu_strobe
add wave -noupdate -height 19 -group dut_old -radix hexadecimal /tb/DUT/cpu_addr
add wave -noupdate -height 19 -group dut_old -radix hexadecimal /tb/DUT/cpu_rddata
add wave -noupdate -height 19 -group dut_old -radix hexadecimal /tb/DUT/cpu_wrdata
add wave -noupdate -height 19 -group dut_old /tb/DUT/cbeg
add wave -noupdate -height 19 -group dut_old /tb/DUT/post_cbeg
add wave -noupdate -height 19 -group dut_old /tb/DUT/pre_cend
add wave -noupdate -height 19 -group dut_old /tb/DUT/cend
add wave -noupdate -height 19 -group dut_old /tb/DUT/go
add wave -noupdate -height 19 -group dut_old /tb/DUT/avr_lock_claim
add wave -noupdate -height 19 -group dut_old /tb/DUT/avr_lock_grant
add wave -noupdate -height 19 -group dut_old /tb/DUT/avr_sdcs_n
add wave -noupdate -height 19 -group dut_old /tb/DUT/avr_sd_start
add wave -noupdate -height 19 -group dut_old /tb/DUT/avr_sd_datain
add wave -noupdate -height 19 -group dut_old /tb/DUT/avr_sd_dataout
add wave -noupdate -height 19 -group dut_old /tb/DUT/zx_sdcs_n_val
add wave -noupdate -height 19 -group dut_old /tb/DUT/zx_sdcs_n_stb
add wave -noupdate -height 19 -group dut_old /tb/DUT/zx_sd_start
add wave -noupdate -height 19 -group dut_old /tb/DUT/zx_sd_datain
add wave -noupdate -height 19 -group dut_old /tb/DUT/zx_sd_dataout
add wave -noupdate -height 19 -group dut_old /tb/DUT/tape_read
add wave -noupdate -height 19 -group dut_old /tb/DUT/beeper_mux
add wave -noupdate -height 19 -group dut_old /tb/DUT/atm_scr_mode
add wave -noupdate -height 19 -group dut_old /tb/DUT/atm_turbo
add wave -noupdate -height 19 -group dut_old /tb/DUT/beeper_wr
add wave -noupdate -height 19 -group dut_old /tb/DUT/covox_wr
add wave -noupdate -height 19 -group dut_old /tb/DUT/palcolor
add wave -noupdate -height 19 -group dut_old /tb/DUT/int_turbo
add wave -noupdate -height 19 -group dut_old /tb/DUT/cpu_next
add wave -noupdate -height 19 -group dut_old /tb/DUT/cpu_stall
add wave -noupdate -height 19 -group dut_old /tb/DUT/external_port
add wave -noupdate -height 19 -group dut_old /tb/DUT/zclk_stall
add wave -noupdate -height 19 -group dut_old /tb/DUT/dout_ram
add wave -noupdate -height 19 -group dut_old /tb/DUT/ena_ram
add wave -noupdate -height 19 -group dut_old /tb/DUT/dout_ports
add wave -noupdate -height 19 -group dut_old /tb/DUT/ena_ports
add wave -noupdate -height 19 -group dut_old /tb/DUT/border
add wave -noupdate -height 19 -group dut_old /tb/DUT/drive_ff
add wave -noupdate -height 19 -group dut_old /tb/DUT/drive_00
add wave -noupdate -height 19 -group dut_old /tb/DUT/atm_palwr
add wave -noupdate -height 19 -group dut_old /tb/DUT/atm_paldata
add wave -noupdate -height 19 -group dut_old /tb/DUT/fontrom_readback
add wave -noupdate -height 19 -group dut_old /tb/DUT/int_start
add wave -noupdate -height 19 -group dut_old /tb/DUT/pager_off
add wave -noupdate -height 19 -group dut_old /tb/DUT/pent1m_ROM
add wave -noupdate -height 19 -group dut_old /tb/DUT/pent1m_page
add wave -noupdate -height 19 -group dut_old /tb/DUT/pent1m_ram0_0
add wave -noupdate -height 19 -group dut_old /tb/DUT/pent1m_1m_on
add wave -noupdate -height 19 -group dut_old /tb/DUT/atmF7_wr_fclk
add wave -noupdate -height 19 -group dut_old /tb/DUT/dos_turn_off
add wave -noupdate -height 19 -group dut_old /tb/DUT/dos_turn_on
add wave -noupdate -height 19 -group dut_old /tb/DUT/page
add wave -noupdate -height 19 -group dut_old /tb/DUT/romnram
add wave -noupdate -height 19 -group dut_old -expand /tb/DUT/wrdisable
add wave -noupdate -height 19 -group dut_old /tb/DUT/rd_pages
add wave -noupdate -height 19 -group dut_old /tb/DUT/rd_ramnrom
add wave -noupdate -height 19 -group dut_old /tb/DUT/rd_dos7ffd
add wave -noupdate -height 19 -group dut_old /tb/DUT/rd_wrdisables
add wave -noupdate -height 19 -group dut_old /tb/DUT/daddr
add wave -noupdate -height 19 -group dut_old /tb/DUT/dreq
add wave -noupdate -height 19 -group dut_old /tb/DUT/drnw
add wave -noupdate -height 19 -group dut_old /tb/DUT/drddata
add wave -noupdate -height 19 -group dut_old /tb/DUT/dwrdata
add wave -noupdate -height 19 -group dut_old /tb/DUT/dbsel
add wave -noupdate -height 19 -group dut_old /tb/DUT/drrdy
add wave -noupdate -height 19 -group dut_old /tb/DUT/bw
add wave -noupdate -height 19 -group dut_old /tb/DUT/video_addr
add wave -noupdate -height 19 -group dut_old /tb/DUT/video_data
add wave -noupdate -height 19 -group dut_old /tb/DUT/video_strobe
add wave -noupdate -height 19 -group dut_old /tb/DUT/video_next
add wave -noupdate -height 19 -group dut_old /tb/DUT/atm_pen2
add wave -noupdate -height 19 -group dut_old /tb/DUT/vg_ddrv
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/rst_n}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/fclk}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/zpos}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/zneg}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/za}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/zd}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/mreq_n}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/rd_n}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/m1_n}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/pager_off}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/pent1m_ROM}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/pent1m_page}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/pent1m_ram0_0}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/pent1m_1m_on}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/in_nmi}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/atmF7_wr}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/dos}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/dos_turn_on}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/dos_turn_off}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/zclk_stall}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/page}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/romnram}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/wrdisable}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/rd_page0}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/rd_page1}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/rd_dos7ffd}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/rd_ramnrom}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/rd_wrdisables}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/ramnrom}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/dos_7ffd}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/wrdisables}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/mreq_n_reg}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/rd_n_reg}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/m1_n_reg}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/dos_exec_stb}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/ram_exec_stb}
add wave -noupdate -height 19 -group pagers0_old {/tb/DUT/instantiate_atm_pagers[0]/atm_pager/stall_count}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/rst_n}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/fclk}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/zpos}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/zneg}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/za}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/zd}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/mreq_n}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/rd_n}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/m1_n}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/pager_off}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/pent1m_ROM}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/pent1m_page}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/pent1m_ram0_0}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/pent1m_1m_on}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/in_nmi}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/atmF7_wr}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/dos}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/dos_turn_on}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/dos_turn_off}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/zclk_stall}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/page}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/romnram}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/wrdisable}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/rd_page0}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/rd_page1}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/rd_dos7ffd}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/rd_ramnrom}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/rd_wrdisables}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/ramnrom}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/dos_7ffd}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/wrdisables}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/mreq_n_reg}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/rd_n_reg}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/m1_n_reg}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/dos_exec_stb}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/ram_exec_stb}
add wave -noupdate -height 19 -group pagers1_old {/tb/DUT/instantiate_atm_pagers[1]/atm_pager/stall_count}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/rst_n}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/fclk}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/zpos}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/zneg}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/za}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/zd}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/mreq_n}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/rd_n}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/m1_n}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/pager_off}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/pent1m_ROM}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/pent1m_page}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/pent1m_ram0_0}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/pent1m_1m_on}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/in_nmi}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/atmF7_wr}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/dos}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/dos_turn_on}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/dos_turn_off}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/zclk_stall}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/page}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/romnram}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/wrdisable}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/rd_page0}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/rd_page1}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/rd_dos7ffd}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/rd_ramnrom}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/rd_wrdisables}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/ramnrom}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/dos_7ffd}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/wrdisables}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/mreq_n_reg}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/rd_n_reg}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/m1_n_reg}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/dos_exec_stb}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/ram_exec_stb}
add wave -noupdate -height 19 -group pagers2_old {/tb/DUT/instantiate_atm_pagers[2]/atm_pager/stall_count}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/rst_n}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/fclk}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/zpos}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/zneg}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/za}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/zd}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/mreq_n}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/rd_n}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/m1_n}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/pager_off}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/pent1m_ROM}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/pent1m_page}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/pent1m_ram0_0}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/pent1m_1m_on}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/in_nmi}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/atmF7_wr}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/dos}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/dos_turn_on}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/dos_turn_off}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/zclk_stall}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/page}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/romnram}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/wrdisable}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/rd_page0}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/rd_page1}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/rd_dos7ffd}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/rd_ramnrom}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/rd_wrdisables}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/ramnrom}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/dos_7ffd}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/wrdisables}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/mreq_n_reg}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/rd_n_reg}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/m1_n_reg}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/dos_exec_stb}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/ram_exec_stb}
add wave -noupdate -height 19 -group pagers3_old {/tb/DUT/instantiate_atm_pagers[3]/atm_pager/stall_count}
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/rst_n
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/fclk
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/zpos
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/zneg
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/int_start
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/set_nmi
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/imm_nmi
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/clr_nmi
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/rfsh_n
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/m1_n
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/mreq_n
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/csrom
add wave -noupdate -height 19 -group znmi_old -radix hexadecimal /tb/DUT/znmi/a
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/drive_00
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/in_nmi
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/gen_nmi
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/set_nmi_r
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/set_nmi_now
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/imm_nmi_r
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/imm_nmi_now
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/pending_nmi
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/in_nmi_2
add wave -noupdate -height 19 -group znmi_old -radix hexadecimal /tb/DUT/znmi/nmi_count
add wave -noupdate -height 19 -group znmi_old -radix hexadecimal /tb/DUT/znmi/clr_count
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/pending_clr
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/last_m1_rom
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/last_m1_0066
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/nmi_start
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/m1_n_reg
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/mreq_n_reg
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/rfsh_n_reg
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/was_m1
add wave -noupdate -height 19 -group znmi_old /tb/DUT/znmi/was_m1_reg
add wave -noupdate -group t80_regs /tb/z80/u0/Regs/AddrA
add wave -noupdate -group t80_regs /tb/z80/u0/Regs/AddrB
add wave -noupdate -group t80_regs /tb/z80/u0/Regs/AddrC
add wave -noupdate -group t80_regs /tb/z80/u0/Regs/DIH
add wave -noupdate -group t80_regs /tb/z80/u0/Regs/DIL
add wave -noupdate -group t80_regs /tb/z80/u0/Regs/DOAH
add wave -noupdate -group t80_regs /tb/z80/u0/Regs/DOAL
add wave -noupdate -group t80_regs /tb/z80/u0/Regs/DOBH
add wave -noupdate -group t80_regs /tb/z80/u0/Regs/DOBL
add wave -noupdate -group t80_regs /tb/z80/u0/Regs/DOCH
add wave -noupdate -group t80_regs /tb/z80/u0/Regs/DOCL
add wave -noupdate -group t80_regs -expand /tb/z80/u0/Regs/RegsH
add wave -noupdate -group t80_regs -expand /tb/z80/u0/Regs/RegsL
add wave -noupdate -group t80_regs /tb/z80/u0/Regs/Clk
add wave -noupdate -height 19 -group t80 /tb/z80/u0/RESET_n
add wave -noupdate -height 19 -group t80 /tb/z80/u0/CLK_n
add wave -noupdate -height 19 -group t80 /tb/z80/u0/CEN
add wave -noupdate -height 19 -group t80 /tb/z80/u0/WAIT_n
add wave -noupdate -height 19 -group t80 /tb/z80/u0/INT_n
add wave -noupdate -height 19 -group t80 /tb/z80/u0/NMI_n
add wave -noupdate -height 19 -group t80 /tb/z80/u0/BUSRQ_n
add wave -noupdate -height 19 -group t80 /tb/z80/u0/M1_n
add wave -noupdate -height 19 -group t80 /tb/z80/u0/IORQ
add wave -noupdate -height 19 -group t80 /tb/z80/u0/NoRead
add wave -noupdate -height 19 -group t80 /tb/z80/u0/Write
add wave -noupdate -height 19 -group t80 /tb/z80/u0/RFSH_n
add wave -noupdate -height 19 -group t80 /tb/z80/u0/HALT_n
add wave -noupdate -height 19 -group t80 /tb/z80/u0/BUSAK_n
add wave -noupdate -height 19 -group t80 /tb/z80/u0/A
add wave -noupdate -height 19 -group t80 /tb/z80/u0/DInst
add wave -noupdate -height 19 -group t80 /tb/z80/u0/DI
add wave -noupdate -height 19 -group t80 /tb/z80/u0/DO
add wave -noupdate -height 19 -group t80 /tb/z80/u0/MC
add wave -noupdate -height 19 -group t80 /tb/z80/u0/TS
add wave -noupdate -height 19 -group t80 /tb/z80/u0/IntCycle_n
add wave -noupdate -height 19 -group t80 /tb/z80/u0/IntE
add wave -noupdate -height 19 -group t80 /tb/z80/u0/Stop
add wave -noupdate -height 19 -group t80 /tb/z80/u0/ResetPC
add wave -noupdate -height 19 -group t80 /tb/z80/u0/ResetSP
add wave -noupdate -height 19 -group t80 /tb/z80/u0/ACC
add wave -noupdate -height 19 -group t80 /tb/z80/u0/F
add wave -noupdate -height 19 -group t80 /tb/z80/u0/Ap
add wave -noupdate -height 19 -group t80 /tb/z80/u0/Fp
add wave -noupdate -height 19 -group t80 /tb/z80/u0/I
add wave -noupdate -height 19 -group t80 /tb/z80/u0/R
add wave -noupdate -height 19 -group t80 /tb/z80/u0/SP
add wave -noupdate -height 19 -group t80 /tb/z80/u0/PC
add wave -noupdate -height 19 -group t80 /tb/z80/u0/RegDIH
add wave -noupdate -height 19 -group t80 /tb/z80/u0/RegDIL
add wave -noupdate -height 19 -group t80 /tb/z80/u0/RegBusA
add wave -noupdate -height 19 -group t80 /tb/z80/u0/RegBusB
add wave -noupdate -height 19 -group t80 /tb/z80/u0/RegBusC
add wave -noupdate -height 19 -group t80 /tb/z80/u0/RegAddrA_r
add wave -noupdate -height 19 -group t80 /tb/z80/u0/RegAddrA
add wave -noupdate -height 19 -group t80 /tb/z80/u0/RegAddrB_r
add wave -noupdate -height 19 -group t80 /tb/z80/u0/RegAddrB
add wave -noupdate -height 19 -group t80 /tb/z80/u0/RegAddrC
add wave -noupdate -height 19 -group t80 /tb/z80/u0/RegWEH
add wave -noupdate -height 19 -group t80 /tb/z80/u0/RegWEL
add wave -noupdate -height 19 -group t80 /tb/z80/u0/Alternate
add wave -noupdate -height 19 -group t80 /tb/z80/u0/TmpAddr
add wave -noupdate -height 19 -group t80 /tb/z80/u0/IR
add wave -noupdate -height 19 -group t80 /tb/z80/u0/ISet
add wave -noupdate -height 19 -group t80 /tb/z80/u0/RegBusA_r
add wave -noupdate -height 19 -group t80 /tb/z80/u0/ID16
add wave -noupdate -height 19 -group t80 /tb/z80/u0/Save_Mux
add wave -noupdate -height 19 -group t80 /tb/z80/u0/TState
add wave -noupdate -height 19 -group t80 /tb/z80/u0/MCycle
add wave -noupdate -height 19 -group t80 /tb/z80/u0/IntE_FF1
add wave -noupdate -height 19 -group t80 /tb/z80/u0/IntE_FF2
add wave -noupdate -height 19 -group t80 /tb/z80/u0/Halt_FF
add wave -noupdate -height 19 -group t80 /tb/z80/u0/BusReq_s
add wave -noupdate -height 19 -group t80 /tb/z80/u0/BusAck
add wave -noupdate -height 19 -group t80 /tb/z80/u0/ClkEn
add wave -noupdate -height 19 -group t80 /tb/z80/u0/NMI_s
add wave -noupdate -height 19 -group t80 /tb/z80/u0/INT_s
add wave -noupdate -height 19 -group t80 /tb/z80/u0/IStatus
add wave -noupdate -height 19 -group t80 /tb/z80/u0/DI_Reg
add wave -noupdate -height 19 -group t80 /tb/z80/u0/T_Res
add wave -noupdate -height 19 -group t80 /tb/z80/u0/XY_State
add wave -noupdate -height 19 -group t80 /tb/z80/u0/Pre_XY_F_M
add wave -noupdate -height 19 -group t80 /tb/z80/u0/NextIs_XY_Fetch
add wave -noupdate -height 19 -group t80 /tb/z80/u0/XY_Ind
add wave -noupdate -height 19 -group t80 /tb/z80/u0/No_BTR
add wave -noupdate -height 19 -group t80 /tb/z80/u0/BTR_r
add wave -noupdate -height 19 -group t80 /tb/z80/u0/Auto_Wait
add wave -noupdate -height 19 -group t80 /tb/z80/u0/Auto_Wait_t1
add wave -noupdate -height 19 -group t80 /tb/z80/u0/Auto_Wait_t2
add wave -noupdate -height 19 -group t80 /tb/z80/u0/IncDecZ
add wave -noupdate -height 19 -group t80 /tb/z80/u0/BusB
add wave -noupdate -height 19 -group t80 /tb/z80/u0/BusA
add wave -noupdate -height 19 -group t80 /tb/z80/u0/ALU_Q
add wave -noupdate -height 19 -group t80 /tb/z80/u0/F_Out
add wave -noupdate -height 19 -group t80 /tb/z80/u0/Read_To_Reg_r
add wave -noupdate -height 19 -group t80 /tb/z80/u0/Arith16_r
add wave -noupdate -height 19 -group t80 /tb/z80/u0/Z16_r
add wave -noupdate -height 19 -group t80 /tb/z80/u0/ALU_Op_r
add wave -noupdate -height 19 -group t80 /tb/z80/u0/Save_ALU_r
add wave -noupdate -height 19 -group t80 /tb/z80/u0/PreserveC_r
add wave -noupdate -height 19 -group t80 /tb/z80/u0/MCycles
add wave -noupdate -height 19 -group t80 /tb/z80/u0/MCycles_d
add wave -noupdate -height 19 -group t80 /tb/z80/u0/TStates
add wave -noupdate -height 19 -group t80 /tb/z80/u0/IntCycle
add wave -noupdate -height 19 -group t80 /tb/z80/u0/NMICycle
add wave -noupdate -height 19 -group t80 /tb/z80/u0/Inc_PC
add wave -noupdate -height 19 -group t80 /tb/z80/u0/Inc_WZ
add wave -noupdate -height 19 -group t80 /tb/z80/u0/IncDec_16
add wave -noupdate -height 19 -group t80 /tb/z80/u0/Prefix
add wave -noupdate -height 19 -group t80 /tb/z80/u0/Read_To_Acc
add wave -noupdate -height 19 -group t80 /tb/z80/u0/Read_To_Reg
add wave -noupdate -height 19 -group t80 /tb/z80/u0/Set_BusB_To
add wave -noupdate -height 19 -group t80 /tb/z80/u0/Set_BusA_To
add wave -noupdate -height 19 -group t80 /tb/z80/u0/ALU_Op
add wave -noupdate -height 19 -group t80 /tb/z80/u0/Save_ALU
add wave -noupdate -height 19 -group t80 /tb/z80/u0/PreserveC
add wave -noupdate -height 19 -group t80 /tb/z80/u0/Arith16
add wave -noupdate -height 19 -group t80 /tb/z80/u0/Set_Addr_To
add wave -noupdate -height 19 -group t80 /tb/z80/u0/Jump
add wave -noupdate -height 19 -group t80 /tb/z80/u0/JumpE
add wave -noupdate -height 19 -group t80 /tb/z80/u0/JumpXY
add wave -noupdate -height 19 -group t80 /tb/z80/u0/Call
add wave -noupdate -height 19 -group t80 /tb/z80/u0/RstP
add wave -noupdate -height 19 -group t80 /tb/z80/u0/LDZ
add wave -noupdate -height 19 -group t80 /tb/z80/u0/LDW
add wave -noupdate -height 19 -group t80 /tb/z80/u0/LDSPHL
add wave -noupdate -height 19 -group t80 /tb/z80/u0/IORQ_i
add wave -noupdate -height 19 -group t80 /tb/z80/u0/Special_LD
add wave -noupdate -height 19 -group t80 /tb/z80/u0/ExchangeDH
add wave -noupdate -height 19 -group t80 /tb/z80/u0/ExchangeRp
add wave -noupdate -height 19 -group t80 /tb/z80/u0/ExchangeAF
add wave -noupdate -height 19 -group t80 /tb/z80/u0/ExchangeRS
add wave -noupdate -height 19 -group t80 /tb/z80/u0/I_DJNZ
add wave -noupdate -height 19 -group t80 /tb/z80/u0/I_CPL
add wave -noupdate -height 19 -group t80 /tb/z80/u0/I_CCF
add wave -noupdate -height 19 -group t80 /tb/z80/u0/I_SCF
add wave -noupdate -height 19 -group t80 /tb/z80/u0/I_RETN
add wave -noupdate -height 19 -group t80 /tb/z80/u0/I_BT
add wave -noupdate -height 19 -group t80 /tb/z80/u0/I_BC
add wave -noupdate -height 19 -group t80 /tb/z80/u0/I_BTR
add wave -noupdate -height 19 -group t80 /tb/z80/u0/I_RLD
add wave -noupdate -height 19 -group t80 /tb/z80/u0/I_RRD
add wave -noupdate -height 19 -group t80 /tb/z80/u0/I_INRC
add wave -noupdate -height 19 -group t80 /tb/z80/u0/SetDI
add wave -noupdate -height 19 -group t80 /tb/z80/u0/SetEI
add wave -noupdate -height 19 -group t80 /tb/z80/u0/IMode
add wave -noupdate -height 19 -group t80 /tb/z80/u0/Halt
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/fclk
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/rst_n
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/zpos
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/zneg
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/cbeg
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/post_cbeg
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/pre_cend
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/cend
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/za
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/zd_in
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/zd_out
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/zd_ena
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/m1_n
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/rfsh_n
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/mreq_n
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/iorq_n
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/rd_n
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/wr_n
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/int_turbo
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/win0_romnram
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/win1_romnram
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/win2_romnram
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/win3_romnram
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/win0_page
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/win1_page
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/win2_page
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/win3_page
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/win0_wrdisable
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/win1_wrdisable
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/win2_wrdisable
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/win3_wrdisable
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/romrw_en
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/nmi_buf_clr
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/rompg
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/romoe_n
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/romwe_n
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/csrom
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/cpu_req
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/cpu_rnw
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/cpu_addr
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/cpu_wrdata
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/cpu_wrbsel
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/cpu_rddata
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/cpu_next
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/cpu_strobe
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/cpu_stall
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/win
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/page
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/romnram
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/wrdisable
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/rd_buf
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/cached_addr
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/cached_addr_valid
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/cache_hit
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/dram_beg
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/opfetch
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/memrd
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/memwr
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/stall14
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/stall7_35
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/stall14_ini
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/stall14_cyc
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/stall14_cycrd
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/stall14_fin
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/r_mreq_n
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/pending_cpu_req
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/cpu_rnw_r
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/ramreq
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/ramwr
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/ramrd
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/cpureq_357
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/ramrd_reg
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/ramwr_reg
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/io
add wave -noupdate -height 19 -group zmem /tb/DUT/z80mem/io_r
add wave -noupdate -height 19 -group dut /tb/DUT/fclk
add wave -noupdate -height 19 -group dut /tb/DUT/clkz_out
add wave -noupdate -height 19 -group dut /tb/DUT/clkz_in
add wave -noupdate -height 19 -group dut /tb/DUT/iorq_n
add wave -noupdate -height 19 -group dut /tb/DUT/mreq_n
add wave -noupdate -height 19 -group dut /tb/DUT/rd_n
add wave -noupdate -height 19 -group dut /tb/DUT/wr_n
add wave -noupdate -height 19 -group dut /tb/DUT/m1_n
add wave -noupdate -height 19 -group dut /tb/DUT/rfsh_n
add wave -noupdate -height 19 -group dut /tb/DUT/int_n
add wave -noupdate -height 19 -group dut /tb/DUT/nmi_n
add wave -noupdate -height 19 -group dut /tb/DUT/wait_n
add wave -noupdate -height 19 -group dut /tb/DUT/res
add wave -noupdate -height 19 -group dut /tb/DUT/d
add wave -noupdate -height 19 -group dut /tb/DUT/a
add wave -noupdate -height 19 -group dut /tb/DUT/csrom
add wave -noupdate -height 19 -group dut /tb/DUT/romoe_n
add wave -noupdate -height 19 -group dut /tb/DUT/romwe_n
add wave -noupdate -height 19 -group dut /tb/DUT/rompg0_n
add wave -noupdate -height 19 -group dut /tb/DUT/dos_n
add wave -noupdate -height 19 -group dut /tb/DUT/rompg2
add wave -noupdate -height 19 -group dut /tb/DUT/rompg3
add wave -noupdate -height 19 -group dut /tb/DUT/rompg4
add wave -noupdate -height 19 -group dut /tb/DUT/iorqge1
add wave -noupdate -height 19 -group dut /tb/DUT/iorqge2
add wave -noupdate -height 19 -group dut /tb/DUT/iorq1_n
add wave -noupdate -height 19 -group dut /tb/DUT/iorq2_n
add wave -noupdate -height 19 -group dut /tb/DUT/rd
add wave -noupdate -height 19 -group dut /tb/DUT/ra
add wave -noupdate -height 19 -group dut /tb/DUT/rwe_n
add wave -noupdate -height 19 -group dut /tb/DUT/rucas_n
add wave -noupdate -height 19 -group dut /tb/DUT/rlcas_n
add wave -noupdate -height 19 -group dut /tb/DUT/rras0_n
add wave -noupdate -height 19 -group dut /tb/DUT/rras1_n
add wave -noupdate -height 19 -group dut /tb/DUT/vred
add wave -noupdate -height 19 -group dut /tb/DUT/vgrn
add wave -noupdate -height 19 -group dut /tb/DUT/vblu
add wave -noupdate -height 19 -group dut /tb/DUT/vhsync
add wave -noupdate -height 19 -group dut /tb/DUT/vvsync
add wave -noupdate -height 19 -group dut /tb/DUT/vcsync
add wave -noupdate -height 19 -group dut /tb/DUT/ay_clk
add wave -noupdate -height 19 -group dut /tb/DUT/ay_bdir
add wave -noupdate -height 19 -group dut /tb/DUT/ay_bc1
add wave -noupdate -height 19 -group dut /tb/DUT/beep
add wave -noupdate -height 19 -group dut /tb/DUT/ide_a
add wave -noupdate -height 19 -group dut /tb/DUT/ide_d
add wave -noupdate -height 19 -group dut /tb/DUT/ide_dir
add wave -noupdate -height 19 -group dut /tb/DUT/ide_rdy
add wave -noupdate -height 19 -group dut /tb/DUT/ide_cs0_n
add wave -noupdate -height 19 -group dut /tb/DUT/ide_cs1_n
add wave -noupdate -height 19 -group dut /tb/DUT/ide_rs_n
add wave -noupdate -height 19 -group dut /tb/DUT/ide_rd_n
add wave -noupdate -height 19 -group dut /tb/DUT/ide_wr_n
add wave -noupdate -height 19 -group dut /tb/DUT/vg_clk
add wave -noupdate -height 19 -group dut /tb/DUT/vg_cs_n
add wave -noupdate -height 19 -group dut /tb/DUT/vg_res_n
add wave -noupdate -height 19 -group dut /tb/DUT/vg_hrdy
add wave -noupdate -height 19 -group dut /tb/DUT/vg_rclk
add wave -noupdate -height 19 -group dut /tb/DUT/vg_rawr
add wave -noupdate -height 19 -group dut /tb/DUT/vg_a
add wave -noupdate -height 19 -group dut /tb/DUT/vg_wrd
add wave -noupdate -height 19 -group dut /tb/DUT/vg_side
add wave -noupdate -height 19 -group dut /tb/DUT/step
add wave -noupdate -height 19 -group dut /tb/DUT/vg_sl
add wave -noupdate -height 19 -group dut /tb/DUT/vg_sr
add wave -noupdate -height 19 -group dut /tb/DUT/vg_tr43
add wave -noupdate -height 19 -group dut /tb/DUT/rdat_b_n
add wave -noupdate -height 19 -group dut /tb/DUT/vg_wf_de
add wave -noupdate -height 19 -group dut /tb/DUT/vg_drq
add wave -noupdate -height 19 -group dut /tb/DUT/vg_irq
add wave -noupdate -height 19 -group dut /tb/DUT/vg_wd
add wave -noupdate -height 19 -group dut /tb/DUT/sdcs_n
add wave -noupdate -height 19 -group dut /tb/DUT/sddo
add wave -noupdate -height 19 -group dut /tb/DUT/sdclk
add wave -noupdate -height 19 -group dut /tb/DUT/sddi
add wave -noupdate -height 19 -group dut /tb/DUT/spics_n
add wave -noupdate -height 19 -group dut /tb/DUT/spick
add wave -noupdate -height 19 -group dut /tb/DUT/spido
add wave -noupdate -height 19 -group dut /tb/DUT/spidi
add wave -noupdate -height 19 -group dut /tb/DUT/spiint_n
add wave -noupdate -height 19 -group dut /tb/DUT/dos
add wave -noupdate -height 19 -group dut /tb/DUT/zclk
add wave -noupdate -height 19 -group dut /tb/DUT/zpos
add wave -noupdate -height 19 -group dut /tb/DUT/zneg
add wave -noupdate -height 19 -group dut /tb/DUT/rst_n
add wave -noupdate -height 19 -group dut /tb/DUT/rrdy
add wave -noupdate -height 19 -group dut /tb/DUT/rddata
add wave -noupdate -height 19 -group dut /tb/DUT/rompg
add wave -noupdate -height 19 -group dut /tb/DUT/zports_dout
add wave -noupdate -height 19 -group dut /tb/DUT/zports_dataout
add wave -noupdate -height 19 -group dut /tb/DUT/porthit
add wave -noupdate -height 19 -group dut /tb/DUT/csrom_int
add wave -noupdate -height 19 -group dut /tb/DUT/kbd_data
add wave -noupdate -height 19 -group dut /tb/DUT/mus_data
add wave -noupdate -height 19 -group dut /tb/DUT/kbd_stb
add wave -noupdate -height 19 -group dut /tb/DUT/mus_xstb
add wave -noupdate -height 19 -group dut /tb/DUT/mus_ystb
add wave -noupdate -height 19 -group dut /tb/DUT/mus_btnstb
add wave -noupdate -height 19 -group dut /tb/DUT/kj_stb
add wave -noupdate -height 19 -group dut /tb/DUT/kbd_port_data
add wave -noupdate -height 19 -group dut /tb/DUT/kj_port_data
add wave -noupdate -height 19 -group dut /tb/DUT/mus_port_data
add wave -noupdate -height 19 -group dut /tb/DUT/wait_read
add wave -noupdate -height 19 -group dut /tb/DUT/wait_write
add wave -noupdate -height 19 -group dut /tb/DUT/wait_rnw
add wave -noupdate -height 19 -group dut /tb/DUT/wait_start_gluclock
add wave -noupdate -height 19 -group dut /tb/DUT/wait_start_comport
add wave -noupdate -height 19 -group dut /tb/DUT/wait_end
add wave -noupdate -height 19 -group dut /tb/DUT/gluclock_addr
add wave -noupdate -height 19 -group dut /tb/DUT/comport_addr
add wave -noupdate -height 19 -group dut /tb/DUT/waits
add wave -noupdate -height 19 -group dut /tb/DUT/not_used0
add wave -noupdate -height 19 -group dut /tb/DUT/not_used1
add wave -noupdate -height 19 -group dut /tb/DUT/cfg_vga_on
add wave -noupdate -height 19 -group dut /tb/DUT/modes_raster
add wave -noupdate -height 19 -group dut /tb/DUT/mode_contend_type
add wave -noupdate -height 19 -group dut /tb/DUT/mode_contend_ena
add wave -noupdate -height 19 -group dut /tb/DUT/contend
add wave -noupdate -height 19 -group dut /tb/DUT/fdd_mask
add wave -noupdate -height 19 -group dut /tb/DUT/gen_nmi
add wave -noupdate -height 19 -group dut /tb/DUT/clr_nmi
add wave -noupdate -height 19 -group dut /tb/DUT/in_nmi
add wave -noupdate -height 19 -group dut /tb/DUT/in_trdemu
add wave -noupdate -height 19 -group dut /tb/DUT/trdemu_wr_disable
add wave -noupdate -height 19 -group dut /tb/DUT/set_nmi
add wave -noupdate -height 19 -group dut /tb/DUT/imm_nmi
add wave -noupdate -height 19 -group dut /tb/DUT/nmi_buf_clr
add wave -noupdate -height 19 -group dut /tb/DUT/brk_ena
add wave -noupdate -height 19 -group dut /tb/DUT/brk_addr
add wave -noupdate -height 19 -group dut /tb/DUT/tape_in
add wave -noupdate -height 19 -group dut /tb/DUT/ideout
add wave -noupdate -height 19 -group dut /tb/DUT/idein
add wave -noupdate -height 19 -group dut /tb/DUT/idedataout
add wave -noupdate -height 19 -group dut /tb/DUT/zmem_dout
add wave -noupdate -height 19 -group dut /tb/DUT/zmem_dataout
add wave -noupdate -height 19 -group dut /tb/DUT/ayclk_gen
add wave -noupdate -height 19 -group dut /tb/DUT/received
add wave -noupdate -height 19 -group dut /tb/DUT/tobesent
add wave -noupdate -height 19 -group dut /tb/DUT/intrq
add wave -noupdate -height 19 -group dut /tb/DUT/drq
add wave -noupdate -height 19 -group dut /tb/DUT/vg_wrFF_fclk
add wave -noupdate -height 19 -group dut /tb/DUT/vg_rdwr_fclk
add wave -noupdate -height 19 -group dut /tb/DUT/vg_ddrv
add wave -noupdate -height 19 -group dut /tb/DUT/up_ena
add wave -noupdate -height 19 -group dut /tb/DUT/up_paladdr
add wave -noupdate -height 19 -group dut /tb/DUT/up_paldata
add wave -noupdate -height 19 -group dut /tb/DUT/up_palwr
add wave -noupdate -height 19 -group dut /tb/DUT/genrst
add wave -noupdate -height 19 -group dut /tb/DUT/peff7
add wave -noupdate -height 19 -group dut /tb/DUT/p7ffd
add wave -noupdate -height 19 -group dut /tb/DUT/romrw_en
add wave -noupdate -height 19 -group dut /tb/DUT/cpm_n
add wave -noupdate -height 19 -group dut /tb/DUT/fnt_wr
add wave -noupdate -height 19 -group dut /tb/DUT/cpu_req
add wave -noupdate -height 19 -group dut /tb/DUT/cpu_rnw
add wave -noupdate -height 19 -group dut /tb/DUT/cpu_wrbsel
add wave -noupdate -height 19 -group dut /tb/DUT/cpu_strobe
add wave -noupdate -height 19 -group dut /tb/DUT/cpu_addr
add wave -noupdate -height 19 -group dut /tb/DUT/cpu_rddata
add wave -noupdate -height 19 -group dut /tb/DUT/cpu_wrdata
add wave -noupdate -height 19 -group dut /tb/DUT/cbeg
add wave -noupdate -height 19 -group dut /tb/DUT/post_cbeg
add wave -noupdate -height 19 -group dut /tb/DUT/pre_cend
add wave -noupdate -height 19 -group dut /tb/DUT/cend
add wave -noupdate -height 19 -group dut /tb/DUT/go
add wave -noupdate -height 19 -group dut /tb/DUT/avr_lock_claim
add wave -noupdate -height 19 -group dut /tb/DUT/avr_lock_grant
add wave -noupdate -height 19 -group dut /tb/DUT/avr_sdcs_n
add wave -noupdate -height 19 -group dut /tb/DUT/avr_sd_start
add wave -noupdate -height 19 -group dut /tb/DUT/avr_sd_datain
add wave -noupdate -height 19 -group dut /tb/DUT/avr_sd_dataout
add wave -noupdate -height 19 -group dut /tb/DUT/zx_sdcs_n_val
add wave -noupdate -height 19 -group dut /tb/DUT/zx_sdcs_n_stb
add wave -noupdate -height 19 -group dut /tb/DUT/zx_sd_start
add wave -noupdate -height 19 -group dut /tb/DUT/zx_sd_datain
add wave -noupdate -height 19 -group dut /tb/DUT/zx_sd_dataout
add wave -noupdate -height 19 -group dut /tb/DUT/tape_read
add wave -noupdate -height 19 -group dut /tb/DUT/beeper_mux
add wave -noupdate -height 19 -group dut /tb/DUT/atm_scr_mode
add wave -noupdate -height 19 -group dut /tb/DUT/atm_turbo
add wave -noupdate -height 19 -group dut /tb/DUT/beeper_wr
add wave -noupdate -height 19 -group dut /tb/DUT/covox_wr
add wave -noupdate -height 19 -group dut /tb/DUT/palcolor
add wave -noupdate -height 19 -group dut /tb/DUT/int_turbo
add wave -noupdate -height 19 -group dut /tb/DUT/cpu_next
add wave -noupdate -height 19 -group dut /tb/DUT/cpu_stall
add wave -noupdate -height 19 -group dut /tb/DUT/external_port
add wave -noupdate -height 19 -group dut /tb/DUT/zclk_stall
add wave -noupdate -height 19 -group dut /tb/DUT/dout_ram
add wave -noupdate -height 19 -group dut /tb/DUT/ena_ram
add wave -noupdate -height 19 -group dut /tb/DUT/dout_ports
add wave -noupdate -height 19 -group dut /tb/DUT/ena_ports
add wave -noupdate -height 19 -group dut /tb/DUT/border
add wave -noupdate -height 19 -group dut /tb/DUT/drive_ff
add wave -noupdate -height 19 -group dut /tb/DUT/drive_00
add wave -noupdate -height 19 -group dut /tb/DUT/atm_palwr
add wave -noupdate -height 19 -group dut /tb/DUT/atm_paldata
add wave -noupdate -height 19 -group dut /tb/DUT/fontrom_readback
add wave -noupdate -height 19 -group dut /tb/DUT/int_start
add wave -noupdate -height 19 -group dut /tb/DUT/d_pre_out
add wave -noupdate -height 19 -group dut /tb/DUT/d_ena
add wave -noupdate -height 19 -group dut /tb/DUT/pager_off
add wave -noupdate -height 19 -group dut /tb/DUT/pent1m_ROM
add wave -noupdate -height 19 -group dut /tb/DUT/pent1m_page
add wave -noupdate -height 19 -group dut /tb/DUT/pent1m_ram0_0
add wave -noupdate -height 19 -group dut /tb/DUT/pent1m_1m_on
add wave -noupdate -height 19 -group dut /tb/DUT/atmF7_wr_fclk
add wave -noupdate -height 19 -group dut /tb/DUT/dos_turn_off
add wave -noupdate -height 19 -group dut /tb/DUT/dos_turn_on
add wave -noupdate -height 19 -group dut /tb/DUT/page
add wave -noupdate -height 19 -group dut /tb/DUT/romnram
add wave -noupdate -height 19 -group dut /tb/DUT/wrdisable
add wave -noupdate -height 19 -group dut /tb/DUT/rd_pages
add wave -noupdate -height 19 -group dut /tb/DUT/rd_ramnrom
add wave -noupdate -height 19 -group dut /tb/DUT/rd_dos7ffd
add wave -noupdate -height 19 -group dut /tb/DUT/rd_wrdisables
add wave -noupdate -height 19 -group dut /tb/DUT/daddr
add wave -noupdate -height 19 -group dut /tb/DUT/dreq
add wave -noupdate -height 19 -group dut /tb/DUT/drnw
add wave -noupdate -height 19 -group dut /tb/DUT/drddata
add wave -noupdate -height 19 -group dut /tb/DUT/dwrdata
add wave -noupdate -height 19 -group dut /tb/DUT/dbsel
add wave -noupdate -height 19 -group dut /tb/DUT/drrdy
add wave -noupdate -height 19 -group dut /tb/DUT/bw
add wave -noupdate -height 19 -group dut /tb/DUT/video_addr
add wave -noupdate -height 19 -group dut /tb/DUT/video_data
add wave -noupdate -height 19 -group dut /tb/DUT/video_strobe
add wave -noupdate -height 19 -group dut /tb/DUT/video_next
add wave -noupdate -height 19 -group dut /tb/DUT/atm_pen2
add wave -noupdate -height 19 -expand -group tb /tb/fclk
add wave -noupdate -height 19 -expand -group tb /tb/clkz_out
add wave -noupdate -height 19 -expand -group tb /tb/clkz_in
add wave -noupdate -height 19 -expand -group tb /tb/iorq_n
add wave -noupdate -height 19 -expand -group tb /tb/mreq_n
add wave -noupdate -height 19 -expand -group tb /tb/rd_n
add wave -noupdate -height 19 -expand -group tb /tb/wr_n
add wave -noupdate -height 19 -expand -group tb /tb/m1_n
add wave -noupdate -height 19 -expand -group tb /tb/rfsh_n
add wave -noupdate -height 19 -expand -group tb /tb/res
add wave -noupdate -height 19 -expand -group tb /tb/ziorq_n
add wave -noupdate -height 19 -expand -group tb /tb/zmreq_n
add wave -noupdate -height 19 -expand -group tb /tb/zrd_n
add wave -noupdate -height 19 -expand -group tb /tb/zwr_n
add wave -noupdate -height 19 -expand -group tb /tb/zm1_n
add wave -noupdate -height 19 -expand -group tb /tb/zrfsh_n
add wave -noupdate -height 19 -expand -group tb /tb/int_n
add wave -noupdate -height 19 -expand -group tb /tb/wait_n
add wave -noupdate -height 19 -expand -group tb /tb/nmi_n
add wave -noupdate -height 19 -expand -group tb /tb/zint_n
add wave -noupdate -height 19 -expand -group tb /tb/zwait_n
add wave -noupdate -height 19 -expand -group tb /tb/znmi_n
add wave -noupdate -height 19 -expand -group tb /tb/za
add wave -noupdate -height 19 -expand -group tb /tb/zd
add wave -noupdate -height 19 -expand -group tb /tb/zd_dut_to_z80
add wave -noupdate -height 19 -expand -group tb /tb/reset_pc
add wave -noupdate -height 19 -expand -group tb /tb/reset_sp
add wave -noupdate -height 19 -expand -group tb /tb/csrom
add wave -noupdate -height 19 -expand -group tb /tb/romoe_n
add wave -noupdate -height 19 -expand -group tb /tb/romwe_n
add wave -noupdate -height 19 -expand -group tb /tb/rompg0_n
add wave -noupdate -height 19 -expand -group tb /tb/dos_n
add wave -noupdate -height 19 -expand -group tb /tb/rompg2
add wave -noupdate -height 19 -expand -group tb /tb/rompg3
add wave -noupdate -height 19 -expand -group tb /tb/rompg4
add wave -noupdate -height 19 -expand -group tb /tb/rd
add wave -noupdate -height 19 -expand -group tb /tb/ra
add wave -noupdate -height 19 -expand -group tb /tb/rwe_n
add wave -noupdate -height 19 -expand -group tb /tb/rucas_n
add wave -noupdate -height 19 -expand -group tb /tb/rlcas_n
add wave -noupdate -height 19 -expand -group tb /tb/rras0_n
add wave -noupdate -height 19 -expand -group tb /tb/rras1_n
add wave -noupdate -height 19 -expand -group tb /tb/ide_d
add wave -noupdate -height 19 -expand -group tb /tb/hsync
add wave -noupdate -height 19 -expand -group tb /tb/vsync
add wave -noupdate -height 19 -expand -group tb /tb/red
add wave -noupdate -height 19 -expand -group tb /tb/grn
add wave -noupdate -height 19 -expand -group tb /tb/blu
add wave -noupdate -height 19 -expand -group tb /tb/sdcs_n
add wave -noupdate -height 19 -expand -group tb /tb/sddo
add wave -noupdate -height 19 -expand -group tb /tb/sddi
add wave -noupdate -height 19 -expand -group tb /tb/sdclk
add wave -noupdate -height 19 -expand -group tb /tb/spick
add wave -noupdate -height 19 -expand -group tb /tb/spidi
add wave -noupdate -height 19 -expand -group tb /tb/spido
add wave -noupdate -height 19 -expand -group tb /tb/spics_n
add wave -noupdate -height 19 -expand -group tb /tb/zrst_n
add wave -noupdate -height 19 -expand -group tb /tb/mreq_wr_n
add wave -noupdate -height 19 -expand -group tb /tb/iorq_wr_n
add wave -noupdate -height 19 -expand -group tb /tb/full_wr_n
add wave -noupdate -height 19 -expand -group tb /tb/rma14
add wave -noupdate -height 19 -expand -group tb /tb/rma15
add wave -noupdate -height 19 -expand -group tb /tb/rpag
add wave -noupdate -height 19 -expand -group tb /tb/fe_write
add wave -noupdate -height 19 -expand -group tb /tb/cmos_addr
add wave -noupdate -height 19 -expand -group tb /tb/cmos_read
add wave -noupdate -height 19 -expand -group tb /tb/cmos_write
add wave -noupdate -height 19 -expand -group tb /tb/cmos_rnw
add wave -noupdate -height 19 -expand -group tb /tb/cmos_req
add wave -noupdate -height 19 -expand -group tb /tb/bpt
add wave -noupdate -height 19 -expand -group tb /tb/dza
add wave -noupdate -height 19 -expand -group tb /tb/dzw
add wave -noupdate -height 19 -expand -group tb /tb/dzr
add wave -noupdate -height 19 -expand -group tb /tb/curr_cycle
add wave -noupdate -height 19 -expand -group tb /tb/is_fetch
add wave -noupdate -height 19 -expand -group tb /tb/is_mrd
add wave -noupdate -height 19 -expand -group tb /tb/is_mwr
add wave -noupdate -height 19 -expand -group tb /tb/is_iord
add wave -noupdate -height 19 -expand -group tb /tb/is_iowr
add wave -noupdate -height 19 -expand -group tb /tb/is_iack
add wave -noupdate -height 19 -expand -group tb /tb/is_any
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {3150600 ps} 0} {{Cursor 2} {1863936836336 ps} 0} {{Cursor 3} {1863933415900 ps} 0}
quietly wave cursor active 2
configure wave -namecolwidth 487
configure wave -valuecolwidth 149
configure wave -justifyvalue left
configure wave -signalnamewidth 0
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 17800
configure wave -gridperiod 35600
configure wave -griddelta 8
configure wave -timeline 0
configure wave -timelineunits ns
update
WaveRestoreZoom {1910242412926 ps} {1910249711888 ps}
