#include<bits/stdc++.h>
#include "HashChaining.cpp"
#include "HashLineraProb.cpp"
#include "HashQuadreticprob.cpp"
#include "HashDouble.cpp"
#define INF 1073741800

using namespace std;

string word_generation( )
{
    string x;
    for(int i=0; i<7; i++)
    {
        x.push_back((rand()%26)+'a');
    }
    // cout<<x<<endl;
    return x;
}


int main()
{
    int n;
    cin>>n;
    int chainHash[6][2],linerProbHash[6][4],quadraticProbHash[6][4],doubleHash[6][4];
    for (int i=0; i<6; i++)
    {
        int  s=(.4+i*0.1)*n;
        set<string> st;
        while(s!=st.size())
        {
            st.insert(word_generation());
        }
        vector<string> vec= vector<string> (st.begin(),st.end());
        Hash_Chaining hC(n);
        Hash_Linear hL(n);
        Hash_Quadratic hQ(n);
        Hash_Double hD(n);

        for(int j=0; j<s; j++)
        {
            hC.insertChainHash(vec[j],j+1);
            hL.insertLinear(vec[j],j+1);
            hQ.insertQuadratic(vec[j],j+1);
            hD.insertDouble(vec[j],j+1);
        }
        int tenpercant=s*0.1;
        double time_hC=0;
        double time_hL=0;
        double time_hQ=0;
        double time_hD=0;
        int prob_hL=0;
        int prob_hQ=0;
        int prob_hD=0;
        //cout<<"SSGSRGERGERDG"<<endl;
        for(int j=0; j<tenpercant; j++)
        {
            auto start = chrono::high_resolution_clock::now();
            hC.searchChainHash(vec[rand()%s]);
            auto stop = chrono::high_resolution_clock::now();
            time_hC += (double)chrono::duration_cast<chrono::nanoseconds>(stop - start).count();
//cout<<"        1           "<<endl;
            start = chrono::high_resolution_clock::now();
            prob_hL+=hL.searchLinear(vec[rand()%s]);
            stop = chrono::high_resolution_clock::now();
            time_hL += (double)chrono::duration_cast<chrono::nanoseconds>(stop - start).count();

           // cout<<"       2222222           "<<endl;
            start = chrono::high_resolution_clock::now();
            prob_hQ+=hQ.searchQuadratic(vec[rand()%s]);
            stop = chrono::high_resolution_clock::now();
            time_hQ += (double)chrono::duration_cast<chrono::nanoseconds>(stop - start).count();


           // cout<<"        333333333333        "<<endl;

            start = chrono::high_resolution_clock::now();
            prob_hD+=hD.searchDouble(vec[rand()%s]);
            stop = chrono::high_resolution_clock::now();
            time_hD += (double)chrono::duration_cast<chrono::nanoseconds>(stop - start).count();
             // cout<<"       444444       "<<endl;
        }
        chainHash[i][0]=(1.0*time_hC)/tenpercant;

        linerProbHash[i][0]=(1.0*time_hL)/tenpercant;
        linerProbHash[i][1]=(1.0*prob_hL)/tenpercant;

        quadraticProbHash[i][0]=(1.0*time_hQ)/tenpercant;
        quadraticProbHash[i][1]=(1.0*prob_hQ)/tenpercant;

        doubleHash[i][0]=(1.0*time_hD)/tenpercant;
        doubleHash[i][1]=(1.0*prob_hD)/tenpercant;

        //cout<<"ttime   :   "<<time_hC<<endl;
        // cout<<"time   :   "<<time_hL<<endl;
        //cout<<"ttime   :   "<<time_hQ<<endl;
        // cout<<"time   :   "<<time_hD<<endl;

        for(int j=0; j<tenpercant; j++)
        {
            hC.deleteChainHash(vec[rand()%s]);
            hL.deleteLinear(vec[rand()%s]);
            hQ.deleteQuadratic(vec[rand()%s]);
            hD.deleteDouble(vec[rand()%s]);
        }
        time_hC=0;

        time_hL=0;
        prob_hL=0;

        time_hQ=0;
        prob_hQ=0;

        time_hD=0;
        prob_hD=0;

        for(int j=0; j<tenpercant; j++)
        {
            auto start = chrono::high_resolution_clock::now();
            hC.searchChainHash(vec[rand()%s]);
            auto stop = chrono::high_resolution_clock::now();
            time_hC += (double)chrono::duration_cast<chrono::nanoseconds>(stop - start).count();

            start = chrono::high_resolution_clock::now();
            prob_hL+=hL.searchLinear(vec[rand()%s]);
            stop = chrono::high_resolution_clock::now();
            time_hL += (double)chrono::duration_cast<chrono::nanoseconds>(stop - start).count();

            start = chrono::high_resolution_clock::now();
            prob_hQ+=hQ.searchQuadratic(vec[rand()%s]);
            stop = chrono::high_resolution_clock::now();
            time_hQ += (double)chrono::duration_cast<chrono::nanoseconds>(stop - start).count();

            start = chrono::high_resolution_clock::now();
            prob_hD+=hD.searchDouble(vec[rand()%s]);
            stop = chrono::high_resolution_clock::now();
            time_hD += (double)chrono::duration_cast<chrono::nanoseconds>(stop - start).count();
        }
        chainHash[i][1]=(1.0*time_hC)/tenpercant;

        linerProbHash[i][2]=(1.0*time_hL)/tenpercant;
        linerProbHash[i][3]=(1.0*prob_hL)/tenpercant;

        quadraticProbHash[i][2]=(1.0*time_hQ)/tenpercant;
        quadraticProbHash[i][3]=(1.0*prob_hQ)/tenpercant;

        doubleHash[i][2]=(1.0*time_hD)/tenpercant;
        doubleHash[i][3]=(1.0*prob_hD)/tenpercant;

        // cout<<"ttime   :   "<<time_hC<<endl;
        //cout<<"time   :   "<<time_hL<<endl;
        // cout<<"ttime   :   "<<time_hQ<<endl;
        // cout<<"time   :   "<<time_hD<<endl;
    }

    cout<<"Table 1 for Chaining :   before              after"<<endl;
    for(int i=0; i<6; i++)
    {
        cout<<" Load factor : "<<(.4+i*0.1)<<"             "<<chainHash[i][0]<<"              "<<chainHash[i][1]<<endl;
    }

    cout<<"Table 2 for Linear :   beforeAvgST      beforeAvgProb    afterAvgST       afterAvgProb"<<endl;
    for(int i=0; i<6; i++)
    {
        cout<<" Load factor : "<<(.4+i*0.1)<<"             "<<linerProbHash[i][0]<<"              "<<linerProbHash[i][1]<<"                  "<<linerProbHash[i][2]<<"               "<<linerProbHash[i][3]<<endl;
    }


    cout<<"Table 3 for Quadratic :   beforeAvgST      beforeAvgProb    afterAvgST       afterAvgProb"<<endl;
    for(int i=0; i<6; i++)
    {
        cout<<" Load factor : "<<(.4+i*0.1)<<"           "<<quadraticProbHash[i][0]<<"            "<<quadraticProbHash[i][1]<<"                  "<<quadraticProbHash[i][2]<<"               "<<quadraticProbHash[i][3]<<endl;
    }


    cout<<"Table 4 for Linear :   beforeAvgST      beforeAvgProb    afterAvgST       afterAvgProb"<<endl;
    for(int i=0; i<6; i++)
    {
        cout<<" Load factor : "<<(.4+i*0.1)<<"      "<<doubleHash[i][0]<<"              "<<doubleHash[i][1]<<"                  "<<doubleHash[i][2]<<"                    "<<doubleHash[i][3]<<endl;
    }
    for(int i=0; i<6; i++)
    {
        cout<<" Table  "<<i +4 <<"  for  "<<(.4+i*0.1)<<" load factor  " <<endl;
        cout<<"Separate    "<<chainHash[i][0]<<"         N/A                "<<chainHash[i][1]<<"        N/A   "<<endl;
        cout<<"Linear       "<<linerProbHash[i][0]<<"             "<<linerProbHash[i][1]<<"              "<<linerProbHash[i][2]<<"              "<<linerProbHash[i][3]<<endl;
        cout<<"Quardratic "<<quadraticProbHash[i][0]<<"            "<<quadraticProbHash[i][1]<<"            "<<quadraticProbHash[i][2]<<"                "<<quadraticProbHash[0][3]<<endl;
        cout<<"Double      "<<doubleHash[i][0]<<"          "<<doubleHash[i][1]<<"           "<<doubleHash[i][2]<<"             "<<doubleHash[i][3]<<endl;
    }





}

