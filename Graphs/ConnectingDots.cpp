#include<bits/stdc++.h>
using namespace std;
#define MAXN 51


bool checkCycle(char board[][MAXN], int n, int m, int i, int j, bool **visited, char prevLoc, char color){
    // cout << "Checking " << color << " at " << i << " " << j << endl;
    if (board[i][j] != color){
        return false;
    }
    if (visited[i][j]){
        return true;
    }
    visited[i][j] = true;
    bool ans;
    //Check top square
    if (i>0 && prevLoc!='t'){
    	ans = checkCycle(board, n, m, i-1, j, visited, 'b', color);
        if (ans){
            return ans;
        }
    }
    //Check left square
    if (j>0 && prevLoc!='l'){
    	ans = checkCycle(board, n, m, i, j-1, visited, 'r', color);
        if (ans){
            return ans;
        }
    }
    //Check right square
    if (j<m-1 && prevLoc!='r'){
    	ans = checkCycle(board, n, m, i, j+1, visited, 'l', color);
        if (ans){
            return ans;
        }
    }
    //Check bototom square
    if (i<n-1 && prevLoc!='b'){
    	ans = checkCycle(board, n, m, i+1, j, visited, 't', color);
        if (ans){
            return ans;
        }
    }
    return false;
}

int solve(char board[][MAXN],int n, int m)
{
	bool **visited = new bool*[n];
    for (int i=0; i<n; i++){
        visited[i] = new bool[m];
        for(int j=0; j<m; j++){
            visited[i][j] = false;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if (!visited[i][j]){
                if(checkCycle(board, n, m, i, j, visited, 'n', board[i][j])){
                	return 1;
           		}
            }
        }
    }
    for(int i=0; i<n; i++){
        delete[] visited[i];
    }
    delete[]visited;
    return 0;
}

int main()
{
	int N,M,i;
	char board[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>board[i];
	}
	cout<<solve(board,N,M)<<endl;
}