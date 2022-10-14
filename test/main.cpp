#include "image.hpp"

auto main(int argc, const char* argv[]) -> int
{
    IP::Image image("test.jpg");
    image.write("new.png");

    return 0;
}