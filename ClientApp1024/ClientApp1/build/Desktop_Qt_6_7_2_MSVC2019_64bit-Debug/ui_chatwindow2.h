/********************************************************************************
** Form generated from reading UI file 'chatwindow2.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWINDOW2_H
#define UI_CHATWINDOW2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWindow2
{
public:
    QGroupBox *chatgroupBox;
    QLineEdit *messageInput;
    QPushButton *sendButton;
    QTextEdit *messageDisplay;
    QLabel *titleLabel;
    QLabel *label;
    QPushButton *exitButton;
    QLabel *exit;
    QPushButton *tvonButton;
    QPushButton *tvoffButton;
    QSpinBox *channelBox;
    QLabel *channelLabel;
    QSlider *soundSlider;
    QLabel *soundLabel;
    QFrame *tvDisplay;

    void setupUi(QWidget *ChatWindow2)
    {
        if (ChatWindow2->objectName().isEmpty())
            ChatWindow2->setObjectName("ChatWindow2");
        ChatWindow2->resize(720, 480);
        ChatWindow2->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);\n"
"border: 1px solid black;\n"
"border-color: rgb(0, 0, 0);"));
        chatgroupBox = new QGroupBox(ChatWindow2);
        chatgroupBox->setObjectName("chatgroupBox");
        chatgroupBox->setGeometry(QRect(380, 70, 311, 391));
        chatgroupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 251, 202);\n"
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
        titleLabel = new QLabel(ChatWindow2);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(140, 10, 441, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Quicksand Medium")});
        font1.setPointSize(20);
        font1.setWeight(QFont::Medium);
        font1.setItalic(false);
        titleLabel->setFont(font1);
        titleLabel->setStyleSheet(QString::fromUtf8("color: rgb(85, 85, 255);\n"
"font: 500 20pt \"Quicksand Medium\";\n"
"background-color:rgb(240, 240, 240);\n"
"border-color:transparent;"));
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label = new QLabel(ChatWindow2);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 120, 251, 191));
        label->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-color:transparent;"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        exitButton = new QPushButton(ChatWindow2);
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
        exit = new QLabel(ChatWindow2);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(10, 10, 31, 31));
        exit->setStyleSheet(QString::fromUtf8("background-color:  rgb(255, 255, 255);\n"
"border:none;"));
        exit->setAlignment(Qt::AlignmentFlag::AlignCenter);
        tvonButton = new QPushButton(ChatWindow2);
        tvonButton->setObjectName("tvonButton");
        tvonButton->setGeometry(QRect(80, 90, 101, 31));
        tvonButton->setFont(font);
        tvonButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        tvoffButton = new QPushButton(ChatWindow2);
        tvoffButton->setObjectName("tvoffButton");
        tvoffButton->setGeometry(QRect(210, 90, 101, 31));
        tvoffButton->setFont(font);
        tvoffButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        channelBox = new QSpinBox(ChatWindow2);
        channelBox->setObjectName("channelBox");
        channelBox->setGeometry(QRect(170, 340, 131, 31));
        channelBox->setStyleSheet(QString::fromUtf8("/* QSpinBox \352\270\260\353\263\270 \354\212\244\355\203\200\354\235\274 - \355\214\214\354\212\244\355\205\224 \355\206\244 */\n"
"QSpinBox {\n"
"    background-color: #fce4ec;  /* \353\266\200\353\223\234\353\237\254\354\232\264 \355\225\221\355\201\254\354\203\211 \353\260\260\352\262\275 */\n"
"    border: 1px solid #f8bbd0;  /* \354\227\260\355\225\234 \355\225\221\355\201\254 \355\205\214\353\221\220\353\246\254 */\n"
"    border-radius: 5px;         /* \355\205\214\353\221\220\353\246\254 \353\221\245\352\270\200\352\262\214 */\n"
"    padding: 2px;\n"
"    color: #6a1b9a;             /* \355\205\215\354\212\244\355\212\270 \354\203\211\354\203\201 - \353\266\200\353\223\234\353\237\254\354\232\264 \353\263\264\353\235\274\354\203\211 */\n"
"    font: bold 12px;            /* \355\205\215\354\212\244\355\212\270 \352\265\265\352\262\214 */\n"
"}\n"
"\n"
"/* QSpinBox\354\235\230 \354\234\204/\354\225\204\353\236\230 \353\262\204\355\212\274(\355\231\224\354\202\264\355\221\234) \354\212\244\355\203\200\354"
                        "\235\274 */\n"
