#include "parsec.hpp"
#include <algorithm>

namespace parsec {
  ParserSyntax Token(std::string s) {
    return ParserSyntax{[ s ](std::string_view view) {
      auto [ iter1, iter2 ]   = std::mismatch(s.begin(), s.end(), view.begin());
      const size_t matchedLen = iter2 - view.begin();
      return ParseResult{
          .isAccept = iter1 == s.end(),
          .matched  = view.substr(0, matchedLen),
          .rest     = view.substr(matchedLen),
      };
    }};
  }
} // namespace parsec
