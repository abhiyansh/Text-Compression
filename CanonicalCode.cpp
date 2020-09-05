bool compareCodeLen(pair<string, char> p1, pair<string, char> p2){
	return p1.first.length() < p2.first.length();
}

string incrementBinary(string bin){
	for(int i=bin.length()-1;i>=0;i--){
		if(bin[i]=='0'){
			bin[i]='1';
			return bin;
		}
		else 
			bin[i]='0';
	}
	bin = '1'+bin;
	return bin;
}

tuple< vector< pair<char, int> >, map<char, string> > getCanonicalCodes(map<char, string> codes){
	
	vector<pair<string, char> > v;
	map<char, string>::iterator it;
	for(it = codes.begin(); it!=codes.end(); it++){
		v.push_back(make_pair(it->second, it->first));
	}
	sort(v.begin(), v.end(), compareCodeLen);

	vector< pair<char, int> > codeLen;
	map<char, string> canonicalCodes;
	
	vector<pair<string, char> >::iterator it_2 = v.begin();

	int len = v.at(0).first.length();
	codeLen.push_back(make_pair(v.at(0).second, len));

	string st = "";

	while(len--) st+='0';

	canonicalCodes[v.at(0).second] = st;

	it_2++;

	for( ;it_2!=v.end();it_2++){
		len = it_2->first.length();
		codeLen.push_back(make_pair(it_2->second, len));
		st = incrementBinary(st);
		if(st.length()!=len){
			while(st.length()<len) st+='0';
		}
		canonicalCodes[it_2->second] = st;
	}

	return make_tuple(codeLen, canonicalCodes);
}

map<char, string> genCanonicalCodes(vector< pair<char, int> > codeLen){
	map<char, string> canonicalCodes;

	vector< pair<char, int> >::iterator it = codeLen.begin();

	int len = it->second;

	string st = "";

	while(len--) st+='0';

	canonicalCodes[it->first] = st;

	it++;

	for( ;it!=codeLen.end();it++){
		len = it->second;
		st = incrementBinary(st);
		if(st.length()!=len){
			while(st.length()<len) st+='0';
		}
		canonicalCodes[it->first] = st;
	}

	return canonicalCodes;
}