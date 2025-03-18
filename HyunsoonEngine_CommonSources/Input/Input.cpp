#include "Input.h"
#include "Application.h"

extern hs::Application app;

namespace hs
{
	std::vector<Input::Key> Input::mKeys = {};
	Vector2					Input::mMousePosition = Vector2::One;

	int ASCII[(UINT)eKeyCode::End] = {
		'Q',
		'W',
		'E',
		'R',
		'T',
		'Y',
		'U',
		'I',
		'O',
		'P',
		'A',
		'S',
		'D',
		'F',
		'G',
		'H',
		'J',
		'K',
		'L',
		'Z',
		'X',
		'C',
		'V',
		'B',
		'N',
		'M',
		VK_LEFT,
		VK_RIGHT,
		VK_UP,
		VK_DOWN,
		VK_SPACE,
		VK_TAB,
		VK_CONTROL,
		VK_MENU,
		VK_LBUTTON,
		VK_MBUTTON,
		VK_RBUTTON,
	};

	void Input::Initialize()
	{
		createKeys();
	}

	void Input::Update()
	{
		updateKeys();
	}

	void Input::createKeys()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
			mKeys.emplace_back(eKeyCode(i), eKeyState::None, false);
	}

	void Input::updateKeys()
	{
		std::for_each(mKeys.begin(), mKeys.end(),
			[](Key& key) -> void {
				updateKey(key);
			});
	}

	void Input::updateKey(Input::Key& key)
	{
		if (GetFocus())
		{
			if (isKeyDown(key.keyCode))
			{
				updateKeyDown(key);
			}
			else
			{
				updateKeyUp(key);
			}

			getMousePositionByWindow();
		}
		else
		{
			clearKeys();
		}
	}

	bool Input::isKeyDown(eKeyCode code)
	{
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}

	void Input::updateKeyDown(Input::Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::Pressed;
		else
			key.state = eKeyState::Down;

		key.bPressed = true;
	}

	void Input::updateKeyUp(Input::Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::Up;
		else
			key.state = eKeyState::None;

		key.bPressed = false;
	}

	void Input::clearKeys()
	{
		for (Key& key : mKeys)
		{
			if (key.state == eKeyState::Down || key.state == eKeyState::Pressed)
				key.state = eKeyState::Up;
			else if (key.state == eKeyState::Up)
				key.state = eKeyState::None;

			key.bPressed = false;
		}
	}

	void Input::getMousePositionByWindow()
	{
		POINT mousePos = {};
		GetCursorPos(&mousePos);
		ScreenToClient(app.GetHwnd(), &mousePos);

		mMousePosition.x = mousePos.x;
		mMousePosition.y = mousePos.y;
	}

} // namespace hs