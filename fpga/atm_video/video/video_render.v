`include "../include/tune.v"

// Pentevo project (c) NedoPC 2011
//
// renders fetched video data to the pixels

module video_render(

	input  wire        clk, // 28 MHz clock


	input  wire [63:0] pic_bits, // video data from fetcher

	input  wire        fetch_sync, // synchronizes pixel rendering -
	                               // coincides with cbeg!!!

	input  wire        cbeg,
	input  wire        post_cbeg, // pixel strobed and
	input  wire        pre_cend,
	input  wire        cend,      // general sync

	input  wire        int_start, // for flash gen

	input  wire [ 2:0] typos, // Y pos in text symbols

	output wire [ 3:0] pixels, // output pixels



	input  wire        mode_atm_n_pent, // decoded modes

	input  wire        mode_zx,         //
	input  wire        mode_p_16c,      //
	input  wire        mode_p_hmclr,    //
	                                    //
	input  wire        mode_a_hmclr,    //
	input  wire        mode_a_16c,      //
	input  wire        mode_a_text,     //

	input  wire        mode_pixf_14     //
);


	reg [4:0] flash_ctr;
	wire flash;

	initial
	begin
		flash_ctr = 0;
	end

	always @(posedge clk) if( int_start )
	begin
		flash_ctr <= flash_ctr + 1;
	end
	assign flash = flash_ctr[4];





	// fetched data divided in bytes
	wire [7:0] bits [0:7];

	assign bits[0] = pic_bits[ 7:0 ];
	assign bits[1] = pic_bits[15:8 ];
	assign bits[2] = pic_bits[23:16];
	assign bits[3] = pic_bits[31:24];
	assign bits[4] = pic_bits[39:32];
	assign bits[5] = pic_bits[47:40];
	assign bits[6] = pic_bits[55:48];
	assign bits[7] = pic_bits[63:56];



	reg [1:0] gnum; // pixel group number
	reg [2:0] pnum; // pixel number
	wire [1:0] gadd;
	wire [2:0] padd;
	wire ginc;

	wire modes_16c;
	

	wire   ena_pix;
	assign ena_pix = cbeg | (mode_pixf_14 & pre_cend);


	assign modes_16c = mode_p_16c | mode_a_16c;

	assign {ginc, padd} = {1'b0, pnum} + {2'b00, modes_16c, ~modes_16c};

	always @(posedge clk) if( ena_pix )
	if( fetch_sync )
		pnum <= 3'b000;
	else
		pnum <= padd;


	assign gadd = gnum + ( {mode_zx,~mode_zx} & {2{ginc}} );

	always @(posedge clk) if( ena_pix )
	if( fetch_sync )
		gnum <= 2'b00;
	else
		gnum <= gadd;




	wire [15:0] pgroup; // pixel group
	wire [7:0] pixbyte, symbyte, attrbyte;
	wire [7:0] pix16_2 [0:1];
	wire [3:0] pix16   [0:3];

	wire pixbit; // pixel bit, for attr modes
	wire [3:0] pix0, pix1; // colors for bit=0 and bit=1, for attr modes

	wire [3:0] apix, c16pix;


	assign pgroup = { bits[ {gnum[0], 1'b0, gnum[1]} ] ,
	                  bits[ {gnum[0], 1'b1, gnum[1]} ] };

	assign pixbyte  = pgroup[15:8];
	assign attrbyte = pgroup[ 7:0];


	assign pix16_2[0] = pgroup[ 7:0];
	assign pix16_2[1] = pgroup[15:8];

	assign pix16[0] = { pix16_2[0][6], pix16_2[0][2:0] };
	assign pix16[1] = { pix16_2[0][7], pix16_2[0][5:3] };
	assign pix16[2] = { pix16_2[1][6], pix16_2[1][2:0] };
	assign pix16[3] = { pix16_2[1][7], pix16_2[1][5:3] };


	assign pixbit = mode_a_text ? symbyte[pnum] : pixbyte[pnum];

	assign pix0 = { (mode_zx ? attrbyte[6] : attrbyte[7]), attrbyte[5:3] }; // paper
	assign pix1 = { attrbyte[6], attrbyte[2:0] }; // ink

	
	assign apix = ( pixbit^(flash&mode_zx) ) ? pix1 : pix0;

	assign c16pix = pix16[ pnum[2:1] ];



	assign pixels = modes_16c ? c16pix : apix;





	video_fontrom video_fontrom(

		.address( {typos, pixbyte} ),

		.q( symbyte )
	);



/*
	wire [3:0] pix0, pix1, zxcolor;
	wire [7:0] pixbyte, attrbyte;

	assign attrbyte = bits[ { 2'b01, pixnum[3] } ];

	assign pix0 = { attrbyte[6], attrbyte[5:3] };
	assign pix1 = { attrbyte[6], attrbyte[2:0] };

	assign pixbyte = bits[ { 2'b00, pixnum[3] } ];

	assign pixels = ( pixbyte[~pixnum[2:0]] ^ (flash & attrbyte[7]) ) ? pix1 : pix0;
*/


endmodule

