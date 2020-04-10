#include <iostream>
using namespace std;

int countWaysToMakeChange(int denominations[], int n, int value){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */

    int *ans = new int[value+1];
    ans[0] = 1;
    for (int i=1; i<value+1; i++){
        if (i < n+1 && i == denominations[i-1]){
            ans[i] = 1;
        }
        else{
            ans[i] =0;
        }
        for(int j=0; j<n && denominations[j] < i; j++){
            if(ans[i-denominations[j]] != -1){
                ans[i] += ans[i-denominations[j]];
            }
        }
        cout << ans[i] << " ";
    }
    cout << endl;
    return ans[value];
}

int main(){
    int n, val;
    cin>>n;
    int *input = new int[n];
    for (int i=0; i<n; i++){
        cin >> input[i];
    }
    cin >> val;
    int ans = countWaysToMakeChange(input, n, val);
    delete[] input;
    // cout << ans << endl;
}
