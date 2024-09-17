BrowserStackSim
BrowserStackSim is a simple C-based program that simulates an internet browser's back and forward button functionality using stacks. This project demonstrates how to manage browser history using stack data structures to implement backward and forward navigation.

Introduction
This project implements a basic simulation of web browser navigation using two stacks—one for the "back" history and one for the "forward" history. When a user navigates to a new page, the previous page is pushed onto the back stack. If the user clicks the "back" button, the current page is moved to the forward stack and the top of the back stack becomes the current page. The "forward" button allows the user to return to previously visited pages.

Features
* Simulates browser history with "back" and "forward" navigation.
* Handles browser history using stack data structures.
* Displays current page and history stacks in the terminal.
* Simple and lightweight C program.

How to Run
In the terminal:
Compile the program using:
gcc browser_simulation.c -o browser_simulation
Run the program using:
./browser_simulation

Output:
Initial State:
Current page: www.reddit.com
Back Stack:
  www.google.com
  www.youtube.com

Forward Stack:
  (empty)

Going back to: www.google.com
After Going Back:
Current page: www.google.com
Back Stack:
  www.youtube.com

Forward Stack:
  www.reddit.com

Going back to: www.youtube.com
After Going Back Again:
Current page: www.youtube.com
Back Stack:
  (empty)

Forward Stack:
  www.google.com
  www.reddit.com

Going forward to: www.google.com
After Going Forward:
Current page: www.google.com
Back Stack:
  www.youtube.com

Forward Stack:
  www.reddit.com

Going forward to: www.reddit.com
After Going Forward:
Current page: www.reddit.com
Back Stack:
  www.google.com
  www.youtube.com

Forward Stack:
  (empty)
