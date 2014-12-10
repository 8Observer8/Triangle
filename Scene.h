#ifndef SCENE_H
#define SCENE_H

#include <QGLWidget>
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>

class Scene : public QGLWidget, public QOpenGLFunctions
{
public:
    Scene( QWidget *parent = 0 );

    void initializeGL();
    void paintGL();
    void resizeGL( int w, int h );

private:
    GLuint m_posAttr;
    GLuint m_colAttr;
    GLuint m_matrixUniform;

    QOpenGLShaderProgram *m_program;
};

#endif // SCENE_H
