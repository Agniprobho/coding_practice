#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <string> fTS;

string InToStr(int a)
{
    string str, str1;
    
    str = to_string(a);
    
    for (int i=0; i<str.size()-2; i++)
    {
        str1 += str[i];
    }
    str1 += ':';
    for (int i=str.size()-2; i<str.size(); i++)
    {
        str1 += str[i];
    }
    return str1;
}

int strToIn(string a)
{
    int b;
    string str;
    
    for (int i=0; i<a.size(); i++)
    {
        if (a[i]!=':')
        {
            str += a[i];
        }
    }
    
    b = stoi(str);
    return b;
}

void freeTime(string c1[][2], string c2[][2], int n1, int n2, string b1[], string b2[])
{
    vector <int> f1, f2;
    
    //free time for calendar 1
    if (c1[0][0] != b1[0])
    {
        f1.push_back(strToIn(b1[0]));
        f1.push_back(strToIn(c1[0][0]));
    }
    for (int i=0; i<n1-1; i++)
    {
        if (c1[i][1] != c1[i+1][0]) //free time slots
        {
            f1.push_back(strToIn(c1[i][1]));
            f1.push_back(strToIn(c1[i+1][0]));
        }
    }
    if (c1[n1-1][1] != b1[1])
    {
        f1.push_back(strToIn(c1[n1-1][1]));
        f1.push_back(strToIn(b1[1]));
    }
        
    //free time for calendar 2
    if (c2[0][0] != b2[0])
    {
        f2.push_back(strToIn(b2[0]));
        f2.push_back(strToIn(c2[0][0]));
    }
    for (int i=0; i<n2-1; i++)
    {
        if (c2[i][1] != c2[i+1][0]) //free time slots
        {
            f2.push_back(strToIn(c2[i][1]));
            f2.push_back(strToIn(c2[i+1][0]));
        }
    }
    if (c2[n2-1][1] != b2[1])
    {
        f2.push_back(strToIn(c2[n2-1][1]));
        f2.push_back(strToIn(b2[1]));
    }
    
    for (int i=0; i<f1.size()/2; i++)   //time slots
    {
        for (int j=0; j<f2.size()/2; j++)   //time slots
        {
            //(a,b), (c,d)
            //1. a>=c and b>=d and a<d: (a,d)
            //2. a>=c and b<=d and a<b: (a,b)
            //3. a<=c and b<=d and c<b: (c,b)
            //4. a<=c and b>=d and c<d: (c,d)
            if (f1.at(2*i)>=f2.at(2*j) && f1.at(2*i+1)>=f2.at(2*j+1) && f1.at(2*i)<f2.at(2*j+1))
            {
                fTS.push_back(InToStr(f1.at(2*i)));
                fTS.push_back(InToStr(f2.at(2*j+1)));
            }
            else if (f1.at(2*i)>=f2.at(2*j) && f1.at(2*i+1)<=f2.at(2*j+1) && f1.at(2*i)<f1.at(2*i+1))
            {
                fTS.push_back(InToStr(f1.at(2*i)));
                fTS.push_back(InToStr(f1.at(2*i+1)));
            }
            else if (f1.at(2*i)<=f2.at(2*j) && f1.at(2*i+1)<=f2.at(2*j+1) && f2.at(2*j)<f1.at(2*i+1))
            {
                fTS.push_back(InToStr(f2.at(2*j)));
                fTS.push_back(InToStr(f1.at(2*i+1)));
            }
            else if (f1.at(2*i)<=f2.at(2*j) && f1.at(2*i+1)>=f2.at(2*j+1) && f2.at(2*j)<f2.at(2*j+1))
            {
                fTS.push_back(InToStr(f2.at(2*j)));
                fTS.push_back(InToStr(f2.at(2*j+1)));
            }
        }
    }
    
    f1.clear();
    f2.clear();
}

int main()
{
    string Calendar1[][2]  = {{"9:00","10:30"},{"12:00","13:00"},{"16:00","18:00"}};
    string bound1[] = {"9:00","20:00"};
    string Calendar2[][2]  = {{"10:00","11:30"},{"12:30","14:30"},{"14:30","15:00"},{"16:00","17:00"}};
    string bound2[] = {"10:00","18:30"};
    
    const size_t numElements1 = sizeof(Calendar1) / sizeof(Calendar1[0]);	//count number of strings in array
    const size_t numElements2 = sizeof(Calendar2) / sizeof(Calendar2[0]);	//count number of strings in array
    
    freeTime(Calendar1, Calendar2, numElements1, numElements2, bound1, bound2);
    
    cout<<"[";
    for (int i=0; i<fTS.size()/2; i++)
    {
        cout<<"['"<<fTS.at(2*i)<<"','"<<fTS.at(2*i+1)<<"'],";
    }
    cout<<"]";

    return 0;
}
