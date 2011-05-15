// Pentevo project (c) NedoPC 2011
//
// NMI generation

`include "../include/tune.v"

module znmi
(
	input  wire rst_n,
	input  wire fclk,

	input  wire zpos,
	input  wire zneg,

	input  wire int_start, // when INT starts
	input  wire set_nmi,   // NMI request from slavespi

	input  wire clr_nmi, // clear nmi: from zports, pulsed at out to #xxBE


	// some more signals like /RFSH....



	output reg  in_nmi, // when 1, there must be last ram page in 0000-3FFF

	output wire gen_nmi // NMI generator: when 1, NMI_N=0, otherwise NMI_N=Z
);

	reg set_nmi_r;

	wire set_nmi_now;

	reg [4:0] nmi_count;


	always @(posedge fclk)
		set_nmi_r   <= set_nmi;

	assign set_nmi_now = (set_nmi_r != set_nmi);


	always @(posedge fclk, negedge rst_n)
	if( !rst_n )
		in_nmi <= 1'b0;
	else
	begin
		if( clr_nmi )
			in_nmi <= 1'b0;
		else if( set_nmi_now && (!in_nmi) )
			in_nmi <= 1'b1;
	end




	always @(posedge fclk, negedge rst_n)
	if( !rst_n )
		nmi_count <= 5'b0000;
	else if( set_nmi_now && (!in_nmi) )
		nmi_count <= 5'b11111;
	else if( nmi_count[4] )
		nmi_count <= nmi_count - 5'd1;


	assign gen_nmi <= nmi_count[4];


endmodule

