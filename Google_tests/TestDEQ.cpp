#include "gtest/gtest.h"
#include "DEQ.h"

using namespace std;
// Test to check if the DEQ is initialized as empty
TEST(DEQTest, Initialization) {
    DEQ<int> deq;
    EXPECT_TRUE(deq.DEQisEmpty()) << "Error: DEQ should be empty after initialization. Ensure the constructor properly initializes the front and rear pointers.";
    EXPECT_EQ(deq.DEQ_Length(), 0) << "Error: DEQ length should be 0 after initialization. Verify that the length is properly initialized to 0.";
    if (deq.DEQisEmpty() && deq.DEQ_Length() == 0) {
        cout << "Success: DEQ initialized correctly as empty.\n";
    }
}

// Test to add elements to the front and check the values
TEST(DEQTest, AddFront) {
    DEQ<int> deq;

    deq.Add_Front(10);
    EXPECT_EQ(deq.DEQ_Length(), 1) << "Error: After adding an element to the front, DEQ length should be 1. Ensure that the length is incremented correctly.";
    EXPECT_EQ(deq.View_Front(), 10) << "Error: After adding 10 to the front, View_Front() should return 10. Verify the logic in Add_Front() and View_Front().";
    EXPECT_EQ(deq.View_Rear(), 10) << "Error: When the DEQ has only one element, View_Rear() should return the same value as View_Front().";

    deq.Add_Front(20);
    EXPECT_EQ(deq.DEQ_Length(), 2) << "Error: After adding another element to the front, DEQ length should be 2.";
    EXPECT_EQ(deq.View_Front(), 20) << "Error: After adding 20 to the front, View_Front() should return 20. Check that the front pointer is correctly updated.";
    EXPECT_EQ(deq.View_Rear(), 10) << "Error: View_Rear() should still return 10 after adding 20 to the front.";

    deq.Add_Front(30);
    EXPECT_EQ(deq.DEQ_Length(), 3) << "Error: After adding a third element to the front, DEQ length should be 3.";
    EXPECT_EQ(deq.View_Front(), 30) << "Error: After adding 30 to the front, View_Front() should return 30. Verify that each new node is inserted at the correct position.";
    EXPECT_EQ(deq.View_Rear(), 10) << "Error: View_Rear() should still return 10 after adding multiple elements to the front.";

    if (deq.DEQ_Length() == 3 && deq.View_Front() == 30 && deq.View_Rear() == 10) {
        cout << "Success: Elements added to the front correctly and values verified.\n";
    }
}

// Test to add elements to the rear and check the values
TEST(DEQTest, AddRear) {
    DEQ<int> deq;

    deq.Add_Rear(10);
    EXPECT_EQ(deq.DEQ_Length(), 1) << "Error: After adding an element to the rear, DEQ length should be 1. Ensure the length is incremented correctly.";
    EXPECT_EQ(deq.View_Front(), 10) << "Error: After adding 10 to the rear, View_Front() should return 10 as it's the only element.";
    EXPECT_EQ(deq.View_Rear(), 10) << "Error: After adding 10 to the rear, View_Rear() should also return 10 as it's the only element.";

    deq.Add_Rear(20);
    EXPECT_EQ(deq.DEQ_Length(), 2) << "Error: After adding another element to the rear, DEQ length should be 2.";
    EXPECT_EQ(deq.View_Front(), 10) << "Error: View_Front() should still return 10 after adding an element to the rear.";
    EXPECT_EQ(deq.View_Rear(), 20) << "Error: View_Rear() should return 20 after adding it to the rear. Check that the rear pointer is correctly updated.";

    deq.Add_Rear(30);
    EXPECT_EQ(deq.DEQ_Length(), 3) << "Error: After adding a third element to the rear, DEQ length should be 3.";
    EXPECT_EQ(deq.View_Front(), 10) << "Error: View_Front() should still return 10, as the front element should remain unchanged.";
    EXPECT_EQ(deq.View_Rear(), 30) << "Error: View_Rear() should return 30 after adding it to the rear. Ensure that each new node is inserted correctly at the rear.";

    if (deq.DEQ_Length() == 3 && deq.View_Front() == 10 && deq.View_Rear() == 30) {
        cout << "Success: Elements added to the rear correctly and values verified.\n";
    }
}

// Test to remove elements from the front and check the values
TEST(DEQTest, RemoveFront) {
    DEQ<int> deq;

    deq.Add_Front(10);
    deq.Add_Front(20);
    deq.Add_Front(30);

    EXPECT_EQ(deq.View_Front(), 30) << "Error: View_Front() should return 30 before removing it. Ensure the Add_Front() logic is correct.";
    deq.Remove_Front();
    EXPECT_EQ(deq.View_Front(), 20) << "Error: After removing the front element, View_Front() should return 20. Check that the front pointer is updated correctly in Remove_Front().";
    EXPECT_EQ(deq.DEQ_Length(), 2) << "Error: After removing one element from the front, DEQ length should be 2.";

    deq.Remove_Front();
    EXPECT_EQ(deq.View_Front(), 10) << "Error: After removing another front element, View_Front() should return 10.";
    EXPECT_EQ(deq.DEQ_Length(), 1) << "Error: After removing two elements from the front, DEQ length should be 1.";

    deq.Remove_Front();
    EXPECT_TRUE(deq.DEQisEmpty()) << "Error: After removing all elements, the DEQ should be empty.";
    EXPECT_EQ(deq.DEQ_Length(), 0) << "Error: DEQ length should be 0 after removing all elements.";

    if (deq.DEQisEmpty() && deq.DEQ_Length() == 0) {
        cout << "Success: Elements removed from the front correctly and DEQ is empty.\n";
    }
}

