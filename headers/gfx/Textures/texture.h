#ifndef TEXTURE_H
#define TEXTURE_H
#pragma once
#include <iostream>
#include <string>
#include <vector>

#define NO_TEXTURE "!ROOT!/headers/gfx/Textures/std/untextured.jpg"
//#define NO_TEXTURE "!ROOT!/data/textures/std/untextured.jpg"

// ttexture = Type Texture
typedef std::string ttexture;

class texture {
private:
    ttexture text;
public:
    texture(ttexture texture_ = NO_TEXTURE) { text = texture_; }
    texture operator=(ttexture texture_) { text = texture_; }
    texture get() { return text; }
    void update(ttexture texture_) { text = texture_; }
    virtual ~texture() {}
};

#endif // TEXTURE_H
