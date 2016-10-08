#ifndef DOWNLOADMANAGER_H
#define DOWNLOADMANAGER_H

#include <QObject>

#include <QFile>
#include <QObject>
#include <QQueue>
#include <QTime>
#include <QUrl>
#include <QNetworkAccessManager>

#include "textprogressbar.h"

class DownloadManager : public QObject
{
    Q_OBJECT
public:
    explicit DownloadManager(QObject *parent = 0);

    void append(const QUrl &url);
    void append(const QStringList &urlList);
    QString saveFileName(const QUrl &url);

signals:
    void finished();

private slots:
    void startNextDownload();
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void downloadFinished();
    void downloadReadyRead();

private:
    QNetworkAccessManager manager;
    QQueue<QUrl> downloadQueue;
    QNetworkReply *currentDownload;
    QFile output;
    QTime downloadTime;
    TextProgressBar progressBar;

    int downloadedCount;
    int totalCount;
};

#endif // DOWNLOADMANAGER_H
