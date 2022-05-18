#pragma once

#include <QMainWindow>
#include <QRadioButton>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_rbHGGruen_toggled(bool checked);

    void on_rbHGBlau_toggled(bool checked);

    void on_rbHGRot_toggled(bool checked);

    void on_rbHGGelb_toggled(bool checked);

    void on_rbHGGrau_toggled(bool checked);

    void on_btnBeenden_clicked();

    void on_rbVGBlau_toggled(bool checked);

    void on_rbVGRot_toggled(bool checked);

    void on_rbVGGelb_toggled(bool checked);

    void on_rbVGSchwarz_toggled(bool checked);

    void on_rbVGWeiss_toggled(bool checked);

    void on_checkFett_toggled(bool checked);

    void on_checkKursiv_toggled(bool checked);

    void on_lineEdit_returnPressed();

    void on_lineEdit_editingFinished();

private:
    Ui::MainWindow *ui;

    const int MIN_FONTSIZE = 5;
    const int MAX_FONTSIZE = 20;

    QFont appFont;
    QRadioButton* backColorRB;
    QRadioButton* foreColorRB;

    void init();

    void setBackColor(QColor, QRadioButton*);
    void setForeColor(QColor, QRadioButton*);
    void setFontStyle();
    void setFont(QWidget*, QFont&);

    void setFontSize();
};
