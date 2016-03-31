Author: Baichuan Zhang

Task Description:

Implemented red black tree and augmented interval tree data structure to efficiently find existence of an overlap among a large collection of rectangles in O(n*lgn) time complexity. This project has wide application in Very-Large-Scale Integration (VLSI) domain. I did this work as my programming project in graduate level Algorithm class. Please refer to project.pdf file for detailed description of project.

Description of how to run the code:

Since I have created the makefile, you simply type "make" to generate the executable file named “overlappingRect.out”. 
And then type "./overlappingRect.out inputfilename" to get result.

output: if given input file no overlap, simply print out "no overlap". If given input file exsits overlapping rectangle, print out p q overlap, where p and q are ids
of overlapping rectangle, and p < q.

In the code, I created four classes. Treenode for representing node in the interval tree; IntervalTree for representing IntervalTree data structure; Point for representing x and y coordinates of points in the rectangle; Edge for representing the two edges of rectangle which are parallel to y axis.

Running example:

./overlappingRect.out dataset/bigdataset_nonoverlap.txt

If you have any questions, please contact:

Baichuan Zhang
Email: bz3@umail.iu.edu
