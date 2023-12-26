const NUM_SERVERS = 3;
const MAX_CALLS = 1000;

class Call {
  constructor(id, enqueueTime, duration) {
    this.id = id;
    this.enqueueTime = enqueueTime;
    this.duration = duration; // Duration of the call in seconds
  }
}

class Server {
  constructor() {
    this.isFree = true;
    this.callHistory = [];
    this.callCount = 0;
    this.busyUntil = 0; // Time when the server will be free
  }
}

class VirtualCallCenter {
  constructor() {
    this.servers = Array(NUM_SERVERS).fill(null).map(() => new Server());
    this.customerQueue = [];
    this.front = this.rear = -1;
  }

  enqueue(id, duration) {
    if (this.rear === MAX_CALLS - 1) {
      console.log(`Queue is full. Call ${id} could not be enqueued.`);
      return;
    }

    const call = new Call(id, Date.now(), duration);
    if (this.front === -1) {
      this.front = 0;
    }
    this.rear++;
    this.customerQueue[this.rear] = call;

    // Automatically assign calls to servers based on load (less loaded server first).
    this.servers.forEach(async (server, i) => {
      if (server.isFree && this.front <= this.rear) {
        const newCall = this.customerQueue[this.front];
        server.isFree = false;
        server.busyUntil = Date.now() + newCall.duration * 1000; // Convert duration to milliseconds
        server.callHistory.push(newCall);
        server.callCount++;
        console.log(`\nCall ${newCall.id} assigned to Server ${i + 1}. Duration: ${newCall.duration} seconds.\n`);
        this.front++;
        await this.wait(newCall.duration * 1000); // Wait asynchronously
        server.isFree = true;
        
        // Check if there are calls waiting in the queue and assign them to the now free server
        if (this.front <= this.rear) {
          const waitingCall = this.customerQueue[this.front];
          server.isFree = false;
          server.busyUntil = Date.now() + waitingCall.duration * 1000;
          server.callHistory.push(waitingCall);
          server.callCount++;
          console.log(`Call ${waitingCall.id} assigned to Server ${i + 1} (from queue). Duration: ${waitingCall.duration} seconds.`);
          this.front++;
          await this.wait(waitingCall.duration * 1000);
          server.isFree = true;
        }
      }
    });

    console.log(`Call ${id} added to the queue. Duration: ${duration} seconds.`);
  }

  wait(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
  }

  updateServerStatus() {
    const currentTime = Date.now();
    this.servers.forEach(server => {
      if (!server.isFree && currentTime >= server.busyUntil) {
        server.isFree = true;
      }
    });
  }

  checkTimeLeft() {
    this.servers.forEach((server, i) => {
      if (!server.isFree) {
        const currentTime = Date.now();
        const timeLeft = (server.busyUntil - currentTime) / 1000; // Convert to seconds
        console.log(`Server ${i + 1} will be free in ${timeLeft} seconds.`);
      }
    });
  }

  forwardCallsManually() {
    if (this.front > this.rear) {
      console.log("No pending calls to forward.");
      return;
    }

    this.servers.forEach(async (server, i) => {
      if (server.isFree && this.front <= this.rear) {
        const newCall = this.customerQueue[this.front];
        server.isFree = false;
        server.busyUntil = Date.now() + newCall.duration * 1000; // Convert duration to milliseconds
        server.callHistory.push(newCall);
        server.callCount++;
        console.log(`Call ${newCall.id} manually assigned to Server ${i + 1}. Duration: ${newCall.duration} seconds.`);
        this.front++;
        await this.wait(newCall.duration * 1000); // Wait asynchronously
        server.isFree = true;
      }
    });
  }

  displayCallCounts() {
    console.log("Call Counts for Servers:");
    this.servers.forEach((server, i) => {
      console.log(`Server ${i + 1}: ${server.callCount} calls.`);
    });
  }
}

function showMenu() {
  console.log("\n=== Virtual Call Center Menu ===");
  console.log("1. Enter a Call (Automatic Assignment)");
  console.log("2. Check Total Pending Calls");
  console.log("3. Check Time Left for Servers");
  console.log("4. Forward Calls Manually");
  console.log("5. Display Call Counts for Servers");
  console.log("6. Exit");
}

async function main() {
  const callCenter = new VirtualCallCenter();
  let callId = 1;
  let callDuration;
  let isRunning = true;

  while (isRunning) {
    callCenter.updateServerStatus();
    showMenu();

    const choice = parseInt(await prompt("Enter your choice: "), 10);

    switch (choice) {
      case 1:
        if (callId <= MAX_CALLS) {
          callDuration = parseInt(await prompt("Enter the call duration (in seconds): "), 10);
          callCenter.enqueue(callId++, callDuration);
        } else {
          console.log("Maximum number of calls reached.");
        }
        break;
      case 2:
        console.log(`Total pending calls: ${callCenter.rear - callCenter.front + 1}`);
        break;
      case 3:
        callCenter.checkTimeLeft();
        break;
      case 4:
        callCenter.forwardCallsManually();
        break;
      case 5:
        callCenter.displayCallCounts();
        break;
      case 6:
        isRunning = false; // Exit the loop and end the program
        break;
      default:
        console.log("Invalid choice. Please try again.");
    }
  }
  console.log("Goodbye!"); // Optional exit message
}

main();

function prompt(question) {
  const readline = require('readline');
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
  });

  return new Promise(resolve => {
    rl.question(question, answer => {
      rl.close();
      resolve(answer);
    });
  });
}
