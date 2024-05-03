#include <iostream>
#include <span>
#include <string_view>

#include <fmt/core.h>
#include <tl/optional.hpp>

#include "input_stream_context.hpp"

void echo(std::istream &is) {
  std::string line;
  int lineno{0};
  while (std::getline(is, line)) {
    fmt::println("{:<5d}: {}", ++lineno, line);
  }
}

void run(std::span<std::string_view const> program_args) {
  [[maybe_unused]] std::string_view program = program_args.front();
  auto args = program_args.subspan(1);
  if (args.empty()) {
    echo(std::cin);
  } else {
    for (std::string_view filename : args) {
      fmt::println("{}", filename);
      InputStreamContext ctx{filename};
      echo(std::cin);
    }
  }
}

int main(int argc, char **argv) {
  std::vector<std::string_view> args;
  args.reserve(argc);
  std::copy_n(argv, argc, std::back_inserter(args));
  run(args);
}
