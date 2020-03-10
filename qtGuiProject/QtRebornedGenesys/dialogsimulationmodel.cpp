#include "dialogsimulationmodel.h"
#include "ui_dialogsimulationmodel.h"
#include "graphicalmodelcomponent.h"
#include <iostream>
#include <QMessageBox>
#include <QCloseEvent>
#include <QGraphicsScene>
#include <QBrush>

DialogSimulationModel::DialogSimulationModel(Model* model, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DialogSimulationModel)
{
	_model = model;
	// build global
	ui->setupUi(this);
	this->setWindowTitle(QString::fromStdString(_model->infos()->name()));

	// build graphic model
	QGraphicsScene* modelScene = new QGraphicsScene();
	ui->graphicsViewModel->setScene(modelScene);
	ui->graphicsViewModel->setMouseTracking(true);
	QBrush background;
	background.setColor(Qt::green);
	background.setStyle(Qt::CrossPattern);
	modelScene->setBackgroundBrush(background);
	//connect(modelScene, SIGNAL())
	// build graphical model components
	ComponentManager* cm = _model->components();
	ElementManager* em = _model->elements();
	for (std::list<ModelComponent*>::iterator it = cm->begin(); it!= cm->end(); it++) {
		ModelComponent* comp = (*it);
		GraphicalModelComponent* graphComp = new GraphicalModelComponent(comp);
		//_mapSimUI->map(comp, graphComp);
		_mapSimUI->map(dynamic_cast<ModelElement*>(comp), dynamic_cast<QGraphicsItem*>(graphComp));
		modelScene->addItem(graphComp);
	}

	// build blocks
	ui->labelNumberOfComponents->setText(QString::number(cm->numberOfComponents()));
	ui->labelNumberOfElements->setText(QString::number(em->numberOfElements()));
	// build trace
	// build results
}

DialogSimulationModel::~DialogSimulationModel()
{
	delete ui;
}

void DialogSimulationModel::_on_graphicalmodelScene_mousemove(QMouseEvent *event)
{

}

void DialogSimulationModel::closeEvent(QCloseEvent *e) {
	QMessageBox::StandardButton resBtn = QMessageBox::Yes;
	if (true || _model->hasChanged()) {
		resBtn = QMessageBox::question( this, "Close Model",
										tr("Model has changed. Close anyway?\n"),
										QMessageBox::No | QMessageBox::Yes,
										QMessageBox::Yes);
	}
	if (resBtn == QMessageBox::No) {
		e->ignore();
	}
}

void DialogSimulationModel::_on_reject() {
}


void DialogSimulationModel::on_horizontalSliderZoom_valueChanged(int value)
{
	static int oldvalue = 100;
	float relation = (value*1.0)/(oldvalue*1.0);
	oldvalue = value;
	ui->graphicsViewModel->scale(relation, relation);
}
