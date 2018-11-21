#pragma once

#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <string>
#include <sstream>
#include <exception>
#include <algorithm>

#include "../util.h"
#include "../pfactor.h"
#include "../divisors.h"

using std::vector;
using std::set;
using std::map;
using std::pair;

/** ArithmeticalCongruenceMonoid
 *
 * An Arithmetical Congruence Monoid for some integers a and b is a semigroup of
 * integer elements in the form a+bj for some integer j (b multiples).
 */
class ArithmeticalCongruenceMonoid
{
public:
  /** Constructor
   * @param a
   * @param b
   */
  ArithmeticalCongruenceMonoid(int a, int b);

  /** Constructor
   * @param ab a b pair
   */
  ArithmeticalCongruenceMonoid(pair<int,int> ab):
    ArithmeticalCongruenceMonoid{ab.first, ab.second}
  {}

  //! Get a
  int a() const { return m_a; }

  //! Get b
  int b() const { return m_b; }

  //! Generate n elements (starting from a)
  vector<int> elements(int n);

  //! Generate n elements (starting from nearest below s)
  vector<int> elements(int s, int n);

  //! Is n an element
  bool in(int n);

  //! Set of element divisors of n
  set<int> divisors(int n);

  /** factorization
   * @param n Number to factorize
   * @return List of factorizations
   *
   * Factorization in an ACM is similar to prime factorization over the integers
   * except that we extend "prime" to really mean irreducible in the ACM. What
   * this means is that an ACM element is irreducible if it cannot be factored
   * into other irreducible ACM elements.
   *
   * For example consider the Hilbert ACM (call it H) with elements {1, 5, 9,
   * ...} (a=1, b=4). 5 is necessarily irreducible because it is prime. However
   * 9, normally factorable to 3*3 over the integers, is irreducible in H
   * because 3 is not an element of H. The first element to be considered
   * reducible then is 25=5*5.
   *
   * Furthermore:
   * - 45 is factorable to 5*9.
   * - 441 is factorable to 21*21 and 9*49
   */
  const set<vector<int>>& factorizations(int n);

  //! Is n irreducible
  bool irreducible(int n);

  //! Irreducibles up to limit
  vector<int> irreducibles_up_to(int lim);

  //! User defined ACM to string
  explicit operator std::string() const
  { return "M("+to_string(m_a)+","+to_string(m_b)+")"; }

private:
  int m_a, m_b;
  map<int,set<vector<int>>> m_factorizations;
  map<int,bool> m_irreducible;

  ArithmeticalCongruenceMonoid() = delete;

  //! ACMFactor
  const set<vector<int>>& ACMFactor(int n);
};

//! Stream insertion overload
std::ostream& operator<<(
    std::ostream& os,
    const ArithmeticalCongruenceMonoid& obj);
