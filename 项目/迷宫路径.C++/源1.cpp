#include<iostream>
using namespace std;
#if 0
/*
��OOP����Թ�·����Ѱ�����⣬�������Ҫ�����£�
�������Թ����������� 5 5
�������Թ�·���ڵ���Ϣ��1��ʾ�����ߣ�0��ʾ���ߣ�
0 0 1 0 1
0 0 1 0 0
1 0 0 1 0
0 1 0 0 0
��ʼѰ���Թ�·���������Ͻǵ����½ǵ�һ����ͨ�е�·����:
�Թ������ڿ�ͨ�е�·��
* * 1 0 1
0 * 1 0 0
1 * * 1 0
0 1 * * *
*/
const int WAY_CNT = 4;   // �ܵķ�����Ŀ
const int WAY_RIGHT = 0;
const int WAY_DOWN = 1;
const int WAY_LEFT = 2;
const int WAY_UP = 3;

const int WAY_STATE_OK = 5; // ·�������������
const int WAY_STATE_ERR = 6;  // ·������������

class MazeNode  // �Թ��ڵ�����
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
	int _state[WAY_CNT];//��¼״̬��Ϣ,��Χ�ĸ�����,���ߵ�״̬
};
class CSeqtack  // ջ����
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
			throw "ջΪ��!";
		}
		_top--;
	}
	MazeNode Top()
	{
		if(Empty())
		{
			throw "ջΪ��!";
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
class Maze  // �Թ�����
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
	void adjustMazeNode()//�����Թ��ڵ㷽�������״̬
	{
		for(int i = 0; i < _row;i++)
		{
			for(int j = 0; j < _col;j++)
			{
				//�߽�ֵ���趨
				if(i == 0)   //������һ��
				{
					_pMazes[i][j].addState(WAY_UP,WAY_STATE_ERR);
				}
				if(j == 0)   //������һ��
				{
					_pMazes[i][j].addState(WAY_LEFT,WAY_STATE_ERR);
				}
				if(i == (_row-1))   //������һ��
				{
					_pMazes[i][j].addState(WAY_DOWN,WAY_STATE_ERR);
				}
				if(j == (_col - 1))   //������һ��
				{
					_pMazes[i][j].addState(WAY_RIGHT,WAY_STATE_ERR);
				}
				//�Ǳ߽�ֵ���趨
				if(j < (_col-1) && _pMazes[i][j+1].GetVal() == 1)  //��
				{
					_pMazes[i][j].addState(WAY_RIGHT,WAY_STATE_ERR);
				}
				if(i < (_row-1) && _pMazes[i+1][j].GetVal() == 1)  //��
				{
					_pMazes[i][j].addState(WAY_DOWN,WAY_STATE_ERR);
				}
				if(j > 0 && _pMazes[i][j-1].GetVal() == 1)             //��
				{
					_pMazes[i][j].addState(WAY_LEFT,WAY_STATE_ERR);
				}
				if(i > 0 && _pMazes[i-1][j].GetVal() == 1)            //��
				{
					_pMazes[i][j].addState(WAY_UP,WAY_STATE_ERR);
				}
			}
		}
	}
	void findMazePath()// ��ʼѰ���Թ�·��
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
			if (x == _row - 1 && y == _col - 1) //����
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
			cout<<"�Թ������ڿ�ͨ�е�·��!"<<endl;
			return;
		}
		while(!_stack.Empty())
		{
			MazeNode top = _stack.Top();
			_pMazes[top.GetX()][top.GetY()].setVal('*');
			_stack.Pop();
		}
		cout<<"============="<<endl;
		cout<<"�Թ�·��Ϊ:"<<endl;
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
	cout << "�������Թ���������:";
	int row, col;
	cin >> row >> col;

	Maze maze(row, col);

	cout << "�������Թ�·���ڵ���Ϣ��1��ʾ�����ߣ�0��ʾ���ߣ�:" << endl;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			int data;
			cin >> data;
			maze.initMazeNode(i, j, data);
		}
	}

	// �����Թ��ڵ㷽�������״̬
	maze.adjustMazeNode();
	// ��ʼѰ���Թ�·��
	maze.findMazePath();
	// ��ӡ�Թ�Ѱ�ҵĽ��
	maze.showMazePath();
	return 0;
}
#endif
