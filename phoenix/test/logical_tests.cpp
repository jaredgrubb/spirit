/*=============================================================================
    Phoenix
    Copyright (c) 2001-2004 Joel de Guzman

    Use, modification and distribution is subject to the Boost Software
    License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <boost/test/minimal.hpp>
#include <boost/spirit/phoenix/core.hpp>
#include <boost/spirit/phoenix/operator.hpp>

using namespace boost::phoenix;
using namespace std;

int
test_main(int, char*[])
{
    {
        bool x = false;
        bool y = true;

        BOOST_TEST((!arg1)(x) == true);
        BOOST_TEST((!arg1)(y) == false);
        BOOST_TEST((arg1 || arg2)(x, y) == true);
        BOOST_TEST((arg1 && arg2)(x, y) == false);

        // short circuiting:
        int i = 1234;
        (arg1 || (arg2 = 4567))(y, i);
        BOOST_TEST(i == 1234);
        (arg1 && (arg2 = 4567))(y, i);
        BOOST_TEST(i == 4567);
    }

    return 0;
}
