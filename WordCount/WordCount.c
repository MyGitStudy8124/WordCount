#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int CountChar() //��дһ��ͳ��txt�ļ��ַ����ĺ���//
{
	int count1 = 0; //�ַ�����//
	FILE* fp = fopen("test.txt", "r");  //���ļ���//
	if (!fp)
	{
		printf("file read is error");
		exit(0);
	}
	while (1) //ʹ��whileѭ����ȡ�ļ��е��ַ����Ҽ���//
	{
		fgetc(fp); //ʹ��fgetc()������ȡָ��fpָ����ļ��е��ַ�//
		if (feof(fp)) //ʹ��feof()�����ж�ָ���Ƿ񵽴��ļ�ĩβ//
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
	int count2 = 0; //���ʼ���//
	char buf[255]; //�������fscanf��ȡ������//
	char ch;
	FILE* fp = fopen("test.txt", "r");  //���ļ���//
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
	while ((opt = getopt(argc, argv, "c:w:")) != -1)  //ʹ�ÿ⺯�����������в���// 
	{
		switch(opt)         //c w ��Ӧ�������// 
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
	if(c) //c ����� ��ӡ�ַ���// 
	{
		a=CountChar();
		printf("�ַ�����%d\n",a);
	}
	if(w)  // w ����� ��ӡ������// 
	{
		b=CountWord();
		printf("��������%d\n",b);
	}
}
