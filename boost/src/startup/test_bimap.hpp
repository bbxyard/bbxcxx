#ifndef __TEST_BIMAP_HPP__
#define __TEST_BIMAP_HPP__


#include "boost/bimap.hpp"

namespace bbxyard {

namespace bbimap {

/************************************************************************/
/* from simple_bimap                                                    */
/************************************************************************/
namespace simple_bimap {
template <typename MapType>
void print_map(const MapType& map, const std::string& separator, std::ostream& os)
{
    typedef typename MapType::const_iterator const_iterator;
    for (const_iterator i = map.begin(); i != map.end(); ++i)
    {
        os << i->first << separator << i->second << std::endl;
    }
}

inline int main()
{
    // Soccer World cup
    typedef boost::bimap<std::string, int> result_bimap;
    typedef result_bimap::value_type position;

    result_bimap results;
    results.insert( position("Germany",     3) );
    results.insert( position("Argentina",   1) );
    results.insert( position("Spain",       2) );
    results.insert( position("France",      4) );

    std::cout << "The number of countries is: " << results.size() << std::endl;
    std::cout << "The winner is: " << results.right.at(1) << std::endl << std::endl;    

    // results.right works like a std::map< int, std::string >
    std::cout << "The countries names ordered by their final position: " << std::endl;
    print_map(results.right, ") ", std::cout);
    std::cout << std::endl;

    // results.left works like a std::map< std::string, int >
    std::cout << "The countries names ordered alphabetically along with their final position: " << std::endl;
    print_map(results.left, " ends in position ", std::cout);

    return 0;
}


} // namespace simple_bimap



class test {
public:
    static int main(int argc, char* argv[])
    {
        bbimap::simple_bimap::main();
        return 0;
    }
};

} // namespace bbimap

} // namespace bbxyard

#endif // __TEST_BIMAP_HPP__