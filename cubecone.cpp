#include<iostream>
#include<cmath>
using namespace std;
#define pi 3.14
class shape{
    protected:
    int a,r,h;
    
    public:
    virtual int  area()=0;
    
    virtual int volume()=0;
    
};
class cube:public shape
{
    public:
    cube()
    {
        this->a=5;
    }
    cube(int n)
    {
        this->a=n;
    }
    int area()
    {
        return 6*a*a;
    }
    int volume()
    {
        return a*a*a;
    }
};
class cone:public shape
{
    public:
    cone()
    {
        this->r=5;
        this->h=5;
    }
    cone(int x,int y)
    {
        this->r=x;
        this->h=y;
    }
    int area()
    {
        int s,d;
        d=(r*r)+(h*h);
        s=sqrt(d);
        return pi*r*(r+s);
    }
    int volume()
    {
        return (pi*r*r*h)/3;
    }


};
int main()
{
   /* cube cu1(10);
    cone co1(10,10);
    cout<<"the area of cube is="<<cu1.area()<<" and volume is="<<cu1.volume()<<endl;
    cout<<"the area of cone is="<<co1.area()<<" and the volume is="<<co1.volume()<<endl;
    */
    shape *s1,*s2;
    cube cu1(10);
    cone co1(10,10);
    s1=&cu1;
    s2=&co1;
    cout<<"the area of cube is="<<s1->area()<<" and volume is="<<s1->volume()<<endl;
    cout<<"the area of cone is="<<s2->area()<<" and the volume is="<<s2->volume()<<endl;

    return 0;
}