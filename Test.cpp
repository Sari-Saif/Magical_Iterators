#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <stdexcept>

using namespace ariel;
using namespace std;

TEST_CASE("adding")
{
    MagicalContainer container;
    CHECK(container.size() == 0);
    container.addElement(0);
    container.addElement(2);
    container.addElement(30);
    container.addElement(5);
    container.addElement(789);
    CHECK(container.size() == 5);
}

TEST_CASE("Removing elements from container")
{
    MagicalContainer container;

    SUBCASE("removing an existing element and non existing")
    {
        container.addElement(1);
        container.addElement(2);
        CHECK_NOTHROW(container.removeElement(1));
        CHECK_THROWS(container.removeElement(1)); // isnot exist
        CHECK(container.size() == 1);
    }
}

TEST_CASE("ascendIterator test")
{
    MagicalContainer container;
    container.addElement(10);
    container.addElement(20);

    SUBCASE("iterating")
    {
        MagicalContainer::AscendingIterator it(container);
        CHECK(*it == 10);
        ++it;
        CHECK(*it == 15);
        CHECK(it == it.end());
    }

    SUBCASE("iterating over an empty")
    {
        MagicalContainer emptyContainer;
        MagicalContainer::AscendingIterator it(emptyContainer);
        CHECK(it == it.end());
    }
}

TEST_CASE("primeIterator")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);

    MagicalContainer::PrimeIterator it(container);
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 3);
    ++it;

    CHECK(it == it.end());
}

TEST_CASE("sideCrossiterator case")
{
    MagicalContainer container;
    container.addElement(17);
    container.addElement(21);
    container.addElement(43);
    container.addElement(55);
    container.addElement(512);

    SUBCASE("Iterating in side-cross from start to end")
    {
        MagicalContainer::SideCrossIterator it(container);

        CHECK(*it == 17);
        ++it;
        CHECK(*it == 512);
        ++it;
        CHECK(*it == 21);
        ++it;
        CHECK(*it == 55);
        ++it;
        CHECK(*it == 43);
        ++it;
        CHECK(it == it.end());
    }

    SUBCASE("empty container")
    {
        MagicalContainer emptyContainer;
        MagicalContainer::SideCrossIterator it(emptyContainer);
        CHECK(it == it.end());
    }
}

TEST_CASE("Multiple Iterators Test")
{
    MagicalContainer container;
    container.addElement(11);
    container.addElement(23);
    container.addElement(32);
    container.addElement(44);
    container.addElement(56);
    container.addElement(67);
    container.addElement(71);
    container.addElement(81);
    container.addElement(99);
    // Verifying that iterators do not affect each other's state or progress during iteration

    SUBCASE("Ascending Iterators")
    {
        MagicalContainer::AscendingIterator it1(container);
        MagicalContainer::AscendingIterator it2(container);

        ++(++it1);
        CHECK(*it1 == 32);
        CHECK(*it2 == 11);
        ++it2;
        CHECK(*it2 == 23);
        ++(++(++it1));
        ++(++(++(++it2)));
        CHECK(*it2 == 56);
        CHECK(*it1 == 67);
    }

    SUBCASE("Prime Iterators")
    {
        MagicalContainer::PrimeIterator it1(container);
        MagicalContainer::PrimeIterator it2(container);

        ++it1;
        CHECK(*it1 == 23);
        CHECK(*it2 == 11);
        ++it2;
        ++it1;
        CHECK(*it2 == 23);
        CHECK(*it1 == 67);
        ++it2;
        CHECK(*it2 == 71);
    }
}


TEST_CASE("primeIterator with non prime")
{
    MagicalContainer container;
    container.addElement(4);
    container.addElement(6);
    container.addElement(8);
    container.addElement(9);
    container.addElement(10);
    container.addElement(12);

    MagicalContainer::PrimeIterator it(container);

    CHECK(it == it.end());
    CHECK_THROWS_AS(++it, runtime_error);
}

TEST_CASE("operator= throws when iterators are pointing at different containers")
{
    MagicalContainer container1;
    MagicalContainer container2;

    container1.addElement(1);
    container1.addElement(2);
    container1.addElement(3);

    container2.addElement(4);
    container2.addElement(5);
    container2.addElement(6);

    SUBCASE("AscendingIterator")
    {
        MagicalContainer::AscendingIterator it1(container1);
        MagicalContainer::AscendingIterator it2(container2);

        CHECK_THROWS_AS(it1 = it2, std::runtime_error);
    }
    SUBCASE("SideCrossIterator")
    {
        MagicalContainer::SideCrossIterator it1(container1);
        MagicalContainer::SideCrossIterator it2(container2);

        CHECK_THROWS_AS(it1 = it2, std::runtime_error);
    }
    SUBCASE("AscendingIterator")
    {
        MagicalContainer::PrimeIterator it1(container1);
        MagicalContainer::PrimeIterator it2(container2);

        CHECK_THROWS_AS(it1 = it2, std::runtime_error);
    }
}
