#include<iostream>
#include <algorithm>  
#include <vector>

using namespace std;

void vec_binary_search(vector<int> &vec, int ele){
    int mid , beg = 0;
    int end = vec.size()-1;
    // <<-- IMPORTANT Due to INT_MAX
    while (beg<=end)
    {
        mid = beg +((end-beg)/2); 
        if(vec[mid]>ele)
        {
            end = mid +1;
        }
        else if(vec[mid]<ele)
        {
            beg = mid-1;
        }
        else
        {
            cout<<"\n ELement is present at index : "<<mid;
            exit(0); //else the loop will re-evaluate with the same values and execute infinitely
        }
    }
    if(beg>end){
        cout<<"\n ELEMENT NOT FOUND";
    }
    

}

void array_sort(int *a){
    int n , i ;
    cout<< "Enter the elements : ";
    for ( i = 0; i < 10; i++)
    {
        cin>>a[i];
        cout<<endl;
    }

    sort(a,a+10);
     for ( i = 0; i < 10; i++)
    {
        cout<<a[i] << "     ";
    }
}

void vec_sort(vector<int> &vec){
    int n , i , j , ele;
    cout<< "Enter the no of elements : ";
    cin>>n;
    cout<<"\n Enter the elements : ";
    for ( i = 0; i < n; i++)
    {
        cin>>j;
        vec.push_back(j);
        cout<<"  ";
    }
    sort(vec.begin(),vec.end());

    cout<<"\n The sorted vector is : \n";
    for ( i = 0; i < vec.size(); i++)
    {
        cout<<vec[i]<<" ";
    }

    cout << "\n Enter the element you want to search for : ";
    cin >> ele;

    //    ************BINARY SEARCH*****************
    vec_binary_search(vec,ele);
    
}


int main()
{
    int a[10];
    vector<int> vec;

    // array_sort(a);

    vec_sort(vec);
      
    return 0;
}
