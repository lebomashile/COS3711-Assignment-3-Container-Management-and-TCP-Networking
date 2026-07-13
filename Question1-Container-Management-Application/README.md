# Question 1 – Container Management Application

## Overview

This project is a desktop application developed using **C++** and the **Qt Framework** for creating, managing, and organising shipping containers.

The application allows users to create different container types, allocate containers to pallets, calculate pallet statistics, generate XML data, and transmit the information to a TCP server application.

---

## Features

- Create Box containers
- Create Cylinder containers
- Automatic container code generation
- Allocate containers to pallets
- Calculate pallet weight
- Calculate pallet volume
- Backup and restore unallocated containers
- Generate XML representation of pallet data
- Send XML data over TCP
- Menu bar and toolbar
- User-friendly graphical interface

---

## Main Classes

- MainClient
- MainWindow
- Container
- Box
- Cylinder
- ContainerFactory
- Pallet
- UnallocatedList
- ContainerMemento
- XmlWriter
- Client

---

## Design Patterns Used

### Factory Pattern

The `ContainerFactory` class is responsible for creating different container types (Box and Cylinder) while hiding the object creation process from the rest of the application.

### Memento Pattern

The `ContainerMemento` class provides backup and restore functionality for the list of unallocated containers, allowing previous application states to be recovered.

---

## Key Programming Concepts

- Object-Oriented Programming
- Inheritance
- Abstract Classes
- Polymorphism
- Factory Pattern
- Memento Pattern
- XML Serialization
- TCP Networking
- Event-Driven Programming
- Signals and Slots
- Model-View Programming
- Memory Management

---

## How to Run

1. Open the project in Qt Creator.
2. Configure a Qt Kit.
3. Build the project.
4. Run the application.
5. Create containers.
6. Allocate containers to pallets.
7. Generate and send XML data to the TCP Container Server.

---

## Skills Demonstrated

- Desktop Application Development
- Object-Oriented Programming
- Design Patterns
- Factory Pattern
- Memento Pattern
- XML Serialization
- TCP Client Communication
- Qt Widgets
- Qt XML
- Qt Network
- Model-View Programming
- Software Architecture

---

## Key Learning Outcomes

Through this project I gained practical experience with:

- Applying the Factory and Memento design patterns.
- Designing reusable object-oriented software.
- Developing desktop applications using Qt.
- Managing application state through backup and restore functionality.
- Generating structured XML documents.
- Communicating with remote applications using TCP sockets.

---

## Future Improvements

- SQLite database integration
- User authentication
- Secure TCP communication
- Undo/Redo functionality
- Improved validation
- Unit testing
