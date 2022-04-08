//ENCODER!!!
//Gabe H and Daniel K

#include "huffman.hh"
#include "bitio.hh"
#include <cassert>
#include <fstream>


int main(int argc, char *argv[]) {
	if(argc < 2){
		std::cout << "ERROR: NO FILE TO COMPRESS, try again pls <3 \n";
		return 0;
	}
	else {

		std::ifstream is_file (argv[1], std::ifstream::in);

		std::string filename = argv[1];

		std::ofstream os_file (filename+".comp", std::ofstream::out);
		BitOutput output(os_file);	
		
		Huffman encode_tree;
		char symbol;

		while(is_file.get(symbol)){
			std::cout << symbol;
			Huffman::bits_t char_bit = encode_tree.encode(symbol);
			for(auto j : char_bit){
				output.output_bit(j);
			}
		}
		Huffman::bits_t char_bit = encode_tree.encode(Huffman::HEOF);
		for(auto k : char_bit){
			output.output_bit(k);
		}

		return 0;
	}
}
