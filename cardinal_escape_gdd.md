# Cardinal Escape Design Document

## Last Updated: 10/09/2018

## Design Problem Statement: Create an "escape the room" game involving cardinal directions.

## Theme: navigating and exploring a strange place using a compas

## Setup
The player wakes up dazed and confused in the dark. He/She feels objects in their pockets. 
Inside his/her pockets are a flashlight and a compas. He/She turns on the flashlight and immediately finds 
the door. He/She runs up to the door and attempts to open the door. *Rattle rattle*...**Locked!** He looked up from the knob and his stomach began to twist. On the door a note read: 

"Good luck navigating out of this one nerd." - K

## Overview
Cardinal Escape is a text-based game in the "escape-the-room" genre. The game utilizes a library commonly known for being used for the game NetHack: the ncurses library. Unlike most traditional escape games where players use and combine objects throughout the room to solve puzzles, the player will have to rely on using visual clues to solve puzzles. For instance, players will have to figure out the order the numbers go in a combination based on which wall the numbers are on.

## Mechanics & Elements

### Movement & Compas
Movement will be dictated by typed commands. To fit the orienteering theme the commands will dictate which cardinal direction the player will face next. The compas is designed to let the character know which direction faces which cardinal direction. If the player is facing the north wall and wants to face the East wall they will type in east.

### Examining & Flashlight
Once the player orients to a wall the game will do either of the following depending on design direction:

- describe what is on the wall and will ask the player to choose what they want to examine
- use the ascii graphical capabilities of ncurses to display important information but give the player the option to choose what they can focus on with the flashlight

### Key & Lockbox
A key is the only usable object that can be picked up and used by the player. The key will be obtained at the end of the game to unock the door and escape the room. The key will be in a locked strongbox with an 8 digit keypad. The player will need the correct combination to unlock the box.

### Clues
A common element in the escape-the-room genre is the visual clue. Often, these visual cues are used with visual elements to solve puzzles. in Cardinal Escape, the visual cues will support the entire puzzle.

## Walkthrough

The player will start the game facing north. 