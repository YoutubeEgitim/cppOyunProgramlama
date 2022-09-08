#pragma once
#include<SFML/Audio.hpp>
#include<unordered_map>
class SesYoneticisi
{
public:
	void sesDosyasiEkle(const std::string& sesIsmi,
						const std::string& dosyaIsmi);

	void sesOynat(const std::string& sesIsmi);
	typedef std::shared_ptr<sf::SoundBuffer>	SoundBufferPtr;
	
private:
	std::unordered_map<std::string, SoundBufferPtr>		m_sesTamponHaritasi;
	std::unordered_map < std::string, sf::Sound>	m_sesHaritasi;
};
