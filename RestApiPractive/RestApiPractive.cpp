#include <QNetworkAccessManager>
#include <qnetworkreply.h>
#include "RestApiPractive.h"

RestApiPractive::RestApiPractive(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    networke_access_manager_ = new QNetworkAccessManager(this);
    
    connections();
}

void RestApiPractive::connections()
{
    connect(ui.pushButton_get_, &QPushButton::clicked, this, [=]() {
        networke_access_manager_->get(QNetworkRequest(QUrl(ui.lineEdit_url_->text())));
        });

    connect(networke_access_manager_, &QNetworkAccessManager::finished, this, [&](QNetworkReply* reply) {
        QByteArray data = reply->readAll();
        QString str = QString::fromLatin1(data);
        ui.plainTextEdit->clear();
        ui.plainTextEdit->setPlainText(str);
        });
}
