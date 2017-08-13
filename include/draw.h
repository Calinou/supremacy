#ifndef DRAW_H
#define DRAW_H

#include <types.h>

class DrawBuffer;
struct World;
class Selection;

void draw_selection(DrawBuffer& draw_buffer, World& world, Selection& selection, u32 render_tick);
void draw_world(DrawBuffer& draw_buffer, World& world, Game& game, u32 render_tick);

#endif