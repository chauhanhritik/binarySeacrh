// Almost similar to book allocation, we minimise the time instead of pages and alocation to each painter will b eeither of contigous boards pr none
// min value of search space --> max value of time given in array
// max value of search space --> sum of all time values

//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool allocationPossible(int arr[], int n, int k, long long mid){
         int pnt = 1; // no. of painters
        long long curr_time = 0;
        for(int i = 0; i < n; ++i)
        {
            curr_time += arr[i];
            if(curr_time > mid)
            {
                ++pnt;
                if(pnt > k)
                    return false;
                curr_time = arr[i];
            }
        }
        return true;
        
    }
  
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
       // if(k>n) return -1;
        long long ans, h=0, l = arr[0];
        for(int i = 0; i<n ;i++){
            if(arr[i]>l) l = arr[i];
            h+=arr[i];
        }
        long long mid;
        
        while (l<=h){
            mid = l+(h-l)/2;
            
            if(allocationPossible(arr,n,k,mid)){
                ans = mid;
                h = mid-1;
            } else l = mid+1;
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends