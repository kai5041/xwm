#include <fstream>
#include <functional>
#include <string>

#include <xwm/Dispatcher.hpp>
#include <xwm/Architecture.hpp>
#include <xwm/commands.hpp>
#include <xwm/utils.hpp>

#if defined(_WIN32)
#include <windows.h>
#else
#include <dlfcn.h>
#endif

using ArchitectureEntry = std::function<xwm::Architecture* (xwm::Dispatcher&)>;

namespace xwm {

  u32 load_architecture(Dispatcher& dispatcher) {
    log_if_error(dispatcher.get_args().empty(),
      "Architecture image filename not provided");

    u32 exit_code = 0;
    std::string architecture_path = dispatcher.get_args()[0];

    {
      log_if_error(!(std::ifstream(architecture_path).is_open()),
        "Could not open architecture image: " + architecture_path);
    }

    dispatcher.get_args().erase(dispatcher.get_args().begin());

#if defined(_WIN32)

    HMODULE handle = LoadLibraryA(architecture_path.c_str());
    log_if_error(!handle, "LoadLibrary failed");

    using EntryFn = xwm::Architecture* (__cdecl*)(xwm::Dispatcher&);

    FARPROC sym = GetProcAddress(handle, "entry");
    log_if_error(!sym, "Architecture *entry(Dispatcher &dispatcher) not found");

    EntryFn entry = reinterpret_cast<EntryFn>(sym);

    xwm::Architecture* architecture = entry(dispatcher);
    exit_code = architecture->run();

    FreeLibrary(handle);

#else

    void* handle = dlopen(architecture_path.c_str(), RTLD_LAZY);
    log_if_error(!handle, dlerror());

    using EntryFn = xwm::Architecture* (*)(xwm::Dispatcher&);

    EntryFn entry = reinterpret_cast<EntryFn>(dlsym(handle, "entry"));
    log_if_error(!entry, "Architecture *entry(Dispatcher &dispatcher) not found");

    xwm::Architecture* architecture = entry(dispatcher);
    exit_code = architecture->run();

    dlclose(handle);

#endif

    return exit_code;
  }

} // namespace xwm
