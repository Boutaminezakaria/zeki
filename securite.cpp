#include "securite.h"
#include "ui_securite.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <string>
#include <QDebug>
#include <QMessageBox>


Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    arduino = new QSerialPort(this);
    serialBuffer = "";
    parsed_data = "";
    temperature_value = 0.0;


    bool arduino_is_available = false;
    QString arduino_uno_port_name;
    //
    //  For each available serial port
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        //  check if the serialport has both a product identifier and a vendor identifier
        if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
            //  check if the product ID and the vendor ID match those of the arduino uno
            if((serialPortInfo.productIdentifier() == arduino_uno_product_id)
                    && (serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id)){
                arduino_is_available = true; //    arduino uno is available on this port
                arduino_uno_port_name = serialPortInfo.portName();
            }
        }
    }

    /*
     *  Open and configure the arduino port if available
     */
    if(arduino_is_available){
        qDebug() << "Found the arduino port...\n";
        arduino->setPortName(arduino_uno_port_name);
        arduino->open(QSerialPort::ReadOnly);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
    }else{
        qDebug() << "Couldn't find the correct port for the arduino.\n";
        QMessageBox::information(this, "Serial Port Error", "Couldn't open serial port to arduino.");
    }
}

Dialog2::~Dialog2()
{
    if(arduino->isOpen()){
        arduino->close(); //    Close the serial port if it's open.
    }
    delete ui;
}

void Dialog2::readSerial()

    {

         //qDebug() << serialBuffer ;

            QStringList Buffersplit = serialBuffer.split(",");

             if(Buffersplit.length() < 3){
                 serialData = arduino->readAll();
                 serialBuffer += QString::fromStdString(serialData.toStdString());
             }else{
                 qDebug() << Buffersplit;
                 Dialog2::updateTemperature(Buffersplit[1]);
                 serialBuffer ="";
             }






    }


void Dialog2::updateTemperature(QString sensor_reading)
{
    QString ch,chh;
    int f,g,au;
    au=sensor_reading.toInt();
    f=au%10;
    g=au/10;



    if(g>250)
    {
        ch="FUITE DE GAZ";

    }
    else{
         ch="pas de fuite";


    }

     ui->text->setText(ch);

      if(f==1)
      {
          chh="pas de flame";

      }
          else{
              chh="flame";
          }

   ui->textt->setText(chh);

      }

