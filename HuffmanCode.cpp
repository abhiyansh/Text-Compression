//takes in an frequency map, returns code for each char

void getCodes(MinHeapNode* root, string st, map<char, string> &codes){
	if(!root) return;

	if(root->c!='\0'){
		codes.insert(make_pair(root->c, st));
		return;
	}

	getCodes(root->left, st+"0", codes);
	getCodes(root->right, st+"1", codes);
}

map<char, string> huffmanCode(map<char, int> const &frequency){

	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

	map<char, int>::const_iterator it;

	for(it = frequency.begin();it != frequency.end();it++){
		minHeap.push(new MinHeapNode(it->second, it->first));
	}

	while(minHeap.size()!=1){

		MinHeapNode* a = minHeap.top();
		minHeap.pop();
		MinHeapNode* b = minHeap.top();
		minHeap.pop();
		MinHeapNode* c = new MinHeapNode(a->freq+b->freq, '\0');
		c->left = a;
		c->right = b;
		minHeap.push(c);
		
	}

	map<char, string> codes;

	getCodes(minHeap.top(), "", codes);

	return codes;

}







