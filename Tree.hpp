#include <iostream>


using namespace std;

namespace ariel
{

    class Node{
	public:
	 ~Node();
	Node *left;
	Node *right;
	int data;
	Node(int d){
	data=d;
	left=right=NULL;
	}
	};

    class Tree{
        
        public:
	
        Node *head;
	Tree();
	~Tree();
        int sizeofTree;
        int size();
        void remove(int);
        bool contains(int);
        int root();
        int parent(int);
        int left(int);
        int right(int);
        void print();
	void print(Node *head);
        Tree& insert(int);
	void insert(Node*&,int);
	Node* newNode(int);
    };
}
