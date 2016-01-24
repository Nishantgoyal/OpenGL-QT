#-------------------------------------------------
#
# Project created by QtCreator 2016-01-13T11:51:28
#
#-------------------------------------------------

QT       += core gui
QT += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Program1
TEMPLATE = app


SOURCES += main.cpp\
    glwidget.cpp \
    loadshaders.cpp \
    cube.cpp \

HEADERS  += \
    glwidget.h \
    glheaders.h \
    cube.h \

FORMS    += widget.ui

DISTFILES +=

RESOURCES += \
    resources.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../../lib64/release/ -lGLEW
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../../lib64/debug/ -lGLEW
else:unix: LIBS += -L$$PWD/../../../../../../../../lib64/ -lGLEW

INCLUDEPATH += $$PWD/../../../../../../../../lib64
DEPENDPATH += $$PWD/../../../../../../../../lib64

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../../../lib64/release/libGLEW.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../../../lib64/debug/libGLEW.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../../../lib64/release/GLEW.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../../../lib64/debug/GLEW.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../../../../../lib64/libGLEW.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../../usr/lib64/release/ -lGLU
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../../usr/lib64/debug/ -lGLU
else:unix: LIBS += -L$$PWD/../../../../../../../../usr/lib64/ -lGLU

INCLUDEPATH += $$PWD/../../../../../../../../usr/lib64
DEPENDPATH += $$PWD/../../../../../../../../usr/lib64
