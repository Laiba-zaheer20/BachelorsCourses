void product_subarrays(int arr[], int n) 
{ 
    // Variable to store the product 
    int product = 1; 
  
    // Compute the product while 
    // traversing for subarrays 
    for (int i = 0; i < n; i++) { 
        for (int j = i; j < n; j++) { 
            for (int k = i; k <= j; k++) 
                product *= arr[j]; 
        } 
    } 
  
    // Printing product of all subarray 
    cout << product << "\n"; 
} 


// C++ program to find product 
// of all subarray of an array 
  
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to find product of all subarrays 
void product_subarrays(long long int arr[], int n) 
{ 
    // Variable to store the product 
    long long int res = 1; 
  
    // Compute the product while 
    // traversing for subarrays 
    for (int i = 0; i < n; i++) { 
        long long int product = 1; 
        for (int j = i; j < n; j++) { 
            product = product * arr[j]; 
            res *= product; 
        } 
    } 
    // Printing product of all subarray 
    cout << res << "\n"; 
} 

  
// Driver code 
int main() 
{ 

    int arr[] = { 10, 3, 7 }; 
  
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    // Function call 
    product_subarrays(arr, n); 
  
    return 0; 

}



//Mainly because splitting it into more than two parts and recombining more than two results results in a more complex implementation 
//but doesn't change the fundamental (Big O) characteristic of the algorithm - the difference is a constant factor, and may result in a 
//slowdown if the division and recombination of more than 2 subsets creates additional overhead.
//
//
//For example, if you do a 3-way merge sort, then in the recombination phase you now have to find the biggest of 3 elements for every element, 
//which requires 2 comparisons instead of 1, so you'll do twice as many comparisons overall. In exchange, you reduce the recursion depth by a 
//factor of ln(2)/ln(3) == 0.63, so you have 37% fewer swaps, but 2*0.63 == 26% more comparisons (and memory accesses). Whether that is good 
//or bad depends on which is more expensive in your hardware.
 
