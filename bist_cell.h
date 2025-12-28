// Description: Built in Self Test

// Author: Pranav Prabhu

#include <systemc.h>

SC_MODULE (bist_cell) {

	sc_in<bool> b0,b1,d0,d1;		//Declaring bool inputs
	sc_out<bool> z;				//Declaring bool output

	void prc_bist_cell();

	SC_CTOR (bist_cell) {
		SC_METHOD (prc_bist_cell);
		sensitive <<b0 <<b1 <<d0 <<d1;		//Sensitivity List
		}
		
	};
