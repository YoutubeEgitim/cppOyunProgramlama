#pragma once

#include "Ok.hpp"

class VektorSekli :public Ok
{
public:
	virtual void baslat() override;
	virtual void guncelle(const sf::Time& dt) override;
	virtual void ciz(Pencere& pencere) override;
	virtual void guiCizdir(const std::string& yazi = "");
	virtual void yonAta(const sf::Vector2f& yon)override ;
	
private:
	bool	m_vektorGorulsunmu;
	bool	m_eksenlerGorulsunmu;
	bool	m_yaziGorulsunmu;
	Ok		m_xEkseni;
	Ok		m_yEkseni;
};
