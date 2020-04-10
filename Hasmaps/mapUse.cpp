#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
	//Your Code goes here
    unordered_map<int, bool> traversed;
    int startMax, maxLength;
    for (int i=0; i<n;i++){
        traversed[arr[i]] = false;
    }
    startMax = 0;
    maxLength = 0;
    for(int i=1;i<n; i++){
        if (!traversed[arr[i]]){
            int startCurrent = arr[i], currentLength = 0;
            int x = arr[i];
            while(traversed.count(x) > 0){    //Going forward
                traversed[x] = true;
                currentLength++;
                x++;
            }
            x=arr[i]-1;     //Going backwards
            while(traversed.count(x) > 0){
                startCurrent = x;
                currentLength++;
                traversed[x] = true;
                x--;
            }
            if (currentLength > maxLength){
                maxLength = currentLength;
                startMax = startCurrent;
            }
        }
    }
    vector<int> output;
    for(int i=0; i<maxLength; i++){
        output.push_back(startMax);
        startMax++;
    }
    return output;
}

int main(){
    int size;
    cin >> size;
    int *arr = new int[size];
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
    vector<int> output  = longestConsecutiveIncreasingSequence(arr, size);
    for(int i=0; i<output.size(); i++){
        cout << output[i] << " ";
    }
    return 0;
}