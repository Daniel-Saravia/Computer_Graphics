README for the Computer Graphics Repository
Repository Overview
The Computer Graphics repository by Daniel Saravia focuses on generating Sierpinski patterns, both in 2D and 3D, using OpenGL and GLUT. It contains three main C++ files, each implementing a different variation of the Sierpinski pattern.

Getting Started
To get started with this repository, first clone it to your local machine using the following command:

bash
Copy code
git clone https://github.com/Daniel-Saravia/Computer_Graphics
Navigate to the cloned directory to access the files.

Files in the Repository
Sierpinski2D.cpp: Generates a 2D Sierpinski gasket.
Sierpinski3D.cpp: Plots a 3D Sierpinski Tetrahedron.
Sierpinski3DMOVE.cpp: An interactive 3D Sierpinski Tetrahedron with rotation features.
How to Compile and Run
Ensure you have OpenGL and GLUT installed on your system. Use the following commands to compile and run the programs:

Sierpinski2D.cpp:
bash
Copy code
g++ Sierpinski2D.cpp -o Sierpinski2D -lglut -lGLU -lGL
./Sierpinski2D
Sierpinski3D.cpp:
bash
Copy code
g++ Sierpinski3D.cpp -o Sierpinski3D -lglut -lGLU -lGL
./Sierpinski3D
Sierpinski3DMOVE.cpp:
bash
Copy code
g++ Sierpinski3DMOVE.cpp -o MOVE -lglut -lGLU -lGL
./MOVE
Dependencies
OpenGL
GLUT
Contributing
Contributions to the repository are welcome. Please ensure that any pull requests or issues are relevant to the project's scope, which is primarily focused on computer graphics using OpenGL and GLUT.
