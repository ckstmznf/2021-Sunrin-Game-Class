#pragma once
class Asset
{
public:
	sf::Texture* getTexture(const string& path); //���ҽ� ��θ� �޾Ƽ� ����
	void release(); //�������� ������ ���ҽ����� �����Ѵ�.
	map<string, sf::Texture*> textures;
};

extern Asset asset; //Asset�� �������� ����