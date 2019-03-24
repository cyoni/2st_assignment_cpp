#include <iostream>
#include "Tree.hpp"

using namespace std;
using namespace ariel;

ariel::Tree::Tree(){
head=NULL;
sizeofTree=0;
}

ariel::Node::~Node(void){}
ariel::Tree::~Tree(void){}

int ariel::Tree::size()
{

    return sizeofTree;
}

void ariel::Tree::remove(int number)
{

	if (sizeofTree==0){

		throw std::invalid_argument("Tree is empty");
		
	}
	int isLeft=0;
	int found = contains(number);

	if (found==1){
	if (size()==1 && number == root()){
	delete head;
	head=NULL;
	sizeofTree--;
	return;
	}

        Node *current = head;
	Node *parent=head;

	while (current->data!=number){
	parent=current;

	if (current->data > number) {current=current->left;isLeft=0;}
	else {current=current->right; isLeft=1;}
	}

	// 1. leaf

	if (current->left == NULL  && current->right == NULL){

	delete current;
	if (isLeft == 0) parent->left=NULL;
	else parent->right=NULL;

	}
	// 3. the deleted node has two children
	else if (current->left != NULL && current->right != NULL) {
///////////////////////////////////

	Node *succ = current;
	Node *succparent = current;
	Node *del=current;

	current = current->right;
	while (current != NULL){
	succparent=succ;
	succ=current;
	current=current->left;
	
	}
	if (succ!=del->right){
	succparent->left=succ->right;
	succ->right=del->right;
	}

	current=del;
	if (current==head) head=succ;
	else if(isLeft==0) parent->left=succ;
	else parent->right=succ;
	succ->left=current->left;
	

//////////////////////////////////
	}
	else{ // 2. it has only one child
	
	if (current->right == NULL){
	if (current == head) head= current->left;
	else {if (isLeft==0) parent->left=current->left;
	else parent->right=current->left;}}
	
	else{ if (current->left == NULL){
	if (current == head) {head= current->right;}
	else {if (isLeft==0) parent->left=current->right;
	else {parent->right=current->right;}	}
	} }

	
	}

	sizeofTree--;
	} 
	else{
	throw std::invalid_argument("The number you are trying to remove does not exist");
	}

	
}

bool ariel::Tree::contains(int number)
{
      return false;
}

int ariel::Tree::root()
{

return head->data;
}

int ariel::Tree::parent(int i)
{

    return NULL;
}


int ariel::Tree::left(int i)
{
  
    return NULL;
}

int ariel::Tree::right(int i)
{
 
    return NULL;
}

void ariel::Tree::print()
{
cout << "this tree is: (inorder)" << endl;
ariel::Tree::print(head);
}

void ariel::Tree::print(Node *current)
{
 if (current==NULL) return;
 cout << current->data << endl;
 print(current->left);
 print(current->right);

}


Node* ariel::Tree::newNode(int key){
Node *node=new Node(key);
return node;
}

void ariel::Tree::insert(Node *&root, int key){
if (root==NULL){
root=newNode(key);
sizeofTree++;
return;
}
if (key < root->data) insert(root->left, key);
else insert(root->right, key);
}


ariel::Tree& ariel::Tree::insert(int number)  
{
    if (contains(number)==1){throw std::invalid_argument("The number already in the tree");}

    insert(head, number);
    return (*this);
}
