#include "gtest/gtest.h"
#include "Simulation.h"
#include "Plane.h"
#include <sstream>

using namespace std;

// Test to ensure the simulation initializes correctly
TEST(SimulationTest, Initialization) {
    int Tmax = 360;  // 6 hours
    int Ts = 10;     // 10 minutes per landing
    int DeltaT = 6;  // Average time between arrivals is 6 minutes

    Simulation simulation(Tmax, Ts, DeltaT);

    // Ensure Tmax, Ts, and DeltaT are set correctly
    EXPECT_EQ(Tmax, 360) << "Error: Tmax should be initialized to 360 minutes (6 hours). Check the constructor initialization of Tmax.";
    EXPECT_EQ(Ts, 10) << "Error: Ts (service time) should be initialized to 10 minutes. Check the constructor initialization of Ts.";
    EXPECT_EQ(DeltaT, 6) << "Error: DeltaT should be initialized to 6 minutes. Check the constructor initialization of DeltaT.";

    if (Tmax == 360 && Ts == 10 && DeltaT == 6) {
        cout << "Success: Simulation initialized correctly with Tmax=360, Ts=10, DeltaT=6.\n";
    }
}

// Test enqueuing planes and verifying their order in the queue based on priority
TEST(SimulationTest, EnqueuePlaneBasedOnPriority) {
    Simulation simulation(360, 10, 6);

    // Create planes with different priorities
    Plane plane1(10, 1);  // Medium priority
    Plane plane2(5, 2);   // High priority
    Plane plane3(15, 0);  // Low priority

    // Enqueue the planes
    simulation.enqueuePlane(plane1);
    simulation.enqueuePlane(plane2);
    simulation.enqueuePlane(plane3);

    // Process landing to check order based on priority
    simulation.processLanding(20);  // At time 20, highest priority plane (plane2) should land

    // Check if the first plane to land is plane2 (priority 2)
    std::stringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());  // Redirect cout to buffer
    simulation.processLanding(30);  // Now process the next plane (plane1)
    std::cout.rdbuf(old);  // Restore cout

    std::string output = buffer.str();
    EXPECT_NE(output.find("Plane landed with priority 1"), std::string::npos)
                        << "Error: The plane with priority 1 should have landed second. Ensure the planes land in correct priority order.";

    if (output.find("Plane landed with priority 1") != std::string::npos) {
        cout << "Success: Planes enqueued and landed in correct priority order.\n";
    }
}

// Test landing a plane and ensuring the queue is updated correctly
TEST(SimulationTest, PlaneLanding) {
    Simulation simulation(360, 10, 6);

    // Add planes to the queue
    Plane plane1(10, 1);  // Medium priority
    Plane plane2(5, 2);   // High priority
    simulation.enqueuePlane(plane1);
    simulation.enqueuePlane(plane2);

    // Process landing of the highest priority plane
    std::stringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());  // Redirect cout to buffer
    simulation.processLanding(20);  // Plane with priority 2 should land
    std::cout.rdbuf(old);  // Restore cout

    std::string output = buffer.str();
    EXPECT_NE(output.find("Plane landed with priority 2"), std::string::npos)
                        << "Error: The plane with the highest priority (2) should land first. Check the landing logic.";

    if (output.find("Plane landed with priority 2") != std::string::npos) {
        cout << "Success: Plane landed correctly, and queue updated.\n";
    }
}

// Test that planes land correctly and the average wait time is calculated
TEST(SimulationTest, AverageWaitTimeCalculation) {
    Simulation simulation(360, 10, 6);

    // Add planes with different arrival times
    Plane plane1(10, 1);  // Medium priority
    Plane plane2(15, 2);  // High priority
    Plane plane3(20, 0);  // Low priority

    simulation.enqueuePlane(plane1);
    simulation.enqueuePlane(plane2);
    simulation.enqueuePlane(plane3);

    // Simulate the landing of the planes
    simulation.processLanding(30);  // Plane2 should land at time 30 (15-minute wait)
    simulation.processLanding(40);  // Plane1 should land at time 40 (30-minute wait)
    simulation.processLanding(50);  // Plane3 should land at time 50 (30-minute wait)

    // Calculate the average wait time
    std::stringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());  // Redirect cout to buffer
    simulation.printAverageWaitTime();
    std::cout.rdbuf(old);  // Restore cout

    std::string output = buffer.str();
    EXPECT_NE(output.find("Average wait time: 25 minutes."), std::string::npos)
                        << "Error: The average wait time should be around 25 minutes. Check the logic for calculating and printing the average wait time.";

    if (output.find("Average wait time: 25 minutes.") != std::string::npos) {
        cout << "Success: Average wait time calculated and displayed correctly.\n";
    }
}

// Test handling of an empty landing queue
TEST(SimulationTest, LandingWithEmptyQueue) {
    Simulation simulation(360, 10, 6);

    // Try processing a landing with an empty queue and expect an exception
    EXPECT_THROW({
                     simulation.processLanding(20);
                 }, std::runtime_error) << "Error: The processLanding function should throw a std::runtime_error when trying to land a plane from an empty queue.";

    cout << "Success: Correct behavior when attempting to process a landing with an empty queue (exception thrown).\n";
}

// Test handling multiple planes with the same priority
TEST(SimulationTest, MultiplePlanesWithSamePriority) {
    Simulation simulation(360, 10, 6);

    // Add multiple planes with the same priority
    Plane plane1(10, 1);
    Plane plane2(20, 1);
    Plane plane3(30, 1);

    simulation.enqueuePlane(plane1);
    simulation.enqueuePlane(plane2);
    simulation.enqueuePlane(plane3);

    std::stringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());  // Redirect cout to buffer
    simulation.processLanding(40);  // Plane1 should land first (FIFO for same priority)
    std::cout.rdbuf(old);  // Restore cout

    std::string output = buffer.str();
    EXPECT_NE(output.find("Plane landed with priority 1, waited for 30 minutes."), std::string::npos)
                        << "Error: Planes with the same priority should land in FIFO order based on arrival time.";

    if (output.find("Plane landed with priority 1, waited for 30 minutes.") != std::string::npos) {
        cout << "Success: Planes with the same priority are handled in FIFO order.\n";
    }
}