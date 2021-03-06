/*
神奇的幻方(数组）

题目描述
幻方是一种很神奇的N*N矩阵：它由数字1,2,3,……,N*N构成，且每行、每列及两条对角线上的数字之和都相同。当N为奇数时，我们可以通过以下方法构建一个幻方：
首先将1写在第一行的中间。之后，按如下方式从小到大依次填写每个数K(K=2,3,…,N*N)：
1.若(K?1)在第一行但不在最后一列，则将K填在最后一行，(K?1)所在列的右一列；
2.若(K?1)在最后一列但不在第一行，则将K填在第一列，(K?1)所在行的上一行；3.若(K?1)在第一行最后一列，则将K填在(K?1)的正下方；
4.若(K?1)既不在第一行，也不在最后一列，如果(K?1)的右上方还未填数，则将K填在(K?1)的右上方，否则将K填在(K?1)的正下方。
现给定N请按上述方法构造N*N的幻方。

输入
输入文件只有一行，包含一个整数N即幻方的大小。(N为奇数，小于30)

输出
输出文件包含N行，每行N个整数，即按上述方法构造出的N*N的幻方。相邻两个整数之间用单个空格隔开。

样例输入
3

样例输出
8 1 6
3 5 7
4 9 2

*/

#include<stdio.h>

int main()
{
	int n,a[31][31],i,j,k=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			a[i][j]=0;
	i=1,j=(n+1)/2;
	a[i][j]=k;
	k++;
	while(k<n*n+1){
		if(i==1&&j!=n){
			i=n,j++;
			
		}
		else if(i!=1&&j==n){
			i--,j=1;
		}
		else if(i==1&&j==n){
			i++;
		}
		else if(i!=1&&j!=n){
			if(a[i-1][j+1]==0){
				i--,j++;
			}
			else{
				i++;
			}
		}
		
		a[i][j]=k;
		k++;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("%d\n",a[i][n]);
	}
}
