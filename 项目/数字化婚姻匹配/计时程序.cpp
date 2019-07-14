#include <iostream>
using namespace std;
#include <windows.h>

class MyTimer
{
public:
	MyTimer()
	{
		QueryPerformanceFrequency(&_freq);
		costTime=0.0;
	}
	void Start()
	{
		for(int i=0; i<EN_NUMER; ++i)
		{
			QueryPerformanceCounter(&_array[i]._begin);	
		}
	}
	void Stop()
	{
		for(int i=0; i<EN_NUMER; ++i)
		{
			QueryPerformanceCounter(&_array[i]._end);	
		}
	}
	void Reset()
	{
		costTime=0.0;
	}
	void showTime()
	{
		double allTime=0.0;
		for(int i=0; i<EN_NUMER; ++i)
		{
			allTime+=(((double)_array[i]._end.QuadPart-(double)_array[i]._begin.QuadPart)/(double)_freq.QuadPart);
		}
		costTime=allTime/EN_NUMER;
		costTime*=1000000;
		
		if((((int)costTime)/1000000) > 0)
		{
			cout<<costTime/1000000<<" s"<<endl;
		}
		else if(((int)costTime)/1000 > 0)
		{
			cout<<costTime/1000<<" ms"<<endl;
		}
		else
		{
			cout<<costTime<<" us"<<endl;
		}
	}
private:
	class Array
	{
	public:
		LARGE_INTEGER _begin;
		LARGE_INTEGER _end;
	};
	enum{EN_NUMER=5};
	LARGE_INTEGER _freq;
	double costTime;
	Array _array[EN_NUMER];
};
// 220ms     70s    i5  4G
int main()
{
	MyTimer timer;
	timer.Start();
////////////////////////////////
	long a=1000000;
	while(a--);

/////////////////////////////////
	timer.Stop();
	timer.showTime();

	return 0;
}


192.168.245.200
5000
root
111111
