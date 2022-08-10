#include<iostream>
using namespace std;

//basic template syntax
template <typename T>

class Pair{
    T x;
    T y;

    public:
    void setX(T x){
        this->x = x;
    }

    void setY(T y){
        this->y = y;
    }

    T getX(){
        return x;
    }

    T getY(){
        return y;
    }

};

int main(){
    Pair<int> p1;
    p1. setX(10);
    p1.setY(30);
    cout<<p1.getX()<<" "<<p1.getY()<<endl;

    Pair<double> p2;
    p2. setX(10.6);
    p2.setY(30.8);
    cout<<p2.getX()<<" "<<p2.getY()<<endl;
}