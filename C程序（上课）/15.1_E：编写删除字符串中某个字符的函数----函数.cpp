/*

编写删除字符串中某个字符的函数----函数
时间限制: 1 Sec  内存限制: 128 MB
提交: 1350  解决: 660
[提交][状态][讨论版]
题目描述


编制函数del_char

函数原型为 void del_char(char *,char),函数的功能是删除a指向的字符串中值为ch的字符，例如从字符串"AscADef"中删除'A'后，字符串为"scDef"。


输入


需要删除的字符ch

需要处理的字符串


输出


处理后的字符串


样例输入

A
AscADef

样例输出

scDef
*/

#include<stdio.h>
#include<string.h>

void del_char(char* a,char b)
{
	char c[100];
	int l=strlen(a),i,j=0;
	for(i=0;i<l;i++){
		if(a[i]==b){
			j++;
		}else{
			c[i-j]=a[i];
		}
	}
	c[i-j]='\0';
	strcpy(a,c);
}

int main()
{
	char *a=new char[100];
	char b;
	scanf("%c\n",&b);
	gets(a);
	del_char(a,b);
	printf("%s\n",a);
}
