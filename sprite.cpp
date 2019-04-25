
#include "headers.h"



Sprite::Sprite(std::string fname) {
    glGenTextures(1, &ID);

    glBindTexture(GL_TEXTURE_2D, ID);

    unsigned char *data = stbi_load(fname.c_str(),&width, &height, &nrChannels, 0);
    if(data) {
        GLenum format = GL_RGB;
        if(fname.substr(fname.length()-4) == ".png")
            format = GL_RGBA;
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else std::cout << "Failed to load " << fname << std::endl;
    stbi_image_free(data);
}
