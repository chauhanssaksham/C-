#include <iostream>
#include <climits>
using namespace std;

int main(){
    int n, e;
    cin >> n >> e;
    int **edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for (int j=0; j<n;j++){
            edges[i][j] = -1;
        }
    }
    for (int i=0; i<e; i++){
        int s,d, w;
        cin >> s >> d >> w;
        edges[s][d] = w;
        edges[d][s] = w;
    }
    int *parent = new int[n];
    int *weights = new int[n];
    bool *visited = new bool[n];
    for (int i=0; i<n; i++){
        parent[i] = -1;
        weights[i] = INT_MAX;
        visited[i] = false;
    }
    int currentVertex = 0;
    weights[0] = 0;
    visited[0] = true;
    int count =0;
    while(count < n-1){
        for (int i=0; i<n; i++){
            if (edges[currentVertex][i] != -1 && !visited[i]){
                if (edges[currentVertex][i] < weights[i]){
                    // cout << "Iteration #" << count << ", comparing " << currentVertex << " and " << i << endl;
                    weights[i] = edges[currentVertex][i];
                    parent[i] = currentVertex;
                }
            }
        }
        int minWeightIndex;
        for (int i=0; i<n; i++){
            if (!visited[i]){
                minWeightIndex = i;
                break;
            }
        }    
        // cout << "first Min index = " << minWeightIndex << endl;
        for (int i=minWeightIndex+1; i<n; i++){
            if (!visited[i] && weights[i] < weights[minWeightIndex]){
                minWeightIndex = i;
            }
        }
        // cout << "Now min index  = " << minWeightIndex << endl; 
        visited[minWeightIndex] = true;
        currentVertex = minWeightIndex;
        count++;
    }
    for (int i=1; i<n; i++){
        cout << i << " " << parent[i] << " " << weights[i] << endl;
    }
    return 0;
}