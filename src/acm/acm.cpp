#include "acm.h"

// -----------------------------------------------------------------------------
// ArithmeticalCongruenceMonoid: Public instance functions
// -----------------------------------------------------------------------------

ArithmeticalCongruenceMonoid::ArithmeticalCongruenceMonoid(int a, int b):
  m_factorizations{std::make_pair(1, vector<vector<int>>{})},
  m_irreducible{std::make_pair(1, true)}
{
  if(a % b != (int)std::pow(a, 2) % b)
    throw std::domain_error("a and a^2 must be equivalent mod b");
  m_b = b;
  m_a = a % b;
}

vector<int>
ArithmeticalCongruenceMonoid::elements(int n)
{
  return elements(m_a, n);
}

vector<int>
ArithmeticalCongruenceMonoid::elements(int s, int n)
{
  int i = s-(s-m_a)%m_b;
  vector<int> e;
  for (int j = 0; j < n; ++j, i+=(m_b))
    e.push_back(i);
  return e;
}

bool
ArithmeticalCongruenceMonoid::in(int n)
{
  return n % m_b == m_a;
}

set<int>
ArithmeticalCongruenceMonoid::divisors(int n)
{
  set<int> ds;
  auto dsA = ::divisors(n);
  std::for_each(dsA.begin(), dsA.end(),
      [&ds,this](int d) { if (in(d)) { ds.insert(d); } });
  return ds;
}

const vector<vector<int>>&
ArithmeticalCongruenceMonoid::factorizations(int n)
{
  if (m_factorizations.count(n))
    return m_factorizations.at(n);
  return ACMFactor(n);
}

bool ArithmeticalCongruenceMonoid::irreducible(int n)
{
  if (m_irreducible.count(n))
    return m_irreducible.at(n);
  // ...
  m_irreducible.insert(std::make_pair(n, true)); // TODO
  return m_irreducible.at(n);
}

// -----------------------------------------------------------------------------
// ArithmeticalCongruenceMonoid: Private instance functions
// -----------------------------------------------------------------------------

const vector<vector<int>>&
ArithmeticalCongruenceMonoid::ACMFactor(int n)
{
  if (m_factorizations.count(n)) {
    return m_factorizations.at(n);
  }
  // Initialize empty list of factorizations for n and get the reference
  m_factorizations.insert(std::make_pair(n, vector<vector<int>>{}));
  vector<vector<int>> &fs = m_factorizations.at(n);
  // If n not ACM element
  if (!in(n)) {
    return fs;
  }
  auto ds = divisors(n);
  // If divisors only 1 and n
  if (ds.size()==2) {
    fs.push_back({n});
    return fs;
  }
  for (auto di = next(ds.begin()); di != prev(ds.end()); ++di) {
    int d = *di;
    int dd = n/d;
    if (d <= dd) {
      break;
    }
    auto dfs = ACMFactor(d);
    auto ddfs = ACMFactor(dd);
    for (auto df: dfs) {
      for (auto ddf: ddfs) {
        vector<int> nf;
        nf.reserve(df.size()+ddf.size());
        nf.insert(nf.end(), df.begin(), df.end());
        nf.insert(nf.end(), ddf.begin(), ddf.end());
        fs.emplace_back(std::move(nf));
      }
    }
  }
  return fs;
}

// -----------------------------------------------------------------------------
// Non-member functions
// -----------------------------------------------------------------------------

std::ostream& operator<<(
    std::ostream& os,
    const ArithmeticalCongruenceMonoid& obj)
{
  return (os << (std::string)obj);
}
