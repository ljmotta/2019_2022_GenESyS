#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogabout.h"
#include "dialogmodelinformation.h"
#include "dialogsimulationmodel.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QStandardItem>
#include <QListWidget>
#include <QListWidgetItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QBrush>
#include <QTreeWidgetItem>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow) {
	ui->setupUi(this);
	connect(ui->actionAbout, SIGNAL(triggered(bool)), this, SLOT(on_actionAbout_triggered()));

	//--------------------------

	//*****************************************************************
	this->_simulator = new Simulator(); // \todo: in an advanced model, simulation could come from a socket or rest api
	TraceManager* tm = _simulator->tracer();
	tm->setTraceLevel(Util::TraceLevel::everythingMostDetailed);
	tm->addTraceHandler<MainWindow>(this, &MainWindow::_traceHandler);
	tm->addTraceReportHandler<MainWindow>(this, &MainWindow::_traceReportHandler);
	tm->addTraceSimulationHandler<MainWindow>(this, &MainWindow::_traceSimulationHandler);
	tm->addTraceErrorHandler<MainWindow>(this, &MainWindow::_traceErrorHandler);
	_simulationInsertPlugins();
	// refresh UI
	_refreshActions();
	_refreshWidgets();
	this->showMaximized();
}

MainWindow::~MainWindow() {
	delete ui;
}

//*******************************************************************
// SIMULATOR START
//*******************************************************************

void MainWindow::_insertPluginUI(Plugin* plugin) {
	if (plugin != nullptr) {
		if (plugin->isIsValidPlugin()) {
			std::string plugtext = plugin->pluginInfo()->pluginTypename();
			std::string plugtextAdds = "";
			if (plugin->pluginInfo()->isSink())
				plugtextAdds += ",Sink";
			if (plugin->pluginInfo()->isSource())
				plugtextAdds += ",Source";
			if (plugin->pluginInfo()->isReceiveTransfer())
				plugtextAdds += ",ReceiveTransfer";
			if (plugin->pluginInfo()->isSendTransfer())
				plugtextAdds += ",SendTransfer";
			if (plugtextAdds != "") {
				plugtext += " [" + plugtextAdds.erase(0, 1) + "]";
			}
			if (plugin->pluginInfo()->isComponent()) {
				QTreeWidgetItem *plugItem = new QTreeWidgetItem(ui->treeWidgetPlugins);
				plugItem->setText(1, QString::fromStdString(plugtext));
				plugItem->setIcon(0, QIcon(QPixmap("/home/rlcancian/Laboratory/Software_Lab/IA32_Architecture/GccProjects/RebornedGenESyS/RebornedGenESyS/qtGuiProject/QtRebornedGenesys/resources/plugins/default_component.bmp")));
			} else {
			}
			//new QListWidgetItem(QString::fromStdString(plugtext), ui->listWidgetPlugins);
		}
	}
}

