// Write a function that given a list of non negative integers, arranges them
// such that they form the largest possible number. For example, given
// [50, 2, 1, 9], the largest formed number is 95021.
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

static const char usage[] = "usage: arrange <number> [<number>..]";

template <typename T>
std::ostream& operator<<(std::ostream& s, const std::vector<T>& t)
{
    s << "[";
    for (std::size_t i = 0; i < t.size(); i++)
    {
        s << t[i] << (i == t.size() - 1 ? "" : ",");
    }
    return s << "]";
}

std::vector<int> readargs(int argc, char* argv[])
{
    static const std::vector<int> testVector{50, 2, 1, 9};

    if (argc <= 1)
        return testVector;

    std::vector<int> result;
    for (int i = 1; i < argc; ++i)
    {
        int val = std::stoi(argv[i]);
        if (val < 0)
            throw std::runtime_error("Must be positive integer");
        result.push_back(val);
    }
    return result;
}

// Custom sort operator to fulfill the assignment requirements
struct
{
    bool operator()(int a, int b) const
    {
        std::ostringstream lhs;
        std::ostringstream rhs;
        lhs << a << b;
        rhs << b << a;
        return lhs.str() > rhs.str(); // Lexical comparison solves the problem
    }

} sort_operator;

int main(int argc, char* argv[])
{
    try {
        std::vector<int> input = readargs(argc, argv);
        std::cout << input << " -> ";
        std::sort(input.begin(), input.end(), sort_operator);
        for(unsigned i = 0; i < input.size(); ++i)
            std::cout << input[i];
        std::cout << std::endl;
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << usage << std::endl;
        std::cerr << e.what() << std::endl;
    }
    return 1;
}
