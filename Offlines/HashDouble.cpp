#include<bits/stdc++.h>
#define pb push_back
#define INF 1073741800

using namespace std;
class Hash_Double
{
    int n;
    vector < pair<string,int>  > vec;
    pair<string,int> dummy;

    int h1( string s)
    {
        unsigned long long int hashVal = 66437;
        for(int i=0; i<s.size(); i++)
        {
            hashVal =(((hashVal << 5) + hashVal) + s[i])%n;
        }
        return hashVal%n;
    }
    int h2(string s,int i)
    {
        unsigned long long int hashVal = 8921;
        for(int j=0; j<s.size(); j++)
        {
            hashVal =(((hashVal <<3) + hashVal) + s[j])%n;
        }
      int hash_value =(h1(s)+i*hashVal)%n;
        return hash_value%n;
    }
public:
    Hash_Double(int siz)
    {
        n=siz;
        vec.resize(siz);
        for(int i=0;i<n;i++){
            vec[i]=make_pair("NULL",-1);
        }
        dummy=make_pair("DUMMY",-1);
    }

    int searchDouble (string key)
    {
        int hash_index;
        for(int i=0; i<n; i++)
        {
            hash_index = h2(key,i) ;
            if(vec[hash_index].first==key)
                return i+1;
            if(vec[hash_index].first=="NULL")
                return -1;
        }
       // cout<<"not found"<<endl;
        return -1;
    }

    void insertDouble ( string key, int value)
    {
        int hash_index;
        for(int i=0; i<n*5; i++)
        {
            hash_index = h2(key,i) ;
            if(vec[hash_index].first=="NULL" || vec[hash_index].first=="DUMMY")
            {
                vec[hash_index]=make_pair(key,value);
                return;
            }
        }
        //cout<<"hash table overflow"<<endl;
    }

    void deleteDouble ( string key)
    {
        if (searchDouble(key) == -1)
        {
            //cout << "This key isn't present in hash table. Unable to delete" << endl;
            return;
        }
        else
        {
            int hash_index = searchDouble(key);
            vec[hash_index]=dummy;
        }
    }
};
