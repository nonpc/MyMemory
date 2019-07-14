#include<iostream>
#include<cassert>
#include<cstring>
#include<cstdlib>
using namespace std;

/*
OOPʵ��һ���򵥵�ͼ����鼮����
��ɫ��
ѧ��   ��  ��ѯ�鼮   �鿴�Լ��Ѿ����ĵ��鼮   
����Ա ��  ��ѯ�鼮   ����   ����    ������ʷ 

ʵ�壺  ��    ��    ������Ϣ
*/
//===================��Ա��Ϣ����=======================
//Ȩ����Ϣ����
const int AUTH_STUDENT = 0; // ѧ��Ȩ��
const int AUTH_MANAGER = 1; // ����ԱȨ��
const int AUTH_INVLAID = 2; // ��ЧȨ��
const int NAME_LEN = 20;
const int SEX_LEN = 5;
const int PWD_LEN = 20;

// �û���
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
// �û����ݿ���
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
	// ����û���Ϣ
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
	// ����û���¼Ȩ��
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
		return AUTH_INVLAID;//��ЧȨ��
	}
private:
	CUser *pUserArr;
	int mSize;
	int mIndex;
};
//===================�鼮��Ϣ����=======================
const int BOOK_NAME_LEN = 50;
const int BOOK_NUM = 100;
// �鼮���Ͷ���
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
		cout<<"���"<<"    "<<"����"<<"   "<<"����"<<endl;
		cout<<mISBN<<"   "<<mName<<"    "<< mAmount<<endl;
	}
