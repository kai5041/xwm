#include <xwm/cli.hpp>
#include <xwm/utils.hpp>

namespace xwm {

int load_architecture(Cli &cli) {
  if (cli.get_args().size() == 0) {
    log_message(LogLevel::ERROR, "No architecture image provided.");
    return 1;
  }

  std::cout << "Architecture image: " << cli.get_args()[0] << std::endl;

  // select architecture
  return 0;
}

} // namespace xwm