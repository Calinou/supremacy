#ifndef ITEMS_H
#define ITEMS_H

#include <item_id.h>
#include <types.h>
#include <vector>
#include <math/vector.h>

class Items
{
public:
    Items();
    ~Items();

    int     add(ItemID item_id, Vector3i pos, u16 item_count);
    void    remove(int id);

    ItemID  item_id(int id) const { return _item_id[id]; }
    Vector3i    pos(int id) const { return _pos[id]; }
    int     count() const { return _count; }
    u16     item_count(int id) const { return _item_count[id]; }

    void    set_pos(int id, Vector3i pos);
    void    set_item_count(int id, u16 item_count);

private:
    std::vector<ItemID>     _item_id;
    std::vector<Vector3i>       _pos;
    std::vector<int>        _free;
    std::vector<u16>        _item_count;
    int                     _count;
};

#endif
