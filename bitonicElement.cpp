// an array is said to have a bitonic element(bitonic element) if it increases upto an element and then starts decreasing from that element onwards. ex --> 1,2,3,4,5,3,1 (5 is the bitonic/peak element) 
// edge cases --> array is sorted in ascending/descending  order until the end, then the highest element is the bitonic point
#include<iostream> 
#include<vector>
using namespace std; 

int bitonicElement(int arr[]){
    int mid , l = 0 , h = 9;

    while (l<=h)
    {
        mid = l + ( h - l)/2;
        if ((mid == 0 || arr[mid-1] < arr[mid]) && (mid == 9 || arr[mid+1] < arr[mid] ))
        {
            cout << "\n Element : "<< arr[mid]<< " at index : " << mid;
            return mid;
        }
        else if (arr[mid-1]<arr[mid]) l =mid+1;
        else  h = mid-1;
    }
    return -1; //not gonna reach this in reality, provided the array is sorted that is entered
}


int main() 
 { 
    int arr[10],  ele = 0, index ;
    vector<int> vec;
    
    cout << "Enter the bitonic array(10 elements) : ";
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    bitonicElement(arr);   
    return 0; 
}