#ifndef __PARSEC_HPP__
#define __PARSEC_HPP__

#include <functional>
#include <string>
#include <string_view>

namespace parsec {
  struct ParseResult {
    bool             isAccept;
    std::string_view matched;
    std::string_view rest;
  };

  struct ParserSyntax {
    const std::function<ParseResult(std::string_view)> doParse;
  };

  const ParserSyntax Epsilon{[](std::string_view v) {
    return ParseResult{true, v};
  }};

  const ParserSyntax Void{[](std::string_view v) {
    return ParseResult{false, v};
  }};

  const ParserSyntax Eof{[](std::string_view v) {
    return ParseResult{v == "", v};
  }};

  ParserSyntax Token(std::string s);

  inline ParserSyntax operator""_T(const char *s, size_t n) { return Token(s); }

} // namespace parsec

#endif // __PARSEC_HPP__
