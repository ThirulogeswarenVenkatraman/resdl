#include "include/game.h"
#include "include/madflow.h"

const int SCREEN_X { 1280 }, SCREEN_Y { 720 };

int main(int argc,char* argv[])
{ 
	if (game::getInstance()->Init(1280, 720, "Mad Engine"))
	{
		std::cout << "RefreshRate: " << game::getInstance()->getRefreshRate();
		std::cout << "\nsec_per_update = " << 1.0f / (float)game::getInstance()->getRefreshRate();
		const float FixedDeltaTime = 1.0f / (float)game::getInstance()->getRefreshRate();
		float previousTime = 0.0f;
		float lag = 0.0f;
		float max = 0.0f;
		while (game::getInstance()->isRunnning())
		{
			float DeltaTime = InSec() - previousTime;
			previousTime = InSec();
			lag += DeltaTime;
			game::getInstance()->HandleEvents();

			while (lag >= FixedDeltaTime)
			{
				game::getInstance()->HandleEvents();
				game::getInstance()->Update(FixedDeltaTime);
				lag -= FixedDeltaTime;
			}
			game::getInstance()->Render();
		}
	}
	else { std::cerr << "Game Init() failed!\n"; return -1; }
	game::getInstance()->clean();
	std::cout << "\nSubsystem Cleaned UP !\n";
	return 0;
}