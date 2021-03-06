#ifndef GAME_H
#define GAME_H

#include <non_copyable.h>
#include <engine/game_scene.h>
#include <engine/input.h>
#include <math/rng.h>
#include <thread_pool.h>
#include <rendering/renderer.h>
#include <draw_buffer.h>
#include <fps_counter.h>

class Window;
class GameScene;
class Game : NonCopyable
{
public:
    Game();
    ~Game();

    Input&      input() { return _input; }
    Window&     window() { return *_window; }
    Rng&        rng() { return _rng; }
    ThreadPool& thread_pool() { return _thread_pool; }
    Renderer&   renderer() { return *_renderer; }
    DrawBuffer& draw_buffer() { return _draw_buffer; }
    FpsCounter& fps_counter_update() { return _fps_counter_update; }
    FpsCounter& fps_counter_render() { return _fps_counter_render; }

    template <typename T, typename... Ts>
    T* set_scene(Ts... args)
    {
        T* scene;

        scene = new T(args...);
        scene->set_game(*this);
        if (_next_scene)
            delete _next_scene;
        _next_scene = scene;
        return scene;
    }

    void    loop();
    void    stop();
    void    select_renderer();

private:
    void    update();
    void    render();
    void    handle_events();

    Input       _input;
    Window*     _window;
    Rng         _rng;
    ThreadPool  _thread_pool;
    Renderer*   _renderer;
    DrawBuffer  _draw_buffer;
    GameScene*  _scene;
    GameScene*  _next_scene;
    FpsCounter  _fps_counter_update;
    FpsCounter  _fps_counter_render;
    bool        _running;
};

#endif
