#include <iostream>
using namespace std;

int fiboMemoHelper(int n, int *ans){
    if (n<=1){
        return n;
    }
    if (ans[n] != 0){
        return ans[n];
    }
    int a = fiboMemoHelper(n-1, ans);
    int b = fiboMemoHelper(n-2, ans);
    ans[n] = a+b;
    return ans[n];
}
int fibo_memoization(int n){ 
    int *ans = new int[n+1];
    for(int i=0; i<n+1; i++){
        ans[i] = 0;
    }
    return fiboMemoHelper(n, ans);
    delete [] ans;
}

int fibo_dp(int n){
    int *ans = new int[n+1];
    ans[0] = 0;
    ans[1] = 1;
    for(int i=2; i<n+1; i++){
        ans[i] = ans[i-1] + ans[i-2];
    }
    return ans[n];
}

int main(){
    int ans = fibo_dp(7);
    cout << ans << endl;
    return 0;
}