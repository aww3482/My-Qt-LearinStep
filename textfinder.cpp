#include "textfinder.h"
#include "ui_textfinder.h"
#include <QFile>
#include <QTextStream>

TextFinder::TextFinder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TextFinder)
{
    ui->setupUi(this);
    LoadTextFile();
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
