#ifndef CUBE_H
#define CUBE_H

#include "glheaders.h"

struct VertexData
{
    GLfloat x, y, z;
    GLfloat nx, ny, nz;
    GLfloat r, g, b;

    void SetPosition(GLfloat _x, GLfloat _y, GLfloat _z)
    {
        x = _x; y = _y; z = _z;
    }
    void SetColor(GLfloat _r, GLfloat _g, GLfloat _b)
    {
        r = _r; g = _g; b = _b;
    }
    void SetNormals(GLfloat _nx, GLfloat _ny, GLfloat _nz)
    {
        nx = _nx; ny = _ny; nz = _nz;
    }
};

class Cube {
public:
    Cube();

    void render();
    void initialiseGeometry();
    void init();

protected:
    VertexData center;
    GLfloat height;
    GLfloat width;
    GLfloat depth;
    GLuint VertexCount;
    GLuint IndicesCount;
    VertexData verts[24];
    GLuint VertexArrayID;   //here
    GLuint vboId[2];
};

#endif // CUBE_H
