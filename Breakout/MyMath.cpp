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
}