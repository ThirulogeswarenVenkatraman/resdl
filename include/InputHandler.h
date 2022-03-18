#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "common.h"

enum mouseButtons {
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
	const Uint8* keyStates;
	std::vector<bool> mouseStates;
	static InputHandler* InputHanderInst;

	void MouseButtonDown(SDL_Event& q_event);
	void MouseButtonUp(SDL_Event& q_event);
	void OnKeyDown();
	void OnKeyUp();

public:
	static InputHandler* getInstance();
	InputHandler();
	void EventUpdater();

	bool getMouseButtonState(int button);
	bool isKeyDown(SDL_Scancode key);
};

#endif
