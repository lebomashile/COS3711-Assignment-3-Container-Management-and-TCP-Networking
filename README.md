# COS3711-Assignment-3-Container-Management-and-TCP-Networking

## Overview

This repository contains my solution for **COS3711 – Advanced Programming Assignment 3**, completed as part of my Bachelor of Science in Computer Science studies at the **University of South Africa (UNISA)**.

The assignment focuses on advanced object-oriented software development using the **Qt Framework** and demonstrates desktop application development, design patterns, XML serialization, TCP networking, multithreading, model-view programming, and software architecture through two interconnected applications.

---

# Technologies Used

- C++
- Qt Widgets
- Qt Network
- Qt XML
- Qt Core
- CMake
- Qt Creator

---

# Design Patterns Used

This project demonstrates the implementation of several software engineering design patterns:

- Factory Pattern
- Memento Pattern
- Model-View Architecture

---

# Question 1 – Container Management Application

A desktop application used to create, manage and organise shipping containers before transmitting their information to a remote server.

### Features

- Create Box containers
- Create Cylinder containers
- Automatic container code generation
- Move containers onto pallets
- Backup and restore unallocated containers using the Memento pattern
- Calculate pallet weight and volume
- XML serialization
- TCP communication
- Manual Qt GUI development
- Menus and toolbars

📄 See the detailed documentation in:

```text
Question1-Container-Management-Application/README.md
```

---

# Question 2 – TCP Container Server

A companion desktop application that receives XML data over TCP, validates container codes using regular expressions, parses the XML, and displays the received information using Qt's Model-View framework.

### Features

- TCP server
- XML parsing
- Regular expression validation
- Table View display
- Real-time updates
- Model-View Programming

📄 See the detailed documentation in:

```text
Question2-TCP-Container-Server/README.md
```

---

# Skills Demonstrated

- Desktop Application Development
- Object-Oriented Programming
- Factory Pattern
- Memento Pattern
- TCP Networking
- XML Serialization
- XML Parsing
- Qt Widgets
- Qt Network
- Qt XML
- Model-View Programming
- Event-Driven Programming
- Signals and Slots
- Memory Management
- Regular Expressions
- Software Architecture


---

# Requirements

- Qt Creator
- Qt 6.x
- C++17 Compiler
- CMake

---

# How to Run

1. Build the **TCP Container Server**.
2. Start the server and begin listening on port **6164**.
3. Build and run the **Container Management Application**.
4. Create containers and assign them to pallets.
5. Generate and send XML data.
6. Observe the received data displayed by the server.

---

# Learning Outcomes

Through this assignment I strengthened my understanding of:

- Advanced Object-Oriented Programming
- Design Patterns
- Desktop Application Development
- XML Serialization
- XML Parsing
- TCP Client-Server Communication
- Model-View Programming
- Software Architecture
- Memory Management
- Event-Driven Programming

---

# Future Improvements

- SQLite database integration
- User authentication
- Secure TCP communication
- Improved error handling
- Logging
- Unit testing
- Enhanced user interface

---

## Author

**Lebohang Mashile**

BSc Computer Science Graduate (UNISA)

This repository forms part of my academic software development portfolio, showcasing practical implementation of advanced C++ programming concepts, desktop application development, and software engineering principles.
