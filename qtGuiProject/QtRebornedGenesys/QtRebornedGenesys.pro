#-------------------------------------------------
#
# Project created by QtCreator 2019-11-05T22:56:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtRebornedGenesys
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
        ../../../RebornedGenESyS/Attribute.cpp \
        ../../../RebornedGenESyS/Assign.cpp \
        ../../../RebornedGenESyS/CollectorDefaultImpl1.cpp \
        ../../../RebornedGenESyS/ComponentManager.cpp \
        ../../../RebornedGenESyS/ConnectionManager.cpp \
        ../../../RebornedGenESyS/Counter.cpp \
        ../../../RebornedGenESyS/Create.cpp \
        ../../../RebornedGenESyS/Decide.cpp \
        ../../../RebornedGenESyS/Delay.cpp \
        ../../../RebornedGenESyS/Dispose.cpp \
        ../../../RebornedGenESyS/Dummy.cpp \
        ../../../RebornedGenESyS/ElementManager.cpp \
        ../../../RebornedGenESyS/Enter.cpp \
        ../../../RebornedGenESyS/Entity.cpp \
        ../../../RebornedGenESyS/EntityGroup.cpp \
        ../../../RebornedGenESyS/EntityType.cpp \
        ../../../RebornedGenESyS/Event.cpp \
        ../../../RebornedGenESyS/FitterDefaultImpl1.cpp \
        ../../../RebornedGenESyS/Formula.cpp \
        ../../../RebornedGenESyS/Leave.cpp \
        ../../../RebornedGenESyS/LicenceManager.cpp \
        ../../../RebornedGenESyS/LSODE.cpp \
        ../../../RebornedGenESyS/MarkovChain.cpp \
        ../../../RebornedGenESyS/Model.cpp \
        ../../../RebornedGenESyS/ModelCheckerDefaultImpl1.cpp \
        ../../../RebornedGenESyS/ModelComponent.cpp \
        ../../../RebornedGenESyS/ModelElement.cpp \
        ../../../RebornedGenESyS/ModelInfo.cpp \
        ../../../RebornedGenESyS/ModelManager.cpp \
        ../../../RebornedGenESyS/ModelPersistenceDefaultImpl1.cpp \
        ../../../RebornedGenESyS/ModelSimulation.cpp \
        ../../../RebornedGenESyS/OLD_ODEelement.cpp \
        ../../../RebornedGenESyS/OnEventManager.cpp \
        ../../../RebornedGenESyS/ParserChangesInformation.cpp \
        ../../../RebornedGenESyS/ProcessAnalyserDefaultImpl1.cpp \
        ../../../RebornedGenESyS/Plugin.cpp \
        ../../../RebornedGenESyS/PluginInformation.cpp \
        ../../../RebornedGenESyS/PluginManager.cpp \
        ../../../RebornedGenESyS/PluginConnectorDummyImpl1.cpp \
        ../../../RebornedGenESyS/Queue.cpp \
        ../../../RebornedGenESyS/Record.cpp \
        ../../../RebornedGenESyS/Release.cpp \
        ../../../RebornedGenESyS/Resource.cpp \
        ../../../RebornedGenESyS/Route.cpp \
        ../../../RebornedGenESyS/SamplerDefaultImpl1.cpp \
        ../../../RebornedGenESyS/Seize.cpp \
        ../../../RebornedGenESyS/Set.cpp \
        ../../../RebornedGenESyS/Simulator.cpp \
        ../../../RebornedGenESyS/SimulationControl.cpp \
        ../../../RebornedGenESyS/SimulationResponse.cpp \
        ../../../RebornedGenESyS/SimulationReporterDefaultImpl1.cpp \
        ../../../RebornedGenESyS/SinkModelComponent.cpp \
        ../../../RebornedGenESyS/SourceModelComponent.cpp \
        ../../../RebornedGenESyS/Station.cpp \
        ../../../RebornedGenESyS/StatisticsDefaultImpl1.cpp \
        ../../../RebornedGenESyS/StatisticsCollector.cpp \
        ../../../RebornedGenESyS/ToolManager.cpp \
        ../../../RebornedGenESyS/TraceManager.cpp \
        ../../../RebornedGenESyS/Util.cpp \
        ../../../RebornedGenESyS/Variable.cpp \
        ../../../RebornedGenESyS/Write.cpp \
        ../../../RebornedGenESyS/parserBisonFlex/ParserDefaultImpl2.cpp \
        ../../../RebornedGenESyS/parserBisonFlex/Genesys++-driver.cpp \
        ../../../RebornedGenESyS/parserBisonFlex/Genesys++-scanner.cpp \
        ../../../RebornedGenESyS/parserBisonFlex/GenesysParser.cpp \
        ../../../RebornedGenESyS/parserBisonFlex/obj_t.cpp \
        mainwindow.cpp \
    dialogabout.cpp \
    mapkernelandui.cpp \
    dialogmodelinformation.cpp

HEADERS += \
        mainwindow.h \
        ../../../RebornedGenESyS/Plugin.h \
        ../../../RebornedGenESyS/Util.h \
        ../../../RebornedGenESyS/List.h \
        ../../../RebornedGenESyS/TraceManager.h \
        ../../../RebornedGenESyS/Traits.h \
        ../../../RebornedGenESyS/parserBisonFlex/position.hh \
        ../../../RebornedGenESyS/parserBisonFlex/stack.hh \
    dialogabout.h \
    mapkernelandui.h \
    dialogmodelinformation.h

FORMS += \
        mainwindow.ui \
    dialogabout.ui \
    dialogmodelinformation.ui

RESOURCES += \
    resources.qrc
