#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#endif

#include <string>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <queue>
#include <stack>

#include "test_bimap.hpp"
#include "test_string.hpp"
#include "test_autoptr.hpp"

#include "test_misc.hpp"
#include "test_python.hpp"

int main(int argc, char* argv[])
{
    // 2013.12.1
    bbxyard::bpython::test::main(argc, argv);

    // 2013.11.23
    bbxyard::misc::test::main(argc, argv);

    //// 2013.09.02
    //bbxyard::bautoptr::test::main(argc, argv);

    //// 2013.09.01
    //bbxyard::bstring::test::main(argc, argv);

    //// 2013.08
    //bbxyard::bbimap::test::main(argc, argv);
    return 0;
}
