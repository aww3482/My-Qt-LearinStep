#ifndef TEXTFINDER_H
#define TEXTFINDER_H

#include <QWidget>

namespace Ui {
class TextFinder;
}

class TextFinder : public QWidget
{
    Q_OBJECT

public:
    explicit TextFinder(QWidget *parent = 0);
    ~TextFinder();

private slots:
    void on_findButton_clicked();
    void OnStartClicked();
    void OnStopClicked();
private:
    Ui::TextFinder *ui;
    void LoadTextFile();
};

#endif // TEXTFINDER_H
