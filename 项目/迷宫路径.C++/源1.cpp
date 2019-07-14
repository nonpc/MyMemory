#include<iostream>
using namespace std;
#if 0
/*
用OOP完成迷宫路径的寻找问题，软件运行要求如下：
请输入迷宫的行列数： 5 5
请输入迷宫路径节点信息（1表示不能走，0表示能走）
0 0 1 0 1
0 0 1 0 0
1 0 0 1 0
0 1 0 0 0
开始寻找迷宫路径（从左上角到右下角的一个可通行的路径）:
迷宫不存在可通行的路径
* * 1 0 1
0 * 1 0 0
1 * * 1 0
0 1 * * *
*/
const int WAY_CNT = 4;   // 总的方向数目
const int WAY_RIGHT = 0;
const int WAY_DOWN = 1;
const int WAY_LEFT = 2;
const int WAY_UP = 3;

const int WAY_STATE_OK = 5; // 路径方向可以行走
const int WAY_STATE_ERR = 6;  // 路径方向不能行走

class MazeNode  // 迷宫节点类型
{
public:
	MazeNode()
	{
		_val = 0;
		for(int i = 0; i < WAY_CNT;i++)
		{
			_state[i] = WAY_STATE_OK;
		}
	}
	MazeNode(int x ,int y,int val = 0)
	{
		_x = x;
		_y = y;
		_val = val;
		for(int i = 0; i < WAY_CNT;i++)
		{
			_state[i] = WAY_STATE_OK;
		}
	}
	void addVal(int x,int y,int val)
	{
		_x = x;
		_y = y;
		_val = val;
	}
	int GetVal()
	{
		return _val;
	}
	void addState(int a,int data)
	{
		_state[a] =  data;
	}
	int GetState(int a)
	{
		return _state[a];
	}
	int GetX()
	{
		return _x;
	}
	int GetY()
	{
		return _y;
	}
	void setVal(char a)
	{
		_val = (int)a;
	}
private:
	int _val;
	int _x;
	int _y;
	int _state[WAY_CNT];//记录状态信息,周围四个方向,行走的状态
};
class CSeqtack  // 栈类型
{
public:
	CSeqtack(int size = 10)
	{
		_top = 0;
		_size = size;
		_stack = new MazeNode[_size];
	}
	~CSeqtack()
	{
		delete []_stack;
	}
	void Push(MazeNode &data)
	{
		if(Full())
		{
			MazeNode *tmp = new MazeNode[2*_size];
			for(int i = 0; i < _size;i++)
			{
				tmp[i].addVal(_stack[i].GetX(),_stack[i].GetY(),_stack[i].GetVal()) ;
			}
			delete []_stack;
			_stack = tmp;
			_size *= 2;
		}
		_stack[_top++].addVal(data.GetX(),data.GetY(),data.GetVal());
	}
	void Pop()
	{
		if(Empty())
		{
			throw "栈为空!";
		}
		_top--;
	}
	MazeNode Top()
	{
		if(Empty())
		{
			throw "栈为空!";
		}
		return _stack[_top-1];
	}
	bool Full()
	{
		return _top == _size;
	}
	bool Empty()
	{
		return _top == 0;
	}
private:
	MazeNode *_stack;
	int _top;
	int _size;
};
class Maze  // 迷宫类型
{
public:
	Maze(int r = 10, int c = 10):_row(r),_col(c)
	{
		_pMazes = new MazeNode*[_row];
		for(int i = 0; i < _row;i++)
		{
			_pMazes[i] = new MazeNode[_col];
		}
	}
	void initMazeNode(int i,int j,int data)
	{
		_pMazes[i][j].addVal(i,j,data);
	}
	void adjustMazeNode()//调整迷宫节点方向的行走状态
	{
		for(int i = 0; i < _row;i++)
		{
			for(int j = 0; j < _col;j++)
			{
				//边界值的设定
				if(i == 0)   //最上面一行
				{
					_pMazes[i][j].addState(WAY_UP,WAY_STATE_ERR);
				}
				if(j == 0)   //最左面一行
				{
					_pMazes[i][j].addState(WAY_LEFT,WAY_STATE_ERR);
				}
				if(i == (_row-1))   //最下面一行
				{
					_pMazes[i][j].addState(WAY_DOWN,WAY_STATE_ERR);
				}
				if(j == (_col - 1))   //最右面一行
				{
					_pMazes[i][j].addState(WAY_RIGHT,WAY_STATE_ERR);
				}
				//非边界值的设定
				if(j < (_col-1) && _pMazes[i][j+1].GetVal() == 1)  //右
				{
					_pMazes[i][j].addState(WAY_RIGHT,WAY_STATE_ERR);
				}
				if(i < (_row-1) && _pMazes[i+1][j].GetVal() == 1)  //下
				{
					_pMazes[i][j].addState(WAY_DOWN,WAY_STATE_ERR);
				}
				if(j > 0 && _pMazes[i][j-1].GetVal() == 1)             //左
				{
					_pMazes[i][j].addState(WAY_LEFT,WAY_STATE_ERR);
				}
				if(i > 0 && _pMazes[i-1][j].GetVal() == 1)            //上
				{
					_pMazes[i][j].addState(WAY_UP,WAY_STATE_ERR);
				}
			}
		}
	}
	void findMazePath()// 开始寻找迷宫路径
	{
		if(_pMazes[0][0].GetVal() == 1)
		{
			return;
		}
		_stack.Push(_pMazes[0][0]);
		while (!_stack.Empty())
		{
			MazeNode node = _stack.Top();
			int x = node.GetX();
			int y = node.GetY();
			if (x == _row - 1 && y == _col - 1) //出口
			{
				return;
			}
			if(_pMazes[x][y].GetState(WAY_RIGHT) == WAY_STATE_OK)
			{
				_pMazes[x][y].addState(WAY_RIGHT,WAY_STATE_ERR);
				_pMazes[x][y+1].addState(WAY_LEFT,WAY_STATE_ERR);
				y++;
				_stack.Push(_pMazes[x][y]);
				continue;
			}
			 if(_pMazes[x][y].GetState(WAY_DOWN) == WAY_STATE_OK)
			{
				_pMazes[x][y].addState(WAY_DOWN,WAY_STATE_ERR);
				_pMazes[x+1][y].addState(WAY_UP,WAY_STATE_ERR);
				x++;
				_stack.Push(_pMazes[x][y]);
				continue;
			}
			 if(_pMazes[x][y].GetState(WAY_LEFT) == WAY_STATE_OK)
			{
				_pMazes[x][y].addState(WAY_LEFT,WAY_STATE_ERR);
				_pMazes[x][y-1].addState(WAY_RIGHT,WAY_STATE_ERR);
				y--;
				_stack.Push(_pMazes[x][y]);
				continue;
			}
			 if(_pMazes[x][y].GetState(WAY_UP) == WAY_STATE_OK)
			{
				_pMazes[x][y].addState(WAY_UP,WAY_STATE_ERR);
				_pMazes[x-1][y].addState(WAY_DOWN,WAY_STATE_ERR);
				x--;
				_stack.Push(_pMazes[x][y]);
				continue;
			}

			 _stack.Pop();
		}
	}
	void showMazePath()
	{
		if(_stack.Empty())
		{
			cout<<"迷宫不存在可通行的路径!"<<endl;
			return;
		}
		while(!_stack.Empty())
		{
			MazeNode top = _stack.Top();
			_pMazes[top.GetX()][top.GetY()].setVal('*');
			_stack.Pop();
		}
		cout<<"============="<<endl;
		cout<<"迷宫路径为:"<<endl;
		for(int i = 0;i < _row;i++)
		{
			for(int j = 0; j < _col;j++)
			{
				if(_pMazes[i][j].GetVal() == '*')
				{
					cout<<"*"<<" ";
				}
				else
				{
					cout<<_pMazes[i][j].GetVal()<<" ";
				}
			}
			cout<<endl;
		}
	}
private:
	int _row;
	int _col;
	MazeNode **_pMazes;
	CSeqtack _stack;
};
int main()
{
	cout << "请输入迷宫的行列数:";
	int row, col;
	cin >> row >> col;

	Maze maze(row, col);

	cout << "请输入迷宫路径节点信息（1表示不能走，0表示能走）:" << endl;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			int data;
			cin >> data;
			maze.initMazeNode(i, j, data);
		}
	}

	// 调整迷宫节点方向的行走状态
	maze.adjustMazeNode();
	// 开始寻找迷宫路径
	maze.findMazePath();
	// 打印迷宫寻找的结果
	maze.showMazePath();
	return 0;
}
#endif
