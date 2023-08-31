#pragma once
#include "UIPanel.h"

class GameOverUIPanel : public UIPanel
{
	void initialiseButtons();

public:
	GameOverUIPanel(Vector2i res);
	void virtual draw(RenderWindow& window);
};