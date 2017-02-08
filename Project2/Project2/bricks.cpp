// Create bricks
Brick b(Vector2f(0, 0), Color::Black, 1);
int width = b.getShape()->getSize().x;
int height = b.getShape()->getSize().y;
int xpos, ypos;
int rows = 5;
int cols = 14;
int spacer = 5;
int startX = (window.getSize().x - (cols*width + (cols - 1)*spacer)) / 2 + width / 2;

for (int x = 0; x < rows; x++)
{
	for (int y = 0; y < rows; y++)
	{
		xpos = width*x + spacer*x + startX;
		ypos = height*y + spacer*y + height;

		Brick * brick = new Brick(Vector2f(xpos, ypos), Color::Red, 1);
		bricks.push_back(brick);
	}
}

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

// Because using new operator puts objects on heap instead of stack we need to remove them from the heap.
// Since they were created in Game, before Game gets destroyed it will call the destructor ~Game and that is where we delete them.
Game::~Game()
{
	// Memory management, on every object you use the operator new must be destroyed by delete.
	for (Brick * brick : bricks)
	{
		delete brick;
	}
}
