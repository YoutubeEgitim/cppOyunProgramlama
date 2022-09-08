#include<iostream>
using namespace std;

class Sekil
{
public:
	virtual void ciz() = 0;
	virtual void hareket() = 0;

	virtual int konumGetir()
	{
		return konum;
	}

	int konum;
};

class CizimModulu
{
public:
	void sekilCiz(Sekil* sekil)
	{
		cout << "CizimModulu" << std::endl;
		sekil->ciz();
	}
};

class Kare :public Sekil
{
public:
	void ciz() override
	{
		cout << "Kare::ciz()" << endl;
	}

};


int main()
{
	Kare yeniKare;
	CizimModulu modul;

	modul.sekilCiz(&yeniKare);
}