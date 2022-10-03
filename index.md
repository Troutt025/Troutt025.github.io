# Troutt025.github.io

* * *

## Table of Contents

1. Introduction
2. Self-Assessment
3. Code Review
4. Software Design and Engineering: Exceptions
5. Algorithms and Data Structure: Exceptions
6. Databases: PMTool

* * *

## Introduction

My name is Jesse Troutt. I am an alumni at Southern New Hampshire University as an Honor Roll student.
I am majoring in Computer Science with a concentration in Software Engineering.

This is my portfolio where I have included:
 - A professional self-assessment detailing my work throughout my studies and the enhancements made to my chosen artifacts
 - A code review of my artifacts chosen along with enhancements
 - My Exceptions artifact which covers Software Design and Engineering along with Algorithms and Data Structures
 - My PMTool artifact which is a personal project enhanced to include Databases

Each artifact is chosen to meet the specific criteria of the CS-499 Computer Science Capstone course where I enhance the artifacts to show my skills as a Software Engineer.

* * *

## Self-Assessment

* * *

## Code Review

[Code Review Video](https://youtu.be/udnlpyADtt4)

This is my code review for both artifacts across all categories.
The video covers an overview of what each artifact is meant to accomplish, as well as going through a checklist of review items pertaining to the code.

* * *

## Software Design and Engineering: Exceptions

[Link to enhanced Exceptions code](https://github.com/Troutt025/Troutt025.github.io/blob/main/Exceptions.cpp)

[Link to original Exceptions code as .zip file](https://github.com/Troutt025/Troutt025.github.io/blob/main/Exceptions.zip)

This artifact is called Exceptions. It is intended to showcase the handling of exceptions created by purposely causing overflows, errors, and other exceptions and then handling those exceptions without compromising security and integrity. It was created for class CS-405 in April of 2022.

I specifically chose this artifact as I believe that software security is extremely important and the handling of exceptions is a crucial key to keeping a program secure. This artifact shows that I am capable of comprehending code exceptions and have the ability to write handlers to catch these exceptions in a clean, organized manner. Each function has its own purpose for creating an exception, handling an exception, or performing an algorithm. These functions are also organized in a way that is simple to understand with appropriate comments. I was able to update code comments to be more helpful in understanding functions, I used my standing knowledge of the C++ language to include both limits and a standard namespace. The inclusion of limits allowed me to eliminate possible human error by replacing a variable with a constant. This will also be useful in any future adaptations of this project. The inclusion of the standard namespace allowed me to eliminate unnecessary repetition by removing “std::” from all cout’s, endl’s and the like. I was also able to enhance the error messages produced to give a more helpful reason for the program to exit, as well as include a visible error message that was previously not output during the overflow checking section. 

With the enhancements to this artifact I was able to meet a few of the targeted outcomes. Due to comment changes and error codes I was able to employ strategies for building collaborative environments that enable diverse audiences to support organizational decision making. Along with the changes to limits and namespaces I showed a development of a security mindset that anticipates adversarial exploits in software architecture and designs to expose potential vulnerabilities, mitigate design flaws, and ensure privacy and enhanced security of data and resources. 

I ran into a few challenges when enhancing my project. The first was that after coming back to it after so long, I noticed that I was struggling to remember how it was meant to work. The comments I had originally left were not very helpful, and it seemed that running the program would just exit without any specific reason why. In updating the artifact I changed a few error codes and included an output for one of the errors and I found that it was exiting due to finding an exception. Since the update it is much more clear what is happening while running the program.

* * *

## Algorithms and Data Structure: Exceptions

[Link to enhanced Exceptions code](https://github.com/Troutt025/Troutt025.github.io/blob/main/Exceptions.cpp)

[Link to original Exceptions code as .zip file](https://github.com/Troutt025/Troutt025.github.io/blob/main/Exceptions.zip)

This artifact is the same as artifact one, a program titled Exceptions. It is intended to showcase the handling of exceptions created by purposely causing overflows, errors, and other exceptions and then handling those exceptions without compromising security and integrity. It was created for class CS-405 in April of 2022.

I specifically chose this artifact as each function has specific algorithms such as division, overflow handling, and exception handling. I also improved the artifact by including algorithms for multiplication, user input handling, and underflow handling. In doing so I was able to meet multiple course outcomes. With the inclusion of user input handling I showed a developed security mindset that anticipates adversarial exploits in software architecture and designs to expose potential vulnerabilities, mitigate design flaws, and ensure privacy and enhanced security of data and resources. In the multiplication function and variable input checks I was able to design and evaluate computing solutions that solve a given problem using algorithmic principles and computer science practices and standards appropriate to its solution, while managing the trade-offs involved in design choices. 

I met my course objectives planned with each enhancement, as well as made an extra enhancement I had not initially planned. I was able to include my original algorithms for multiplication while adding algorithms for underflow handling and user input validation. 

In the process of enhancing this artifact I was met with a few challenges, some self-induced. I had to come up with an algorithm for solving the issue of underflow in the multiplication function, as I had overflow handled and had not yet attempted underflow. A simple mistake in checking against the numerical max of a short made it where anytime a negative number was input the program would automatically underflow. I was able to quickly fix this once I realized I should be checking against the numerical minimum instead. I also wanted the user to be able to input whatever number they wished for multiplication and division, which caused its own problems. I know users should not be able to input whatever they want without some kind of validation, so I had to create an algorithm for checking user input to ensure the program's security.

* * *

## Databases: PMTool

[Link to enhanced PMTool code](https://github.com/Troutt025/Troutt025.github.io/tree/main/PMTool)

[Link to original PMTool code as .zip file](https://github.com/Troutt025/Troutt025.github.io/blob/main/PMTool.zip)

This artifact is titled PMTool. It is a tool I created for my current job that is designed to make a backup of a DeltaV system and then copy hotfix files across the network to all DeltaV associated machines. This task was originally all done manually which could take hours to complete. With this tool I have significantly reduced the time necessary to complete the tasks. 

I chose this artifact as it has a database of machines that are used as reference to copy hotfix files out to. Originally, the machines needed to be input manually, which could take a while if the system was large enough. My added enhancements made it possible for the program to automatically grab the machine names and put them in the database itself. Eliminating the need for manual entry. With my enhancements I have demonstrated an ability to use well-founded and innovative techniques in computing practices for the purpose of implementing computer solutions that deliver value and accomplish industry-specific goals. The specific goal being accomplishing a task in a reduced amount of time and effort. I was also able to design, develop, and deliver professional-quality written communications that are coherent, technically sound, and appropriately adapted to specific audiences and contexts with the code comments and README file.

During the enhancement of this artifact I faced a lot of challenges. I have not had a lot of experience writing in batch script, so a lot of research was necessary. Understanding how loops are created and what tools I had available were all relatively new to me. Another challenge was how variables work in batch script, using the variables as well as outputting them to a document was a bit of a challenge that was overcome with a bit of research. I learned a lot about Windows tools available in batch as well as how variables and loops work within it.

* * *


