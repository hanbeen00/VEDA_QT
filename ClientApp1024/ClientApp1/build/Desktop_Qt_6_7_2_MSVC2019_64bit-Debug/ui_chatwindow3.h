/********************************************************************************
** Form generated from reading UI file 'chatwindow3.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWINDOW3_H
#define UI_CHATWINDOW3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWindow3
{
public:
    QGroupBox *chatgroupBox;
    QLineEdit *messageInput;
    QPushButton *sendButton;
    QTextEdit *messageDisplay;
    QLabel *titleLabel;
    QPushButton *exitButton;
    QLabel *exit;
    QSlider *room1Slider;
    QSlider *room2Slider;
    QSlider *room3Slider;
    QLabel *label_4;
    QLabel *titleLabel_2;
    QLabel *titleLabel_3;
    QLabel *titleLabel_4;
    QPushButton *windowOpenButton;
    QPushButton *windowCloseButton;
    QLabel *label;
    QLabel *guideLabel;

    void setupUi(QWidget *ChatWindow3)
    {
        if (ChatWindow3->objectName().isEmpty())
            ChatWindow3->setObjectName("ChatWindow3");
        ChatWindow3->resize(720, 480);
        ChatWindow3->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);\n"
"border: 1px solid black;\n"
"border-color: rgb(0, 0, 0);\n"
"selection-color: rgb(85, 170, 255);"));
        chatgroupBox = new QGroupBox(ChatWindow3);
        chatgroupBox->setObjectName("chatgroupBox");
        chatgroupBox->setGeometry(QRect(380, 70, 311, 391));
        chatgroupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(231, 255, 235);\n"
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
        messageDisplay->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border:2px solid rgb(181, 178, 255);\n"
"border-radius: 7px;\n"
"color: rgb(56, 56, 56);\n"
"font: 10pt \"Quicksand\";"));
        messageDisplay->setReadOnly(true);
        titleLabel = new QLabel(ChatWindow3);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(140, 10, 441, 41));
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
        exitButton = new QPushButton(ChatWindow3);
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
        exit = new QLabel(ChatWindow3);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(10, 10, 31, 31));
        exit->setStyleSheet(QString::fromUtf8("background-color:  rgb(255, 255, 255);\n"
"border:none;"));
        exit->setAlignment(Qt::AlignCenter);
        room1Slider = new QSlider(ChatWindow3);
        room1Slider->setObjectName("room1Slider");
        room1Slider->setGeometry(QRect(120, 270, 241, 41));
        room1Slider->setStyleSheet(QString::fromUtf8("QSlider {\n"
"    background-color: #e0e0e0;   /* \354\212\254\353\235\274\354\235\264\353\215\224 \354\240\204\354\262\264 \353\260\260\352\262\275\354\203\211 */\n"
"    border: transparent;   /* \354\212\254\353\235\274\354\235\264\353\215\224 \355\205\214\353\221\220\353\246\254 */\n"
"    border-radius: 10px;         /* \354\212\254\353\235\274\354\235\264\353\215\224 \355\205\214\353\221\220\353\246\254\354\235\230 \353\221\245\352\267\274 \354\240\225\353\217\204 */\n"
"    padding: 5px;                /* \354\212\254\353\235\274\354\235\264\353\215\224 \353\202\264\353\266\200 \355\214\250\353\224\251 */\n"
"}\n"
"QSlider::groove:horizontal {\n"
"    border: 1px solid rgb(255, 255, 255); /* \355\212\270\353\236\231 \352\262\275\352\263\204\354\204\240 */\n"
"    height: 15px;               /* \355\212\270\353\236\231\354\235\230 \353\206\222\354\235\264 \354\204\244\354\240\225 */\n"
"    background: rgb(170, 255, 255);        /* \355\212\270\353\236\231 \353\260\260\352\262\275\354\203\211 */\n"
"    "
                        "margin: 2px 0;\n"
