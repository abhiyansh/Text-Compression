//build huffman tree from table of codes



HuffmanNode* buildTree(map<char, string> const &codes){
	
	map<char, string>::const_iterator it;
	
	HuffmanNode *root = new	HuffmanNode();
	HuffmanNode *curr;
	
	string st;
	char c;

	for(it = codes.begin();it!=codes.end();it++){
		curr = root;
		st = it->second;
		
		while(!st.empty()){
			char c = st[0];
			st = st.substr(1);
			if(c == '0'){
				if(curr->left==NULL)
					curr->left = new HuffmanNode();
				curr = curr->left;
			}else{
				if(curr->right==NULL)
					curr->right = new HuffmanNode();
				curr = curr->right;
			}
		}

		curr->data = it->first;
		// cout<<curr->data<<endl;
	}
	return root;
}





