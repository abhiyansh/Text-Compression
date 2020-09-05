
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

int str2int(string st){
	int n = 0;
	int temp;

	for(int i=0;i<st.length();i++){
		temp = (int)(st[i]-48);
		n*=10;
		n+=temp;
	}

	return n;
}

vector< pair<char, int> > readEncodingData(string address){
	
	vector< pair<char, int> > encodingData;
	string line;

	ifstream file(address);

	if(file.is_open()){
		while(getline(file, line, '|')){
			if(line.length())
				encodingData.push_back(make_pair(line[0], str2int(line.substr(1))));
		}
	}

	return encodingData;
}



