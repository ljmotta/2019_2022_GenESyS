/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StatisticsDummyImpl.cpp
 * Author: cancian
 * 
 * Created on 23 de Agosto de 2018, 16:52
 */

#include "StatisticsDummyImpl.h"

StatisticsDummyImpl::StatisticsDummyImpl() {
}

StatisticsDummyImpl::StatisticsDummyImpl(const StatisticsDummyImpl& orig) {
}

StatisticsDummyImpl::~StatisticsDummyImpl() {
}

unsigned int StatisticsDummyImpl::numElements() {
}

double StatisticsDummyImpl::min() {
}

double StatisticsDummyImpl::max() {
}

double StatisticsDummyImpl::average() {
}

double StatisticsDummyImpl::mode() {
}

double StatisticsDummyImpl::mediane() {
}

double StatisticsDummyImpl::variance() {
}

double StatisticsDummyImpl::stddeviation() {
}

double StatisticsDummyImpl::variationCoef() {
}

double StatisticsDummyImpl::halfWidthConfidenceInterval(double confidencelevel) {
}

unsigned int StatisticsDummyImpl::newSampleSize(double confidencelevel, double halfWidth) {
}

double StatisticsDummyImpl::quartil(unsigned short num) {
}

double StatisticsDummyImpl::decil(unsigned short num) {
}

double StatisticsDummyImpl::centil(unsigned short num) {
}

void StatisticsDummyImpl::setHistogramNumClasses(unsigned short num) {
}

unsigned short StatisticsDummyImpl::histogramNumClasses() {
	return 1;
}

double StatisticsDummyImpl::histogramClassLowerLimit(unsigned short classNum) {
}

unsigned int StatisticsDummyImpl::histogramClassFrequency(unsigned short classNum) {
}

Collector_if* StatisticsDummyImpl::getCollector() {
	return this->_collector;
}

void StatisticsDummyImpl::setCollector(Collector_if* collector) {

}