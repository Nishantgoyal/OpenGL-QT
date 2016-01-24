#include "glwidget.h"

GLWidget::GLWidget(const QGLFormat& format, QWidget* parent)
    :QGLWidget(format, parent){

}

GLWidget::~GLWidget() {
}

void GLWidget::initializeGL() {

    //Initialize GLEW
    glewInit();

    programID = LoadShaders(":/vert.glsl", ":/frag.glsl");

    object = new Cube();
    object->init();

    glUseProgram(programID);

}

void GLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, qMax(h, 1));

    Projection = glm::perspective(glm::radians(45.0f), (float)w / (float)h , 0.1f, 100.0f);
    View = glm::lookAt(
                glm::vec3(4, 3, 3),
                glm::vec3(0, 0, 0),
                glm::vec3(0, 1, 0)
                );
    Model = glm::mat4(1.0f);

    mvp = Projection * View * Model;

}

void GLWidget::paintGL() {

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    object->render();
    MatrixID = glGetUniformLocation(programID, "MVP");
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), 0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void *)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void *)(6 * sizeof(GLfloat)));
//    mvp_handle
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);
}
