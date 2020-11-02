#ifndef __PARSEC_PRIMITIVE_HPP
#define __PARSEC_PRIMITIVE_HPP

#include "parsec/basic.hpp"
#include "parsec/primitive.hpp"
#include "parsec/token.hpp"

namespace parsec {
  struct PrimitiveParserSyntax {
    ParseResult (*const doParse)(std::string_view);
  };

  constexpr PrimitiveParserSyntax Epsilon{
      .doParse = [](std::string_view v) noexcept -> ParseResult {
        return ParseResult{
            .isAccept = true,
            .matched  = "",
            .rest     = v,
        };
      }};

  constexpr PrimitiveParserSyntax Void{
      .doParse = [](std::string_view v) noexcept -> ParseResult {
        return ParseResult{
            .isAccept = false,
            .matched  = "",
            .rest     = v,
        };
      }};

  constexpr PrimitiveParserSyntax Eof{.doParse = [](std::string_view v) {
    return ParseResult{v == "", v, v};
  }};
}

#endif // __PARSEC_PRIMITIVE_HPP