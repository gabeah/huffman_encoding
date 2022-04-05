#include "bitio.hh"
#include <iostream>
#include <algorithm>
#include <cassert>
BitInput::BitInput(std::istream& is)
:is_(is), bufferInput(0), counterInput(8)
{}
BitOutput::BitOutput(std::ostream& os)
:os_(os),  bufferOutput(0), counterOutput(0)
{}
bool BitInput::input_bit(){
	if(counterInput == 8){
		bufferInput = is_.get();
		counterInput = 0;
	}
	bool val = (bufferInput >> (7 - counterInput)) & 1;
	counterInput ++;
	return val;
}

void BitOutput::output_bit(bool bit){
	if(counterOutput == 8){
		os_.put(bufferOutput);
		bufferOutput = 0;
		counterOutput = 0;
	}
	bufferOutput <<= 1;
	bufferOutput = bufferOutput | bit;
	counterOutput++;

}
BitOutput::~BitOutput(){
	while(counterOutput < 8){
		bufferOutput <<= 1;
		counterOutput++;
	}
	os_.put(bufferOutput);
}

