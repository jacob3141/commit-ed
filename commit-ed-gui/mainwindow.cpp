#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent, Qt::Window | Qt::WindowStaysOnTopHint),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setCommitMessage(QString message) {
    QStringList lines = message.split('\n');
    ui->textEditSummary->document()->setPlainText(lines.first());

    QString description;
    for(int i = 1; i < lines.count(); i++) {
        description.append(lines.at(i));
    }
    ui->textEditDescription->setText(description);
}

QString MainWindow::commitMessage() {
    QString summary = ui->textEditSummary->document()->toPlainText().trimmed();
    QString description = ui->textEditDescription->document()->toPlainText().trimmed();

    if(summary.endsWith(".")) summary.chop(1);
    if(!description.endsWith(".")) description.append(".");
    if(!summary.at(0).isUpper()) summary[0] = summary[0].toUpper();
    if(!description.at(0).isUpper()) description[0] = description[0].toUpper();

    return summary + "\n\n"
        + description;
}

void MainWindow::on_textEditSummary_textChanged() {
    ui->progressBarProblem->setValue(ui->textEditSummary->document()->toPlainText().length());
}

void MainWindow::on_textEditDescription_textChanged() {
    ui->progressBarSolution->setValue(ui->textEditDescription->document()->toPlainText().length());
}
