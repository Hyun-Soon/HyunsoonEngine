#pragma once

#include <algorithm>
#include <vector>

#include "TimeUtils.h"
#include "MathTypes.h"

namespace hs
{
	enum class eKeyState
	{
		Down,
		Up,
		Pressed,
		None,
	};

	enum class eKeyCode
	{
		Q,
		W,
		E,
		R,
		T,
		Y,
		U,
		I,
		O,
		P,
		A,
		S,
		D,
		F,
		G,
		H,
		J,
		K,
		L,
		Z,
		X,
		C,
		V,
		B,
		N,
		M,
		Left,
		Right,
		Up,
		Down,
		Space,
		Tab,
		Ctrl,
		Alt,
		LButton,
		MButton,
		RButton,
		End,
	};

	class Input
	{
	public:
		struct Key
		{
			Key(eKeyCode code, eKeyState state, bool pressed)
				: keyCode(code), state(state), bPressed(pressed) {
				};

			eKeyCode  keyCode;
			eKeyState state;
			bool	  bPressed;
		};

		static void Initialize();
		static void Update();

		__forceinline static bool	 GetKeyDown(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Down; }
		__forceinline static bool	 GetKeyUp(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Up; }
		__forceinline static bool	 GetKey(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Pressed; }
		__forceinline static Vector2 GetMousePosition() { return mMousePosition; }

	private:
		static void createKeys();
		static void updateKeys();
		static void updateKey(Input::Key& key);
		static bool isKeyDown(eKeyCode code);
		static void updateKeyDown(Input::Key& key);
		static void updateKeyUp(Input::Key& key);
		static void clearKeys();
		static void getMousePositionByWindow();

		static std::vector<Key> mKeys;
		static Vector2			mMousePosition;
	};
} // namespace hs