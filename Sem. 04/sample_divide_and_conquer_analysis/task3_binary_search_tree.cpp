//Binary Tree
struct Node
{
	Node(int k)
	{
		
		key = k;
		left = nullptr;
		right = nullptr;
	}
	int key;
	Node* left;
	Node* right;
};

Node* findNodeInBST(Node* st, int key)
{
	if (st == nullptr)
		return nullptr;
	
	if (st->key == key)
		return st;
    
	if (st->key > key)
		return findNodeInBST(st->left, key);
	
	if (st->key < key)
		return findNodeInBST(st->right, key);
};