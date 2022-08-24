// a peak element in an array exists when it is greater than or equal to  it's adjacent element(s), and holds same for the first and last elements as well, which are the H cases of this.
// returning the first peak element we come accross, using binary search approach to better the time complexity
#include<iostream> 
#include<vector>
using namespace std; 

int firstPeakElement(int arr[]){
    int l = 0, h = 9;
    int mid;
    while (l<=h){
        mid = l + ( h - l ) / 2;

        // if(arr[mid-1] <= arr[mid] && arr[mid+1] <= arr[mid]) return mid;  --> this statement does not handle any of the H cases, only applicable for elements having two adjacent elements
         // if first element is being checked       if last element is being checked
        if((mid == 0 || arr[mid-1] <= arr[mid]) && (mid == 9 || arr[mid+1] <= arr[mid])) return mid;
        else if (mid > 0 && arr[mid-1] > arr[mid]) h = mid - 1;
        else l = mid + 1;

    }

    return mid; //this will most likely not get executed in any case as any array whether sorted or not will def have atleast one peak element
}

int main() 
 { 
    int arr[10];
    cout << "Enter 10 elements :";
    for (int i = 0; i < 10; i++)
    {
        cout << "  ";
        cin >> arr[i];
    }

    int peakIndex = firstPeakElement(arr);
    cout << "\n One of the peak elements is at index : " << peakIndex;
    return 0; 
}