#include "find_text.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

FindDialog::FindDialog(QWidget *parent):QDialog(parent){
      label = new QLabel(tr("Find &what"));
      lineText = new QLineEdit;
     label->setBuddy(lineText);


    findButton = new QPushButton(tr("&Find"));
    findButton->setDefault(true);
    findButton->setEnabled(false);
    closeButton = new QPushButton(tr("&Close"));

    backwardCheck = new QCheckBox(tr("Search &backward"));
    matchCaseCheck = new QCheckBox(tr("Match &case"));

    QHBoxLayout *text_line = new QHBoxLayout;
    text_line->addWidget(label);
    text_line->addWidget(lineText);

     QVBoxLayout *button_column = new QVBoxLayout;
     button_column->addWidget(findButton);
     button_column->addWidget(closeButton);
     button_column->addStretch();

     QVBoxLayout *column_checkbox = new QVBoxLayout;
     column_checkbox->addLayout(text_line);
     column_checkbox->addWidget(backwardCheck);
     column_checkbox->addWidget(matchCaseCheck);

     QHBoxLayout *main_layout = new QHBoxLayout;
     main_layout->addLayout(column_checkbox);
     main_layout->addLayout(button_column);

     setLayout(main_layout);
    // setFixedSize(800,200);
     setFixedHeight(sizeHint().height());
     setFixedWidth(750);
     setWindowTitle("Find");
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(lineText, SIGNAL(textChanged(const QString &)),this,
            SLOT(enableButton(const QString &)));
    connect(findButton, SIGNAL(cliked()), this,SLOT(findClicled()));

}

void FindDialog::findClicled(){
    QString text = lineText->text();
    Qt::CaseSensitivity cs =  matchCaseCheck->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;
    if(backwardCheck->isChecked()){
        emit FindNext(text, cs);
    }
    else{
        emit FindPrevious(text, cs);
    }

}

void FindDialog::enableButton(const QString &textstr){

    findButton->setEnabled(!lineText->text().isEmpty());
  //  findButton->setEnabled(true);
}




