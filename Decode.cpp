string decode(HuffmanNode *huffmanTree, string encoded_str){

	string decoded_str = "";
	HuffmanNode *root = huffmanTree;
	HuffmanNode *curr;

	char c;

	while(!encoded_str.empty()){
		curr = root;
		while(curr->data=='\0'){
			c = encoded_str[0];
			encoded_str = encoded_str.substr(1);
			if(c=='0') curr = curr->left;
			else curr = curr->right;
		}
		decoded_str+=curr->data;
	}

	return decoded_str;
}