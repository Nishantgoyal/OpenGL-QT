#ifndef GLWIDGET_H
#define GLWIDGET_H

#include "glheaders.h"
#include "cube.h"

class Cube;

GLuint LoadShaders( const QString& vertexShaderPath,
                    const QString& fragmentShaderPath );
class GLWidget :public QGLWidget
{
    Q_OBJECT
public:
    GLWidget(const QGLFormat& format, QWidget* parent = 0);
    ~GLWidget();

protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();

private:
    Cube *object;

    glm::mat4 Projection;
    glm::mat4 View;
    glm::mat4 Model;
    glm::mat4 mvp;

//    GLuint mvp_handle;
    GLuint programID;
    GLuint MatrixID;
};

#endif // GLWIDGET_H
