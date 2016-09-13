#include "money/money.h"

#include <iostream>
#include <vector>
#include <sstream>

namespace money
{

namespace impl
{
bool isDivisibleImpl(const int num, const int count, const std::vector<int>& denoms, const int max_index, const int step)
{
    if(denoms.empty() || num < denoms.front())
    {
        return false;
    }

    const auto max = count * denoms.back();
    if(max < num)
    {
        return false;
    }
    else if(max == num)
    {
        return true;
    }

    const auto min = count * denoms.front();
    if(min > num)
    {
        return false;
    }
    else if(min == num)
    {
        return true;
    }

    if(max_index < 0)
    {
        return false;
    }

    if(count <= 0)
    {
        return false;
    }

    for(auto k = 0; k < step; ++k)
    {
        std::cout << "    ";
    }
    std::cout << "isDivisibleImpl( " << num << " " << count << " )" << std::endl;

    auto res = false;

    for(auto i = max_index; i >= 0; --i)
    {
        auto rest = num % denoms[i];
        auto div = num / denoms[i];

        if(rest == 0 && div == count)
        {
            std::cout << "rest == 0; success" << std::endl;
            res = true;
            break;
        }

        for(auto j = 0; j < div; ++j)
        {
            const auto r_num = rest + j * denoms[i];
            const auto r_count = count - (div - j);

            if(isDivisibleImpl(r_num, r_count, denoms, max_index - 1, step + 1))
            {
                res = true;
                break;
            }
        }

        if(res)
        {
            break;
        }
    }

    return res;
}

}  // namespace impl

std::vector<int> getDenominators(const int max)
{
    auto res = std::vector<int>();

    for(auto i = 2; i <= max; ++i)
    {
        auto isPrime = true;
        for(auto n : res)
        {
            if(i % n == 0)
            {
                isPrime = false;
                break;
            }
        }
        if(isPrime)
        {
            res.push_back(i);
        }
    }
    return res;
}

bool isDivisible(const int num, const int count, const std::vector<int>& denoms)
{
    std::cout << "isDivisible( " << num << " " << count << " )" << std::endl;
    return impl::isDivisibleImpl(num, count, denoms, denoms.size()-1, 0);
}

int calculateSum(const int num, const std::vector<int>& denoms)
{
    auto res = 0;
    for(auto i = 0; i < num; ++i)
    {
        for(auto j = 0; j < num; ++j)
        {
            res += (isDivisible(i+1, j+1, denoms) ? 1 : 0);
        }
    }
    return res;
}

}  // namespace money
