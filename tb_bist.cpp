// Description: Testbench for BIST Cell

//Author: Pranav Prabhu

#include <systemc.h>
#include "bist_cell.h"


SC_MODULE(tb_bist) {

	//Declaring tb variables
	sc_in<bool> z;
	sc_out<bool> b0; 
	sc_out<bool> b1; 
	sc_out<bool> d0; 
	sc_out<bool> d1; 

	void sim_proc(){
	
	//Test Vector 1
	b0.write(false);
	b1.write(false);
	d0.write(true);
	d1.write(false);
	wait(10,SC_NS);
	cout<<sc_time_stamp() <<": b0 = "<<b0.read()<<" b1 = "<< b1.read()<<" d0 = "<<d0.read()<<" d1 = " <<d1.read()<< "Z="<< z.read()<<endl;

	sc_stop();
	}

	SC_CTOR(tb_bist){
		SC_THREAD(sim_proc);
	}
};


int sc_main(int argc,char* argv[]) {

	sc_signal<bool> b0,b1,d0,d1,z;

	bist_cell dut("bist_cell");		//Instantiating BIST DUT
	dut.b0(b0);
	dut.b1(b1);
	dut.d0(d0);
	dut.d1(d1);
	dut.z(z);

	tb_bist tb("tb_bist");
	tb.b0(b0);
	tb.b1(b1);
	tb.d0(d0);
	tb.d1(d1);
	tb.z(z);
	sc_start();

	return 0;
}
