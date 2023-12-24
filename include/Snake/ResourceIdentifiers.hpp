#pragma once

// Forward declaration of SFML classes
namespace sf
{
	class Font;
}

namespace Resource
{
	enum Font
	{
		Regular
	};
}

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

namespace Application
{
	typedef ResourceHolder<sf::Font, Resource::Font> FontHolder;
}
