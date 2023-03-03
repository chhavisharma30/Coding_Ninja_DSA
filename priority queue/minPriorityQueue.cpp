//min priority queue implementation is also called heap sort
//heap sort time complexity is O(nlogn){insertion} + O(nlogn)(deletion) = O(nlogn)
//heap sort space complexity is O(n) as we are using vector array of n size

#include<iostream>
#include<vector>
using namespace std;

class priorityQueue{
    vector<int> pq; //array to store the cbt
    public:
        priorityQueue(){    //constructor
        }

        //func to check if queue is empty
        bool isEmpty(){
            return pq.size()==0;
        }

        //func to check size of priority queue
        int getSize(){
            return pq.size();
        }

        //func to get min element of the queue
        int getMin(){
            if(isEmpty()){
                return 0;
            }
            return pq[0];
        }

        //func to insert an element in queue
        void insert(int element){
            pq.push_back(element);

            int childIndex = pq.size()-1;
            
            //up heapify(more in notes)
            while(childIndex>0){
                int parentIndex = (childIndex-1)/2;

                if(pq[childIndex]<pq[parentIndex]){
                    int temp = pq[childIndex];
                    pq[childIndex]= pq[parentIndex];
                    pq[parentIndex]= temp;
                }
                else{
                    break;
                }

                childIndex=parentIndex;
            }
        }


        //func to delete min element in queue
        int removeMin(){
            
            if(isEmpty()){
                return 0;
            }

            //deleting min element
            int ans = pq[0];
            pq[0]=pq[pq.size()-1];
            pq.pop_back();

            //down heapify
            int parentIndex=0;
            int lchildIndex=2*parentIndex+1;
            int rchildIndex=2*parentIndex+2;
            int minIndex=0;

            while(lchildIndex<pq.size()){       //if left child index is out of size than right will definitly be out

                int minIndex=parentIndex;
                if(pq[minIndex]>pq[lchildIndex]){
                    minIndex=lchildIndex;
                }
                if(rchildIndex<pq.size() && pq[minIndex]>pq[rchildIndex]){
                    minIndex=rchildIndex;
                }
                if(minIndex==parentIndex){
                    break;
                }
                int temp=pq[minIndex];
                pq[minIndex]=pq[parentIndex];
                pq[parentIndex]=temp;

                parentIndex=minIndex;
                lchildIndex=2*parentIndex+1;
                rchildIndex=2*parentIndex+2;
            }

            return ans;
        }
};

int main(){
    priorityQueue p;
    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);

    cout<<p.getSize()<<endl;
    cout<<p.getMin()<<endl;

    while(!p.isEmpty()){
        cout<<p.removeMin()<<endl;
    }    
}