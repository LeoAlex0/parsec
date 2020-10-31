#include "output.hpp"
#include "parsec.hpp"
#include <iostream>

using namespace parsec;

int main(int argc, char *argv[]) {
  if (argc > 1) {
    auto tok    = "demo"_T;
    auto parsed = tok.doParse(argv[ 1 ]);

    std::cout << parsed << std::endl;
  } else {
    std::cout << "will parse \"demo\"_T on argv[1]" << std::endl;
  }
  return 0;
}
