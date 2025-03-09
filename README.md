First-Come-First-Serve (FCFS) CPU Scheduler

Overview
This program implements a First-Come-First-Serve (FCFS) CPU scheduling algorithm. 
The program takes input for burst time and arrival time for a set of processes, 
then calculates their completion time and turnaround time according to FCFS 
scheduling principles.

Features
- Handles 3 processes (can be modified for more)
- Sorts processes by arrival time for proper FCFS implementation
- Calculates and displays key scheduling metrics:
  - Burst Time (BT): Time required for process execution
  - Arrival Time (AT): Time at which process arrives in the ready queue
  - Turnaround Time (TT): Time from arrival to completion
  - Completion Time (CT): Time when process execution finishes

Implementation Details
- Uses dynamic memory allocation to create arrays for each process
- Each process has a 4-element array storing:
  - Index 0: Burst Time (BT)
  - Index 1: Arrival Time (AT)
  - Index 2: Turnaround Time (TT)
  - Index 3: Completion Time (CT)
- Processes are sorted by arrival time using a simple bubble sort
- CPU idle time is handled correctly when there's a gap between processes

Algorithm
1. Collect burst time and arrival time for each process
2. Sort processes by arrival time
3. Calculate completion time for each process:
   - If current time < process arrival time, CPU waits (remains idle)
   - Process executes for its burst time
   - Completion time = current time after execution
4. Calculate turnaround time for each process:
   - Turnaround time = Completion time - Arrival time
5. Display results in a formatted table

Memory Management
The program properly frees all dynamically allocated memory before termination to prevent memory leaks.
