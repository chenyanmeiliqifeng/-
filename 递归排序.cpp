#include<bits/stdc++.h>
using namespace std;
 
///�Ե�һ��Ԫ��Ϊ��׼����С������Ԫ�ط���֮ǰ�����ڵķ���֮���ǿ��ŵ�˼�����
int movel(int a[],int b,int e)  ///��һ�������һ�����±�
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
    if(b>=e) return;   ///�����Ǵ��ڵ��ڣ�����ֻ���ڣ���Ϊʵ���ϵ�ֻʣ������ʱ��i+1��Խ�磬����e
 
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