void MainWindow::__simulationInsert_FAKE_Plugins() {
	//Util::TraceLevel tl = simulator->tracer()->traceLevel();
	//simulator->tracer()->setTraceLevel(Util::TraceLevel::debugOnly);
	PluginManager* plm = _simulator->plugins();
	_insertPluginUI(plm->insert("create.so"));
	_insertPluginUI(plm->insert("dispose.so"));
	_insertPluginUI(plm->insert("decide.so"));
	_insertPluginUI(plm->insert("batch.so"));
	_insertPluginUI(plm->insert("separate.so"));
	_insertPluginUI(plm->insert("assign.so"));
	_insertPluginUI(plm->insert("record.so"));
	_insertPluginUI(plm->insert("submodel.so"));
	_insertPluginUI(plm->insert("entitytype.so"));
	_insertPluginUI(plm->insert("entitygroup.so"));
	_insertPluginUI(plm->insert("attribute.so"));
	_insertPluginUI(plm->insert("counter.so"));
	_insertPluginUI(plm->insert("queue.so"));
	_insertPluginUI(plm->insert("set.so"));
	_insertPluginUI(plm->insert("resource.so"));
	_insertPluginUI(plm->insert("variable.so"));
	_insertPluginUI(plm->insert("schedule.so"));
	_insertPluginUI(plm->insert("entitygroup.so"));
	// arena advanced process
	_insertPluginUI(plm->insert("delay.so"));
	_insertPluginUI(plm->insert("dropoff.so"));
	_insertPluginUI(plm->insert("hold.so"));
	_insertPluginUI(plm->insert("match.so"));
	_insertPluginUI(plm->insert("pickup.so"));
	_insertPluginUI(plm->insert("read.so"));
	_insertPluginUI(plm->insert("write.so"));
	_insertPluginUI(plm->insert("release.so"));
	_insertPluginUI(plm->insert("remove.so"));
	_insertPluginUI(plm->insert("seize.so"));
	_insertPluginUI(plm->insert("search.so"));
	_insertPluginUI(plm->insert("signal.so"));
	_insertPluginUI(plm->insert("store.so"));
	_insertPluginUI(plm->insert("unstore.so"));
	_insertPluginUI(plm->insert("expression.so"));
	_insertPluginUI(plm->insert("failure.so"));
	_insertPluginUI(plm->insert("file.so"));
	_insertPluginUI(plm->insert("statisticscollector.so"));
	_insertPluginUI(plm->insert("storage.so"));
	// arena transfer station
	_insertPluginUI(plm->insert("enter.so"));
	_insertPluginUI(plm->insert("leave.so"));
	_insertPluginUI(plm->insert("pickstation.so"));
	_insertPluginUI(plm->insert("route.so"));
	_insertPluginUI(plm->insert("sequence.so"));
	_insertPluginUI(plm->insert("station.so"));
	// arena transfer conveyour
	_insertPluginUI(plm->insert("access.so"));
	_insertPluginUI(plm->insert("exit.so"));
	_insertPluginUI(plm->insert("start.so"));
	_insertPluginUI(plm->insert("stop.so"));
	_insertPluginUI(plm->insert("conveyour.so"));
	_insertPluginUI(plm->insert("segment.so"));
	// arena transfer transport
	_insertPluginUI(plm->insert("alocate.so"));
	_insertPluginUI(plm->insert("free.so"));
	_insertPluginUI(plm->insert("halt.so"));
	_insertPluginUI(plm->insert("move.so"));
	_insertPluginUI(plm->insert("request.so"));
	_insertPluginUI(plm->insert("transporter.so"));
	_insertPluginUI(plm->insert("distance.so"));
	_insertPluginUI(plm->insert("network.so"));
	_insertPluginUI(plm->insert("networklink.so"));
	// others
	_insertPluginUI(plm->insert("dummy.so"));
	_insertPluginUI(plm->insert("lsode.so"));
	_insertPluginUI(plm->insert("biochemical.so"));
	_insertPluginUI(plm->insert("markovchain.so"));
	_insertPluginUI(plm->insert("cellularautomata.so"));
	_insertPluginUI(plm->insert("cppforgenesys.so"));
	//simulator->tracer()->setTraceLevel(tl);
}

void MainWindow::_simulationInsertPlugins() {
	// TODO: Not implemented yet
	__simulationInsert_FAKE_Plugins();
}

void MainWindow::_traceHandler(TraceEvent e) {
	// TODO: -- use e.getTracelevel() to set text style (color, bold, etc)
	if (e.tracelevel() == Util::TraceLevel::errorFatal)
		ui->textEdit_Console->setTextColor(QColor::fromRgb(255, 0, 0));
	else if (e.tracelevel() == Util::TraceLevel::errorRecover)
		ui->textEdit_Console->setTextColor(QColor::fromRgb(128, 0, 0));
	else {
		unsigned short grayVal = 5 * (static_cast<unsigned int> (e.tracelevel()));
		ui->textEdit_Console->setTextColor(QColor::fromRgb(grayVal, grayVal, grayVal));
	}
	ui->textEdit_Console->append(QString::fromStdString(e.text()));
}

