# Virtual Call Center Project

This project implements a virtual call center with the ability to receive, assign, and manage customer calls using C++ programming. The call center consists of multiple servers that handle customer calls for a fixed duration and save call history. It utilizes linked lists, stacks, and queues to efficiently manage calls and server resources.

## Table of Contents
- [Project Overview](#project-overview)
- [Project Structure](#project-structure)
- [How to Use](#how-to-use)
- [Sample Usage](#sample-usage)
- [Contributors](#contributors)
- [License](#license)

## Project Overview

A virtual call center is a centralized system used for receiving and transmitting a large volume of customer requests via telephone. This project simulates the core functionalities of such a call center, including:

1. Enqueueing customer calls into a queue.
2. Automatically assigning calls to available servers based on server load.
3. Maintaining call history for each server using a stack.
4. Monitoring server availability and automatically freeing servers after call completion.
5. Manually forwarding pending calls to available servers.

The project is implemented in C++ and uses data structures like linked lists, stacks, and queues to efficiently manage customer calls and server resources.

## Project Structure

The project is structured as follows:

- `main.cpp`: The main program that interacts with the virtual call center.
- `Call` struct: Represents an individual customer call, including ID, enqueue time, and duration.
- `Server` struct: Represents a server, including availability, call history stack, call count, and busy time.
- `VirtualCallCenter` struct: Manages the entire call center, including an array of servers and a customer call queue.
- Functions for initializing, enqueuing calls, updating server status, checking time left for servers, and forwarding calls manually.

## How to Use

Follow the on-screen menu to interact with the virtual call center.

## Sample Usage

Here's a sample interaction with the virtual call center:


Menu:
1. Enter a call (Automatic Assignment)
2. Show total pending calls
3. Check time left for servers to become free
4. Forward calls manually
5. Exit

Enter your choice: 1

Enter the call duration (in seconds): 300
Call 1 added to the queue. Duration: 300 seconds.


Enter your choice: 4
Call 2 manually assigned to Server 1. Duration: 300 seconds.


Enter your choice: 5


## Contributor

- Mahir Faysal Haque Dipto
