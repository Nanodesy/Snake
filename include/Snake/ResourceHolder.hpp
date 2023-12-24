#pragma once
#include <map>
#include <memory>

template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
	void loadFromFile(Identifier id, const std::string &filename);
	Resource& get(Identifier id);
	const Resource& get(Identifier id) const;

	private:
		std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};

#include "ResourceHolder.inl"
