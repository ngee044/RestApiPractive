#pragma once

#include <QtWidgets/QMainWindow>

#include "ui_RestApiPractive.h"

class QNetworkAccessManager;
class QNetworkReply;

class RestApiPractive : public QMainWindow
{
    Q_OBJECT

public:
    RestApiPractive(QWidget *parent = Q_NULLPTR);

    void connections();
    
public slots:

private:
    Ui::RestApiPractiveClass ui;

    QNetworkAccessManager* networke_access_manager_;

};
