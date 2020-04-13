#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMinVertex(int *distance, bool *visited, int n){
    int minVertex;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            minVertex = i;
            break;
        }
    }
    for(int i=minVertex+1; i<n; i++){
        if (!visited[i] && distance[minVertex] > distance[i]){
            minVertex = i;
        }
    }
    return minVertex;
}

void dijkstra(int **edges, int n){
    bool *visited = new bool[n];
    int *distance = new int[n];
    for (int i=0; i<n; i++){
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[0] = 0;
    for(int i=0; i<n-1; i++){
        int minVertex = findMinVertex(visited, distance, n);
        cout << "Current Vertex = " << minVertex << endl;
        visited[minVertex] = true;
        for(int j=0; j<n; j++){
            if (edges[minVertex][j] != -1 && !visited[j]){
                int dist = distance[minVertex] + edges[minVertex][j];
                if(dist < distance[j]){
                    distance[j] = dist;
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        cout << i << " " << distance[i] << endl;
    }
    delete[] distance;
    delete[] visited;
}

int main(){
    int n, e;
    cin >> n >> e;
    int **edges = new int*[n];
    for (int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j] = -1;
        }
    }
    for(int i=0; i<e; i++){
        int s,d,w;
        cin >> s >> d >> w;
        edges[s][d]=w;
        edges[d][s]=w;
    }
    dijkstra(edges, n);
    for(int i=0; i<n; i++){
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}