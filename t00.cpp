#include <bits/stdc++.h>
using namespace std;

map<int,string> Map;

class Subject
{
    public:
        Subject(int num,int m,int n,int b[4],int k,int x)  //
        {
            memcpy(a,b,4*sizeof(int));
            subject_num = num;
            max_num = m;
            sign_num = n;
            brackets = k;
            decimal = x;

        }

        string sign()     //随机选择运算符
        {
            while(1)
            {
                int i=rand()%4;
                if(a[i])
                {
                    return Map[i];
                }
            }
        }
        string get_num()      //随机产生数字
        {
            stringstream n;
            if(decimal)
            {
                n<<rand()%(max_num*100)/double(100);
            }
            else
            {
                n<<rand()%max_num+1;
            }
            return n.str();
        }
        void output(char t[])         // 输出到文件
        {

            ofstream out(t);
            if(!out)        //
                cout<<"error"<<endl;
            stringstream s;
            int i,j,flag=0,count=0;
            for(i=0;i<subject_num;i++)  //生成运算式
            {

                for(flag=0,count=0,j=0;j<sign_num;j++)
                {


                    if(brackets&&rand()%4==0)    //有括号&&将随机概率设为1/4
                    {
                        s<<"(";
                        flag=1;         //左括号"("后有数字
                        count++;        //左括号"("个数
                    }
                    s<<get_num();
                    if(count&&flag==0&&rand()%3==0)    //已有左括号"("&&前面为符号加数字&&将随机概率设为1/3
                    {
                        s<<")";
                        count--;
                    }
                    else
                        flag=0;
                    s<<sign();
                }
                s<<get_num();

                while(count!=0)         //有未匹配左括号"("
                {
                    s<<")";
                    count--;
                }
                out<<s.str()<<"=\n";
                s.str("");
            }

            out.close();
            cout<<t<<"文件已生成。"<<endl;
        }


    private:
        int subject_num,max_num,sign_num,brackets,decimal;        //题目数量，最大数,运算符数量 //括号，小数
        int a[4];           //选择运算符

};



int main()
{
    srand((unsigned)time(NULL));

    Map[0]="+";Map[1]="-";Map[2]="*";Map[3]="/";    //运算符
    int n,m,k,a[4],i,j;
    char t[100];
    cout<<"请输入题目数量：";
    cin>>n;
    cout<<"请设置最大数：";
    cin>>m;
    cout<<"请设置运算符数量：";
    cin>>k;
    cout<<"是否有加号（0/1）：";
    cin>>a[0];
    cout<<"是否有减号（0/1）：";
    cin>>a[1];
    cout<<"是否有除号（0/1）：";
    cin>>a[2];
    cout<<"是否有乘号（0/1）：";
    cin>>a[3];
    cout<<"是否有括号（0/1）：";
    cin>>i;
    cout<<"是否有小数（0/1）：";
    cin>>j;
    Subject s(n,m,k,a,i,j);
    cout<<"请输入生成文件名：";
    cin>>t;
    s.output(t);
    return 0;

}
