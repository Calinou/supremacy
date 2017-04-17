#ifndef ACTORS_H
#define ACTORS_H

#include <vector>
#include <actor_id.h>
#include <vec3.h>

class Actors
{
public:
    Actors();
    ~Actors();

    int         add(ActorID actor_id, Vec3 pos);
    void        remove(int id);
    void        increment(int id);
    void        decrement(int id);

    ActorID     actor_id(int id) const { return _actor_id[id]; }
    Vec3        pos(int id) const { return _pos[id]; }
    int         health(int id) const { return _health[id]; }
    int         speed(int id) const { return _speed[id]; }
    int         count() const { return _count; }

    void        set_pos(int id, Vec3 pos);
    void        set_health(int id, int health);
    void        set_speed(int id, int speed);

private:
    std::vector<ActorID>    _actor_id;
    std::vector<Vec3>       _pos;
    std::vector<int>        _health;
    std::vector<int>        _speed;
    std::vector<int>        _counter;
    std::vector<int>        _free;
    int                     _count;
};

#endif