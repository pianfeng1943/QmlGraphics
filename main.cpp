#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "BGraphics/BGraphicsScene.h"

int main(int argc, char *argv[])
{
#ifdef Q_OS_WIN
    // Select between OpenGL and OpenGL ES (Angle)
    //QCoreApplication::setAttribute(Qt::AA_UseOpenGLES);
    QCoreApplication::setAttribute(Qt::AA_UseDesktopOpenGL);
#endif

    QGuiApplication a(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<BGraphicsScene>("BGraphicsScene", 1, 0, "BGraphicsScene");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return a.exec();
}
