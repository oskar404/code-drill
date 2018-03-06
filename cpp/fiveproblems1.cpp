// Write three functions that compute the sum of the numbers in a given list
// using a for-loop, a while-loop, and recursion.
#include <iostream>
#include <vector>

template <typename T>
T forloop(const std::vector<T>& list)
{
    T sum = 0;
    for (unsigned int i = 0; i < list.size(); ++i)
        sum += list[i];
    return sum;
}

template <typename T>
T whileloop(const std::vector<T>& list)
{
    T sum = 0;
    typename std::vector<T>::const_iterator it = list.begin();
    while (it != list.end())
    {
        sum += *it;
        ++it;
    }
    return sum;
}

template <typename T>
T recursion(const std::vector<T>& list)
{
    if (list.empty())
        return static_cast<T>(0);
    std::vector<T> mylist = list;
    T it = mylist.back();
    mylist.pop_back();
    return it + recursion(mylist);
}

int main(int argc, char* argv[])
{
    std::vector<int> l1{1,2,3,4,5,-4,-1};
    std::cout << "forloop(): " << forloop(l1) << std::endl;
    std::cout << "whileloop(): " << whileloop(l1) << std::endl;
    std::cout << "recursion(): " << recursion(l1) << std::endl;
    std::vector<float> l2{1.0, 2.3};
    std::cout << "forloop(): " << forloop(l2) << std::endl;
    std::cout << "whileloop(): " << whileloop(l2) << std::endl;
    std::cout << "recursion(): " << recursion(l2) << std::endl;
    return 0;
}
