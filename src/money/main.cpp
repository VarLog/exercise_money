#include <cstdlib>

#include <iostream>
#include <vector>
#include <sstream>

#include "money/money.h"

namespace mn = money;

int runIsDivisible(int argc, char** argv)
{
    if(argc != 3)
    {
        std::cerr << "usage: " << argv[0] << " <num> <count>" << std::endl;
        return EXIT_FAILURE;
    }

    auto num = 0;
    {
        auto ss = std::stringstream(argv[1]);
        ss >> num;
    }

    auto count = 0;
    {
        auto ss = std::stringstream(argv[2]);
        ss >> count;
    }

    auto denoms = mn::getDenominators(num);
    std::cout << "denoms: ";
    for(auto n : denoms)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::cout << "num: " << num << std::endl;
    std::cout << "count: " << num << std::endl;

    std::cout << std::endl;
    auto res = mn::isDivisible(num, count, denoms);
    std::cout << std::endl;

    std::cout << "isDivisible res: " << (res ? 1 : 0) << std::endl;

    return EXIT_SUCCESS;
}

int runCalculateSum(int argc, char** argv)
{
    if(argc != 2)
    {
        std::cerr << "usage: " << argv[0] << " <num>" << std::endl;
        return EXIT_FAILURE;
    }

    auto num = 0;
    {
        auto ss = std::stringstream(argv[1]);
        ss >> num;
    }

    auto denoms = mn::getDenominators(num);
    std::cout << "denoms: ";
    for(auto n : denoms)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::cout << "num: " << num << std::endl;

    auto res = mn::calculateSum(num, denoms);
    std::cout << "calculateSum res: " << res << std::endl;

    return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);

    auto app = std::string(argv[0]);

    auto pos = app.find_last_of("/");
    if(pos != std::string::npos)
    {
        if(app.substr(pos+1, 3) == "div")
        {
            return runIsDivisible(argc, argv);
        }
    }

    return runCalculateSum(argc, argv);
}
