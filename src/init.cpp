#include <archive.h>
#include <biome.h>
#include <init.h>
#include <item_data.h>
#include <log.h>
#include <material.h>
#include <task.h>
#include <tile.h>
#include <util/file_path.h>
#include <log.h>
#include <core/file_system.h>

#if defined(__unix__)
# include <unistd.h>
#else
# include <windows.h>
#endif

static bool make_save_path(const char* path)
{
    const char* p;

    p = save_path(path);
    if (!FileSystem::mkpath(p))
    {
        log_line(LogLevel::Fatal, "Could not create dir: %s", p);
        return false;
    }
    return true;
}

static bool make_game_paths()
{
    return make_save_path("worlds");
}

bool init_game_data()
{
    bool good;
    Archive archive;
	uint32_t pid;

#if defined(WIN32)
	pid = GetCurrentProcessId();
#else
	pid = getpid();
#endif

    log_line(LogLevel::Info, "Game started with PID %u", pid);

    good = true;
    good &= make_game_paths();
    log_line(LogLevel::Info, "Loading game data");
    archive.open(data_path("/supremacy.bin"));
    Tile::load(archive);
    Material::load(archive);
    ItemData::load(archive);
    Biome::load(archive);
    Task::load(archive);
    log_line(LogLevel::Info, "Game data loaded");
    return good;
}
