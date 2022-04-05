#include "bitio.hh"
#include <iostream>
#include <algorithm>
#include <cassert>
BitInput::BitInput(std::istream& is){
	counterInput = 8;
	bufferInput = 0;
}
BitOutput::BitOutput(std::ostream& os){
	counterOutput = 8;
	bufferOutput = 0;
} 
bool BitInput::input_bit(){
	if(counterInput == 8){
		bufferInput = std::istream& is.get();
		counterInput = 0;
	}
	bool val = bufferInput & 1;
	bufferInput = bufferInput >> 1;
	counterInput ++;
	return val;
}

void BitOutput::output_bit(bool bit){
	if(counterOutput == 8){
		os.put(bufferOutput);
		counterOutput = 0;
	}
	if(bit){
		bufferOutput = bufferOutput << 1;
		counterOutput ++;
	}
	else if(!bit){
		bufferOutut = bufferOutput << 0;
		counterOutput ++;
	}
	else{
		assert(false);
	}


}