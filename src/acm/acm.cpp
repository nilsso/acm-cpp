#include "acm.h"

// -----------------------------------------------------------------------------
// ArithmeticalCongruenceMonoid: Public instance functions
// -----------------------------------------------------------------------------

ArithmeticalCongruenceMonoid::ArithmeticalCongruenceMonoid(int a, int b):
  m_factorizations{std::make_pair(1, set<vector<int>>{{}})},
  m_irreducible{
    std::make_pair(1, true),
    std::make_pair(2, true),
    std::make_pair(3, true)}
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
  return (n == 1) || (n % m_b == m_a);
}

set<int>
ArithmeticalCongruenceMonoid::divisors(int n)
{
  set<int> ds;
  auto dsA = ::divisors(n);
  std::for_each(dsA.begin(), dsA.end(),
      [&n,&ds,this](int d) { if (in(d) && in(n/d)) { ds.insert(d); } });
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
  auto ds = divisors(n);
  return __ACMFactor(n, ds);
}

const set<vector<int>>&
ArithmeticalCongruenceMonoid::__ACMFactor(int n, const set<int> &dss)
{
  // If value cached
  if (m_factorizations.count(n))
    return m_factorizations.at(n);

  // Initialize empty list of n factorizations and get reference
  m_factorizations.insert(std::make_pair(n, set<vector<int>>{}));
  auto &fs = m_factorizations.at(n);

  // If n not ACM element
  if (!in(n))
    return fs;

  auto ds = divisors(n);
  auto di = next(ds.begin());
  auto de = ds.end();
  for (; di != de; ++di) {
    int d = *di;
    int dd = n/d;
    if (ds.count(dd) && (
          (dd==1 && fs.size()==0) ||
          (__ACMFactor(d, ds).begin())->size()==1)) {
      set<vector<int>> ddfs;
      for (auto df: __ACMFactor(dd, ds)) {
        ddfs.emplace(df);
      }
      for (vector<int> ddf: ddfs) {
        if (ddf.size()==0 || d >= *prev(ddf.end())) {
          ddf.push_back(d);
          fs.insert(ddf);
        }
      }
    }
  }
  return fs;
}

vector<int>
ArithmeticalCongruenceMonoid::irreducibles_up_to(int lim)
{
  return irreducibles_up_to(m_a, lim);
}

vector<int>
ArithmeticalCongruenceMonoid::irreducibles_up_to(int s, int lim)
{
  vector<int> irreducibles;
  for (int n = s-(s-m_a)%m_b; n <= lim; n += m_b) {
    if (irreducible(n))
      irreducibles.push_back(n);
  }
  return irreducibles;
}

string
ArithmeticalCongruenceMonoid::atomic_density_list(int n)
{
  return atomic_density_list(n, m_a);
}

string
ArithmeticalCongruenceMonoid::atomic_density_list(int n, int s)
{
  stringstream ss;
  s -= (s-m_a)%m_b;
  for (int i = 0; i < n; ++i, s+=m_b)
    ss << (irreducible(s) ? '1' : '0');
  return ss.str();
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
