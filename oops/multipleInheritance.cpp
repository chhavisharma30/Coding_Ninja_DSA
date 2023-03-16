#include<iostream>
using namespace std;

class Teacher{
    string name;
    string age;

    public:
    void print(){
        cout<<"teacher"<<endl;
    }
};

class Student{
    public:
    void print(){
        cout<<"student"<<endl;
    }
};

class TA : public Teacher,public Student{

};

int main(){
    TA a;

    //a.print();        This will give error as print function is in both parent classes so we don't know which one to access
    //If print() was present in TA class, that fn will be executed without any error
    a.Teacher::print();     //It will execute Teacher class' print function
  
}