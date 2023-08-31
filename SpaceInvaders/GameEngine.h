#pragma once
#include <SFML/Graphics.hpp>
#include "ScreenManager.h"
#include "SoundEngine.h"
#include <memory>

using namespace sf;
using namespace std;

class GameEngine
{
	Clock m_Clock;
	Time m_DT;
	RenderWindow m_Window;

	unique_ptr<ScreenManager> m_ScreenManager;

	float m_FPS = 0;
	Vector2f m_Resolution;

	void handleInput();
	void update();
	void draw();

public:
	SoundEngine m_SoundEngine;

	GameEngine();
	void run();
};