private:
	int mISBN;
	char mName[BOOK_NAME_LEN];
	int mAmount;
};
// �鼮��DB����
class CBookDB
{
public:
	CBookDB()
	{
		mIndex = 0;
	}
	// ����鼮
	void addBook(const CBook &book) 
	{
		/*if(mIndex < 0)
		{
			mIndex = 0;
		}*/
		mBookArr[mIndex++] = book;
	}
	// ɾ���鼮
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
	// �����鼮����
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
//====================������Ϣ����=====================
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
	/*CLoan(char *name = "xiaolizi",char* book = "����Դ��",int y = 2018,int m = 6,int d =1,int ry = 2019,int rm = 2,int rd = 22,char *manager = "xiao bai")
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
	//����
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
	// ���һ��������Ϣ
	void addLoanDB()
	{
		//if(mIndex  <= 0)//��ʼ��
		//{
		//	mIndex = 0;
		//}
		char name[NAME_LEN];
		char book[BOOK_NAME_LEN];
		int y,m,d,ry,rm,rd;
		char manager[NAME_LEN];
		cout<<mIndex<<endl;
		cout<<"�����������:";
		fflush(stdin);
		gets(name);
		cout<<"�������������:";
		fflush(stdin);
		gets(book);
		cout<<"���������ʱ��:"<<endl;
		cout<<"��:";
		fflush(stdin);
		cin>>y;
		cout<<"��:";
		fflush(stdin);
		cin>>m;
		cout<<"��:";
		fflush(stdin);
		cin>>d;
		cout<<"�����뻹��ʱ��:"<<endl;
		cout<<"��:";
		fflush(stdin);
		cin>>ry;
		cout<<"��:";
		fflush(stdin);
		cin>>rm;
		cout<<"��:";
		fflush(stdin);
		cin>>rd;
		cout<<"���������Ա:";
		fflush(stdin);
		gets(manager);
		mLoan[mIndex++].addLoan(name,book,y,m,d,ry,rm,rd,manager);
	}
	//��ѯ������Ϣ
	void queryStudentLoanInfo(char *username)
	{
		//if(mIndex  <= 0)//��ʼ��
		//{
		//	mIndex = 0;
		//}
		bool flag = false;
		for(int i = 0; i < mIndex;i++)
		{
			if(!strcmp(mLoan[i].getUser(),username))
			{
				flag = true;
				cout<<"������:";
				cout<<mLoan[i].getUser()<<endl;	
				cout<<"�����鼮:";
				cout<<mLoan[i].getBook()<<endl;	
				cout<<"��������:";
				cout<<mLoan[i].getBorrowTimeY()<<"/"<<mLoan[i].getBorrowTimeM()<<"/"<<mLoan[i].getBorrowTimeD()<<endl;	
				cout<<"��������:";
				cout<<mLoan[i].getBackTimeY()<<"/"<<mLoan[i].getBackTimeM()<<"/"<<mLoan[i].getBackTimeD()<<endl;
				cout<<"����Ա:";
				cout<<mLoan[i].getManager()<<endl;
			}
		}
		if(!flag)
		{		
			cout<<"���޽��ļ�¼."<<endl;
		}
	}
	//������Ϣ
	void backLoanDB()
	{
		if(mIndex <= 0)
		{
			cout<<"��û�н�����Ϣ."<<endl;
			return;
		}
		cout<<"����������:";
		char name[NAME_LEN];
		cin>>name;
		for(int i = 0; i < mIndex;i++)
		{
			if(!strcmp(mLoan[i].getBook(),name))
			{
				fflush(stdin);
				int ry,rm,rd;
				cout<<"�����뻹��ʱ��:"<<endl;
				cout<<"��:";
				cin>>ry;
				fflush(stdin);
				cout<<"��:";
				cin>>rm;
				fflush(stdin);
				cout<<"��:";
				cin>>rd;
				fflush(stdin);
				mLoan[i].backBook(ry,rm,rd);
				cout<<"����ɹ�!"<<endl;
			}
		}
	}
	//��ʾ������Ϣ
	void show()
	{
		for(int i = 0;i < mIndex;i++)
		{
			cout<<"������:";
			cout<<mLoan[i].getUser()<<endl;	
			cout<<"�����鼮:";
			cout<<mLoan[i].getBook()<<endl;	
			cout<<"��������:";
			cout<<mLoan[i].getBorrowTimeY()<<"/"<<mLoan[i].getBorrowTimeM()<<"/"<<mLoan[i].getBorrowTimeD()<<endl;	
			cout<<"��������:";
			cout<<mLoan[i].getBackTimeY()<<"/"<<mLoan[i].getBackTimeM()<<"/"<<mLoan[i].getBackTimeD()<<endl;
			cout<<"����Ա:";
			cout<<mLoan[i].getManager()<<endl;
		}
	}
private:
	CLoan mLoan[LOAN_INFO_SIZE];
	int mIndex;
}; 
//===================������======================
class CMenu
{
public:
	// Ԥ��д����
	CMenu()
	{
		CUser user;
		user.addnID(1000);
		user.addName("zhang san");
		user.addage(20);
		user.addSex("��");
		user.addAuth(AUTH_STUDENT);
		user.addPassword("1111");
		mUserDB.addUser(user);
		CUser manager;
		manager.addnID(7777);
		manager.addName("hong mei");
		manager.addage(35);
		manager.addSex("Ů");
		manager.addAuth(AUTH_MANAGER);
		manager.addPassword("9999");
		mUserDB.addUser(manager);
		CBook book;
		book.addISBN(10086);
		book.addName("C++");
		book.addAmount(10);
		mBookDB.addBook(book);
	}
	//��½�˵�
	void loginMenu()
	{
		for (;;)
		{
			cout << "�û���:";
			gets(mLoginUser);  // scanf   zhang san
			cout << "����:";
			char pwd[20];
			gets(pwd);

			// ����û���¼�Ƿ�ɹ�
			int auth = mUserDB.checkUser(mLoginUser, pwd);
			if (auth != AUTH_INVLAID)
			{
				// ������Ӧ�����˵�
				if (auth == AUTH_STUDENT) // ����ѧ�����˵�
				{
					studentMenu();
				}
				else // �������Ա���˵�
				{
					managerMenu();
					/*
					1. ��ѯ�鼮
					2. ����    ѧ����  �鼮�� ����ʱ��  ����ʱ�� CLoan => CLoanDB CBookDB
					3. ����    
					4. ��ѯ������ʷ CLoanDB => CLoan
					*/
				}
			}
			else
			{
				cout << "�û������������!��������..." << endl; 
			}
		}
	}
	//ѧ���������˵�
	void studentMenu()
	{
		while(true)
		{
			cout << "============" << endl;
			cout << "1.��ѯ�鼮" << endl;
			cout << "2.�ѽ����鼮" << endl;
			cout << "9.�˳���¼"<<endl;
			cout << "0.�˳�"<<endl;
			cout << "============" << endl;
			cout << "ѡ��:";
			int choice = 0;
			cin >> choice;
			switch (choice)
			{
			case 1:
				{
					fflush(stdin);
					cout << "�������鼮������:";
					char name[20];
					gets(name);	
					CBook *book = mBookDB.queryBook(name);
					if (book == NULL)
					{
						cout << name << " ���鼮�����ڣ�" << endl;
					}
					else
					{
					  // �鵽�Ժ󣬴�ӡ�鼮����Ϣ
						book->show();
					}
				}
				break;
			case 2:
			// ��ѯ������Ϣ���кܶ࣬һ�ν��д�ӡ
				mLoanDB.queryStudentLoanInfo(mLoginUser);
				break;
			case 9:
				fflush(stdin);
				loginMenu();
				break;
			case 0:
				exit(0);
			default:
				cout << "������Ч��������ѡ��..." << endl;
			}
		}
	}
	//����Ա�������˵�
	void managerMenu()
	{
		/*1. ��ѯ�鼮
		2. ����    ѧ����  �鼮�� ����ʱ��  ����ʱ�� CLoan => CLoanDB CBookDB
		3. ����    
		4. ��ѯ������ʷ CLoanDB => CLoan
		*/
		while(true)
		{
			cout << "============" << endl;
			cout << "1.��ѯ�鼮" << endl;
			cout << "2.����" << endl;
			cout << "3.����" << endl;
			cout << "4.��ѯ������ʷ" << endl;
			cout << "9.�˳���¼"<<endl;
			cout << "0.�˳�"<<endl;
			cout << "============" << endl;
			cout << "ѡ��:";
			int choice = 0;
			cin >> choice;
			switch (choice)
			{
			case 1:
				{	
					fflush(stdin);
					cout << "�������鼮������:";
					char name[20];
					gets(name);	
					CBook *book = mBookDB.queryBook(name);
					if (book == NULL)
					{
						cout << name << " ���鼮�����ڣ�" << endl;
					}
					else
					{
					  // �鵽�Ժ󣬴�ӡ�鼮����Ϣ
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
				cout << "������Ч��������ѡ��..." << endl;
			}
		}
	}
private:
	CUserDB mUserDB; // ��Ա��Ϣ���ݿ�
	CBookDB mBookDB; // �鼮��Ϣ���ݿ�
	CLoanDB mLoanDB; // ������Ϣ���ݿ�
	char mLoginUser[NAME_LEN]; // ��¼��ǰ��¼���û���
}; //464-244=220  300
/*
�����  CMenu
���ݲ�  CBookDB
*/

int main()
{
	CMenu menu;
	menu.loginMenu();
	return 0;
}