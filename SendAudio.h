#include <QCoreApplication>
#include <QAudioInput>
#include <QBluetoothSocket>

class SendAudio
{
    void doSomething()
    {
        QAudioFormat format;
        format.setSampleRate(16000);
        format.setChannelCount(1);
        format.setSampleSize(16);
        format.setCodec("audio/pcm");
        format.setByteOrder(QAudioFormat::LittleEndian);
        format.setSampleType(QAudioFormat::SignedInt);

        QAudioInput* audioInput = new QAudioInput(format);
        QIODevice* audioDevice  = audioInput->start();

        // Bluetooth cihazının MAC adresini aşağıdaki şekilde değiştirin
        QString deviceAddress = "00:00:00:00:00:00";

        QBluetoothSocket socket(QBluetoothServiceInfo::RfcommProtocol);
        socket.connectToService(QBluetoothAddress(deviceAddress), QBluetoothUuid(QBluetoothUuid::SerialPort));
        socket.waitForConnected();

        // Ses verisini oku ve Bluetooth cihazına gönder
        qint64 bytesWritten = socket.write(audioDevice->readAll());

        if (bytesWritten == -1)
        {
            qDebug() << "Hata: Ses verisi gönderilemedi.";
        }
        else
        {
            qDebug() << "Başarıyla ses gönderildi.";
        }

        // Bağlantıyı kapat
        socket.close();
        audioInput->stop();
    }
}
