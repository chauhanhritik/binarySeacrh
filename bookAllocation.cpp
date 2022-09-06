// we have to find the min value of max pages that can be allocated to a student. Here our search space starts from the max no of pages in a single book(smallest value) to sum of all pages(i.e no of students = 1, all books allocated to him only) and each student must be allocated atleast one book irrespective of no of students and no of books
// for any specific value of mid, reduction in mid will lead to increased no of students and vice versa 

//THIS CODE HAS NOT BEEN DEBUGGED PROPERLY YET AS I AM NOT ABLE TP FIGURE OUT THE MISTAKE

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool isAllocationPossible(int A[],int n, int m, int mid){
        int stu = 1, currpages = 0;
        
        for (int i = 0; i<n;i++){
            
            if(currpages+A[i]<mid) currpages+=A[i];
            
            else {
                stu++;
                 if(stu>m) return false;
                currpages = A[i];
            }
        }
        
         return true;
        
    }
    
    
    int findPages(int A[], int N, int M) 
    {   int sum = 0;
        if(N<M) return -1;
        int res = INT_MAX;
        for(int i = 0; i<N;i++){
            sum+=A[i];
        }
        sort(A,A+N+1);
        int l = A[N-1], h = sum;
        
        while(l<=h){
            int mid = l + (h-l)/2; //max no of pages that can be alloted to a student
            if(isAllocationPossible(A,N,M,mid)){ //this is for two cases, the first being that mid is the answer and the second being that there is a smaller value possible
                res = mid; //mid currently is max no of pages that can be alloted to a student
                h = mid-1; // but since we need to minimize the max no of pages that can be alloted, we look if a smaller value exists or not
            } else {
                l = mid+1;
            }
            
        }
        return res;
        
    }
};



int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl; //A being array of book pages, n being no of books and m being no of students
    }
    return 0;
}

