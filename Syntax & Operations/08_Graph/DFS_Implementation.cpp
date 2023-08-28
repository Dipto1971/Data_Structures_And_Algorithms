#include <bits/stdc++.h>
using namespace std;

int visited[7] = {0, 0, 0, 0, 0, 0, 0}; //Mark all the nodes as unvisited
    int A[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}}; //This is the Adjacency matrix

void DFS (int i){
    int j;
    cout << i << " ";
    visited[i]=1;
    for(j=0; j<7; j++){
        if(A[i][j]==1 && !visited[j]){
            DFS(j);
        }
    }

}

int main(){
    DFS(0);


}