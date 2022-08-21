// finding the first and last occurance of a no in a sorted vector, can be done using binary search

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void begin_search(vector<int> &vec, int ele){
    int mid , l = 0 , first = -1, last = -1;
    int h = vec.size();

    // finding first occurence
    while (l<=h)
    {
        mid = l + ((h-l)/2);

        if(vec[mid] > ele){ h = mid-1 ;}

        else 
        if(vec[mid] < ele){ l = mid + 1;}

        else
        { first = mid;
          h = mid-1;  //we need to check if there is any occurence of the element before the currently updated index, else we cant be sure
        }
    }
    l = 0 , h = vec.size();
    // finding last occurence
    while (l<=h)
    {
        mid = l + ((h-l)/2);

        if(vec[mid] > ele){ h = mid-1 ;}

        else 
        if(vec[mid] < ele){ l = mid + 1;}

        else
        { 
            last  = mid;
            l = mid+1;
         }
    }

    cout << "\n First and last index : " << first <<"  " << last;
    

}

int main(int argc, char const *argv[])
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
    begin_search(vec,ele);
    
    return 0;
}
