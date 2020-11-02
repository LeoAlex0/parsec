#ifndef __PARSEC_HPP__
#define __PARSEC_HPP__

#include "parsec/basic.hpp"
#include "parsec/primitive.hpp"

#include <functional>

namespace parsec {

  template <typename S, typename T> struct Parsed {
    T value;
    S rest;
  };

  template <typename T> concept SyntaxParser = requires(T a) {
    { a.doParse("") }
    ->std::convertible_to<ParseResult>;
  };
} // namespace parsec

#endif // __PARSEC_HPP__
