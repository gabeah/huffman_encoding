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

			for(int j = 0; j < f_length; j++){
				is_file.seekg(0, is_file.beg);
				int char_in = get(is_file.seekg(0,j));
				bits_t char_bit = Huffman::encode(char_in);
			}
		}
	}
}
