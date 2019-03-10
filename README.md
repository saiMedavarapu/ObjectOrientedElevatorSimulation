# ObjectOrientedElevatorSimulation
The objective of this assignment is to extend the elevator service simulator. You need to develop
an object oriented code the simulate multiple elevators. Your code should take as input the following
parameters:
• The total number of floors.
• The number of elevators.
• The size of each elevator(the max number of people the elevator can hold).
• The time it takes to move between two floors for each elevator.
• The initial location of each elevator.
1. Your code should randomly generate a number of requests. the request should look like:
elevator source destination
1 3 23
4 12 1
2 1 10
. . .
. . .
2. Write an object oriented code to simulate the service provided by the elevators.(the algorithms
developed in homework 1 should be re-used in this home work).
3. Each elevator should randomly select with algorithm to use.
4. For each elevator, you should log the number of requests served by that elevator, the order in
which the requests have been served, the time it takes to serve each request, and total time it
takes to serve all requests.
