#include "mainwindow.h"
#include "ui_mainwindow.h"

QPoint center;
int r = 30, vx = 3, vy = 3;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(1200, 600));
    this->statusBar()->setSizeGripEnabled(false);
    center.setX(width() / 2);
    center.setY(height() / 2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter;
    QPen pen;
    QBrush brush;
    brush.setColor(Qt::black);
    brush.setStyle(Qt::SolidPattern);
    pen.setColor(Qt::white);

    painter.begin(this);

    painter.setBrush(brush);
    painter.drawRect(0,0, width(), height());
    painter.setPen(pen);
    painter.drawEllipse(center, r, r);

    QThread::msleep(1);

    center.rx()+=vx;
    center.ry()+=vy;

    if ((center.x() <= r) || (center.x() >= width() - r)) vx = -vx;
    if ((center.y() <= r) || (center.y() >= height() - r)) vy = -vy;
    update();

    painter.end();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape) this->close();
}
