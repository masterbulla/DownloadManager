#include "downloaderwindow.h"
#include "ui_downloaderwindow.h"
#include <QFileDialog>
#include <QDebug>

DownloaderWindow::DownloaderWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DownloaderWindow)
{
    ui->setupUi(this);
    progress = new QProgressBar(this);
    ui->statusbar->addPermanentWidget(progress);
    manager = new DownloadManager();
    this->setWindowTitle(QString("Download Manager"));
    // Set minimum width of the window
    this->setMinimumWidth(this->contentsRect().width());
    progress->setVisible(false);
    connect(manager,SIGNAL(updateProgress(qint64,qint64)),
            this,SLOT(updateProgressStatus(qint64,qint64)));
    connect(manager,SIGNAL(finished(int,int)),
            this,SLOT(on_finished(int,int)));
}

DownloaderWindow::~DownloaderWindow()
{
    delete ui;
}

void DownloaderWindow::on_downloadButton_clicked()
{
    manager->append(ui->downloadLineEdit->text().trimmed());
    progress->setVisible(true);
    ui->downloadButton->setEnabled(false);
    ui->browseButton->setEnabled(false);
}

void DownloaderWindow::updateProgressStatus(qint64 bytesReceived,qint64 bytesTotal)
{
    progress->setMaximum(bytesTotal);
    progress->setValue(bytesReceived);
}

void DownloaderWindow::on_finished(int downloadedCount, int totalCount)
{
    QString final_string(QString::number(downloadedCount)+"/"+QString::number(totalCount)+" downloaded");
    ui->statusbar->showMessage(final_string);
    progress->setVisible(false);
    ui->downloadButton->setEnabled(true);
    ui->browseButton->setEnabled(true);
}

void DownloaderWindow::on_browseButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);
    qDebug() << dir;
}
