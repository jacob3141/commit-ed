#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow :
    public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setCommitMessage(QString message);
    QString commitMessage();

public slots:
    void on_textEditSummary_textChanged();
    void on_textEditDescription_textChanged();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
