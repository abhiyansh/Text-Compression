#include "bits/stdc++.h"
#include<fstream>


using namespace std;

//local files
#include "ReadData.cpp"
#include "MinHeap.h"
#include "HuffmanCode.cpp"
#include "Encode.cpp"
#include "HuffmanTree.h"
#include "BuildTree.cpp"
#include "Decode.cpp"
#include "Compress.cpp"
#include "Uncompress.cpp"
#include "WriteData.cpp"
// #include "PrintHuffmanTree.cpp"

int main(){

	/*encoding*/

	string input_address = "input.txt";
	string data;
	map<char, int> frequency;

	tie(frequency, data) = readData(input_address);

	map<char, string> codes = huffmanCode(frequency);

	string encoded_str = encode(data, codes);

	string compressed_str = compress(encoded_str);

	writeData(compressed_str, "compressed.txt");

	//function to save the codes

	/*decoding*/

	compressed_str = readCompressedFile("compressed.txt");
	//function to read codes

	string binary_file = uncompress(compressed_str);

	HuffmanNode *huffmanTree = buildTree(codes);
	// printHuffmanTree(huffmanTree, "");

	string decoded_str = decode(huffmanTree, binary_file);

	//function to output the decompressed file

	writeData(decoded_str, "output.txt");

	return 0;
}



