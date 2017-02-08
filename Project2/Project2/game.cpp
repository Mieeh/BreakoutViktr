#include "game.h"

Game::Game()
{
	window.create(sf::VideoMode(800, 600), "broken out");
	window.setFramerateLimit(60);

	createbricks();
}

Game::~Game()
{
	// Because using new operator puts objects on heap instead of stack we need to remove them from the heap.
	// Since they were created in Game, before Game gets destroyed it will call the destructor ~Game and that is where we delete them.
	// Memory management, on every object you use the operator new must be destroyed by delete.
	for (Brick * brick : bricks)
	{
		delete brick;
	}
}

void Game::start()
{
	clock.restart();
	while (window.isOpen())
	{
		Time elapsed = clock.restart();
		events();
		update(elapsed);
		draw();
	}
}

void Game::events()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void Game::update(Time elapsed)
{
	paddle.updatePosition(Mouse::getPosition(window));
	ball.update(elapsed);

	// Remove dead bricks
	for (std::vector<Brick*>::iterator it = bricks.begin(); it != bricks.end(); )
	{
		if ((*it)->isDead())
		{
			delete * it;
			it = bricks.erase(it);
		}
		else
		{
			++it;
		}
	}
}

void Game::createbricks()
{
	// Create bricks

	int rows = 5;
	int cols = 7;
	int spacerx = 100;
	int spacery = 50;
	//int startX = (window.getSize().x - (cols*BRICK_WIDTH + (cols - 1)*spacer)) / 2 + BRICK_WIDTH / 2;
	int startX = BRICK_WIDTH + spacerx;
	int startY = BRICK_HEIGHT + spacery;

	for (int x = 0; x < cols; x++)
	{
		for (int y = 0; y < rows; y++)
		{
			int xpos = (BRICK_WIDTH + spacerx*x);
			int ypos = (BRICK_HEIGHT + spacery*y);

			printf("%d, %d\n", xpos, ypos);

			bricks.push_back(new Brick(Vector2f(xpos, ypos)));
		}
	}
}

void Game::draw()
{
	window.clear();

	for (int i = 0; i < bricks.size(); i++)
		window.draw(bricks.at(i)->getShape());

	window.draw(ball.getShape());
	window.draw(paddle.getShape());
	window.display();
}