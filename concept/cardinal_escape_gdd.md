# Cardinal Escape Design Document

## Last Updated: 12/05/2018

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

## Basic Mechanics

### Game Display
The game display will be an 80x20 character rectangle intersected using a vertical partition dividing the rectangle into two
equally sized squares. The left square will be the game space or "map" the player will navigate and the
right a window to display a dialog box and the help screen. The game space will be in two dimensions and the asthetics of the game will be reminicent of 
NetHack. The player will be represented by an "@" ascii symbol. Other elements in the game space will be 
represented by other ASCII characters.

### Movement
The player will move the character avatar around the game space using vi style navigation (hjkl).

### Map
The game map consists of "tiles". When the player inputs a navigational key the player "moves" to the
respective tile based on which navigational key is pressed (h causes the player to go to the tile to the left of where the avitar, l to the right and so on). The player avatar can only take up one tile at a time.


### Examining, Picking Up, Using
Other than moving, the player interacts with the game map in one of three ways at a time: examining,
picking up, and using. With any object on the map the player can examine it by moving to the tile the
object is on and it's description will show up on the right screen. 

 The player can examine an item/element by moving the avatar to the tile the item/element is on.  When the player avatar is on the same square of the game space as an element a discription of it is drawn on the window to the the right of the game space.

## Game Elements in the World

- Note
- Terminal
- Briefcase
- Light remote
- Blacklight
- Blacklight hidden messages
- Desk
- File cabinet
- Pickaxe
- Cracks in Floor
- Wads of paper with ones and zeros
- Keypad
- Door with lock


## Minimum Viable Product (MVP)
The MVP will consist of the two windows, the avatar that can move around the game space, and an item that
can be examined.