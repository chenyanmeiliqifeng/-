//三角形每边三个数，顶角的数共用，三条边的和相等，填入数字1-6。
#include<stdio.h>
int main()
{
	int a,b,c,d,e,f;
	for(a=1;a<=6;a++)
		for(b=1;b<=6;b++)
			{
				if(b==a)
					continue;
				for(c=1;c<=6;c++)
				{
					if((c==a)||(c==b))
						continue;
					for(d=1;d<=6;d++)
					{
						if((d==a)||(d==b)||(d==c))
							continue;
						for(e=1;e<=6;e++)
						{
							if((e==d)||(e==c)||(e==b)||(e==a))
								continue;
						f=21-(a+b+c+d+e);
						if((a+b+c==c+d+e)&&(a+b+c==a+f+e))
							printf("a=%d,b=%d,c=%d,d=%d,e=%d,f=%d\n",a,b,c,d,e,f);
						}
					}		
				}	
			}
			return 1;			
} 
