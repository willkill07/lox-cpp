target_sources(lox PRIVATE driver.cpp input_stream_context.cpp)
target_include_directories(lox PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(lox PRIVATE tl::expected tl::optional fmt::fmt CLI11::CLI11)
