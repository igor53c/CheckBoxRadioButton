#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    appFont = this->font();

    ui->rbHGGrau->setChecked(true);
    ui->rbVGSchwarz->setChecked(true);

    backColorRB = ui->rbHGGrau;
    foreColorRB = ui->rbVGSchwarz;

    ui->lineEdit->setText(QString::number(appFont.pointSize()));
}

void MainWindow::on_rbHGGruen_toggled(bool checked)
{
    if(checked)
        setBackColor(Qt::green, ui->rbHGGruen);
}

void MainWindow::on_rbHGBlau_toggled(bool checked)
{
    if(checked)
        setBackColor(Qt::blue, ui->rbHGBlau);
}

void MainWindow::on_rbHGRot_toggled(bool checked)
{
    if(checked)
        setBackColor(Qt::red, ui->rbHGRot);
}

void MainWindow::on_rbHGGelb_toggled(bool checked)
{
    if(checked)
        setBackColor(Qt::yellow, ui->rbHGGelb);
}

void MainWindow::on_rbHGGrau_toggled(bool checked)
{
    if(checked)
        setBackColor(Qt::gray, ui->rbHGGrau);
}

void MainWindow::setBackColor(QColor color, QRadioButton* radioButton)
{
    QPalette pal = this->palette();

    if(color != pal.color(QPalette::WindowText))
    {
        pal.setColor(QPalette::Window, color);

        this->setPalette(pal);

        backColorRB = radioButton;
    }
    else
        backColorRB->setChecked(true);
}

void MainWindow::on_rbVGBlau_toggled(bool checked)
{
    if(checked)
        setForeColor(Qt::blue, ui->rbVGBlau);
}

void MainWindow::on_rbVGRot_toggled(bool checked)
{
    if(checked)
        setForeColor(Qt::red, ui->rbVGRot);
}

void MainWindow::on_rbVGGelb_toggled(bool checked)
{
    if(checked)
        setForeColor(Qt::yellow, ui->rbVGGelb);
}

void MainWindow::on_rbVGSchwarz_toggled(bool checked)
{
    if(checked)
        setForeColor(Qt::black, ui->rbVGSchwarz);
}

void MainWindow::on_rbVGWeiss_toggled(bool checked)
{
    if(checked)
        setForeColor(Qt::white, ui->rbVGWeiss);
}

void MainWindow::setForeColor(QColor color, QRadioButton* radioButton)
{
    QPalette pal = this->palette();

    if(color != pal.color(QPalette::Window))
    {
        pal.setColor(QPalette::WindowText, color);

        this->setPalette(pal);

        ui->gbHintergrund->setPalette(pal);
        ui->gbVordergrund->setPalette(pal);
        ui->gbFont->setPalette(pal);

        foreColorRB = radioButton;
    }
    else
        foreColorRB->setChecked(true);
}

void MainWindow::on_checkFett_toggled(bool)
{
    setFontStyle();
}

void MainWindow::on_checkKursiv_toggled(bool)
{
    setFontStyle();
}

void MainWindow::setFontStyle()
{
    QString fontFamily = appFont.family();
    int fontSize = appFont.pointSize();
    int fontWeight = QFont::Normal;
    bool bItalic = false;

    if(ui->checkFett->isChecked())
        fontWeight = QFont::Bold;

    if(ui->checkKursiv->isChecked())
        bItalic = true;

    QFont newFont(fontFamily, fontSize, fontWeight, bItalic);

    appFont = newFont;

    //this->setFont(appFont);

    // ui->gbHintergrund->setFont(appFont);
    // ui->gbVordergrund->setFont(appFont);
    // ui->gbFont->setFont(appFont);

    setFont(ui->gbHintergrund, appFont);
    setFont(ui->gbVordergrund, appFont);
    setFont(ui->gbFont, appFont);
}

void MainWindow::setFont(QWidget *widget, QFont &font)
{
    widget->setFont(font);

    for(QWidget* child : widget->findChildren<QWidget*>())
        child->setFont(font);
}

void MainWindow::on_btnBeenden_clicked()
{
    close();
}

void MainWindow::on_lineEdit_returnPressed()
{
    // setFontSize();

    // ui->btnBeenden->setFocus();

    this->focusNextChild();
}

void MainWindow::setFontSize()
{
    QString fontFamily = appFont.family();
    int fontSize = appFont.pointSize();
    int fontWeight = appFont.weight();
    bool bItalic = appFont.italic();

    int newFontSize;

    bool bOK;

    newFontSize = ui->lineEdit->text().toInt(&bOK);

    if(!bOK)
    {
        QMessageBox::critical(this, "Fehler", "Ungültige Eingabe");

        newFontSize = fontSize;

        ui->lineEdit->setText( QString::number(fontSize));
    }
    else if(newFontSize < MIN_FONTSIZE)
    {
        QMessageBox::critical(this, "Fehler", "Die Mindestgröße der Schriftart beträgt: " +
                                                  QString::number(MIN_FONTSIZE));

        newFontSize = fontSize;

        ui->lineEdit->setText( QString::number(fontSize));
    }
    else if(newFontSize > MAX_FONTSIZE)
    {
        QMessageBox::critical(this, "Fehler", "Die maximale Größe der Schriftart beträgt: " +
                                                  QString::number(MAX_FONTSIZE));

        newFontSize = fontSize;

        ui->lineEdit->setText( QString::number(fontSize));
    }

    if(newFontSize == fontSize)
        return;

    QFont newFont(fontFamily, newFontSize, fontWeight, bItalic);

    appFont = newFont;

    setFont(ui->gbHintergrund, newFont);
    setFont(ui->gbVordergrund, newFont);
    setFont(ui->gbFont, newFont);
}

void MainWindow::on_lineEdit_editingFinished()
{
     setFontSize();
}

