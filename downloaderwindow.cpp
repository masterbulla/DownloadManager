#include "downloaderwindow.h"
#include "ui_downloaderwindow.h"
#include <QDebug>

DownloaderWindow::DownloaderWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DownloaderWindow)
{
    ui->setupUi(this);
    manager = new DownloadManager();
    this->setWindowTitle(QString("Download Manager"));
    // Set minimum width of the window
    this->setMinimumWidth(this->contentsRect().width());
    connect(manager,SIGNAL(updateProgress(qint64,qint64)),this,SLOT(updateProgressStatus(qint64,qint64)));
    connect(manager,SIGNAL(finished(int,int)),this,SLOT(on_finished(int,int)));
}

DownloaderWindow::~DownloaderWindow()
{
    delete ui;
}

void DownloaderWindow::on_downloadButton_clicked()
{
    manager->append(ui->downloadLineEdit->text().trimmed());
}

void DownloaderWindow::updateProgressStatus(qint64 bytesReceived,qint64 bytesTotal)
{
    QString progress(QString::number(bytesReceived)+"/"+QString::number(bytesTotal));
    qDebug() << progress;
    ui->statusbar->showMessage(progress);
}

void DownloaderWindow::on_finished(int downloadedCount, int totalCount)
{
    QString final_string(QString::number(downloadedCount)+"/"+QString::number(totalCount)+" downloaded");
    ui->statusbar->showMessage(final_string);
}
