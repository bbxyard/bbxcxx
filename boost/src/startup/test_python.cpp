#pragma comment(lib, "python27.lib")

#define  _RTLDLL
#include "boost/python.hpp"
#include "boost/noncopyable.hpp"
#include "boost/assert.hpp"
#include <cassert>
#include "pythonrun.h"  // ������ʾ����Ҳ���ԣ������Ƿ��㺯���������.

#include "test_python.hpp"

namespace bbxyard {
namespace bpython {

class pyinit : boost::noncopyable
{
public:
    pyinit(int initsigs = 1)
    {
        assert(initsigs == 0 || initsigs == 1);
        Py_InitializeEx(initsigs);
    }
    ~pyinit()
    {
        Py_Finalize();
    }
    const char* get_version() const
    {
        return Py_GetVersion();
    }
    const char* get_platform() const
    {
        return Py_GetPlatform();
    }
    void show_python_info() const
    {
        std::cout << "python platform: " << get_platform() << std::endl
                  << "python version: "  << get_version()  << std::endl;
                  //<< "python home: "     << Py_GetPythonHome() << std::endl;
    }
};

// ���Ի�������.
inline void test_object()
{
    using namespace boost::python;
    object i(10);
    i = 7 * i;
    std::cout << extract<int>(i) << std::endl;

    object s("boxu");
    std::string str = extract<std::string>(s * 5);
    std::cout << str << std::endl;
}


int test::main(int argc, char* argv[])
{
    pyinit pyi;
    pyi.show_python_info();
    test_object();
    return 0;
}

} // namespace bpython
} // namespace bbxyard
