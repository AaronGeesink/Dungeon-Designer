# Tabletop RPG Dungeon Designer
 > Authors: [Aaron Geesink](https://github.com/roveredpwn), [Garrett Geesink](https://github.com/chatmansave),  [Emerson Jacobson](https://github.com/emwjacobson)

## Project Description

#### General Description:

This program is a terminal based dungeon map generation tool for use in tabletop roleplaying games. The user will have two dungeon generations types to choose from: linear dungeon generation that creates a dungeon map that can only be progressed in one direction, or a nonlinear dungeon generation that creates dungeons with branching paths. Each dungeon generation type will also have two options for both simple and complex generation, for a total of four basic dungeon generation options. The user will also have the ability to change other parameters for the dungeon generation, such as the number of rooms or the size of the dungeon. Once the dungeon map is generated, each room within the dungeon will be populated with encounters such as dungeon loot, traps, or enemies. Once all of the dungeon generation parameters are set, the dungeon map will be displayed in ASCII text to the terminal, and the user will be able to view the generated dungeon layout as well as the encounters within each room of the dungeon. The user will then be able to regenerate the encounters within the generated dungeon map or generate a new dungeon altogether if they want another map.

#### Why it is important:

This project is important for our group because we are all interested in playing tabletop roleplaying games such as Dungeons and Dragons. In these games, the game master overseeing the actions of the game is often tasked with creating game resources for roleplaying fantasy scenarios, including making intricate maps for dungeons that the players will be encountering while playing. Making dungeon maps for Dungeons and Dragons and filling each room in the dungeon with interesting encounters can take a lot of time, so having a way to automate the map generation for dungeons would allow for the game master to focus on the other aspects of game preparation such as creating interesting characters and story. Angular, grid based maps are especially suited for playing in AD&D Second Edition, which is the primary tabletop RPG that two of the project members play.

#### Languages/Tools/Technologies:

[C++](https://www.cplusplus.com/) - This project will be programmed primarily using C++ 11.

[Visual Studio Code](https://code.visualstudio.com/) - This is a text and code editor that we will use to write and test code in Windows.

[Git](https://git-scm.com/) - Git allows us to make changes to the GitHub repository, either through Linux, or through Windows using Git Bash.

[Valgrind](https://valgrind.org/) - Valgrind is a Linux tool which detects errors and memory management bugs in C++ code. We will use it to fix memory leaks in our code.

[Vim](https://www.vim.org/) - Vim is a text editor that allows us to edit code in Linux.

[Github](https://github.com/) - GitHub is a version control system that allows multiple users to share and edit code together online, as well as manage the development of the project with a collection of Agile tools. Github allows for the creation of task boards to sort features into “To-do, doing, done” categories to organize the implementation of program features between multiple group members.

[Visio](https://www.microsoft.com/en-us/microsoft-365/visio/) - Visio is Microsoft’s diagram and flowchart design software. We will use it to make UML class diagrams and other program diagrams for our project.

[CMake](https://cmake.org/) - CMake is a Linux tool which allows us to compile C++ code into executable programs that will run in Linux.

[Google Test Framework](https://github.com/google/googletest) - This is a collection of tools made by Google which will allow us to create and run test cases for our project code. This will allow us to test the functionality and edge cases for our program and ensure that all program inputs have the intended outputs.

#### Program inputs/outputs:

Inputs - The user-specified parameters that will be used to generate a dungeon layout. The user will be able to specify the size of the dungeon map, the types of encounters in the dungeon rooms, the type of dungeon to generate, and the algorithm to generate a dungeon of that type. In addition, once a dungeon has been generated, the user will be able to specify a number of options to modify that dungeon, such as regenerating the encounters, regenerating a dungeon with the same parameters, or changing the parameters of the current dungeon. The user will also have the option to delete the current dungeon and generate a new dungeon with different parameters. If possible, we would like to add the ability for the user to save dungeon layouts that they have generated, and load these dungeon layouts back into the program.

Outputs - The program will use the user-specified parameters to randomly generate a dungeon with those parameters. The objects of a dungeon will be stored within a 2-dimensional data structure such as a vector after it is generated. The program will also visually output the layout of the generated dungeon to the screen using ASCII characters.

#### Program Design Patterns:

The three design patterns we will be using for this project are Abstract Factory, Strategy, and Singleton.

The Abstract Factory design pattern will be used for the Dungeon class to construct different implementations of our dungeon. A dungeon will be generated based on a collection of user-specified parameters, and the behavior of the dungeon generation algorithm will be determined at runtime based on these parameters. A dungeon can differ by a number of parameters, such as size, number of rooms, number of encounters and types of encounters, as well as different types of dungeons and dungeon generation algorithms. By using the Abstract Factory design pattern, we will not have to determine the behavior of the dungeon generation ahead of time, and instead build the behavior at runtime from the user-provided parameters. Aaron Geesink will be responsible for this design pattern.

The Strategy design pattern will be used for the dungeon generation algorithms to choose between different algorithms to generate the dungeons. Each of the types of dungeon layouts will have more than one algorithm to generate dungeons of that type. For example, we can specify a linear dungeon, with rooms that extend in a straight line, and we can develop multiple algorithms for generating linear dungeons. A simple linear dungeon algorithm would generate a simple dungeon with one straight path through each of its rooms, while a complex linear dungeon algorithm would generate a straight dungeon with branching paths between its rooms. This applies to other dungeon types as well. A non-linear dungeon will have a simple algorithm and a complex algorithm that will allow for the ability to create different dungeons of the same type. Jacob Emerson will be responsible for this design pattern.

The Singleton design pattern will be used for the Dungeon class, as we only want to create one dungeon at any given moment. We will be able to modify that dungeon in order to produce different dungeon layouts using the same dungeon object. For example, we will have the option to regenerate the contents of each of the dungeon rooms, or generate a new dungeon using the same parameters. Singleton is useful in this case because it allows us to keep using a dungeon layout until the user decides to generate an entirely new dungeon with different parameters. Garrett Geesink will be responsible for this design pattern.

Here is a rough prototype picture for the design of the dungeons:

 ![Design Prototype Image](https://github.com/cs100/final-project-agees001-ggees001-ejaco020/blob/master/DesignDocs/PrototypeDesign.png)

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
