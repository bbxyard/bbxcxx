
#define  _RTLDLL
#include "boost/noncopyable.hpp"
#include "boost/python.hpp"
#include "boost/foreach.hpp"

#include <string>

using namespace boost::python;

std::string hello_str()
{
    return "hello boost python";
}

std::string hello_to(const std::string& s)
{
    return "hello: " + s;
}

std::string hello_x(const std::string& s, int x)
{
    std::string tmp = "hello: ";
    for (int i = 0; i < x; ++i)
    {
        tmp += s + " ";
    }
    return tmp;
}

static std::string (*func1)()                           = &hello_str;
static std::string (*func2)(const std::string&)         = &hello_to;
static std::string (*func3)(const std::string&, int)    = hello_x;

BOOST_PYTHON_MODULE(boostpy)
{
    def("hellos", hello_str, "this is the doc string of hello_str");
    def("helloto", hello_to, arg("s"));
    def("hellox",  hello_x,  (arg("s"), "x")); //以下有更简洁写法args.
    
    def("hello",   func1,  "same as hello_str");
    def("hello",   func2,  arg("s"), "same as hello_to");
    def("hello",   func3,  args("s", "x"), "same as hello_x");
}

