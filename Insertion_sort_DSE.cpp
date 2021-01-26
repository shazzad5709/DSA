#include <iostream>
using namespace std;

int main()
{
    int a[100], n, i, t, j;
    
    cin>>n;
    for(i=0; i<n; i++)
        cin>>a[i];

    for(i=1; i<n; i++)
    {
        t=a[i];
        j=i-1;
        while(j>=0 && a[j]>t)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=t;
    }
    
    cout<<"Sorted Elements: ";
    for(i=0; i<n; i++)
        cout<<a[i]<<" ";
}