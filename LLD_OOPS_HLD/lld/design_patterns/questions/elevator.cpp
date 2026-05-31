#include<bits/stdc++.h>

using namespace std;

/**
 * Problem Statement:
 * You are designing a system that:

    Handles multiple elevators + multiple floors
    Supports:
    External requests (UP/DOWN from floors)
    Internal requests (destination inside elevator)
    Optimizes:
    Wait time
    Movement efficiency
    Ensures:
    Safety (overload, emergency stop, sensors) 


    Interviewer: Can you solve the elevator system design problem?
    Candidate: certainly! Here's is my understanding of the problem and how I would approach it.
    - the system manages multiple elevators and multiple floors
    - user can request an elevator from a floor (external request) and can also select a destination floor from inside the elevator (internal request)
    - the system should optimize wait time and movement efficiency while ensuring safety (e.g., overload protection, emergency stop, sensors)
    - the system should be scalable to handle building of different sizes and traffic patterns.


    Interviewer: Pls contunues Ahead;
    Candidate: Before we dive into the design, let's clarify some requirements and assumptions:
    - How many elevators and floors are we dealing with? (e.g., 4 elevators and 10 floors)
    - Are there any specific constraints on the elevator's speed, capacity, or response time?
    - how shoild the syste optimzee the elevator assgn,ment


    clarification of the Requirements:
    - Support for multiple elevators and floors.
    - External requests (UP/DOWN from floors) and internal requests (destination inside elevator).
    - Optimization of wait time and movement efficiency.
    - Safety features (overload protection, emergency stop, sensors).
    - Scalability to handle different building sizes and traffic patterns.

    Identification of the Main Components:
    - elevator class -> represent the elevator and its attributes (e.g., current floor, direction, capacity, status).
    - Building class -> contains the logic for managing elevators, handling requests, and optimizing movement.
    - Floor class -> represent a Single Floor
    - ElevatorController -> Mangages the coordination b/w all the elevators
    
 */ 
enum Direction {
    UP,
    DOWN,
    IDLE
};
enum ElevatorState{
      MOVING,
      STOPPED,
      MAINTENANCE
};
class Elevator {
   int id;
   int currentFloor;
   Direction direction;
   ElevatorState state;
   vector<ElevatorObservers*> observers; // for safety monitoring and notifications
   vector<ElevatorRequests*>request;

};


class Building {
   int numFloors;
   ElevatorController* controller;

};



