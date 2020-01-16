//循环调用方式实现0-1背包问题的动态规划算法
#include<stdio.h>
#include <iostream>     
#include <algorithm>  
using namespace std;  
  
#define N 3 // N件宝贝    
#define C 5 // C是背包的总capacity    
  
int main()  
{  
    int value[N + 1] = { 0, 60, 100, 120 }; // 价值    
    int weight[N + 1] = { 0, 1, 2, 3 };     // 重量    
    int f[N + 1][C + 1] = { 0 };   // f[i][j]表示在背包容量为j的情况下，前i件宝贝的最大价值    
  
    int i = 1;  
    int j = 1;  
    for (i = 1; i <= N; i++)        //外循环控制物品数量，确保每个物品都会被遍历到  
    {  
        /*for (j = weight[i]; j <= C; j++)      //内循环控制物品的重量，确保能够遍历出“以前每个物品放入时的最大价值f[i][j]” 
        { 
            int x = f[i - 1][j];        //不放第i件物品 
            int y = f[i - 1][j - weight[i]] + value[i];      //放入第i件物品 
            f[i][j] = max(x, y); 
        }*/  
  
        for (j = 1; j <= C; j++)  
        {  
            // 递推关系式    
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
  
    cout << endl << "选取的最大价值是：" << f[N][C] << endl;  
    cout << "选取的物品如下：" << endl;  
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
