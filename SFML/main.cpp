#include "pch.h"
#include "Game.h"


extern bool GAME_END = false;

int main() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), "SFML works!", sf::Style::Close, settings); // VideoMode : âũ��, 
	window.setFramerateLimit(60); //FPS�� 60���� ����

	sf::Clock clock;
	
	game.init(&window);

	
	int i = 0;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		sf::Time deltaTime = clock.restart(); //��Ÿ Ÿ���� �����´�.
		// cout << deltaTime.asSeconds() << endl; //��ŸŸ���� ���
		window.clear();

		game.updata(deltaTime.asSeconds());
		game.render(window);

		window.display();

		if (GAME_END) {
			cout << "���� ����" << endl;
			break;
		}
	}

	game.release();
	return 0;
}
