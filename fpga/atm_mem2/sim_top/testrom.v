// bin2v output
// 

module bin2v(

	input  wire [ 9:0] in_addr,

	output reg  [ 7:0] out_word

);

	always @*
	case( in_addr )

		10'h0: out_word = 8'hF3;
		10'h1: out_word = 8'hED;
		10'h2: out_word = 8'h56;
		10'h3: out_word = 8'h01;
		10'h4: out_word = 8'h77;
		10'h5: out_word = 8'h00;
		10'h6: out_word = 8'h3E;
		10'h7: out_word = 8'h02;
		10'h8: out_word = 8'hED;
		10'h9: out_word = 8'h79;
		10'hA: out_word = 8'h21;
		10'hB: out_word = 8'hD9;
		10'hC: out_word = 8'h00;
		10'hD: out_word = 8'h11;
		10'hE: out_word = 8'h41;
		10'hF: out_word = 8'h00;
		10'h10: out_word = 8'h01;
		10'h11: out_word = 8'hF7;
		10'h12: out_word = 8'h40;
		10'h13: out_word = 8'hED;
		10'h14: out_word = 8'hA3;
		10'h15: out_word = 8'h78;
		10'h16: out_word = 8'h83;
		10'h17: out_word = 8'h47;
		10'h18: out_word = 8'hFE;
		10'h19: out_word = 8'h40;
		10'h1A: out_word = 8'h20;
		10'h1B: out_word = 8'hF7;
		10'h1C: out_word = 8'h01;
		10'h1D: out_word = 8'hFD;
		10'h1E: out_word = 8'h7F;
		10'h1F: out_word = 8'h7A;
		10'h20: out_word = 8'hEE;
		10'h21: out_word = 8'h10;
		10'h22: out_word = 8'h57;
		10'h23: out_word = 8'hED;
		10'h24: out_word = 8'h79;
		10'h25: out_word = 8'h20;
		10'h26: out_word = 8'hE9;
		10'h27: out_word = 8'h01;
		10'h28: out_word = 8'h77;
		10'h29: out_word = 8'h00;
		10'h2A: out_word = 8'h3E;
		10'h2B: out_word = 8'h06;
		10'h2C: out_word = 8'hED;
		10'h2D: out_word = 8'h79;
		10'h2E: out_word = 8'h21;
		10'h2F: out_word = 8'hD9;
		10'h30: out_word = 8'h00;
		10'h31: out_word = 8'h11;
		10'h32: out_word = 8'h41;
		10'h33: out_word = 8'h00;
		10'h34: out_word = 8'h01;
		10'h35: out_word = 8'hF7;
		10'h36: out_word = 8'h40;
		10'h37: out_word = 8'hED;
		10'h38: out_word = 8'hA3;
		10'h39: out_word = 8'h78;
		10'h3A: out_word = 8'h83;
		10'h3B: out_word = 8'h47;
		10'h3C: out_word = 8'hFE;
		10'h3D: out_word = 8'h40;
		10'h3E: out_word = 8'h20;
		10'h3F: out_word = 8'hF7;
		10'h40: out_word = 8'h01;
		10'h41: out_word = 8'hFD;
		10'h42: out_word = 8'h7F;
		10'h43: out_word = 8'h7A;
		10'h44: out_word = 8'hEE;
		10'h45: out_word = 8'h10;
		10'h46: out_word = 8'h57;
		10'h47: out_word = 8'hED;
		10'h48: out_word = 8'h79;
		10'h49: out_word = 8'h20;
		10'h4A: out_word = 8'hE9;
		10'h4B: out_word = 8'h3E;
		10'h4C: out_word = 8'h10;
		10'h4D: out_word = 8'hED;
		10'h4E: out_word = 8'h79;
		10'h4F: out_word = 8'h3E;
		10'h50: out_word = 8'h06;
		10'h51: out_word = 8'h01;
		10'h52: out_word = 8'h77;
		10'h53: out_word = 8'h01;
		10'h54: out_word = 8'hED;
		10'h55: out_word = 8'h79;
		10'h56: out_word = 8'h21;
		10'h57: out_word = 8'hE1;
		10'h58: out_word = 8'h00;
		10'h59: out_word = 8'h11;
		10'h5A: out_word = 8'h10;
		10'h5B: out_word = 8'h06;
		10'h5C: out_word = 8'h0E;
		10'h5D: out_word = 8'h77;
		10'h5E: out_word = 8'h3E;
		10'h5F: out_word = 8'h08;
		10'h60: out_word = 8'hD3;
		10'h61: out_word = 8'hFF;
		10'h62: out_word = 8'h7E;
		10'h63: out_word = 8'h23;
		10'h64: out_word = 8'hD3;
		10'h65: out_word = 8'hFF;
		10'h66: out_word = 8'h06;
		10'h67: out_word = 8'h41;
		10'h68: out_word = 8'hED;
		10'h69: out_word = 8'h51;
		10'h6A: out_word = 8'hF6;
		10'h6B: out_word = 8'h08;
		10'h6C: out_word = 8'hD3;
		10'h6D: out_word = 8'hFF;
		10'h6E: out_word = 8'h06;
		10'h6F: out_word = 8'h01;
		10'h70: out_word = 8'hED;
		10'h71: out_word = 8'h51;
		10'h72: out_word = 8'h1D;
		10'h73: out_word = 8'h20;
		10'h74: out_word = 8'hED;
		10'h75: out_word = 8'h01;
		10'h76: out_word = 8'h77;
		10'h77: out_word = 8'h41;
		10'h78: out_word = 8'h3E;
		10'h79: out_word = 8'h06;
		10'h7A: out_word = 8'hED;
		10'h7B: out_word = 8'h79;
		10'h7C: out_word = 8'h3E;
		10'h7D: out_word = 8'hFF;
		10'h7E: out_word = 8'hD3;
		10'h7F: out_word = 8'hFF;
		10'h80: out_word = 8'h3E;
		10'h81: out_word = 8'hA6;
		10'h82: out_word = 8'h01;
		10'h83: out_word = 8'h77;
		10'h84: out_word = 8'hBD;
		10'h85: out_word = 8'hED;
		10'h86: out_word = 8'h79;
		10'h87: out_word = 8'hAF;
		10'h88: out_word = 8'hE6;
		10'h89: out_word = 8'hF8;
		10'h8A: out_word = 8'h21;
		10'h8B: out_word = 8'hF1;
		10'h8C: out_word = 8'h00;
		10'h8D: out_word = 8'h0E;
		10'h8E: out_word = 8'hFF;
		10'h8F: out_word = 8'h16;
		10'h90: out_word = 8'h08;
		10'h91: out_word = 8'hD9;
		10'h92: out_word = 8'h0E;
		10'h93: out_word = 8'hFE;
		10'h94: out_word = 8'hD9;
		10'h95: out_word = 8'hD9;
		10'h96: out_word = 8'hED;
		10'h97: out_word = 8'h79;
		10'h98: out_word = 8'hD9;
		10'h99: out_word = 8'hED;
		10'h9A: out_word = 8'hA3;
		10'h9B: out_word = 8'h3C;
		10'h9C: out_word = 8'h15;
		10'h9D: out_word = 8'h20;
		10'h9E: out_word = 8'hF6;
		10'h9F: out_word = 8'hD9;
		10'hA0: out_word = 8'h0E;
		10'hA1: out_word = 8'hF6;
		10'hA2: out_word = 8'hD9;
		10'hA3: out_word = 8'hAF;
		10'hA4: out_word = 8'h16;
		10'hA5: out_word = 8'h08;
		10'hA6: out_word = 8'hD9;
		10'hA7: out_word = 8'hED;
		10'hA8: out_word = 8'h79;
		10'hA9: out_word = 8'hD9;
		10'hAA: out_word = 8'hED;
		10'hAB: out_word = 8'hA3;
		10'hAC: out_word = 8'h3C;
		10'hAD: out_word = 8'h15;
		10'hAE: out_word = 8'h20;
		10'hAF: out_word = 8'hF6;
		10'hB0: out_word = 8'hAF;
		10'hB1: out_word = 8'h01;
		10'hB2: out_word = 8'hFE;
		10'hB3: out_word = 8'hAD;
		10'hB4: out_word = 8'hED;
		10'hB5: out_word = 8'h79;
		10'hB6: out_word = 8'h21;
		10'hB7: out_word = 8'h01;
		10'hB8: out_word = 8'h01;
		10'hB9: out_word = 8'h11;
		10'hBA: out_word = 8'h00;
		10'hBB: out_word = 8'h41;
		10'hBC: out_word = 8'h01;
		10'hBD: out_word = 8'h83;
		10'hBE: out_word = 8'h01;
		10'hBF: out_word = 8'hED;
		10'hC0: out_word = 8'hB0;
		10'hC1: out_word = 8'h21;
		10'hC2: out_word = 8'hCF;
		10'hC3: out_word = 8'h00;
		10'hC4: out_word = 8'h11;
		10'hC5: out_word = 8'h00;
		10'hC6: out_word = 8'h40;
		10'hC7: out_word = 8'h01;
		10'hC8: out_word = 8'h0A;
		10'hC9: out_word = 8'h00;
		10'hCA: out_word = 8'hED;
		10'hCB: out_word = 8'hB0;
		10'hCC: out_word = 8'hC3;
		10'hCD: out_word = 8'h00;
		10'hCE: out_word = 8'h40;
		10'hCF: out_word = 8'h01;
		10'hD0: out_word = 8'h77;
		10'hD1: out_word = 8'h41;
		10'hD2: out_word = 8'h3E;
		10'hD3: out_word = 8'hAB;
		10'hD4: out_word = 8'hED;
		10'hD5: out_word = 8'h79;
		10'hD6: out_word = 8'hC3;
		10'hD7: out_word = 8'h04;
		10'hD8: out_word = 8'h41;
		10'hD9: out_word = 8'h7F;
		10'hDA: out_word = 8'h7B;
		10'hDB: out_word = 8'h7D;
		10'hDC: out_word = 8'h7C;
		10'hDD: out_word = 8'h00;
		10'hDE: out_word = 8'h7A;
		10'hDF: out_word = 8'h7D;
		10'hE0: out_word = 8'h60;
		10'hE1: out_word = 8'hF1;
		10'hE2: out_word = 8'hE1;
		10'hE3: out_word = 8'hD1;
		10'hE4: out_word = 8'hC1;
		10'hE5: out_word = 8'hC1;
		10'hE6: out_word = 8'hB1;
		10'hE7: out_word = 8'hA1;
		10'hE8: out_word = 8'h91;
		10'hE9: out_word = 8'h41;
		10'hEA: out_word = 8'h21;
		10'hEB: out_word = 8'h31;
		10'hEC: out_word = 8'h11;
		10'hED: out_word = 8'h01;
		10'hEE: out_word = 8'h01;
		10'hEF: out_word = 8'hF1;
		10'hF0: out_word = 8'hE1;
		10'hF1: out_word = 8'hFF;
		10'hF2: out_word = 8'hFE;
		10'hF3: out_word = 8'hFD;
		10'hF4: out_word = 8'hFC;
		10'hF5: out_word = 8'hEF;
		10'hF6: out_word = 8'hEE;
		10'hF7: out_word = 8'hED;
		10'hF8: out_word = 8'hEC;
		10'hF9: out_word = 8'hFF;
		10'hFA: out_word = 8'hDE;
		10'hFB: out_word = 8'hBD;
		10'hFC: out_word = 8'h9C;
		10'hFD: out_word = 8'h6F;
		10'hFE: out_word = 8'h4E;
		10'hFF: out_word = 8'h2D;
		10'h100: out_word = 8'h0C;
		10'h101: out_word = 8'hF3;
		10'h102: out_word = 8'hCD;
		10'h103: out_word = 8'h77;
		10'h104: out_word = 8'h42;
		10'h105: out_word = 8'hDD;
		10'h106: out_word = 8'h21;
		10'h107: out_word = 8'h00;
		10'h108: out_word = 8'h44;
		10'h109: out_word = 8'h21;
		10'h10A: out_word = 8'h2D;
		10'h10B: out_word = 8'h41;
		10'h10C: out_word = 8'h11;
		10'h10D: out_word = 8'h00;
		10'h10E: out_word = 8'h44;
		10'h10F: out_word = 8'h01;
		10'h110: out_word = 8'hA5;
		10'h111: out_word = 8'h00;
		10'h112: out_word = 8'hED;
		10'h113: out_word = 8'hB0;
		10'h114: out_word = 8'h21;
		10'h115: out_word = 8'hD2;
		10'h116: out_word = 8'h41;
		10'h117: out_word = 8'h11;
		10'h118: out_word = 8'h00;
		10'h119: out_word = 8'h46;
		10'h11A: out_word = 8'h01;
		10'h11B: out_word = 8'hA5;
		10'h11C: out_word = 8'h00;
		10'h11D: out_word = 8'hED;
		10'h11E: out_word = 8'hB0;
		10'h11F: out_word = 8'h21;
		10'h120: out_word = 8'h00;
		10'h121: out_word = 8'h59;
		10'h122: out_word = 8'h54;
		10'h123: out_word = 8'h5D;
		10'h124: out_word = 8'h13;
		10'h125: out_word = 8'h01;
		10'h126: out_word = 8'hFF;
		10'h127: out_word = 8'h00;
		10'h128: out_word = 8'h36;
		10'h129: out_word = 8'h07;
		10'h12A: out_word = 8'hED;
		10'h12B: out_word = 8'hB0;
		10'h12C: out_word = 8'hDD;
		10'h12D: out_word = 8'hE9;
		10'h12E: out_word = 8'h3E;
		10'h12F: out_word = 8'h3F;
		10'h130: out_word = 8'h01;
		10'h131: out_word = 8'hF7;
		10'h132: out_word = 8'hBF;
		10'h133: out_word = 8'h21;
		10'h134: out_word = 8'h00;
		10'h135: out_word = 8'h80;
		10'h136: out_word = 8'hEE;
		10'h137: out_word = 8'h7F;
		10'h138: out_word = 8'hED;
		10'h139: out_word = 8'h79;
		10'h13A: out_word = 8'hEE;
		10'h13B: out_word = 8'h7F;
		10'h13C: out_word = 8'h77;
		10'h13D: out_word = 8'hA7;
		10'h13E: out_word = 8'h28;
		10'h13F: out_word = 8'h03;
		10'h140: out_word = 8'h3D;
		10'h141: out_word = 8'h18;
		10'h142: out_word = 8'hF3;
		10'h143: out_word = 8'h3E;
		10'h144: out_word = 8'h3F;
		10'h145: out_word = 8'h01;
		10'h146: out_word = 8'hF7;
		10'h147: out_word = 8'hFF;
		10'h148: out_word = 8'h21;
		10'h149: out_word = 8'h00;
		10'h14A: out_word = 8'hC0;
		10'h14B: out_word = 8'hEE;
		10'h14C: out_word = 8'h7F;
		10'h14D: out_word = 8'hED;
		10'h14E: out_word = 8'h79;
		10'h14F: out_word = 8'hEE;
		10'h150: out_word = 8'h7F;
		10'h151: out_word = 8'hBE;
		10'h152: out_word = 8'h57;
		10'h153: out_word = 8'h08;
		10'h154: out_word = 8'h7A;
		10'h155: out_word = 8'hC6;
		10'h156: out_word = 8'h00;
		10'h157: out_word = 8'h5F;
		10'h158: out_word = 8'h7A;
		10'h159: out_word = 8'h08;
		10'h15A: out_word = 8'h3E;
		10'h15B: out_word = 8'h20;
		10'h15C: out_word = 8'h28;
		10'h15D: out_word = 8'h02;
		10'h15E: out_word = 8'h3E;
		10'h15F: out_word = 8'h10;
		10'h160: out_word = 8'h16;
		10'h161: out_word = 8'h59;
		10'h162: out_word = 8'h12;
		10'h163: out_word = 8'h08;
		10'h164: out_word = 8'h36;
		10'h165: out_word = 8'h00;
		10'h166: out_word = 8'hA7;
		10'h167: out_word = 8'h28;
		10'h168: out_word = 8'h03;
		10'h169: out_word = 8'h3D;
		10'h16A: out_word = 8'h18;
		10'h16B: out_word = 8'hDF;
		10'h16C: out_word = 8'h3E;
		10'h16D: out_word = 8'h3F;
		10'h16E: out_word = 8'h01;
		10'h16F: out_word = 8'hF7;
		10'h170: out_word = 8'hFF;
		10'h171: out_word = 8'h21;
		10'h172: out_word = 8'h00;
		10'h173: out_word = 8'hC0;
		10'h174: out_word = 8'hEE;
		10'h175: out_word = 8'h7F;
		10'h176: out_word = 8'hED;
		10'h177: out_word = 8'h79;
		10'h178: out_word = 8'hEE;
		10'h179: out_word = 8'h7F;
		10'h17A: out_word = 8'h77;
		10'h17B: out_word = 8'hA7;
		10'h17C: out_word = 8'h28;
		10'h17D: out_word = 8'h03;
		10'h17E: out_word = 8'h3D;
		10'h17F: out_word = 8'h18;
		10'h180: out_word = 8'hF3;
		10'h181: out_word = 8'h3E;
		10'h182: out_word = 8'h3F;
		10'h183: out_word = 8'h01;
		10'h184: out_word = 8'hF7;
		10'h185: out_word = 8'hBF;
		10'h186: out_word = 8'h21;
		10'h187: out_word = 8'h00;
		10'h188: out_word = 8'h80;
		10'h189: out_word = 8'hEE;
		10'h18A: out_word = 8'h7F;
		10'h18B: out_word = 8'hED;
		10'h18C: out_word = 8'h79;
		10'h18D: out_word = 8'hEE;
		10'h18E: out_word = 8'h7F;
		10'h18F: out_word = 8'hBE;
		10'h190: out_word = 8'h57;
		10'h191: out_word = 8'h08;
		10'h192: out_word = 8'h7A;
		10'h193: out_word = 8'hC6;
		10'h194: out_word = 8'h40;
		10'h195: out_word = 8'h5F;
		10'h196: out_word = 8'h7A;
		10'h197: out_word = 8'h08;
		10'h198: out_word = 8'h3E;
		10'h199: out_word = 8'h20;
		10'h19A: out_word = 8'h28;
		10'h19B: out_word = 8'h02;
		10'h19C: out_word = 8'h3E;
		10'h19D: out_word = 8'h10;
		10'h19E: out_word = 8'h16;
		10'h19F: out_word = 8'h59;
		10'h1A0: out_word = 8'h12;
		10'h1A1: out_word = 8'h08;
		10'h1A2: out_word = 8'h36;
		10'h1A3: out_word = 8'h00;
		10'h1A4: out_word = 8'hA7;
		10'h1A5: out_word = 8'h28;
		10'h1A6: out_word = 8'h03;
		10'h1A7: out_word = 8'h3D;
		10'h1A8: out_word = 8'h18;
		10'h1A9: out_word = 8'hDF;
		10'h1AA: out_word = 8'h3E;
		10'h1AB: out_word = 8'h7A;
		10'h1AC: out_word = 8'h01;
		10'h1AD: out_word = 8'hF7;
		10'h1AE: out_word = 8'hBF;
		10'h1AF: out_word = 8'hED;
		10'h1B0: out_word = 8'h79;
		10'h1B1: out_word = 8'hFD;
		10'h1B2: out_word = 8'h21;
		10'h1B3: out_word = 8'h00;
		10'h1B4: out_word = 8'h48;
		10'h1B5: out_word = 8'hFD;
		10'h1B6: out_word = 8'h34;
		10'h1B7: out_word = 8'h00;
		10'h1B8: out_word = 8'h20;
		10'h1B9: out_word = 8'h05;
		10'h1BA: out_word = 8'hFD;
		10'h1BB: out_word = 8'h23;
		10'h1BC: out_word = 8'hFD;
		10'h1BD: out_word = 8'h34;
		10'h1BE: out_word = 8'h00;
		10'h1BF: out_word = 8'hFD;
		10'h1C0: out_word = 8'h21;
		10'h1C1: out_word = 8'hFF;
		10'h1C2: out_word = 8'h4F;
		10'h1C3: out_word = 8'hFD;
		10'h1C4: out_word = 8'h35;
		10'h1C5: out_word = 8'h00;
		10'h1C6: out_word = 8'h20;
		10'h1C7: out_word = 8'h05;
		10'h1C8: out_word = 8'hFD;
		10'h1C9: out_word = 8'h2B;
		10'h1CA: out_word = 8'hFD;
		10'h1CB: out_word = 8'h35;
		10'h1CC: out_word = 8'h00;
		10'h1CD: out_word = 8'hDD;
		10'h1CE: out_word = 8'h21;
		10'h1CF: out_word = 8'h00;
		10'h1D0: out_word = 8'h86;
		10'h1D1: out_word = 8'hDD;
		10'h1D2: out_word = 8'hE9;
		10'h1D3: out_word = 8'h3E;
		10'h1D4: out_word = 8'h3F;
		10'h1D5: out_word = 8'h01;
		10'h1D6: out_word = 8'hF7;
		10'h1D7: out_word = 8'h3F;
		10'h1D8: out_word = 8'h21;
		10'h1D9: out_word = 8'h00;
		10'h1DA: out_word = 8'h00;
		10'h1DB: out_word = 8'hEE;
		10'h1DC: out_word = 8'h7F;
		10'h1DD: out_word = 8'hED;
		10'h1DE: out_word = 8'h79;
		10'h1DF: out_word = 8'hEE;
		10'h1E0: out_word = 8'h7F;
		10'h1E1: out_word = 8'h77;
		10'h1E2: out_word = 8'hA7;
		10'h1E3: out_word = 8'h28;
		10'h1E4: out_word = 8'h03;
		10'h1E5: out_word = 8'h3D;
		10'h1E6: out_word = 8'h18;
		10'h1E7: out_word = 8'hF3;
		10'h1E8: out_word = 8'h3E;
		10'h1E9: out_word = 8'h3F;
		10'h1EA: out_word = 8'h01;
		10'h1EB: out_word = 8'hF7;
		10'h1EC: out_word = 8'h7F;
		10'h1ED: out_word = 8'h21;
		10'h1EE: out_word = 8'h00;
		10'h1EF: out_word = 8'h40;
		10'h1F0: out_word = 8'hEE;
		10'h1F1: out_word = 8'h7F;
		10'h1F2: out_word = 8'hED;
		10'h1F3: out_word = 8'h79;
		10'h1F4: out_word = 8'hEE;
		10'h1F5: out_word = 8'h7F;
		10'h1F6: out_word = 8'hBE;
		10'h1F7: out_word = 8'h57;
		10'h1F8: out_word = 8'h08;
		10'h1F9: out_word = 8'h7A;
		10'h1FA: out_word = 8'hC6;
		10'h1FB: out_word = 8'h80;
		10'h1FC: out_word = 8'h5F;
		10'h1FD: out_word = 8'h7A;
		10'h1FE: out_word = 8'h08;
		10'h1FF: out_word = 8'h3E;
		10'h200: out_word = 8'h20;
		10'h201: out_word = 8'h28;
		10'h202: out_word = 8'h02;
		10'h203: out_word = 8'h3E;
		10'h204: out_word = 8'h10;
		10'h205: out_word = 8'h16;
		10'h206: out_word = 8'h99;
		10'h207: out_word = 8'h12;
		10'h208: out_word = 8'h08;
		10'h209: out_word = 8'h36;
		10'h20A: out_word = 8'h00;
		10'h20B: out_word = 8'hA7;
		10'h20C: out_word = 8'h28;
		10'h20D: out_word = 8'h03;
		10'h20E: out_word = 8'h3D;
		10'h20F: out_word = 8'h18;
		10'h210: out_word = 8'hDF;
		10'h211: out_word = 8'h3E;
		10'h212: out_word = 8'h3F;
		10'h213: out_word = 8'h01;
		10'h214: out_word = 8'hF7;
		10'h215: out_word = 8'h7F;
		10'h216: out_word = 8'h21;
		10'h217: out_word = 8'h00;
		10'h218: out_word = 8'h40;
		10'h219: out_word = 8'hEE;
		10'h21A: out_word = 8'h7F;
		10'h21B: out_word = 8'hED;
		10'h21C: out_word = 8'h79;
		10'h21D: out_word = 8'hEE;
		10'h21E: out_word = 8'h7F;
		10'h21F: out_word = 8'h77;
		10'h220: out_word = 8'hA7;
		10'h221: out_word = 8'h28;
		10'h222: out_word = 8'h03;
		10'h223: out_word = 8'h3D;
		10'h224: out_word = 8'h18;
		10'h225: out_word = 8'hF3;
		10'h226: out_word = 8'h3E;
		10'h227: out_word = 8'h3F;
		10'h228: out_word = 8'h01;
		10'h229: out_word = 8'hF7;
		10'h22A: out_word = 8'h3F;
		10'h22B: out_word = 8'h21;
		10'h22C: out_word = 8'h00;
		10'h22D: out_word = 8'h00;
		10'h22E: out_word = 8'hEE;
		10'h22F: out_word = 8'h7F;
		10'h230: out_word = 8'hED;
		10'h231: out_word = 8'h79;
		10'h232: out_word = 8'hEE;
		10'h233: out_word = 8'h7F;
		10'h234: out_word = 8'hBE;
		10'h235: out_word = 8'h57;
		10'h236: out_word = 8'h08;
		10'h237: out_word = 8'h7A;
		10'h238: out_word = 8'hC6;
		10'h239: out_word = 8'hC0;
		10'h23A: out_word = 8'h5F;
		10'h23B: out_word = 8'h7A;
		10'h23C: out_word = 8'h08;
		10'h23D: out_word = 8'h3E;
		10'h23E: out_word = 8'h20;
		10'h23F: out_word = 8'h28;
		10'h240: out_word = 8'h02;
		10'h241: out_word = 8'h3E;
		10'h242: out_word = 8'h10;
		10'h243: out_word = 8'h16;
		10'h244: out_word = 8'h99;
		10'h245: out_word = 8'h12;
		10'h246: out_word = 8'h08;
		10'h247: out_word = 8'h36;
		10'h248: out_word = 8'h00;
		10'h249: out_word = 8'hA7;
		10'h24A: out_word = 8'h28;
		10'h24B: out_word = 8'h03;
		10'h24C: out_word = 8'h3D;
		10'h24D: out_word = 8'h18;
		10'h24E: out_word = 8'hDF;
		10'h24F: out_word = 8'h3E;
		10'h250: out_word = 8'h7A;
		10'h251: out_word = 8'h01;
		10'h252: out_word = 8'hF7;
		10'h253: out_word = 8'h7F;
		10'h254: out_word = 8'hED;
		10'h255: out_word = 8'h79;
		10'h256: out_word = 8'hFD;
		10'h257: out_word = 8'h21;
		10'h258: out_word = 8'h00;
		10'h259: out_word = 8'h88;
		10'h25A: out_word = 8'hFD;
		10'h25B: out_word = 8'h34;
		10'h25C: out_word = 8'h00;
		10'h25D: out_word = 8'h20;
		10'h25E: out_word = 8'h05;
		10'h25F: out_word = 8'hFD;
		10'h260: out_word = 8'h23;
		10'h261: out_word = 8'hFD;
		10'h262: out_word = 8'h34;
		10'h263: out_word = 8'h00;
		10'h264: out_word = 8'hFD;
		10'h265: out_word = 8'h21;
		10'h266: out_word = 8'hFF;
		10'h267: out_word = 8'h8F;
		10'h268: out_word = 8'hFD;
		10'h269: out_word = 8'h35;
		10'h26A: out_word = 8'h00;
		10'h26B: out_word = 8'h20;
		10'h26C: out_word = 8'h05;
		10'h26D: out_word = 8'hFD;
		10'h26E: out_word = 8'h2B;
		10'h26F: out_word = 8'hFD;
		10'h270: out_word = 8'h35;
		10'h271: out_word = 8'h00;
		10'h272: out_word = 8'hDD;
		10'h273: out_word = 8'h21;
		10'h274: out_word = 8'h00;
		10'h275: out_word = 8'h44;
		10'h276: out_word = 8'hDD;
		10'h277: out_word = 8'hE9;
		10'h278: out_word = 8'h01;
		10'h279: out_word = 8'h53;
		10'h27A: out_word = 8'h2A;
		10'h27B: out_word = 8'hC5;
		10'h27C: out_word = 8'h01;
		10'h27D: out_word = 8'h77;
		10'h27E: out_word = 8'h41;
		10'h27F: out_word = 8'h3E;
		10'h280: out_word = 8'hAB;
		10'h281: out_word = 8'hC3;
		10'h282: out_word = 8'h2F;
		10'h283: out_word = 8'h3D;

		default: out_word = 8'hFF;

	endcase

endmodule
