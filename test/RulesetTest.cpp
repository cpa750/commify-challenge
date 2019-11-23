#include <stdexcept>
#define BOOST_TEST_DYN_LINK
#ifdef STAND_ALONE
#define BOOST_TEST_MODULE Main
#endif

#include "../include/Ruleset.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(RulesetTest)

    BOOST_AUTO_TEST_CASE(AddGetSpecialsTest)
    {
        Rule r;
        r.unitPrice = 30;
        r.specials = {{6, 150}}; // specials are stored as specialNo, specialPrice 
        Ruleset rs;
        rs.addItem('A', r.unitPrice, r.specials);

        std::vector<int> s = rs.getSpecials('A').at(0);
        BOOST_CHECK_EQUAL(s.at(0), 6);
        BOOST_CHECK_EQUAL(s.at(1), 150);
        BOOST_CHECK_EQUAL(rs.getUnitPrice('A'), 30);
    }
    BOOST_AUTO_TEST_CASE(AddExceptionTest)
    {
        Ruleset rs;
        rs.addItem('A', 50, {{5, 200}});
        BOOST_CHECK_THROW(rs.addItem('A', 40, {{3, 100}}), KeyExists); 
    }
    BOOST_AUTO_TEST_CASE(GetItemsTest)
    {
        Ruleset rs;
        rs.addItem('A', 50, {{5, 200}});
        rs.addItem('B', 20, {{5, 80}});

        std::vector<char> items = rs.getItems();
        BOOST_CHECK_EQUAL(items.at(0), 'A');
        BOOST_CHECK_EQUAL(items.at(1), 'B');
    }
    BOOST_AUTO_TEST_CASE(AddSpecialTest)
    {
        Ruleset rs;
        rs.addItem('A', 50, {{5, 200}});
        rs.addSpecial('A', {4, 180});
        
        int specialNo = rs.getSpecials('A').at(1).at(0);
        int specialPrice = rs.getSpecials('A').at(1).at(1);

        BOOST_CHECK_EQUAL(specialNo, 4);
        BOOST_CHECK_EQUAL(specialPrice, 180);
    }
    BOOST_AUTO_TEST_CASE(ClearSpecialTest)
    {
        Ruleset rs;
        rs.addItem('A', 50, {{5, 200}});
        rs.clearSpecials('A');

        BOOST_CHECK_EQUAL(rs.getSpecials('A').empty(), true);
    }
    BOOST_AUTO_TEST_CASE(GetUnitPrice)
    {
        Ruleset rs;
        rs.addItem('A', 50, {{5, 200}});
        BOOST_CHECK_EQUAL(rs.getUnitPrice('A'), 50);
    }
    BOOST_AUTO_TEST_CASE(RemoveRuleTest)
    {
        Ruleset rs;
        rs.addItem('A', 50, {{5, 200}});
        rs.removeItem('A');
        BOOST_CHECK_THROW(rs.getUnitPrice('A'), std::out_of_range);
        // If this throws out of range, A must have been removed
    }
    BOOST_AUTO_TEST_CASE(RemoveSpecialTest)
    {
        Ruleset rs;
        rs.addItem('A', 50, {{5, 200}});
        rs.removeSpecial('A', 0);
        BOOST_CHECK_EQUAL(rs.getSpecials('A').size(), 0);
    }
    BOOST_AUTO_TEST_CASE(RemoveItemExceptionTest)
    {
        Ruleset rs;
        rs.addItem('A', 50, {{5, 200}});
        BOOST_CHECK_THROW(rs.removeItem('B'), std::out_of_range);
    }
    BOOST_AUTO_TEST_CASE(RemoveSpecialExceptionTest)
    {
        Ruleset rs;
        rs.addItem('A', 50, {{5, 200}});
        BOOST_CHECK_THROW(rs.removeSpecial('B', 0), std::out_of_range);
        BOOST_CHECK_THROW(rs.removeSpecial('A', 1), std::out_of_range);
    }
    BOOST_AUTO_TEST_CASE(VectorAtException)
    {
        Ruleset rs;
        rs.addItem('A', 50, {{5, 200}});
        BOOST_CHECK_THROW(rs.clearSpecials('B'), std::out_of_range);
        // Checking that vector::at throws out_of_bounds properly
        // This checks this functionality for these functions:
        // addSpecial, clearSpecials, getUnitPrice, getSpecials, setUnitPrice 
    }
BOOST_AUTO_TEST_SUITE_END()

