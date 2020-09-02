string encode(string orig, map<char, string> const &codes){
	
	string encoded_str = "";

	for(int i=0;i<orig.size();i++){
		encoded_str+=codes.at(orig[i]);
	}

	return encoded_str;

}