"}\n"
"QSlider::handle:horizontal {\n"
"    background: #5c5c5c;        /* \355\225\270\353\223\244\354\235\230 \354\203\211\354\203\201 */\n"
"    border: 1px solid #5c5c5c;\n"
"    width: 120px;                /* \355\225\270\353\223\244\354\235\230 \353\204\223\354\235\264 \354\204\244\354\240\225 */\n"
"	height:10 px;\n"
"    margin: -5px 0;             /* \355\225\270\353\223\244\354\235\230 \353\247\210\354\247\204 */\n"
"    border-radius: 5px;         /* \355\225\270\353\223\244\354\235\230 \353\252\250\354\204\234\353\246\254 \353\221\245\352\270\200\352\262\214 */\n"
"}\n"
"\n"
"/* \354\212\254\353\235\274\354\235\264\353\215\224 \355\225\270\353\223\244\354\235\204 \355\201\264\353\246\255\355\225\230\352\263\240 \354\233\200\354\247\201\354\235\274 \353\225\214\354\235\230 \354\212\244\355\203\200\354\235\274 */\n"
"QSlider::handle:horizontal:pressed {\n"
"    background: rgb(222, 222, 222);        /* \354\212\254\353\235\274\354\235\264\353\215\224\353\245\274 \354\233\200\354\247"
                        "\201\354\235\274 \353\225\214 \355\225\270\353\223\244\354\235\230 \354\203\211\354\203\201 \353\263\200\355\231\224 */\n"
