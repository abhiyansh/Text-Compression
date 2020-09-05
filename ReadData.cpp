
//Read file return the file as string and the frequency of each element.
tuple<map<char, int>, string> readData(string input_add){
	
	string data = "";

	fstream fin(input_add, fstream::in);

	map<char, int> frequency;

	char ch;

	while (fin >> noskipws >> ch) {
		data+=ch;
		frequency[ch]++;
	}

	return make_tuple(frequency, data);
}

string readCompressedFile(string input_add){
	string data = "";
	fstream fin(input_add, fstream::in);
	char ch;
	while (fin >> noskipws >> ch) data+=ch;
	
	return data;
}