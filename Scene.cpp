#include <QDebug>
#include <QMatrix4x4>
#include "Scene.h"

Scene::Scene( QWidget *parent ) :
    QGLWidget( parent ),
    m_program( 0 )
{
}

void Scene::initializeGL()
{
    initializeOpenGLFunctions();
    m_program = new QOpenGLShaderProgram( this );
    m_program->addShaderFromSourceFile( QOpenGLShader::Vertex, ":/Shaders/vShader.glsl" );
    m_program->addShaderFromSourceFile( QOpenGLShader::Fragment, ":/Shaders/fShader.glsl" );
    if ( !m_program->link() )
    {
        qWarning( "Error: unable to link a shader program" );
        return;
    }
    m_posAttr = m_program->attributeLocation( "posAttr" );
    m_colAttr = m_program->attributeLocation( "colAttr" );
    m_matrixUniform = m_program->uniformLocation( "matrix" );
}

void Scene::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT );

    if ( !m_program->bind() )
        return;

    QMatrix4x4 matrix;
    matrix.perspective( 60.0f, 4.0f/3.0f, 0.1f, 100.0f );
    matrix.translate( 0.0f, 0.0f, -2.0f );

    m_program->setUniformValue( m_matrixUniform, matrix );

    GLfloat vertices[] =
    {
        0.0f, 0.5f,
        -0.5f, -0.5f,
        0.5f, -0.5f
    };

    GLfloat colors[] =
    {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f
    };

    glVertexAttribPointer( m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, vertices );
    glVertexAttribPointer( m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors );

    glEnableVertexAttribArray( 0 );
    glEnableVertexAttribArray( 1 );

    glDrawArrays( GL_TRIANGLES, 0, 3 );

    glDisableVertexAttribArray( 1 );
    glDisableVertexAttribArray( 0 );

    m_program->release();
}

void Scene::resizeGL( int w, int h )
{
    glViewport( 0, 0, w, h );
}
