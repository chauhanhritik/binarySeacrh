// minimum no in  a sorted rotated array
// we need to find the element for which previous element > current element, thus we have to look for it in the unsorted part
// edge case - first element

#include<iostream> 
using namespace std; 

int minElement(int arr[]){
    int mid , l = 0 , h = 9; 
    while (l<=h)
    {   
        mid = l + (h-l)/2;
        if( mid==0 || arr[mid-1] > arr[mid]) return arr[mid]; //as mid may be = 0, in which case mid-1 will overflow
        else if(arr[l]>arr[mid]) h = mid - 1; //left side array is unsorted
        else if(arr[h]<arr[mid]) l = mid + 1; //right side array is unsorted
        else return arr[l] ; //i.e both side elements were sorted
    }
    return -1;
}

int main() 
 { 
    int arr[10], n;
    cout << "Enter a sorted rotated array of 10 elements : ";
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
        cout << "  ";
    }
    int minEle = minElement(arr);
    cout <<"The smallest element is : " << minEle;
    return 0; 
}