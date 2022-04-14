/*
按题目要求定义CXGraph类的++前缀后缀和--前缀后缀以及<<共5个运算符重载函数。
主函数参照题目给出的示例。

题目描述
X字母可以放大和缩小，变为n行X（n=1,3,5,7,9,...,21）。例如，3行x图案如下：

现假设一个n行（n>0，奇数）X图案，遥控器可以控制X图案的放大与缩小。
遥控器有5个按键，1）show，显示当前X图案；2）show++, 显示当前X图案，
再放大图案，n+2；3）++show，先放大图案，n+2，再显示图案；
4）show--，显示当前X图案，再缩小图案，n-2；5）--show，先缩小图案，n-2，
再显示图案。假设X图案的放大和缩小在1-21之间。n=1时，缩小不起作用，
n=21时，放大不起作用。

用类CXGraph表示X图案及其放大、缩小、显示。主函数模拟遥控器，
代码如下，不可修改。请补充CXGraph类的定义和实现。


输入
第一行n，大于0的奇数，X图案的初始大小。
第二行，操作次数
每个操作一行，为show、show++、show--、--show、++show之一，具体操作含义见题目。

输出
对每个操作，输出对应的X图案。
 
样例输入
3
5
show
show++
show++
++show
--show

样例输出
XXX
 X
XXX

XXX
 X
XXX

XXXXX
 XXX
  X
 XXX
XXXXX

XXXXXXXXX
 XXXXXXX
  XXXXX
   XXX
    X
   XXX
  XXXXX
 XXXXXXX
XXXXXXXXX

XXXXXXX
 XXXXX
  XXX
   X
  XXX
 XXXXX
XXXXXXX

*/

#include<iostream>
#include<cstring>
using namespace std;

class CXGraph
{
	private:
		int n;
	public:
		CXGraph(int n)
		{
			this->n = n;
		}
		CXGraph operator ++ (int)
		{
			CXGraph a(*this);
			if(n<21)
				n+=2;
			return a;
		}
		CXGraph &operator ++ ()
		{
			if(n<21)
				n+=2;
			return *this;
		}
		CXGraph operator -- (int)
		{
			CXGraph a(*this);
			if(n>1)
				n-=2;
			return a;
		}
		CXGraph &operator -- ()
		{
			if(n>1)
				n-=2;
			return *this;
		}
		friend ostream &operator << (ostream & out,const CXGraph & h)
		{
			int k,i,m,j;
			k=h.n/2+1;
			for(i=k;i>0;i--)
			{
				for(j=k-i;j>0;j--)
					cout<<" ";
				for(m=2*i-1;m>0;m--)		
					cout<<"X";
				cout<<endl;
			}
			
			for(i=2;i<=k;i++)
			{
				for(j=k-i;j>0;j--)
					cout<<" ";
				for(m=2*i-1;m>0;m--)
					cout<<"X";
				cout<<endl;
			}
			return out;
		}
};

int main()
{
	int t,n;
	string command;
	
	cin>>n;
	CXGraph xGraph(n);

	cin>>t;
	while(t--)
	{
		cin>>command;

		if(command=="show++")
			cout<<xGraph++<<endl;
		else if(command=="++show")
			cout<<++xGraph<<endl;
    	else if(command=="show--")
			cout<<xGraph--<<endl;
		else if(command=="--show")
			cout<<--xGraph<<endl;
		else if(command=="show")
			cout<<xGraph<<endl; 
	}
	return 0;
}


