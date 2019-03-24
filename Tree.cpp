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

}

void ariel::Tree::print(Node *current)
{

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
