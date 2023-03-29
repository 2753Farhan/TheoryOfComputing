//this code works for only the CGF given in example 5.4.5 of the Automata book.It is not generalized
#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter a string: \n";
    string input_string;
    cin>>input_string;

    bool contains_one = false;
    bool is_accepted = false;

    for(int i=0; i<input_string.size(); i++)
    {
        if(input_string[i]=='1')
            contains_one=true;
    }

    if(contains_one)
    {
        cout<<"The input string is accepted.\n";
        is_accepted=true;
    }
    else
    {
        cout<<"The input string is not accepted.\n"<<endl;
    }

    if(is_accepted)
    {
        string A, B;
        int i, j;

        for( i=0; i<input_string.size(); i++)
        {
            if(input_string[0]=='1')
                A="e";
            if(input_string[0]=='1')
            {
                B=input_string.substr(1,input_string.size()-1);
                break;
            }
            else if(input_string[i]=='1' && i != 0)
            {
                A=input_string.substr(0,i);
                j=i;
                B=input_string.substr(i+1,((input_string.size()-i-1)));
                break;
            }
        }

        cout<<"The leftmost derivation:\nS-->A1B-->";
        string temp_A, temp_B;
        temp_A.push_back('A');

        for(int i=0; i<A.size(); i++)
        {
            if(A[i]=='e')
                break;
            temp_A="0"+temp_A;
            cout << temp_A<<"1B"<<"-->";
        }

        temp_A.pop_back();
        cout << temp_A<<"1B"<<"-->";

        temp_B.push_back('B');

        for(int i=0; i<B.size(); i++)
        {
            if(B[i]=='0')
            {
                temp_B.pop_back();
                temp_B+="0B";
                cout<< temp_A<<"1"<<temp_B<<"-->";
            }
            else
            {
                temp_B.pop_back();
                temp_B+="1B";
                cout<< temp_A<<"1"<<temp_B<<"-->";
            }
        }

        temp_B.pop_back();
        cout << temp_A<<"1"<<temp_B<<"\n";
        //Rightmost derivation part:

        cout<<"The rightmost derivation:\nS-->A1B-->";
        string temp_1, temp_2;

        temp_2.push_back('B');
        //if(B.size()==0);

        for(int i=0; i<B.size(); i++)
        {
            if(B[i]=='0')
            {
                temp_2.pop_back();
                temp_2+="0B";
                cout<< "A1"<<temp_2<<"-->";
            }
            else
            {
                temp_2.pop_back();
                temp_2+="1B";
                cout<< "A1"<<temp_2<<"-->";
            }
        }

        temp_2.pop_back();
        temp_1.push_back('A');
        cout << temp_1<<"1"<<temp_2<<"-->";


        for(int i=0; i<A.size(); i++)
        {
            if(A[i]=='e')
                break;
            temp_1="0"+temp_1;
            cout << temp_1<<"1"<<temp_2<<"-->";
        }

        temp_1.pop_back();
        cout <<temp_1<<"1"<<temp_2;

    }
}

