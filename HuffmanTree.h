class HuffmanNode{
public:
	char data;
	HuffmanNode *left;
	HuffmanNode *right;

	HuffmanNode(){
		data = '\0';
		left = right = NULL;
	}
};