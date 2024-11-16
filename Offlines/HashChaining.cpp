#include<bits/stdc++.h>
#include "dublyLL.h"
#define pb push_back
#define INF 1073741800

using namespace std;
class Hash_Chaining
{
    int n;
    vector <Doubly_Linked_List* > vec;
    int h1( string s)
    {
        unsigned long long int hashVal = 5381;
        for(int i=0; i<s.size(); i++)
        {
            hashVal = ((hashVal << 5) + hashVal) + s[i];
        }
        return hashVal%n;
    }

public:
    Hash_Chaining(int siz)
    {
        n=siz;
        vec.resize(siz);
    }

    node* searchChainHash (string key)
    {
        int hash_index = h1(key) ;
        Doubly_Linked_List* temp=vec[hash_index];
        if(temp==NULL)
            return NULL;
        node* res=temp->search_key(key);
        if(res==NULL)
            return NULL;
        return res;
    }

    void insertChainHash ( string key, int value)
    {
        int hash_index = h1(key) ;
        if(vec[hash_index]==NULL)
        {
            Doubly_Linked_List* d=new Doubly_Linked_List();
            vec[hash_index]=d;
        }
        vec[hash_index]->add_node(make_pair(key,value));
    }

    void deleteChainHash ( string key)
    {
        if (searchChainHash(key) == NULL)
        {
           // cout << "This key isn't present in hash table. Unable to delete" << endl;
        }
        else
        {
            int hash_index = h1(key);
            vec[hash_index]->delete_node(key);
        }
    }
};

