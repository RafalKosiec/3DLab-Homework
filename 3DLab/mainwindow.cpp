#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::string bashOutput;

std::string exec(char* cmd) {
    FILE* pipe = popen(cmd, "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while(!feof(pipe)) {
        if(fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }
    pclose(pipe);
    return result;
}

void MainWindow::on_pushButton_pressed()
{
    //Path to script. Change accordingly.
    char* pathToScript = "/home/rafikolcz/QTProjects/3DLab/returnString.sh";
    bashOutput = exec(pathToScript);
    QString QbashOutput = QString::fromStdString(bashOutput);
    ui->label->setText(QbashOutput);
}
