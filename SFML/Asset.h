#pragma once
class Asset
{
public:
	sf::Texture* getTexture(const string& path); //리소스 경로를 받아서 관리
	void release(); //동적으로 가져온 리소스들을 해제한다.
	map<string, sf::Texture*> textures;
};

extern Asset asset; //Asset의 전역변수 설정