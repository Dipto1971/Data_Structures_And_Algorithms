# Virtual Call Center Project

This 'Data Structure' project implements a virtual call center with the ability to receive, assign, and manage customer calls using both C++(Basic) and JavaScript(Advanced) programming languages. The call center consists of multiple servers that handle customer calls for a fixed duration and save call history. It utilizes queues and asynchronous programming concepts to efficiently manage calls and server resources.

## Table of Contents
- [Project Overview (C++)](#project-overview-c)
- [Key Features of JavaScript Upgrade](#key-features-of-javascript-upgrade)
- [Project Structure](#project-structure)
- [How to Use](#how-to-use)
- [Sample Usage](#sample-usage)
- [Contributor](#contributor)
- [License](#license)

## Project Overview (C++)

A virtual call center is a centralized system used for receiving and transmitting a large volume of customer requests via telephone. The original C++ version of this project simulates the core functionalities of such a call center and includes the following features:

1. Enqueueing customer calls into a queue.
2. Automatically assigning calls to available servers based on server load.
3. Maintaining call history for each server using a stack.
4. Monitoring server availability and automatically freeing servers after call completion.
5. Manually forwarding pending calls to available servers.

The project is implemented in C++ and uses data structures like linked lists, stacks, and queues to efficiently manage customer calls and server resources.

## Key Features of JavaScript Upgrade

The JavaScript version of the virtual call center retains all the features of the original C++ project while introducing significant improvements:

1. **Asynchronous Processing**: The JavaScript version employs asynchronous programming using `async/await` to handle call durations. This ensures that calls are managed without blocking the main program thread, providing a more realistic and responsive simulation.

2. **Promises**: Promises are used in JavaScript to manage asynchronous operations. The `await this.wait(ms)` function returns a promise, allowing for smoother execution and efficient handling of calls.

3. **User Interaction**: While both versions provide a menu-driven user interface, the JavaScript version uses asynchronous input/output through the `prompt` function, aligning with JavaScript's event-driven nature. This enhances the user experience.

4. **Time Management**: JavaScript utilizes `Date.now()` for timestamping events, while C++ employs `time(nullptr)`. Both versions track the time left for servers to become available after handling calls, enhancing the realism of the simulation.

## Project Structure

The project consists of the following components:

- `main.js`: The main program for the JavaScript version that interacts with the virtual call center.
- `Call` class (JavaScript) / `Call` struct (C++): Represents an individual customer call, including ID, enqueue time, and duration.
- `Server` class (JavaScript) / `Server` struct (C++): Represents a server, including availability, call history array (JavaScript) / stack (C++), call count, and busy time.
- `VirtualCallCenter` class (JavaScript) / `VirtualCallCenter` struct (C++): Manages the entire call center, including an array of servers and a customer call queue.
- Functions/methods for initializing, enqueuing calls, updating server status, checking time left for servers, manually forwarding calls, and displaying call counts.

## How to Use

Follow the on-screen menu to interact with the virtual call center. The JavaScript version can be executed using Node.js.

## Sample Usage

Here's a sample interaction with the JavaScript-based virtual call center:

```plaintext
Menu:
1. Enter a Call (Automatic Assignment)
2. Check Total Pending Calls
3. Check Time Left for Servers
4. Forward Calls Manually
5. Display Call Counts for Servers
6. Exit

Enter your choice: 1
Enter the call duration (in seconds): 300
Call 1 added to the queue. Duration: 300 seconds.

Enter your choice: 4
Call 2 manually assigned to Server 1. Duration: 300 seconds.

Enter your choice: 6
