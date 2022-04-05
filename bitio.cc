#include "bitio.hh"
#include <iostream>
#include <algorithm>
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
		bufferInput = is.get();
		counterInput = 0;
	}
	bool val = bufferInput & 1;
	bufferInput = bufferInput >> 1;
	counterInput ++;
	return val;
}

void BitOutput::output_bit(bool bit){
	if(counterInput == 8){
		os.put(bufferInput);
		counterInput = 0;
	}
	if(bit){
		bufferinput = bufferinput << 1;
		counterInput ++;
	}
	else if(!bit){
		bufferinput = bufferinput << 0;
		counterInput ++;
	}
	else{
		assert(false);
	}


}