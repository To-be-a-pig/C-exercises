/*
数组求同（数组）

题目描述
输入两个数组（数组元素个数6和8），
输出在两个数组中都出现的元素（如a[6]={2,3,4,5,6,7},
b[8]={3,5,7,9,11,13,15,19},则输出3、5、7）。


样例输入
2 3 4 5 6 7
3 5 7 9 11 13 15 19

样例输出
3
5
7

*/

#include<stdio.h>

int main(){
	int i,j,k,a[6],b[8];
	for(i=0;i<6;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<8;i++){
		scanf("%d",&b[i]);
	}
	for(i=0;i<6;i++){
		for(j=0;j<8;j++){
			if(a[i]==b[j]){
				printf("%d\n",a[i]);
				break;
			}
		}
	}
}
