/********************************************************************************
** Form generated from reading UI file 'dialog_example.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_EXAMPLE_H
#define UI_DIALOG_EXAMPLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_dialog_example
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dialog_example)
    {
        if (dialog_example->objectName().isEmpty())
            dialog_example->setObjectName(QString::fromUtf8("dialog_example"));
        dialog_example->resize(400, 300);
        buttonBox = new QDialogButtonBox(dialog_example);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(dialog_example);
        QObject::connect(buttonBox, SIGNAL(accepted()), dialog_example, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dialog_example, SLOT(reject()));

        QMetaObject::connectSlotsByName(dialog_example);
    } // setupUi

    void retranslateUi(QDialog *dialog_example)
    {
        dialog_example->setWindowTitle(QCoreApplication::translate("dialog_example", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialog_example: public Ui_dialog_example {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_EXAMPLE_H
