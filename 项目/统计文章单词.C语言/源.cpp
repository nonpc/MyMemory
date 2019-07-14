#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<string.h>
#include<ctype.h>
#include <time.h>
#define SIZE 5000000

/*
“烫”是未初始化的栈空间，“屯”是申请后未做过内存清零或COPY的堆内存。
*/
typedef struct Word
{
	char arr[40];
	int count;//当前单词个数
}Word;//存储每个单词

typedef struct Num
{
	Word *brr;//指向某一个单词的结构体
	int length;
	int listsize;
}N;//单词总量

int Len(const char *path)
{
	assert(path!=NULL);
	FILE *fr=fopen(path,"r");
	assert(fr!=NULL);
	fseek(fr,0,SEEK_END);
	int len=ftell(fr);
	fclose(fr);
	return len+1;
}

char* GetWord(const char *path,char *str,int len)//将文件保存在内存中
{
	//assert(path!=NULL);
	FILE *fr=fopen(path,"r");
	//assert(fr!=NULL);
	//fseek(fr,0,SEEK_END);
	//int len=ftell(fr);//该函数返回位置标识符的当前值。
	//char *str=(char *)malloc(len*sizeof(char));
	//fseek(fr,0,SEEK_SET);//重置
	//fread(str,len,1,fr);
	//*(str+len+1)='\0';

	fseek(fr,0,SEEK_SET);
	for(int i=0;i<len;i++)
	{
		*str=fgetc(fr);
		//printf("%c",*str);
		str++;
	}
	/*do
	{
		*str=fgetc(fr);
		printf("%c",*str);
		str++;
	}
	while(*str!=EOF);*/
	//str++;
	*str='\0';
	fclose(fr);
	return str;
}

int Length(Num num)//统计总单词个数
{
	return num.length;
}

Num WriteWords(const char*str,Num num)//将内存中的单词写入结构体
{
	assert(*str!=NULL);
	int i=0;
	int j=0;
	bool flag=false;
	while(*str!='\0')
	{
		if((*str>=65&&*str<=90)||(*str>=97&&*str<=122)||*str=='\'')
		{
			num.brr[i].arr[j]=*str;
			j++;
			str++;
			flag=true;
		}
		else
		{
			if(flag)
			{
				num.brr[i].count=1;
				num.brr[i].arr[j]='\0';
				i++;
				num.length++;
				j=0;
				flag=false;
			}
			str++;
		}
	}
	return num;
}

Num SumWords(Num num,int many)//统计单词出现个数
{
	for(int i=0;i,i<many;i++)
	{
		for(int j=i+1;j<many;j++)
		{
			if(num.brr[i].count==0)
			{
				break;
			}
			if(!strcmp(num.brr[i].arr,num.brr[j].arr))
			{
				num.brr[i].count++;
				num.brr[j].count=0;
			}
		}
	}
	return num;
}

void Show(Num num,int many)
{
	for(int i=0;i<many;i++)
	{
		if(num.brr[i].count==0)
		{
			continue;
		}
		printf("%s",num.brr[i].arr);
		printf("  %d\n",num.brr[i].count);
	}
}

Num Sort(Num num,int many)//排序冒泡
{
	/*int temp;
	char temp2[40];*/
	Word temp;
	for(int j=0;j<many;j++)
	{
		for(int i=0;i<many-j;i++)
		{
			if(num.brr[i].count<num.brr[i+1].count)
			{
				temp=num.brr[i];
				num.brr[i]=num.brr[i+1];
				num.brr[i+1]=temp;

				/*temp=num.brr[i].count;
				strcpy(temp2,num.brr[i].arr);	
				num.brr[i].count=num.brr[i+1].count;
				strcpy(num.brr[i].arr,num.brr[i+1].arr);
				num.brr[i+1].count=temp;
				strcpy(num.brr[i+1].arr,temp2);	*/
			}
		}	
	}
	return num;
}


Num QuickSort(Num num,int left,int right)//快排
{
	int f;
	Word t;
	int rtemp,ltemp;
	ltemp=left;
	rtemp=right;
	f=num.brr[(ltemp+rtemp)/2].count;
	while(ltemp<rtemp)
	{
		while (num.brr[ltemp].count<f)
		{
			++ltemp;
		}
		while (num.brr[rtemp].count>f)
		{
			--rtemp;
		}
		if(ltemp<=rtemp)
		{
			t=num.brr[ltemp];
			num.brr[ltemp]=num.brr[rtemp];
			num.brr[rtemp]=t;
			--rtemp;
			++ltemp;
		}
	}
	if(ltemp==rtemp)
	{
		ltemp++;
	}
	if(left<rtemp)
	{
		QuickSort(num,left,ltemp-1);
	}
	if(ltemp<right)
	{
		QuickSort(num,rtemp+1,right);
	}
	return num;
}

void Search(Num num ,int many,char *sch)//检索
{
	printf("检索结果：\n");
	for(int i=0;i<many;i++)
	{
		if(num.brr[i].count==0)
		{
			continue;
		}
		if(!strcmp(num.brr[i].arr,sch))
		{
			printf("%s   %d",num.brr[i].arr,num.brr[i].count);
		}
	}
}

int main()
{
	clock_t start,finish;//记录程序运行时间
    double totaltime;
    start=clock();


	const char *path="E:\\1.txt";
	//const char *str=GetWord(path);
	int len=Len(path);
	char *str=(char *)malloc(len*sizeof(char));
	GetWord(path,str,len);
	Num num;
	num.length=0;
	num.brr=(Word*)malloc(SIZE*sizeof(Word));
	num = WriteWords(str,num);
	int many=Length(num);
	SumWords(num,many);
	//Sort(num,many);//冒泡排序
	QuickSort(num,0,many-1);//快速排序
	Show(num,many);
	printf("总单词个数为:%d\n",many);
	//printf("=====================\n");
	//char sch[]="Harry";
	//printf("检索单词为：%s\n",sch);
	//Search(num,many,sch);//单词检索
	free(num.brr);


	finish=clock();//记录程序运行时间
	totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
 	printf("\n程序运行的时间为: %.5f 秒",totaltime);

	return 0;
}
