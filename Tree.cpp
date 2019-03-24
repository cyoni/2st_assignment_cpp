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
	
	
}

bool ariel::Tree::contains(int number)
{
        Node *current = head;
	Node *parent=NULL;

	while (current != NULL){

	parent=current;
	if (current->data == number){
	return true;
	break;
	}

	if (current->data > number) current=current->left;
	else current=current->right;
	}
  	return false;
}

int ariel::Tree::root()
{

return head->data;
}

int ariel::Tree::parent(int i)
{

   int found = contains(i);

    if (found == 0 || head->data == i){
       throw std::invalid_argument("check your input & tree");
    } 


  	Node *current = head;
	Node *parent=NULL;
	
	while (current != NULL){

	
	if (current->data == i){
	break;
	}

	parent=current;
	if (current->data > i) current=current->left;
	else current=current->right;
	}
	
    return parent->data;
}


int ariel::Tree::left(int i)
{
  int found = contains(i);

    if (found == 0){
   throw std::invalid_argument("The number does not exist");
	return 0;
    }

  	Node *current = head;
	Node *parent=NULL;
	
	while (current != NULL){

	
	if (current->data == i){
	break;
	}

	parent=current;
	if (current->data > i) current=current->left;
	else current=current->right;
	}
	
	if (current->left == NULL){
       throw std::invalid_argument("no left son");
	
	}
    return current->left->data;
}

int ariel::Tree::right(int i)
{
 int found = contains(i);

    if (found == 0){
       throw std::invalid_argument("The number does not exist");
    }

  	Node *current = head;
	Node *parent=NULL;
	
	while (current != NULL){

	
	if (current->data == i){
	break;
	}

	parent=current;
	if (current->data > i) current=current->left;
	else current=current->right;
	}
	
	if (current->right == NULL){
       throw std::invalid_argument("No right son");

	}
    return current->right->data;
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
