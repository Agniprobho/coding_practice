#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <int> v2;

void combinationUtil(int arr[], int data[], int start, int end, int index, int r)  
{  
    // Current combination is ready 
    // to be printed, print it  
    if (index == r)  
    {  
        for (int j = 0; j < r; j++)  
            v2.push_back(data[j]);  
        return;  
    }  
    
    // replace index with all possible  
    // elements. The condition "end-i+1 >= r-index" 
    // makes sure that including one element  
    // at index will make a combination with  
    // remaining elements at remaining positions  
    for (int i = start; i <= end && end - i + 1 >= r - index; i++)  
    {  
        data[index] = arr[i];  
        combinationUtil(arr, data, i+1, end, index+1, r);  
    }  
}  

int Min(vector <string> v, vector <string> v1)
{
	int min = 1000;
	int cmb, r, n, check, check1, size1, size2, size1_next, cmb_num;
	n = v.size();
	vector <string> vec;
	
	int arr[n];
	for (int i=0; i<n; i++)
	{
	    arr[i] = i;
	}

	for (int i=0; i<v.size(); i++)
	{
	    cmb = i+1; //combinations, picks: cmb at a time
	    //for each cmb, ie, number of extra connections to add, check all possibilities
	    //If all airports are covered, break and exit loop 
	    //min is cmb in that case
	    v2.clear();
	    
	    check1 = 0;
	    
	    r = cmb;  
        int data[r];
	    combinationUtil(arr, data, 0, n-1, 0, r); 
	    
	    for (int j=0; j<v2.size()/cmb; j++)
	    {
	        vec.clear();
	        for (int k=0; k<cmb; k++)
	        {
	            vec.push_back(v.at(v2.at(cmb*j+k)));    //note extra connection airports for combination j in vec
	        }
	        
	        //check if the airports in combination j are sufficient to get to all airports
	        size1=0; 
	        size2=vec.size();
	        
	        while (size1<size2)
	        {
	            size1_next = size2;
	            for (int k=size1; k<size2; k++)
	            {
	                for (int l=0; l<v1.size()/2; l++)
	                {
	                    if (vec.at(k)==v1.at(2*l))
	                    {
	                        check = 0;
	                        for (int m=0; m<vec.size(); m++)
	                        {
	                            if (v1.at(2*l+1)==vec.at(m)) //airport already noted
	                                check=1;
	                        }
	                        
	                        if (check==0) //airport not noted
	                        {
	                            vec.push_back(v1.at(2*l+1));
	                        }
	                    }
	                }
	            }
	            size1 = size1_next;
	            size2 = vec.size();
	        }
	        
	        if (size2==v.size())
	        {
	            check1 = 1;
	            cmb_num = j;
	            min = cmb;
	            break;
	        }
	    }
	    
	    if (check1 ==1)
	        break;
	}
	
	for (int i=0; i<cmb; i++)
	    cout<<v.at(v2.at(cmb*cmb_num+i))<<"\t";
	    
	vec.clear();
	
	return min;
}

int main()
{
    int j, sz1, sz2, check, check1;
    vector <string> v, v1;
	
	//input
    string A[] = {"BGI", "CDG", "DEL", "DOH", "DSM", "EWR", "EYW", "HND", "ICN",
				"JFK", "LGA", "LHR", "ORD", "SAN", "SFO", "SIN", "TLV", "BUD"};
    string routes[][2] = {{"DSM","ORD"},{"ORD","BGI"},{"BGI","LGA"},{"SIN","CDG"},{"CDG","SIN"},{"CDG","BUD"},{"DEL","DOH"},{"DEL","CDG"},
				{"TLV","DEL"},{"EWR","HND"},{"HND","ICN"},{"HND","JFK"},{"ICN","JFK"},{"JFK","LGA"},{"EYW","LHR"},{"LHR","SFO"},{"SFO","SAN"},{"SFO","DSM"},{"SAN","EYW"}};
				
	string start = "LGA";
	
	const size_t sA = sizeof(A) / sizeof(A[0]);	//count number of strings in array
	const size_t sR = sizeof(routes) / sizeof(routes[0]);	//count number of strings in array
    sz1 = sA;
	sz2 = sR;
	
	//cleanup: remove start airport from list of airports to connect (v) and endpoints in routes (v1)
	for (int i=0; i<sz1; i++)
	{
	    if (A[i]!=start)
	        v.push_back(A[i]);
	}
	
	for (int i=0; i<sz2; i++)
	{
	    if (routes[i][1]!=start)
	    {
	        v1.push_back(routes[i][0]);
	        v1.push_back(routes[i][1]);
	    }
	}
	
    cout<<Min(v, v1)<<"\n";
    
    v.clear();
    v1.clear();
    v2.clear();
    
    return 0;
}