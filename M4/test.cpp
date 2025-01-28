// Uncomment the next line to use precompiled headers
#include "pch.h"
// uncomment the next line if you do not use precompiled headers
//#include "gtest/gtest.h"
//
// the global test environment setup and tear down
// you should not need to change anything here
class Environment : public ::testing::Environment
{
public:
    ~Environment() override {}

    // Override this to define how to set up the environment.
    void SetUp() override
    {
        //  initialize random seed
        srand(time(nullptr));
    }

    // Override this to define how to tear down the environment.
    void TearDown() override {}
};

// create our test class to house shared data between tests
// you should not need to change anything here
class CollectionTest : public ::testing::Test
{
protected:
    // create a smart point to hold our collection
    std::unique_ptr<std::vector<int>> collection;

    void SetUp() override
    { // create a new collection to be used in the test
        collection.reset(new std::vector<int>);
    }

    void TearDown() override
    { //  erase all elements in the collection, if any remain
        collection->clear();
        // free the pointer
        collection.reset(nullptr);
    }

    // helper function to add random values from 0 to 99 count times to the collection
    void add_entries(int count)
    {
        assert(count > 0);
        for (auto i = 0; i < count; ++i)
            collection->push_back(rand() % 100);
    }
};

// When should you use the EXPECT_xxx or ASSERT_xxx macros?
// Use ASSERT when failure should terminate processing, such as the reason for the test case.
// Use EXPECT when failure should notify, but processing should continue

// Test that a collection is empty when created.
// Prior to calling this (and all other TEST_F defined methods),
//  CollectionTest::StartUp is called.
// Following this method (and all other TEST_F defined methods),
//  CollectionTest::TearDown is called
TEST_F(CollectionTest, CollectionSmartPointerIsNotNull)
{
    // is the collection created
    ASSERT_TRUE(collection);

    // if empty, the size must be 0
    ASSERT_NE(collection.get(), nullptr);
}

// Test that a collection is empty when created.
TEST_F(CollectionTest, IsEmptyOnCreate)
{
    // is the collection empty?
    ASSERT_TRUE(collection->empty());

    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);
}

/* Comment this test out to prevent the test from running
 * Uncomment this test to see a failure in the test explorer */
 //TEST_F(CollectionTest, AlwaysFail)
 //{
 //    FAIL();
 //}

 // TODO: Create a test to verify adding a single value to an empty collection
TEST_F(CollectionTest, CanAddToEmptyVector)
{
    // we can use EXPECT for the first two statements because they have been proven in the previous test
    // 
    // is the collection empty?
    EXPECT_TRUE(collection->empty());

    // if empty, the size must be 0
    EXPECT_EQ(collection->size(), 0);

    add_entries(1);

    // is the collection still empty?
    ASSERT_FALSE(collection->empty());

    // verify that the size of collection is now 1
    ASSERT_EQ(collection->size(), 1);
}

// TODO: Create a test to verify adding five values to collection
TEST_F(CollectionTest, CanAddFiveValuesToVector)
{
    // is the collection empty?
    EXPECT_TRUE(collection->empty());

    // if empty, the size must be 0
    EXPECT_EQ(collection->size(), 0);

    // add five entries
    add_entries(5);

    // verify size of collection is five
    ASSERT_EQ(collection->size(), 5);
}

// TODO: Create a test to verify that max size is greater than or equal to size for 0, 1, 5, 10 entries

TEST_F(CollectionTest, MaxSizeIsGreaterThanOrEqualToSize) {

    // is the collection empty?
    EXPECT_TRUE(collection->empty());

    // if empty, the size must be 0
    EXPECT_EQ(collection->size(), 0);

    // Using ASSERT because it is part of the test case
    // verify that max_size is greater than or equal to size for 0 entries
    ASSERT_GE(collection->max_size(), collection->size());

    // add one entry
    add_entries(1);

    // verify the size of collection is 1
    EXPECT_EQ(collection->size(), 1);

    // Using ASSERT because it is part of the test case
    // verify that max_size is greater than or equal to size for 1 entry
    ASSERT_GE(collection->max_size(), collection->size());

    // add four more entries to make 5 total entries in collection
    add_entries(4);

    // verify the size of collection is 5
    EXPECT_EQ(collection->size(), 5);

    // Using ASSERT because it is part of the test case
    // verify that max_size is greater than or equal to size for 5 entries
    ASSERT_GE(collection->max_size(), collection->size());

    // add five more entries to make ten total entries in collection
    add_entries(5);

    // verify the size of collection is 10
    EXPECT_EQ(collection->size(), 10);

    // Using ASSERT because it is part of the test case
    // verify that max_size is greater than or equal to size for 10 entries
    ASSERT_GE(collection->max_size(), collection->size());

}

