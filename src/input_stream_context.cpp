#include "input_stream_context.hpp"

#include <filesystem>

InputStreamContext::InputStreamContext(std::string_view name)
    : m_file_stream(std::filesystem::path{name}),
      m_old_rdbuf{std::cin.rdbuf(m_file_stream.rdbuf())} {}

InputStreamContext::~InputStreamContext() {
  if (m_old_rdbuf != nullptr) {
    std::cin.rdbuf(m_old_rdbuf);
  }
}
