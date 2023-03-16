/*Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
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
1 2 1
0 1 3
0 3 5*/
#include<iostream>
#include <bits\stdc++.h>
using namespace std;

//making an edge class to store source destination and weight of eachh edge
class edge{
    public:
    int v1;
    int v2;
    int weight;
};

//func to compare edges according to their weight
bool compareEdge(edge e1,edge e2){
    return(e1.weight<e2.weight);
}

//func to find parent of a given vertex
int findParent(int x,int parent[]){
    int temp=x;
    while(parent[temp]!=temp){
        temp=parent[temp];
    }
    return temp;
}

int main(){
    int n,e;
    cin>>n>>e;

    edge* input = new edge[e];
    edge* output = new edge[n-1];

    //taking input of edges
    for(int i=0;i<e;i++){
        int x,y,z;
        cin>>x>>y>>z;
        input[i].v1=x;
        input[i].v2=y;
        input[i].weight=z;
    }

    //sorting edges based on their weights
    sort(input,input+e,compareEdge);        //O(ElogE)

    //initializing parent array
    int parent[n];
    for(int i=0;i<n;i++){
        parent[i]=i;
    }

    //implementing kruskals algo by performing cycle detection and adding edges in MST      //O(E*V) where v is no of vertices
    int count=0,i=0;
    while (count<n-1)
    {
        edge curr = input[i];
        i++;
        int pv1 = findParent(curr.v1,parent);
        int pv2=findParent(curr.v2,parent);
        if(pv1==pv2){
            continue;
        }
        output[count]=curr;
        parent[pv1]=pv2;
        count++;
    }
    
    //printing the output
    for(int i=0;i<n-1;i++){
        if(output[i].v1<output[i].v2){
        cout<<output[i].v1<<" "<<output[i].v2<<" "<<output[i].weight<<endl;
        }
        else{
            cout<<output[i].v2<<" "<<output[i].v1<<" "<<output[i].weight<<endl;
        }
    }
}

//total complexity = O(ElogE+E*V)