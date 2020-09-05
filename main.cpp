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

int main(){

	/*encoding*/

	string input_address = "input.txt";
	string data;
	map<char, int> frequency;

	tie(frequency, data) = readData(input_address);

	map<char, string> codes = huffmanCode(frequency);

	vector<pair<char, int> > encodingData;
	map<char, string> canonicalCodes;

	tie(encodingData, canonicalCodes) = getCanonicalCodes(codes);

	string encoded_str = encode(data, canonicalCodes);

	string compressed_str = compress(encoded_str);

	writeData(compressed_str, "compressed.txt");

	//function to save the codes
	writeEncodingData(encodingData, "EncodingData.txt");

	/*decoding*/

	compressed_str = readCompressedFile("compressed.txt");

	//function to read codes
	encodingData = readEncodingData("EncodingData.txt");

	canonicalCodes = genCanonicalCodes(encodingData);

	string binary_file = uncompress(compressed_str);

	HuffmanNode *huffmanTree = buildTree(canonicalCodes);
	// printHuffmanTree(huffmanTree, "");

	string decoded_str = decode(huffmanTree, binary_file);

	//write uncompressed data
	writeData(decoded_str, "output.txt");

	return 0;
}



