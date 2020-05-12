#pragma once

#include "IO.hpp"

#ifdef LOCAL
void signalHandler(int) {
  throw "Abort detected";
}
#endif

void doReplace() {
}

template <typename T, typename U, typename...Vs>
void doReplace(T &t, const U &u, Vs &&...vs) {
  t = u;
  doReplace(vs...);
}

template <typename T, typename...Us>
T minim(T &was, const T &cand, Us &&...us) {
  if (was > cand) {
    was = cand;
    doReplace(us...);
  }
  return was;
}

template <typename T, typename...Us>
T maxim(T &was, const T &cand, Us &&...us) {
  if (was < cand) {
    was = cand;
    doReplace(us...);
  }
  return was;
}