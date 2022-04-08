//Gabe H and Daniel K
// Decoder

#include "bitio.hh"
#include "huffman.hh"
#include <fstream>

int main(int argc, char *argv[]) { 							// The decoder program (tm)
	if(argc < 2){ 									// If we didn't get a file to decode
		std::cout << "ERROR: NO FILE TO DECOMPRESS, try again pls <3 \n"; 	// BE MAD OMGGGGGGGG THIS SUXXXXXXXX
		return 0; 								// Rage quit
	}
	else { 										// Yay we have a file
		for(int i = 1; i < argc; i++){ 						// IGNORE THIS IS IN A LOOP
											// I THOUGHT WE HAD TO ENCODE/DECODE MULTIPLE FILES AND DID THIS
											// FORGIVE ME (gabe)

			std::ifstream is_file (argv[i], std::ifstream::in); 		// Create the input stream
			BitInput input(is_file); 					// Construct the input stream
			
			std::cout << "Opened File... \n"; 				// Text for dramatic effect

			std::string filename = argv[i]; 				// Take filename for sneaky purposes

			std::ofstream os_file (filename+".plaintxt", std::ofstream::out); // Create the output file
			
			std::cout << "Created Output... \n"; 				// Say what I just did

			Huffman decode_tree; 						// create our blank decode tree
			int symbol = -1; 						// create a placeholder for our symbol

			std::cout << "Begin Decoding... \n"; 				// dramatic effect x2

			while (true) { 							// Loop forever!!!!!!!!!!!!!!!!!!

				while (symbol < 0) {  					// As long as we don't encounter a node that matters
			 		symbol = decode_tree.decode(input.input_bit()); // keep taking bits
			 	} 							// I'm sorry placeholder nodes, you are important

			 	if(symbol == Huffman::HEOF){ 				// If we reach the end of the file, no longer loop forever
					break;
				}
				else { 							// Otherwise we have come to a symbol
			 	os_file.put(symbol);  					// Write the symbol to the new file
			 	symbol = -1; 						// Reset the symbol
				}
			} 	
			std::cout << "Done \n"; 					// And there was much rejoicing
			return 0; 			// STOP
		
		}
	}
}
