//takes in an arr of char and corresponding frequency, prints the code for each character

#include "bits/stdc++.h"

using namespace std;

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

void printCodes(MinHeapNode* root, string st){
	
	if(!root) return;

	if(root->c!='\0'){
		cout<<root->c<<": "<<st<<endl;
		return;
	}

	printCodes(root->left, st+"0");
	printCodes(root->right, st+"1");
}

void huffmanCode(char a[], int f[], int n){

	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

	for(int i=0;i<n;i++){
		minHeap.push(new MinHeapNode(f[i], a[i]));
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

	printCodes(minHeap.top(), "");

}


int main(){
	char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	int f[] = {5, 9, 12, 13, 16, 45};

	int n = sizeof(arr)/sizeof(arr[0]);

	huffmanCode(arr, f, n);

	return 0;
}






