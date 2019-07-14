#include<iostream>
#include<cassert>
#include<cstring>
#include<cstdlib>
using namespace std;

/*
OOP实现一个简单的图书馆书籍管理
角色：
学生   ：  查询书籍   查看自己已经借阅的书籍   
管理员 ：  查询书籍   借书   还书    借阅历史 

实体：  人    书    借阅信息
*/
//===================人员信息定义=======================
//权限信息定义
const int AUTH_STUDENT = 0; // 学生权限
const int AUTH_MANAGER = 1; // 管理员权限
const int AUTH_INVLAID = 2; // 无效权限
const int NAME_LEN = 20;
const int SEX_LEN = 5;
const int PWD_LEN = 20;

// 用户类
class CUser
{
public:
	void addnID(int id)
	{
		mID = id;
	}
	void addName(char *name)
	{
		assert(name != NULL);
		strcpy(mName,name);
	}
	void addage(int age)
	{
		mage = age;
	}
	void addSex(char *sex)
	{
		assert(sex != NULL);
		strcpy(msex,sex);
	}
	void addAuth(int auth)
	{
		mAuth = auth;
	}
	void addPassword(char* pwd)
	{
		assert(pwd != NULL);
		strcpy(mPassword,pwd);
	}
	int reID()
	{
		return mID;
	}
	char* reNmae()
	{
		return mName;
	}
	int reAge()
	{
		return mage;
	}
	char* reSex()
	{
		return msex;
	}
	int reAuth()
	{
		return mAuth;
	}
	char* rePassword()
	{
		return mPassword;
	}
private:
	int mID;
	char mName[NAME_LEN];
	int mage;
	char msex[SEX_LEN];
	int mAuth;
	char mPassword[PWD_LEN];
};
// 用户数据库类
class CUserDB
{
public:
	CUserDB(int size=10)
	{
		pUserArr = new CUser[size];
		mSize = size;
		mIndex = 0;
	}
	~CUserDB()
	{
		delete []pUserArr;
		pUserArr = NULL;
	}
	// 添加用户信息
	void addUser(const CUser &user)
	{
		if(mIndex > mSize)
		{
			CUser *tmp = new CUser[2*mSize];
			for(int i = 0; i < mIndex;i++)
			{
				tmp[i] = pUserArr[i];
			}
			delete []pUserArr;
			pUserArr = tmp;
			mSize *= 2;
		}
		pUserArr[mIndex++] = user;
		/*pUserArr[mIndex].addnID(user.reID());
		pUserArr[mIndex].addName(user.reNmae());
		pUserArr[mIndex].addage (user.reAge());
		pUserArr[mIndex].addSex(user.reSex());
		pUserArr[mIndex].addAuth(user.reAuth());
		pUserArr[mIndex].addPassword(user.rePassword());
		mIndex++;*/
	}
	// 检查用户登录权限
	int checkUser(char *name, char *pwd)
	{
		for(int i = 0;i < mIndex;i++)
		{
			if(!strcmp(pUserArr[i].reNmae(),name))
			{
				if(!strcmp(pUserArr[i].rePassword(),pwd))
				{
					return pUserArr[i].reAuth();
				}
			}
		}
		return AUTH_INVLAID;//无效权限
	}
private:
	CUser *pUserArr;
	int mSize;
	int mIndex;
};
//===================书籍信息定义=======================
const int BOOK_NAME_LEN = 50;
const int BOOK_NUM = 100;
// 书籍类型定义
class CBook
{
public:
	int getISBN()
	{
		return mISBN; 
	}
	char* getName()
	{
		return mName;
	}
	int getAmount()
	{
		return mAmount;
	}
	void addISBN(int isbn)
	{
		mISBN = isbn;
	}
	void addName(char* name)
	{
		assert(name != NULL);
		strcpy(mName,name);
	}
	void addAmount(int amount)
	{
		mAmount = amount;
	}
	void ChangeISBN(int n)
	{
		mISBN = n;
	}
	void ChangeAmount(int n)
	{
		mAmount = n;
	}
	void ChangeName(char *name)
	{
		assert(name != NULL);
		strcpy(mName,name);
	}
	void show()
	{
		cout<<"编号"<<"    "<<"书名"<<"   "<<"数量"<<endl;
		cout<<mISBN<<"   "<<mName<<"    "<< mAmount<<endl;
	}
private:
	int mISBN;
	char mName[BOOK_NAME_LEN];
	int mAmount;
};
// 书籍的DB定义
class CBookDB
{
public:
	CBookDB()
	{
		mIndex = 0;
	}
	// 添加书籍
	void addBook(const CBook &book) 
	{
		/*if(mIndex < 0)
		{
			mIndex = 0;
		}*/
		mBookArr[mIndex++] = book;
	}
	// 删除书籍
	void delBook(int isbn)
	{
		for (int i = 0; i < mIndex; ++i)
		{
			if (isbn == mBookArr[i].getISBN())
			{
				if(mBookArr[i].getAmount() > 1)
				{
					mBookArr[i].ChangeAmount(mBookArr[i].getAmount() - 1);
				}
				else
				{
					mBookArr[i].ChangeAmount(0);
					mBookArr[i].ChangeISBN(0);
				}
			}
		}
	}
	// 更新书籍册数
	void updateBookNumber(int isbn, int amount)
	{
		for(int i = 0;i < mIndex;i++)
		{
			if (isbn == mBookArr[i].getISBN())
			{	
				mBookArr[i].ChangeAmount(amount);
			}
		}
	}
	CBook* queryBook(char *name)
	{
		assert(name != NULL);
		for(int i = 0;i < mIndex;i++)
		{
			if(!strcmp(mBookArr[i].getName(),name))
			{
				return &mBookArr[i];
			}
		}
		return NULL;
	}
private:
	CBook mBookArr[BOOK_NUM];
	int mIndex;
};
//====================借阅信息定义=====================
class CDate
{
public:
	CDate(int y=0, int m=0, int d=0)
	{
		mYear = y;
		mMonth = m;
		mDay = d;
	}
	void addDate(int y,int m,int d)
	{
		mYear = y;
		mMonth = m;		
		mDay = d;
	}
	int getY()
	{
		return mYear;
	}
	int getM()
	{
		return mMonth;
	}
	int getD()
	{
		return mDay;
	}
	void show()
	{
		cout << mYear << "/" << mMonth << "/" << mDay << endl;
	}
private:
	int mYear;
	int mMonth;
	int mDay;
};
const int LOAN_INFO_SIZE = 100;
class CLoan
{
public:
	/*CLoan(char *name = "xiaolizi",char* book = "炁体源流",int y = 2018,int m = 6,int d =1,int ry = 2019,int rm = 2,int rd = 22,char *manager = "xiao bai")
	{
		mUser.addName(name);
		mBook.addName(book);
		mborrowTime.addDate(y,m,d);
		mbackTime.addDate(ry,rm,rd);
		mManager.addName(manager);
	}*/
	void addLoan(char *name,char* book,int y,int m,int d,int ry,int rm,int rd,char *manager)
	{
		mUser.addName(name);
		mBook.ChangeName(book);
		mborrowTime.addDate(y,m,d);
		mbackTime.addDate(ry,rm,rd);
		mManager.addName(manager);
	}
	char* getUser()
	{
		return  mUser.reNmae();
	}
	char* getBook()
	{
		return mBook.getName();
	}
	int getBorrowTimeY()
	{
		return mborrowTime.getY();
	}
	int getBorrowTimeM()
	{
		return mborrowTime.getM();
	}
	int getBorrowTimeD()
	{
		return mborrowTime.getD();
	}
	int getBackTimeY()
	{
		return mbackTime.getY();
	}
	int getBackTimeM()
	{
		return mbackTime.getM();
	}
	int getBackTimeD()
	{
		return mbackTime.getD();
	}
	char* getManager()
	{
		return mManager.reNmae();
	}
	int getBookAmount()
	{
		return mBook.getAmount();
	}
	//还书
	void backBook(int ry,int rm,int rd)
	{
		mbackTime.addDate(ry,rm,rd);
	}
private:
	CUser mUser;
	CBook mBook;
	CDate mborrowTime;
	CDate mbackTime;
	CUser mManager;
};
class CLoanDB
{
public:
	CLoanDB()
	{
		mIndex = 0;
	}
	// 添加一条借阅信息
	void addLoanDB()
	{
		//if(mIndex  <= 0)//初始化
		//{
		//	mIndex = 0;
		//}
		char name[NAME_LEN];
		char book[BOOK_NAME_LEN];
		int y,m,d,ry,rm,rd;
		char manager[NAME_LEN];
		cout<<mIndex<<endl;
		cout<<"请输入借阅者:";
		fflush(stdin);
		gets(name);
		cout<<"请输入借阅书名:";
		fflush(stdin);
		gets(book);
		cout<<"请输入借阅时间:"<<endl;
		cout<<"年:";
		fflush(stdin);
		cin>>y;
		cout<<"月:";
		fflush(stdin);
		cin>>m;
		cout<<"日:";
		fflush(stdin);
		cin>>d;
		cout<<"请输入还书时间:"<<endl;
		cout<<"年:";
		fflush(stdin);
		cin>>ry;
		cout<<"月:";
		fflush(stdin);
		cin>>rm;
		cout<<"日:";
		fflush(stdin);
		cin>>rd;
		cout<<"请输入管理员:";
		fflush(stdin);
		gets(manager);
		mLoan[mIndex++].addLoan(name,book,y,m,d,ry,rm,rd,manager);
	}
	//查询借阅信息
	void queryStudentLoanInfo(char *username)
	{
		//if(mIndex  <= 0)//初始化
		//{
		//	mIndex = 0;
		//}
		bool flag = false;
		for(int i = 0; i < mIndex;i++)
		{
			if(!strcmp(mLoan[i].getUser(),username))
			{
				flag = true;
				cout<<"借阅者:";
				cout<<mLoan[i].getUser()<<endl;	
				cout<<"借阅书籍:";
				cout<<mLoan[i].getBook()<<endl;	
				cout<<"借阅日期:";
				cout<<mLoan[i].getBorrowTimeY()<<"/"<<mLoan[i].getBorrowTimeM()<<"/"<<mLoan[i].getBorrowTimeD()<<endl;	
				cout<<"还书日期:";
				cout<<mLoan[i].getBackTimeY()<<"/"<<mLoan[i].getBackTimeM()<<"/"<<mLoan[i].getBackTimeD()<<endl;
				cout<<"管理员:";
				cout<<mLoan[i].getManager()<<endl;
			}
		}
		if(!flag)
		{		
			cout<<"暂无借阅记录."<<endl;
		}
	}
	//还书信息
	void backLoanDB()
	{
		if(mIndex <= 0)
		{
			cout<<"还没有借阅信息."<<endl;
			return;
		}
		cout<<"请输入书名:";
		char name[NAME_LEN];
		cin>>name;
		for(int i = 0; i < mIndex;i++)
		{
			if(!strcmp(mLoan[i].getBook(),name))
			{
				fflush(stdin);
				int ry,rm,rd;
				cout<<"请输入还书时间:"<<endl;
				cout<<"年:";
				cin>>ry;
				fflush(stdin);
				cout<<"月:";
				cin>>rm;
				fflush(stdin);
				cout<<"日:";
				cin>>rd;
				fflush(stdin);
				mLoan[i].backBook(ry,rm,rd);
				cout<<"还书成功!"<<endl;
			}
		}
	}
	//显示借阅信息
	void show()
	{
		for(int i = 0;i < mIndex;i++)
		{
			cout<<"借阅者:";
			cout<<mLoan[i].getUser()<<endl;	
			cout<<"借阅书籍:";
			cout<<mLoan[i].getBook()<<endl;	
			cout<<"借阅日期:";
			cout<<mLoan[i].getBorrowTimeY()<<"/"<<mLoan[i].getBorrowTimeM()<<"/"<<mLoan[i].getBorrowTimeD()<<endl;	
			cout<<"还书日期:";
			cout<<mLoan[i].getBackTimeY()<<"/"<<mLoan[i].getBackTimeM()<<"/"<<mLoan[i].getBackTimeD()<<endl;
			cout<<"管理员:";
			cout<<mLoan[i].getManager()<<endl;
		}
	}
private:
	CLoan mLoan[LOAN_INFO_SIZE];
	int mIndex;
}; 
//===================界面类======================
class CMenu
{
public:
	// 预填写数据
	CMenu()
	{
		CUser user;
		user.addnID(1000);
		user.addName("zhang san");
		user.addage(20);
		user.addSex("男");
		user.addAuth(AUTH_STUDENT);
		user.addPassword("1111");
		mUserDB.addUser(user);
		CUser manager;
		manager.addnID(7777);
		manager.addName("hong mei");
		manager.addage(35);
		manager.addSex("女");
		manager.addAuth(AUTH_MANAGER);
		manager.addPassword("9999");
		mUserDB.addUser(manager);
		CBook book;
		book.addISBN(10086);
		book.addName("C++");
		book.addAmount(10);
		mBookDB.addBook(book);
	}
	//登陆菜单
	void loginMenu()
	{
		for (;;)
		{
			cout << "用户名:";
			gets(mLoginUser);  // scanf   zhang san
			cout << "密码:";
			char pwd[20];
			gets(pwd);

			// 检测用户登录是否成功
			int auth = mUserDB.checkUser(mLoginUser, pwd);
			if (auth != AUTH_INVLAID)
			{
				// 进入相应的主菜单
				if (auth == AUTH_STUDENT) // 进入学生主菜单
				{
					studentMenu();
				}
				else // 进入管理员主菜单
				{
					managerMenu();
					/*
					1. 查询书籍
					2. 借书    学生名  书籍名 借阅时间  还书时间 CLoan => CLoanDB CBookDB
					3. 还书    
					4. 查询借阅历史 CLoanDB => CLoan
					*/
				}
			}
			else
			{
				cout << "用户名或密码错误!重新输入..." << endl; 
			}
		}
	}
	//学生操作主菜单
	void studentMenu()
	{
		while(true)
		{
			cout << "============" << endl;
			cout << "1.查询书籍" << endl;
			cout << "2.已借阅书籍" << endl;
			cout << "9.退出登录"<<endl;
			cout << "0.退出"<<endl;
			cout << "============" << endl;
			cout << "选择:";
			int choice = 0;
			cin >> choice;
			switch (choice)
			{
			case 1:
				{
					fflush(stdin);
					cout << "请输入书籍的名称:";
					char name[20];
					gets(name);	
					CBook *book = mBookDB.queryBook(name);
					if (book == NULL)
					{
						cout << name << " 该书籍不存在！" << endl;
					}
					else
					{
					  // 查到以后，打印书籍的信息
						book->show();
					}
				}
				break;
			case 2:
			// 查询借阅信息，有很多，一次进行打印
				mLoanDB.queryStudentLoanInfo(mLoginUser);
				break;
			case 9:
				fflush(stdin);
				loginMenu();
				break;
			case 0:
				exit(0);
			default:
				cout << "输入无效，请重新选择..." << endl;
			}
		}
	}
	//管理员操作主菜单
	void managerMenu()
	{
		/*1. 查询书籍
		2. 借书    学生名  书籍名 借阅时间  还书时间 CLoan => CLoanDB CBookDB
		3. 还书    
		4. 查询借阅历史 CLoanDB => CLoan
		*/
		while(true)
		{
			cout << "============" << endl;
			cout << "1.查询书籍" << endl;
			cout << "2.借书" << endl;
			cout << "3.还书" << endl;
			cout << "4.查询借阅历史" << endl;
			cout << "9.退出登录"<<endl;
			cout << "0.退出"<<endl;
			cout << "============" << endl;
			cout << "选择:";
			int choice = 0;
			cin >> choice;
			switch (choice)
			{
			case 1:
				{	
					fflush(stdin);
					cout << "请输入书籍的名称:";
					char name[20];
					gets(name);	
					CBook *book = mBookDB.queryBook(name);
					if (book == NULL)
					{
						cout << name << " 该书籍不存在！" << endl;
					}
					else
					{
					  // 查到以后，打印书籍的信息
						book->show();
					}
				}
				break;
			case 2:
				mLoanDB.addLoanDB();
				break;
			case 3:
				mLoanDB.backLoanDB();
				break;
			case 4:
				mLoanDB.show();
				break;
			case 9:
				fflush(stdin);
				loginMenu();
				break;
			case 0:
				exit(0);
			default:
				cout << "输入无效，请重新选择..." << endl;
			}
		}
	}
private:
	CUserDB mUserDB; // 人员信息数据库
	CBookDB mBookDB; // 书籍信息数据库
	CLoanDB mLoanDB; // 借阅信息数据库
	char mLoginUser[NAME_LEN]; // 记录当前登录的用户名
}; //464-244=220  300
/*
界面层  CMenu
数据层  CBookDB
*/

int main()
{
	CMenu menu;
	menu.loginMenu();
	return 0;
}