#pragma once
#include<SFML/Graphics.hpp>

class Pencere;



class Cizilebilir
{
public:
	typedef std::shared_ptr<Cizilebilir>	CizilebilirPtr;
	typedef std::vector<CizilebilirPtr>		CizilebilirListesi;

	virtual void		baslat();
	virtual void		guncelle(const sf::Time& dt);
	virtual void		ciz(Pencere& pencere);
	
	virtual void		guiCizdir(const std::string& yazi="");

	virtual void		konumAta(const sf::Vector2f& konum);
	sf::Vector2f		konumGetir();
	void				cocukEkle(CizilebilirPtr yeniCocuk);
	void				isimAta(const std::string& isim);
protected:
	std::string			m_isim;
	sf::Vector2f		m_konum;
	CizilebilirListesi	m_cocuklar;
};

