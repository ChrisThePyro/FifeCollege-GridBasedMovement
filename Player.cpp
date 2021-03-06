#include "stdafx.h"
#include "Player.h"
#include "Grid.h"


// Constructor
Player::Player(sf::Texture& _texture)
	: GridSprite(_texture)
{

}

// Handle player movement
bool Player::input(const sf::Event& _event)
{
	// Mark that we have received our input
	m_receivedInput = true;

	if (_event.type == sf::Event::KeyPressed)
	{
		// Handle movement
		if (_event.key.code == sf::Keyboard::Up
			|| _event.key.code == sf::Keyboard::Down
			|| _event.key.code == sf::Keyboard::Left
			|| _event.key.code == sf::Keyboard::Right)
		{
			int targetX = m_gridX;
			int targetY = m_gridY;

			if (_event.key.code == sf::Keyboard::Up)
			{
				--targetY;
			}
			else if (_event.key.code == sf::Keyboard::Down)
			{
				++targetY;
			}
			else if (_event.key.code == sf::Keyboard::Left)
			{
				--targetX;
			}
			else if (_event.key.code == sf::Keyboard::Right)
			{
				++targetX;
			}

			// Get the object currently in our target Cell
			GridObject* targetCellObject = m_grid->GetOjbect(targetX, targetY);

			// TODO: perform special actions based on content of target cell
			// (if boulder, push)
			// (if boulder and can't push, don't move)
			// (if diamond, collect)
			// (if closed exit, don't move)
			// (if open exit, go to next level)

			// NOTE: This will automatically delete whatever GridObject is in the target cell!
			m_grid->MoveObject(m_gridX, m_gridY, targetX, targetY);

			// Return true since we handled some input
			return true;
		}
	}
}