void MainWindow::_traceErrorHandler(TraceErrorEvent e) {
	ui->textEdit_Console->setTextColor(QColor::fromRgb(255, 0, 0));
	ui->textEdit_Console->append(QString::fromStdString(e.text()));
}

void MainWindow::_traceReportHandler(TraceEvent e) {
	ui->textEdit_Console->setTextColor(QColor::fromRgb(0, 0, 128));
	ui->textEdit_Console->append(QString::fromStdString(e.text()));
}

void MainWindow::_traceSimulationHandler(TraceSimulationEvent e) {
	if (e.tracelevel() == Util::TraceLevel::errorFatal)
		ui->textEdit_Console->setTextColor(QColor::fromRgb(255, 64, 0));
	else if (e.tracelevel() == Util::TraceLevel::errorRecover)
		ui->textEdit_Console->setTextColor(QColor::fromRgb(128, 64, 0));
	else {
		unsigned short grayVal = 5 * (static_cast<unsigned int> (e.tracelevel()));
		ui->textEdit_Console->setTextColor(QColor::fromRgb(grayVal, 128, grayVal));
	}
	ui->textEdit_Console->append(QString::fromStdString(e.text()));
}

//-----------------------------------------------------------------
// PROTECTED

void MainWindow::closeEvent(QCloseEvent *e) {
	QMessageBox::StandardButton resBtn = QMessageBox::Yes;
	if (true) {
		resBtn = QMessageBox::question(this, "Exit Application",
				tr("Really want to exit?\n"),
				QMessageBox::No | QMessageBox::Yes,
				QMessageBox::Yes);
	}
	if (resBtn == QMessageBox::No) {
		e->ignore();
	} else {
		// application will close. Iterate open models to close them before
	}
}

//-----------------------------------------------------------------
// PRIVATE

// default Event Handlers

void MainWindow::_onSimulationStartHandler(SimulationEvent* re) {

}

void MainWindow::_onReplicationStartHandler(SimulationEvent* re) {

}

void MainWindow::_onProcessEventHandler(SimulationEvent* re) {

}

void MainWindow::_onReplicationEndHandler(SimulationEvent* re) {

}

void MainWindow::_onSimulationEndHandler(SimulationEvent* re) {

}

void MainWindow::_onEntityRemoveHandler(SimulationEvent* re) {

}

void MainWindow::_refreshActions() {
	bool thereIsAtLeastOneModelOpenned = _simulator->models()->size() > 0;
	ui->actionClose->setEnabled(thereIsAtLeastOneModelOpenned);
	ui->actionSave->setEnabled(thereIsAtLeastOneModelOpenned);
	ui->actionSave_as->setEnabled(thereIsAtLeastOneModelOpenned);
	//ui->actionModels->setEnabled(thereIsAtLeastOneModelOpenned);
}

void MainWindow::_refreshPropertyWidget() {
	ui->tableWidgetProperties->insertColumn(1);
	ui->tableWidgetProperties->insertRow(1);
}

void MainWindow::_refreshWidgets() {
	bool thereIsAtLeastOneModelOpenned = _simulator->models()->size() > 0;
	ui->menuModel->setEnabled(thereIsAtLeastOneModelOpenned);
	ui->menuView->setEnabled(thereIsAtLeastOneModelOpenned);
	//ui->groupBoxModel->setEnabled(thereIsAtLeastOneModelOpenned);
	if (thereIsAtLeastOneModelOpenned) {
		_refreshWidgetCurrentModel();
	} else { // no models openned
		//ui->groupBoxModel->setTitle(tr(""));
	}
	_refreshPropertyWidget();
}

