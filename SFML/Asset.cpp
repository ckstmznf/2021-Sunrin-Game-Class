#include "pch.h"
#include "Asset.h"

sf::Texture* Asset::getTexture(const string& path)
{
	if (!textures[path]) {
		// 가져온 리소스가 없다면
		sf::Texture* texture = new sf::Texture();
		texture->loadFromFile(path);
		textures[path] = texture;
	}

	return textures[path]; //있다면
}

void Asset::release()
{
	for (auto iter : textures) {
		//map의 for-each문은 iter에 key와 value를 다 넣는다.
		delete iter.second;
	}
}


Asset asset; //Asset의 전역변수 설정