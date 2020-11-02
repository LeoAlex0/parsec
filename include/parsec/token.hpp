#ifndef __PARSEC_TOKEN_HPP_
#define __PARSEC_TOKEN_HPP_

#include "parsec/basic.hpp"

#include <functional>

namespace parsec {
  struct GeneralParserSyntax {
    const std::function<ParseResult(std::string_view)> doParse;
  };

  GeneralParserSyntax Token(std::string s);

  constexpr auto operator""_T(const char *s, size_t n) {
    struct EqFunc {
      const char * s;
      const size_t n;
      ParseResult  doParse(std::string_view x) const noexcept {
        auto [ iter1, iter2 ] = std::mismatch(s, s + n, x.begin(), x.end());

        return ParseResult{.isAccept = iter1 == s + n,
                           .matched  = x.substr(0, iter2 - x.begin()),
                           .rest     = x.substr(iter2 - x.begin())};
      }
    } ret{s, n};
    return ret;
  }

}

#endif