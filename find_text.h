#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QWidget>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    FindDialog(QWidget *parent = nullptr);
signals:
    void FindNext(const QString &str, Qt::CaseSensitivity cs);
    void FindPrevious(const QString &str, Qt::CaseSensitivity cs);
private slots:
    void findClicled();
    void enableButton(const QString &text);
private:
    QPushButton *findButton;
    QPushButton *closeButton;
    QLabel *label;
    QCheckBox *backwardCheck;
    QCheckBox *matchCaseCheck;
    QLineEdit *lineText;

};
#endif // MAINWINDOW_H
