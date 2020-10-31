#ifndef __FUNCTIONAL_HPP_
#define __FUNCTIONAL_HPP_

namespace parsec {
  template <typename Function, typename... Args>
  auto apply(Function func, Args... args) {
    return [ & ](auto... rest) { return func(args..., rest...); };
  }
} // namespace parsec

#endif // __FUNCTIONAL_HPP_