"}"));
        room1Slider->setPageStep(1);
        room1Slider->setValue(0);
        room1Slider->setOrientation(Qt::Horizontal);
        room2Slider = new QSlider(ChatWindow3);
        room2Slider->setObjectName("room2Slider");
        room2Slider->setGeometry(QRect(120, 340, 241, 41));
        room2Slider->setStyleSheet(QString::fromUtf8("QSlider {\n"
"    background-color: #e0e0e0;   /* \354\212\254\353\235\274\354\235\264\353\215\224 \354\240\204\354\262\264 \353\260\260\352\262\275\354\203\211 */\n"
"    border: transparent;   /* \354\212\254\353\235\274\354\235\264\353\215\224 \355\205\214\353\221\220\353\246\254 */\n"
"    border-radius: 10px;         /* \354\212\254\353\235\274\354\235\264\353\215\224 \355\205\214\353\221\220\353\246\254\354\235\230 \353\221\245\352\267\274 \354\240\225\353\217\204 */\n"
"    padding: 5px;                /* \354\212\254\353\235\274\354\235\264\353\215\224 \353\202\264\353\266\200 \355\214\250\353\224\251 */\n"
"}\n"
"QSlider::groove:horizontal {\n"
"    border: 1px solid rgb(255, 255, 255); /* \355\212\270\353\236\231 \352\262\275\352\263\204\354\204\240 */\n"
"    height: 15px;               /* \355\212\270\353\236\231\354\235\230 \353\206\222\354\235\264 \354\204\244\354\240\225 */\n"
"    background: rgb(218, 255, 201);\n"
"    margin: 2px 0;\n"
"}\n"
"QSlider::handle:horizontal {\n"
"    background: #"
                        "5c5c5c;        /* \355\225\270\353\223\244\354\235\230 \354\203\211\354\203\201 */\n"
"    border: 1px solid #5c5c5c;\n"
"    width: 120px;                /* \355\225\270\353\223\244\354\235\230 \353\204\223\354\235\264 \354\204\244\354\240\225 */\n"
"	height:10 px;\n"
"    margin: -5px 0;             /* \355\225\270\353\223\244\354\235\230 \353\247\210\354\247\204 */\n"
"    border-radius: 5px;         /* \355\225\270\353\223\244\354\235\230 \353\252\250\354\204\234\353\246\254 \353\221\245\352\270\200\352\262\214 */\n"
"}\n"
"\n"
"/* \354\212\254\353\235\274\354\235\264\353\215\224 \355\225\270\353\223\244\354\235\204 \355\201\264\353\246\255\355\225\230\352\263\240 \354\233\200\354\247\201\354\235\274 \353\225\214\354\235\230 \354\212\244\355\203\200\354\235\274 */\n"
"QSlider::handle:horizontal:pressed {\n"
"    background: rgb(222, 222, 222);        /* \354\212\254\353\235\274\354\235\264\353\215\224\353\245\274 \354\233\200\354\247\201\354\235\274 \353\225\214 \355\225\270\353\223\244\354\235\230 \354\203"
                        "\211\354\203\201 \353\263\200\355\231\224 */\n"
"}"));
        room2Slider->setPageStep(1);
        room2Slider->setOrientation(Qt::Horizontal);
        room3Slider = new QSlider(ChatWindow3);
        room3Slider->setObjectName("room3Slider");
        room3Slider->setGeometry(QRect(120, 410, 241, 41));
        room3Slider->setStyleSheet(QString::fromUtf8("QSlider {\n"
"    background-color: #e0e0e0;   /* \354\212\254\353\235\274\354\235\264\353\215\224 \354\240\204\354\262\264 \353\260\260\352\262\275\354\203\211 */\n"
"    border: transparent;   /* \354\212\254\353\235\274\354\235\264\353\215\224 \355\205\214\353\221\220\353\246\254 */\n"
"    border-radius: 10px;         /* \354\212\254\353\235\274\354\235\264\353\215\224 \355\205\214\353\221\220\353\246\254\354\235\230 \353\221\245\352\267\274 \354\240\225\353\217\204 */\n"
"    padding: 5px;                /* \354\212\254\353\235\274\354\235\264\353\215\224 \353\202\264\353\266\200 \355\214\250\353\224\251 */\n"
"}\n"
"QSlider::groove:horizontal {\n"
"    border: 1px solid rgb(255, 255, 255); /* \355\212\270\353\236\231 \352\262\275\352\263\204\354\204\240 */\n"
"    height: 15px;               /* \355\212\270\353\236\231\354\235\230 \353\206\222\354\235\264 \354\204\244\354\240\225 */\n"
"    background: rgb(255, 223, 202);\n"
"    margin: 2px 0;\n"
"}\n"
"QSlider::handle:horizontal {\n"
"    background: #"
                        "5c5c5c;        /* \355\225\270\353\223\244\354\235\230 \354\203\211\354\203\201 */\n"
"    border: 1px solid #5c5c5c;\n"
"    width: 120px;                /* \355\225\270\353\223\244\354\235\230 \353\204\223\354\235\264 \354\204\244\354\240\225 */\n"
"	height:10 px;\n"
"    margin: -5px 0;             /* \355\225\270\353\223\244\354\235\230 \353\247\210\354\247\204 */\n"
"    border-radius: 5px;         /* \355\225\270\353\223\244\354\235\230 \353\252\250\354\204\234\353\246\254 \353\221\245\352\270\200\352\262\214 */\n"
"}\n"
"\n"
"/* \354\212\254\353\235\274\354\235\264\353\215\224 \355\225\270\353\223\244\354\235\204 \355\201\264\353\246\255\355\225\230\352\263\240 \354\233\200\354\247\201\354\235\274 \353\225\214\354\235\230 \354\212\244\355\203\200\354\235\274 */\n"
"QSlider::handle:horizontal:pressed {\n"
"    background: rgb(222, 222, 222);        /* \354\212\254\353\235\274\354\235\264\353\215\224\353\245\274 \354\233\200\354\247\201\354\235\274 \353\225\214 \355\225\270\353\223\244\354\235\230 \354\203"
                        "\211\354\203\201 \353\263\200\355\231\224 */\n"
"}"));
        room3Slider->setPageStep(1);
        room3Slider->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(ChatWindow3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 100, 131, 111));
        label_4->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-color: transparent;"));
        titleLabel_2 = new QLabel(ChatWindow3);
        titleLabel_2->setObjectName("titleLabel_2");
        titleLabel_2->setGeometry(QRect(20, 270, 101, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Quicksand Medium")});
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setItalic(false);
        titleLabel_2->setFont(font2);
        titleLabel_2->setStyleSheet(QString::fromUtf8("color: rgb(85, 85, 255);\n"
"font: 500 12pt \"Quicksand Medium\";\n"
"background-color:transparent;\n"
"border-color:transparent;"));
        titleLabel_2->setAlignment(Qt::AlignCenter);
        titleLabel_3 = new QLabel(ChatWindow3);
        titleLabel_3->setObjectName("titleLabel_3");
        titleLabel_3->setGeometry(QRect(20, 340, 101, 41));
        titleLabel_3->setFont(font2);
        titleLabel_3->setStyleSheet(QString::fromUtf8("color: rgb(85, 85, 255);\n"
"font: 500 12pt \"Quicksand Medium\";\n"
"background-color:transparent;\n"
"border-color:transparent;"));
        titleLabel_3->setAlignment(Qt::AlignCenter);
        titleLabel_4 = new QLabel(ChatWindow3);
        titleLabel_4->setObjectName("titleLabel_4");
        titleLabel_4->setGeometry(QRect(20, 410, 101, 41));
        titleLabel_4->setFont(font2);
        titleLabel_4->setStyleSheet(QString::fromUtf8("color: rgb(85, 85, 255);\n"
"font: 500 12pt \"Quicksand Medium\";\n"
"background-color:transparent;\n"
"border-color:transparent;"));
        titleLabel_4->setAlignment(Qt::AlignCenter);
        windowOpenButton = new QPushButton(ChatWindow3);
        windowOpenButton->setObjectName("windowOpenButton");
        windowOpenButton->setGeometry(QRect(210, 110, 101, 31));
        windowOpenButton->setFont(font);
        windowOpenButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
"}"));
        windowCloseButton = new QPushButton(ChatWindow3);
        windowCloseButton->setObjectName("windowCloseButton");
        windowCloseButton->setGeometry(QRect(210, 160, 101, 31));
        windowCloseButton->setFont(font);
        windowCloseButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
