#include<stdio.h>
#include<assert.h>


//31.��һ���ַ����г�ȥ���ڵĿո�
void Deblank(char *string)
{
	assert(*string != NULL);
	char *pb = string;
	char *pe = string;
	while(*pe != '\0')
	{
		if(*pe == ' ' && *pe++ == ' ')//�����ո��жϺ����Ƿ��пո���pb��һ����׼������     (pe++)�����޸ĳ�pe+1
		{
			pb++;
		}
		while(!isalpha(*pe))//���˶��ڿո�
		{
			pe++;
		}
		*pb = *pe;//����
		pe++;
		pb++;
	}
	*pb = '\0';
}


int main()
{
	char arr[] = "abc         bcd                 def      dg";
	Deblank(arr);
	printf("%s\n",arr);

	return 0;
}


//��һ�ַ���:����ǰ���пո�
void Deblank(char *string)
{
	assert(*string != NULL);
	char *pb = string;
	char *pe = string;
	while(!(isalpha(*pe)))
	{
		pe++;
		pb++;
	}
	while(*pe != '\0')
	{
		if(*pe == ' ' && *(pe+1) == ' ')//�����ո��жϺ����Ƿ��пո���pb��һ����׼������
		{
			pb++;
		}
		while(!isalpha(*pe) )//���˶��ڿո�
		{
			if(*pe == '\0')//ĩβ�пո�
			{
				*(pb-1) = '\0';
				return ;
			}
			pe++;
		}
		*pb = *pe;//����
		pe++;
		pb++;
	}
	*pb = '\0';
}


int main()
{
	char arr[] = "       abc         bcd                 def      dg         ";
	Deblank(arr);
	printf("%s\n",arr);

	return 0;
}