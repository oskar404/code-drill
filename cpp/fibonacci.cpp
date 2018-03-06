// Write a function that computes the list of the first 100 Fibonacci numbers.
// By definition, the first two numbers in the Fibonacci sequence are 0 and 1,
// and each subsequent number is the sum of the previous two. As an example,
// here are the first 10 Fibonnaci numbers: 0, 1, 1, 2, 3, 5, 8, 13, 21, and 34.
#include <iostream>
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
                std::cerr << "fibonacci(): overflow ar " << i << std::endl;
                break;
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

int main(int argc, char* argv[])
{
    std::cout << fibonacci(100);
    return 0;
}
