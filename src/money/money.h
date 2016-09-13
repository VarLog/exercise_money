#ifndef _MONEY_MONEY_H_
#define _MONEY_MONEY_H_

#include <vector>

namespace money
{
std::vector<int> getDenominators(const int max);
bool isDivisible(const int num, const int count, const std::vector<int>& denoms);
int calculateSum(const int num, const std::vector<int>& denoms);

namespace impl
{
bool isDivisibleImpl(const int num, const int count, const std::vector<int>& denoms, const int max_index, const int step);
}  // namespace impl

}  // namespace money

#endif  // _MONEY_MONEY_H_
