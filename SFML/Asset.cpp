#include "pch.h"
#include "Asset.h"

sf::Texture* Asset::getTexture(const string& path)
{
	if (!textures[path]) {
		// ������ ���ҽ��� ���ٸ�
		sf::Texture* texture = new sf::Texture();
		texture->loadFromFile(path);
		textures[path] = texture;
	}

	return textures[path]; //�ִٸ�
}

void Asset::release()
{
	for (auto iter : textures) {
		//map�� for-each���� iter�� key�� value�� �� �ִ´�.
		delete iter.second;
	}
}


Asset asset; //Asset�� �������� ����