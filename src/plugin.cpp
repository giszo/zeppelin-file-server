#include "fileserver.h"

namespace zeppelin
{
namespace library
{
class MusicLibrary;
}
namespace player
{
class Controller;
}
}

// =====================================================================================================================
extern "C"
std::shared_ptr<zeppelin::plugin::Plugin> plugin_create(const std::shared_ptr<zeppelin::library::MusicLibrary>& library,
							const std::shared_ptr<zeppelin::player::Controller>& ctrl)
{
    return std::make_shared<FileServer>();
}
