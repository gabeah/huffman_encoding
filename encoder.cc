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

			std::ifstream is_file (argv[i], in *);
			is_file.seekg (0, is_file.end);
			int f_length = is.tellg();
			is_file.seekg (0, is_file.beg);

			std::ofstream os_file (argv[i]+".comp", out *);
			BitOutput::BitOutput(os_file);
			
			char symbol;

			while(is_file.get(symbol)){
				bits_t char_bit = Huffman::encode(symbol);
				BitOutput::output_bit(char_bit);
			}
			
			is_file.close();
			os_file.close();

			return 0;
		}
	}
}
