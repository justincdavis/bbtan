QT += widgets
QT += multimedia

CONFIG += gui
CONFIG += c++11

SOURCES += \
    main.cpp \
    vec2d.cpp \
    graphics.cpp \
    vec3d.cpp \
    plugin.cpp \ 
<<<<<<< HEAD \
    balls.cpp
    balls.cpp
=======
    world.cpp
>>>>>>> 905ceee1805acbd2ab9d49b3bb2e0658c53a09ac

HEADERS  += \
    graphics.h \
    vec2d.h \
    graphics.h \
    window.h \
    vec3d.h \
    plugin.h \ 
<<<<<<< HEAD \
    balls.h
    balls.h
=======
    world.h
>>>>>>> 905ceee1805acbd2ab9d49b3bb2e0658c53a09ac

DISTFILES += \
    data/ShortLaser.wav \
    data/comp.png

ASSETS_DIR = data

CONFIG(debug, debug|release) {
    DATADIR = debug/$$ASSETS_DIR
} else {
    DATADIR = release/$$ASSETS_DIR
}

copydata.commands = $(COPY_DIR) \"$$shell_path($$absolute_path("$$ASSETS_DIR", $$_PRO_FILE_PWD_))\" \"$$shell_path($$absolute_path($$DATADIR, $$OUT_PWD))\"
first.depends = $(first) copydata

export(first.depends)
export(copydata.commands)

QMAKE_EXTRA_TARGETS += first copydata
