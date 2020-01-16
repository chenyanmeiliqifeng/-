#include<bits/stdc++.h>
using namespace std;
 
///以第一个元素为标准，将小于他的元素放在之前，大于的放在之后，是快排的思想基础
int movel(int a[],int b,int e)  ///第一个和最后一个的下标
{
    int i=b,j=e,tmp;
    int pivot=a[b];
    while(i<j)
    {
        while(i<j && a[j]>pivot)
            j--;
        while(i<j && a[i]<=pivot)
            i++;
        if(i<j)
        {
            tmp=a[i];
            a[i]=a[j];
            a[j]=tmp;
        }
    }
    a[0]=a[j];
    a[j]=pivot;
    return i;
}
 
void quickSort(int a[],int b,int e)
{
    if(b>=e) return;   ///必须是大于等于，不能只等于，因为实际上当只剩俩个数时，i+1会越界，超过e
 
    else
    {
        int i=b,j=e,tmp;
        int pivot=a[b];
        while(i<j)
        {
            while(i<j && a[j]>pivot)
                j--;
            while(i<j && a[i]<=pivot)
                i++;
            if(i<j)
            {
                tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
        a[b]=a[j];
        a[j]=pivot;
        quickSort(a,b,i-1);
        quickSort(a,i+1,e);
    }
}
 
int main()
{
    int n;
    cin>>n;
    int *p=new int[n];
    for(int i=0; i<n; i++)
        scanf("%d",p+i);
    quickSort(p,0,n-1);
    printf("%d",p[0]);
    for(int i=1; i<n; i++)
        printf(" %d",p[i]);
    return 0;
}
