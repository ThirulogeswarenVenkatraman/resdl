#include "minclude.h"

InputHandler* InputHandler::InputHanderInst = 0;

InputHandler* InputHandler::getInstance()
{
	if (InputHanderInst == 0)
	{ 
		InputHanderInst = new InputHandler();
		return InputHanderInst;
	}
	return InputHanderInst;
}

InputHandler::InputHandler()
{
	keyStates = 0;
	for (int i = 0; i < 3; i++)
	{
		mouseStates.push_back(false);
	}
}

bool InputHandler::getMouseButtonState(int buttton)
{
	return mouseStates[buttton];
}

void InputHandler::EventUpdater()
{
	SDL_Event evnt;
	if(SDL_PollEvent(&evnt))
	{
		
		switch (evnt.type)
		{
		case SDL_QUIT:
			game::getInstance()->setState(false);
			break;
		case SDL_MOUSEBUTTONDOWN:
			MouseButtonDown(evnt);
			break;
		case SDL_MOUSEBUTTONUP:
			MouseButtonUp(evnt);
			break;
		case SDL_KEYDOWN:
			OnKeyDown();
			break;
		case SDL_KEYUP:
			OnKeyUp();
			break;
		default:
			break;
		}
	}
	
}


void InputHandler::MouseButtonDown(SDL_Event& q_event)
{
	if (q_event.button.button == SDL_BUTTON_LEFT)
	{
		mouseStates[LEFT] = true;
	}
	if (q_event.button.button == SDL_BUTTON_MIDDLE)
	{
		mouseStates[MIDDLE] = true;
	}
	if (q_event.button.button == SDL_BUTTON_RIGHT)
	{
		mouseStates[RIGHT] = true;
	}
}

void InputHandler::MouseButtonUp(SDL_Event& q_event)
{
	if (q_event.button.button == SDL_BUTTON_LEFT)
	{
		mouseStates[LEFT] = false;
	}
	if (q_event.button.button == SDL_BUTTON_MIDDLE)
	{
		mouseStates[MIDDLE] = false;
	}
	if (q_event.button.button == SDL_BUTTON_RIGHT)
	{
		mouseStates[RIGHT] = false;
	}
}

void InputHandler::OnKeyDown()
{
	keyStates = SDL_GetKeyboardState(0);
}

void InputHandler::OnKeyUp()
{
	keyStates = SDL_GetKeyboardState(0);
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{

	if (keyStates != 0)
	{
		if (keyStates[key] == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	return false;
}

