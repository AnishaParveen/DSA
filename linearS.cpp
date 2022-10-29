#include<iostream>
using namespace std;
int linear_search(int [],int ,int );
int main()
{
    int arr[10],n,key;
    cout<<"enter the size of array="<<endl;
    cin>>n;
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

    cout<<"enter the search element="<<endl;
    cin>>key;
    cout<<"key is present in index "<<linear_search(arr,n,key);
return 0;
}
int linear_search(int arr[],int size,int key)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==key)
            return i;
        
    }
    return -1;
}