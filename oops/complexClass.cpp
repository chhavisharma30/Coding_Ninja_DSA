/*A ComplexNumber class contains two data members : one is the real part (R) and the other is imaginary (I) (both integers).
Implement the Complex numbers class that contains following functions -
1. constructor
You need to create the appropriate constructor.
2. plus -
This function adds two given complex numbers and updates the first complex number.
e.g.
if C1 = 4 + i5 and C2 = 3 +i1
C1.plus(C2) results in: 
C1 = 7 + i6 and C2 = 3 + i1

3. multiply -
This function multiplies two given complex numbers and updates the first complex number.
e.g.
if C1 = 4 + i5 and C2 = 1 + i2
C1.multiply(C2) results in: 
C1 = -6 + i13 and C2 = 1 + i2

4. print -
This function prints the given complex number in the following format :
a + ib*/
#include<iostream>
using namespace std;

class ComplexNumbers{
    int r,i;
    public:

        ComplexNumbers(){

        }

        ComplexNumbers(int r,int i){
            this->r=r;
            this->i = i;
        }

        void plus(ComplexNumbers const &x){
            r = r + x.r;
            i = i + x.i;
        }

        void multiply(ComplexNumbers const &x){
            ComplexNumbers temp;
            temp.r = r*x.r - i*x.i;
            temp.i = r*x.i + i*x.r;

            r = temp.r;
            i=temp.i;
        }

        void print(){
            cout<<r<<" + "<<i<<"i"<<endl;
        }
};

int main(){
    int r1,i1,r2,i2;
    cin>>r1>>i1>>r2>>i2;
    ComplexNumbers c1(r1,i1);
    ComplexNumbers c2(r2,i2);

    int choice;
    cin>>choice;

    if(choice==1){
        c1.plus(c2);
        c1.print();
    }

    if(choice==2){
        c1.multiply(c2);
        c1.print();
    }
}