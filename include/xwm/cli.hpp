#pragma once

#include <xwm/defs.hpp>
#include <functional>
#include <string>
#include <string_view>

namespace xwm {

class Cli;

struct Command {
    std::string args;
    std::string description;
    std::function<int(Cli &)> handler;

    Command(std::string_view a, std::string_view desc,
            std::function<int(Cli &)> h);
};

class Cli {
private:
    Vec<Command> commands;
    Vec<std::string> args;

public:
    Cli();

    void register_command(Command cmd);
    int run(const Vec<std::string> &args);
    void print_help() const;

    Vec<std::string> &get_args() { return args; }
};

} // namespace xwm
