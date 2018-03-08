// Write a function that computes the list of the first 100 Fibonacci numbers.
// By definition, the first two numbers in the Fibonacci sequence are 0 and 1,
// and each subsequent number is the sum of the previous two. As an example,
// here are the first 10 Fibonnaci numbers: 0, 1, 1, 2, 3, 5, 8, 13, 21, and 34.
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

// NB! This type can handle fibonacci only up to 93 values, After that we have
//     overflow
using ullint = unsigned long long int;

std::vector<ullint> fibonacci(unsigned size)
{
    std::vector<ullint> result;
    if (size > 0)
        result.push_back(0);
    if (size > 1)
        result.push_back(1);
    if (size > 2)
    {
        for (std::size_t i = 2; i <= size; ++i)
        {
            ullint next = result[i-2] + result[i-1];
            if (next < result[i-1])
            {
                std::ostringstream err;
                err << "fibonacci(): overflow ar " << i;
                throw std::runtime_error(err.str().c_str());
            }
            result.push_back(next);
        }
    }
    return result;
}

template <typename T>
std::ostream& operator<<(std::ostream& s, const std::vector<T>& t)
{
    for (std::size_t i = 0; i < t.size(); i++) {
        s << t[i] << std::endl;
    }
    return s;
}

static const char usage[] = "usage: fibonacci <count>";

unsigned readargs(int argc, char* argv[])
{
    unsigned result = 93;
    if (argc > 2)
        throw std::runtime_error(usage);
    if (argc == 2)
    {
        int val = 0;
        try {
            val = std::stoi(argv[1]);
        }
        catch (const std::exception&)
        {
            throw std::runtime_error(usage);
        }
        if (val < 1)
            throw std::runtime_error(usage);
        result = static_cast<unsigned>(val);
    }
    return result;
}

int main(int argc, char* argv[])
{
    try {
        std::cout << fibonacci(readargs(argc, argv));
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 1;
}
