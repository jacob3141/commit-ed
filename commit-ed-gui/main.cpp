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
