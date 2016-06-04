QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Puzzle_15
TEMPLATE = app


SOURCES += main.cpp\
           mainwindow.cpp \
           form.cpp \
           Game.cpp


HEADERS  += mainwindow.h \
            form.h \
            Game.h \


FORMS    += mainwindow.ui \
            form.ui

RESOURCES += \
            sprite.qrc

SUBDIRS += \
           Game_test.pro
