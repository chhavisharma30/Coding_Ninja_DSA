#include<iostream>
using namespace std;

template<typename T>
class queue{
    T* data;
    int firstIndex;
    int nextIndex;
    int capacity;
    int size;

    public:
        queue(int s){
            data = new T[s];
            firstIndex=-1;          //to indicate that queue is empty
            nextIndex=0;
            capacity=s;
            size=0;
        }

        int getSize(){
            return size;
        }

        bool isEmpty(){
            return size==0;
        }

        void enqueue(T element){        //considering the queue to be circular
            if(size==capacity){         //create a new queue of double size so that queue never gets full
                T* newData = new T[2*capacity];
                int j=0;
                for(int i=firstIndex;i<capacity;i++){
                    newData[j]=data[i];
                    j++;
                }
                for(int i=0;i<firstIndex;i++){
                    newData[j]=data[i];
                    j++;
                }
                delete[] data;
                data = newData;
                firstIndex=0;
                nextIndex=capacity;
            }
            data[nextIndex]=element;
            nextIndex=(nextIndex+1)%capacity;
            if(firstIndex==-1){
                firstIndex=0;
            }
            size++;
        }

        T front(){
            if(isEmpty()){
                cout<<"Queue is empty!"<<endl;
                return 0;
            }
            return data[firstIndex];
        }

        T dequeue(){                //considering the queue to be circular
            if(isEmpty()){
                cout<<"Queue is empty!"<<endl;
                return 0;
            }

            T ans = data[firstIndex];
            firstIndex=(firstIndex+1)%capacity;
            size--;
            if(size==0){
                firstIndex=-1;
                nextIndex=0;
            }
            return ans;
        }
};

int main(){
    queue<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout<<q.front()<<endl;

    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    q.enqueue(70);
    q.enqueue(80);
    
    cout<<q.front()<<endl;

    cout<<q.getSize()<<endl;

    cout<<q.isEmpty()<<endl;
}