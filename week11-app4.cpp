// ranges:    views, actions, algorithms, examples.
//   views:   lazy ranges (sequences), calculated in time of request
//   actions: same with views, but eager calculation. all calculation over range is done at the beginning of request
//   algos:   equivalent with actions, only difference is that we call the algos in imperative way ourselves.
//            they don't compose with other algos.

// already available helper lambdas:
//   std::plus<T>(), std::minus<T>(), std::multiplies<T>(), std::divides<T>()

// importing a specific template/object into our namespace without chaning its name

// creating an alias namespace from an already available one

#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <set>
#include <map>

//#include <range/v3/all.hpp>

#include <range/v3/action.hpp> // examine this header for all actions
#include <range/v3/view.hpp> // examine this header for all views
#include <range/v3/algorithm.hpp> // examine this header for all algorithms

#include <range/v3/numeric.hpp>
//#include <range/v3/numeric/accumulate.hpp>
//#include <range/v3/numeric/adjacent_difference.hpp>
//#include <range/v3/numeric/inner_product.hpp>
//#include <range/v3/numeric/iota.hpp>
//#include <range/v3/numeric/partial_sum.hpp>

using std::vector; // imports the whole template into our namespace
using std::list;
using std::array;
using std::set;
using std::map;
using std::pair;
using std::string;
using std::cout;
using std::endl;

namespace views = ranges::views; // instead of ranges::views::*, directly use views::*
namespace actions = ranges::actions; // instead of ranges::views::*, directly use views::*
using namespace ranges; // instead of ranges::*, directly use *

