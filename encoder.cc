//ENCODER!!!
//Gabe H and Daniel K

#include "huffman.hh"
#include "bitio.hh"
#include <cassert>
#include <fstream>


int main(int argc, char *argv[]) { 						// Main function for encoder
	if(argc < 2){ 								// If we weren't given a file
		std::cout << "ERROR: NO FILE TO COMPRESS, try again pls <3 \n"; // BE MAD!!!!! :((((( GIVE US FILES
		return 0; 							// Hi graders, gabe here, this project made me lose my mine, I appreciate you <333!!!
	}
	else { 									// Yay we were given a file

		std::ifstream is_file (argv[1], std::ifstream::in); 		// Setup the input stream

		std::string filename = argv[1]; 				// take the filename (for sneaky purposes)

		std::ofstream os_file (filename+".comp", std::ofstream::out); 	// Setup an output stream with the filename that we got with sneak
		BitOutput output(os_file);	 				// Construct writing program with our output file
		
		Huffman encode_tree; 						// Create our encoding tree
		char symbol; 							// setup our symbol for encoding

		while(is_file.get(symbol)){ 					// While there are bits to read, get one and set it to symbol
			std::cout << symbol; 					// Output the symbol we see (for testing purposes)
			Huffman::bits_t char_bit = encode_tree.encode(symbol);  // Encode with the symbol we have
			for(auto j : char_bit){ 				// For the bytes in what we encoded
				output.output_bit(j); 				// Write what we encoded
			}
		}
		Huffman::bits_t char_bit = encode_tree.encode(Huffman::HEOF);  	// After we read everything, encode the EndOfFile
		for(auto k : char_bit){ 					// Aaaaand write it!
			output.output_bit(k);
		}

		return 0; 	// end
	}
}
