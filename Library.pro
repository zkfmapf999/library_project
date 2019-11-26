#-------------------------------------------------
#
# Project created by QtCreator 2019-09-23T00:37:15
#
#-------------------------------------------------

QT       += core gui sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RC_FILE = icon.rc
TARGET = Library
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        sign_up.cpp \
    main_view.cpp \
    join_view.cpp \
    library_list.cpp \
    mysql.cpp \
    library_find.cpp \
    main_view_2.cpp \
    secound_floor.cpp \
    library_seat.cpp \
    library_find_2.cpp \
    myinfo.cpp \
    seeboard.cpp \
    seeboardwrite.cpp \
    seeplus.cpp \
    library_find_3.cpp \
    library_recommand.cpp \
    library_admin.cpp

HEADERS += \
        sign_up.h \
    main_view.h \
    header.h \
    join_view.h \
    library_list.h \
    mysql.h \
    library_find.h \
    main_view_2.h \
    secound_floor.h \
    library_seat.h \
    library_find_2.h \
    myinfo.h \
    seeboard.h \
    seeboardwrite.h \
    seeplus.h \
    library_find_3.h \
    library_recommand.h \
    library_admin.h

FORMS += \
        sign_up.ui \
    main_view.ui \
    join_view.ui \
    library_list.ui \
    library_find.ui \
    main_view_2.ui \
    secound_floor.ui \
    library_seat.ui \
    library_find_2.ui \
    myinfo.ui \
    seeboard.ui \
    seeboardwrite.ui \
    seeplus.ui \
    library_find_3.ui \
    library_recommand.ui \
    library_admin.ui

RESOURCES += \
    resource.qrc
