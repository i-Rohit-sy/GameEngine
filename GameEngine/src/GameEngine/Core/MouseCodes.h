#pragma once
namespace GameEngine
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define GE_MOUSE_BUTTON_0      ::GameEngine::Mouse::Button0
#define GE_MOUSE_BUTTON_1      ::GameEngine::Mouse::Button1
#define GE_MOUSE_BUTTON_2      ::GameEngine::Mouse::Button2
#define GE_MOUSE_BUTTON_3      ::GameEngine::Mouse::Button3
#define GE_MOUSE_BUTTON_4      ::GameEngine::Mouse::Button4
#define GE_MOUSE_BUTTON_5      ::GameEngine::Mouse::Button5
#define GE_MOUSE_BUTTON_6      ::GameEngine::Mouse::Button6
#define GE_MOUSE_BUTTON_7      ::GameEngine::Mouse::Button7
#define GE_MOUSE_BUTTON_LAST   ::GameEngine::Mouse::ButtonLast
#define GE_MOUSE_BUTTON_LEFT   ::GameEngine::Mouse::ButtonLeft
#define GE_MOUSE_BUTTON_RIGHT  ::GameEngine::Mouse::ButtonRight
#define GE_MOUSE_BUTTON_MIDDLE ::GameEngine::Mouse::ButtonMiddleE    GE_MOUSE_BUTTON_3