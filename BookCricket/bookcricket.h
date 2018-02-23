#ifndef BOOKCRICKET_H
#define BOOKCRICKET_H

#include <QMainWindow>

namespace Ui {
class BookCricket;
}

class BookCricket : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit BookCricket(QWidget *parent = 0);
    ~BookCricket();
    
private slots:
    void on_pushButton_clicked();
    void playBookCricket(int, QString);
    void on_action_About_BookCricket_triggered();

    void on_actionE_xit_triggered();

private:
    Ui::BookCricket *ui;
};

#endif // BOOKCRICKET_H
