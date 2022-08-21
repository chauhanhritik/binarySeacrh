#include<iostream> 
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std; 

void search_occurence(vector<int> &vec, int ele)
{
    if(!binary_search(vec.begin(),vec.end(),ele)){ //as the required element must exist atleast once
        cout << "\n Elements dont exist";
        exit(0);
    }

    int first = -1 , last = -1;
    first = lower_bound(vec.begin(), vec.end(), ele)-vec.begin();
    last = upper_bound(vec.begin(), vec.end(),ele)-vec.begin()-1; //-1 added as upper bound returns the address of next element of ele if ele is found

    cout << "\n First : " << first << "  Last : "<< last;
}

 int main() 
 { 
    int n , ele;
    vector<int> vec; 
    cout<<"Enter the No of elements : ";
    cin >> n;
    cout << "\n Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        cout << "   ";
        cin >> ele;
        vec.push_back(ele);
    }
    sort(vec.begin(), vec.end());
    cout << "\n Sorted Vector : ";
    for ( int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << "  ";
    }
    

    cout << "\n Enter the element to search for : ";
    cin >> ele;
    search_occurence(vec,ele);
 
}