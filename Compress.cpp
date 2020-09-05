//takes in a string of binaries and converts it into an array of unsigned char 

//range(0-7)
string toBinary(int x){
	string st = "";
	for(int i=0;i<3;i++){
		if(x&1) st = '1'+st;
		else st = '0'+st;
		x = x>>1;
	}
	return st;
}

string compress(string st){
	
	//making input string length multiple of 8

	//number of 0s appended in the end
	int padding = (8 - (st.length() + 3) % 8) % 8;
	string prefix = toBinary(padding);
	st = prefix+st;

	for(int i=0;i<padding;i++) st+='0';

	int n = st.length();

	string output_str = "";

	unsigned char byte;

	for(int j=0;j<(n/8);j++){
		byte = 0;
		for( int i = 0; i < 8; ++i ) if( st[(j*8)+i] == '1' ) byte |= 1 << (7-i);
		output_str+=(byte);
	}

	return output_str;
}