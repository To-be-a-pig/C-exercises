/*
数字检查（数组）

题目描述
通过键盘输入n（n<50）个4位数（输入-1时结束），
统计这n个4位数中各位上的数字均是偶数的数的个数，
并把这些4位数按照从小到大的顺序进行输出。

输入
输入n个四位数，输入-1时结束。

输出
n个数字中每一位均为偶数的数字的数量
按从小到大的顺序输出这些数字

样例输入
2422
8496
0001
0000
-1

样例输出
2
0000
2422

*/

#include<stdio.h>

int main()
{
	int k[50],w[50],a,b,c,d,i,j,m=0,n=0;
	while(1){
		scanf("%d",&k[m]);
		if(k[m]==-1)
			break;
		a=k[m]/1000;
		b=k[m]%1000/100;
		c=k[m]%100/10;
		d=k[m]%10;
		if(a%2==0&&b%2==0&&c%2==0&&d%2==0){
			w[n]=k[m];
			n++;
		}
		m++;
	}
	
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1;j++){
			if(w[j]>w[j+1]){
				a=w[j];
				w[j]=w[j+1];
				w[j+1]=a;
			} 
		}
	}
	
	printf("%d\n",n);
	for(i=0;i<n;i++){
		printf("%d%d%d%d\n",w[i]/1000,w[i]%1000/100,w[i]%100/10,w[i]%10);
	}
	return 0;
}


