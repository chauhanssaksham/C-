#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void printDFS(int **edges, int n, int sv, bool* visited){
    cout << sv << " ";
    visited[sv] = true;
    for (int i=0; i<n; i++){
        if (i==sv){
            continue;
        }
        if (edges[sv][i] == 1){
            if (visited[i]){
                continue;
            }
            printDFS(edges, n, i, visited);
        }
    }
    cout << endl;
}

void printBFS(int **edges, int n, int sv, bool *visited){
    queue<int> printQueue;
    printQueue.push(sv);
    visited[sv] = true;
    while(!printQueue.empty()){
        int front = printQueue.front();
        printQueue.pop();
        cout << front << " ";
        for (int i=0; i<n; i++){
            if (i==front){
                continue;
            }
            if (edges[front][i] == 1 && !visited[i]){
                printQueue.push(i);
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

void DFS(int **edges, int n){
    bool *visited  = new bool[n];
    for (int i=0; i <n ; i++){
        visited[i] = false;
    }
    for (int i=0; i<n; i++){
        if (!visited[i]){
            printDFS(edges, n, i, visited);
        }
    }
    delete [] visited;
}

void BFS(int **edges, int n){
    bool *visited  = new bool[n];
    for (int i=0; i <n ; i++){
        visited[i] = false;
    }
    for (int i=0; i<n; i++){
        if (!visited[i]){
            printBFS(edges, n, i, visited);
        }
    }
    delete [] visited;
}
bool HasPathDFS(int **edges, int n, int v1, int v2, bool *visited){
    if (edges[v1][v2] == 1){
        return true;
    }
    visited[v1] = true;
    for (int i=0; i<n; i++){
        if (i == v1){
            continue;
        }
        if (edges[v1][i] == 1 && !visited[i]){
            if (HasPathDFS(edges, n, i, v2, visited)){
                return true;
            }
        }
    }
    return false;
}
bool HasPathBFS(int **edges, int n, int v1, int v2, bool *visited){
    queue<int>findingQueue;
    findingQueue.push(v1);
    while(!findingQueue.empty()){
        int front = findingQueue.front();
        findingQueue.pop();
        visited[front] = true;
        for (int i=0; i<n; i++){
            if (edges[front][i] == 1 && !visited[i]){
                if (i==v2){
                    return true;
                }
                findingQueue.push(i);
            }
        }
    }
    return false;
}

vector<int> *getPathDFS(int **edges, int n, int v1, int v2, bool *visited){
    if (edges[v1][v2]==1){
        vector<int> *ans = new vector<int>();
        ans->push_back(v2);
        ans->push_back(v1);
        return ans;
    }
    visited[v1] = true;
    for (int i=0; i<n; i++){
        if (i == v1){
            continue;
        }
        if (edges[v1][i] == 1 && !visited[i]){
            vector<int> *ans = getPathDFS(edges, n, i, v2, visited);
            if (ans!=NULL){
                ans->push_back(v1);
                return ans;
            }
        }
    }
    return NULL;
}


// 7 8 0 2 0 1 1 3 1 4 2 6 3 4 4 5 6 5
// 13 12 0 1 0 2 1 3 1 4 2 6 3 5 4 5 5 6 9 10 10 12 11 9 11 12
int main(){
    int n, e;
    cout << "Enter the number of vertices: " << endl;
    cin >> n;
    cout << "Enter the number of edges: " << endl;
    cin >> e;
    int **edges = new int*[n];
    for (int i=0; i<n; i++){
        edges[i] = new int[n];
        for (int j=0; j<n; j++){
            edges[i][j] = 0;
        }
    }
    for (int i=0; i<e; i++){
        cout << "Enter the edge as a pair of vertices: " << endl;
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    int v1, v2;
    cin >> v1 >> v2;
    bool *visited = new bool[n];
    for (int i=0; i<n; i++){
        visited[i] = false;
    }
    vector<int> *path = getPathDFS(edges, n, v1, v2, visited);
    if (path != NULL){
        for (int i=0; i<path->size(); i++){
        cout << path->at(i) << " ";
        }
    }
    else{ 
        cout << "No path found!" << endl;
    }
    delete path;
    for (int i=0; i<n; i++){
        delete [] edges[i];
    }
    delete [] edges;
    delete [] visited;
    return 0;
}