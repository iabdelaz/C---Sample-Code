C---Sample-Code
===============
The program reads the specified input file (data.txt) then, based on the first two digits, 
allocates the number of vertices and weighted edges of the graph contained in the file. The 
program then initializes a number of disjoint sets equal to the number of vertices and a 
min-heap containing all edge weights. By inserting each edge one at a time, the program will 
calculate the min-heap structure and perform the disjoint set opperations. Finally, the program 
computes a minnimum spanning tree using Kruskal's algorithm and prints the set structure, heap 
structure, and minnimum spanning tree to a new file (output.txt).  
