// Write a function that combines two lists by alternatingly taking elements.
// For example: given the two lists [a, b, c] and [1, 2, 3], the function should
// return [a, 1, b, 2, c, 3].
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

std::vector<std::string> alternate(
        const std::vector<std::string>& v1, const std::vector<std::string>& v2)
{
    if (v1.size() != v2.size())
        throw std::invalid_argument("Input vectors do not have same size");

    std::vector<std::string> result;
    for (std::size_t i = 0; i < v1.size(); ++i)
    {
        result.push_back(v1[i]);
        result.push_back(v2[i]);
    }
    return result;
}

std::ostream& operator<<(std::ostream& s, std::vector<std::string> t)
{
    s << "[";
    for (std::size_t i = 0; i < t.size(); i++) {
        s << t[i] << (i == t.size() - 1 ? "" : ",");
    }
    return s << "]";
}

int main(int argc, char* argv[])
{
    std::vector<std::string> v1{"A", "B", "C", "D"};
    std::vector<std::string> v2{"1", "2", "3", "4"};
    std::vector<std::string> v3{};
    std::cout << "alternate(): " << alternate(v1, v2) << std::endl;
    std::cout << "alternate(): " << alternate(v2, v1) << std::endl;
    std::cout << "alternate(): " << alternate(v3, v3) << std::endl;
    try
    {
        alternate(v1,v3);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
