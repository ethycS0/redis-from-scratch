# Redis-From-Scratch

Redis-From-Scratch is a personal project where I built a simple Redis-like server and client entirely from scratch using **C++**. This project was created to deepen my understanding of fundamental computer science concepts, including **socket programming**, **protocol design**, and **basic data storage mechanisms**.

## Overview

### Features
- **Custom Redis Protocol (RESP) implementation**: Designed a basic protocol to communicate between the server and client.
- **Socket Programming**: Established network communication between the server and client using raw sockets.
- **Polling Mechanism**: Integrated polling to handle multiple client connections efficiently and process requests faster.
- **Basic Data Storage**: Used the standard `std::map` from `<map>` as a simple key-value store for data persistence.

### Design Highlights
- **Server-Client Architecture**: The project simulates a minimal Redis-like server that listens for client requests, processes commands, and returns responses.
- **Command Parsing**: Implements basic command parsing, adhering to a simplified version of the RESP protocol.
- **Key-Value Store**: Supports basic operations using `std::map`, offering functionality similar to simple GET, SET and DEL commands.

### Learning Objectives
This project is a learning exercise intended to:
- Explore low-level network programming concepts.
- Understand protocol design for client-server communication.
- Gain practical experience in building scalable systems by starting with a minimal implementation.

### Limitations
- Currently only supports basic data operations (GET, SET, DEL) with `std::map`.
- Advanced data structures and features of a full Redis implementation, such as persistence, replication, or clustering, are not included.

## Future Improvements
- Implement additional data structure.
- Explore optimizations for performance and memory efficiency.
