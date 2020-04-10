#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> mergeKSortedArrays(vector<vector<int>*> input){
	vector<int> indexVector;
    priority_queue<int, vector<int>, greater<int> > PQ;
    for(int i=0; i<input.size(); i++){
        indexVector.push_back(0);
        PQ.push(input[i]->at(0));
        
    }
    vector<int> ans;
    while(!PQ.empty()){
        int current = PQ.top();
        ans.push_back(current);
        PQ.pop();
        for (int i=0; i<input.size(); i++){
            if (indexVector[i] != -1 && input[i]->at(indexVector[i]) == current){
                if (indexVector[i] == input[i]->size() - 1){
                    indexVector[i]= -1;
                } else {
                    indexVector[i]++;
                    PQ.push(input[i]->at(indexVector[i]));
                }
                break;
            }
        }
    }
    return ans;
}
#include <queue>
#include <vector>
using namespace std;
void findMedian(int arr[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output as specified in the question.
     */
	priority_queue<int> firstHalf;
	priority_queue<int, vector<int>, greater<int> > secondHalf;
    firstHalf.push(min(arr[0], arr[1]));
    secondHalf.push(max(arr[0], arr[1]));
    cout << arr[0] << endl;
    cout << (arr[0] + arr[1] )/2 << endl;
    for (int i=2; i<n; i++){
        if (i%2 == 0){
            //Add to first half
            if(arr[i] < secondHalf.top()){
                //Normal add
                firstHalf.push(arr[i]);
            } else{
                //swap add
                firstHalf.push(secondHalf.top());
                secondHalf.pop();
                secondHalf.push(arr[i]);
            }
            cout << firstHalf.top() << endl;
        } else {
            //Add to second half
            if (arr[i] > firstHalf.top()){
                //Normal add
                secondHalf.push(arr[i]);
            } else {
                //Swap add
                secondHalf.push(firstHalf.top());
                firstHalf.pop();
                firstHalf.push(arr[i]);
            }
            int print = (firstHalf.top() + secondHalf.top())/2;
            cout << print << endl;
        }
    }
}
int buyTicket (int *arr, int n, int k){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    priority_queue<int> PQ;
    queue<pair<int, bool> > Queue;
    for (int i=0; i<n; i++){
        PQ.push(arr[i]);
        if (i==k){
        Queue.push(pair<int, bool>(arr[i], true));
        } else {
        Queue.push(pair<int, bool>(arr[i], false));
        }
    }
    int time= 0;
    while(1){
    	pair<int, bool> front = Queue.front();
        if (front.first == PQ.top()){
            //Ticket dedo
            time++;
            PQ.pop();
            Queue.pop();
            if(front.second){
                return time;
            }
        } else{
            //Line ke peechhe bhejo
            Queue.pop();
            Queue.push(front);
        }
    }
}

int main(){
    int arr[] = {3,9,4};
    cout << buyTicket(arr, 3, 2) << endl;
    return 0;
}