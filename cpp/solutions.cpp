// Write a program that outputs all possibilities to put + or - or nothing
// between the numbers 1, 2, ..., 9 (in this order) such that the result is
// always 100. For example: 1 + 2 + 34 – 5 + 67 – 8 + 9 = 100.
#include <iostream>
#include <cstdlib>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& s, const std::vector<T>& t)
{
    for (std::size_t i = 0; i < t.size(); i++)
        s << (i > 0 && t[i] >= 0 ? "+" : "") << t[i];
    return s;
}

static const std::vector<int> NUMBERS{1,2,3,4,5,6,7,8,9};
static const int SUM = 100;

void recurse(std::vector<int>& buf, unsigned idx)
{
    // Check if we have recursed to depth
    if (idx >= NUMBERS.size())
    {
        int result = 0;
        for (auto item : buf)
            result += item;
        if (result == SUM)
            std::cout << buf << " = " << SUM << std::endl;
        return;
    }
    
    // Branch 1: Add number to previous
    buf.push_back(NUMBERS[idx]);
    recurse(buf, idx+1);
    buf.pop_back();
    
    // Branch 2: Subtract number from previous
    buf.push_back(-1*NUMBERS[idx]);
    recurse(buf, idx+1);
    buf.pop_back();

    // Branch 3: Concatenate number to previous
    int prev = buf.back();
    buf.back() = (10 * std::abs(prev) + NUMBERS[idx]) * (prev >= 0 ? 1 : -1);
    recurse(buf, idx+1);
    buf.back() = prev;
}

int main(int argc, char* argv[])
{
    // Initialize buffer with first value
    std::vector<int> buf;
    buf.push_back(NUMBERS[0]);
    recurse(buf, 1);
    return 0;
}
