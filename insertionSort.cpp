#include<iostream>
using namespace std;
void swap(int&,int&);
void insertion_sort(int[],int);
int main()
{
    int n,arr[20];
    cout<<"enter the size of the array="<<endl;
    cin>>n;
    cout<<"enter the elements to be sorted="<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"the elements are="<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<",";
    }
    cout<<endl;
    insertion_sort(arr,n);
    cout<<" after sorting the elements are="<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<",";
    }
    cout<<endl;

    return 0;
}
void swap(int &a,int &b)
{
    int tmp;
    tmp=a;
    a=b;
    b=tmp;
}
void insertion_sort(int arr[],int n)
{
    for(int j=0;j<n;j++)
    {
        int min=j;
        
        for(int i=j+1;i<n;i++)
        {
            if(arr[min]>arr[i])
            min=i;
        }
        if(j!=min)
        swap(arr[j],arr[min]);
    }
    
}