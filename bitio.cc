#include "bitio.hh"
#include <iostream>
#include <algorithm>
#include <cassert>
BitInput::BitInput(std::istream& is) 		// Setup the input stream
:is_(is), bufferInput(0), counterInput(8)
{}

BitOutput::BitOutput(std::ostream& os) 		// Setup the output stream
:os_(os),  bufferOutput(0), counterOutput(0)
{}

bool BitInput::input_bit(){ 					// Function for reading a stream
	if(counterInput == 8){ 					// If we have read all the bits
		bufferInput = is_.get(); 			// Grab a new byte
		counterInput = 0; 				// Reset counter
	}
	bool val = (bufferInput >> (7 - counterInput)) & 1; 	// Set val to the bit we read
	counterInput ++; 					// Increase counter and return val
	return val;
}

void BitOutput::output_bit(bool bit){ 				// Function for writing to stream
	if(counterOutput == 8){ 				// If we have written all the bits to the byte
		os_.put(bufferOutput); 				// Send the byte
		bufferOutput = 0;
		counterOutput = 0;
	}
	bufferOutput <<= 1; 					// Shift the output Left 1 spot
	bufferOutput = bufferOutput | bit; 			// Put in that empty spot the bit we recieved
	counterOutput++; 					// Increase counter

}
BitOutput::~BitOutput(){ 			// The destructor
	while(counterOutput < 8){ 		// If we ended with an incomplete byte
		bufferOutput <<= 1; 		// Shift output 1 spot, and fill spot with 0
		counterOutput++; 		// Increase counter
	}
	os_.put(bufferOutput); 			// Write the byte
}