"QSpinBox::up-button, QSpinBox::down-button {\n"
"    background-color: #f8bbd0;  /* \353\262\204\355\212\274\354\235\230 \352\270\260\353\263\270 \353\260\260\352\262\275\354\203\211 - \354\227\260\355\225\234 \355\225\221\355\201\254 */\n"
"    border: none;               /* \353\262\204\355\212\274 \352\262\275\352\263\204\354\204\240 \354\240\234\352\261\260 */\n"
"    width: 16px;                /* \353\262\204\355\212\274 \353\204\223\354\235\264 \354\204\244\354\240\225 */\n"
"}\n"
"\n"
"QSpinBox::up-arrow, QSpinBox::down-arrow {\n"
"    width: 8px;                 /* \355\231\224\354\202\264\355\221\234 \355\201\254\352\270\260 */\n"
"    height: 8px;\n"
"    image: url(arrow.png);      /* \355\231\224\354\202\264\355\221\234 \354\235\264\353\257\270\354\247\200 \354\204\244\354\240\225 \352\260\200\353\212\245 */\n"
"}\n"
"\n"
"/* \353\247\210\354\232\260\354\212\244\353\245\274 \353\262\204\355\212\274\354\227\220 \354\230\254\353\240\270\354\235\204 \353\225\214 \354\203\211\354\203\201"
                        " \353\263\200\355\231\224 */\n"
"QSpinBox::up-button:hover, QSpinBox::down-button:hover {\n"
"    background-color: #c5cae9;  /* \353\247\210\354\232\260\354\212\244 \354\230\244\353\262\204 \354\213\234 \354\227\260\355\225\234 \355\214\214\353\236\200\354\203\211\354\234\274\353\241\234 \353\263\200\352\262\275 */\n"
"}\n"
"\n"
"/* QSpinBox\354\235\230 \354\236\205\353\240\245 \355\225\204\353\223\234(\355\205\215\354\212\244\355\212\270 \355\221\234\354\213\234 \354\230\201\354\227\255) \354\212\244\355\203\200\354\235\274 */\n"
"QSpinBox::editable {\n"
"    background-color: #f3e5f5;  /* \354\236\205\353\240\245 \355\225\204\353\223\234 \353\260\260\352\262\275\354\203\211 - \354\227\260\355\225\234 \353\263\264\353\235\274\354\203\211 */\n"
"    color: #6a1b9a;             /* \355\205\215\354\212\244\355\212\270 \354\203\211\354\203\201 */\n"
"}\n"
"\n"
"/* \354\212\244\355\225\200\353\260\225\354\212\244 \353\262\204\355\212\274 \355\201\264\353\246\255 \354\213\234\354\235\230 \354\203\211\354\203\201 \353"
                        "\263\200\355\231\224 */\n"
