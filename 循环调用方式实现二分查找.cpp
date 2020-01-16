//iteration循环、迭代 
#include<stdio.h> 
#include<algorithm>
using namespace std; 
int binarySearch(int a[],int length,int k)
{
    int start=0;
    int end=length-1;
    while(start<=end)
	{
        int mid=start+(end-start)/2;
        if(a[mid]==k)
		 return mid;
        else if(a[mid]>k)
		{
            end = mid-1;
        }
		else
		{
            start = mid+1;
        }
    }
    return -1;
}
int main()
{
	int N,T[N];
	printf("请输入一组数组T[N]:\n");
	while(scanf("%d",&N)!=EOF)
	{
		for(int i=0;i<N;i++)
		scanf("%d",&T[i]);
		sort(T,T+N);
		int x;
		while(scanf("%d",&x))
		{
			if(x==1)
			break;
			printf("%d\n",binarySearch(T,N-1,x));
		}
	}
	return 0;
}
