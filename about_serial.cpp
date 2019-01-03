#include "about_serial.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>
about_serial::about_serial()
{

}

QByteArray about_serial::read_from_arduio()
{
    if (arduino->isReadable())
    {
    data=arduino->readAll();
    return  data;
    }
}

int about_serial::write_to_ardiuino(QByteArray d)
{
    if (arduino->isWritable())
    {
        arduino->write(d);
    }
    else
    {
        qDebug ()<<"couldn't write to serial!";
    }

}
