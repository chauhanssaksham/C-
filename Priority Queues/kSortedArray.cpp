#include <iostream>
#include <queue>
using namespace std;

void kSortedArray(int *input, int size, int k){
    priority_queue<int> PQ;
    for(int i=0;i<k;i++){
        PQ.push(input[i]);
    }
    for (int i=0; i< size; i++){
        input[i] = PQ.top();
        PQ.pop();
        if (i+k < size){
            PQ.push(input[i+k]);
        }
    }
}
// 10 12 6 7 9
// k = 3
int main(){
    int arr[] = {10,12,6,7,9};
    kSortedArray(arr, 5, 3);
    for(int i=0; i<5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}