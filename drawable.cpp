#include "headers.h"

Drawable::Drawable(Sprite *s, int x, int y) {
    todraw = true;
    sprite = s;
    this->x = x;
    this->y = y;
    width = s->width;
    height = s->height;
}

void Drawable::draw(Shader *shader) {
    /**TODO: create MVP and assign as uniforms*/
    /** Set uniform texture */
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, sprite->ID);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Drawable::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

void Drawable::setSprite(Sprite *s) {
    sprite = s;
}

void Drawable::setSize(int width, int height) {
    this->width = width;
    this->height = height;
}
