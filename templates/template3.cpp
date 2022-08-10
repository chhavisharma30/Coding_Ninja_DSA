#include<iostream>
using namespace std;

template <typename T, typename V>

class Pair{
    T x;
    V y;

    public:
    void setX(T x){
        this->x = x;
    }

    void setY(V y){
        this->y = y;
    }

    T getX(){
        return x;
    }

    V getY(){
        return y;
    }

};

int main(){
    Pair<Pair<int,double>,char> p1;             //nesting template objects
    Pair<int,double> p2;
    p2.setX(12);
    p2.setY(2.9);
    p1. setX(p2);
    p1.setY('t');
    cout<<p1.getX().getX()<<" "<<p1.getX().getY()<<" "<<p1.getY()<<endl;
}