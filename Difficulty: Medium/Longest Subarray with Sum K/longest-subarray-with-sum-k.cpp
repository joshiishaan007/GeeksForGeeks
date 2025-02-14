//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        
        map<int,int> prefixSum; // for storing prefix sum
        int sum=0; // for storing current summation
        int maxlen=0; // for storing max possible length
        
        for(int i=0; i<arr.size(); i++){
            
            sum += arr[i]; // adding value of a[i] to previous sum
            
            // if sum is equal to k then update maxlen
            if(sum == k){
                maxlen = max(maxlen,i+1);
            }
            
            // finding remaining prefix sum
            int rem = sum-k;
            
            //
            if(prefixSum.find(rem) != prefixSum.end()){
                int len = i-prefixSum[rem];
                maxlen = max(maxlen,len);
            }
            
            // if prefix sum is not present in prefixSum then adding it
            if(prefixSum.find(sum) == prefixSum.end()){
                prefixSum[sum] = i;
            }
        }
        
        return maxlen;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends