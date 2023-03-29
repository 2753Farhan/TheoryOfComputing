#include<bits/stdc++.h>
using namespace std;

vector<string> cha;

int Search(string val){
    int i, ind = -1;
    for(i=0;i<cha.size();i++){
        if(cha[i]==val){
            ind=i;
            break;
        }
    }
    return ind;
}

vector<string> epsilon;


int main(){
    int n;
    cout << "How many states are there? \n";
    cin >> n;
    cout <<"Please enter the states:\n";
    for(int i=0;i<n;i++){
        string c;
        cin >> c;
        cha.push_back(c);
    }

    char dfa[n][2][10];
    for(int i=0;i<n;i++){
        cout << "("<<cha[i]<<",0)=?\n";
        cin >> dfa[i][0];
        cout << "("<<cha[i]<<",1)=?\n";
        cin >> dfa[i][1];
    }

    printf("Printing the transition table:\n");
    printf("# 0 1\n");
    for(int i=0;i<n;i++)
    {
        cout << cha[i] << " ";
        for(int j=0;j<2;j++)
        {
            if(dfa[i][j]=="N")
                printf("N ");
            else
                cout << dfa[i][j]<<" ";
        }
        printf("\n");
    }

    vector<string> finalStates;
    cout << "please enter the final states: press 'S' to stop\n";
    while(1){
        string s;
        cin >> s;
        if(s=="S")break;
        else{
            finalStates.push_back(s);
        }
    }


    bool table[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            table[i][j]=true;
        }
    }


    for(int i=0.;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if((find(finalStates.begin(),finalStates.end(),cha[i])!=finalStates.end()&&find(finalStates.begin(),finalStates.end(),cha[j])!=finalStates.end())||(find(finalStates.begin(),finalStates.end(),cha[i])==finalStates.end()&&find(finalStates.begin(),finalStates.end(),cha[j])==finalStates.end())){
                //cout << "DAfdsf";
                table[j][i]=false;
            }
        }
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(!table[i][j]){
                //cout << i << "  "<< j << "\n";
                int k,l,m,n;
                if(Search(dfa[i][0])>Search(dfa[j][0])){
                    k=Search(dfa[i][0]);
                    l=Search(dfa[j][0]);
                }
                else{
                    k=Search(dfa[j][0]);
                    l=Search(dfa[i][0]);
                }
                if(Search(dfa[i][1])>Search(dfa[j][1])){
                    m=Search(dfa[i][1]);
                    n=Search(dfa[j][1]);
                }
                else{
                    m=Search(dfa[j][1]);
                    n=Search(dfa[i][1]);
                }
               // cout << k << " "<<l << " "<< m << " "<< n<<"\n";
                if(k==l||m==n)continue;
                if(table[k][l]||table[m][n]){
                    table[i][j]=true;
                }
            }
        }
        //cout << "\n";
    }
    cout << "Minimization table : \n";
    for(int i=1;i<n;i++){
        cout << cha[i] <<" ";
        for(int j=0;j<i;j++){
            if(table[i][j]){
                cout << "x ";
            }
            else cout << "+ ";
        }
        cout << "\n";
    }
    cout << "  ";
    for(int i=0;i<n-1;i++) cout << cha[i] << " ";
    cout << "\n";
    cout << "Equivalent states are: \n";
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(!table[i][j]){
                cout << "{"<<cha[i]<<","<<cha[j]<<"}\n";
            }
        }
        //cout << "\n";
    }
}





