#include<iostream>
//#include<vld.h>

using namespace std;

class CMyString
{
public:
	CMyString(char * pData = nullptr);
	CMyString& operator=(const CMyString &str);
	void show();
private:
	char* m_pData;
};

CMyString::CMyString(char *pData)
{
	if(pData == nullptr)
		return;
	int len = strlen(pData);
	m_pData = new char[len+1];
	int i = 0;
	for(i = 0 ; i < len;++i)
	{
		m_pData[i] = pData[i];
	}
	m_pData[i] = '\0';
	//strcpy(m_pData,pData);
}

CMyString& CMyString::operator=(const CMyString &str)
{
	if(this != &str)
	{
		CMyString strTmp(str);
		char *pTmp = strTmp.m_pData;
		strTmp.m_pData = m_pData;
		m_pData = pTmp;
	}
	return *this;
}
void CMyString::show()
{
	cout<<m_pData<<endl;
}

int main()
{
	char arr[] = "hello world";
	char brr[] ="aaa";
	CMyString a(arr);
	CMyString b(brr);
	b = a;
	b.show();
	return 0;
}