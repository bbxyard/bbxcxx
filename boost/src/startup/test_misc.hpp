#ifndef __TEST_MISC_HPP__
#define __TEST_MISC_HPP__

#include "boost/shared_ptr.hpp"
#include "boost/assign.hpp"
#include "boost/foreach.hpp"

namespace bbxyard {

namespace misc {

class foo
{
public:
    foo()
    {
        std::cout << "create foo ..." << std::endl;
    }

    void say_hello(const char* s)
    {
        std::cout << "hello: " << s << std::endl;
    }

    ~foo()
    {
        std::cout << "destroy foo ..." << std::endl;
    }
};

inline void withdraw_resource(void*)
{
    std::cout << "this is the resource withdraw function!!" << std::endl;
}

inline void test_resource_mgr()
{
    boost::shared_ptr<void>    remover((void*)0, withdraw_resource);
    FILE* fp = NULL;

    fp = fopen("C:\\Windows\\System32\\cmd.exe", "rb");
    if (NULL == fp)
        return;
    boost::shared_ptr<FILE> bfp(fp, fclose);
    char buff[1024] = {0};
    fread(buff, sizeof(char), sizeof(buff), fp);

    foo* f = new foo;
    boost::shared_ptr<foo>  fptr(f);
    fptr->say_hello("foobar");
}

inline void test_assign()
{
    using namespace boost::assign;
    std::vector<std::string> vs;
    vs += "hello", "foo", "bar", "bbxyard";
    std::list<int>  li;
    li += 1, 3, 5, 7, 9;
    BOOST_FOREACH(const std::string& s, vs)
    {
        std::cout << s << "\t";
    }
    std::cout << std::endl;
}

class test
{
public:
    static int main(int argc, char* argv[])
    {
        test_resource_mgr();
        test_assign();
        return 0;
    }
};

} // namespace misc

} // namespace bbxyard


#endif // __TEST_MISC_HPP__
