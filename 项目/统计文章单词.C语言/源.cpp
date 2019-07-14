#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<string.h>
#include<ctype.h>
#include <time.h>
#define SIZE 5000000

/*
���̡���δ��ʼ����ջ�ռ䣬���͡��������δ�����ڴ������COPY�Ķ��ڴ档
*/
typedef struct Word
{
	char arr[40];
	int count;//��ǰ���ʸ���
}Word;//�洢ÿ������

typedef struct Num
{
	Word *brr;//ָ��ĳһ�����ʵĽṹ��
	int length;
	int listsize;
}N;//��������

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

char* GetWord(const char *path,char *str,int len)//���ļ��������ڴ���
{
	//assert(path!=NULL);
	FILE *fr=fopen(path,"r");
	//assert(fr!=NULL);
	//fseek(fr,0,SEEK_END);
	//int len=ftell(fr);//�ú�������λ�ñ�ʶ���ĵ�ǰֵ��
	//char *str=(char *)malloc(len*sizeof(char));
	//fseek(fr,0,SEEK_SET);//����
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

int Length(Num num)//ͳ���ܵ��ʸ���
{
	return num.length;
}

Num WriteWords(const char*str,Num num)//���ڴ��еĵ���д��ṹ��
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

Num SumWords(Num num,int many)//ͳ�Ƶ��ʳ��ָ���
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

Num Sort(Num num,int many)//����ð��
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


Num QuickSort(Num num,int left,int right)//����
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

void Search(Num num ,int many,char *sch)//����
{
	printf("���������\n");
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
	clock_t start,finish;//��¼��������ʱ��
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
	//Sort(num,many);//ð������
	QuickSort(num,0,many-1);//��������
	Show(num,many);
	printf("�ܵ��ʸ���Ϊ:%d\n",many);
	//printf("=====================\n");
	//char sch[]="Harry";
	//printf("��������Ϊ��%s\n",sch);
	//Search(num,many,sch);//���ʼ���
	free(num.brr);


	finish=clock();//��¼��������ʱ��
	totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
 	printf("\n�������е�ʱ��Ϊ: %.5f ��",totaltime);

	return 0;
}