void MainWindow::_refreshWidgetCurrentModel() {
	Model* m = _simulator->models()->current();
	//ui->groupBoxModel->setTitle(QString::fromStdString(m->infos()->name()));

	/*
	Model* m = simulator->models()->current();
	ui->groupBoxModel->setTitle(QString::fromStdString(m->infos()->name()));
	//ui->

	QGraphicsScene *scene;
	QGraphicsPixmapItem *pix;
	scene = new QGraphicsScene(this);
	ui->graphicsViewModel->setScene(scene);
	//QBrush backBrush(Qt::gray);
	//scene->setBackgroundBrush(backBrush);
	//QGraphicsEllipseItem *ellipse;
	//QGraphicsRectItem *rectangle;
	//QPixmap *pix;
	//QGraphicsTextItem *text;
	//QBrush greenBrush(Qt::green);
	//QBrush blueBrush(Qt::cyan);
	//QPen outlinePen(Qt::black);
	//outlinePen.setWidth(1);

	std::list<ModelComponent*>::iterator it = m->components()->begin();
	unsigned int i=0;
	while (it != m->components()->end()) {
		//pix=new QGraphicsPixmapItem(QPixmap("./resources/plugins/default_component.bmp"));
		//scene->addItem(pix);
		pix = scene->addPixmap(QPixmap("/home/rlcancian/Laboratory/Software_Lab/IA32_Architecture/GccProjects/RebornedGenESyS/RebornedGenESyS/qtGuiProject/QtRebornedGenesys/resources/plugins/default_component.bmp"));
		pix->setFlag(QGraphicsItem::ItemIsMovable);
		pix->setToolTip(QString::fromStdString("("+(*it)->classname()+ ") " + (*it)->name()));
		pix->setOpacity(0.8);
		pix->setX(i*100);
		pix->setVisible(true);
		//pix->
		//rectangle = scene->addRect(i*200, 0, 160, 80, outlinePen, blueBrush);
		//rectangle->setAcceptTouchEvents(true);
		//rectangle->setOpacity(0.7);
		//rectangle->setToolTip(QString::fromStdString("("+(*it)->classname()+ ") " + (*it)->name()));
		//rectangle->setFlag(QGraphicsItem::ItemIsMovable);
		//
		//scene->addPixmap()
		it++;
		i++;
	}

	// addEllipse(x,y,w,h,pen,brush)
	//ellipse = scene->addEllipse(0, -100, 300, 60, outlinePen, greenBrush);
	//ellipse->setFlag(QGraphicsItem::ItemIsMovable);
	//text = scene->addText("genesys model", QFont("Arial", 12) );
	// movable text
	//text->setFlag(QGraphicsItem::ItemIsMovable);

	 */
}

//***********************************************************simulator->models()->current()********
// MAINWINDOW START
//*******************************************************************

void MainWindow::on_actionAbout_triggered() {
	DialogAbout dialog;
	dialog.setModal(true);
	dialog.exec();
}

void MainWindow::on_actionExit_triggered() {
	this->close();
}

void MainWindow::_createUiForNewModel(Model* newModel) {
	DialogSimulationModel* dialog = new DialogSimulationModel(newModel);
	_mapSimUI->map(newModel, dialog);
	connect(dialog, &DialogSimulationModel::destroyed, this, &MainWindow::on_dialogmodel_destroyed);
	ui->mdiArea->addSubWindow(dialog);
	dialog->showMaximized();
	dialog->setVisible(true);
}

void MainWindow::on_actionNew_triggered() {
	Model* newModel = new Model(_simulator);
	_simulator->models()->insert(newModel);
	_createUiForNewModel(newModel);
	_refreshActions();
	_refreshWidgets();
}

void MainWindow::on_actionOpen_triggered() {
	QString fileName = QFileDialog::getOpenFileName(this,
			tr("Open Simulation Model"), "../RebornedGenESyS/temp/",
			tr("Genesys Simulation Model (*.gsm);;All Files (*)"));
	if (fileName.isEmpty())
		return;
	else {
		QFile file(fileName);
		if (!file.open(QIODevice::ReadOnly)) {
			QMessageBox::information(this, tr("Unable to open file"),
					file.errorString());
			return;
		}
		bool loaded = _simulator->models()->loadModel(fileName.toStdString());
		if (loaded) {
			_createUiForNewModel(_simulator->models()->current());
			_refreshActions();
			_refreshWidgets();
		}
	}
}

