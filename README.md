<h2 align="center">CSCE 2211 Fall 2024 Applied Data Structures</h2>
<h3 align="center">Assignment 2</h3>

> [!IMPORTANT]  
> Write your name, section number, and ID in comment at the beginning of each file, then push your changes. 📝

<table border="0">
 <tr>
    <td><b style="font-size:20px">📋 Prerequisites for the Assignment</b></td>
    <td><b style="font-size:20px">🛠️ How It Works (Testing Cases)</b></td>
 </tr>
 <tr>
    <td>
    1. Create a <a href="https://account.jetbrains.com/login" target="_blank">JetBrains Account</a> & apply for the student pack. 🎓<br>    
    2. Download <a href="https://www.jetbrains.com/clion/download/#section=mac" target="_blank">CLion for Windows & Mac</a> and sign in with your account. 💻<br>    
    3. Sign in to the GitHub Desktop app on your PC. 🔗<br>  
    4. Clone this repository to start working on the assignment. 📂<br>
    5. Write your name and ID in a comment at the beginning of each file, then push your changes. 📝<br>
    </td>
    <td>
    1. Open the repo folder as a project in CLion IDE. 🚀<br> 
    2. Start writing your code in the <strong>Code_lib</strong> directory. 🖊️<br>
    3. After completing the required parts, go to <strong>Google_tests</strong> and run <strong>TestDEQ.cpp</strong>, <strong>TestPlane.cpp</strong> and <strong>TestSimulation.cpp</strong> to test your code. 🧪<br>
    4. The test suite files will show which tests have passed and which have failed. ✅❌<br>
    </td>
 </tr>
</table>

> [!WARNING]  
> - Your submission time affect the assignment grade; pay attention to your grades and submit on time.
> - You have to commit and push your code to Github at the end of each change.

## 🔍 Overview of the Assignment
This assignment consists of two main problems related to data structures and simulations. You will implement a Double-Ended Queue (DEQ) and use it in a simulation of a waiting queue for planes at an airport. The assignment is split into two key sections:  
1.	**The DEQ ADT Implementation** (50 points)
2.  **Simulation of a Waiting Queue of Planes in an Airport** (50 points)

Each part of the assignment builds on fundamental data structure concepts, particularly focusing on linked lists and queues.  
📕 [Check the Assignment PDF](CSCE_2211_Assignment2.pdf)

> [!TIP]
> Use the [visualization tool](https://visualgo.net/en/list)

***

## 🧱 The DEQ ADT (50 Points) [Go to the DEQ Code](Code_lib/DEQ.cpp)

The DEQ (Double-Ended Queue) is a sequential container similar to both a Stack and a Queue, where elements can be added or removed from both the front and rear.

🔨 Required Implementation

You are required to implement a template class DEQ using a Simple Linked List (SLL). The DEQ should support the following operations:

- **Constructor**: Initialize an empty DEQ.
- **Destructor**: Properly destroy and deallocate memory for the DEQ.
- **DEQisEmpty**: Test if the DEQ is empty.
- **Add_Front**: Add an element to the front of the DEQ.
- **Add_Rear**: Add an element to the rear of the DEQ.
- **Remove_Front**: Remove and return the element at the front of the DEQ.
- **Remove_Rear**: Remove and return the element at the rear of the DEQ.
- **View_Front**: Retrieve (without removal) the front element.
- **View_Rear**: Retrieve (without removal) the rear element.
- **DEQ_Length**: Return the number of elements in the DEQ.

📁 Files to Implement `DEQ.cpp - Implementation of the DEQ functions.`

🚀 Instructions

- Implement all required member functions in DEQ.cpp.
- Comment your code and document any assumptions you made while implementing the DEQ.
- Test your DEQ implementation using the provided unit tests in the TestDEQ.cpp file.

***

## ✈️ Simulation of a Waiting Queue of Planes in an Airport (50 Points) [Go to Simulation Code](Code_lib/Simulation.cpp)

In this simulation, you will implement a priority queue using the DEQ and simulate the operation of an airport’s landing queue. Each plane arriving near the airport must wait in a queue until the runway is free. The queue gives priority based on fuel levels (or other conditions), and planes with higher priority land first.

#### ✍️ Required Implementation

Implement the PriorityLinkedQueue class to simulate the following:

- Arrival Time: Planes arrive at random times based on a specified interval (∆T).
- Service Time: Planes land at fixed intervals (Ts).
- Priority: Planes join the queue based on priority (0 = low, 2 = high).
- Average Wait Time: Calculate and print the average wait time for planes during the simulation.

#### Simulation Details

- Time unit: 1 minute.
- Tmax: Total simulation period = 6 hours (360 minutes).
- Ts: Time to land each plane = 10 minutes.
- ∆T: Average inter-arrival time = 6 minutes.
- Randomly generate priorities for each plane between 0 and 2.
- Log the events of plane arrivals and landings for each run of the simulation.

📁 Files to Implement `Simulation.cpp - Implementation of the airport simulation.`

#### 🚀 Instructions

- Implement the Plane class and Simulation class using the provided skeleton files.
- Ensure that your simulation calculates the average wait time correctly and logs each event (plane arrival, landing).
- Test your simulation using the provided unit tests in the TestSimulation.cpp file.

### 🔧 Testing Your Code
- Run the DEQ tests [Test your DEQ code](Google_tests/TestDEQ.cpp).
- Run the Simulation tests [Test your Simulation code](Google_tests/TestSimulation.cpp).

Ensure that all test cases pass before submitting your assignment.

### 📬 Submission Instructions:
- Comment your code and document any assumptions you made.

***
📝 To-Do List
- [ ] Run all test cases successfully.
- [ ] Commit and push your code regularly to GitHub.
- [ ] Submit your final code before the deadline (September 29th, 2024, 11:59 CLT).

:white_check_mark: Use `git status` to list all new or modified files that haven't yet been committed.

<p align="center">
  <b>Created by</b><br>
  <b>Mohamed Ibrahim Hany</b>
</p>
