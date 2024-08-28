// #ifndef MAINWINDOW_H
// #define MAINWINDOW_H

// #include <QMainWindow>
// #include <QTextEdit>
// #include <QFileDialog>
// #include <QMessageBox>
// #include "highlighter.h"

// class MainWindow : public QMainWindow
// {
//     Q_OBJECT

// public:
//     MainWindow(QWidget *parent = nullptr);

// public slots:
//     void about();
//     void newFile();
//     void openFile();
//     void save();
//     void saveAs();
//     void exitApp();
//     void undo();
//     void redo();
//     void cut();
//     void copy();
//     void paste();
//     void selectAll();
//     void run();
//     void build();

// private:
//     void setupEditor();
//     void setupFileMenu();
//     void setupEditMenu();
//     void setupCompileMenu();
//     void setupHelpMenu();

//     QTextEdit *editor;
//     Highlighter *highlighter;
// };

// #endif // MAINWINDOW_H
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QFileDialog>
#include <QMessageBox>
#include <QSplitter>
#include <QProcess>
#include "highlighter.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

public slots:
    void about();
    void newFile();
    void openFile();
    void save();
    void saveAs();
    void exitApp();
    void undo();
    void redo();
    void cut();
    void copy();
    void paste();
    void selectAll();
    void run();
    void build();

private slots:
    void readProcessOutput();
    void readProcessError();

private:
    void setupEditor();
    void setupOutputWindow();
    void setupFileMenu();
    void setupEditMenu();
    void setupCompileMenu();
    void setupHelpMenu();
    void saveToFile(const QString &fileName);

    QTextEdit *editor;
    QTextEdit *outputWindow;
    Highlighter *highlighter;
    QProcess *process;
    QString currentFile;
};

#endif // MAINWINDOW_H


// #ifndef MAINWINDOW_H
// #define MAINWINDOW_H

// #include <QMainWindow>
// #include <QTextEdit>
// #include <QProcess>
// #include "highlighter.h"

// class MainWindow : public QMainWindow
// {
//     Q_OBJECT

// public:
//     MainWindow(QWidget *parent = nullptr);

// private slots:
//     void newFile();
//     void openFile();
//     void save();
//     void saveAs();
//     void exitApp();
//     void undo();
//     void redo();
//     void cut();
//     void copy();
//     void paste();
//     void selectAll();
//     void run();
//     void build();
//     void about();
//     void readProcessOutput();
//     void readProcessError();

// private:
//     void setupEditor();
//     void setupOutputWindow();
//     void setupFileMenu();
//     void setupEditMenu();
//     void setupCompileMenu();
//     void setupHelpMenu();
//     void saveToFile(const QString &fileName);
//     QString findCompiler(const QString &compilerName);

//     QTextEdit *editor;
//     QTextEdit *outputWindow;
//     Highlighter *highlighter;
//     QProcess *process;
//     QString currentFile;
// };

// #endif // MAINWINDOW_H

