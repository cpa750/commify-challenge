#include <stdexcept>
#define BOOST_TEST_DYN_LINK
#ifdef STAND_ALONE
#define BOOST_TEST_MODULE Main
#endif

#include "../include/Calculator.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(CalculatorTest)

    BOOST_AUTO_TEST_CASE(OneCharParse)

    {
        std::string seq = "A";
        Ruleset rs;
        rs.addItem('A', 50);
        Calculator c(rs, seq);
        std::map<char, int> b = c.parse();

        BOOST_CHECK_EQUAL(b['A'], 1);
    }

    BOOST_AUTO_TEST_CASE(MultiCharParse)
    {
        std::string seq = "ABABABABABAB";
        Ruleset rs;
        rs.addItem('A', 50);
        rs.addItem('B', 20);
        Calculator c(rs, seq);
        std::map<char, int> b = c.parse();

        BOOST_CHECK_EQUAL(b['A'], 6);
        BOOST_CHECK_EQUAL(b['B'], 6);
    }

    BOOST_AUTO_TEST_CASE(NoCharsParse)
    { 
        std::vector<char> chars; std::string seq = "ABABABABABAB"; 
        Ruleset rs;
        Calculator c(rs, seq);

        BOOST_CHECK_THROW(c.parse(), CharListEmpty);

    }

    BOOST_AUTO_TEST_CASE(NoStringParse)
    {
        std::string seq;
        Ruleset rs;
        rs.addItem('A', 50);
        rs.addItem('B', 20);
        Calculator c(rs, seq);

        BOOST_CHECK_THROW(c.parse(), StringEmpty);
    }

    BOOST_AUTO_TEST_CASE(ApplyWithNoSpecials)
    {
        Ruleset rs;
        rs.addItem('A', 50);
        Calculator c(rs);
        c.addItems("AAA");
        BOOST_CHECK_EQUAL(c.calculateTotal(), 150); 
    }
    BOOST_AUTO_TEST_CASE(ApplyWithOneSpecial)
    {
        Ruleset rs;
        rs.addItem('A', 50, {{5, 200}});
        Calculator c(rs);
        c.addItems("AAAAA");
        BOOST_CHECK_EQUAL(c.calculateTotal(), 200);
    }
    BOOST_AUTO_TEST_CASE(ApplyWithManySpecials)
    {
        Ruleset rs;
        rs.addItem('A', 50, {{5, 200}, {4, 180}});
        rs.addItem('B', 50, {{5, 200}, {4, 140}});
        // Notice the difference in specials for
        // these two items

        Calculator c(rs);
        c.addItems("AAAAA");
        c.addItems("BBBBB");
        int total = c.calculateTotal();
        BOOST_CHECK_EQUAL(total, 390);
        // 390 is the lowest total for this ruleset
    }
    BOOST_AUTO_TEST_CASE(AddInvalidItemException)
    {
        Ruleset rs;
        rs.addItem('A', 50, {{5, 200}});
        Calculator c(rs);
        BOOST_CHECK_THROW(c.addItems("AB");, std::out_of_range);
    }
BOOST_AUTO_TEST_SUITE_END()

