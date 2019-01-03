#ifndef ABOUT_SERIAL_H
#define ABOUT_SERIAL_H
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>

class about_serial
{
public:
    about_serial();
    int write_to_ardiuino(QByteArray);
    QByteArray read_from_arduio();
private:
    QSerialPort *arduino;
    QByteArray data;

};

#endif // ABOUT_SERIAL_H
