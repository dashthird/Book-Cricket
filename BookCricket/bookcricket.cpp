#include "bookcricket.h"
#include "ui_bookcricket.h"
#include<QGlobal.h>
#include<QTime>
#include<QMessageBox>

int i=1,j=1,score1=0,score2=0,player_score=0,temp,flag=0;

BookCricket::BookCricket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BookCricket)
{
    ui->setupUi(this);
    QTime time = QTime::currentTime();
    qsrand(time.msec());

}

BookCricket::~BookCricket()
{
    delete ui;
}

void BookCricket::on_pushButton_clicked()
{
    if(i<=11 || j<=11)
    {
        temp = qrand()%5;
        temp=2*temp;
        QString s = QString::number(temp);
        ui->textEdit->setText(s);
        playBookCricket(temp,s);
    }
}

void BookCricket::playBookCricket(int temp, QString s)
{
    if(i<=11)
    {
        player_score=player_score+temp;
        score1=score1+temp;
        QString p = QString::number(player_score);
        QString s1 = QString::number(score1);
        QString q="";
        if(temp!=0)
            q=q+"*";

        switch(i)
        {
        case 1:
            ui->a1LineEdit->setText(p+q);
            break;
        case 2:
            ui->a2LineEdit->setText(p+q);
            break;
        case 3:
            ui->a3LineEdit->setText(p+q);
            break;
        case 4:
            ui->a4LineEdit->setText(p+q);
            break;
        case 5:
            ui->a5LineEdit->setText(p+q);
            break;
        case 6:
            ui->a6LineEdit->setText(p+q);
            break;
        case 7:
            ui->a7LineEdit->setText(p+q);
            break;
        case 8:
            ui->a8LineEdit->setText(p+q);
            break;
        case 9:
            ui->a9LineEdit->setText(p+q);
            break;
        case 10:
            ui->a10LineEdit->setText(p+q);
            break;
        case 11:
            ui->a11LineEdit->setText(p+q);
            break;
        }
        if(temp==0)
        {
            i++;
            player_score=0;
        }

        QString wickets = QString::number(i-1);
        if(i==12)
            ui->totalLineEdit->setText(s1+" (all out)");
        else
            ui->totalLineEdit->setText(s1+"/"+wickets);
    }
    else if(j<=11 && flag==0)
    {
        player_score=player_score+temp;
        score2=score2+temp;
        QString p = QString::number(player_score);
        QString s2 = QString::number(score2);
        QString q="";
        if(temp!=0)
            q=q+"*";

        switch(j)
        {
        case 1:
            ui->b1LineEdit->setText(p+q);
            break;
        case 2:
            ui->b2LineEdit->setText(p+q);
            break;
        case 3:
            ui->b3LineEdit->setText(p+q);
            break;
        case 4:
            ui->b4LineEdit->setText(p+q);
            break;
        case 5:
            ui->b5LineEdit->setText(p+q);
            break;
        case 6:
            ui->b6LineEdit->setText(p+q);
            break;
        case 7:
            ui->b7LineEdit->setText(p+q);
            break;
        case 8:
            ui->b8LineEdit->setText(p+q);
            break;
        case 9:
            ui->b9LineEdit->setText(p+q);
            break;
        case 10:
            ui->b10LineEdit->setText(p+q);
            break;
        case 11:
            ui->b11LineEdit->setText(p+q);
            break;
        }

        if(temp==0)
        {
            j++;
            player_score=0;
        }

        QString wickets = QString::number(j-1);
        if(j==12)
            ui->totalLineEdit_2->setText(s2+" (all out)");
        else
            ui->totalLineEdit_2->setText(s2+"/"+wickets);

        if(score2>score1)
            flag=1;
    }
    if(j==12)
        flag=1;
    if(flag==1)
    {
        if(score1==score2)
            ui->label_5->setText("Tie!");
        else if(score1>score2)
        {
            int diff=score1-score2;
            QString d = QString::number(diff);
            if(diff==1)
                ui->label_5->setText("India has won by 1 run!");
            else
                ui->label_5->setText("India has won by "+d+" runs!");
        }
        else
        {
            int diff=12-j;
            QString d = QString::number(diff);
            if(diff==1)
                ui->label_5->setText("South Africa has won by 1 wicket!");
            else
                ui->label_5->setText("South Africa has won by "+d+" wickets!");
        }
        ui->pushButton->setVisible(false);
        ui->textEdit->setVisible(false);
        ui->label_4->setVisible(false);
    }
}

void BookCricket::on_action_About_BookCricket_triggered()
{
    QMessageBox::about(this,"About Book Cricket","Book Cricket\n\nBuilt on Feb 23 2018\n\nCopyright \xa9 2018 Siddharth. All rights reserved.\n\nThe program is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.");
}

void BookCricket::on_actionE_xit_triggered()
{
    close();
}
