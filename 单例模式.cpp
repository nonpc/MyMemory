#if 0
#include<iostream>

using namespace std;
#endif


//��������ģʽ
#if 0
//�̲߳���ȫ�ĵ���
class Singleton 
{
public:
	//ע������Ͷ���ģʽ��ͬ
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
		cout<<"�Ҿ��ǻʵ�ĳĳĳ....."<<endl;
	}
private :
	//ע������ , �Ͷ���ģʽ�����ĳ�Ա��ͬ 
	static Singleton* singleton ;
	Singleton()
	{cout<<"�������󴴽�"<<endl;}
	~Singleton()
	{cout<<"������������"<<endl;}
	//����һ���ڲ���
	//�������ģʽ������������������Դ�����޷��ͷţ������ڴ�й©��
    //ԭ�򣺴�ʱȫ���������У��洢�Ĳ�����һ��ʵ�����󣬶���һ��ʵ�������ָ�룬��һ����ַ�������ѣ�
	//ʵ�������أ��ڶ�������Ϊ��ͨ��new�����ģ���Ȼ�����ܹ���Сȫ����������ռ�ã���ʵ��������һ���綼�ŵ�������
	//���ǣ�����ͷ���Դ�أ� 
	//�����ڲ���
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
	// ����һ���ڲ���ľ�̬����
	// ���ö�������ʱ��˳�����ͷ�singletonָ��Ķ�����Դ
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

//��������ģʽ
#if 0
class Singleton 
{
public:
	//��ȡΨһ���õĶ���
	static Singleton* getInstance()
	{
		return &singleton;
	}
	//������������ , ������static
	static void doSomething()
	{
		cout<<"�Ҿ��ǻʵ�ĳĳĳ....."<<endl;
	}
private :
	//��������������
	static Singleton singleton ;
	//�ù��캯��Ϊ private����������Ͳ��ᱻʵ���� , ���Ʋ����������
	Singleton()
	{cout<<"�������󴴽�"<<endl;}
	~Singleton()
	{cout<<"������������"<<endl;}
};
//��̬���ݳ�Ա��ʼ�� , �����ڴ�
//���������ͣ���������::����̬���ݳ�Ա����=��ֵ�� 
Singleton Singleton::singleton ;

int main()
{
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();
	Singleton *p3 = Singleton::getInstance();
	//ֻ��һ����ַ
	cout<<"p1: "<<p1<<endl<<"p2: "<<p2<<endl<<"p3: "<<p3<<endl;
	return 0;
}


#endif