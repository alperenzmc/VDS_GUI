QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Client/guiinterface.cpp \
    Client/tcpclient.cpp \
    Client/udpclient.cpp \
    Server/mythread.cpp \
    Server/tcpserver.cpp \
    Server/udpserver.cpp \
    VDP_Simulator/configuration.cpp \
    VDP_Simulator/mainwindow.cpp \
    VDP_Simulator/visualizevdp.cpp \
    main.cpp \
    yaml/src/binary.cpp \
    yaml/src/contrib/graphbuilder.cpp \
    yaml/src/contrib/graphbuilderadapter.cpp \
    yaml/src/convert.cpp \
    yaml/src/depthguard.cpp \
    yaml/src/directives.cpp \
    yaml/src/emit.cpp \
    yaml/src/emitfromevents.cpp \
    yaml/src/emitter.cpp \
    yaml/src/emitterstate.cpp \
    yaml/src/emitterutils.cpp \
    yaml/src/exceptions.cpp \
    yaml/src/exp.cpp \
    yaml/src/memory.cpp \
    yaml/src/node.cpp \
    yaml/src/node_data.cpp \
    yaml/src/nodebuilder.cpp \
    yaml/src/nodeevents.cpp \
    yaml/src/null.cpp \
    yaml/src/ostream_wrapper.cpp \
    yaml/src/parse.cpp \
    yaml/src/parser.cpp \
    yaml/src/regex_yaml.cpp \
    yaml/src/scanner.cpp \
    yaml/src/scanscalar.cpp \
    yaml/src/scantag.cpp \
    yaml/src/scantoken.cpp \
    yaml/src/simplekey.cpp \
    yaml/src/singledocparser.cpp \
    yaml/src/stream.cpp \
    yaml/src/tag.cpp



HEADERS += \
    Client/guiinterface.h \
    Client/tcpclient.h \
    Client/udpclient.h \
    Server/mythread.h \
    Server/tcpserver.h \
    Server/udpserver.h \
    VDP_Simulator/configuration.h \
    VDP_Simulator/mainwindow.h \
    VDP_Simulator/visualizevdp.h \ \ \
    yaml/include/yaml-cpp/anchor.h \
    yaml/include/yaml-cpp/binary.h \
    yaml/include/yaml-cpp/contrib/anchordict.h \
    yaml/include/yaml-cpp/contrib/graphbuilder.h \
    yaml/include/yaml-cpp/depthguard.h \
    yaml/include/yaml-cpp/dll.h \
    yaml/include/yaml-cpp/emitfromevents.h \
    yaml/include/yaml-cpp/emitter.h \
    yaml/include/yaml-cpp/emitterdef.h \
    yaml/include/yaml-cpp/emittermanip.h \
    yaml/include/yaml-cpp/emitterstyle.h \
    yaml/include/yaml-cpp/eventhandler.h \
    yaml/include/yaml-cpp/exceptions.h \
    yaml/include/yaml-cpp/mark.h \
    yaml/include/yaml-cpp/node/convert.h \
    yaml/include/yaml-cpp/node/detail/impl.h \
    yaml/include/yaml-cpp/node/detail/iterator.h \
    yaml/include/yaml-cpp/node/detail/iterator_fwd.h \
    yaml/include/yaml-cpp/node/detail/memory.h \
    yaml/include/yaml-cpp/node/detail/node.h \
    yaml/include/yaml-cpp/node/detail/node_data.h \
    yaml/include/yaml-cpp/node/detail/node_iterator.h \
    yaml/include/yaml-cpp/node/detail/node_ref.h \
    yaml/include/yaml-cpp/node/emit.h \
    yaml/include/yaml-cpp/node/impl.h \
    yaml/include/yaml-cpp/node/iterator.h \
    yaml/include/yaml-cpp/node/node.h \
    yaml/include/yaml-cpp/node/parse.h \
    yaml/include/yaml-cpp/node/ptr.h \
    yaml/include/yaml-cpp/node/type.h \
    yaml/include/yaml-cpp/noexcept.h \
    yaml/include/yaml-cpp/null.h \
    yaml/include/yaml-cpp/ostream_wrapper.h \
    yaml/include/yaml-cpp/parser.h \
    yaml/include/yaml-cpp/stlemitter.h \
    yaml/include/yaml-cpp/traits.h \
    yaml/include/yaml-cpp/yaml.h \
    yaml/src/collectionstack.h \
    yaml/src/contrib/graphbuilderadapter.h \
    yaml/src/directives.h \
    yaml/src/emitterstate.h \
    yaml/src/emitterutils.h \
    yaml/src/exp.h \
    yaml/src/indentation.h \
    yaml/src/nodebuilder.h \
    yaml/src/nodeevents.h \
    yaml/src/ptr_vector.h \
    yaml/src/regex_yaml.h \
    yaml/src/regeximpl.h \
    yaml/src/scanner.h \
    yaml/src/scanscalar.h \
    yaml/src/scantag.h \
    yaml/src/setting.h \
    yaml/src/singledocparser.h \
    yaml/src/stream.h \
    yaml/src/streamcharsource.h \
    yaml/src/stringsource.h \
    yaml/src/tag.h \
    yaml/src/token.h


INCLUDEPATH += \
    yaml/include \
    yaml/src


FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    config_files/config.yaml \
    yaml-cpp/src/contrib/yaml-cpp.natvis \
    yaml-cpp/src/contrib/yaml-cpp.natvis.md \
    yaml/src/contrib/yaml-cpp.natvis \
    yaml/src/contrib/yaml-cpp.natvis.md
