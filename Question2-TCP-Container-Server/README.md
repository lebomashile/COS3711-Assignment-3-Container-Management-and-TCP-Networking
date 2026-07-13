# Question 2 – TCP Container Server

## Overview

This project is a Qt desktop application that acts as a TCP server for the Container Management Application. It listens for incoming XML data, validates container codes using regular expressions, parses the XML, and displays the received container information using Qt's Model-View framework.

---

## Features

- TCP server
- Listens on port 6164
- Receives XML container data
- Parses XML documents
- Validates container codes using Regular Expressions
- Displays data in a table view
- Updates automatically when new data is received

---

## Main Classes

- Gui
- Server
- XmlReader

---

## Key Programming Concepts

- TCP Networking
- XML Parsing
- Regular Expressions
- Model-View Programming
- Event-Driven Programming
- Signals and Slots
- Object-Oriented Programming

---

## How to Run

1. Open the project in Qt Creator.
2. Configure a Qt Kit.
3. Build the project.
4. Start the server.
5. Run the Container Management Application.
6. Post XML from the client application to populate the table.
