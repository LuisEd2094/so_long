# so_long
So Long Project from 42 School

It's a basic 2d game where you collect all the objects and reach the exit.

It uses the School mlx lib to handle all the display on the screen, but I have to provide with all the game logic and handle the loading of the sprites.

The game is over as soon as you collect all Collectables and reach the exit, 

There will be a move counter being printed on the terminal, try to get the lowest score possible!

Usage:

Run Make and then ./so_long <.ber file with the map> from the terminal

I provide with some .ber files but you can try a few for yourself.

A valid .ber file looks something like:

1111111111111
11010C00000C1
1000100000001
1CP000E0000C1
1111111111111

1 = Obstacle
0 = Free Space
P = Player
E = Exit
C = Collectables

It has a to be a full square, it should only the characters listed above, only 1 Player, 1 Exit and atleast 1 Collectable. Borders should be made of
obstacles (1s) and it should be finishable as the player can only move horizontally and vertically.

An example of an invalid map:

1111111111111
10010000001C1
1000011111101
1P0011E000001
1111111111111

As you can see, the player is on the left side and the collectable and exit are on the right side, with no way for the player to get there following the 
move restrictions, as such the program will display an error.
