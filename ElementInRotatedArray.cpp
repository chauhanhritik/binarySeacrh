#include<iostream> 
#include<vector>
using namespace std; 

int find_element(vector <int> &vec,int k){
    int l = 0, h = (vec.size()-1); 
    int mid;
    while (l<=h){
        mid = l + (h-l)/2;
        if(vec[mid]==k) return mid;

        else if(vec[l]<=vec[mid]) //this condition ensures that the left part of the element is sorted and may have repeatition. If all elements were to be distinct then only "<" would be used
        // for right side, we would have used  - vec[mid]<vec[h], We can use either of the two conditions
        { //now we have only checked that the left side array is sorted, but we dont know if the element exists within it or not. So -
            if(vec[l]<=k && k < vec[mid]) //the element exists on left side of MID if true
            {h = mid - 1;}
            else l = mid + 1; //moving over to the right side
        }
        else //here right side is sorted 
        {
            if( vec[mid] < k && k <= vec[h]) 
            {
                l = mid + 1;
            }
            else {h = mid-1 ;}
        }

    }
    
    
    return -1;
}

int main() 
 { 
    int n , k , ele;
    vector<int> vec;
    cout << "Enter the no of element : ";
    cin >> n;
    cout << "\n Enter a sorted rotated array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        vec.push_back(ele);
    }
    cout << "\n Enter the element you want to find : ";
    cin >> k;
    int index = find_element(vec,k);
    cout << "\n Element is present at index : " << index ;
    return 0; 
}