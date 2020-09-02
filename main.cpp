#include "bits/stdc++.h"
#include<fstream>


using namespace std;

//local files
#include "ReadData.cpp"
#include "MinHeap.h"
#include "HuffmanCode.cpp"
#include "Encode.cpp"

int main(){

	string input_address = "input.txt";
	string data;
	map<char, int> frequency;

	tie(frequency, data) = readData(input_address);

	map<char, string> codes = huffmanCode(frequency);

	string encoded_str = encode(data, codes);

	cout<<encoded_str<<endl;

	return 0;
}