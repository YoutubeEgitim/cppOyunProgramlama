#include<iostream>
using namespace std;
class Sekil
{
public:
    void yaz() {}
     void	ciz()
    {
        cout << "Sekil::Ciz()";
    }
    int x, y;
};
void cagir(Sekil* sekil)
{
    sekil->ciz();
}
int main()
{
    Sekil yeni;
    cagir(&yeni);

}