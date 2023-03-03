/*Problem Description:
Implement the class for Max Priority Queue which includes following functions -
1. getSize -
Return the size of priority queue i.e. number of elements present in the priority queue.
2. isEmpty -
Check if priority queue is empty or not. Return true or false accordingly.
3. insert -
Given an element, insert that element in the priority queue at the correct position.
4. getMax -
Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.
5. removeMax -
Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.*/
#include<iostream>
#include<vector>
#include<limits>    //used to use infinity in any code
using namespace std;

class maxPriorityQueue{
    vector<int> pq;
    public:
    maxPriorityQueue(){}

    bool isEmpty(){
        return pq.size()==0;
    }

    int getSize(){
        return pq.size();
    }

    int getMax(){
        if(isEmpty()){
            return (numeric_limits<float>::infinity())*-1;;
        }
        return pq[0];
    }

    void insert(int element){
        pq.push_back(element);

        //up heapify
        int childIndex = pq.size()-1;
        while(childIndex>0){
            int parentIndex=(childIndex-1)/2;

            if(pq[childIndex]>pq[parentIndex]){
                int temp=pq[childIndex];
                pq[childIndex]=pq[parentIndex];
                pq[parentIndex]=temp;
            }
            else{
                break;
            }

            childIndex=parentIndex;
        }
    }

    int removeMax(){
        if(isEmpty()){
            return (numeric_limits<float>::infinity())*-1;  //return -infinity
            
        }

        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();

        //down heapify
        int parentIndex=0;
        int lchildIndex = 2*parentIndex +1;
        int rchildIndex = 2*parentIndex +2;
        int maxIndex=0;

        while(lchildIndex<pq.size()){
            maxIndex = parentIndex;

            if(pq[lchildIndex]>pq[maxIndex]){
                maxIndex=lchildIndex;
            }
            if(rchildIndex<pq.size() && pq[maxIndex]<pq[rchildIndex] ){
                maxIndex=rchildIndex;
            }
            if(maxIndex==parentIndex){
                break;
            }
            int temp = pq[maxIndex];
            pq[maxIndex]=pq[parentIndex];
            pq[parentIndex]=temp;

            parentIndex=maxIndex;
                lchildIndex=2*parentIndex+1;
                rchildIndex=2*parentIndex+2;
        }
        return ans;
    }
};

int main(){
    maxPriorityQueue p;
    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);

    cout<<p.getSize()<<endl;
    cout<<p.getMax()<<endl;

    while(!p.isEmpty()){
        cout<<p.removeMax()<<endl;
    }    
}