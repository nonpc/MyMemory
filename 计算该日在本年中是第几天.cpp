//20.定义一个结构体变量(包括年,月,日)。计算该日在本年中是第几天，注意闰年问题
struct Days
{
	int year;
	int month;
	int day;
};
void Job1(Days day)
{
	int sum=0;
	switch(day.month)
	{
	case 1:
		sum=day.day;
		break;
	case 2:
		sum=day.day+31;
		break;
	case 3:
		sum=day.day+59;
		break;
	case 4:
		sum=day.day+90;
		break;
	case 5:
		sum=day.day+120;
		break;
	case 6:
		sum=day.day+151;
		break;
	case 7:
		sum=day.day+181;
		break;
	case 8:
		sum=day.day+212;
		break;
	case 9:
		sum=day.day+243;
		break;
	case 10:
		sum=day.day+273;
		break;
	case 11:
		sum=day.day+304;
		break;
	case 12:
		sum=day.day+334;
		break;
	}
	if((day.year%4==0&&day.year%100!=0)||day.year%400==0)//闰年的判断方法，能被4整除不能被100整除；能被400整除
	{
		sum++;
	}
	printf("%d月%d日是%d年的第%d天\n",day.month,day.day,day.year,sum);
}

int main()
{
	Days d={2018,11,3};
	Job1(d);
	return 0;
}