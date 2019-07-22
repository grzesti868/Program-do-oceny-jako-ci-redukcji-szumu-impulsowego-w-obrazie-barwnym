#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(0));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonLoad_clicked()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Images (*.bmp *.jpg *.png)");
    if (QString::compare(fileName, ""))
    {
        raw.load(fileName);
        corrupted.load(fileName);
        int imageWidth = ui->image->width();
        ui->image->setPixmap(QPixmap::fromImage((raw.scaledToWidth(imageWidth))));
        ui->image2->setPixmap(QPixmap::fromImage((corrupted.scaledToWidth(imageWidth))));
        ui->spinBox->setEnabled(true);

    }

}

void MainWindow::on_spinBox_valueChanged(int level)
{
    if(!raw.isNull())
    {
        int imageWidth = ui->image2->width();
        corrupted=Noise::setNoise(raw,level);
        ui->image2->setPixmap(QPixmap::fromImage((corrupted.scaledToWidth(imageWidth))));
    }
}



void MainWindow::on_filterButton_clicked()
{
    if((ui->radVMF->isChecked()) || (ui->radPGF->isChecked()) || (ui->radTEST->isChecked()))
    {
    if(!corrupted.isNull())
    {
        if(!(ui->radTEST->isChecked()))
        {
        fixed_img=corrupted;
        if(ui->radVMF->isChecked())
        {
            fixed.putImage(corrupted);
            fixed.execute();
            fixed.getImage(fixed_img);
        }
        if(ui->radPGF->isChecked())
        {
            fixedPGF.putImage(corrupted);
            fixedPGF.execute();
            fixed_img=fixedPGF.getImage();
        }

        int imageWidth = ui->image3->width();

        ui->image3->setPixmap(QPixmap::fromImage((fixed_img.scaledToWidth(imageWidth))));
        }

        Accuracy::setAll(raw,corrupted,fixed_img);

        int imageWidth = ui->image3->width();

        on_btnShowMap_clicked();


        ImgQuality::setImage1(raw);
        ImgQuality::setImage2(fixed_img);

        double m_Mae=ImgQuality::countMae();
        double m_Psnr=ImgQuality::countPsnr();
        double m_Mse=ImgQuality::countMse();
        ui->lbMAE->setText(QString::number(m_Mae));
        ui->lbMSE->setText(QString::number(m_Mse));
        ui->lbPSNR->setText(QString::number(m_Psnr));

        ImgQuality::setImage1(raw);
        ImgQuality::setImage2(fixed_img);


        Accuracy::makeDetectionMap();


        double TP = ImgQuality::countSpecialMae( Accuracy::getMask(),ImgQuality::TP);
        drawing.setValue(0, TP ,Qt::green,"MAE(TP)");



        double FP = ImgQuality::countSpecialMae( Accuracy::getMask(),ImgQuality::FP);
        drawing.setValue(1, FP ,Qt::red,"MAE(FP)");



        double FN = ImgQuality::countSpecialMae( Accuracy::getMask(),ImgQuality::FN);
        drawing.setValue(2, FN ,Qt::blue,"MAE(FN)");

        imageWidth = ui->imgMaeChart->width();
        drawing.drawChart();
        ui->imgMaeChart->setPixmap(drawing.getMaeChart().scaledToWidth(imageWidth));

        ui->lbTP->setText(QString::number(Accuracy::getTP()));
        ui->lbTN->setText(QString::number(Accuracy::getTN()));
        ui->lbFP->setText(QString::number(Accuracy::getFP()));
        ui->lbFN->setText(QString::number(Accuracy::getFN()));
        ui->lbACC->setText(QString::number(Accuracy::getAccuracy()));
        ui->btnSaveFix->setEnabled(true);
        ui->btnSaveMap->setEnabled(true);
        ui->btnSaveCorr->setEnabled(true);
        ui->btnShowMap->setEnabled(true);

    }
     else
        MessageBox( QString("Nie ma obrazka do odfiltorwania"), QMessageBox::Icon::Warning  );
    }
     else
        MessageBox( QString("Prosze wybrać filtr"), QMessageBox::Icon::Question  );




}

void MainWindow::on_btnSaveCorr_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),"",tr("JPG (*.jpg);;PNG (*.png)"));
    if(!corrupted.isNull())
    {
      corrupted.save(fileName);
    }
}

void MainWindow::on_btnSaveFix_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),"",tr("JPG (*.jpg);;PNG (*.png)"));
    if(!fixed_img.isNull())
    {
      fixed_img.save(fileName);
    }
}

void MainWindow::on_btnSaveMap_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),"",tr("JPG (*.jpg);;PNG (*.png)"));
    if(ui->rad1->isChecked())
    {
        Accuracy::getOrgMap().save(fileName);
    }

    if(ui->rad2->isChecked())
    {
        Accuracy::getEstMap().save(fileName);
    }

    if(ui->rad3->isChecked())
    {
        Accuracy::getDetectionMap().save(fileName);
    }
}

void MainWindow::on_btnShowMap_clicked()
{
    int imageWidth = ui->image4->width();
    if(ui->rad1->isChecked())
    {
        Accuracy::makeOrgMap();
        ui->image4->setPixmap(QPixmap::fromImage((Accuracy::getOrgMap().scaledToWidth(imageWidth))));
    }

    if(ui->rad2->isChecked())
    {
       Accuracy::makeEstMap();
       ui->image4->setPixmap(QPixmap::fromImage((Accuracy::getEstMap().scaledToWidth(imageWidth))));
    }

    if(ui->rad3->isChecked())
    {
        Accuracy::makeDetectionMap();
        ui->image4->setPixmap(QPixmap::fromImage(Accuracy::getDetectionMap().scaledToWidth(imageWidth)));
    }
}

void MainWindow::on_loadCorr_clicked()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Images (*.bmp *.jpg *.png)");
    if (QString::compare(fileName, ""))
    {

        corrupted.load(fileName);
        int imageWidth = ui->image->width();
        ui->image2->setPixmap(QPixmap::fromImage((corrupted.scaledToWidth(imageWidth))));

    }
}

void MainWindow::on_loadFixed_clicked()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Images (*.bmp *.jpg *.png)");
    if (QString::compare(fileName, ""))
    {
        fixed_img.load(fileName);
        int imageWidth = ui->image->width();
        ui->image3->setPixmap(QPixmap::fromImage((fixed_img.scaledToWidth(imageWidth))));
    }


}
