#include "dialogsamp.h"
#include "ui_dialogsamp.h"

Dialogsamp::Dialogsamp(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialogsamp) {
    ui->setupUi(this);
    connect(ui->Blue, SIGNAL(clicked()), this, SLOT(setTextColot()));
    connect(ui->Blacki, SIGNAL(clicked()), this, SLOT(setTextColot()));
    connect(ui->Red, SIGNAL(clicked()), this, SLOT(setTextColot()));
}

Dialogsamp::~Dialogsamp()
{
    delete ui;
}


void Dialogsamp::on_UnderLine_clicked(bool checked) {
    QFont font = ui->plainTextEdit->font();
    font.setUnderline(checked);
    ui->plainTextEdit->setFont(font);
}

void Dialogsamp::on_B_clicked(bool checked) {
    QFont font = ui->plainTextEdit->font();
    font.setBold(checked);
    ui->plainTextEdit->setFont(font);
}

void Dialogsamp::on_Ita_clicked(bool checked) {
    QFont font = ui->plainTextEdit->font();
    font.setItalic(checked);
    ui->plainTextEdit->setFont(font);
}

void Dialogsamp::setTextColot() {
    QPalette plet = ui->plainTextEdit->palette();
    if (ui->Blue->isChecked()) {
        plet.setColor(QPalette::Text, Qt::blue);
    } else if (ui->Red->isChecked()) {
        plet.setColor(QPalette::Text, Qt::red);
    } else {
        plet.setColor(QPalette::Text, Qt::black);
    }
    ui->plainTextEdit->setPalette(plet);
}
