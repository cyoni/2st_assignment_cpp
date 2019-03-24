#include <iostream>
#include <mutex>
#include <thread>
#include <mutex>


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
        int sizeofTree=0;
        int size();
        Tree& remove(int n);
        bool contains(int n);
        int root();
        int parent(int i);
        int left(int i);
        int right(int i);
        void print();
	void print(Node *head);
        Tree& insert(int n);

    };
}
