#include<iostream>
using namespace std;

class Bus{
    public:
    void print();
};

void test();

class Truck{
    private:
    int x;
    protected:
    int y;
    public:
    int z;

    friend void Bus::print();
    friend void test();
};

void Bus::print(){
    Truck t;
    t.x=1;
    t.y=2;
    cout<<t.x<<" "<<t.y<<endl;
}

void test(){
    Truck t;
    t.x=1;
    t.y=2;
    cout<<t.x<<" "<<t.y<<endl;
}

int main(){
    Bus b;
    b.print();
    test();
}