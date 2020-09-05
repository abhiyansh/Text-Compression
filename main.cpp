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
#include "CanonicalCode.cpp"
// #include "PrintHuffmanTree.cpp"

int main(int argc, char** argv){

	//mode, read, write addresses
	string mode = argv[1];
	string input_address = argv[2];
	string output_address = argv[3];


	/*encoding*/
	if(mode=="-c"){

		string data;
		map<char, int> frequency;

		//read input data and calculate frequency of each character
		tie(frequency, data) = readData(input_address);
		//generate huffman codes for each character
		map<char, string> codes = huffmanCode(frequency);

		//encoding data stores the length of huffman code for each character
		vector<pair<char, int> > encodingData;
		//stores the canonical huffman codes of each char
		map<char, string> canonicalCodes;

		//converts the huffman codes to canonical 
		tie(encodingData, canonicalCodes) = getCanonicalCodes(codes);

		//encodes the original data using the canonical codes
		string encoded_str = encode(data, canonicalCodes);

		//converts the encoded data into bytes and stores them as a string
		string compressed_str = compress(encoded_str);

		//writes the compressed string
		writeData(compressed_str, output_address);

		//writes the encoding information
		writeEncodingData(encodingData, "EncodingData.txt");

	}

	/*decoding*/
	else if(mode=="-u"){
		//reads the compressed file
		string compressed_str = readCompressedFile(input_address);

		//reads the encoding information
		vector<pair<char, int> > encodingData = readEncodingData("EncodingData.txt");

		//generates the canonical codes using the encoding information
		map<char, string> canonicalCodes = genCanonicalCodes(encodingData);

		//generates string of binary encoded information from the compressed file
		string binary_file = uncompress(compressed_str);

		//builds the huffman tree from canonical codes to efficiently decode info
		HuffmanNode *huffmanTree = buildTree(canonicalCodes);
		// printHuffmanTree(huffmanTree, "");

		//decodes the string of binaries to obtain the original uncompressed data
		string decoded_str = decode(huffmanTree, binary_file);

		//write uncompressed data
		writeData(decoded_str, output_address);
	}

	else{
		cout<<"invalid mode"<<endl;
	}

	return 0;
}