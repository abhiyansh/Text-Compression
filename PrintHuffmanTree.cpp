void printHuffmanTree(HuffmanNode *root, string st){
	if(!root) return;

	if(root->data!='\0'){
		cout<<root->data<<": "<<st<<endl;
		return;
	}

	printHuffmanTree(root->left, st+"0");
	printHuffmanTree(root->right, st+"1");
}