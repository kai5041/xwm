#include <xwm/architecture.hpp>
#include <xwm/cli.hpp>
#include <xwm/utils.hpp>

#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

namespace xwm {

int load_shared_lib(const std::string &lib_path, Cli &cli) {
#ifdef _WIN32
  HMODULE handle = LoadLibraryA(lib_path.c_str());
  if (!handle) {
    std::cerr << "Failed to open library: " << GetLastError() << std::endl;
    return -3;
  }

  using LoadFunc = Architecture *(__cdecl *)(Vec<std::string>);
  LoadFunc load_architecture_impl =
      reinterpret_cast<LoadFunc>(reinterpret_cast<void *>(
          GetProcAddress(handle, "load_architecture_impl")));

  if (!load_architecture_impl) {
    std::cerr << "Cannot load symbol 'load_architecture_impl': "
              << GetLastError() << std::endl;
    FreeLibrary(handle);
    return -1;
  }

  Architecture *arch = load_architecture_impl(cli.get_args());
  int result = arch->run();
  delete arch;

  FreeLibrary(handle);
  return result;

#else
  void *handle = dlopen(lib_path.c_str(), RTLD_NOW);
  if (!handle) {
    std::cerr << "Failed to open library: " << dlerror() << std::endl;
    return -3;
  }

  dlerror();

  using LoadFunc = Architecture *(*)(Vec<std::string>);
  LoadFunc load_architecture_impl =
      reinterpret_cast<LoadFunc>(dlsym(handle, "load_architecture"));
  const char *dlsym_error = dlerror();
  if (dlsym_error) {
    std::cerr << "Cannot load symbol 'load_architecture': " << dlsym_error
              << std::endl;
    dlclose(handle);
    return -1;
  }

  Architecture *arch = load_architecture_impl(cli.get_args());
  int result = arch->run();
  delete arch;

  dlclose(handle);
  return result;
#endif
}

int load_architecture(Cli &cli) {
  if (cli.get_args().empty()) {
    log_message(LogLevel::_ERROR, "No architecture image provided.");
    return 1;
  }

  return load_shared_lib(cli.get_args()[0], cli);
}

} // namespace xwm
