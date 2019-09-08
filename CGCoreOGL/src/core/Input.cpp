#include "core/Input.h"

std::map<int, bool> Input::KeyPressed =
{
	{   GLFW_KEY_UNKNOWN, false},
	{   GLFW_KEY_SPACE, false},
	{   GLFW_KEY_APOSTROPHE, false},
	{   GLFW_KEY_COMMA, false},
	{   GLFW_KEY_MINUS, false},
	{   GLFW_KEY_PERIOD , false},
	{   GLFW_KEY_SLASH  , false},
	{	GLFW_KEY_0   , false},
	{	GLFW_KEY_1   , false},
	{	GLFW_KEY_2   , false},
	{	GLFW_KEY_3   , false},
	{	GLFW_KEY_4   , false},
	{	GLFW_KEY_5   , false},
	{	GLFW_KEY_6   , false},
	{	GLFW_KEY_7   , false},
	{	GLFW_KEY_8   , false},
	{	GLFW_KEY_9   , false},
	{	GLFW_KEY_SEMICOLON, false},
	{	GLFW_KEY_EQUAL , false},
	{	GLFW_KEY_A , false},
	{	GLFW_KEY_B  , false},
	{	GLFW_KEY_C , false},
	{	GLFW_KEY_D , false},
	{	GLFW_KEY_E , false},
	{	GLFW_KEY_F  , false},
	{	GLFW_KEY_G  , false},
	{	GLFW_KEY_H  , false},
	{	GLFW_KEY_I  , false},
	{	GLFW_KEY_J  , false},
	{	GLFW_KEY_K , false},
	{	GLFW_KEY_L  , false},
	{	GLFW_KEY_M  , false},
	{	GLFW_KEY_N  , false},
	{	GLFW_KEY_O  , false},
	{	GLFW_KEY_P  , false},
	{	GLFW_KEY_Q  , false},
	{	GLFW_KEY_R  , false},
	{	GLFW_KEY_S  , false},
	{	GLFW_KEY_T  , false},
	{	GLFW_KEY_U  , false},
	{	GLFW_KEY_V  , false},
	{	GLFW_KEY_W  , false},
	{	GLFW_KEY_X  , false},
	{	GLFW_KEY_Y  , false},
	{	GLFW_KEY_Z  , false},
	{	GLFW_KEY_LEFT_BRACKET, false},
	{	GLFW_KEY_BACKSLASH, false},
	{	GLFW_KEY_RIGHT_BRACKET, false},
	{	GLFW_KEY_GRAVE_ACCENT, false},
	{	GLFW_KEY_WORLD_1 , false},
	{	GLFW_KEY_WORLD_2 , false},
	{	GLFW_KEY_ESCAPE , false},
	{	GLFW_KEY_ENTER , false},
	{	GLFW_KEY_TAB , false},
	{	GLFW_KEY_BACKSPACE , false},
	{	GLFW_KEY_INSERT , false},
	{	GLFW_KEY_DELETE , false},
	{	GLFW_KEY_RIGHT , false},
	{	GLFW_KEY_LEFT, false},
	{	GLFW_KEY_DOWN, false},
	{	GLFW_KEY_UP, false},
	{	GLFW_KEY_PAGE_UP , false},
	{	GLFW_KEY_PAGE_DOWN , false},
	{	GLFW_KEY_HOME , false},
	{	GLFW_KEY_END , false},
	{	GLFW_KEY_CAPS_LOCK , false},
	{	GLFW_KEY_SCROLL_LOCK , false},
	{	GLFW_KEY_NUM_LOCK , false},
	{	GLFW_KEY_PRINT_SCREEN , false},
	{	GLFW_KEY_PAUSE , false},
	{	GLFW_KEY_F1   , false},
	{	GLFW_KEY_F2   , false},
	{	GLFW_KEY_F3   , false},
	{	GLFW_KEY_F4   , false},
	{	GLFW_KEY_F5   , false},
	{	GLFW_KEY_F6   , false},
	{	GLFW_KEY_F7   , false},
	{	GLFW_KEY_F8   , false},
	{	GLFW_KEY_F9   , false},
	{	GLFW_KEY_F10  , false},
	{	GLFW_KEY_F11  , false},
	{	GLFW_KEY_F12  , false},
	{	GLFW_KEY_F13  , false},
	{	GLFW_KEY_F14  , false},
	{	GLFW_KEY_F15  , false},
	{	GLFW_KEY_F16  , false},
	{	GLFW_KEY_F17  , false},
	{	GLFW_KEY_F18  , false},
	{	GLFW_KEY_F19  , false},
	{	GLFW_KEY_F20  , false},
	{	GLFW_KEY_F21  , false},
	{	GLFW_KEY_F22  , false},
	{	GLFW_KEY_F23  , false},
	{	GLFW_KEY_F24  , false},
	{	GLFW_KEY_F25  , false},
	{	GLFW_KEY_KP_0 , false},
	{	GLFW_KEY_KP_1 , false},
	{	GLFW_KEY_KP_2 , false},
	{	GLFW_KEY_KP_3 , false},
	{	GLFW_KEY_KP_4 , false},
	{	GLFW_KEY_KP_5 , false},
	{	GLFW_KEY_KP_6 , false},
	{	GLFW_KEY_KP_7 , false},
	{	GLFW_KEY_KP_8 , false},
	{	GLFW_KEY_KP_9 , false},
	{	GLFW_KEY_KP_DECIMAL , false },
	{	GLFW_KEY_KP_DIVIDE , false },
	{	GLFW_KEY_KP_MULTIPLY , false },
	{	GLFW_KEY_KP_SUBTRACT , false },
	{	GLFW_KEY_KP_ADD , false },
	{	GLFW_KEY_KP_ENTER , false },
	{	GLFW_KEY_KP_EQUAL , false },
	{	GLFW_KEY_LEFT_SHIFT , false },
	{	GLFW_KEY_LEFT_CONTROL , false },
	{	GLFW_KEY_LEFT_ALT , false },
	{	GLFW_KEY_LEFT_SUPER , false },
	{	GLFW_KEY_RIGHT_SHIFT , false },
	{	GLFW_KEY_RIGHT_CONTROL , false },
	{	GLFW_KEY_RIGHT_ALT , false },
	{	GLFW_KEY_RIGHT_SUPER , false },
	{	GLFW_KEY_MENU  , false },
	{	GLFW_KEY_LAST   , false },
	{ GLFW_KEY_MENU, false }
};

bool Input::MouseMoved = false;
bool Input::MouseOnePreesed = false;
bool Input::MouseTwoPreesed = false;
bool Input::MouseThreePreesed = false;
float Input::MouseX = 0;
float Input::MouseY = 0;

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	Input::MouseMoved = true;

	Input::MouseX = xpos;
	Input::MouseY = ypos;
}


Input::Input(GLFWwindow * win)
	:window(win)
{
	glfwSetCursorPosCallback(window, mouse_callback);
}


Input::~Input()
{
}

void Input::Update()
{
	for (auto& kv : Input::KeyPressed) {
		kv.second = glfwGetKey(window, kv.first) == GLFW_PRESS;
	}
	Input::MouseOnePreesed = GLFW_PRESS == glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1);
	Input::MouseTwoPreesed = GLFW_PRESS == glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_2);
	Input::MouseThreePreesed = GLFW_PRESS == glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_3);
}
