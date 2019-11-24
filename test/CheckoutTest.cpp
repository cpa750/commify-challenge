#define BOOST_TEST_DYN_LINK
#ifdef STAND_ALONE
#define BOOST_TEST_MODULE Main
#endif

#include "../include/Checkout.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(CheckoutTest)


    BOOST_AUTO_TEST_CASE(ScanOne)
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
    BOOST_AUTO_TEST_CASE(ScanTwoDifferent)
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
    BOOST_AUTO_TEST_CASE(ScanFourDifferent)
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
    BOOST_AUTO_TEST_CASE(ScanTwoSame)
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
    BOOST_AUTO_TEST_CASE(ScanThreeSame)
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
    BOOST_AUTO_TEST_CASE(ScanFourSame)
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
    BOOST_AUTO_TEST_CASE(ScanFiveSame)
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
    BOOST_AUTO_TEST_CASE(ScanSixSame)
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
    BOOST_AUTO_TEST_CASE(ScanSequenceAAAB)
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
    BOOST_AUTO_TEST_CASE(ScanSequenceAAABB)
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
    BOOST_AUTO_TEST_CASE(ScanSequenceAAABBD)
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
    BOOST_AUTO_TEST_CASE(ScanSequenceDABABA)
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

