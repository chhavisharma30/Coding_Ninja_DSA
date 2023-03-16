/*Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -
v1 v2 w

where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)

Output Format :
MST

Constraints :
2 <= V, E <= 10^5

Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8

Sample Output 1 :
0 1 3
1 2 1
0 3 5*/
#include<iostream>
using namespace std;

//func to find vertex with min weight
int getMin(int* weight,bool* visited,int n){
    int minW = INT16_MAX;
    int minId = -1;
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            if(minW>weight[i]){
            minW = weight[i];
            minId=i;
            }
        }
    }
    return minId;
}

int main(){
    int n,e;
    cin>>n>>e;
    int** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int f,s,w;
        cin>>f>>s>>w;
        edges[f][s]=w;
        edges[s][f]=w;
    }

    //initializing visted,weight and parent array
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }

    int* weight = new int[n];
    weight[0]=0;
    for(int i=1;i<n;i++){
        weight[i]=INT16_MAX;
    }

    int* parent = new int[n];
    parent[0]=-1;
    for(int i=1;i<n;i++){
        parent[i] = 0;
    }

    //proceeding with prims algo
    for(int i=0;i<n-1;i++){       //O(n)
        //picking min weight vertex
        int currV = getMin(weight,visited,n);       //O(n*n)
        //marking vertex as visited
        visited[currV] = true;
        //exploring neighbours of vertex and modifying their weight and parent if needed
        for(int j=0;j<n;j++){       //O(n*n)
            if(edges[currV][j]!=0 && visited[j]==false){
                if(edges[currV][j]<weight[j]){
                    weight[j]=edges[currV][j];
                    parent[j]=currV;
                }
            }
        }
    }

    //printing the result
    for(int i=1;i<n;i++){
        if(parent[i]<i){
        cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }
        else{
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
    }
}

//Total complexity = o(n*n)
//We can improve complexity upto O((E+V) log V) by using adjacdency list instead of adj matrix and using priority queue for finding min vertex.