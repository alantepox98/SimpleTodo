#include <iostream>
#include <string>
using namespace std;

class node{
	public:
		node* left;
		node* right;
		int data; 
};

class bst{
	private:
		node* root ; 
		void bstinsertPrivate(int key, node* ptr);\

	public:
		bst();
		void bstinsert(int key);
		int bstsearch(int key);
		
};

bst:: bst(){
	root = NULL;
	
}

void bst:: bstinsert(int key){
	bstinsertPrivate(key,root);
}

void bst:: bstinsertPrivate(int key, node* ptr){
	if(root==NULL){
		cout<< "Inserting root, "<<key<<endl;
		root= new node;
		root -> right = NULL;
		root -> left = NULL;
		root -> data = key;
	}
	else if(key < ptr -> data)	{
		if(ptr-> left != NULL){
			bstinsertPrivate(key, ptr -> left);
		}
		else{
			cout<< "inserting "<< key<< " as "<< ptr -> data <<"'s left child"<< endl;
			ptr -> left = new node;
			ptr -> left -> data = key;
			ptr -> left -> left = NULL;
			ptr -> left -> right = NULL;
		}
	}
	else if(key > ptr -> data)	{
		if(ptr-> right != NULL){
			bstinsertPrivate(key, ptr -> right);
		}
		else{
			cout<< "inserting "<< key<< " as "<< ptr -> data <<"'s right child"<< endl;
			ptr -> right = new node;
			ptr -> right -> data = key;
			ptr -> right -> left = NULL;
			ptr -> right -> right = NULL;
		}
	}
}

int bst:: bstsearch(int key){
	node*  ptr; 
	ptr = root;
	cout<< "Searching for "<< key<<"..."<<endl;
	while(ptr!= NULL){
		if(ptr -> data == key){
			cout<< key<< " was found!"<<endl;
			return key;
		}
		else if(key < ptr-> data){
			ptr = ptr -> left;
		}
		else{
			ptr = ptr -> right;
		}
	}
	cout<<key<<" was not found..."<<endl;
}



int main(){
	bst tree;
	
	cout<< endl;
	tree.bstinsert(8);
	tree.bstinsert(3);
	tree.bstinsert(10);
	tree.bstinsert(1);
	tree.bstinsert(6);
	tree.bstinsert(14);
	tree.bstinsert(4);
	tree.bstinsert(7);
	tree.bstinsert(13);

	cout<< endl;

	tree.bstsearch(14);
	tree.bstsearch(33);
	tree.bstsearch(23);
	tree.bstsearch(6);
	
	return 0;
}