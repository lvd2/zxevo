module sdgovnoemu
(
	input  wire cs_n,
	input  wire clk,
	input  wire doo,
	output wire di
);

	integer counter=0;
	integer bitphase=0;

	reg [7:0] shout;


	assign di = shout[7];

	always @(negedge cs_n)
	begin
		bitphase = 0;

		shout <= counter[7:0];
	end

	always @(negedge clk)
	begin
		bitphase = bitphase + 1;
		if( bitphase>7 )
			bitphase = 0;

		if( bitphase==0 )
		begin
			counter = counter + 1;
			if( counter>256 )
				counter = 0;

			shout <= counter[7:0];
		end
		else
			shout[7:0] <= { shout[6:0], 1'b0 };
	end


endmodule
