#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Button'a bir click event handler bağlayın.
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    // QBluetoothDeviceDiscoveryAgent nesnesi oluşturun.
    QBluetoothDeviceDiscoveryAgent *discoveryAgent = new QBluetoothDeviceDiscoveryAgent();

    // Bir QListWidget nesnesi oluşturun.


    // DiscoveryAgent'ın devicesFound() sinyalini bağlayın.
    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            [&](const QBluetoothDeviceInfo &devices) {
                // Bulunan her cihaz için, adını QListWidget nesnesine ekleyin.
                    ui->listWidget->addItem(devices.name());

            });

    // DiscoveryAgent'ın start() işlevini çağırarak cihaz taramasını başlatın.
    discoveryAgent->start();

    // Ana döngüde bekleyin.
    while (true) {
        QCoreApplication::processEvents();
    }

    // DiscoveryAgent'ın stop() işlevini çağırarak cihaz taramasını durdurun.
    discoveryAgent->stop();
}

void MainWindow::on_pushButton_2_clicked()
{
    // Seçili öğeyi alın.

    auto currentItem =  ui->listWidget->currentItem();
    // Seçili öğenin metnini alın.
    QString text = currentItem->text();
    ui->pushButton_2->setText("Connect to "+ text);
}

