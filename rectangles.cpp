#include <iostream>
#include <vector>

using namespace std;

int rectangles (double C[][2], int n)
{
    int count=0;
    int check;
    double layer;
    vector <double> vec;
    
    //find all y-lines. for each y-line, there is a unique rectangle
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (C[i][0]==C[j][0] && j!=i)   //found a y-line, same x: (i,j)
            {
                check = 0;
                if (C[i][1]<C[j][1])
                    layer = C[i][1]+0.8*(C[j][1]-C[i][1]); //midpoint: might be a non-integer: get a unique number for each unique set of i and j at a layer
                else
                    layer = C[j][1]+0.8*(C[i][1]-C[j][1]); 
                //get total number of y-lines in layer
                for (int k=0; k<vec.size()/2; k++)
                {
                    if (vec.at(2*k)==layer) //if layer is noted, only increment count of y-lines
                    {
                        check = 1;
                        vec.at(2*k+1) += 1;
                        break;
                    }
                }
                if (check==0)
                {
                    vec.push_back(layer);
                    vec.push_back(1);
                }
            }
        }
    }
    
    for (int i=0; i<vec.size()/2; i++)
    {
        count += (vec.at(2*i+1)/2)*((vec.at(2*i+1)/2)-1)*0.5;   //double counting: (i,j), (j,i); number of rectangles = lC2 at each layer
    }
    
    vec.clear();
    return count; 
}

int main()
{
    double C[][2] = {{0.0,0.0},{1.0,0.0},{2.0,0.0},{0.0,1.0},{1.0,1.0},{2.0,1.0},{3.0,0.0},{3.0,1.0}};
    
    const size_t nn = sizeof(C) / sizeof(C[0]);
    int n = nn;
    
    cout<<rectangles(C, n);

    return 0;
}
