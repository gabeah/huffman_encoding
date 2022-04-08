//Gabe H and Daniel K
// Decoder

#include "bitio.hh"
#include "huffman.hh"
#include <fstream>

int main(int argc, char *argv[]) {
	if(argc < 2){
		std::cout << "ERROR: NO FILE TO DECOMPRESS, try again pls <3 \n";
		return 0;
	}
	else {
		for(int i = 1; i < argc; i++){

			std::ifstream is_file (argv[i], std::ifstream::in);
			BitInput input(is_file);
			
			std::cout << "Opened File... \n";

			std::string filename = argv[i];

			std::ofstream os_file (filename+".plaintxt", std::ofstream::out);
			
			std::cout << "Created Output... \n";

			Huffman decode_tree;
			int symbol = -1;

			std::cout << "Begin Decoding... \n";
			while (true) {
				while (symbol < 0) { 
			 		symbol = decode_tree.decode(input.input_bit());
			 	}
			 	if(symbol == Huffman::HEOF){
					break;
				}
				else {
			 	os_file.put(symbol); 
			 	symbol = -1;
				}
			} 	
			std::cout << "Done \n";
			return 0;
		
		}
	}
}
