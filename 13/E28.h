#ifndef E28_H
#define E28_H

#include <string>
using std::string;

class TreeNode{
public:
	TreeNode():value(string()), count(new int(1)), left(nullptr), right(nullptr) {}
	TreeNode(const TreeNode&);
	TreeNode& operator=(const TreeNode&);
	~TreeNode();
private:
	string value;
	int* count;
	TreeNode* left;
	TreeNode* right;
};

class BinStrTree {
public:
	BinStrTree():root(new TreeNode()) {}
	BinStrTree(const BinStrTree& bt):root(new TreeNode(*bt.root)) {}
	BinStrTree& operator=(const BinStrTree&);
	~BinStrTree();
private:
	TreeNode* root;
};

TreeNode::TreeNode(const TreeNode& tr){
	value = tr.value;
	++*count;
	left = tr.left;
	right = tr.right;
}

TreeNode& TreeNode::operator=(const TreeNode& tn){
	++*tn.count;
	if(--*count == 0){
		delete count;
		delete left;
		delete right;
	}
	count = tn.count;
	value = tn.value;
	left = tn.left;
	right = tn.right;

	return *this;
}

TreeNode::~TreeNode(){
	if(--*count == 0){
		if(left){
			delete left;
			left = nullptr;
		}
		if(right){
			delete right;
			right = nullptr;
		}
		delete count;
		count = nullptr;
	}
}

BinStrTree& BinStrTree::operator=(const BinStrTree& bt){
	// root = bt.root;
	TreeNode* new_root = new TreeNode(*bt.root);
	delete root;
	root = new_root;
	return *this;
}

BinStrTree::~BinStrTree(){
	delete root;
}

#endif