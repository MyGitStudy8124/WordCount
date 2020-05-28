#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int CountChar() //编写一个统计txt文件字符数的函数//
{
	int count1 = 0; //字符计数//
	FILE* fp = fopen("test.txt", "r");  //将文件打开//
	if (!fp)
	{
		printf("file read is error");
		exit(0);
	}
	while (1) //使用while循环读取文件中的字符并且计数//
	{
		fgetc(fp); //使用fgetc()函数读取指针fp指向的文件中的字符//
		if (feof(fp)) //使用feof()函数判断指针是否到达文件末尾//
		{
			break;
		}
		count1++;
	}
	fclose(fp);
	return count1;
}
int CountWord()
{
	int count2 = 0; //单词计数//
	char buf[255]; //用来存放fscanf读取的数据//
	char ch;
	FILE* fp = fopen("test.txt", "r");  //将文件打开//
	if (!fp)
	{
		printf("file read is error");
		exit(0);
	}
	while (fscanf(fp,"%s",buf)!=EOF)
	{
		count2++;
	}
	fclose(fp);
	return count2;
}
int main(int argc, char* argv[])
{
	int a;
	int b;
	int opt = 0;
	int c = 0;
	int w = 0;
	char s[50];
	while ((opt = getopt(argc, argv, "c:w:")) != -1)  //使用库函数解析命令行参数// 
	{
		switch(opt)         //c w 对应两种情况// 
		{
			case 'c':      
					c=1;
					strcpy(s,optarg);
					break;
			case 'w':
					w=1;
					strcpy(s,optarg);
					break;
		}
	}
	if(c) //c 情况下 打印字符数// 
	{
		a=CountChar();
		printf("字符数：%d\n",a);
	}
	if(w)  // w 情况下 打印单词数// 
	{
		b=CountWord();
		printf("单词数：%d\n",b);
	}
}
