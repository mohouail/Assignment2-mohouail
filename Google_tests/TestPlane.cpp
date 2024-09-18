#include "gtest/gtest.h"
#include "Plane.h"
#include <sstream>

using namespace std;

// Test to check if the Plane object is initialized correctly
TEST(PlaneTest, PlaneInitialization) {
    // Test plane with priority 2 and arrival time 10
    Plane plane(10, 2);

    // Ensure arrival time and priority are correctly set
    EXPECT_EQ(plane.arrivalTime, 10) << "Error: The plane's arrival time should be 10. Make sure the constructor correctly initializes the arrivalTime.";
    EXPECT_EQ(plane.priority, 2) << "Error: The plane's priority should be 2. Ensure the constructor sets the priority correctly.";

    if (plane.arrivalTime == 10 && plane.priority == 2) {
        cout << "Success: Plane initialized correctly with arrival time 10 and priority 2.\n";
    }
}

// Test boundary case where priority is at its minimum (0)
TEST(PlaneTest, PlaneWithMinimumPriority) {
    // Test plane with priority 0 and arrival time 5
    Plane plane(5, 0);

    EXPECT_EQ(plane.arrivalTime, 5) << "Error: The plane's arrival time should be 5.";
    EXPECT_EQ(plane.priority, 0) << "Error: The plane's priority should be 0. Priority must be between 0 and 2.";

    if (plane.arrivalTime == 5 && plane.priority == 0) {
        cout << "Success: Plane initialized correctly with minimum priority (0).\n";
    }
}

// Test boundary case where priority is at its maximum (2)
TEST(PlaneTest, PlaneWithMaximumPriority) {
    // Test plane with priority 2 and arrival time 20
    Plane plane(20, 2);

    EXPECT_EQ(plane.arrivalTime, 20) << "Error: The plane's arrival time should be 20.";
    EXPECT_EQ(plane.priority, 2) << "Error: The plane's priority should be 2. Priority must be between 0 and 2.";

    if (plane.arrivalTime == 20 && plane.priority == 2) {
        cout << "Success: Plane initialized correctly with maximum priority (2).\n";
    }
}

// Test out-of-bound values to ensure the class correctly handles priority limits (even if the current code doesn't handle this, it's good to check)
TEST(PlaneTest, PlaneWithInvalidPriority) {
    Plane plane(15, 5);  // Invalid priority, should still be set

    // Validate that priority 5, which is out of the valid range, can be identified
    EXPECT_EQ(plane.priority, 5) << "Error: The plane's priority is out of the expected range (0-2).";

    if (plane.priority == 5) {
        cout << "Success: Plane initialized with out-of-range priority for testing.\n";
    }
}

// Test the overloaded << operator to check if plane details are correctly formatted
TEST(PlaneTest, PlaneOutputStream) {
    // Plane with priority 1 arriving at time 15
    Plane plane(15, 1);

    stringstream output;
    output << plane;

    // Check if the output stream is formatted correctly
    EXPECT_EQ(output.str(), "Plane with priority 1 arrived at 15") << "Error: The << operator should return 'Plane with priority <priority> arrived at <arrivalTime>'. Make sure the output format is correct.";

    if (output.str() == "Plane with priority 1 arrived at 15") {
        cout << "Success: The << operator for the Plane class works as expected.\n";
    }
}

// Test if the constructor can handle negative arrival time (should still allow it, though it is unusual)
TEST(PlaneTest, NegativeArrivalTime) {
    Plane plane(-10, 1);  // Negative arrival time for edge case testing

    EXPECT_EQ(plane.arrivalTime, -10) << "Error: The plane's arrival time should be -10. Ensure the constructor can handle unusual but valid values.";

    if (plane.arrivalTime == -10) {
        cout << "Success: Plane initialized correctly with a negative arrival time.\n";
    }
}

// Test if the Plane class behaves as expected with extreme values for arrival time and priority
TEST(PlaneTest, ExtremeValues) {
    Plane plane(1000000, 2);  // Large arrival time, maximum priority

    EXPECT_EQ(plane.arrivalTime, 1000000) << "Error: The plane's arrival time should be 1,000,000. Ensure large values are supported by the class.";
    EXPECT_EQ(plane.priority, 2) << "Error: The plane's priority should be 2.";

    if (plane.arrivalTime == 1000000 && plane.priority == 2) {
        cout << "Success: Plane initialized correctly with extreme values.\n";
    }
}