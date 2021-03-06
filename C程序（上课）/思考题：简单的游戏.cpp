/*

[思维] 简单的游戏
时间限制: 1 Sec  内存限制: 32 MB
提交: 878  解决: 165
[提交][状态][讨论版]
题目描述


    有一天MA和AD正在玩一个非常简单的游戏。首先，每个玩家选择一个从1到n的整数。假设MA选择了数字m，AD选择了数字a。
    然后由电脑随机生成一个整数c，其范围在1到n之间（任何从1到n的整数都以相同的概率被选中），这时候胜负就分出来了。赢家是选择的数字更接近c的玩家。 AD同意，如果m和a与c的差距相同，MA胜。
    AD很想赢，所以他要你帮助他。你知道MA选择的号码m，和范围上界n。 你需要确定AD选择哪个值，使得他赢的可能性是最大的。

    简单来说，你需要找到这样的整数a（1 ≤ a ≤ n），使得 |c - a| < |c - m| 概率的最大，其中c是从1到n（包括n）的等概率选择的整数。


输入


输入包括两个整数 n ， m (1?≤?m?≤?n?≤?109) ，分别代表在游戏中数的范围（从1到n） 和 MA选择的数字


输出


输出一个数a，使得AD胜的概率最大。如果存在多种可能，输出最小的一个。

样例输入

3 1

样例输出

2

提示



在测试样例中: 当c=2或3的时候 AD 会赢，选择 a = 2 它赢的概率为2 / 3，如果AD 选择 a?=?3, 它赢的概率为 1?/?3，如果选择 a?=?1, 它赢的概率为 0。

*/

#include<stdio.h>

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(n==1){
		n=1;
	}
	else if(n%2==0){
		if(m>n/2){
			n=m-1;
		}
		else{
			n=m+1;
		}
	}
	else{
		if(m>=(n+1)/2){
			n=m-1;
		}
		else{
			n=m+1;
		}
	}
	printf("%d\n",n);

}
