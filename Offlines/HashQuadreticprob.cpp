#include<bits/stdc++.h>
#define pb push_back
#define INF 1073741800

using namespace std;
class Hash_Quadratic
{
    int n;
    int probCount;
    vector < pair<string,int>  > vec;
    pair<string,int> dummy;

    int h1( string s)
    {
        unsigned long long int hashVal = 66437;
        for(int i=0; i<s.size(); i++)
        {
            hashVal =(((hashVal << 7) + hashVal) + s[i])%n;
        }
        return hashVal%n;
    }
    int h2(string s,int i)
    {
        int hash_value =(h1(s)+i*56+46*i*i)%n;
        return hash_value%n;
    }
public:
    Hash_Quadratic(int siz)
    {
        n=siz;
        vec.resize(siz);
        for(int i=0;i<n;i++){
            vec[i]=make_pair("NULL",-1);
        }
        probCount=0;
        dummy=make_pair("DUMMY",-1);
    }

    int searchQuadratic (string key)
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
        //cout<<"not found"<<endl;
        return -1;
    }

    void insertQuadratic ( string key, int value)
    {
        int hash_index;
        for(int i=0; i<n; i++)
        {
            hash_index = h2(key,i) ;
            if(vec[hash_index].first=="NULL")
            {
                vec[hash_index]=make_pair(key,value);
                return;
            }
        }
        //cout<<"hash table overflow"<<endl;
    }

    void deleteQuadratic ( string key)
    {
        if (searchQuadratic(key) == -1)
        {
            //cout << "This key isn't present in hash table. Unable to delete" << endl;
            return;
        }
        else
        {
            int hash_index = searchQuadratic(key);
            vec[hash_index]=dummy;
        }
    }
};

