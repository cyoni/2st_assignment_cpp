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

ariel::Node::Node(int d){
	data=d;
	left=right=NULL;
}
int ariel::Tree::size()
{
    return sizeofTree;
}

ariel::Tree& ariel::Tree::remove(int number)
{
	int isLeft=0;
	int found = contains(number);

	if (found==1){
	if (size()==1 && number == root()){
	delete head;
	head=NULL;
	sizeofTree--;
	return (*this);	
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

	return (*this);
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
	if (sizeofTree==0){
	       throw std::invalid_argument("check your input & tree");
	}

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

ariel::Tree& ariel::Tree::insert(int number)  
{
	int ok=0;
    if (sizeofTree==0){ 
	
	head = new Node(number);

        sizeofTree=1; 
    }
    else{
        Node *current = head;
	Node *parent=NULL;
	Node *tmp = new Node(number);
	
	while (current != NULL){

	parent=current;
	if (current->data == number){
	throw std::invalid_argument("The number is already exists");
	}
	if (current->data > number) current=current->left;
	else current=current->right;
	}
	
	if (ok==0){
	if (parent->data>number) parent->left=tmp;
	else parent->right=tmp;
	sizeofTree++;
	}
    } 
    return (*this);
}
