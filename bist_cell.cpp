//Description: Built in Self Test with process definition

//Author: Pranav Prabhu

#include "bist_cell.h"


void bist_cell::prc_bist_cell() {

	bool s1,s2,s3;         //decalring temporary variable to assign computation to
	
	bool b0_v = b0.read();
    bool b1_v = b1.read();
    bool d0_v = d0.read();
    bool d1_v = d1.read();
	
	//Performing Computations

	s1 =! (b0 & d1);
	s2 =! (d0 & b1);
	s3 =! (s2 | s1);
	s2 = s2 & s1;
	//Assigning to output port
	//z = !(s2|s3);
	
	z.write(!(s2 || s3));

}