// TODO: Create a test to verify that capacity is greater than or equal to size for 0, 1, 5, 10 entries

TEST_F(CollectionTest, VerifyCapacityIsGreaterThanOrEqualToSizeForEntries) {
    // is the collection empty?
    EXPECT_TRUE(collection->empty());

    // if empty, the size must be 0
    EXPECT_EQ(collection->size(), 0);

    // Using ASSERT because it is part of the test case
    // verify that capacity is greater than or equal to size for 0 entries
    ASSERT_GE(collection->capacity(), collection->size());

    // add one entry
    add_entries(1);

    // verify the size of collection is 1
    EXPECT_EQ(collection->size(), 1);

    // Using ASSERT because it is part of the test case
    // verify that capacitye is greater than or equal to size for 1 entry
    ASSERT_GE(collection->capacity(), collection->size());

    // add four more entries to make five total entries in collection
    add_entries(4);

    // verify the size of collection is 5
    EXPECT_EQ(collection->size(), 5);

    // Using ASSERT because it is part of the test case
    // verify that capacity is greater than or equal to size for 5 entries
    ASSERT_GE(collection->capacity(), collection->size());

    // add five more entries to make ten total entries in collection
    add_entries(5);

    // verify the size of collection is 10
    EXPECT_EQ(collection->size(), 10);

    // Using ASSERT because it is part of the test case
    // verify that capacity is greater than or equal to size for 10 entries
    ASSERT_GE(collection->capacity(), collection->size());
}

// TODO: Create a test to verify resizing increases the collection

TEST_F(CollectionTest, VerifyResizingIncreasesTheCollection) {

    // is the collection empty?
    EXPECT_TRUE(collection->empty());

    // if empty, the size must be 0
    EXPECT_EQ(collection->size(), 0);

    // add an entry
    add_entries(1);

    // verify the size of collection is now 1
    EXPECT_EQ(collection->size(), 1);

    // resize the collection by increasing its current size by one
    collection->resize(collection->size() + 1);

    // Using ASSERT because it is part of the test case
    // verify that the size of collection is now 2
    ASSERT_EQ(collection->size(), 2);
}

// TODO: Create a test to verify resizing decreases the collection

TEST_F(CollectionTest, VerifyResizingDecreasesTheCollection) {

    // is the collection empty?
    EXPECT_TRUE(collection->empty());

    // if empty, the size must be 0
    EXPECT_EQ(collection->size(), 0);

    //first add two entries
    add_entries(2);

    // verify the collection size is 2
    EXPECT_EQ(collection->size(), 2);

    // resize the collection by decreasing its current size by one
    collection->resize(collection->size() - 1);

    // Using ASSERT because it is part of the test case
    // verify that the size of collection is now 1.
    ASSERT_EQ(collection->size(), 1);

}

// TODO: Create a test to verify resizing decreases the collection to zero

TEST_F(CollectionTest, VerifyResizingDecreasesTheCollectionToZero) {

    // is the collection empty?
    EXPECT_TRUE(collection->empty());

    // if empty, the size must be 0
    EXPECT_EQ(collection->size(), 0);

    // add five entries
    add_entries(5);

    // vreify the size of collection is now five
    EXPECT_EQ(collection->size(), 5);

    // resize collection to zero
    collection->resize(0);

    // Using ASSERT because it is part of the test case
    //verify that the size of collection is now zero
    ASSERT_EQ(collection->size(), 0);
}

// TODO: Create a test to verify clear erases the collection

