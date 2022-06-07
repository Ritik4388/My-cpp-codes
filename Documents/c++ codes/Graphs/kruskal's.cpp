#include<iostream>
#include<map>
#include<vector>
#include<iterator>
using namespace std;

int checkParent(int node, vector<int> &parent){
    if(parent[node] == node){
        return node;
    }
    return checkParent(parent[node], parent);
}

int main(){
    int v, e ;
    cin >> v >> e;
    multimap<int, pair<int,int>> m;
    multimap<int, pair<int,int>> mst;
    for(int i=0; i<e; i++){
        int s,d,wt;
        cin >> wt >> s >> d;
        m.insert(pair<int, pair<int,int>>(wt, {s,d}));
    }
    vector<int> parent(v);
    for(int i=0; i<v; i++){
        parent[i] = i;
    }
    int cnt = 0;
    multimap<int, pair<int,int>>::iterator it;
    for(it = m.begin(); it != m.end(); ++it){
        int src = checkParent(it->second.first, parent);
        int dst = checkParent(it->second.second, parent);
        if(src != dst){
            mst.insert(pair<int, pair<int,int>>(it->first ,{it->second.first ,it->second.second}));
            parent[it->second.second] = it->second.first;
            cnt++;
            if(cnt == v-1) break;
        }
    }
    multimap<int, pair<int,int>>::iterator i;
    for(i = mst.begin(); i != mst.end(); ++i){
        cout << i->first << " " << i->second.first << " " << i->second.second << endl;
    }
    return 0;
}