int main()
{
    auto is_six = [](int i) { return i == 6; };
    auto print = [](int i) { cout << i << ' '; };
    auto printm = [](const pair<string, int>& p) { cout << p.first << ":" << p.second << ' '; };

    // algorithms
    // ranges::min, max, minelement, maxelement, minmax_element
    // ranges::distance
    // ranges::any_of, all_of, none_of
    // ranges::count, count_if
    // ranges::find, find_if, find_if_not
    // ranges::for_each

    { // min, max, min_element, max_element, minmax_element
        auto v = vector<int>{6, 2, 3, 4, 5, 6};
        cout << "Min value = " << min(v) << endl;
        cout << "Max value = " << max(v) << endl;
        cout << "Min value = " << *min_element(v) << endl;
        cout << "Max value = " << *max_element(v) << endl;
        cout << "Min index = " << (min_element(v) - begin(v)) << endl;

        auto [it_min, it_max] = minmax_element(v);
        cout << "Min value = " << *it_min << endl;
        cout << "Max value = " << *it_max << endl;
    }

    { // set union & range distance (size)
        auto const v1 = vector<char>{'a','b','c'};
        auto const v2 = vector<char>{'c','d','e'};
        auto v3 = views::set_union(v1, v2);
        auto sz = distance(v3); // 5
        cout << "size:     " << sz << endl;
    }

    { // any_of, all_of, none_of
        auto v = vector<int>{6, 2, 3, 4, 5, 6};
        cout << std::boolalpha;
        cout << "vector: " << views::all(v) << endl;
        cout << "vector any_of is_six: " << any_of(v, is_six) << endl;
        cout << "vector all_of is_six: " << all_of(v, is_six) << endl;
        cout << "vector none_of is_six: " << none_of(v, is_six) << endl;
    }

    { // count
        auto v = vector<int>{6, 2, 3, 4, 5, 6};
        auto c = count(v, 6);
        cout << "vector:   " << c << endl; // 2

        auto a = array<int, 6>{6, 2, 3, 4, 5, 6};
        c = count(a, 6);
        cout << "array:    " << c << '\n';
    }

    { // count_if
        auto v = list<int>{6, 2, 3, 4, 5, 6};
        auto c = count_if(v, is_six);
        cout << "vector:   " << c << endl; // 2

        auto a = array<int, 6>{6, 2, 3, 4, 5, 6};
        c = count_if(a, is_six);
        cout << "array:    " << c << endl; // 2
    }

    { // find, find_if, find_if_not
        cout << "vector:   ";
        auto v = vector<int>{6, 2, 6, 4, 6, 1};
        {
            auto i = find(v, 6); // 1 2 3 4 5 6
            cout << "*i: " << *i << endl; // 6
        }
        {
            auto i = find(v, 10); // 1 2 3 4 5 6
            if(i == end(v))
                cout << "didn't find 10" << endl; // didn't find 10
        }
        {
            auto i = find_if(v, is_six);
            if(i != end(v))
                cout << "*i: " << *i << endl; // 6
        }
        {
            auto i = find_if_not(v, is_six);
            if(i != end(v))
                cout << "*i: " << *i << endl; // 2
        }
        {
            auto i = find(v, 6);
            ++i;
            if(i != end(v))
                cout << "*i after ++ (2 expected): " << *i; // 2
        }

        cout << endl << "array:    ";
        auto a = array<int, 6>{6, 2, 3, 4, 5, 1};
        {
            auto i = find(a, 6);
            if(i != end(a))
                cout << "*i: " << *i; // 6
        }

        cout << endl << "list:     ";
        auto li = list<int>{6, 2, 3, 4, 5, 1};
        {
            auto i = find(li, 6);
            if(i != end(li))
                cout << "*i: " << *i; // 6
        }
        cout << endl;
    }

    { // for_each
        cout << "vector:   ";
        auto v = vector<int>{1, 2, 3, 4, 5, 6};
        //        for(auto item : views::all(v))
        //            cout << item << ' ';
        for_each(v, print); // 1 2 3 4 5 6

        cout << endl << "array:    ";
        auto a = array<int, 6>{1, 2, 3, 4, 5, 6};
        for_each(a, print); // 1 2 3 4 5 6

        cout << endl << "list:     ";
        auto l = list<int>{1, 2, 3, 4, 5, 6};
        for_each(l, print); // 1 2 3 4 5 6

        cout << endl;
    }

    { // for_each on associative containers
        //        auto m = map<string, bool>();
        //        m["5"] = true;
        //        m["3"] = true;
        //        m["5"] = true;
        // map has two keys respectively 3 and 5. map keeps things sorted in ascending manner.

        //        auto s = set<string>();
        //        s.insert("5");
        //        s.insert("3");
        //        s.insert("5");
        //        s.insert("5");

        cout << "set:           ";
        auto si = set<int>{1, 2, 3, 4, 5, 6};
        for_each(si, print); // 1 2 3 4 5 6

        cout << endl << "map:           ";
        auto msi = map<string, int>{{"one", 1}, {"two", 2}, {"three", 3}};
        for_each(msi, printm); // one:1 three:3 two:2

        cout << endl;
    }

    {
        auto v = vector<int>{1, 2, 3, 4, 5, 6, 7, 8};
        std::cout << (v | views::chunk(3)) << endl;
        for(auto item : v | views::chunk(3))
            std::cout << accumulate(item, 1, std::multiplies<int>()) << endl;// [](int a, int b) { return a*b; });
    }

    //    actions::adjacent_remove_if;
    //    actions::drop;
    //    actions::drop_while;
    //    actions::join;
    //    actions::remove_if;
    //    actions::reverse;
    //    actions::shuffle;
    //    actions::slice;
    //    actions::sort;
    //    actions::split;
    //    actions::split_when;
    //    actions::stride;
    //    actions::take;
    //    actions::take_while;
    //    actions::transform;
    //    actions::unique;
    { // drop & drop_while
        auto v = vector<int>{8, 7, 6, 5, 4, 3};
        cout << "views::drop(2)   " << (v | views::drop(2)) << endl;
        v |= actions::drop(2);
        cout << "actions::drop(2) " << (v | views::all) << endl;

        v |= actions::transform([](int a) { return a*2; }) | actions::sort;
        //        v |= actions::sort;
        cout << "transform+sort   " << (v | views::all) << endl;
    }

    { // sort + unique
        auto vi = vector<int>{9, 4, 5, 2, 9, 1, 0, 2, 6, 7, 4, 5, 6, 5, 9, 2, 7,
                              1, 4, 5, 3, 8, 5, 0, 2, 9, 3, 7, 5, 7, 5, 5, 6, 1,
                              4, 3, 1, 8, 4, 0, 7, 8, 8, 2, 6, 5, 3, 4, 5};
        vi |= actions::sort | actions::unique;
        // prints: [0,1,2,3,4,5,6,7,8,9]
        cout << views::all(vi) << endl;
    }

    return 0;
}
