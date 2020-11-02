#include "parsec.hpp"
#include <algorithm>

namespace parsec {
  GeneralParserSyntax Token(std::string s) {
    return GeneralParserSyntax{[ s ](std::string_view view) {
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
