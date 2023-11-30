#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include<string>

#include <GL/glew.h>

#include<stb/stb_image.h>

class Texture
{
public:
	Texture(GLenum TextureTarget, const std::string& filename);

    bool Load();

    void Bind(GLenum TextureUnit);

private:
    std::string m_fileName;
    GLenum m_textureTarget;
    GLuint m_textureObj;
};
#endif