"}"));
        label = new QLabel(ChatWindow3);
        label->setObjectName("label");
        label->setGeometry(QRect(310, 220, 41, 41));
        label->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"border:none;"));
        label->setAlignment(Qt::AlignCenter);
        guideLabel = new QLabel(ChatWindow3);
        guideLabel->setObjectName("guideLabel");
        guideLabel->setGeometry(QRect(120, 230, 231, 21));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("URW Bookman [UKWN]")});
        font3.setPointSize(9);
        font3.setBold(true);
        font3.setItalic(true);
        guideLabel->setFont(font3);
        guideLabel->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 237, 253);\n"
"border:none;\n"
"color: rgb(255, 0, 127);\n"
"font: 500 9pt \"Quicksand Medium\";\n"
"font: 600 italic 9pt \"URW Bookman [UKWN]\";"));
        guideLabel->setAlignment(Qt::AlignCenter);
        guideLabel->raise();
        chatgroupBox->raise();
        titleLabel->raise();
        room1Slider->raise();
        room2Slider->raise();
        room3Slider->raise();
        label_4->raise();
        titleLabel_2->raise();
        titleLabel_3->raise();
        titleLabel_4->raise();
        windowOpenButton->raise();
        windowCloseButton->raise();
        exit->raise();
        exitButton->raise();
        label->raise();

        retranslateUi(ChatWindow3);

        QMetaObject::connectSlotsByName(ChatWindow3);
    } // setupUi

    void retranslateUi(QWidget *ChatWindow3)
    {
        ChatWindow3->setWindowTitle(QCoreApplication::translate("ChatWindow3", "Chat3", nullptr));
        chatgroupBox->setTitle(QString());
        sendButton->setText(QCoreApplication::translate("ChatWindow3", "Send", nullptr));
        titleLabel->setText(QCoreApplication::translate("ChatWindow3", "Window Manage Chat", nullptr));
        exitButton->setText(QString());
        exit->setText(QCoreApplication::translate("ChatWindow3", "<html><head/><body><p><img src=\":/images/exit.png\" width = \"25\" height=\"25\"/></p></body></html> ", nullptr));
        label_4->setText(QCoreApplication::translate("ChatWindow3", "<html><head/><body><p><img src=\":/images/window.png\" width=\"100\" height=\"100\"/></p></body></html>", nullptr));
        titleLabel_2->setText(QCoreApplication::translate("ChatWindow3", "Living room", nullptr));
        titleLabel_3->setText(QCoreApplication::translate("ChatWindow3", "Bed room ", nullptr));
        titleLabel_4->setText(QCoreApplication::translate("ChatWindow3", "Bath room ", nullptr));
        windowOpenButton->setText(QCoreApplication::translate("ChatWindow3", "ALL OPEN", nullptr));
        windowCloseButton->setText(QCoreApplication::translate("ChatWindow3", "ALL CLOSE", nullptr));
        label->setText(QCoreApplication::translate("ChatWindow3", "<html><head/><body><p><img src=\":/images/arrow.png\" width=\"25\" height=\"25\"/></p></body></html>", nullptr));
        guideLabel->setText(QCoreApplication::translate("ChatWindow3", "Move slider to open window       ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatWindow3: public Ui_ChatWindow3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWINDOW3_H
