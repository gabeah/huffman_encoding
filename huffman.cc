//Gabe Howland and Daniel Kryzhanovsky
//HW9 - Huffman encoding
//Much thanks to Tutor Aria for walking through most of the code here
#include "huffman.hh"
#include <iostream>
#include <algorithm> 


Huffman::Huffman(){
	freq_table(257,0);	
	freq_table[256] = 1;	
}

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
	path_t huff_path = huff_tree->path_to(symbol);
	bits_t bin_out;
	for (int i = 0; i <= huff_path.size(); i++){
		if (huff_path[i] == HTree::Direction::LEFT){
			bin_out.push_back(false);
		}
		
		if (huff_path[i] == HTree::Direction::RIGHT){
			bin_out.push_back(true);
		}
		
	}	
	freq_table[symbol]++;
	return bin_out;
}
int Huffman::decode(bool bit){

	if(!decode_ptr){
		new_huffman();
		decode_ptr = huff_tree;
	}

	if(bit) {
		decode_ptr = decode_ptr->get_child(HTree::Direction::RIGHT);
	}
	else {
		decode_ptr = decode_ptr->get_child(HTree::Direction::LEFT);
	}

	if(decode_ptr->get_key() < 0){
		return decode_ptr->get_key();
	}
	else{
		int letter = decode_ptr->get_key();
		freq_table[letter]++;
		decode_ptr = nullptr;
		return letter;
	}


}

