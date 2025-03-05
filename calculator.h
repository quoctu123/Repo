#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>

class Calculator : public QObject {
    Q_OBJECT  // 🔹

public:
    explicit Calculator(QObject *parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE double add(double a, double b) { return a + b; }
    Q_INVOKABLE double subtract(double a, double b) { return a - b; }
    Q_INVOKABLE double multiply(double a, double b) { return a * b; }
    Q_INVOKABLE double divide(double a, double b) {
        return (b == 0) ? 0.0 : a / b;
    }
};

#endif // CALCULATOR_H
