#pragma once

#include <fstream>
#include <iostream>

struct InputStreamContext {
  explicit InputStreamContext(std::string_view name);

  InputStreamContext(InputStreamContext &&) = delete;
  InputStreamContext &operator=(InputStreamContext &&) = delete;

  ~InputStreamContext();

  std::ifstream m_file_stream;
  std::streambuf *m_old_rdbuf;
};