TEST_F(CollectionTest, VerifyClearErasesTheCollection) {

    // is the collection empty?
    EXPECT_TRUE(collection->empty());

    // if empty, the size must be 0
    EXPECT_EQ(collection->size(), 0);

    // add five entries
    add_entries(5);

    // verify the size of collection is now five
    EXPECT_EQ(collection->size(), 5);

    // clear the collection
    collection->clear();

    // Using ASSERT because it is part of the test case
    // verify that clear erases the collection (is empty)
    ASSERT_TRUE(collection->empty());
}

// TODO: Create a test to verify erase(begin,end) erases the collection

TEST_F(CollectionTest, VerifyEraseBeginEndErasesTheCollection) {

    // is the collection empty?
    EXPECT_TRUE(collection->empty());

    // if empty, the size must be 0
    EXPECT_EQ(collection->size(), 0);

    // add some entries
    add_entries(5);

    // verify the size of collection is now five
    EXPECT_EQ(collection->size(), 5);

    //erase the collection using begin, end
    collection->erase(collection->begin(), collection->end());

    // Using ASSERT because it is part of the test case
    // verify that the collection is erased (is empty)
    ASSERT_TRUE(collection->empty());
}

// TODO: Create a test to verify reserve increases the capacity but not the size of the collection

TEST_F(CollectionTest, VerifyReserveIncreasesCpacityButNotSizeOfCollection) {

    // is the collection empty?
    EXPECT_TRUE(collection->empty());

    // if empty then the size must be zero
    EXPECT_EQ(collection->size(), 0);

    // get the initial capacity of collection
    int startCapacity = collection->capacity();

    // create a new variable for increasing the capacity
    int increaseReserve = startCapacity + 10000;

    // increase the capacity by calling the reserve function
    collection->reserve(increaseReserve);

    // Using ASSERT because it is part of the test case
    // verify the collection capacity is now greater than when it started
    ASSERT_GT(collection->capacity(), startCapacity);

    // Using ASSERT because it is part of the test case
    // verify the collection size has not changed 
    ASSERT_EQ(collection->size(), 0);
}

// TODO: Create a test to verify the std::out_of_range exception is thrown when calling at() with an index out of bounds
// NOTE: This is a negative test

TEST_F(CollectionTest, VerifyOORExceptionThrownWhenCallingAtFuncWithIndexOOBounds) {
    
    // is the collection empty?
    EXPECT_TRUE(collection->empty());

    // if empty then the size must be zero
    EXPECT_EQ(collection->size(), 0);

    // Using ASSERT because it is part of the test case
    // test that an exception is thrown when calling at() with an index out of bounds
    ASSERT_THROW(collection->at(collection->size() + 1), std::out_of_range);
}

// TODO: Create 2 unit tests of your own to test something on the collection - do 1 positive & 1 negative

// positive test
// A test to verify that calling shrink_to_fit shrinks the capacity to the size of collection
TEST_F(CollectionTest, VerifyShrinkToFitShrinksCapacityToSizeOfCollection) {

    // is the collection empty?
    EXPECT_TRUE(collection->empty());

    // if empty then the size must be zero
    EXPECT_EQ(collection->size(), 0);

    // verify the collection capacity is 0
    EXPECT_EQ(collection->capacity(), 0);

    // add five entries to collection
    add_entries(5);

    // verify the size of collection is 5
    EXPECT_EQ(collection->size(), 5);

    // reserve 1000
    collection->reserve(1000);

    // verify the capacity is now 1000
    EXPECT_EQ(collection->capacity(), 1000);

    // shrink the capacity to the size of collection
    collection->shrink_to_fit();

    // Using ASSERT because it is part of the test case
    // verify that collection capacity is the same size as collection
    ASSERT_EQ(collection->capacity(), collection->size());

}

// negative test
// A test to verify that an exception is thrown when trying to reserve more than collection's max_size
TEST_F(CollectionTest, VerifyExceptionIsThrownWhenReservingMoreThanCollectionsMaxSize) {
    
    // is the collection empty?
    EXPECT_TRUE(collection->empty());

    // if empty then the size must be zero
    EXPECT_EQ(collection->size(), 0);

    // Using ASSERT because it is part of the test case
    // verify that an exception is thrown when trying to reserve a size that is larger than max_size() for the collection
    ASSERT_THROW(collection->reserve(collection->max_size() + 1), std::length_error);
}