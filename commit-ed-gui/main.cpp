#include "mainwindow.h"
#include <QApplication>

#include <QFile>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QFile file(argv[1]);
    file.open(QFile::ReadWrite);
    if(file.isOpen()) {
        MainWindow w;
        w.setCommitMessage(QString::fromUtf8(file.readAll()));
        w.show();
        a.exec();

        file.write(w.commitMessage().toUtf8());
        file.close();
    }
    return 0;
}
