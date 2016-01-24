//#include "widget.h"
#include "glwidget.h"

#include <QApplication>
#include <QtOpenGL/QGLFormat>

QGLFormat setContext() {
    QGLFormat glFormat;
    glFormat.setVersion(3, 3);
    glFormat.setProfile(QGLFormat::CoreProfile);
    glFormat.setSampleBuffers(true);
    return glFormat;

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGLFormat glFormat = setContext();

    GLWidget w(glFormat);
    w.show();

    return a.exec();
}
