#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QObject>

class Calculator : public QObject {
    Q_OBJECT
public:
    explicit Calculator(QObject *parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE double add(double a, double b) { return a + b; }
    Q_INVOKABLE double subtract(double a, double b) { return a - b; }
    Q_INVOKABLE double multiply(double a, double b) { return a * b; }
    Q_INVOKABLE double divide(double a, double b) {
        if (b != 0)
            return a / b;
        return 0; // Hoặc có thể xử lý lỗi chia cho 0
    }
};
int main(int argc, char *argv[])
{

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    Calculator calculator;
    engine.rootContext()->setContextProperty("calculator", &calculator);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
