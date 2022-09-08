#include "Cizilebilir.hpp"



void Cizilebilir::guiCizdir(const std::string& yazi)
{
}

void Cizilebilir::konumAta(const sf::Vector2f& konum)
{
	m_konum = konum;
}

sf::Vector2f Cizilebilir::konumGetir()
{
	return m_konum;
}
