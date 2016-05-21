	#pragma once
	#include <SFML/Graphics.hpp>
	#include "Mandelbrot.hpp"

	class Julia :
		public Mandelbrot
	{
		sf::RenderWindow& m_appWindow;
		double m_cY;
		double m_cX;
	public:
		Julia(sf::RenderWindow& appWindow);

		sf::Vector3f calcColor(int coordX, int coordY) override;

		void setC(sf::Vector2f coord);
	};

