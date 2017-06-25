SvgParser 


What is it about ? 

The application helps you easily to maintain, create, edit, translate and erase svg shapes and then save them again in a valid svg1.1 format.

Supported shapes and properties:
	rect x, y, width, height, fill
	circle cx, cy, r, fill 
	line x1, x2, y1, y2, stroke

How to use it: 
	compile it with g++ 
	then you can open an svg file and the application will 	read the shapes for you, or can start crating new one 	with the create operation. 

Operations:
	open - expects valid svg file, opens the file reads the shapes 
	create - creates new shape, expect the name of the shape and then all of it supported properties in the indicated above way
	save - saves the current shapes in a corect svg format.
	print - prints to the console the currect shapes
	erase - expects the index of the shape to be removed
	exit - exits the application 
 