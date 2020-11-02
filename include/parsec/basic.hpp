#ifndef __PARSEC_BASIC_HPP_
#define __PARSEC_BASIC_HPP_

#include <string_view>

namespace parsec {
  struct ParseResult {
    bool             isAccept;
    std::string_view matched;
    std::string_view rest;
  };
}

#endif // __PARSEC_BASIC_HPP_