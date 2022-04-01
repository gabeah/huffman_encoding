//Gabe Howland and Daniel Kryzhanovsky
//HW9 - Huffman encoding
//Much thanks to Tutor Aria for walking through most of the code here
#include "huffman.hh"
#include <iostream>
#include <algorithm> 

void new_huffman() {

	HForest::Hforest forest = HForest();
	for (int c=0, c<ALPHABET_SIZE; c++){
		forest.add_tree(c, freq_table[c],nullptr,nullptr)
	}
	while(forest.size()>1){
		HTree::tree_ptr_t smallest = pop_tree();
		HTree::tree_ptr_t sec_smallest = pop_tree();
	
		forest.add_tree(fake_key, 
			smallest->get_value()+sec_smallest->get_value(),
			smallest,
			sec_smallest);
		fake_key--;

	}
	huff_tree = pop_tree();
}

bits_t Huffman::encode(int symbol) {

	new_huffman;	
}



