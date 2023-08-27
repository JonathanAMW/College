#include <iostream>
#include <stb/stb_image.h>
#include "Texture.h"

Texture::Texture(GLenum TextureTarget, const std::string& FileName)
{
    m_textureTarget = TextureTarget;
    m_fileName = FileName;
}

bool Texture::Load()
{
	// Flips the image so it appears right side up
	stbi_set_flip_vertically_on_load(true);
	// Stores the width, height, and the number of color channels of the image
	int widthImg = 0, heightImg = 0, numColCh = 0;
	// Reads the image from a file and stores it in bytes
	unsigned char* image_data = stbi_load(m_fileName.c_str(), &widthImg, &heightImg, &numColCh, 0);

    if(!image_data)
    {
        std::cout << "Cant load texture from " << m_fileName.c_str() << " - " << stbi_failure_reason();
        exit(0); 
    }

	// Generates an OpenGL texture object
	glGenTextures(1, &m_textureObj);
	glBindTexture(m_textureTarget, m_textureObj);
    if(m_textureTarget == GL_TEXTURE_2D)
    {
        glTexImage2D(m_textureTarget, 0, GL_RGB, widthImg, heightImg, 0, GL_RGB, GL_UNSIGNED_BYTE, image_data);
    } 
    else
    {
        std::cout << "Support for texture target " << m_textureTarget << " is not implemented\n";
        exit(1);
    }

	// Configures the type of algorithm that is used to make the image smaller or bigger
	glTexParameterf(m_textureTarget, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(m_textureTarget, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Configures the way the texture repeats (if it does at all)
	glTexParameterf(m_textureTarget, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(m_textureTarget, GL_TEXTURE_WRAP_T, GL_CLAMP);

    // Unbinds the OpenGL Texture object so that it can't accidentally be modified
	glBindTexture(m_textureTarget, 0);

	// Deletes the image data as it is already in the OpenGL Texture object
	//stbi_image_free(image_data);

	return true;
}


void Texture::Bind(GLenum TextureUnit)
{
    glActiveTexture(TextureUnit);
    glBindTexture(m_textureTarget, m_textureObj);
}