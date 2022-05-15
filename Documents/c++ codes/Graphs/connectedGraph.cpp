#include <iostream>
#include <queue>
using namespace std;

void print(int** edges, int n, int vertex, bool* visited){
    
    cout << vertex << endl;
    visited[vertex] = true;
    for(int i=0; i<n; i++){
        if(edges[vertex][i] == 1){   
            if(visited[i]) continue;
            print(edges, n, i, visited);
        }

    }
}

void printBFS(int** edges, int n, int vertex){

    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }

    queue<int> pendingVertex;
    pendingVertex.push(vertex);
    visited[vertex] = true;
    while(!pendingVertex.empty()){
        int curr = pendingVertex.front();
        pendingVertex.pop();
        
        cout << curr << endl;
        for(int i=0; i<n; i++){
            if(edges[curr][i] == 1){
                if(visited[i]) continue;
                pendingVertex.push(i);
                visited[i] = true;
            }
        }
    }

    delete [] visited;

}
 // 6 6 0 1 0 2 0 3 2 5 3 4 1 
 
int main(){
    int n;
    int e;
    cout << "No. of vertex : " ;
    cin >> n;
    cout << "No. of Edges : " ;
    cin >> e;

    int** edges = new int*[n];

    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j] = 0;
        }
    } 

    cout << "Edges are : " << endl;
    for(int i=0; i<e; i++){
        int start, end;
        cout << "starting Vertex : " ;
        cin >> start;
        cout << "Ending Vertex : " ;
        cin >> end;

        edges[start][end] = 1;
        edges[end][start] = 1;
    }

    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    cout << "DFS";
    print(edges, n, 0, visited);
    cout << "BFS";
    printBFS(edges, n, 0);

    delete [] visited;
    for(int i=0; i<n; i++){
        delete edges[i];
    }
    delete [] edges;
    
}