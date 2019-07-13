//60.约瑟夫问题
/*
约瑟夫问题 :着名犹太历史学家 Josephus有过以下的故事：在罗马人占领乔塔帕特后，39 个犹太人
与Josephus及他的朋友躲到一个洞中，39个犹太人决定宁愿死也不要被敌人到，于是决定了一个自杀方式，
41个人排成一个圆圈，由第1个人 开始报数，每报数到第3人该人就必须自杀， 然后再由下一个重新报数，
直到所有人都自杀身亡为止。然而Josephus 和他的朋友并不想遵从，Josephus要他的朋友先假装遵从，
他将朋友与自己安排 在第16个与第31个位置，于是逃过了这场死亡游戏。 
现将这个问题扩大，假设现在你与m个朋友不幸参与了这个游戏，你要如何保护你与你的朋友？

解题思路:将他们看成是一个环,每走三个,将要死的人标记,直到剩余人数是自己和朋友的总和.
需要注意第一轮末尾,要将下标置为队首下标.
还要注意第二轮及以后要略过已经标记的下标,同时还要考虑掠过的下标是不是队末,如果是还需置为队首
*/

void Fun(int people,int friends)
{
	int count = 0;
	int i = 0;   
	bool tmp[42] = {false};  //舍弃0号下标的元素
	while(people != 0)
	{
		count++;
		i++;
		if(tmp[i] == true) //第二轮开始遇到第一轮标记过的,直接跳过
		{
			if(i == 41) //第n轮被标记后会直接略过,不能回到开头 
			{
				i = 0;
			}
			count--;
			continue;
		}
		if(count == 3 )
		{
			people--;
			tmp[i] = true;
			count = 0;
			if(people == friends+1)
			{
				break;
			}
		}
		if(i == 41)//第一轮完成后 回到开头 
		{
			i = 0;
		}
		
	}
	printf("安全的位置为:\n");
	for(int j = 1; j < 42;j++)
	{
		if(tmp[j] == false)
		{
			printf("%d ",j);
		}
	}
	printf("\n");
}

int main()
{
	int people = 41;
	int friends = 1;
	Fun(people,friends);

	return 0;
}
