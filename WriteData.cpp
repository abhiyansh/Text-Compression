//takes in string to write and file address
void writeData(string v, string address){
	ofstream file(address);
	if(file.is_open()){
		file<<v;
		file.close();
	}
}