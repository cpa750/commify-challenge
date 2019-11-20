#define BOOST_TEST_MODULE Parser
#define BOOST_TEST_DYN_LINK
#include <utility>
#include <vector>

#include <map>
#include "../include/Parser.h"
#include "../include/exceptions.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(TestOneCharParse)
{
    std::vector<char> chars = {'A'};
    std::string seq = "A";

    Parser p(chars, seq);
    std::map<char, int> b = p.parse();
    
    BOOST_CHECK_EQUAL(b['A'], 1);
}

BOOST_AUTO_TEST_CASE(TestMultiCharParse)
{
    std::vector<char> chars = {'A', 'B'};
    std::string seq = "ABABABABABAB";

    Parser p(chars, seq);
    std::map<char, int> b = p.parse();

    BOOST_CHECK_EQUAL(b['A'], 6);
    BOOST_CHECK_EQUAL(b['B'], 6);
}

BOOST_AUTO_TEST_CASE(TestNoCharsParse)
{
    std::vector<char> chars;
    std::string seq = "ABABABABABAB";
    
    Parser p(chars, seq);
    
    BOOST_CHECK_THROW(p.parse(), CharListEmpty);

}

BOOST_AUTO_TEST_CASE(NoStringParse)
{
    std::vector<char> chars {'A', 'B'};
    std::string seq;

    Parser p(chars, seq);

    BOOST_CHECK_THROW(p.parse(), StringEmpty);
}

BOOST_AUTO_TEST_CASE(TestSetters)
{
    Parser p({}, "");
    p.setChars({'A', 'B'});
    p.setSequence("ABABAB");
    p.appendSequence("AB");    

    std::map<char, int> b = p.parse();

    BOOST_CHECK_EQUAL(b['A'], 4);
    BOOST_CHECK_EQUAL(b['B'], 4);
}

