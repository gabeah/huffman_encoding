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

	new_huffman();
	path_t huff_path = path_to(huff_tree);
	bits_t bin_out;
	for (int i = 0; i <= huff_path.size(); i++){
		if (huff_path[i] == Direction::LEFT){
			bin_out.(bool FALSE);
		}
		
		if (huff_path[i] == Direction::RIGHT){
			bin_out.push_back(bool TRUE);
		}
		
	}	
	freq_table[symbol]++;
	return bin_out;
}
int Huffman::decode(bool bit){

	new_huffman();
	for (int j = 0; j <= bin_out.size(); j++){
		
	}
}

