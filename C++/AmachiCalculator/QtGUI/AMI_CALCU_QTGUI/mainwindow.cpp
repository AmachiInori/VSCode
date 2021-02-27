/*
 * TODO 做个回车触发
 */


# include "mainwindow.h"
# include "./ui_mainwindow.h"
# include "../../src/AMI_Calcu.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_calculate_botton_clicked() {
    ui->state_label->setText("Calculating...");
    QString input_str = ui->input_box->toPlainText();
    if (input_str.length() > auto_parser_max) this->refresh_err_info();

    double res = this->inner_calculator(input_str);
    ui->state_label->setText("Done.");

    this->history.push_back({ input_str, res });
    QString output_str;
    output_str.setNum(res);
    ui->output_box->setText(output_str);

    ui->history_box->insertRow(0);
    ui->history_box->setItem(0, 0, new QTableWidgetItem(input_str));
    ui->history_box->setItem(0, 1, new QTableWidgetItem(output_str));
}

double MainWindow::inner_calculator(const QString &_expr) {
    return AmiCal::etolf(_expr.toStdString());
}

void MainWindow::refresh_err_info() {
    QString input_str = ui->input_box->toPlainText();

    ui->state_label->setText("Calculating...");
    std::string err_output;
    if (input_str.isEmpty()) {
        err_output = "Ami000 - Complete";
    } else {
        err_output = AmiCal::get_error_info(input_str.toStdString());
    }
    ui->state_label->setText("Done.");

    ui->debug_info->setText(QString::fromStdString(err_output));
    QPalette _palette = ui->input_box->palette();
    if (err_output != "Ami000 - Complete")
        _palette.setColor(QPalette::Text, Qt::red);
    else
        _palette.setColor(QPalette::Text, Qt::black);
    ui->input_box->setPalette(_palette);
    ui->debug_info->setPalette(_palette);
}

void MainWindow::on_input_box_textChanged() {
    if (ui->input_box->toPlainText().length() > auto_parser_max) {
        QString err_output = "Automatic parsing stopped because the input is too long";
        QPalette _palette = ui->input_box->palette();
        _palette.setColor(QPalette::Text, Qt::red);

        ui->debug_info->setText(err_output);
        ui->debug_info->setPalette(_palette);
        return;
    }
    this->refresh_err_info();
}
