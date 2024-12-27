#pragma once

#include <vector>
#include <Windows.h>

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
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		End,
	};

	class Input
	{
	public:
		struct Key
		{
			Key(eKeyCode code, eKeyState state, bool pressed) :
				keyCode(code),
				state(state),
				bPressed(pressed)
			{
			};


			eKeyCode keyCode;
			eKeyState state;
			bool bPressed;
		};

		static void Initialize();
		static void Update();

		static bool GetKeyDown(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Down; }
		static bool GetKeyUp(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Up; }
		static bool GetKey(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Pressed; }

	private:
		static std::vector<Key> mKeys;
	};
}