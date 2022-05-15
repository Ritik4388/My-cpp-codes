#include <iostream>
#include <queue>
using namespace std;


bool isPath(int** edges, int v1, int v2, int n, bool* visited){ // it will check if there is path between given two vertices.
    
    cout << " v1 " << v1 << " v2 " << v2 << " " << edges[v1][v2] << endl;
    if(edges[v1][v2] == 1) return true ;
    visited[v1] = true;

    for(int i=0; i<n; i++){
        if(edges[v1][i] == 1){
            if(visited[i]) continue;
            cout << "pre" << v1 << endl;
            bool isThere = isPath(edges, i, v2, n, visited);
            if(isThere) {
                return true;
            }
            cout << "post" << v1 << endl;    
        }
    }

    return false;
}
//8 7 0 1 0 2 1 2 2 3 2 4 4 5 6 7
 
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

    cout << "Enter two edges between which u have to check if theie is a path : " << endl;
    int v1, v2;
    cin >> v1 >> v2;
    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    cout << isPath(edges, v1, v2, n, visited);

    delete [] visited;
    for(int i=0; i<n; i++){
        delete edges[i];
    }
    delete [] edges;
    
}