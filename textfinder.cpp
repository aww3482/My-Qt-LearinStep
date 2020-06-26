#include "textfinder.h"
#include "ui_textfinder.h"
#include <QFile>
#include <QTextStream>
#include "windows.h"
#include <QThread>

bool bFlag = true;
QThread workThread;
TextFinder::TextFinder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TextFinder)
{
    ui->setupUi(this);
    connect(ui->btnStart, SIGNAL(clicked()), this, SLOT(OnStartClicked()));
    connect(ui->btnStop,  SIGNAL(clicked()), this, SLOT(OnStopClicked()));
    LoadTextFile();
    workThread.start(QThread::IdlePriority);
}

TextFinder::~TextFinder()
{
    delete ui;
}

void TextFinder::on_findButton_clicked()
{
    QString strSearch = ui->lineEdit->text();
    ui->textEdit->find(strSearch, QTextDocument::FindWholeWords);
}

void TextFinder::OnStartClicked()
{
    ui->label_2->setText("开始了");
//    ui->LcdCount1->setDigitCount(5);
    int i = 9;
    while (bFlag)
    {
        i++;
        ui->LcdCount1->display(i);
        Sleep(1);

    }
}

void TextFinder::OnStopClicked()
{
    bFlag = false;
    ui->label_2->setText("计数");
}

void TextFinder::LoadTextFile()
{
    QFile qfInputFile(":/input.txt");
    qfInputFile.open(QIODevice::ReadOnly);

    QTextStream in(&qfInputFile);
    QString qstrLine = in.readAll();
    qfInputFile.close();

    ui->textEdit->setPlainText(qstrLine);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);


}
