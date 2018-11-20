#pragma once

#include <cmath>
#include <vector>
#include <set>
#include <utility>
#include <string>
#include <sstream>
#include <iostream>
#include <type_traits>

using std::vector;
using std::set;
using std::pair;
using std::string;
using std::stringstream;
using std::ostream;

using std::to_string;

ostream& operator<<(ostream& os, pair<int,int> obj);
ostream& operator<<(ostream& os, vector<int> obj);
ostream& operator<<(ostream& os, vector<vector<int>> obj);
ostream& operator<<(ostream& os, vector<pair<int,int>> obj);

namespace is_stl_container_impl
{
  template <typename T> struct is_stl_container:std::false_type{};
  template <typename T, std::size_t N> struct is_stl_container<std::array<T,N>>    :std::true_type{};
  template <typename... Args> struct is_stl_container<std::vector<Args...>>:std::true_type{};
}

template <typename T> struct is_container {
  static constexpr bool const value = is_stl_container_impl::is_stl_container<std::decay_t<T>>::value;
};

template
<template<typename ...> class Tc, typename T>
inline string join(
    const Tc<T> &c,
    const string &delim,
    const string &lcap="(",
    const string &rcap=")")
{
  stringstream ss;
  ss << lcap;
  if (c.size() > 0) {
    auto end = prev(c.end());
    for (auto i = c.begin(); i != end; ++i) {
      ss << (*i) << delim;
    }
    ss << *prev(c.end());
  }
  ss << rcap;
  return ss.str();
};

template
  <template<typename ...> class Tc, template<typename ...> class Dc, typename T>
inline string join(
    const Dc<Tc<T>> &c,
    const string &delim,
    typename std::enable_if<is_container<Tc<T>>::value>::type* = 0,
    typename std::enable_if<is_container<Dc<T>>::value>::type* = 0)
{
  vector<string> s;
  std::for_each(c.begin(), c.end(),
      [&delim,&s](const Tc<T> &i){ s.push_back(join(i, delim)); });
  return join(s, delim);
};


/// Temporary QOL printing functions

template<typename T>
inline string to_string(pair<T,T> obj)
{
  stringstream ss;
  ss << "(" << obj.first << "," << obj.second << ")";
  return ss.str();
}

inline ostream& operator<<(ostream& os, pair<int,int> obj)
{
  return os << to_string(obj);
}

inline ostream& operator<<(ostream& os, set<int> obj)
{
  return os << join(obj, ",");
}

inline ostream& operator<<(ostream& os, vector<int> obj)
{
  return os << join(obj, ",");
}

inline ostream& operator<<(ostream& os, vector<vector<int>> obj)
{
  return os << join(obj, ",");
}

inline ostream& operator<<(ostream& os, vector<pair<int,int>> obj)
{
  return os << join(obj, ",");
}
