///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//    This file is part of CommitEd.                                         //
//    Copyright (C) 2016 Jacob Dawid <jacob@omg-it.works>                    //
//                                                                           //
//    CommitEd is free software: you can redistribute it and/or modify       //
//    it under the terms of the GNU General Public License as published by   //
//    the Free Software Foundation, either version 3 of the License, or      //
//    (at your option) any later version.                                    //
//                                                                           //
//    CommitEd is distributed in the hope that it will be useful,            //
//    but WITHOUT ANY WARRANTY; without even the implied warranty of         //
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          //
//    GNU General Public License for more details.                           //
//                                                                           //
//    You should have received a copy of the GNU General Public License      //
//    along with CommitEd. If not, see <http://www.gnu.org/licenses/>.       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "highlighter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent, Qt::Window | Qt::WindowStaysOnTopHint),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    new Highlighter(ui->textEditDescription->document());
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
        description.append("\n");
    }
    ui->textEditDescription->setText(description);
}

QString MainWindow::commitMessage() {
    QString summary = ui->textEditSummary->document()->toPlainText().trimmed();
    QString description = ui->textEditDescription->document()->toPlainText().trimmed();

    if(summary.endsWith(".")) summary.chop(1);
    if(!summary.at(0).isUpper()) summary[0] = summary[0].toUpper();

    if(!description.isEmpty()) {
        if(!description.endsWith(".")) description.append(".");
        if(!description.at(0).isUpper()) description[0] = description[0].toUpper();
    }

    return summary + "\n\n"
        + description;
}

void MainWindow::on_textEditSummary_textChanged() {
    ui->progressBarProblem->setValue(ui->textEditSummary->document()->toPlainText().length());
}

void MainWindow::on_textEditDescription_textChanged() {
    ui->progressBarSolution->setValue(ui->textEditDescription->document()->toPlainText().length());
}
