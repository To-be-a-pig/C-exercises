/*

字符衔接

题目描述
已知两个字符串，
把第一个字符串的头3个字符和第二个字符串的末尾3个字符合并成一个新字符串

输入
第一行输入T表示有T个测试实例
第二行输入第1个字符串，设定字符串只包含字母或数字，长度大于3
第三行输入第2个字符串，设定字符串只包含字母或数字，长度大于3
以此类推输入下个实例

输出
每行输出合并后新的字符串

样例输入
2
china1949
szu1983
2012year
day14

样例输出
chi983
201y14

*/

#include<stdio.h>
#include<string.h>

int main()
{
	int t,i,j;
	scanf("%d",&t);
	while(t--){
		char a[100],b[100],c[7];
		scanf("%s",&a);
		scanf("%s",&b);
		for(i=0;i<3;i++){
			c[i]=a[i];
		}
		int lb=strlen(b);
		for(j=lb-3;j<lb;j++){
			c[i]=b[j];
			i++;
		}
		printf("%s\n",c);
	}
}
