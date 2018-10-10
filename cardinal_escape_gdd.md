# Cardinal Escape Design Document

## Last Updated: 10/09/2018

## Design Problem Statement: Create an "escape the room" game involving cardinal directions.

## Setup
The player wakes up dazed and confused in the dark. He/She feels objects in their pockets. 
Inside his/her pockets are a flashlight and a compas. He/She turns on the flashlight and immediately finds 
the door. He/She runs up to the door and attempts to open the door. *Rattle rattle*...**Locked!** He looked up from the knob and his stomach began to twist. On the door a note read: 

"Good luck navigating out of this one nerd." - K

## Overview
Cardinal Escape is a text-based game in the "escape-the-room" genre. The game utilizes a library commonly known for being used for the game NetHack: the ncurses library. Unlike most traditional escape games where players use and combine objects throughout the room to solve puzzles, the player will have to rely on using visual clues to solve puzzles. For instance, players will have to figure out the order the numbers go in a combination based on which wall the numbers are on. 