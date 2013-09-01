#ifndef __TEST_STRING_HPP__
#define __TEST_STRING_HPP__

#include <locale>
#include <string>
#include <cstring>
#include <vector>
#include "boost/algorithm/string.hpp"
#include "boost/regex.hpp"
#include "boost/tokenizer.hpp"


namespace bbxyard {
namespace bstring {

inline void test_locale()
{
    // 字符字典序比较.
    std::cout << std::strcoll("?", "z") << std::endl;   
    std::locale::global(std::locale("German"));   
    std::cout << std::strcoll("?", "z") << std::endl; 

    // conv to env locale
    std::locale::global(std::locale(""));
    std::locale loc;
    std::cout << loc.name() << std::endl;
}

// 大小写转换
inline void test_case_conv()
{
    std::string s = "This is a Test!!";
    boost::algorithm::to_lower(s);
    std::cout << "low case: " << s << std::endl;
    std::cout << "up case: "  << boost::algorithm::to_upper_copy(s) << std::endl;
}

// erase
inline void test_erase()
{
    std::string s = "This is a Test!!";
    std::string s1 = boost::algorithm::erase_all_copy(s, "is");
    std::cout << "erase all space: " << boost::algorithm::erase_all_copy(s, " ") << std::endl;
    std::cout << "erase 1st space: " << boost::algorithm::erase_first_copy(s, " ") << std::endl;
    std::cout << "erase 2nd space: " << boost::algorithm::erase_nth_copy(s, " ", 1) << std::endl;
    std::cout << "erase last space: "<< boost::algorithm::erase_last_copy(s, " ") << std::endl;
}

inline void test_replace()
{
    std::string s = "This is a Test!!";
    std::cout << "repalce all: " << boost::algorithm::replace_all_copy(s, " ", "#") << std::endl;
    std::cout << "replace first: " << boost::algorithm::replace_first_copy(s, "is", "IS") << std::endl;
    std::cout << "replace first: " << boost::algorithm::replace_first_copy(s, " ", "*") << std::endl;
    std::cout << "replace head: "  << boost::algorithm::replace_head_copy(s, 2, "*") << std::endl;
    boost::iterator_range<std::string::iterator> rs = boost::algorithm::find_first(s, "is");
    std::cout << "replace by rage: "<< boost::algorithm::replace_range_copy(s, rs, "are") << std::endl;    
}

inline void test_trim()
{
    std::string s = "\t \n This is a Test!! \t ";
    std::cout << "default trim: " << boost::algorithm::trim_copy(s) << std::endl;
    std::cout << "control trim: " << boost::algorithm::trim_copy_if(s, boost::algorithm::is_cntrl()) << std::endl;
    std::cout << "special trim: " << boost::algorithm::trim_copy_if(s, boost::algorithm::is_any_of(" \t\n")) << std::endl;
}

inline void test_split_join()
{
    std::string s = "\t \n This is a Test!! \t ";
    std::vector<std::string> sub;
    boost::algorithm::split(sub, s, boost::algorithm::is_any_of(" \t\n"), boost::algorithm::token_compress_on);
    std::cout << boost::algorithm::join(sub, "#") << std::endl;
}

inline void test_regex()
{
    std::string s = "Boris Schling"; //"This is a Test!!";
    boost::regex expr1("\\w+\\s\\w+");
    std::cout << boost::regex_match(s, expr1) << std::endl;
    boost::regex expr2("(\\w+)\\s(\\w+)");
    boost::smatch what;
    //if (boost::regex_search(s, expr2))
    //{
    //    std::cout << what[0] << std::endl;
    //    std::cout << what[1] << "-" << what[2] << std::endl;
    //}
}

inline void test_tokenizer()
{
    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
    std::string s = "Boost C++ Library\tvery  very   useful!!";
    boost::char_separator<char> sep(" \t");
    tokenizer tok(s, sep);
    std::cout << "test tokenizer: ";
    for (tokenizer::iterator it = tok.begin(); it != tok.end(); ++it)
        std::cout << "[" << *it << "]" << "\t";
    std::cout << std::endl;
}

class test
{
public:
    static int main(int argc, char* argv[])
    {
        test_locale();
        test_case_conv();
        test_erase();
        test_replace();
        test_trim();
        test_split_join();
        test_regex();
        test_tokenizer();
        return 0;
    }
};

} // namespace bstring
} // namespace bbxyard

#endif // __TEST_STRING_HPP__
