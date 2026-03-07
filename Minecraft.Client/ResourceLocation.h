#pragma once
#include "Textures.h"

typedef arrayWithLength<_TEXTURE_NAME> textureNameArray;

class ResourceLocation
{
private:
	textureNameArray m_texture;
	wstring m_path;
	bool m_preloaded;

public:
	ResourceLocation()
	{
		m_preloaded = false;
		m_path = L"";
	}

	ResourceLocation(_TEXTURE_NAME texture)
	{
		m_texture = textureNameArray(1);
		m_texture[0] = texture;
		m_preloaded = true;
	}

	ResourceLocation(const wstring& path)
	{
		m_path = path;
		// Automatically append .png if missing
		if (m_path.length() < 4 || m_path.substr(m_path.length() - 4, 4) != L".png")
		{
			m_path += L".png";
		}
		m_preloaded = false;
	}

	ResourceLocation(intArray textures)
	{
		m_texture = textureNameArray(textures.length);
		for(unsigned int i = 0; i < textures.length; ++i)
		{
			m_texture[i] = (_TEXTURE_NAME)textures[i];
		}
		m_preloaded = true;
	}

	~ResourceLocation()
	{
		delete m_texture.data;
	}

	_TEXTURE_NAME getTexture()
	{
		return m_texture[0];
	}

	_TEXTURE_NAME getTexture(int idx)
	{
		return m_texture[idx];
	}

	int getTextureCount()
	{
		return m_texture.length;
	}

	wstring getPath() const
	{
		return m_path;
	}

	bool isPreloaded() const
	{
		return m_preloaded;
	}

	// Returns full path for loading from folder
	wstring getFullPath() const
	{
		return m_path;
	}
};
