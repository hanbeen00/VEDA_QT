/********************************************************************************
** Form generated from reading UI file 'chatroomselection.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATROOMSELECTION_H
#define UI_CHATROOMSELECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatRoomSelection
{
public:
    QLabel *titleLabel;
    QPushButton *quitButton;
    QLabel *label_3;
    QGroupBox *groupBox_2;
    QFrame *frame;
    QPushButton *chatRoom2Button;
    QPushButton *chatRoom3Button;
    QPushButton *chatRoom1Button;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_4;
    QLabel *guideLabel;

    void setupUi(QWidget *ChatRoomSelection)
    {
        if (ChatRoomSelection->objectName().isEmpty())
            ChatRoomSelection->setObjectName("ChatRoomSelection");
        ChatRoomSelection->resize(720, 480);
        ChatRoomSelection->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        titleLabel = new QLabel(ChatRoomSelection);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(210, 0, 291, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Quicksand Medium")});
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        titleLabel->setFont(font);
        titleLabel->setStyleSheet(QString::fromUtf8("color: rgb(85, 85, 255);\n"
"font: 500 20pt \"Quicksand Medium\";\n"
"background-color:transparent;"));
        titleLabel->setAlignment(Qt::AlignCenter);
        quitButton = new QPushButton(ChatRoomSelection);
        quitButton->setObjectName("quitButton");
        quitButton->setGeometry(QRect(0, 0, 41, 41));
        quitButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:rgba(0, 0, 0, 0);\n"
"	border:none;\n"
"}\n"
"\n"
""));
        label_3 = new QLabel(ChatRoomSelection);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 0, 41, 41));
        label_3->setStyleSheet(QString::fromUtf8("background-color:  rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignCenter);
        groupBox_2 = new QGroupBox(ChatRoomSelection);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(181, 49, 361, 421));
        frame = new QFrame(groupBox_2);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 10, 341, 401));
        frame->setStyleSheet(QString::fromUtf8("background-color:rgb(221, 252, 255);\n"
"border:1.5px solid rgb(136, 136, 136);\n"
"border-radius:10px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        chatRoom2Button = new QPushButton(frame);
        chatRoom2Button->setObjectName("chatRoom2Button");
        chatRoom2Button->setGeometry(QRect(20, 160, 300, 100));
        chatRoom2Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 800 11pt \"Cantarell Extra Bold\";\n"
"	background-color: rgb(253, 255, 222);\n"
"	border: 1px solid rgb(85, 85, 255);\n"
"	border-radius:20px;\n"
"	color:rgb(85, 85, 255);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(231, 229, 255);         \n"
"}"));
        chatRoom3Button = new QPushButton(frame);
        chatRoom3Button->setObjectName("chatRoom3Button");
        chatRoom3Button->setGeometry(QRect(20, 280, 301, 101));
        chatRoom3Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 800 11pt \"Cantarell Extra Bold\";\n"
"	background-color: rgb(253, 255, 222);\n"
"	border: 1px solid rgb(85, 85, 255);\n"
"	border-radius:20px;\n"
"	color:rgb(85, 85, 255);\n"
"}\n"
"\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(185, 255, 201);\n"
"}"));
        chatRoom1Button = new QPushButton(frame);
        chatRoom1Button->setObjectName("chatRoom1Button");
        chatRoom1Button->setGeometry(QRect(20, 40, 300, 100));
        chatRoom1Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 800 11pt \"Cantarell Extra Bold\";\n"
"	background-color: rgb(253, 255, 222);\n"
"	border: 1px solid rgb(85, 85, 255);\n"
"	border-radius:20px;\n"
"	color:rgb(85, 85, 255);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(255, 204, 162);\n"
"}"));
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 180, 71, 61));
        label_2->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border:none;"));
        label_2->setAlignment(Qt::AlignCenter);
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 60, 81, 71));
        label->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border:none;"));
        label->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 300, 91, 61));
        label_4->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border:none;"));
        label_4->setAlignment(Qt::AlignCenter);
        guideLabel = new QLabel(groupBox_2);
        guideLabel->setObjectName("guideLabel");
        guideLabel->setGeometry(QRect(90, 0, 181, 21));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("URW Bookman [UKWN]")});
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setItalic(true);
        guideLabel->setFont(font1);
        guideLabel->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 237, 253);\n"
"color: rgb(0, 0, 0);\n"
"font: 500 9pt \"Quicksand Medium\";\n"
"font: 600 italic 9pt \"URW Bookman [UKWN]\";"));
        guideLabel->setAlignment(Qt::AlignCenter);
        label_3->raise();
        titleLabel->raise();
        quitButton->raise();

        retranslateUi(ChatRoomSelection);

        QMetaObject::connectSlotsByName(ChatRoomSelection);
    } // setupUi

    void retranslateUi(QWidget *ChatRoomSelection)
    {
        ChatRoomSelection->setWindowTitle(QCoreApplication::translate("ChatRoomSelection", "Select Chat", nullptr));
        titleLabel->setText(QCoreApplication::translate("ChatRoomSelection", "Smart Home", nullptr));
        quitButton->setText(QString());
        label_3->setText(QCoreApplication::translate("ChatRoomSelection", "<html><head/><body><p><img src=\":/images/quit.png\" width = \"40\" height=\"40\"/></p></body></html> ", nullptr));
        groupBox_2->setTitle(QString());
        chatRoom2Button->setText(QCoreApplication::translate("ChatRoomSelection", "                             TV control", nullptr));
        chatRoom3Button->setText(QCoreApplication::translate("ChatRoomSelection", "                             Window control", nullptr));
        chatRoom1Button->setText(QCoreApplication::translate("ChatRoomSelection", "                             Air Conditioning", nullptr));
        label_2->setText(QCoreApplication::translate("ChatRoomSelection", "<html><head/><body><p><img src=\":/images/tv.png\" width=\"60\" height=\"60\"/></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("ChatRoomSelection", "<html><head/><body><p><img src=\":/images/aircon2.png\" width=\"70\" height=\"70\" /></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("ChatRoomSelection", "<html><head/><body><p><img src=\":/images/window.png\" width=\"60\" height=\"50\"/></p></body></html>", nullptr));
        guideLabel->setText(QCoreApplication::translate("ChatRoomSelection", "Select a chat room", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatRoomSelection: public Ui_ChatRoomSelection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATROOMSELECTION_H
