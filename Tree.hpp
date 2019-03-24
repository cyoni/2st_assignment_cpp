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
	Node(int);
	};

    class Tree{
        
        public:
	
        Node *head;
	Tree();
	~Tree();
        int sizeofTree;
        int size();
        Tree& remove(int);
        bool contains(int);
        int root();
        int parent(int i);
        int left(int i);
        int right(int i);
        void print();
	void print(Node *head);
        Tree& insert(int n);
    };
}
