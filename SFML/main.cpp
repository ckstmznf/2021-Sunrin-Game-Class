#include "pch.h"
#include "Game.h"


extern bool GAME_END = false;

int main() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), "SFML works!", sf::Style::Close, settings); // VideoMode : 창크기, 
	window.setFramerateLimit(60); //FPS를 60으로 설정

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
		sf::Time deltaTime = clock.restart(); //델타 타임을 가져온다.
		// cout << deltaTime.asSeconds() << endl; //델타타임을 출력
		window.clear();

		game.updata(deltaTime.asSeconds());
		game.render(window);

		window.display();

		if (GAME_END) {
			cout << "게임 종료" << endl;
			break;
		}
	}

	game.release();
	return 0;
}
