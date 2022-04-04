//Gabe Howland and Daniel Kryzhanovsky
//HW9 - Huffman encoding
//Much thanks to Tutor Aria for walking through most of the code here
#include "huffman.hh"
#include <iostream>
#include <algorithm> 
#include "hforest.hh"


Huffman::Huffman(){
	for(int i = 0; i <256; i++){
		freq_table.push_back(0);
	}
	freq_table.push_back(1);
	//std::vector<int> freq_table(257,0);	
	//freq_table[256] = 1;	
}

void Huffman::build_huffman() {

	HForest forest = HForest();
	for (int c=0; c<Huffman::ALPHABET_SIZE; c++){
		forest.add_tree(HTree::tree_ptr_t(new HTree(c, freq_table[c])));
		//forest.HForest::add_tree(tree);
	}
	while(forest.size()>1){
		HTree::tree_ptr_t smallest = forest.HForest::pop_top();
//		printf("key: %d\n", smallest->get_key());
//		printf("value: %ld\n", smallest->get_value());

		HTree::tree_ptr_t sec_smallest = forest.HForest::pop_top();
	
		 forest.add_tree(HTree::tree_ptr_t(new HTree(fake_key, 
			smallest->get_value()+sec_smallest->get_value(),
			smallest,
			sec_smallest)));
		//forest.HForest::add_tree(tree);
		fake_key--;

	}

	huff_tree = forest.HForest::pop_top();
}

Huffman::bits_t Huffman::encode(int symbol) {

	printf("%d\n", symbol);
	build_huffman();
	HTree::possible_path_t huff_path = huff_tree->path_to(symbol);
	bits_t bin_out;
	auto path_index = huff_path->begin();
	for (int i = 0; i < (int)huff_path->size(); i++){
		if (*path_index == HTree::Direction::LEFT){
			bin_out.push_back(false);
		}

		if (*path_index == HTree::Direction::RIGHT){
			bin_out.push_back(true);
		}
		//printf("%s\n", bin_out.back() ? "true" : "false");

		std::advance(path_index, 1);
		
	}	
	freq_table[symbol]++;
	return bin_out;
}
int Huffman::decode(bool bit){

	if(!decode_ptr){
		build_huffman();
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
Huffman::~Huffman(){

}
