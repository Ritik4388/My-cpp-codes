#include <iostream>
#include <queue>
using namespace std;

void printDFS(int** edges, int n, int vertex, bool* visited){
    
    cout << vertex << endl;
    visited[vertex] = true;
    for(int i=0; i<n; i++){
        if(edges[vertex][i] == 1){   
            if(visited[i]) continue;
            printDFS(edges, n, i, visited);
        }

    }
}

void printBFS(int** edges, int n, int vertex, bool* visited){

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

}

void DFS(int** edges, int n){

    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }

    for(int i=0; i<n; i++){        //checking if each vertex is visited or not it will hlp in disconnected graph.
        if(!visited[i]){
            printDFS(edges, n, i, visited);
        }
    }

}

void BFS(int** edges, int n){

    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }

    for(int i=0; i<n; i++){
        if(!visited[i]){
            printBFS(edges, n, i, visited);
        }
    }

}
 
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

    cout << "DFS : " << endl;
    DFS(edges, n);
    cout << "BFS : " << endl;
    BFS(edges, n);

    for(int i=0; i<n; i++){
        delete edges[i];
    }
    delete [] edges;
    
}