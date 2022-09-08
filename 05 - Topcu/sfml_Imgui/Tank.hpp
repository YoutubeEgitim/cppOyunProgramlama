#pragma once

#include "Cizilebilir.hpp"

class Tank :public Cizilebilir
{
public:
	typedef std::shared_ptr<Tank> TankPtr;

	enum class TankYonu
	{Sol=0,Sag=1};
	Tank(TankYonu yon = TankYonu::Sag,float hucreBoyutu=50.0f);
	// Inherited via Cizilebilir
	virtual void baslat() override;
	virtual void guncelle(const sf::Time& dt) override;
	virtual void ciz(Pencere& pencere) override;
	virtual void konumAta(const sf::Vector2f& konum)override;
	virtual void guiCizdir(const std::string& yazi = "")override;
	void	namluDondur(float aci);
	sf::Vector2f	namluYonuGetir();
	sf::Vector2f	namluPozisyonuGetir();
private:
	void tankOlustur();
	
	float				m_hucreBoyutu;
	sf::RectangleShape	m_govdeSekli;
	sf::CircleShape		m_kuleSekli;
	sf::RectangleShape	m_namluSekli;
	TankYonu			m_yon;
};
