/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *centralwidget;
    QLabel *label_3;
    QGroupBox *groupBox;
    QPushButton *loginButton;
    QPushButton *signupButton;
    QLabel *messageLabel;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *passwordEdit;
    QLineEdit *usernameEdit;
    QFrame *frame;
    QLabel *label_4;
    QLabel *guideLabel;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(720, 480);
        login->setAutoFillBackground(false);
        login->setStyleSheet(QString::fromUtf8("background-color:rgb(226, 226, 226);"));
        centralwidget = new QWidget(login);
        centralwidget->setObjectName("centralwidget");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(220, 120, 291, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("URW Gothic [urw]")});
        font.setPointSize(20);
        font.setBold(true);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"\n"
"background-color: rgb(247, 255, 210);"));
        label_3->setAlignment(Qt::AlignCenter);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(240, 170, 240, 251));
        groupBox->setStyleSheet(QString::fromUtf8("gridline-color: rgb(255, 255, 255);\n"
"\n"
"background-color: rgb(247, 255, 210);"));
        groupBox->setAlignment(Qt::AlignCenter);
        loginButton = new QPushButton(groupBox);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(90, 140, 50, 21));
        loginButton->setMinimumSize(QSize(50, 0));
        loginButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	\n"
"	background-color: rgb(222, 215, 255);\n"
"	min-width : 50px;\n"
"	max-width : 50px;\n"
"\n"
"	color: rgb(85, 170, 255);\n"
"	border-radius:5px;\n"
"	font: 600 9pt \"NotoSerifTamilSlanted SemiBold\";\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #2ecc71;\n"
"    color: white;              \n"
"}"));
        signupButton = new QPushButton(groupBox);
        signupButton->setObjectName("signupButton");
        signupButton->setGeometry(QRect(90, 170, 50, 21));
        signupButton->setMinimumSize(QSize(50, 0));
        signupButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	\n"
"	background-color: rgb(222, 215, 255);\n"
"	min-width : 50px;\n"
"	max-width : 50px;\n"
"\n"
"	color: rgb(85, 170, 255);\n"
"	border-radius:5px;\n"
"	font: 600 9pt \"NotoSerifTamilSlanted SemiBold\";\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #2ecc71;\n"
"    color: white;              \n"
"}"));
        messageLabel = new QLabel(groupBox);
        messageLabel->setObjectName("messageLabel");
        messageLabel->setGeometry(QRect(8, 9, 221, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Sans Serif")});
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        messageLabel->setFont(font1);
        messageLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 127);\n"
"font: 10pt \"Sans Serif\";\n"
"background-color: transparent;"));
        messageLabel->setAlignment(Qt::AlignCenter);
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 50, 31, 31));
        label->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-color:transparent;"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 100, 31, 31));
        label_2->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-color:transparent;"));
        label_2->setAlignment(Qt::AlignCenter);
        passwordEdit = new QLineEdit(groupBox);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setEnabled(true);
        passwordEdit->setGeometry(QRect(50, 100, 171, 31));
        passwordEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	border:2px solid rgb(0, 170, 255);\n"
"	border-radius:7px;\n"
"	background-color: transparent;\n"
" \n"
"	color:rgb(45, 45, 45);\n"
"}"));
        passwordEdit->setEchoMode(QLineEdit::Password);
        usernameEdit = new QLineEdit(groupBox);
        usernameEdit->setObjectName("usernameEdit");
        usernameEdit->setEnabled(true);
        usernameEdit->setGeometry(QRect(50, 50, 171, 31));
        usernameEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	border:2px solid rgb(0, 170, 255);\n"
"	border-radius:7px;\n"
"	background-color: transparent;\n"
" \n"
"	color:rgb(47, 47, 47);\n"
"}"));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(170, 30, 381, 411));
        frame->setStyleSheet(QString::fromUtf8("border:5px solid rgb(255,255,255);\n"
"background-color: rgb(247, 255, 210);\n"
"border-radius:10px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(130, -20, 131, 141));
        label_4->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"border-color:transparent;"));
        label_4->setAlignment(Qt::AlignCenter);
        guideLabel = new QLabel(centralwidget);
        guideLabel->setObjectName("guideLabel");
        guideLabel->setGeometry(QRect(0, 0, 721, 21));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("URW Bookman [UKWN]")});
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setItalic(true);
        guideLabel->setFont(font2);
        guideLabel->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 237, 253);\n"
"color: rgb(0, 0, 0);\n"
"font: 500 9pt \"Quicksand Medium\";\n"
"font: 600 italic 9pt \"URW Bookman [UKWN]\";"));
        guideLabel->setAlignment(Qt::AlignCenter);
        login->setCentralWidget(centralwidget);
        frame->raise();
        label_3->raise();
        groupBox->raise();
        guideLabel->raise();
        statusbar = new QStatusBar(login);
        statusbar->setObjectName("statusbar");
        login->setStatusBar(statusbar);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QMainWindow *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "Sign In", nullptr));
        label_3->setText(QCoreApplication::translate("login", "HyunBin SmartHome", nullptr));
        groupBox->setTitle(QString());
        loginButton->setText(QCoreApplication::translate("login", "login", nullptr));
        signupButton->setText(QCoreApplication::translate("login", "Sign up", nullptr));
        messageLabel->setText(QCoreApplication::translate("login", "Sign In", nullptr));
        label->setText(QCoreApplication::translate("login", "<html><head/><body><p><img src=\":/images/user.png\" width=\"20\" height=\"20\"/></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("login", "<html><head/><body><p><img src=\":/images/padlock.png\" width=\"20\" height=\"20\"/></p></body></html>", nullptr));
        passwordEdit->setInputMask(QString());
        passwordEdit->setText(QString());
        usernameEdit->setInputMask(QString());
        usernameEdit->setText(QString());
        label_4->setText(QCoreApplication::translate("login", "<html><head/><body><p><img src=\":/images/smarthome.png\" width=\"90\" height=\"90\"/></p></body></html>", nullptr));
        guideLabel->setText(QCoreApplication::translate("login", "Hanbin & SiHyun VEDA Mini Project", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
