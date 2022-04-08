//Gabe Howland and Daniel Kryzhanovsky
//HW9 - Huffman encoding
//Much thanks to Tutor Aria for walking through most of the code here
#include "huffman.hh"
#include <iostream>
#include <algorithm> 
#include "hforest.hh"


Huffman::Huffman(){ 			// Constructs a blank huffman tree, and a freq table with a single end of file
	for(int i = 0; i <256; i++){
		freq_table.push_back(0);
	}
	freq_table.push_back(1);
	//std::vector<int> freq_table(257,0);	
	//freq_table[256] = 1;	
}

void Huffman::build_huffman() { 						// Function to rebuild the huffman/update the tree during encode/decode

	HForest forest = HForest(); 						// Create an empty forest
	for (int c=0; c<Huffman::ALPHABET_SIZE; c++){ 				// For each value in the freq table, build a single tree node
		forest.add_tree(HTree::tree_ptr_t(new HTree(c, freq_table[c]))); // and add it to the forest.
		//forest.HForest::add_tree(tree);
	}
	while(forest.size()>1){ 						// As long as there are more than one tree...
		HTree::tree_ptr_t smallest = forest.HForest::pop_top(); 	// Take the smallest tree...
//		printf("key: %d\n", smallest->get_key());
//		printf("value: %ld\n", smallest->get_value());

		HTree::tree_ptr_t sec_smallest = forest.HForest::pop_top(); 	// ...and second smallest...
	
		 forest.add_tree(HTree::tree_ptr_t(new HTree(fake_key, 		// ...and create a new tree with them
			smallest->get_value()+sec_smallest->get_value(),
			smallest,
			sec_smallest)));
		//forest.HForest::add_tree(tree);
		fake_key--; 							// make the fake_key smaller to keep nodes different

	}

	huff_tree = forest.HForest::pop_top(); 					// When there is one tree, cleanup and update the Huffman tree
}

Huffman::bits_t Huffman::encode(int symbol) { 					// This function encodes the huffman tree

//	printf("%d\n", symbol);
	build_huffman(); 							// Create empty hufftree
	HTree::possible_path_t huff_path = huff_tree->path_to(symbol); 		// Find where the node that contains the letter we are encoding is
	
	bits_t bin_out; 							// Create our output variable
	
	auto path_index = huff_path->begin();					// set (or reset) our pointer to the top of the path
	
	for (int i = 0; i < (int)huff_path->size(); i++){ 			// Loop through the path to the node,
		if (*path_index == HTree::Direction::LEFT){ 			// figure out if it is left
			bin_out.push_back(false); 				// if so, add a 0 to bin_out
		}

		if (*path_index == HTree::Direction::RIGHT){ 			// Same as above, but with the right direction
			bin_out.push_back(true);
		}
		//printf("%s\n", bin_out.back() ? "true" : "false");

		std::advance(path_index, 1); 					// Move to the next direction in path
		
	}	
	freq_table[symbol]++; 							// Update freq table with the new count of a symbol
	return bin_out;
}
int Huffman::decode(bool bit){ 							// Function to decode

	if(!decode_ptr){ 							// Start with building/updating a tree and starting at the top
		build_huffman();
		decode_ptr = huff_tree;
	}

	if(bit) { 								// Go through the given directions, and move left or right
		decode_ptr = decode_ptr->get_child(HTree::Direction::RIGHT);
	}
	else {
		decode_ptr = decode_ptr->get_child(HTree::Direction::LEFT);
	}

	if(decode_ptr->get_key() <= 0){ 					// If we are at a placeholder node, restart
		return decode_ptr->get_key();
	}
	else{ 									// Otherwise, get the key (the symbol), update the table
		int letter = decode_ptr->get_key(); 				// Reset the decode pointer, and return the symbol we found
		freq_table[letter]++;
		decode_ptr = nullptr;
		return letter;
	}


}
Huffman::~Huffman(){

}
