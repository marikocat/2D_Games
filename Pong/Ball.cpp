#include "Ball.h"

// This the constructor function
Ball::Ball(float startX, float startY)
{
	m_Position.x = startX;
	m_Position.y = startY;

	m_Shape.setSize(Vector2f(10, 10));
	m_Shape.setPosition(m_Position);
}

FloatRect Ball::getPosition()
{
	return m_Shape.getGlobalBounds();
}

RectangleShape Ball::getShape()
{
	return m_Shape;
}

float Ball::getXVelocity()
{
	return m_DirectionX;
}

void Ball::reboundLeft()
{
	m_DirectionX = -m_DirectionX;
	m_Position.x = 0;
}

void Ball::reboundRight()
{
	m_DirectionX = -m_DirectionX;
	m_Position.x = 1920 - m_Shape.getSize().x;
}

void Ball::reboundBat(int batY)
{
	m_DirectionY = -m_DirectionY;
	m_Position.y = batY - m_Shape.getSize().y;

	// Speed up a little bit on each hit
	m_Speed *= 1.2f;
}

void Ball::reboundTop()
{
	m_DirectionY = -m_DirectionY;
	m_Position.y = 0;
}

void Ball::reboundBottom()
{
	m_Position.y = 0;
	m_Position.x = 500;
}

void Ball::resetSpeed()
{
	m_Speed = 1000.0f;
}

void Ball::update(Time dt)
{
	// Update the ball's position
	m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();
	m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();

	// Move the ball
	m_Shape.setPosition(m_Position);
}