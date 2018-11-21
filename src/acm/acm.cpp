#include "acm.h"

// -----------------------------------------------------------------------------
// ArithmeticalCongruenceMonoid: Public instance functions
// -----------------------------------------------------------------------------

ArithmeticalCongruenceMonoid::ArithmeticalCongruenceMonoid(int a, int b):
  m_factorizations{std::make_pair(1, set<vector<int>>{})},
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

const set<vector<int>>&
ArithmeticalCongruenceMonoid::factorizations(int n)
{
  if (m_factorizations.count(n))
    return m_factorizations.at(n);
  return ACMFactor(n);
}

bool ArithmeticalCongruenceMonoid::irreducible(int n)
{
  // If value cached
  if (m_irreducible.count(n))
    return m_irreducible.at(n);

  const auto& fs = ACMFactor(n);
  bool irreducible = fs.size()==0 || (*fs.begin()).size()==1;
  m_irreducible.insert(std::make_pair(n, irreducible));
  return irreducible;
}

// -----------------------------------------------------------------------------
// ArithmeticalCongruenceMonoid: Private instance functions
// -----------------------------------------------------------------------------

const set<vector<int>>&
ArithmeticalCongruenceMonoid::ACMFactor(int n)
{
  // If value cached
  if (m_factorizations.count(n))
    return m_factorizations.at(n);

  // Initialize empty list of n factorizations and get reference
  m_factorizations.insert(std::make_pair(n, set<vector<int>>{}));
  set<vector<int>> &fs = m_factorizations.at(n);

  // If n not ACM element
  if (!in(n))
    return fs;

  auto ds = divisors(n);
  // If n irreducible (divisors only 1 and n)
  if (ds.size()==2) {
    fs.insert({n});
    return fs;
  }

  // Build list, skipping divisor ends (1 and n)
  auto di = next(ds.begin());
  auto de = prev(ds.end(), 1);
  for (; di != de; ++di) {
    int d = *di;
    int dd = n/d;
    const auto &dfs = ACMFactor(d); // Divisor d factors
    // If divisor d reducible
    if (dfs.size() && (*dfs.begin()).size()==1) {
      const auto &ddfs = ACMFactor(dd); // Divisor n/d (dd) factors
      for (const auto &ddf: ddfs) {
        if (ddf.size()==0 || d >= *prev(ddf.end())) {
          vector<int> nf{ddf};
          nf.push_back(d);
          fs.insert(std::move(nf));
        }
      }
    }
  }
  return fs;
}

vector<int>
ArithmeticalCongruenceMonoid::irreducibles_up_to(int lim)
{
  vector<int> irreducibles;
  for (int n = m_a; n <= lim; n += m_b) {
    if (irreducible(n))
      irreducibles.push_back(n);
  }
  return irreducibles;
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
