class MinHeapNode{
public:
	int freq;
	char c;
	MinHeapNode* left;
	MinHeapNode* right;

	MinHeapNode(int freq, char c){
		this->freq = freq;
		this->c = c;
		left = right = NULL;
	}
};

class compare{
public:
	bool operator()(MinHeapNode* left, MinHeapNode* right){
		return left->freq > right->freq;
	}
};