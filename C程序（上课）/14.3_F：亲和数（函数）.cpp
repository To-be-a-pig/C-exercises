/*
亲和数（函数）

题目描述
古希腊数学家毕达哥拉斯在自然数研究中发现，220的所有真约数(即不是自身的约数)之和为： 
1+2+4+5+10+11+20+22+44+55+110＝284。 
而284的所有真约数为1、2、4、71、 142，加起来恰好为220。人们对这样的数感到很惊奇，并称之为亲和数。一般地讲，如果两个数中任何一个数都是另一个数的真约数之和，则这两个数就是亲和数。 
编写一个函数，判断给定的两个数是否是亲和数。

输入
测试次数t
每组测试数据一行，包含两个整数A、B； 其中 0 <= A,B <= 600000 ;

输出
对于每组测试实例，如果A和B是亲和数的话输出YES，否则输出NO。

样例输入
3
220 284
28 28
10000 3000

样例输出
YES
NO
NO
*/

#include<stdio.h>
#include<math.h>

int findtotal(int a)
{
	int i,j,total=0;
	for(i=1;i<=a/2;i++){
		if(a%i==0){
			total+=i;
		}
	}
	return total;
}

int main()
{
	int t,a,b,i;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&a,&b);
		if(a==b){
			printf("NO\n");
		}
		else if(findtotal(a)==b&&findtotal(b)==a){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
}
