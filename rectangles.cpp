#include <iostream>

using namespace std;

int rectangles (double C[][2], int n)
{
    int count=0;
    
    //find all y-lines. for each y-line, there is a unique rectangle
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (C[i][0]==C[j][0] && j!=i)   //same y-line: (i,j)
            {
                count++;
            }
        }
    }
    
    return count/2; //double counting: (i,j), (j,i)
}

int main()
{
    double C[][2] = {{0.0,0.0},{1.0,0.0},{2.0,0.0},{0.0,1.0},{1.0,1.0},{2.0,1.0}};
    
    const size_t nn = sizeof(C) / sizeof(C[0]);
    int n = nn;
    
    cout<<rectangles(C, n);

    return 0;
}
