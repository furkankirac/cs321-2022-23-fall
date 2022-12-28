#include <iostream>
#include <vector>
#include <range/v3/all.hpp>

// Range-v3 library by Eric Niebler is the next standard library of C++
// C++20 incorporates small portion of this library already.
// However, we'll use the full library from github repo.

template<typename ... Ts>
using vector = std::vector<Ts...>;

using namespace ranges; // instead of ranges::*, directly use *
namespace views = ranges::views; // instead of ranges::views::*, directly use views::*

int main(int, char* [])
{
    { // Sum up elements of a sequence, starting from the value 0.0.
        const auto v = vector<double>{ 1.5, 2.7, 3.8, 4.2 };
        auto val = accumulate(v, 0.0); // 12.2
    }

    { // Fold elements of a sequence via multiplication, starting from the value 1.
        const auto v = vector<int>{ 1, 2, 3, 4 };
        auto val = accumulate(v, 1, [](int a, int b) { return a * b; }); // 24
    }

    { // Count the number of occurrences of number 7.
        const auto v = vector<int>{ 1, 2, 7, 4, 1, 7 };
        auto val = count(v, 7); // 2
    }

    { // Determine equality of two vectors. [1, 2, 3] == [3, 2, 1]
        const auto v1 = vector<int>{ 1, 2, 3 };
        const auto v2 = vector<int>{ 3, 2, 1 };
        auto val = equal(v1, v2); // false
    }

    { // Calculate the dot product of two vectors.
        const auto v1 = vector<int>{ 1, 3, -5 };
        const auto v2 = vector<int>{ 4, -2, -1 };
        auto val = inner_product(v1, v2, 0); // 1*4 + 3*(-2) + (-5)*(-1) = 3
    }

    { // Sort elements of a sequence in ascending order.
        auto v = vector<int>{ 6, 7, 1, 3 };
        sort(v); // [1, 3, 6, 7]
    }

    { // Create a range containing all the elements of the sequence. Useful for conversion.
        const auto v = vector<int>{ 1, 2, 3, 4, 5 };
        auto rng = v | views::all; // [1, 2, 3, 4, 5]
        std::cout << rng;
    }

    { // Create a vector of tuples, i.e. a cartesian product of two sequences.
        const auto letters = vector<char>{ 'A', 'B', 'C' };
        const auto numbers = vector<int>{ 1, 2 };
        auto rng = views::cartesian_product(letters, numbers);
        for(auto [a, b] : rng)
            std::cout << a << ' ' << b << ", ";
        // A 1, A 2, B 1, B 2, C 1, C 2
    }

    { // Create a sequence of powers of two: 1, 2, 4, 8, 16, ...
        auto rng = views::generate([k=1]() mutable { return (k*=2)/2; });
    }

    { // Create a quasi-infinite sequence of integers.
        auto rng = views::ints; // [0, 1, 2, 3, 4...]
    }

    { // Create a quasi-infinite sequence of integers starting from 4.
        auto rng = views::ints(4, unreachable); // [4, 5, 6, 7...]
    }

    { // Create a sequence of integers [4, 5, 6].
        auto rng = views::ints(4, 7); // [4, 5, 6]
    }

    { // Create a quasi-infinite sequence with all elements equal to 4.
        auto rng = views::repeat(4); // [4, 4, 4, 4, 4, 4, 4, ...]
    }

    { // Create a sequence by reversing the original sequence.
        const auto v = vector<int>{ 1, 2, 3, 4 };
        auto rng = v | views::reverse; // [4, 3, 2, 1]
    }

    { // Create a sequence using every third element of the original sequence.
        const auto v = vector<int>{ 0, 1, 2, 3, 4, 5, 6 };
        auto rng = v | views::stride(3); // [0, 3, 6]
    }

    { // Create a sequence without the first element of the original sequence.
        const auto v = vector<int>{ 1, 2, 3, 4 };
        auto rng = v | views::tail; // [2, 3, 4]
    }

    { // Create a sequence that contains the first three elements of the original sequence.
        const auto v = vector<int>{ 1, 2, 3, 4, 5 };
        auto rng = v | views::take(3); // [1, 2, 3]
    }

    { // Multiply each element of the sequence by 2.
        const auto v = vector<int>{ 3, 2, 1 };
        auto rng = v | views::transform([](int x) { return 2*x; }); // [6, 4, 2]
    }

    { // Create a sequence by removing duplicate neighboring elements of the original sequence.
        const auto v = vector<int>{ 1, 2, 2, 3, 1, 1, 2, 2 };
        auto rng = v | views::unique; // [1, 2, 3, 1, 2]
    }

    { // Join two sequences by applying addition.
        const auto v1 = vector<int>{ 4, 2, 7 };
        const auto v2 = vector<int>{ 3, 2, 1 };
        auto rng = views::zip_with([](int a, int b) { return std::to_string(a + b); }, v1, v2); // ["7"s, "4"s, "8"s]
    }

    auto new_line = [] { std::cout << std::endl; };

    auto v1 = vector<double>{3.14, 2.7, 10.5, 20.1};
    auto v2 = vector<char>{'1', '1', '0', '1', '1'};
    auto v3 = vector<short>{1, 1, 0, 1, 1};

    { // example #1: accumulate
        // below is a single for loop implementation summing things up
        auto sum1 = accumulate(v1 | views::reverse | views::take(2), 0.0);
        std::cout << sum1 << std::endl;

        // this is the old-school way of writing it
        auto sum2 = 0.0;
        for(size_t i=v1.size()-1; i>=v1.size()-1-2; --i)
            sum2 += v1[i];
        std::cout << sum1 << std::endl;
    }
    new_line();

    { // example #2: nested-for-loop implementation with ranges
        // below is a nested-for-loop equivalent of going over v1 and v2.
        // nesting is actually equivalent to taking cartesian_product in mathematics
        for(auto [a, b] : views::cartesian_product(v1 | views::reverse, v2))
            std::cout << "[" << a << ", " << b << "]" << std::endl;

        // this is the old-school nested for loop version! very prone to bugs.
        for(int i=v1.size()-1; i>=0; --i)
        {
            auto a = v1[i];
            for(size_t j=0; j<v2.size()-1; ++j)
            {
                auto b = v2[j];
                std::cout << "[" << a << ", " << b << "]" << std::endl;
            }
        }
    }
    new_line();

    { // example #3: inner-product (dot-product) -> single for-loop coupled with some other action
        // this is a generator that returns 1, k^1, k^2, k^3, k^4, ... respectively for each call
        //                     16  8  4  2  1
        auto v3 = vector<short>{1, 1, 0, 1, 1};

        auto multiples_of_k = [](auto k) {
            return [i=1, k]() mutable { return (i*=k)/k; };
        };

        // make it a ranges-library compatible generator that generate 1, 2, 4, 8, 16, ...
        auto multiples_of_2 = views::generate(multiples_of_k(2));

        auto result = inner_product(v3 | views::reverse, multiples_of_2, 0);
        std::cout << result << std::endl;

        // this is the old-school version! very prone to bugs.
        auto sum = 0;
        auto k = 1;
        for(int i=v3.size()-1; i>=0; --i)
        {
            sum += k * v3[i];
            k *= 2;
        }
        std::cout << sum << std::endl;
    }
    new_line();

    // you can easily sort things with ranges library
    {
        v1 |= actions::sort;
        for(auto a : v1)
            std::cout << a << std::endl;
    }
    new_line();

    // you can easily get non-repeating (unique) elements with ranges library
    {
        auto v = vector<int>{10, 10, 5, 5, 5, 20, 5, 10};
        v |= actions::unique; // produces 10, 5, 20, 5, 10
        for(auto a : v)
            std::cout << a << std::endl;
    }
    return 0;
}
