#include<iostream>
using namespace std;

class Vehicle{
    public:
    string color;

    virtual void print()=0;
    
};

class Car: public Vehicle{      //this class will also become abstract if it doesnt implement all pure virtual fns of base class
    public:
    int numGears;

    void print(){
        cout<<"Car"<<endl; 
    }
};

int main(){
    //Vehicle v;    We cnt create object of abstract class

    Car c;

    
}