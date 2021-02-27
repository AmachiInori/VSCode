# ifndef MAINWINDOW_H
# define MAINWINDOW_H

# include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::vector<std::pair<QString, double>> history;
    double inner_calculator(const QString &_expr);
    void refresh_err_info();
    long int auto_parser_max = 32767;
    long int calcu_max = 65535;

private slots:
    void on_calculate_botton_clicked();
    void on_input_box_textChanged();
};
#endif // MAINWINDOW_H
