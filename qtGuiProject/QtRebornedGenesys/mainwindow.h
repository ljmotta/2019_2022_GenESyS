#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mapkernelandui.h"
#include "../../../RebornedGenESyS/Simulator.h"
#include "../../../RebornedGenESyS/Plugin.h"

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void on_actionAbout_triggered();

	void on_actionExit_triggered();

	void on_actionNew_triggered();

	void on_actionOpen_triggered();

	void on_actionClose_triggered();

	void on_actionSave_triggered();

	void on_actionSave_as_triggered();

	void on_actionUndo_triggered();

	void on_actionRedo_triggered();

	void on_actionCut_triggered();

	void on_actionCopy_triggered();

	void on_actionPaste_triggered();

	void on_actionFind_triggered();

	void on_actionReplace_triggered();

	void on_actionGroup_triggered();

	void on_actionCheck_Model_triggered();

	void on_actionStart_triggered();

	void on_actionStep_triggered();

	void on_actionStop_triggered();

	void on_actionRun_Control_triggered();

	void on_tabWidgetModels_tabBarDoubleClicked(int index);

	void on_tabWidgetModels_tabCloseRequested(int index);

	void on_tabWidgetModels_currentChanged(int index);

	void on_actionInformation_triggered();

public slots:
	void on_DialogInformation_actionAccept(); // \todo
	void on_dialogmodel_destroyed(QObject* obj);

protected:
	virtual void closeEvent(QCloseEvent *e);

private:
	Ui::MainWindow *ui;
	// dialogs


	//*******************************************
	// SIMULATOR
	//*******************************************
private:
	void _refreshActions();
	void _refreshPropertyWidget();
	void _refreshWidgets();
	void _refreshWidgetCurrentModel();
	void _createUiForNewModel(Model* newModel);
private:
	void _traceHandler(TraceEvent e);
	void _traceErrorHandler(TraceErrorEvent e);
	void _traceReportHandler(TraceEvent e);
	void _traceSimulationHandler(TraceSimulationEvent e);
	// default Event Handlers
	void _onSimulationStartHandler(SimulationEvent* re);
	void _onReplicationStartHandler(SimulationEvent* re);
	void _onProcessEventHandler(SimulationEvent* re);
	void _onReplicationEndHandler(SimulationEvent* re);
	void _onSimulationEndHandler(SimulationEvent* re);
	void _onEntityRemoveHandler(SimulationEvent* re);
private:
	void _simulationInsertPlugins();
	void __simulationInsert_FAKE_Plugins();
	void _insertPluginUI(Plugin* plugin);
private:
	Simulator* _simulator;
	MapKernelAndUI* _mapSimUI = new MapKernelAndUI();
};

#endif // MAINWINDOW_H
