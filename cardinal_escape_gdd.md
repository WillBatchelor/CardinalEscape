# Cardinal Escape Design Document

## Last Updated: 10/09/2018

## Design Problem Statement: Create an "escape the room" game that satisfies the following criteria:

- The mechanics must engage the player's curiosity
- The mechanics must reward the player's curiosity
- Where game elements are placed within the game space must matter

## Theme: navigating and exploring a strange place 

## Setup
The player wakes up dazed and confused in the dark. He/She feels objects in their pockets. 
Inside his/her pockets are a flashlight and a compas. He/She turns on the flashlight and immediately finds 
the door. He/She runs up to the door and attempts to open the door. *Rattle rattle*...**Locked!** He looked up from the knob and his stomach began to twist. On the door a note read: 

"Good luck navigating out of this one nerd." - K

## Overview
Cardinal Escape is a text-based game in the "escape-the-room" genre. The game utilizes a library commonly
known for being used for the game NetHack: the ncurses library. Unlike most traditional escape game
where players use and combine objects throughout the room to solve puzzles, the player will have to rely
on using visual clues to solve puzzles. For instance, players will have to figure out the order the 
numbers go in a combination based on which wall the numbers are on.

## Mechanics & Elements

### Game Display
The game display will be a rectangle intersected using a vertical partition dividing the rectangle into two
equally sized squares. The left square will be the game space and the right a window to display text. The
game space will be in two dimensions and the asthetics of the game will be reminicent of NetHack. The
player will be represented by an "@" ascii symbol. Other elements in the game space will be represented
by other ASCII characters.

### Movement
The player will move the character avatar around the game space using vi style navigation (hjkl).


### Examining
A player interacts with most (if not all) of the elements of the game by examining them. The player can examine an item/element by moving the player on top of the the square with that element. When the player 
avatar is on the same square of the game space as an element a discription of it is drawn on the window to 
the the right of the game space.

### Key & Lockbox
**The following is an element that may ultimately not be used in the final product:**
A key is the only usable object that can be picked up and used by the player. The key will be obtained at 
the end of the game to unock the door and escape the room. The key will be in a locked strongbox with an 8
digit keypad. The player will need the correct combination to unlock the box.

### Clues
A common element in the escape-the-room genre is the visual clue. Often, these visual cues are used with visual elements to solve puzzles. in Cardinal Escape, the visual cues will support the entire puzzle. Some of the clues will be encoded to add a layer of complexity. For instance, the clues on the wall (and maybe others) will be in binary. In addition to the clues on the wall there will be a clue that will help the player realize the importance of the cardinal directions and how they play into the code combination on the lockbox.

### Computer terminal with binary program.
**The following is an element that may ultimately not be used in the final product:**
There will be a computer in the game that can decode the binary that will show up in the game so the player won't have to break from the experience if they do not have to. Design choices will need to be made to entice the player to use the terminal if at all possible.

## Minimum Viable Product (MVP)
The MVP will consist of the two windows, the avatar that can move around the game space, and an item that
can be examined.