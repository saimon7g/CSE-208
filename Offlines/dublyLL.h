#include<bits/stdc++.h>
#define pb push_back
#define INF 1073741800

using namespace std;

class node
{public:
    pair<string,int> data;
    node *prev;
    node *next;
};

class Doubly_Linked_List
{
    node *frontNode;
    node *endNode;
public:
    Doubly_Linked_List()
    {
        frontNode = NULL;
        endNode = NULL;
    }
    void add_node(pair<string,int> );
    void delete_node(string);
    void traverse();
    node* search_key(string);
};

void Doubly_Linked_List :: add_node(pair<string,int> d)
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

void Doubly_Linked_List :: delete_node(string m)
{
    node *n=NULL;
    n=search_key(m);
    if(n==NULL){
        //cout<<"No such item"<<endl;
    }
    else if(n->prev == NULL)
    {
        frontNode = n->next;
    }
    else if(n->next == NULL)
    {
        endNode = n->prev;
        endNode->next = NULL;
    }
    else
    {
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }
    delete(n);
}
node* Doubly_Linked_List :: search_key(string x)
{
	node *trav;
	trav = frontNode;
	while(trav != NULL)
	{
		if(trav->data.first==x)
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
		//cout<< trav->data.first <<endl;
		trav = trav->next;
	}
}
