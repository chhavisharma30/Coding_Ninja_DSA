/*Implement a polynomial class, with following properties and functions.
Properties :
1. An integer (lets say A) which holds the coefficient and degrees. Use array indices as degree and A[i] as coefficient of ith degree.
2. An integer holding total size of array A.
Functions :
1. Default constructor
2. Copy constructor
3. setCoefficient -
This function sets coefficient for a particular degree value. If the given degree is greater than the current capacity of polynomial, increase the capacity accordingly 
and add then set the required coefficient. If the degree is within limits, then previous coefficient value is replaced by given coefficient value
4. Overload "+" operator  (P3 = P1 + P2) :
Adds two polynomials and returns a new polynomial which has result.
5. Overload "-" operator  (P3 = p1 - p2) :
Subtracts two polynomials and returns a new polynomial which has result
6. Overload * operator (P3 = P1 * P2) :
Multiplies two polynomials and returns a new polynomial which has result
7. Overload "=" operator (Copy assignment operator) -
Assigns all values of one polynomial to other.
8. print() -
Prints all the terms (only terms with non zero coefficients are to be printed) in increasing order of degree.
Print pattern for a single term : \<coefficient>"x"\<degree>
And multiple terms should be printed separated by space. And after printing one polynomial, print new line. For more clarity, refer sample test cases
Input Format :
Line 1 : N, total number of terms in polynomial P1
Line 2 : N integers representing degree of P1 (separated by space)
Line 3 : N integers representing coefficients of P1 (separated by space)
Line 4 : M, total number of terms in polynomial P2
Line 5 : M integers representing degree of P2 (separated by space)
Line 6 : M integers representing coefficients of P2 (separated by space)
Line 7 : Integer C, choice representing the function to be called (See main for more details)
*/

#include <iostream>
using namespace std;

class Polynomial
{
    int *degcoeff;
    int capacity;

public:

    Polynomial(){
        degcoeff = new int[5];
        capacity=5;
        for(int i=0;i<capacity;i++){
            degcoeff[i]=0;
        }
    }

    Polynomial(Polynomial const& a){
        this->degcoeff=new int[a.capacity];
        for(int i=0;i<a.capacity;i++){
            this->degcoeff[i]=a.degcoeff[i];
        }
        this->capacity=a.capacity;
    }

    void operator=(Polynomial const& a){
        this->degcoeff=new int[a.capacity];
        for(int i=0;i<a.capacity;i++){
            this->degcoeff[i]=a.degcoeff[i];
        }
        this->capacity=a.capacity;
    }

    void setcoefficient(int index,int value){
        while(index>=capacity){
            int* newarray = new int[2*capacity];
            for(int i=0;i<capacity;i++){
                newarray[i]=degcoeff[i];
            }
            for(int j=capacity;j<2*capacity;j++){
                newarray[j]=0;
            }
            delete[] degcoeff;
            degcoeff = newarray;
            capacity *= 2;
        }
        degcoeff[index]=value;
    }

    Polynomial operator+(Polynomial& b){
        int Max= max(capacity,b.capacity);
        if(Max==capacity){
            for(int i=b.capacity;i<capacity;i++){
                b.setcoefficient(i,0);
            }
        }
        if(Max==b.capacity){
            for(int i=capacity;i<b.capacity;i++){
                setcoefficient(i,0);
            }
        }
        Polynomial c;
        for(int i=0;i<Max;i++){
            c.setcoefficient(i,degcoeff[i]+b.degcoeff[i]);
        }
        return c;
    }

    Polynomial operator-(Polynomial& b){
       int Max= max(capacity,b.capacity);
        if(Max==capacity){
            for(int i=b.capacity;i<capacity;i++){
                b.setcoefficient(i,0);
            }
        }
        if(Max==b.capacity){
            for(int i=capacity;i<b.capacity;i++){
                setcoefficient(i,0);
            }
        }
        Polynomial c;
        for(int i=0;i<Max;i++){
            c.setcoefficient(i,degcoeff[i]-b.degcoeff[i]);
        }
        return c; 
    }

    Polynomial operator*(Polynomial& b){
        Polynomial c;
        for(int i=0;i<capacity;i++){
            Polynomial p;
            for(int j=0;j<b.capacity;j++){
                p.setcoefficient(i+j,degcoeff[i]*b.degcoeff[j]);
            }
            c = c+p;
        }
        return c;
    }

    void print() const{
        int flag=0;
        for(int i=0;i<capacity;i++){
            if(degcoeff[i]!=0){
                cout<<degcoeff[i]<<"x"<<i<<" ";
                flag=1;
            }
        }
        if(flag==0){
            cout<<"0"<<endl;
        }
        cout<<endl;
    }
};

int main(){
    Polynomial p1;
    p1.setcoefficient(0,3);
    p1.setcoefficient(2,8);
    p1.setcoefficient(8,7);
    p1.setcoefficient(3,13);
    p1.print();

    Polynomial p2(p1);
    p2.print();

    Polynomial p3;
    p3=p1;
    p3.print();

    Polynomial p4;
    p4=p1*p2;
    p4.print();
}