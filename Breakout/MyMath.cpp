#include <SFML/Graphics.hpp>

namespace MyMath {

	static sf::Vector2f RandomUnitVector() {
		float angle = float(rand())* (2 * 3.14159265) / float(RAND_MAX);
		return { cos(angle), sin(angle) };
	}
	static sf::Vector2f RandomUpwardUnitVector() {
		float angle = float(rand()) * (2 * 3.14159265) / float(RAND_MAX);
		if (sin(angle) >= 0)
			return { cos(angle), -sin(angle) };
		else
			return { cos(angle), sin(angle) };
	}
	static float lerp(float t, float a, float b) {
		return(1.0f - t) * a + b * t;
	}

	static sf::Color LerpColor(float t, sf::Color a, sf::Color b) {
		return sf::Color(
			a.r = lerp(t, a.r, b.r),
			a.g = lerp(t, a.g, b.g),
			a.b = lerp(t, a.b, b.b)
		);
	}

	static sf::Color RandomColor() {
		return sf::Color(rand() % 255, rand() % 255, rand() % 255);
	}
}