"QSpinBox::up-button:pressed, QSpinBox::down-button:pressed {\n"
"    background-color: #b39ddb;  /* \355\201\264\353\246\255 \354\213\234 \354\247\204\355\225\234 \353\263\264\353\235\274\354\203\211\354\234\274\353\241\234 \353\263\200\352\262\275 */\n"
"}\n"
""));
        channelBox->setMaximum(5);
        channelLabel = new QLabel(ChatWindow2);
        channelLabel->setObjectName("channelLabel");
        channelLabel->setGeometry(QRect(60, 340, 111, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Quicksand Medium")});
        font2.setPointSize(12);
        font2.setWeight(QFont::Medium);
        font2.setItalic(false);
        channelLabel->setFont(font2);
        channelLabel->setStyleSheet(QString::fromUtf8("color: rgb(85, 85, 255);\n"
"font: 500 12pt \"Quicksand Medium\";\n"
"background-color:transparent;\n"
"border-color:transparent;"));
        channelLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        soundSlider = new QSlider(ChatWindow2);
        soundSlider->setObjectName("soundSlider");
        soundSlider->setGeometry(QRect(170, 390, 131, 31));
        soundSlider->setStyleSheet(QString::fromUtf8("QSlider {\n"
"    background-color: #e0e0e0;   /* \354\212\254\353\235\274\354\235\264\353\215\224 \354\240\204\354\262\264 \353\260\260\352\262\275\354\203\211 */\n"
"    border: transparent;   /* \354\212\254\353\235\274\354\235\264\353\215\224 \355\205\214\353\221\220\353\246\254 */\n"
"    border-radius: 5px;         /* \354\212\254\353\235\274\354\235\264\353\215\224 \355\205\214\353\221\220\353\246\254\354\235\230 \353\221\245\352\267\274 \354\240\225\353\217\204 */\n"
"    padding: 3px;                /* \354\212\254\353\235\274\354\235\264\353\215\224 \353\202\264\353\266\200 \355\214\250\353\224\251 */\n"
"}\n"
"QSlider::groove:horizontal {\n"
"    border: 0px solid rgb(255, 255, 255); /* \355\212\270\353\236\231 \352\262\275\352\263\204\354\204\240 */\n"
"    height: 10px;               /* \355\212\270\353\236\231\354\235\230 \353\206\222\354\235\264 \354\204\244\354\240\225 */\n"
"    background: rgb(72, 72, 72);     /* \355\212\270\353\236\231 \353\260\260\352\262\275\354\203\211 */\n"
"    margin:"
                        " 1px 0;\n"
"}\n"
"QSlider::handle:horizontal {\n"
"    background: rgb(255, 255, 127);      /* \355\225\270\353\223\244\354\235\230 \354\203\211\354\203\201 */\n"
"    border: 2px solid #5c5c5c;\n"
"    width: 15px;                /* \355\225\270\353\223\244\354\235\230 \353\204\223\354\235\264 \354\204\244\354\240\225 */\n"
"	height:10 px;\n"
"    margin: -5px 0;             /* \355\225\270\353\223\244\354\235\230 \353\247\210\354\247\204 */\n"
"    border-radius: 5px;         /* \355\225\270\353\223\244\354\235\230 \353\252\250\354\204\234\353\246\254 \353\221\245\352\270\200\352\262\214 */\n"
"}\n"
"\n"
"/* \354\212\254\353\235\274\354\235\264\353\215\224 \355\225\270\353\223\244\354\235\204 \355\201\264\353\246\255\355\225\230\352\263\240 \354\233\200\354\247\201\354\235\274 \353\225\214\354\235\230 \354\212\244\355\203\200\354\235\274 */\n"
"QSlider::handle:horizontal:pressed {\n"
"    background: rgb(209, 198, 255) ;     /* \354\212\254\353\235\274\354\235\264\353\215\224\353\245\274 \354\233\200\354\247"
                        "\201\354\235\274 \353\225\214 \355\225\270\353\223\244\354\235\230 \354\203\211\354\203\201 \353\263\200\355\231\224 */\n"
"}"));
        soundSlider->setMaximum(100);
        soundSlider->setSingleStep(5);
        soundSlider->setPageStep(5);
        soundSlider->setValue(37);
        soundSlider->setOrientation(Qt::Orientation::Horizontal);
        soundSlider->setTickPosition(QSlider::TickPosition::TicksBelow);
        soundSlider->setTickInterval(10);
        soundLabel = new QLabel(ChatWindow2);
        soundLabel->setObjectName("soundLabel");
        soundLabel->setGeometry(QRect(70, 390, 101, 31));
        soundLabel->setFont(font2);
        soundLabel->setStyleSheet(QString::fromUtf8("color: rgb(85, 85, 255);\n"
"font: 500 12pt \"Quicksand Medium\";\n"
"background-color:transparent;\n"
"border-color:transparent;"));
        soundLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        tvDisplay = new QFrame(ChatWindow2);
        tvDisplay->setObjectName("tvDisplay");
        tvDisplay->setGeometry(QRect(90, 140, 211, 141));
        tvDisplay->setStyleSheet(QString::fromUtf8("background-color: rgba(110,110,110,0.5);\n"
"border:none;"));
        tvDisplay->setFrameShape(QFrame::Shape::StyledPanel);
        tvDisplay->setFrameShadow(QFrame::Shadow::Raised);
        chatgroupBox->raise();
        titleLabel->raise();
        label->raise();
        exit->raise();
        exitButton->raise();
        tvonButton->raise();
        tvoffButton->raise();
        channelBox->raise();
        channelLabel->raise();
        soundSlider->raise();
        soundLabel->raise();
        tvDisplay->raise();

        retranslateUi(ChatWindow2);

        QMetaObject::connectSlotsByName(ChatWindow2);
    } // setupUi

    void retranslateUi(QWidget *ChatWindow2)
    {
        ChatWindow2->setWindowTitle(QCoreApplication::translate("ChatWindow2", "Chat2", nullptr));
        chatgroupBox->setTitle(QString());
        sendButton->setText(QCoreApplication::translate("ChatWindow2", "Send", nullptr));
        titleLabel->setText(QCoreApplication::translate("ChatWindow2", "TV Manage Chat", nullptr));
        label->setText(QCoreApplication::translate("ChatWindow2", "<html><head/><body><p><img src=\":/images/tvon.png\" width=\"200\" height=\"200\"/></p></body></html>", nullptr));
        exitButton->setText(QString());
        exit->setText(QCoreApplication::translate("ChatWindow2", "<html><head/><body><p><img src=\":/images/exit.png\" width = \"25\" height=\"25\"/></p></body></html> ", nullptr));
        tvonButton->setText(QCoreApplication::translate("ChatWindow2", "ON", nullptr));
        tvoffButton->setText(QCoreApplication::translate("ChatWindow2", "OFF", nullptr));
        channelLabel->setText(QCoreApplication::translate("ChatWindow2", "Platform", nullptr));
        soundLabel->setText(QCoreApplication::translate("ChatWindow2", "Sound", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatWindow2: public Ui_ChatWindow2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWINDOW2_H
