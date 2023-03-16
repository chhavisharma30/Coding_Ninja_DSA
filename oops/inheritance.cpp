#include<iostream>
using namespace std;

class Vehicle{
    private:
    int maxSpeed;
    protected:
    int numTyres;
    public:
    string color;

    Vehicle(){
        cout<<"Vehicle constuctor called!"<<endl;
    }

    Vehicle(int z){
        cout<<"Vehicle parametrized constructor called!"<<endl;
    }

    ~Vehicle(){
        cout<<"Vehicle destructor called!"<<endl;
    }
};

class Car : public Vehicle{
    public:
    int numGears;

    Car(int x):Vehicle(x){
        cout<<"Car constructor called!"<<endl;
    }

    ~Car(){
        cout<<"Car destructor called!"<<endl;
    }

    void print(){
        cout<<"numTyres : "<<numTyres<<endl;
        cout<<"color : "<<color<<endl;
        cout<<"numGears : "<<numGears<<endl;
        //cout<<"maxSpeed : "<<maxSpeed<<endl;      We can't accesss it as private members are not inherited!
    }
};

int main(){
    Vehicle v;
    v.color="blue";
    //v.numTyres = 4;       Protected properties are only accessible in the child class
    //v.axSpeed = 150;      Private properties are not accessible outside the class
    
    Car c(5);
    c.color="black";
    c.numGears=5;
    //c.numTyres=4;         Protected properties are only accessible in derived class

}