#ifndef DIALOGSAMP_H
#define DIALOGSAMP_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialogsamp; }
QT_END_NAMESPACE

class Dialogsamp : public QDialog
{
    Q_OBJECT

public:
    Dialogsamp(QWidget *parent = nullptr);
    ~Dialogsamp();

private slots:
    void on_UnderLine_clicked(bool checked);

    void on_B_clicked(bool checked);

    void on_Ita_clicked(bool checked);

    void setTextColot();

private:
    Ui::Dialogsamp *ui;
};
#endif // DIALOGSAMP_H
