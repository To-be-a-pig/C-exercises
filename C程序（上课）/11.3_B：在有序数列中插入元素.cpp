/*
在有序数列中插入元素

题目描述
已有一个已排好的9个元素的数组，
今输入一个数要求按原来排序的规律将它插入数组中。

输入
第一行，原始数列。 第二行，需要插入的数字。

输出
排序后的数列

样例输入
1 7 8 17 23 24 59 62 101
50

样例输出
1
7
8
17
23
24
50
59
62
101

*/

#include<stdio.h>

int main()
{
	int a[9],i,k,j;
	for(i=0;i<9;i++)
		scanf("%d",&a[i]);
	scanf("%d",&k);
	for(i=0;i<8;i++){
		if((a[i]<=k&&a[i+1]>=k)||(a[i]>=k&&a[i+1]<=k)){
			break;
		}
	}
	for(j=0;j<=i;j++){
		printf("%d\n",a[j]);
	}
	printf("%d\n",k);
	for(;j<9;j++){
		printf("%d\n",a[j]);
	}
}
