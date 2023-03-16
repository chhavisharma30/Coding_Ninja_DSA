//To eliminate the ambiguity, we use the virtual keyword

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

    void print(){
        cout<<"Vehicle"<<endl;
    }

    Vehicle(int z){
        cout<<"Vehicle parametrized constructor called!"<<endl;
    }

    ~Vehicle(){
        cout<<"Vehicle destructor called!"<<endl;
    }
};

class Car :virtual public Vehicle{
    public:
    int numGears;

    Car(){
        cout<<"Car constructor called!"<<endl;
    }

    ~Car(){
        cout<<"Car destructor called!"<<endl;
    }

    /*
    void print(){
        cout<<"numTyres : "<<numTyres<<endl;
        cout<<"color : "<<color<<endl;
        cout<<"numGears : "<<numGears<<endl;
        //cout<<"maxSpeed : "<<maxSpeed<<endl;      We can't accesss it as private members are not inherited!
    }
    */
};

class Truck:virtual public Vehicle{
    public:

    Truck(){
        cout<<"Truck constructor called!"<<endl;
    }
};

class Bus: public Car, public Truck{
    public:

    Bus(){
        cout<<"Bus constructor called!"<<endl;
    }
};

int main(){
    Bus  b;
    //b.print();        This statement is ambiguous because Bus class has two copies of Vehicle class' properties
    //It can be resolved using scope resolution operator
    b.Car::print();     //if Car class has its own print() then it will be executed instead of vehicle's print()
}