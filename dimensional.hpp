#include <iostream>

template <typename T, int m, int s, int kg>
struct value {
  value(T t): t(t) {}

  T t;
};

template<typename T>
using meter = value<T,1,0,0>;

template<typename T>
using seconds = value<T,0,1,0>;

template<typename T>
using joule = value<T,2,-2,1>;

template <typename T, int m, int s, int kg>
value<T,m,s,kg> operator+(
  value<T,m,s,kg> const& a,
  value<T,m,s,kg> const& b
) {
  return a.t + b.t;
};

template <typename T, int m, int s, int kg>
value<T,m,s,kg> operator-(
  value<T,m,s,kg> const& a,
  value<T,m,s,kg> const& b
) {
  return a.t - b.t;
};

template <typename T, int m1, int s1, int kg1, int m2, int s2, int kg2>
value<T,m1 + m2,s1 + s2,kg1 + kg2> operator*(
  value<T,m1,s1,kg1> const& a,
  value<T,m2,s2,kg2> const& b
) {
  return a.t * b.t;
};

template <typename T, int m1, int s1, int kg1, int m2, int s2, int kg2>
value<T,m1 - m2,s1 - s2,kg1 - kg2> operator/(
  value<T,m1,s1,kg1> const& a,
  value<T,m2,s2,kg2> const& b
) {
  return a.t / b.t;
};

template <typename T, int m, int s, int kg>
std::ostream& operator<< (std::ostream& o, value<T,m,s,kg> v) {
  o << v.t;

  if (m != 0) { o << "m^" << m; }
  if (s != 0) { o << "s^" << s; }
  if (kg != 0) { o << "kg^" << kg; }

  return o;
}
