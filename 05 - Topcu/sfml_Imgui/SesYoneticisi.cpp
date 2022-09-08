#include "SesYoneticisi.hpp"

void SesYoneticisi::sesDosyasiEkle(	const std::string& sesIsmi,
									const std::string& dosyaIsmi)
{
	
	m_sesTamponHaritasi[dosyaIsmi] = std::make_shared<sf::SoundBuffer>();

	auto donus = m_sesTamponHaritasi[dosyaIsmi]->loadFromFile(dosyaIsmi);

	m_sesHaritasi[sesIsmi].setBuffer(*m_sesTamponHaritasi[dosyaIsmi]);
	
}

void SesYoneticisi::sesOynat(const std::string& sesIsmi)
{
	m_sesHaritasi[sesIsmi].play();
}
