/********************************************************************************
** Form generated from reading UI file 'chatwindow1.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWINDOW1_H
#define UI_CHATWINDOW1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWindow1
{
public:
    QGroupBox *chatgroupBox;
    QLineEdit *messageInput;
    QPushButton *sendButton;
    QTextEdit *messageDisplay;
    QLabel *titleLabel;
    QGroupBox *tempGroup;
    QLabel *label;
    QDial *dial;
    QLabel *label_3;
    QGroupBox *tempGroup_2;
    QComboBox *windBox;
    QLabel *label_6;
    QLabel *label_2;
    QPushButton *airconON;
    QPushButton *airconOFF;
    QPushButton *exitButton;
    QLabel *exit;

    void setupUi(QWidget *ChatWindow1)
    {
        if (ChatWindow1->objectName().isEmpty())
            ChatWindow1->setObjectName("ChatWindow1");
        ChatWindow1->resize(720, 480);
        ChatWindow1->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);\n"
"border: 1px solid black;\n"
"border-color: rgb(0, 0, 0);"));
        chatgroupBox = new QGroupBox(ChatWindow1);
        chatgroupBox->setObjectName("chatgroupBox");
        chatgroupBox->setGeometry(QRect(380, 70, 311, 391));
        chatgroupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 248, 254);\n"
"border-color: rgb(246, 235, 255);\n"
"border-radius: 10px;"));
        messageInput = new QLineEdit(chatgroupBox);
        messageInput->setObjectName("messageInput");
        messageInput->setEnabled(true);
        messageInput->setGeometry(QRect(10, 350, 201, 31));
        messageInput->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	border:2px solid rgb(116, 103, 255);\n"
"	border-radius:5px;\n"
" \n"
"	\n"
"	color: rgb(61, 61, 61);\n"
"	background-color: transparent;\n"
"	font: 9pt \"Sans Serif\";\n"
"}"));
        sendButton = new QPushButton(chatgroupBox);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(220, 350, 81, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Quicksand Medium")});
        font.setPointSize(12);
        sendButton->setFont(font);
        sendButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: 2px solid rgb(135, 135, 135);\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(170, 170, 255);\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(255, 251, 144);\n"
"    color: rgb(195, 193, 255);\n"
"}"));
        messageDisplay = new QTextEdit(chatgroupBox);
        messageDisplay->setObjectName("messageDisplay");
        messageDisplay->setGeometry(QRect(10, 10, 291, 331));
        messageDisplay->setMouseTracking(true);
        messageDisplay->setAcceptDrops(true);
        messageDisplay->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border:2px solid rgb(181, 178, 255);\n"
"border-radius: 7px;\n"
"color: rgb(56, 56, 56);\n"
"font: 10pt \"Quicksand\";\n"
""));
        messageDisplay->setReadOnly(true);
        messageDisplay->setAcceptRichText(true);
        titleLabel = new QLabel(ChatWindow1);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(150, 10, 441, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Quicksand Medium")});
        font1.setPointSize(20);
        font1.setBold(false);
        font1.setItalic(false);
        titleLabel->setFont(font1);
        titleLabel->setStyleSheet(QString::fromUtf8("color: rgb(85, 85, 255);\n"
"font: 500 20pt \"Quicksand Medium\";\n"
"background-color:rgb(240, 240, 240);\n"
"border-color:transparent;"));
        titleLabel->setAlignment(Qt::AlignCenter);
        tempGroup = new QGroupBox(ChatWindow1);
        tempGroup->setObjectName("tempGroup");
        tempGroup->setGeometry(QRect(40, 140, 301, 161));
        tempGroup->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-color:transparent;"));
        label = new QLabel(tempGroup);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 50, 71, 71));
        label->setStyleSheet(QString::fromUtf8("background-color : transparent;\n"
"border-color: transparent;"));
        label->setAlignment(Qt::AlignCenter);
        dial = new QDial(tempGroup);
        dial->setObjectName("dial");
        dial->setGeometry(QRect(120, 10, 151, 131));
        dial->setMouseTracking(false);
        dial->setAcceptDrops(false);
        dial->setStyleSheet(QString::fromUtf8("background-color: rgb(236, 220, 255);"));
        dial->setMinimum(18);
        dial->setMaximum(30);
        dial->setValue(20);
        dial->setNotchesVisible(true);
        label_3 = new QLabel(tempGroup);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 0, 271, 151));
        label_3->setStyleSheet(QString::fromUtf8("    font: 800 11pt \"Cantarell Extra Bold\";\n"
"	background-color: rgb(246, 255, 224);\n"
"	border: 1px solid rgb(85, 85, 255);\n"
"	border-radius:15px;\n"
"	color:rgb(85, 85, 255);"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_3->raise();
        dial->raise();
        label->raise();
        tempGroup_2 = new QGroupBox(ChatWindow1);
        tempGroup_2->setObjectName("tempGroup_2");
        tempGroup_2->setGeometry(QRect(40, 310, 301, 141));
        tempGroup_2->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-color:transparent;"));
        windBox = new QComboBox(tempGroup_2);
        windBox->addItem(QString());
        windBox->addItem(QString());
        windBox->addItem(QString());
        windBox->addItem(QString());
        windBox->addItem(QString());
        windBox->setObjectName("windBox");
        windBox->setGeometry(QRect(30, 60, 81, 31));
        windBox->setStyleSheet(QString::fromUtf8("background-color: rgb(210, 236, 255);    \n"
"font: 800 11pt \"Cantarell Extra Bold\";"));
        label_6 = new QLabel(tempGroup_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 10, 271, 121));
        label_6->setStyleSheet(QString::fromUtf8("    font: 800 11pt \"Cantarell Extra Bold\";\n"
"	background-color:  rgb(246, 255, 224);\n"
"	border: 1px solid rgb(85, 85, 255);\n"
"	border-radius:15px;\n"
"	color:rgb(85, 85, 255);"));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_2 = new QLabel(tempGroup_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(130, 20, 131, 101));
        label_2->setStyleSheet(QString::fromUtf8("background-color : transparent;\n"
"border-color: transparent;"));
        label_2->setAlignment(Qt::AlignCenter);
        label_6->raise();
        windBox->raise();
        label_2->raise();
        airconON = new QPushButton(ChatWindow1);
        airconON->setObjectName("airconON");
        airconON->setGeometry(QRect(100, 80, 61, 31));
        airconON->setFont(font);
        airconON->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:0px solid rgb(135, 135, 135);\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(193, 193, 193);\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	border-radius: 5px;\n"
"    background-color: rgb(255, 251, 144);\n"
"    color: rgb(195, 193, 255);\n"
"}\n"
""));
        airconOFF = new QPushButton(ChatWindow1);
        airconOFF->setObjectName("airconOFF");
        airconOFF->setGeometry(QRect(210, 80, 61, 31));
        airconOFF->setFont(font);
        airconOFF->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: 0px solid rgb(135, 135, 135);\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(193,193,193);\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	border-radius: 5px;\n"
"    background-color: rgb(255, 251, 144);\n"
"    color: rgb(195, 193, 255);\n"
"}"));
        exitButton = new QPushButton(ChatWindow1);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(10, 10, 31, 31));
        exitButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:rgba(0, 0, 0, 0);\n"
"	border:rgba(0, 0, 0, 0);\n"
"	border-radius: 15px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 202, 172,0.5);\n"
"}"));
        exit = new QLabel(ChatWindow1);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(10, 10, 31, 31));
        exit->setStyleSheet(QString::fromUtf8("background-color:  rgb(255, 255, 255);\n"
"border:none;"));
        exit->setAlignment(Qt::AlignCenter);
        exit->raise();
        chatgroupBox->raise();
        titleLabel->raise();
        tempGroup->raise();
        tempGroup_2->raise();
        airconON->raise();
        airconOFF->raise();
        exitButton->raise();

        retranslateUi(ChatWindow1);

        QMetaObject::connectSlotsByName(ChatWindow1);
    } // setupUi

    void retranslateUi(QWidget *ChatWindow1)
    {
        ChatWindow1->setWindowTitle(QCoreApplication::translate("ChatWindow1", "Chat1", nullptr));
        chatgroupBox->setTitle(QString());
        messageInput->setInputMask(QString());
        messageInput->setText(QString());
        sendButton->setText(QCoreApplication::translate("ChatWindow1", "Send", nullptr));
        titleLabel->setText(QCoreApplication::translate("ChatWindow1", "AirConditioning Manage Chat", nullptr));
        tempGroup->setTitle(QString());
        label->setText(QCoreApplication::translate("ChatWindow1", "<html><head/><body><p><img src=\":/images/humidity.png\" width=\"50\" height=\"50\"/></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("ChatWindow1", "Temperature", nullptr));
        tempGroup_2->setTitle(QString());
        windBox->setItemText(0, QCoreApplication::translate("ChatWindow1", "1 Level", nullptr));
        windBox->setItemText(1, QCoreApplication::translate("ChatWindow1", "2 Level", nullptr));
        windBox->setItemText(2, QCoreApplication::translate("ChatWindow1", "3 Level", nullptr));
        windBox->setItemText(3, QCoreApplication::translate("ChatWindow1", "4 Level", nullptr));
        windBox->setItemText(4, QCoreApplication::translate("ChatWindow1", "5 Level", nullptr));

        label_6->setText(QCoreApplication::translate("ChatWindow1", " Wind", nullptr));
        label_2->setText(QCoreApplication::translate("ChatWindow1", "<html><head/><body><p><img src=\":/images/aircon2.png\" width=\"100\" height=\"100\"/></p></body></html>", nullptr));
        airconON->setText(QCoreApplication::translate("ChatWindow1", "ON", nullptr));
        airconOFF->setText(QCoreApplication::translate("ChatWindow1", "OFF", nullptr));
        exitButton->setText(QString());
        exit->setText(QCoreApplication::translate("ChatWindow1", "<html><head/><body><p><img src=\":/images/exit.png\" width = \"25\" height=\"25\"/></p></body></html> ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatWindow1: public Ui_ChatWindow1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWINDOW1_H
