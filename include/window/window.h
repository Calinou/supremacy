#ifndef WINDOW_H
#define WINDOW_H

#include <types.h>
#include <non_copyable.h>

enum class WindowType
{
    SDL2,
    Cocoa,
    Win32
};

enum class WindowRenderApi
{
    OpenGL,
    Vulkan
};

class Keyboard;
class Window : private NonCopyable
{
public:
    Window();
    virtual ~Window();

    uint32_t        width() const { return _width; }
    uint32_t        height() const { return _height; }
    virtual void    swap() = 0;
    virtual void    poll(Keyboard& keyboard) = 0;

    static Window*  create(WindowType type, WindowRenderApi api, int major, int minor);

protected:
    uint32_t    _width;
    uint32_t    _height;
};

#endif