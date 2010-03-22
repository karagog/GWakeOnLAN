/*Copyright 2010 George Karagoulis

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.*/

#include "about_window.h"
#include "ui_about_window.h"

about_window::about_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about_window)
{
    ui->setupUi(this);

    setFixedSize(size());
}

about_window::~about_window()
{
    delete ui;
}

void about_window::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void about_window::about_qt()
{
    QApplication::aboutQt();
}
