#include "Cizilebilir.hpp"

Cizilebilir::Cizilebilir()
{
	m_cizilecekmi = true;
}

sf::Vector2f Cizilebilir::konumGetir()
{
	return m_konum;
}
