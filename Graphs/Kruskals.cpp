#include <iostream>
#include "edge.h"
#include <bits/stdc++.h>
using namespace std;

int topParent(int vertex, int *parents){
    int next = vertex;
    while(next != parents[next]){
        next = parents[next];
    }
    return next;
}

int main(){
    int n, e;
    cout << "Enter the number of vertices and edges: " << endl;
    cin >> n >> e;
    // cout << "Enter the " << e << "edges: " << endl;
    vector<edge> edges;
    for (int i=0; i<e; i++){
        int s, d, w;
        cin >> s >> d >> w;
        edges.push_back(edge(s,d,w));
    }
    sort(edges.begin(), edges.end());
    int *parents = new int[n];
    for(int i=0; i<n; i++){
        parents[i] = i;
    }
    // cout<<"Here";
    vector<edge> MST;
    int i=0;    //Travel over the edges array
    while(MST.size() < n-1){
        edge currentEdge = edges[i];
        i++;
        int xTopParent = topParent(currentEdge.getSource(), parents);
        int yTopParent = topParent(currentEdge.getDestination(), parents);
        if (xTopParent == yTopParent){
            //Cycle is formed
            continue;
        }
        else{
            MST.push_back(currentEdge);
            parents[xTopParent] = yTopParent;
        }
    }
    // cout << "Output: " << endl;
    for(int i=0; i<MST.size(); i++){
        cout << MST[i].getSource() << " " << MST[i].getDestination() << " " << MST[i].getWeight() << endl;
    }
    return 0;
}