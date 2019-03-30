# fdf

First graphical project at 19codingschool (www.s19.be)

# Goal

Fdf (fil de fer) is the first graphical project at my school.

It is fairly simple, you have to read a file containing some points height (and optionally colors)(the points x and y are it's position in the file)
and make a graphical representation by connecting the dots basically.

# How did I do it?

First step is to parse the file:

 I read the file line by line splitting those on every space caracter, each of these strings will be a point, I also validate that the map is a rectangle, meaning that every line has to contain the same amount of point
 
Once the file is correctly parsed I use offsets to process a screenspace coordinate for these points so that the middle of the screen is the middle of my map.

Every point will be processed for every frame, movement and viewing angle will be adjusted using a point rotation algorithm

Once every point has been preprocessed, lines will be drawn using a DDA algorithm and some linear interpolation to calculate the required colors

# Usage

- Compile the project using the make command (may only work on macos)
- Use the executable like so ./fdf map_file
A new window should pop up if the file is valid

# Controls

- Left click:
 - On map (hold): Changes the rotation angle of the map
 - On the color selector: Changes the low color value

- Right click:
 - On map (hold): Moves the whole map
 - On the color selector: Changes the high color value
 
- M: Removes the menu

- 1: Default rendering
- 2: Do not connect points
- 3: POV rendering (unfinished) gives an impression of depth

(Bonus if you click on my face it'll 'corrupt' the map)
