#include "stats.h"
#include "ui_stats.h"
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE

stats::stats(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::stats)
{

    ui->setupUi(this);

    QBarSet *set0 = new QBarSet("Electronique") ;
    QBarSet *set1 = new QBarSet("Maison") ;
    QBarSet *set2 = new QBarSet("Fashion") ;
    QBarSet *set3 = new QBarSet("Electronique") ;

    *set0 << 10 ;
    *set1 << 12 ;
    *set2 << 4 ;
    *set3 << 8 ;

    QBarSeries *series = new QBarSeries() ;
    series->append(set0) ;
    series->append(set1) ;
    series->append(set2) ;
    series->append(set3) ;

    QChart *chart = new QChart() ;
    chart->addSeries(series) ;
    chart->setTitle("Statistiques des commandes") ;
    chart->setAnimationOptions(QChart::AllAnimations) ;
    QStringList categories ;
    categories << "Ce mois" ;
    QBarCategoryAxis *axis = new QBarCategoryAxis() ;
    axis->append(categories) ;
    chart->createDefaultAxes() ;
    chart->setAxisX(axis,series) ;
    chart->legend()->setVisible(true) ;
    chart->legend()->setAlignment(Qt::AlignBottom) ;

    QChartView *chartView = new QChartView(chart) ;
    chartView->setRenderHint(QPainter::Antialiasing) ;
    QPalette pal =  qApp->palette() ;
    pal.setColor(QPalette::Window, QRgb(0xffffff)) ;
    pal.setColor(QPalette::WindowText, QRgb(0x404040)) ;
    qApp->setPalette(pal) ;

    QMainWindow window ;
    window.setCentralWidget(chartView) ;
    window.resize(420,300) ;
    window.show() ;
}

stats::~stats()
{
    delete ui;
}
