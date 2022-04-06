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
		for(int i = 1; i < argc; i++){

			std::ifstream is_file (argv[i], std::ifstream::in);

			std::string filename = argv[i];

			std::ofstream os_file (filename+".comp", std::ofstream::out);
			BitOutput output(os_file);	
			
			Huffman encode_tree;
			char symbol;

			while(is_file.get(symbol)){
				Huffman::bits_t char_bit = encode_tree.encode(symbol);
				for(auto j : char_bit){
					output.output_bit(j);
				}
			}
			
			is_file.close();
			os_file.close();

			return 0;
		}
	}
}
