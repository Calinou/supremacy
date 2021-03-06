#include <items.h>
#include <item_data.h>

Items::Items()
: _count(0)
{
}

Items::~Items()
{
}

int Items::add(ItemID item_id, Vector3i pos, u16 item_count)
{
    if (_free.size() > 0)
    {
        int id = _free.back();
        _free.pop_back();
        _item_id[id] = item_id;
        _pos[id] = pos;
        _item_count[id] = item_count;
        return id;
    }
    else
    {
        _item_id.push_back(item_id);
        _pos.push_back(pos);
        _item_count.push_back(item_count);
        return _count++;
    }
}

void Items::remove(int id)
{
    _item_id[id] = 0;
    _free.push_back(id);
}

void Items::set_pos(int id, Vector3i pos)
{
    _pos[id] = pos;
}

void Items::set_item_count(int id, u16 item_count)
{
    _item_count[id] = item_count;
}
