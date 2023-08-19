#pragma once
#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H

#include <SFML/Graphics.hpp>
#include <map>

using namespace sf;
using namespace std;

class TextureHolder
{
	// A map that holds related pairs of string and Texture
	map<string, Texture> m_Textures;

	// A pointer of the same type as the class itself
	// the one and only instance
	static TextureHolder* m_s_Instance;
public:
	TextureHolder();
	static Texture& GetTexture(string const& filename);
};

#endif // !TEXTURE_HOLDER_H
