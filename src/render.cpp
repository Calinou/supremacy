#include <wish.h>
#include <game.h>
#include <tile.h>
#include <material.h>

void game_render(Game& game)
{
    int x;
    int y;

    bool under;
    wish_attr attr;
    wish_size size;

    wish_attr_init(&attr);
    wish_get_view_size(game.screen.screen, &size);
    wish_clear(game.screen.term);

    for (int j = 0; j < size.y; ++j)
    {
        y = game.camera_y + j;
        wish_move(game.screen.screen, 0, j);
        for (int i = 0; i < size.x; ++i)
        {
            x = game.camera_x + i;
            if (1 || game.map.visible(x, y, game.camera_depth))
            {
                TileID tile_id;
                MaterialID material_id;

                under = false;
                game.map.at(x, y, game.camera_depth, tile_id, material_id);

                if (tile_id == TileID::None)
                {
                    under = true;
                    game.map.at(x, y, game.camera_depth - 1, tile_id, material_id);
                }

                const Tile& tile = Tile::from_id(tile_id);
                const Material& material = Material::from_id(material_id);

                if (under)
                {
                    wish_color(&attr, material.dim_color);
                    wish_bcolor(&attr, material.dim_bgcolor);
                }
                else
                {
                    wish_color(&attr, material.color);
                    wish_bcolor(&attr, material.bgcolor);
                }
                wish_putchar(game.screen.screen, tile.sym, attr);
            }
            else
            {
                wish_color(&attr, 0);
                wish_bcolor(&attr, 0);
                wish_putchar(game.screen.screen, ' ', attr);
            }
        }
    }

    wish_draw(game.screen.term);
}
