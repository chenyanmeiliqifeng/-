//ѭ�����÷�ʽʵ��0-1��������Ķ�̬�滮�㷨
#include<stdio.h>
#include <iostream>     
#include <algorithm>  
using namespace std;  
  
#define N 3 // N������    
#define C 5 // C�Ǳ�������capacity    
  
int main()  
{  
    int value[N + 1] = { 0, 60, 100, 120 }; // ��ֵ    
    int weight[N + 1] = { 0, 1, 2, 3 };     // ����    
    int f[N + 1][C + 1] = { 0 };   // f[i][j]��ʾ�ڱ�������Ϊj������£�ǰi������������ֵ    
  
    int i = 1;  
    int j = 1;  
    for (i = 1; i <= N; i++)        //��ѭ��������Ʒ������ȷ��ÿ����Ʒ���ᱻ������  
    {  
        /*for (j = weight[i]; j <= C; j++)      //��ѭ��������Ʒ��������ȷ���ܹ�����������ǰÿ����Ʒ����ʱ������ֵf[i][j]�� 
        { 
            int x = f[i - 1][j];        //���ŵ�i����Ʒ 
            int y = f[i - 1][j - weight[i]] + value[i];      //�����i����Ʒ 
            f[i][j] = max(x, y); 
        }*/  
  
        for (j = 1; j <= C; j++)  
        {  
            // ���ƹ�ϵʽ    
            if (j < weight[i])  
            {  
                f[i][j] = f[i - 1][j];  
            }  
            else  
            {  
                int x = f[i - 1][j];  
                int y = f[i - 1][j - weight[i]] + value[i];  
                f[i][j] = max(x, y);  
            }  
        }  
    }  
  
    for (i = 0; i <= N; i++)  
    {  
        for (j = 0; j <= C; j++)  
        {  
            printf("%4d ", f[i][j]);  
        }  
  
        cout << endl;  
    }  
  
    cout << endl << "ѡȡ������ֵ�ǣ�" << f[N][C] << endl;  
    cout << "ѡȡ����Ʒ���£�" << endl;  
    i = N, j = C;  
    while (i)  
    {  
        if (f[i][j] == (f[i - 1][j - weight[i]] + value[i]))  
        {  
            cout << i << ":" << "weight=" << weight[i] << ", value=" << value[i] << endl;  
            j -= weight[i];  
        }  
        i--;  
    }  
  
    cout << endl;  
    return 0;  
}  
