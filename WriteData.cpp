//takes in string to write and file address
void writeData(string v, string address){
	ofstream file(address);
	if(file.is_open()){
		file<<v;
		file.close();
	}
}

void writeEncodingData(vector< pair<char, int> >encodingData, string address){
	ofstream file(address);
	if(file.is_open()){
		vector< pair<char, int> >::iterator it;

		for(it = encodingData.begin();it!=encodingData.end();it++){
			file<<it->first<<it->second;
			file<<'|';
		}

		file.close();
	}
}