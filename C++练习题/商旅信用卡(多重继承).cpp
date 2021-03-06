/*
商旅信用卡(多重继承)

题目描述
旅程会员卡，有会员卡号（int）、旅程积分（int），通过会员卡下订单，按订单金额累计旅程积分。
信用卡，有卡号（int）、姓名（string)、额度（int)、账单金额（float)、信用卡积分（int）------请注意数据类型
信用卡退款m，账单金额-m，信用卡积分减去退款金额。
初始假设信用卡积分、旅程积分、账单金额为0。
生成旅程信用卡对象，输入卡信息，调用对象成员函数完成旅程网下单、信用卡刷卡、
信用卡退款、信用卡积分兑换为旅程积分等操作。
根据上述内容，定义旅程会员卡类、信用卡类，从两者派生出旅程信用卡类
并定义三个类的构造函数和其它所需函数。
通过旅程信用卡在旅程网下单，旅程积分和信用卡积分双重积分
（即旅程积分和信用卡积分同时增加）。
旅程信用卡可以按      旅程积分：信用卡积分= 1：2    的比例将信用卡积分兑换为旅程积分。
信用卡消费金额m，若加已有账单金额超额度，则不做操作；否则，账单金额+m，
信用卡积分按消费金额累加。
某旅游网站（假设旅程网）和某银行推出旅游综合服务联名卡—旅程信用卡，
兼具旅程会员卡和银行信用卡功能。

输入
第一行：输入旅程会员卡号 信用卡号 姓名 额度
第二行：测试次数n
第三行到第n+2行，每行：操作 金额或积分
o   m（旅程网下订单，订单金额m） 
c   m（信用卡消费，消费金额m）
q   m (信用卡退款，退款金额m）
t    m（积分兑换，m信用卡积分兑换为旅程积分）

输出
输出所有操作后旅程信用卡的信息：
旅程号   旅程积分
信用卡号  姓名   账单金额   信用卡积分

样例输入
1000 2002  lili  3000
4
o 212.5
c 300
q 117.4
t 200

样例输出
1000 312
2002 lili 395.1 195

按题目要求定义旅程会员卡类CVip和信用卡类CCredit及其多重继承派生的旅程信用卡类CVipCredit,
包括构造函数、下订单、信用卡消费、信用卡退款、信用卡积分兑换等成员函数。
主函数输入数据、定义派生类对象并调用相应的成员函数实现程序的功能。

*/

#include<iostream>
#include<cstring>
using namespace std;

class CVip
{
	protected:
		int cardnum1;
		int jifen1;
	public:
		CVip(int a)
		{
			cardnum1 = a;
			jifen1 = 0;
		}
		void print()
		{
			cout<<cardnum1<<" "<<jifen1<<endl;
		}
};

class CCredit
{
	protected:
		int cardnum2;
		string name;
		int limit;
		float money;
		int jifen2;
	public:
	CCredit(int a,string b,int c)
	{
		cardnum2 = a;
		name = b;
		limit = c;
		money = 0;
		jifen2 = 0;
	}
	void print()
	{
		cout<<cardnum2<<" "<<name<<" "<<money<<" "<<jifen2<<endl;
	}
};

class CVipCredit:public CVip,public CCredit
{
	public:
		CVipCredit(int a,int b,string c,int d):CVip(a),CCredit(b,c,d){}
		void order(float a)
		{
			money += a;
			jifen1 += (int)a;
			jifen2 += (int)a;
		}
		void expense(float a)
		{
			if(a+money<=limit)
			{
				money += a;
				jifen2 += (int)a;
			}
		}
		void refund(float a)
		{
			money -= a;
			jifen2 -= (int)a;
		}
		void change(int a)
		{
			jifen2 -= a;
			jifen1 += a/2; 
		}
		void print()
		{
			CVip::print() ;
			CCredit::print() ;
		}
};

int main()
{
	int a,b,d,n,jifen;
	string c;
	char k;
	float money;
	cin>>a>>b>>c>>d;
	CVipCredit h(a,b,c,d);
	cin>>n;
	while(n--)
	{
		cin>>k;
		if(k=='o')
		{
			cin>>money;
			h.order(money) ;
		}
		if(k=='c')
		{
			cin>>money;
			h.expense(money); 
		}
		if(k=='q')
		{
			cin>>money;
			h.refund(money); 
		}
		if(k=='t')
		{
			cin>>jifen;
			h.change(jifen) ; 
		}
	}
	h.print() ;
}


