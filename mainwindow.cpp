#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800,600);
    initUI();
    connect(spinFontSize,SIGNAL(valueChanged(int)),this,SLOT(on_spinBoxFontSize_valueChanged(int)));
    connect(comboFont,SIGNAL(currentIndexChanged(const QString&)),this,SLOT(on_comboFont_currentIndexChanged(const QString&)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::initUI()
{
    //状态栏上添加组件
    fLabCurFile =new QLabel;
    fLabCurFile->setMinimumWidth(150);
    fLabCurFile->setText("当前文件");
    ui->statusbar->addWidget(fLabCurFile);  //标签添加到状态栏

    progressBar1=new QProgressBar;
    progressBar1->setMaximumWidth(200);
    progressBar1->setMinimum(5);
    progressBar1->setMaximum(50);
    progressBar1->setValue(ui->txtEdit->font().pointSize());
    ui->statusbar->addWidget(progressBar1); //进度条添加到状态栏


    //工具栏上添加组件
    spinFontSize=new QSpinBox;  //文字大小
    spinFontSize->setMinimum(5);
    spinFontSize->setMaximum(50);
    spinFontSize->setValue(ui->txtEdit->font().pointSize());

    ui->mainToolBar->addWidget(new QLabel("字体大小"));
    ui->mainToolBar->addWidget(spinFontSize);

    ui->mainToolBar->addSeparator();    //分隔条
    ui->mainToolBar->addWidget(new QLabel("字体"));
    comboFont=new QFontComboBox;
    comboFont->setMaximumWidth(150);

    ui->mainToolBar->addWidget(comboFont);  //添加到工具栏

    setCentralWidget(ui->txtEdit);


}

void MainWindow::on_spinBoxFontSize_valueChanged(int value)
{
    QTextCharFormat fmt;
    fmt.setFontPointSize(value);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
    progressBar1->setValue(value);
}

void MainWindow::on_comboFont_currentIndexChanged(const QString &arg1)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(arg1);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_actFontBold_triggered(bool checked)
{
    QTextCharFormat fmt=ui->txtEdit->currentCharFormat();
    if(checked)fmt.setFontWeight(QFont::Bold);
    else fmt.setFontWeight(QFont::Normal);

    ui->txtEdit->mergeCurrentCharFormat(fmt);
}


void MainWindow::on_actFontItalic_triggered(bool checked)
{
    QTextCharFormat fmt=ui->txtEdit->currentCharFormat();
    fmt.setFontItalic(checked);

    ui->txtEdit->mergeCurrentCharFormat(fmt);
}



void MainWindow::on_actFontUnder_triggered(bool checked)
{
    QTextCharFormat fmt=ui->txtEdit->currentCharFormat();
    fmt.setFontUnderline(checked);

    ui->txtEdit->mergeCurrentCharFormat(fmt);
}


void MainWindow::on_txtEdit_copyAvailable(bool b)
{
    ui->actCopy->setEnabled(b);
    ui->actCut->setEnabled(b);
    ui->actPaste->setEnabled(ui->txtEdit->canPaste());
}

void MainWindow::on_txtEdit_selectionChanged()
{
    QTextCharFormat fmt=ui->txtEdit->currentCharFormat();

    ui->actFontItalic->setChecked(fmt.font().italic());
    ui->actFontBold->setChecked(fmt.font().bold());
    ui->actFontUnder->setChecked(fmt.font().underline());
}
