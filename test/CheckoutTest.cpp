#define BOOST_TEST_DYN_LINK
#ifdef STAND_ALONE
#define BOOST_TEST_MODULE Main
#endif

#include "../include/Checkout.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(CheckoutTest)


    BOOST_AUTO_TEST_CASE(TestCase1)
    {
        Ruleset rs;
        rs.addItem('A', 60, {{3, 150}});
        rs.addItem('B', 30, {{2, 45}});
        rs.addItem('C', 30);
        rs.addItem('D', 25);
        Checkout c(rs);
        c.scan('A');
        BOOST_CHECK_EQUAL(c.getTotal(), 60);
    }
    BOOST_AUTO_TEST_CASE(TestCase2)
    {
        Ruleset rs;
        rs.addItem('A', 60, {{3, 150}});
        rs.addItem('B', 30, {{2, 45}});
        rs.addItem('C', 30);
        rs.addItem('D', 25);
        Checkout c(rs);
        c.scan('A');
        c.scan('B');
        BOOST_CHECK_EQUAL(c.getTotal(), 90);
    }
    BOOST_AUTO_TEST_CASE(TestCase3)
    {
        Ruleset rs;
        rs.addItem('A', 60, {{3, 150}});
        rs.addItem('B', 30, {{2, 45}});
        rs.addItem('C', 30);
        rs.addItem('D', 25);
        Checkout c(rs);
        c.scan('C');
        c.scan('D');
        c.scan('B');
        c.scan('A');
        BOOST_CHECK_EQUAL(c.getTotal(), 145);
    }
    BOOST_AUTO_TEST_CASE(TestCase4)
    {
        Ruleset rs;
        rs.addItem('A', 60, {{3, 150}});
        rs.addItem('B', 30, {{2, 45}});
        rs.addItem('C', 30);
        rs.addItem('D', 25);
        Checkout c(rs);
        c.scan('A');
        c.scan('A');
        BOOST_CHECK_EQUAL(c.getTotal(), 120);
    }
    BOOST_AUTO_TEST_CASE(TestCase5)
    {
        Ruleset rs;
        rs.addItem('A', 60, {{3, 150}});
        rs.addItem('B', 30, {{2, 45}});
        rs.addItem('C', 30);
        rs.addItem('D', 25);
        Checkout c(rs);
        c.scan('A');
        c.scan('A');
        c.scan('A');
        BOOST_CHECK_EQUAL(c.getTotal(), 150);
    }
    BOOST_AUTO_TEST_CASE(TestCase6)
    {
        Ruleset rs;
        rs.addItem('A', 60, {{3, 150}});
        rs.addItem('B', 30, {{2, 45}});
        rs.addItem('C', 30);
        rs.addItem('D', 25);
        Checkout c(rs);
        c.scan('A');
        c.scan('A');
        c.scan('A');
        c.scan('A');
        BOOST_CHECK_EQUAL(c.getTotal(), 210);
    }
    BOOST_AUTO_TEST_CASE(TestCase7)
    {
        Ruleset rs;
        rs.addItem('A', 60, {{3, 150}});
        rs.addItem('B', 30, {{2, 45}});
        rs.addItem('C', 30);
        rs.addItem('D', 25);
        Checkout c(rs);
        c.scan('A');
        c.scan('A');
        c.scan('A');
        c.scan('A');
        c.scan('A');
        BOOST_CHECK_EQUAL(c.getTotal(), 270);
    }
    BOOST_AUTO_TEST_CASE(TestCase8)
    {
        Ruleset rs;
        rs.addItem('A', 60, {{3, 150}});
        rs.addItem('B', 30, {{2, 45}});
        rs.addItem('C', 30);
        rs.addItem('D', 25);
        Checkout c(rs);
        c.scan('A');
        c.scan('A');
        c.scan('A');
        c.scan('A');
        c.scan('A');
        c.scan('A');
        BOOST_CHECK_EQUAL(c.getTotal(), 300);
    }
    BOOST_AUTO_TEST_CASE(TestCase9)
    {
        Ruleset rs;
        rs.addItem('A', 60, {{3, 150}});
        rs.addItem('B', 30, {{2, 45}});
        rs.addItem('C', 30);
        rs.addItem('D', 25);
        Checkout c(rs);
        c.scan('A');
        c.scan('A');
        c.scan('A');
        c.scan('B');
        BOOST_CHECK_EQUAL(c.getTotal(), 180);
    }
    BOOST_AUTO_TEST_CASE(TestCase10)
    {
        Ruleset rs;
        rs.addItem('A', 60, {{3, 150}});
        rs.addItem('B', 30, {{2, 45}});
        rs.addItem('C', 30);
        rs.addItem('D', 25);
        Checkout c(rs);
        c.scan('A');
        c.scan('A');
        c.scan('A');
        c.scan('B');
        c.scan('B');
        BOOST_CHECK_EQUAL(c.getTotal(), 195);
    }
    BOOST_AUTO_TEST_CASE(TestCase11)
    {
        Ruleset rs;
        rs.addItem('A', 60, {{3, 150}});
        rs.addItem('B', 30, {{2, 45}});
        rs.addItem('C', 30);
        rs.addItem('D', 25);
        Checkout c(rs);
        c.scan('A');
        c.scan('A');
        c.scan('A');
        c.scan('B');
        c.scan('B');
        c.scan('D');
        BOOST_CHECK_EQUAL(c.getTotal(), 220);
    }
    BOOST_AUTO_TEST_CASE(TestCase12)
    {
        Ruleset rs;
        rs.addItem('A', 60, {{3, 150}});
        rs.addItem('B', 30, {{2, 45}});
        rs.addItem('C', 30);
        rs.addItem('D', 25);
        Checkout c(rs);
        c.scan('D');
        c.scan('A');
        c.scan('B');
        c.scan('A');
        c.scan('B');
        c.scan('A');
        BOOST_CHECK_EQUAL(c.getTotal(), 220);
    }

BOOST_AUTO_TEST_SUITE_END()

