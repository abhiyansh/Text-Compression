//takes in a compressed string and converts it into string of binaries


//range(0-7)
int toInt(string st){

	int x = 0;

	for(int i=0;i<3;i++){
		if(st[i]=='1') x+=pow(2, 2-i);
	}
	return x;
}


string uncompress(string compressed_file){
	string bin = "";

	string temp;

	for(int i=0;i<compressed_file.length();i++){
		temp = "";
		for(int j=0;j<8;j++){
			if((compressed_file[i]>>j) & 1) temp = '1'+temp;
			else temp = '0'+temp;
		}

		bin += temp;
	}

	temp = bin.substr(0, 3);


	int padding = toInt(temp);


	int file_len = bin.length()-3-padding;

	bin = bin.substr(3, file_len);

	return bin;

}