/********************************************************************************
** Form generated from reading UI file 'dialogsamp.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSAMP_H
#define UI_DIALOGSAMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialogsamp
{
public:
    QPlainTextEdit *plainTextEdit;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *UnderLine;
    QCheckBox *B;
    QCheckBox *Ita;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *Blacki;
    QRadioButton *Red;
    QRadioButton *Blue;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *confirm;
    QPushButton *exit;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *Cencel;

    void setupUi(QDialog *Dialogsamp)
    {
        if (Dialogsamp->objectName().isEmpty())
            Dialogsamp->setObjectName(QString::fromUtf8("Dialogsamp"));
        Dialogsamp->resize(800, 600);
        plainTextEdit = new QPlainTextEdit(Dialogsamp);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(113, 194, 591, 261));
        groupBox = new QGroupBox(Dialogsamp);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(100, 30, 621, 69));
        horizontalLayout_5 = new QHBoxLayout(groupBox);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        UnderLine = new QCheckBox(groupBox);
        UnderLine->setObjectName(QString::fromUtf8("UnderLine"));

        horizontalLayout_5->addWidget(UnderLine);

        B = new QCheckBox(groupBox);
        B->setObjectName(QString::fromUtf8("B"));

        horizontalLayout_5->addWidget(B);

        Ita = new QCheckBox(groupBox);
        Ita->setObjectName(QString::fromUtf8("Ita"));

        horizontalLayout_5->addWidget(Ita);

        groupBox_2 = new QGroupBox(Dialogsamp);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(100, 110, 621, 69));
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        Blacki = new QRadioButton(groupBox_2);
        Blacki->setObjectName(QString::fromUtf8("Blacki"));

        horizontalLayout_4->addWidget(Blacki);

        Red = new QRadioButton(groupBox_2);
        Red->setObjectName(QString::fromUtf8("Red"));

        horizontalLayout_4->addWidget(Red);

        Blue = new QRadioButton(groupBox_2);
        Blue->setObjectName(QString::fromUtf8("Blue"));

        horizontalLayout_4->addWidget(Blue);

        horizontalLayoutWidget = new QWidget(Dialogsamp);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(60, 490, 641, 51));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        confirm = new QPushButton(horizontalLayoutWidget);
        confirm->setObjectName(QString::fromUtf8("confirm"));

        horizontalLayout_3->addWidget(confirm);

        exit = new QPushButton(horizontalLayoutWidget);
        exit->setObjectName(QString::fromUtf8("exit"));

        horizontalLayout_3->addWidget(exit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        Cencel = new QPushButton(horizontalLayoutWidget);
        Cencel->setObjectName(QString::fromUtf8("Cencel"));

        horizontalLayout_3->addWidget(Cencel);


        retranslateUi(Dialogsamp);
        QObject::connect(confirm, SIGNAL(clicked()), Dialogsamp, SLOT(accept()));
        QObject::connect(exit, SIGNAL(clicked()), Dialogsamp, SLOT(close()));
        QObject::connect(Cencel, SIGNAL(clicked()), Dialogsamp, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialogsamp);
    } // setupUi

    void retranslateUi(QDialog *Dialogsamp)
    {
        Dialogsamp->setWindowTitle(QCoreApplication::translate("Dialogsamp", "Dialogsamp", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("Dialogsamp", "Hello World\n"
"It is my demo\n"
"", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Dialogsamp", "GroupBox", nullptr));
        UnderLine->setText(QCoreApplication::translate("Dialogsamp", "UnderLine", nullptr));
        B->setText(QCoreApplication::translate("Dialogsamp", "B", nullptr));
        Ita->setText(QCoreApplication::translate("Dialogsamp", "Italic", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Dialogsamp", "GroupBox", nullptr));
        Blacki->setText(QCoreApplication::translate("Dialogsamp", "Black", nullptr));
        Red->setText(QCoreApplication::translate("Dialogsamp", "Red", nullptr));
        Blue->setText(QCoreApplication::translate("Dialogsamp", "Blue", nullptr));
        confirm->setText(QCoreApplication::translate("Dialogsamp", "Confirm", nullptr));
        exit->setText(QCoreApplication::translate("Dialogsamp", "EXIT", nullptr));
        Cencel->setText(QCoreApplication::translate("Dialogsamp", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialogsamp: public Ui_Dialogsamp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSAMP_H
