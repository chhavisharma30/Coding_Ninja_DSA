#include<iostream>
using namespace std;

class Vehicle{
    public:
    string color;

    virtual void print(){   
        cout<<"Vehicle"<<endl;
    }
    
};

class Car: public Vehicle{
    public:
    int numGears;

    void print(){
        cout<<"Car"<<endl; 
    }
};

int main(){
    Vehicle v;

    Car c;

    v.print();  //calls vehicle class print()
    c.print();  //calls car class print()

    Vehicle* v1 = new Vehicle;  //creating a vehicle object dynamically
    Vehicle* v2;    //Creating a Vehicle pointer
    //v2=&v;    Pointing v2 to v
    v2=&c;  //Base class pointer can point to child class object but vice versa is not allowed
    v2->print();    //It will call car print() as the function is virtual
    //If there is no print() in car class, it will call vehicle print()
    //If there is no print() in vehicle class , it will give error as the pointer can only access those properties which are present in vehicle class

    
}