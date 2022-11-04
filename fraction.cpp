#include<iostream>
using namespace std;
int findlcm(int a,int b);
int gcd(int a,int b);
class fraction{
    int numeretor,denominator;
    public:
    fraction();
    fraction(int n,int d);
    fraction  minimization();
    void display();
    friend fraction operator+(fraction f1,fraction f2);
    friend fraction operator-(fraction f1,fraction f2);
    friend fraction operator*(fraction f1,fraction f2);
    friend bool operator==(fraction f1,fraction f2);
    fraction operator=(fraction f1);
    fraction operator+=(fraction f1);
    fraction operator-=(fraction f1);
    fraction operator*=(fraction f1);
    friend istream& operator>>(istream &in,fraction &f);
    friend ostream& operator<<(ostream &out,const fraction &f);
    
};
int findlcm(int a,int b)
{
    return (a/gcd(a,b)) * b;
}
int gcd(int a,int b)
{
    if(b!=0)
        return gcd(b,a%b);
    return a;
}
fraction::fraction()
{
    numeretor=1;
    denominator=1;
}
fraction::fraction(int n,int d)
{
    numeretor=n;
    denominator=d;
}
fraction fraction::minimization()
{
    int a=gcd(this->numeretor,this->denominator);
    this->numeretor=this->numeretor/a;
    this->denominator=this->denominator/a;
    return *this;

}

istream& operator>>(istream &in,fraction &f)
{
	cout<<"enter numeretor and denominator="<<endl;
    in>>f.numeretor>>f.denominator;
    return in;
}
ostream& operator<<(ostream &out,const fraction &f)
{
    out<<f.numeretor<<"/"<<f.denominator<<endl;
    return out;
}
fraction operator+(fraction f1,fraction f2)
{
    fraction f3;
    f3.denominator=findlcm(f1.denominator,f2.denominator);
    f3.numeretor=((f3.denominator/f1.denominator)*f1.numeretor)+((f3.denominator/f2.denominator)*f2.numeretor);
    f3.minimization();
    return f3;
}
fraction operator-(fraction f1,fraction f2)
{
    fraction f3;
    f3.denominator=findlcm(f1.denominator,f2.denominator);
    f3.numeretor=((f3.denominator/f1.denominator)*f1.numeretor)-((f3.denominator/f2.denominator)*f2.numeretor);
    f3.minimization();
    return f3;
}
fraction operator*(fraction f1,fraction f2)
{
    fraction f3;
    f3.numeretor=f1.numeretor*f2.numeretor;
    f3.denominator=f1.denominator*f2.denominator;
    f3.minimization();
    return f3;
}
bool operator==(fraction f1,fraction f2)
{
    f1.minimization();
    f2.minimization();
    if(f1.numeretor==f2.numeretor && f1.denominator==f2.denominator)
      return true;
    return false;

}
fraction fraction::operator=(fraction f1)
{
    this->numeretor=f1.numeretor;
    this->denominator=f1.denominator;
    return *this;
}
fraction fraction::operator+=(fraction f1)
{
    int lcm=findlcm(this->denominator,f1.denominator);
    this->numeretor=((lcm/this->denominator)*this->numeretor)+((lcm/f1.denominator)*f1.numeretor);
    this->denominator=lcm;
    this->minimization();
    return *this;
}
fraction fraction ::operator-=(fraction f1)
{
    int lcm=findlcm(this->denominator,f1.denominator);
    this->numeretor=((lcm/this->denominator)*this->numeretor)-((lcm/f1.denominator)*f1.numeretor);
    this->denominator=lcm;
    this->minimization();
    return *this;
}
fraction fraction ::operator*=(fraction f1)
{
    this->numeretor=this->numeretor*f1.numeretor;
    this->denominator=this->denominator*f1.denominator;
    this->minimization();
    return *this;
}


int main()
{	fraction f4,f5,a,b,c,d,e;
    fraction f1(4,8);
    fraction f2(2,16);
    fraction f3(5,10);
    cin>>f4>>f5;
    
    a=f1+f2;
    b=f1-f2;
    c=f1*f2;
    d=a;
    f3*=f2;
    f4+=f1;
    f5-=f2;
    cout<<a<<b<<c<<d<<f3<<f4<<f4;
   
    return 0;

}
