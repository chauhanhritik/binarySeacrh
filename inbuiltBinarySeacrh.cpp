// Binary_search , lower_bound , upper_bound
#include<iostream> 
#include<vector>
#include<bits/stdc++.h>

using namespace std; 


 int main() 
 {  vector<int> vec = {10,20,30,40,50,60};
   

//    vec.begin() , vec.end() , vec.begin() + n etc are called as iterators. The second iterator passed in binary search() function is always excluded
    cout << binary_search(vec.begin(), vec.end() , 20) << "\n"; //will return 1(true) and vec.end() signifies the index next to vec[5], excluding the upper bound and traversing upto 60 only
    cout << binary_search(vec.begin(), vec.begin()+5 , 60) << "\n"; //will return 0(false) as vec.begin() + 5 will allow the traversing upto vec[4], excluding vec[5]
 


    cout << lower_bound(vec.begin(), vec.end(),50) - vec.begin() <<"\n";
    // vec.begin() has to be subtractyed as lower bound returns an iterator and cant be just returned to screen, thus we subtract the vec begin address from it and get the index of the element instead
    cout << lower_bound(vec.begin(), vec.begin()+4, 50) - vec.begin() << "\n";  //here even thought the traversal is done only upto vec[3], but since lower bound returns index for vec[index] >= ele, and 50 didnt exist in the given array, thus it returns 4 as the next index to the last index available as vec[3] < ele
    // cout << "100";
    return 0; 
}