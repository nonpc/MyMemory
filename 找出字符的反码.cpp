//61.找出字符的反码
/*
1)背景说明：一个二进制数,将其每一位取反,称之为这个数的反码。
下面我们定义一个字符的反码。如果这是一个小写字符，
则它和字符'a'的距离与它的反码和字符'z'的距离相同;如果是一个大写字符，则它和字符'A’的，
距离与它的反码和字符'Z’的距离相同;如果不是.上面两种情况,它的反码就是它自身。
比如A的反码是Z，d的反码是w.
一个字符串的反码定义为其所有字符的反码。我们的任务就是计算出给定字符串的反码。
2)解题思路：字符有两种情况，在26个英文字母之内时，
按照公式：反码='Z'-( 字符-'A');去计算它的反码即可。如果不是英文字母，则它的反码是它本身。
*/
void Fun(char k)//求字符的反码
{
	char n = 0;
	if(k >= 'A' && k <= 'Z')
	{
		n = 'Z'-(k-'A');
		printf("字符%c的反码为:%c\n",k,n);
		return;
	}
	if(k >= 'a' && k <= 'z')
	{
		n = 'z'-(k-'a');
		printf("字符%c的反码为:%c\n",k,n);
		return;
	}
	printf("字符%c的反码为:%c\n",k,k);
	return;
}
void Fun1(char *arr,int len)//求字符串的反码
{
	assert(arr != NULL);
	char *brr = (char *)malloc(sizeof(char)*len);
	int i = 0;
	for(int i = 0; i< len ;i++)
	{
		if(arr[i] >= 'A' && arr[i] <= 'Z')
		{
			brr[i] = 'Z'-(arr[i]-'A');
			continue;
		}
		if(arr[i] >= 'a' && arr[i] <= 'z')
		{
			brr[i] = 'z'-(arr[i]-'a');
			continue;
		}
		brr[i] = arr[i];
	}
	printf("字符串的反码为:%s\n",brr);
	free(brr);
}

int main()
{
	char k = 'A';
	char k1 = 'd';
	Fun(k);
	printf("==================\n");
	Fun(k1);
	printf("==================\n");
	char arr[] = "sajdhAHKJFDHsjdhSDHjfhdf";
	int len = sizeof(arr)/sizeof(arr[0]);
	Fun1(arr,len);
	return 0;
}
