#include <iostream>
#include <algorithm>
using namespace std;
struct bag
{
    int weight;//总重量
    int value;//总价值
    float bi;//单位重量的价值
    float rate;//使用率：1代表完整放入，小于1代表被分割后放入
} bags[50];
bool compare(const bag &bag1,const bag &bag2)
{
    return  bag1.bi>bag2.bi;
}
int main()
{
    int sum=0,n;
    float M;
    int j=0;
    cout<<"输入背包容量和物品数量："<<endl;
    cin>>M>>n;
    for(int i=0; i<n; i++)
    {
        cin>>bags[i].weight>>bags[i].value;//录入物品重量和价值。
        bags[i].bi=(float)bags[i].value/bags[i].weight;//计算单位重量价值。
        bags[i].rate=0;//初始化每件物品使用率。
    }
    sort(bags,bags+n,compare);//将物品按照单位重量价值由大到小排序
    for(j=0; j<n; j++)
    {
        if(bags[j].weight<=M)
        {
            bags[j].rate=1;
            sum+=bags[j].weight;
            M-=bags[j].weight;
            cout<<"重："<<bags[j].weight<<"价值："<<bags[j].value<<"的物品被放入了背包"<<endl<<"放入比例:"<<bags[j].rate<<endl;
        }
        else break;
    }
    if(j<n)
    {
        bags[j].rate=M/bags[j].weight;
        sum+=bags[j].rate*bags[j].weight;
        cout<<"重："<<bags[j].weight<<"价值："<<bags[j].value<<"被放入了背包"<<endl<<"放入比例:"<<bags[j].rate<<endl;
    }

    return 0;
}
