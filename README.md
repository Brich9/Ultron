# Ultron
## A Software Mini Computer Simulation
Ultron is a lowlevel software computer simulation that uses four digit instruction sets to emulate a computer. Ultron is written to take either a .u file which is created by the user to run on our ulton "computer," or it will take in a number to specifiy the number of instructions. These instructions are indicated by a -f or -i flag respectively. 
## Instructions for use:
1. Insure OS is a linux based platform or running an available linux based distribution
2. After cloning repository "make ultron" will compile all necessary files.
### Program.u
#### Usage ./ultron -f program.u
* program.u will simply subtract one from an inputted value from the user, then dump the core and all associated instructions.
### Count.u
#### Usage: ./ultron -f count.u
* count.u will, given an inputted number, count down to zero then dump the core and all associated instructions.

**Project Idea Credit to: Dr. See-Mong Tan @Western Washington University**


