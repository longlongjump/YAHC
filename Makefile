


all: huffman

huffman: huffman_tree.o
	g++ -g -o huffman huffman.cpp huffman_tree.o

huffman_tree.o: huffman_tree.h huffman_tree.cpp
	g++ -c -g huffman_tree.cpp