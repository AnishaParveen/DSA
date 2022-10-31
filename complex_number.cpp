#include<iostream>
using namespace std;
class complex{
    int real,imag;
    public:
    complex();
    complex(int r,int i);
     friend complex operator+(complex c1 ,complex c2);
     friend complex operator-(complex c1,complex c2);
     friend complex operator*(complex c1,complex c2);
     friend bool operator==(complex c1,complex c2);
    void output()
    {
        cout<<this->real<<"+"<<this->imag<<"i"<<endl;
    }
    
};
complex:: complex()
{
     real=0;
    imag=0;
}
complex ::complex (int r,int i)
{
    real=r;
    imag=i;
}
complex operator+(complex c1 ,complex c2)
{
    complex c3;
    c3.real=c1.real+c2.real;
    c3.imag=c1.imag+c2.imag;
    return c3;
}
complex  operator-(complex c1 ,complex c2)
{
    complex c3;
    c3.real=c1.real-c2.real;
    c3.imag=c1.imag-c2.imag;
    return c3;
}
complex  operator*(complex c1 ,complex c2)
{
    complex c3;
    c3.real=(c1.real*c2.real)-(c1.imag*c2.imag);
    c3.imag=(c1.real*c2.imag)+ (c1.imag*c2.real);
    return c3;
}
bool  operator==(complex c1,complex c2)
{
    if(c1.real==c2.real && c1.imag==c2.imag)
        return true;
    return false;
}

int main()
{
    complex c1(3,4);
    complex c2(1,4);
    complex c3,c4,c5;
    c3=c1+c2;
    c4=c1-c2;
    c5=c1*c2;
    c3.output();
    c4.output();
    c5.output();
    if(c1==c2)
        cout<<"numbers are equal";
    return 0;

}