#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QSpinBox>
#include <QFontComboBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QLabel *fLabCurFile;    //状态栏里显示当前文件的Label
    QProgressBar *progressBar1;  //状态栏上的进度条
    QSpinBox *spinFontSize; //字体大小
    QFontComboBox * comboFont;  //字体名称
    void initUI();  //代码实现的UI初始化


private slots:
    void on_spinBoxFontSize_valueChanged(int value);
    void on_comboFont_currentIndexChanged(const QString &arg1);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actFontBold_triggered(bool checked);

    void on_actFontItalic_triggered(bool checked);

    void on_actFontUnder_triggered(bool checked);

    void on_txtEdit_copyAvailable(bool b);

    void on_txtEdit_selectionChanged();

    void on_actCut_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
