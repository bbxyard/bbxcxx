#ifndef __TEST_AUTOPTR_HPP__
#define __TEST_AUTOPTR_HPP__


#include "boost/shared_ptr.hpp"
#include "boost/shared_array.hpp"
#include <string>
#include <vector>
#include <iostream>


namespace bbxyard {

namespace bautoptr {

class foobar
{
public:
    foobar()
    {
        std::cout << "foobar class object created!!" << std::endl;
    }
    ~foobar()
    {
        std::cout << "foobar class object destroyed!!" << std::endl;
    }
};

inline void test_shared_ptr()
{
    boost::shared_ptr<foobar> fb(new foobar);
    std::cout << "foobar use_count = " << fb.use_count() << std::endl;
    boost::shared_ptr<foobar> fb2 = fb;
    std::cout << "foobar use_count = " << fb.use_count() << std::endl;
}


class test
{
public:
    static int main(int argc, char* argv[])
    {
        test_shared_ptr();
        return 0;
    }
};


} // namespace bautoptr
} // namespace bbxyard



#endif // __TEST_AUTOPTR_HPP__
