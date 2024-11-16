#include<bits/stdc++.h>
#define pb push_back
#define INF 1073741800

using namespace std;

struct node
{
    int data;     	// Data
    node *prev;  	// A reference to the previous node
    node *next; 	// A reference to the next node
};

class Doubly_Linked_List
{
    node *frontNode;  	// points to first node of list
    node *endNode;   	// points to first las of list
public:
    Doubly_Linked_List()
    {
        frontNode = NULL;
        endNode = NULL;
    }
    void add_node(int );
    void delete_node(int);
    void traverse();
    node* search_key(int);
};

void Doubly_Linked_List :: add_node(int d)
{
    node *temp;
    temp = new node();
    temp->data = d;

    if(frontNode == NULL)
    {
        frontNode=temp;
        temp->prev = NULL;
        temp->next =NULL;
        endNode = temp;
    }
    else
    {
        temp->prev = endNode;
        temp->prev->next=temp;
        temp->next =NULL;
        endNode = temp;
    }
}

void Doubly_Linked_List :: delete_node(int m)
{
    node *n=NULL;
    n=search_key(m);
    cout<<"DFGDGD"<<endl;
    if(n==NULL){
        cout<<"No such item"<<endl;
    }
    // if node to be deleted is first node of list
    else if(n->prev == NULL)
    {
        frontNode = n->next; //the next node will be front of list
        frontNode->prev = NULL;
    }
    // if node to be deleted is last node of list
    else if(n->next == NULL)
    {
        endNode = n->prev;   // the previous node will be last of list
        endNode->next = NULL;
    }
    else
    {
        //previous node's next will point to current node's next
        n->prev->next = n->next;
        //next node's prev will point to current node's prev
        n->next->prev = n->prev;
    }
    //delete node
    delete(n);
}
node* Doubly_Linked_List :: search_key(int x)
{
	node *trav;
	trav = frontNode;
	while(trav != NULL)
	{
		if(trav->data==x)
            return trav;

        trav = trav->next;

	}
	return NULL;
}
void Doubly_Linked_List :: traverse()
{
	node *trav;
	trav = frontNode;
	while(trav != NULL)
	{
		cout<<trav->data<<endl;
		trav = trav->next;
	}
}
