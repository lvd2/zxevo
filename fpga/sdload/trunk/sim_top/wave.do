onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -group video_top /tb/DUT/video_top/clk
add wave -noupdate -group video_top /tb/DUT/video_top/vred
add wave -noupdate -group video_top /tb/DUT/video_top/vgrn
add wave -noupdate -group video_top /tb/DUT/video_top/vblu
add wave -noupdate -group video_top /tb/DUT/video_top/vhsync
add wave -noupdate -group video_top /tb/DUT/video_top/vvsync
add wave -noupdate -group video_top /tb/DUT/video_top/vcsync
add wave -noupdate -group video_top /tb/DUT/video_top/zxborder
add wave -noupdate -group video_top /tb/DUT/video_top/pent_vmode
add wave -noupdate -group video_top /tb/DUT/video_top/atm_vmode
add wave -noupdate -group video_top /tb/DUT/video_top/scr_page
add wave -noupdate -group video_top /tb/DUT/video_top/vga_on
add wave -noupdate -group video_top /tb/DUT/video_top/modes_raster
add wave -noupdate -group video_top /tb/DUT/video_top/mode_contend_type
add wave -noupdate -group video_top /tb/DUT/video_top/cbeg
add wave -noupdate -group video_top /tb/DUT/video_top/post_cbeg
add wave -noupdate -group video_top /tb/DUT/video_top/pre_cend
add wave -noupdate -group video_top /tb/DUT/video_top/cend
add wave -noupdate -group video_top /tb/DUT/video_top/video_strobe
add wave -noupdate -group video_top /tb/DUT/video_top/video_next
add wave -noupdate -group video_top /tb/DUT/video_top/video_addr
add wave -noupdate -group video_top /tb/DUT/video_top/video_data
add wave -noupdate -group video_top /tb/DUT/video_top/video_bw
add wave -noupdate -group video_top /tb/DUT/video_top/video_go
add wave -noupdate -group video_top /tb/DUT/video_top/atm_palwr
add wave -noupdate -group video_top /tb/DUT/video_top/atm_paldata
add wave -noupdate -group video_top /tb/DUT/video_top/up_ena
add wave -noupdate -group video_top /tb/DUT/video_top/up_palwr
add wave -noupdate -group video_top /tb/DUT/video_top/up_paladdr
add wave -noupdate -group video_top /tb/DUT/video_top/up_paldata
add wave -noupdate -group video_top /tb/DUT/video_top/int_start
add wave -noupdate -group video_top /tb/DUT/video_top/fnt_a
add wave -noupdate -group video_top /tb/DUT/video_top/fnt_d
add wave -noupdate -group video_top /tb/DUT/video_top/fnt_wr
add wave -noupdate -group video_top /tb/DUT/video_top/palcolor
add wave -noupdate -group video_top /tb/DUT/video_top/fontrom_readback
add wave -noupdate -group video_top /tb/DUT/video_top/contend
add wave -noupdate -group video_top /tb/DUT/video_top/mode_atm_n_pent
add wave -noupdate -group video_top /tb/DUT/video_top/mode_zx
add wave -noupdate -group video_top /tb/DUT/video_top/mode_p_16c
add wave -noupdate -group video_top /tb/DUT/video_top/mode_p_hmclr
add wave -noupdate -group video_top /tb/DUT/video_top/mode_a_hmclr
add wave -noupdate -group video_top /tb/DUT/video_top/mode_a_16c
add wave -noupdate -group video_top /tb/DUT/video_top/mode_a_text
add wave -noupdate -group video_top /tb/DUT/video_top/mode_a_txt_1page
add wave -noupdate -group video_top /tb/DUT/video_top/mode_pixf_14
add wave -noupdate -group video_top /tb/DUT/video_top/hsync_start
add wave -noupdate -group video_top /tb/DUT/video_top/line_start
add wave -noupdate -group video_top /tb/DUT/video_top/hint_start
add wave -noupdate -group video_top /tb/DUT/video_top/vblank
add wave -noupdate -group video_top /tb/DUT/video_top/hblank
add wave -noupdate -group video_top /tb/DUT/video_top/vpix
add wave -noupdate -group video_top /tb/DUT/video_top/hpix
add wave -noupdate -group video_top /tb/DUT/video_top/vsync
add wave -noupdate -group video_top /tb/DUT/video_top/hsync
add wave -noupdate -group video_top /tb/DUT/video_top/vga_hsync
add wave -noupdate -group video_top /tb/DUT/video_top/scanin_start
add wave -noupdate -group video_top /tb/DUT/video_top/scanout_start
add wave -noupdate -group video_top /tb/DUT/video_top/fetch_start
add wave -noupdate -group video_top /tb/DUT/video_top/fetch_end
add wave -noupdate -group video_top /tb/DUT/video_top/fetch_sync
add wave -noupdate -group video_top /tb/DUT/video_top/pic_bits
add wave -noupdate -group video_top /tb/DUT/video_top/pixels
add wave -noupdate -group video_top /tb/DUT/video_top/color
add wave -noupdate -group video_top /tb/DUT/video_top/vga_color
add wave -noupdate -group video_top /tb/DUT/video_top/typos
add wave -noupdate -group video_top /tb/DUT/video_top/up_palsel
add wave -noupdate -group video_top /tb/DUT/video_top/up_paper
add wave -noupdate -group video_top /tb/DUT/video_top/up_ink
add wave -noupdate -group video_top /tb/DUT/video_top/up_pixel
add wave -noupdate -group video_top /tb/DUT/video_top/border_sync
add wave -noupdate -expand -group vga_double /tb/DUT/video_top/video_vga_double/clk
add wave -noupdate -expand -group vga_double /tb/DUT/video_top/video_vga_double/hsync_start
add wave -noupdate -expand -group vga_double /tb/DUT/video_top/video_vga_double/scanin_start
add wave -noupdate -expand -group vga_double /tb/DUT/video_top/video_vga_double/pix_in
add wave -noupdate -expand -group vga_double /tb/DUT/video_top/video_vga_double/scanout_start
add wave -noupdate -expand -group vga_double /tb/DUT/video_top/video_vga_double/pix_out
add wave -noupdate -expand -group vga_double /tb/DUT/video_top/video_vga_double/ptr_in
add wave -noupdate -expand -group vga_double /tb/DUT/video_top/video_vga_double/ptr_out
add wave -noupdate -expand -group vga_double /tb/DUT/video_top/video_vga_double/pages
add wave -noupdate -expand -group vga_double /tb/DUT/video_top/video_vga_double/wr_stb
add wave -noupdate -expand -group vga_double /tb/DUT/video_top/video_vga_double/data_out
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {3150600 ps} 0} {{Cursor 2} {113328607442 ps} 0}
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
WaveRestoreZoom {113225483596 ps} {113356242394 ps}
