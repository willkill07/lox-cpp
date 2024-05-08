#include <cstdlib>
#include <iostream>
#include <span>
#include <string_view>

#include <CLI/CLI.hpp>
#include <fmt/core.h>

#include "input_stream_context.hpp"

void echo(std::istream &is) {
  std::string line;
  int lineno{0};
  while (std::getline(is, line)) {
    fmt::println("{:<5d}: {}", ++lineno, line);
  }
}

void run(std::span<std::string const> args) {
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
  std::vector<std::string> files;
  CLI::App app{"A Lox Language Interpreter", "Lox"};
  app.add_option("files", files, "files to load into the interpreter");
  CLI11_PARSE(app, argc, argv);
  run(files);
  return EXIT_SUCCESS;
}