void MainWindow::on_actionClose_triggered() {
	Model* m = _simulator->models()->current();
	// find the ui of that model
	DialogSimulationModel* dialog = dynamic_cast<DialogSimulationModel*> (_mapSimUI->getUI(m));
	//_simulator->models()->remove(m);
	dialog->close();
	//
	_refreshWidgets();
}

void MainWindow::on_actionSave_triggered() {
	QString fileName = QFileDialog::getSaveFileName(this,
			tr("Save Simulation Model"), "",
			tr("Genesys Simulation Model (*.gsm);;All Files (*)"));
	if (fileName.isEmpty())
		return;
	else {
		QFile file(fileName);
		if (!file.open(QIODevice::WriteOnly)) {
			QMessageBox::information(this, tr("Unable to open file"),
					file.errorString());
			return;
		}
		//QDataStream out(&file);
		//out.setVersion(QDataStream::Qt_4_5);
		//out << contacts;
	}
}

void MainWindow::on_actionSave_as_triggered() {

}

void MainWindow::on_actionUndo_triggered() {

}

void MainWindow::on_actionRedo_triggered() {

}

void MainWindow::on_actionCut_triggered() {

}

void MainWindow::on_actionCopy_triggered() {

}

void MainWindow::on_actionPaste_triggered() {

}

void MainWindow::on_actionFind_triggered() {

}

void MainWindow::on_actionReplace_triggered() {

}

void MainWindow::on_actionGroup_triggered() {

}

void MainWindow::on_actionCheck_Model_triggered() {
	bool res = _simulator->models()->current()->check();
	if (res)
		QMessageBox::information(this, "Check", "Model check passed", QMessageBox::Ok);
	else
		QMessageBox::warning(this, "Check", "Model check failed", QMessageBox::Ok);
}

void MainWindow::on_actionStart_triggered() {
	_simulator->models()->current()->simulation()->start();
}

void MainWindow::on_actionStep_triggered() {
	_simulator->models()->current()->simulation()->step();
}

void MainWindow::on_actionStop_triggered() {
	_simulator->models()->current()->simulation()->stop();
}

void MainWindow::on_actionRun_Control_triggered() {

}

void MainWindow::on_tabWidgetModels_tabBarDoubleClicked(int index) {

}

void MainWindow::on_tabWidgetModels_tabCloseRequested(int index) {

}

void MainWindow::on_tabWidgetModels_currentChanged(int index) {

}

void MainWindow::on_actionInformation_triggered() {
	DialogModelInformation dialog;
	dialog.setModal(true);
	ModelInfo* infos = _simulator->models()->current()->infos();
	dialog.setModelMVC(infos);
	if (dialog.exec() == dialog.Accepted) {
		ModelInfo ret = dialog.getModelMVC();
		//general
		infos->setAnalystName(ret.analystName());
		infos->setDescription(ret.description());
		infos->setName(ret.name());
		infos->setProjectTitle(ret.projectTitle());
		infos->setVersion(ret.version());
		//simulation
		infos->setNumberOfReplications(ret.numberOfReplications());
		infos->setReplicationLength(ret.replicationLength());
		infos->setReplicationLengthTimeUnit(ret.replicationLengthTimeUnit());
		infos->setWarmUpPeriod(ret.warmUpPeriod());
		infos->setWarmUpPeriodTimeUnit(ret.warmUpPeriodTimeUnit());
	}
}

//************************************************************************

void MainWindow::on_DialogInformation_actionAccept() {

}

void MainWindow::on_dialogmodel_destroyed(QObject* obj) {
	std::cout << "Executando close";
}
