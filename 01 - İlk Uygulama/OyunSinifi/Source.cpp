
#include<iostream>
#include<string>
#include "Uygulama.hpp"
using namespace std;

class Sekil
{
public:
	void f()
	{
		ciz();
	}
private:		
	virtual void ciz() = 0;
};
class Sekil2D :public Sekil
{
public:
	virtual void konumGetir() = 0;
};
class Kare :public Sekil2D
{
public:



	virtual void ciz() override
	{
	}

	virtual void konumGetir() override
	{
	}

};

int main()
{
	Uygulama uygulama;
	uygulama.insaEt(600, 200);
	uygulama.baslat();

}