#include <iostream>
using namespace std;

int helper(int* weights, int* values, int n, int maxWeight, int **ans){
    if (maxWeight <= 0 || n==0){
        return 0;
    }
    if (ans[n][maxWeight] != -1){
        return ans[n][maxWeight];
    }
    if (weights[n-1] > maxWeight){
        ans[n][maxWeight] = helper(weights, values, n-1, maxWeight, ans); 	//Exclusive
        return ans[n][maxWeight];
    }
    int inclusive = values[n-1] + helper(weights, values, n-1, maxWeight-weights[n-1], ans);
    int exclusive = helper(weights, values, n-1, maxWeight, ans);
    ans[n][maxWeight] = max(inclusive, exclusive);
    return ans[n][maxWeight];
}

int knapsack(int* weights, int* values, int n, int maxWeight){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
  */
	int **ans = new int*[n+1];
    for(int i=0; i<n+1; i++){
        ans[i] = new int[maxWeight+1];
        for(int j=0;j<maxWeight+1; j++){
            ans[i][j] = -1;
        }
    }
    return helper(weights, values, n, maxWeight, ans);
}


int main(){

  int n; 
  cin >> n;
  int* weights = new int[n];
  int* values = new int[n];

  for(int i = 0; i < n; i++){
    cin >> weights[i];
  }

  for(int i = 0; i < n; i++){
    cin >> values[i];
  }

  int maxWeight;
  cin >> maxWeight;

  cout << knapsack(weights, values, n, maxWeight);

    return 0;
}