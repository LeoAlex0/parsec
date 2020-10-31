#ifndef __OUTPUT_HPP_
#define __OUTPUT_HPP_

#include "parsec.hpp"
#include <ostream>

namespace parsec {
  std::ostream &operator<<(std::ostream &out, ParseResult result) {
    return out << std::boolalpha << "ParserSyntax {" << std::endl
               << "\t.isAccept=" << result.isAccept << std::endl
               << "\t.matched=\"" << result.matched << "\"" << std::endl
               << "\t.rest=\"" << result.rest << "\"" << std::endl
               << "}";
  }
} // namespace parsec

#endif // __OUTPUT_HPP_
