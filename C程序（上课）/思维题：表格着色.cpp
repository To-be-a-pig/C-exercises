/*
表格着色

题目描述
Simon有一个由n行m列组成的矩形表格。我们将第x行和第y列的单元格表示为一对数字（x，y）。 表格角落的单元格是：（1,1），（n，1），（1，m），（n，m），他们分别是左上角，左下角，右上角，右下角。
Simon认为这张表格上的一些单元格是好的。 另外，我们假定表格的角落没有好的单元格。
一开始，表格中的所有单元都是无色的。 Simon想为他的表格上的所有单元格着色。他可以选择表格中的任意好的单元格(x1,?y1)，和表格的任意角落的点(x2,?y2) ，为表格（p，q）中的所有单元格着色，这两个单元格满足两个不等式：min(x1,?x2)?≤?p?≤?max(x1,?x2), min(y1,?y2)?≤?q?≤?max(y1,?y2)。
请你帮Simon找出为表格的所有单元格着色所需的最少操作次数。 请注意，你可以多次对同一个单元格着色。

输入
第一行包含两个整数n，m（3≤n，m≤50）。
接下来的n行包含表格单元的描述。第i行包含m个空格分隔的整数 ai1,?ai2,?...,?aim。好的单元格的值为1，坏的为0。 输入数据保证至少有一个单元格是好的，没有一个好的单元格位于角落。

输出
输入一个整数 - Simon实现他的想法所需最少的操作次数。

样例输入
3 3
0 0 0
0 1 0
0 0 0

样例输出
4

提示
在第一个样例中，操作的顺序可以是这样的：
首次需要选择单元格（2，2）和角落（1，1）。
第二次你需要选择单元格（2，2）和角落（3，3）。
第三次你需要选择单元格（2，2）和角落（3，1）。
第四次你需要选择单元格（2，2）和角落（1，3）。

-------------------------------

第二个测试样例：

输入：
4 3
0 0 0
0 0 1
1 0 0
0 0 0

输出：
2

在第二个样例中，操作的顺序可以是这样的：
第一次需要选择单元格（3,1）和角落（4,3）。
第二次需要选择单元格（2，3）和角落（1，1）。

*/

#include<stdio.h>

int main()
{
	int a[50][50],i,j,n,m,k1=0,k2=0,k3=0,k4=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(j=1;j<m-1;j++){   //上 
		if(a[0][j]==1){
			k1++;
			break;
		}
	}
	for(j=1;j<m-1;j++){ //下 
		if(a[n-1][j]==1){
			k2++;
			break;
		}
	}
	for(i=1;i<n-1;i++){   //左 
		if(a[i][0]==1){
			k3++;
			break;
		}
	}
	for(i=1;i<n-1;i++){ //右 
		if(a[i][m-1]==1){
			k4++;
			break;
		}
	}
	if(k1==0&&k2==0&&k3==0&&k4==0){
		printf("4\n");
	}
	else{
		printf("2\n");
	}
}
