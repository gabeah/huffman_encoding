//Gabe H and Daniel K
// Decoder

#include "bitio.hh"
#include "huffman.hh"
#include <ifstream>

int main(int argc, char *argv[]) {
	if(argc < 2){
		std::cout << "ERROR: NO FILE TO DECOMPRESS, try again pls <3 \n";
		return 0;
	}
	else {
		for(int i = 1; i < argc; i++){

			std::ifstream is_file (argv[i], std::ifstream::in);
			BitInput input(is_file);

			std::string filename = argv[i];

			std::ofstream os_file (filename+".plaintxt", std::ofstream::out);
			
			Huffman decode_tree;
			char symbol;

			while (true) {
				while (symbol > 0) { 
			 		symbol = huff.decode(input.input_bit());
			 	}
			 	if (symbol == Huffman::HEOF) { 
			 		break;
			 	}
			 	else {
			 	 output.put(symbol); 
			 	 symbol = -1;
			 	}
			return 0;
		}
