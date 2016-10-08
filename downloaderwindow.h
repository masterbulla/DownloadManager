#ifndef DOWNLOADERWINDOW_H
#define DOWNLOADERWINDOW_H

#include <QMainWindow>
#include "downloadmanager.h"

namespace Ui {
class DownloaderWindow;
}

class DownloaderWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DownloaderWindow(QWidget *parent = 0);
    ~DownloaderWindow();

private slots:
    void on_downloadButton_clicked();
    void on_finished(int,int);
    void updateProgressStatus(qint64,qint64);

private:
    Ui::DownloaderWindow *ui;
    DownloadManager *manager;
};

#endif // DOWNLOADERWINDOW_H
