//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        int large = INT_MIN, s_large = INT_MIN;
        
        if(arr.size()<2)
            return -1;
        
        for(int i=0; i<arr.size(); i++){
            if(large<arr[i]){
                s_large = large;
                large = arr[i];
            }
            else if(s_large<arr[i] && arr[i]!=large){
                s_large = arr[i];
            }
        }
        
        if(s_large == INT_MIN)
            return -1;
        return s_large;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends