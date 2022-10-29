#include<iostream>
using namespace std;
int binary_search(int [],int ,int);
int main()
{

    int arr[10],n,key;
    cout<<"enter the size of array="<<endl;
    cin>>n;
    cout<<"enter the sorted elements="<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"the  sorted elements are="<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<",";
    }
    cout<<endl;

    cout<<"enter the search element="<<endl;
    cin>>key;
    cout<<"key is present in index "<<binary_search(arr,n,key);

    return 0;
}
int binary_search(int arr[],int size,int key)
{
    int s=0;
    int e=size;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(arr[mid]==key)
           return mid;
        else if(arr[mid]>key)
        {
            e=mid-1;

        }
        else
        s=mid+1;
    }
    return -1;
}
