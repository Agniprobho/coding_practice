#include <iostream>

using namespace std;

void strToNum(string A[], int sz)
{
    for (int i=0; i<sz; i++)
    {
        for (int j=0; j<A[i].size(); j++)
        {
            if (A[i][j]=='a' || A[i][j]=='b' || A[i][j]=='c')
                A[i][j]='2';
            else if (A[i][j]=='d' || A[i][j]=='e' || A[i][j]=='f')
                A[i][j]='3';
            else if (A[i][j]=='g' || A[i][j]=='h' || A[i][j]=='i')
                A[i][j]='4';
            else if (A[i][j]=='j' || A[i][j]=='k' || A[i][j]=='l')
                A[i][j]='5';
            else if (A[i][j]=='m' || A[i][j]=='n' || A[i][j]=='o')
                A[i][j]='6';
            else if (A[i][j]=='p' || A[i][j]=='q' || A[i][j]=='r' || A[i][j]=='s')
                A[i][j]='7';
            else if (A[i][j]=='t' || A[i][j]=='u' || A[i][j]=='v')
                A[i][j]='8';
            else if (A[i][j]=='w' || A[i][j]=='x' || A[i][j]=='y' || A[i][j]=='z')
                A[i][j]='9';
        }
    }
}

int main()
{
    int j, sz, check, check1;
	
	//input
    string A[] = {"foo", "bar", "baz", "foobar", "emo", "cap", "car", "cat"};
    string phone = {"3662277"};

    const size_t numElements = sizeof(A) / sizeof(A[0]);	//count number of strings in array
    sz = numElements;
    
    string B[sz];
    string A1[sz];
    copy(A, A + sz, A1);    //copy of string A
    
    strToNum(A, sz);
    int l = 0;
    
    for (int i=0; i<sz; i++)
    {
        check = phone.size()-A[i].size()+1;
        for (j=0; j<check; j++)
        {
            check1 =0;
            for (int k=0; k<A[i].size(); k++)
            {
                if (phone[j+k]==A[i][k])
                    check1 += 1;
            }
            if (check1==A[i].size())    //word is in phone number
                break;
        }
        if (check1 == A[i].size())
        {
            B[l] = A1[i];
            l++;
        }
    }
    
    for (int i=0; i<sz; i++)
        cout<<B[i]<<"\n";

    return 0;
}