// Test to remove elements from the rear and check the values
TEST(DEQTest, RemoveRear) {
    DEQ<int> deq;

    deq.Add_Rear(10);
    deq.Add_Rear(20);
    deq.Add_Rear(30);

    EXPECT_EQ(deq.View_Rear(), 30) << "Error: View_Rear() should return 30 before removing it.";
    deq.Remove_Rear();
    EXPECT_EQ(deq.View_Rear(), 20) << "Error: After removing the rear element, View_Rear() should return 20. Check that the rear pointer is updated correctly in Remove_Rear().";
    EXPECT_EQ(deq.DEQ_Length(), 2) << "Error: After removing one element from the rear, DEQ length should be 2.";

    deq.Remove_Rear();
    EXPECT_EQ(deq.View_Rear(), 10) << "Error: After removing another rear element, View_Rear() should return 10.";
    EXPECT_EQ(deq.DEQ_Length(), 1) << "Error: After removing two elements from the rear, DEQ length should be 1.";

    deq.Remove_Rear();
    EXPECT_TRUE(deq.DEQisEmpty()) << "Error: After removing all elements, the DEQ should be empty.";
    EXPECT_EQ(deq.DEQ_Length(), 0) << "Error: DEQ length should be 0 after removing all elements.";

    if (deq.DEQisEmpty() && deq.DEQ_Length() == 0) {
        cout << "Success: Elements removed from the rear correctly and DEQ is empty.\n";
    }
}

// Test to view elements without removing them
TEST(DEQTest, ViewElements) {
    DEQ<int> deq;

    deq.Add_Front(100);
    deq.Add_Rear(200);

    EXPECT_EQ(deq.View_Front(), 100) << "Error: View_Front() should return 100 after adding 100 to the front.";
    EXPECT_EQ(deq.View_Rear(), 200) << "Error: View_Rear() should return 200 after adding 200 to the rear.";

    if (deq.View_Front() == 100 && deq.View_Rear() == 200) {
        cout << "Success: Elements viewed correctly without removal.\n";
    }
}

// Test edge case: removing from an empty DEQ should throw an appropriate error
TEST(DEQTest, RemoveFromEmptyDEQ) {
    DEQ<int> deq;

    // Expect Remove_Front() to throw a runtime error when trying to remove from an empty DEQ
    EXPECT_THROW(deq.Remove_Front(), runtime_error) << "Error: Remove_Front() should throw a runtime_error when attempting to remove from an empty DEQ.";

    // Expect Remove_Rear() to throw a runtime error when trying to remove from an empty DEQ
    EXPECT_THROW(deq.Remove_Rear(), runtime_error) << "Error: Remove_Rear() should throw a runtime_error when attempting to remove from an empty DEQ.";

    EXPECT_TRUE(deq.DEQisEmpty()) << "Error: The DEQ should remain empty after attempting to remove from an empty DEQ.";

    if (deq.DEQisEmpty()) {
        cout << "Success: Correct behavior when attempting to remove from an empty DEQ.\n";
    }
}

// Test edge case: viewing elements in an empty DEQ should throw an exception
TEST(DEQTest, ViewFromEmptyDEQ) {
    DEQ<int> deq;

    EXPECT_THROW(deq.View_Front(), out_of_range) << "Error: Viewing the front element of an empty DEQ should throw an out_of_range exception. Ensure this is handled in View_Front().";
    EXPECT_THROW(deq.View_Rear(), out_of_range) << "Error: Viewing the rear element of an empty DEQ should throw an out_of_range exception. Ensure this is handled in View_Rear().";

    cout << "Success: Correct behavior when attempting to view elements in an empty DEQ (exception thrown).\n";
}

// Test to check the DEQ length after various operations
TEST(DEQTest, LengthAfterOperations) {
    DEQ<int> deq;

    EXPECT_EQ(deq.DEQ_Length(), 0) << "Error: DEQ length should be 0 initially.";

    deq.Add_Front(10);
    deq.Add_Rear(20);
    EXPECT_EQ(deq.DEQ_Length(), 2) << "Error: After adding two elements, DEQ length should be 2.";

    deq.Remove_Front();
    EXPECT_EQ(deq.DEQ_Length(), 1) << "Error: After removing one element, DEQ length should be 1.";

    deq.Remove_Rear();
    EXPECT_EQ(deq.DEQ_Length(), 0) << "Error: After removing all elements, DEQ length should be 0.";

    if (deq.DEQ_Length() == 0) {
        cout << "Success: DEQ length tracked correctly after various operations.\n";
    }
}