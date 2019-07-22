#include "functions.h"

void MessageBox(QString text, QMessageBox::Icon ikona)
{
    QMessageBox Alert;

    Alert.setIcon(ikona);
    Alert.setText(text);
    Alert.exec();
}
