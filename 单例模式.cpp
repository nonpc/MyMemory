#if 0
#include<iostream>

using namespace std;
#endif


//懒汉单例模式
#if 0
//线程不安全的单例
class Singleton 
{
public:
	//注意这里和饿汉模式不同
	static Singleton* getInstance()
	{
		if(singleton == nullptr)
		{
			singleton = new Singleton();
		}
		return singleton;
	}
	static void doSomething()
	{
		cout<<"我就是皇帝某某某....."<<endl;
	}
private :
	//注意这里 , 和饿汉模式声明的成员不同 
	static Singleton* singleton ;
	Singleton()
	{cout<<"单例对象创建"<<endl;}
	~Singleton()
	{cout<<"单例对象销毁"<<endl;}
	//定义一个内部类
	//如果单例模式的类中申请了其他资源，就无法释放，导致内存泄漏！
    //原因：此时全局数据区中，存储的并不是一个实例对象，而是一个实例对象的指针，即一个地址变量而已！
	//实例对象呢？在堆区，因为是通过new得来的！虽然这样能够减小全局数据区的占用，把实例对象这一大坨都放到堆区。
	//可是！如何释放资源呢？ 
	//定义内部类
	class CGarbo
	{
	public:
		CGarbo()
		{}
		~CGarbo()
		{
			if(singleton != nullptr)
			{
				delete singleton;
				singleton = nullptr;
			}
		}
	};
	// 定义一个内部类的静态对象
	// 当该对象销毁时，顺带就释放singleton指向的堆区资源
	static CGarbo m_garbo;
};

Singleton* Singleton::singleton = nullptr;
Singleton::CGarbo Singleton::m_garbo;
int main()
{
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();
	Singleton *p3 = Singleton::getInstance();
	cout<<"p1: "<<p1<<endl<<"p2: "<<p2<<endl<<"p3: "<<p3<<endl;
	return 0;
}
#endif

//饿汉单例模式
#if 0
class Singleton 
{
public:
	//获取唯一可用的对象
	static Singleton* getInstance()
	{
		return &singleton;
	}
	//类中其他方法 , 尽量是static
	static void doSomething()
	{
		cout<<"我就是皇帝某某某....."<<endl;
	}
private :
	//单例对象在这里
	static Singleton singleton ;
	//让构造函数为 private，这样该类就不会被实例化 , 限制产生多个对象
	Singleton()
	{cout<<"单例对象创建"<<endl;}
	~Singleton()
	{cout<<"单例对象销毁"<<endl;}
};
//静态数据成员初始化 , 分配内存
//＜数据类型＞＜类名＞::＜静态数据成员名＞=＜值＞ 
Singleton Singleton::singleton ;

int main()
{
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();
	Singleton *p3 = Singleton::getInstance();
	//只有一个地址
	cout<<"p1: "<<p1<<endl<<"p2: "<<p2<<endl<<"p3: "<<p3<<endl;
	return 0;
}


#endif