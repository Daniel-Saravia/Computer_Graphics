// Conditional compilation for cross-platform compatibility
#ifdef __APPLE_CC__
#include <GLUT/glut.h> // Include the GLUT library for macOS
#else
#include <GL/glut.h>   // Include the GLUT library for other systems
#endif
#include <cstdlib>     // Include the standard library for general utilities

// Global variables to manage rotation
GLfloat rotationX = 0.0f; // Rotation angle around the X-axis
GLfloat rotationY = 0.0f; // Rotation angle around the Y-axis
bool rotate = false;      // Flag to control rotation

// Point struct represents a point in 3D space
struct Point {
  GLfloat x, y, z; // Coordinates of the point
  Point(GLfloat x, GLfloat y, GLfloat z): x(x), y(y), z(z) {} // Constructor
  Point midpoint(Point p) {return Point((x+p.x)/2, (y+p.y)/2, (z+p.z)/2);} // Calculate midpoint
};

// Function prototype declaration
void generateMorePoints();

// Reshape callback function
void reshape(GLint w, GLint h) {
  glViewport(0, 0, w, h); // Set the viewport to cover the new window size
  glMatrixMode(GL_PROJECTION); // Switch to projection matrix
  glLoadIdentity(); // Reset the projection matrix
  gluPerspective(100.0, GLfloat(w)/GLfloat(h), 10.0, 1500.0); // Set perspective projection
}

// Display callback function
void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0.0, 0.0, 500.0, 0.0, 0.0, -500.0, 0.0, 1.0, 0.0);
  // Apply rotation if enabled
  if (rotate) {
      glRotatef(rotationX, 1.0, 0.0, 0.0);
      glRotatef(rotationY, 0.0, 1.0, 0.0);
  }

  generateMorePoints();
  glFlush();
}
// Function to generate points for the Sierpinski Tetrahedron
void generateMorePoints() {
// Define the vertices of tetrahedron the
  static Point vertices[4] = {
    Point(-250, -225, -200),
    Point(-150, -225, -700),
    Point(250, -225, -275),
    Point(0, 450, -500)
  };
  static Point lastPoint = vertices[0];
  // Begin plotting points
  glBegin(GL_POINTS);
  for (int i = 0; i <= 500; i++) {
    // Compute the next point as a midpoint to a randomly chosen vertex
    lastPoint = lastPoint.midpoint(vertices[rand() % 4]);
    // Compute the color intensity based on the z-coordinate
    GLfloat intensity = (700 + lastPoint.z) / 500.0;
    glColor3f(intensity, intensity, 0.25);
    glVertex3f(lastPoint.x, lastPoint.y, lastPoint.z);
  }
  glEnd(); // End plotting points
}
// Mouse motion callback function 
void mouseMotion(int x, int y) {
  // Update rotation angles based on mouse position
  rotationX += (y - 250) * 0.1f;
  rotationY += (x - 250) * 0.1f;
  glutPostRedisplay(); // Request to update the display
}
// Mouse entry/exit callback function
void mouseEnter(int state) {
  // Enable or disable rotation based on mouse entry/exit
  if (state == GLUT_ENTERED) {
    rotate = true;
  } else if (state == GLUT_LEFT) {
    rotate = false;
  }
}
// Initialization function
void init() {
  glEnable(GL_DEPTH_TEST); // Enable depth testing for 3D rendering
}

int main(int argc, char** argv) {
  glutInit(&argc, argv); // Initialize GLUT
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // Set display mode
  glutInitWindowSize(500, 500); // Set initial window size
  glutInitWindowPosition(0, 0); // Set initial window position
  glutCreateWindow("Sierpinski Tetrahedron"); // Create window with title

  // Register callback functions
  glutDisplayFunc(display); // Display callback
  glutReshapeFunc(reshape); // Window reshape callback
  glutIdleFunc(generateMorePoints); // Idle callback for continuous rendering
  glutMotionFunc(mouseMotion); // Mouse motion callback
  glutEntryFunc(mouseEnter); // Mouse entry/exit callback

  init(); // Perform initialization

  glutMainLoop(); // Enter GLUT event processing loop
  return 0; // Standard return for main function
}


