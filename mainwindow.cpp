// #include "mainwindow.h"
// #include <QMenuBar>
// #include <QMenu>
// #include <QAction>
// #include <QFileDialog>
// #include <QMessageBox>
// #include <QApplication>


// MainWindow::MainWindow(QWidget *parent)
//     : QMainWindow(parent)
// {
//     setupEditor();
//     setupFileMenu();
//     setupEditMenu();
//     setupCompileMenu();
//     setupHelpMenu();

//     setCentralWidget(editor);
//     setWindowTitle(tr("Code Editor"));
// }

// void MainWindow::setupEditor()
// {
//     QFont font;
//     font.setFamily("Courier");
//     font.setFixedPitch(true);
//     font.setPointSize(10);

//     editor = new QTextEdit;
//     editor->setFont(font);

//     highlighter = new Highlighter(editor->document());

//     setMinimumSize(600, 400);

//     QFile file("mainwindow.cpp");
//     if (file.open(QFile::ReadOnly | QFile::Text))
//         editor->setPlainText(file.readAll());
// }

// void MainWindow::setupFileMenu()
// {
//     QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

//     QAction *newAction = new QAction(tr("&New"), this);
//     newAction->setShortcut(QKeySequence::New);
//     connect(newAction, &QAction::triggered, this, &MainWindow::newFile);
//     fileMenu->addAction(newAction);

//     QAction *openAction = new QAction(tr("&Open"), this);
//     openAction->setShortcut(QKeySequence::Open);
//     connect(openAction, &QAction::triggered, this, &MainWindow::openFile);
//     fileMenu->addAction(openAction);

//     QAction *saveAction = new QAction(tr("&Save"), this);
//     saveAction->setShortcut(QKeySequence::Save);
//     connect(saveAction, &QAction::triggered, this, &MainWindow::save);
//     fileMenu->addAction(saveAction);

//     QAction *saveAsAction = new QAction(tr("Save &As"), this);
//     saveAsAction->setShortcut(QKeySequence::SaveAs);
//     connect(saveAsAction, &QAction::triggered, this, &MainWindow::saveAs);
//     fileMenu->addAction(saveAsAction);

//     fileMenu->addSeparator();

//     QAction *exitAction = new QAction(tr("&Exit"), this);
//     exitAction->setShortcut(QKeySequence::Quit);
//     connect(exitAction, &QAction::triggered, this, &MainWindow::exitApp);
//     fileMenu->addAction(exitAction);
// }

// void MainWindow::setupEditMenu()
// {
//     QMenu *editMenu = menuBar()->addMenu(tr("&Edit"));

//     QAction *undoAction = new QAction(tr("&Undo"), this);
//     undoAction->setShortcut(QKeySequence::Undo);
//     connect(undoAction, &QAction::triggered, editor, &QTextEdit::undo);
//     editMenu->addAction(undoAction);

//     QAction *redoAction = new QAction(tr("&Redo"), this);
//     redoAction->setShortcut(QKeySequence::Redo);
//     connect(redoAction, &QAction::triggered, editor, &QTextEdit::redo);
//     editMenu->addAction(redoAction);

//     editMenu->addSeparator();

//     QAction *cutAction = new QAction(tr("Cu&t"), this);
//     cutAction->setShortcut(QKeySequence::Cut);
//     connect(cutAction, &QAction::triggered, editor, &QTextEdit::cut);
//     editMenu->addAction(cutAction);

//     QAction *copyAction = new QAction(tr("&Copy"), this);
//     copyAction->setShortcut(QKeySequence::Copy);
//     connect(copyAction, &QAction::triggered, editor, &QTextEdit::copy);
//     editMenu->addAction(copyAction);

//     QAction *pasteAction = new QAction(tr("&Paste"), this);
//     pasteAction->setShortcut(QKeySequence::Paste);
//     connect(pasteAction, &QAction::triggered, editor, &QTextEdit::paste);
//     editMenu->addAction(pasteAction);

//     editMenu->addSeparator();

//     QAction *selectAllAction = new QAction(tr("Select &All"), this);
//     selectAllAction->setShortcut(QKeySequence::SelectAll);
//     connect(selectAllAction, &QAction::triggered, editor, &QTextEdit::selectAll);
//     editMenu->addAction(selectAllAction);
// }

// void MainWindow::setupCompileMenu()
// {
//     QMenu *compileMenu = menuBar()->addMenu(tr("&Compile"));

//     QAction *runAction = new QAction(tr("&Run"), this);
//     connect(runAction, &QAction::triggered, this, &MainWindow::run);
//     compileMenu->addAction(runAction);

//     QAction *buildAction = new QAction(tr("&Build"), this);
//     connect(buildAction, &QAction::triggered, this, &MainWindow::build);
//     compileMenu->addAction(buildAction);
// }

// void MainWindow::setupHelpMenu()
// {
//     QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));

//     QAction *aboutAction = new QAction(tr("&About"), this);
//     connect(aboutAction, &QAction::triggered, this, &MainWindow::about);
//     helpMenu->addAction(aboutAction);
// }

// void MainWindow::about()
// {
//     QMessageBox::about(this, tr("About"), tr("This is a simple code editor."));
// }

// void MainWindow::newFile()
// {
//     editor->clear();
// }

// void MainWindow::openFile()
// {
//     QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt);;All Files (*)"));
//     if (!fileName.isEmpty()) {
//         QFile file(fileName);
//         if (file.open(QFile::ReadOnly | QFile::Text)) {
//             QTextStream in(&file);
//             editor->setPlainText(in.readAll());
//             file.close();
//         } else {
//             QMessageBox::warning(this, tr("Error"), tr("Cannot open file %1.").arg(fileName));
//         }
//     }
// }

// void MainWindow::save()
// {
//     // Implement save logic here
// }

// void MainWindow::saveAs()
// {
//     // Implement save as logic here
// }

// void MainWindow::exitApp()
// {
//     QApplication::quit();
// }

// void MainWindow::undo()
// {
//     editor->undo();
// }

// void MainWindow::redo()
// {
//     editor->redo();
// }

// void MainWindow::cut()
// {
//     editor->cut();
// }

// void MainWindow::copy()
// {
//     editor->copy();
// }

// void MainWindow::paste()
// {
//     editor->paste();
// }

// void MainWindow::selectAll()
// {
//     editor->selectAll();
// }

// void MainWindow::run()
// {
//     // Implement run functionality here
// }

// void MainWindow::build()
// {
//     // Implement build functionality here
// }

#include "mainwindow.h"
#include <QMenuBar>
#include <QProcessEnvironment>
#include <QDir>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QMessageBox>
#include <QApplication>
#include <QVBoxLayout>
#include <QSplitter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), currentFile("")
{
    QSplitter *splitter = new QSplitter(this);
    QWidget *editorContainer = new QWidget(this);
    QVBoxLayout *editorLayout = new QVBoxLayout(editorContainer);

    setupEditor();
    setupOutputWindow();
    editorLayout->addWidget(editor);
    editorContainer->setLayout(editorLayout);

    splitter->addWidget(editorContainer);
    splitter->addWidget(outputWindow);
    setCentralWidget(splitter);

    setupFileMenu();
    setupEditMenu();
    setupCompileMenu();
    setupHelpMenu();

    setWindowTitle(tr("IDE++"));
}

void MainWindow::setupEditor()
{
    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(10);

    editor = new QTextEdit;
    editor->setFont(font);

    highlighter = new Highlighter(editor->document());

    QFile file("mainwindow.cpp");
    if (file.open(QFile::ReadOnly | QFile::Text))
        editor->setPlainText(file.readAll());
}

void MainWindow::setupOutputWindow()
{
    outputWindow = new QTextEdit;
    outputWindow->setReadOnly(true);
    outputWindow->setPlainText("Enter two integers: 12\n23\nResult: 12 < 23");
}

void MainWindow::setupFileMenu()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

    QAction *newAction = new QAction(tr("&New"), this);
    newAction->setShortcut(QKeySequence::New);
    connect(newAction, &QAction::triggered, this, &MainWindow::newFile);
    fileMenu->addAction(newAction);

    QAction *openAction = new QAction(tr("&Open"), this);
    openAction->setShortcut(QKeySequence::Open);
    connect(openAction, &QAction::triggered, this, &MainWindow::openFile);
    fileMenu->addAction(openAction);

    QAction *saveAction = new QAction(tr("&Save"), this);
    saveAction->setShortcut(QKeySequence::Save);
    connect(saveAction, &QAction::triggered, this, &MainWindow::save);
    fileMenu->addAction(saveAction);

    QAction *saveAsAction = new QAction(tr("Save &As"), this);
    saveAsAction->setShortcut(QKeySequence::SaveAs);
    connect(saveAsAction, &QAction::triggered, this, &MainWindow::saveAs);
    fileMenu->addAction(saveAsAction);

    fileMenu->addSeparator();

    QAction *exitAction = new QAction(tr("&Exit"), this);
    exitAction->setShortcut(QKeySequence::Quit);
    connect(exitAction, &QAction::triggered, this, &MainWindow::exitApp);
    fileMenu->addAction(exitAction);
}

void MainWindow::setupEditMenu()
{
    QMenu *editMenu = menuBar()->addMenu(tr("&Edit"));

    QAction *undoAction = new QAction(tr("&Undo"), this);
    undoAction->setShortcut(QKeySequence::Undo);
    connect(undoAction, &QAction::triggered, editor, &QTextEdit::undo);
    editMenu->addAction(undoAction);

    QAction *redoAction = new QAction(tr("&Redo"), this);
    redoAction->setShortcut(QKeySequence::Redo);
    connect(redoAction, &QAction::triggered, editor, &QTextEdit::redo);
    editMenu->addAction(redoAction);

    editMenu->addSeparator();

    QAction *cutAction = new QAction(tr("Cu&t"), this);
    cutAction->setShortcut(QKeySequence::Cut);
    connect(cutAction, &QAction::triggered, editor, &QTextEdit::cut);
    editMenu->addAction(cutAction);

    QAction *copyAction = new QAction(tr("&Copy"), this);
    copyAction->setShortcut(QKeySequence::Copy);
    connect(copyAction, &QAction::triggered, editor, &QTextEdit::copy);
    editMenu->addAction(copyAction);

    QAction *pasteAction = new QAction(tr("&Paste"), this);
    pasteAction->setShortcut(QKeySequence::Paste);
    connect(pasteAction, &QAction::triggered, editor, &QTextEdit::paste);
    editMenu->addAction(pasteAction);

    editMenu->addSeparator();

    QAction *selectAllAction = new QAction(tr("Select &All"), this);
    selectAllAction->setShortcut(QKeySequence::SelectAll);
    connect(selectAllAction, &QAction::triggered, editor, &QTextEdit::selectAll);
    editMenu->addAction(selectAllAction);
}

void MainWindow::setupCompileMenu()
{
    QMenu *compileMenu = menuBar()->addMenu(tr("&Compile"));

    QAction *runAction = new QAction(tr("&Run"), this);
    connect(runAction, &QAction::triggered, this, &MainWindow::run);
    compileMenu->addAction(runAction);

    QAction *buildAction = new QAction(tr("&Build"), this);
    connect(buildAction, &QAction::triggered, this, &MainWindow::build);
    compileMenu->addAction(buildAction);
}

void MainWindow::setupHelpMenu()
{
    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));

    QAction *aboutAction = new QAction(tr("&About"), this);
    connect(aboutAction, &QAction::triggered, this, &MainWindow::about);
    helpMenu->addAction(aboutAction);
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About"), tr("This is a simple code editor."));
}

void MainWindow::newFile()
{
    editor->clear();
    currentFile = "";
}

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt);;All Files (*)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QFile::ReadOnly | QFile::Text)) {
            QTextStream in(&file);
            editor->setPlainText(in.readAll());
            file.close();
            currentFile = fileName;
        } else {
            QMessageBox::warning(this, tr("Error"), tr("Cannot open file %1.").arg(fileName));
        }
    }
}

void MainWindow::save()
{
    if (currentFile.isEmpty()) {
        saveAs();
    } else {
        saveToFile(currentFile);
    }
}

void MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt);;All Files (*)"));
    if (!fileName.isEmpty()) {
        saveToFile(fileName);
        currentFile = fileName;
    }
}

void MainWindow::saveToFile(const QString &fileName)
{
    QFile file(fileName);
    if (file.open(QFile::WriteOnly | QFile::Text)) {
        QTextStream out(&file);
        out << editor->toPlainText();
        file.close();
    } else {
        QMessageBox::warning(this, tr("Error"), tr("Cannot save file %1.").arg(fileName));
    }
}

void MainWindow::exitApp()
{
    QApplication::quit();
}

void MainWindow::undo()
{
    editor->undo();
}

void MainWindow::redo()
{
    editor->redo();
}

void MainWindow::cut()
{
    editor->cut();
}

void MainWindow::copy()
{
    editor->copy();
}

void MainWindow::paste()
{
    editor->paste();
}

void MainWindow::selectAll()
{
    editor->selectAll();
}

QString findCompiler(const QString &compilerName)
{
    // Retrieve the system's PATH environment variable
    QStringList pathDirs = QProcessEnvironment::systemEnvironment().value("PATH").split(QDir::listSeparator());
    qDebug() << "System PATH:" << QProcessEnvironment::systemEnvironment().value("PATH");

    // Check each directory in the PATH
    for (const QString &dir : pathDirs) {
        QDir directory(dir);
        if (directory.exists()) {
            QString compilerPath = directory.filePath(compilerName + ".exe");
            qDebug() << "Checking path:" << compilerPath;

            if (QFileInfo::exists(compilerPath) && QFileInfo(compilerPath).isExecutable()) {
                qDebug() << "Compiler found at:" << compilerPath;
                return compilerPath;
            }
        }
    }

    qDebug() << "Compiler not found in system PATH";
    return QString(); // Compiler not found
}


// void MainWindow::run()
// {
//     if (currentFile.isEmpty()) {
//         saveAs();
//     }

//     if (!currentFile.isEmpty()) {
//         QString command;
//         if (currentFile.endsWith(".ino")) {
//             command = "avrdude -c arduino -P COM3 -p m328p -b 115200 -U flash:w:" + currentFile + ".hex:i";
//         } else if (currentFile.endsWith(".cpp") || currentFile.endsWith(".c")) {
//             command = currentFile.left(currentFile.lastIndexOf('.')); // Remove file extension
//             QString compiler = currentFile.endsWith(".c") ? "gcc" : "g++";

//             QString compilerPath = findCompiler(compiler);
//             if (compilerPath.isEmpty()) {
//                 qDebug() << "Compiler" << compiler << "not found";
//                 outputWindow->append("Error: Compiler " + compiler + " not found");
//                 return;
//             }

//             command = compilerPath + " " + currentFile + " -o " + command;
//             qDebug() << "Compilation command:" << command;
//             process = new QProcess(this);
//             connect(process, &QProcess::readyReadStandardOutput, this, &MainWindow::readProcessOutput);
//             connect(process, &QProcess::readyReadStandardError, this, &MainWindow::readProcessError);
//             process->start(command);
//             return;
//         }

//         process = new QProcess(this);
//         connect(process, &QProcess::readyReadStandardOutput, this, &MainWindow::readProcessOutput);
//         connect(process, &QProcess::readyReadStandardError, this, &MainWindow::readProcessError);
//         process->start(command);
//     }
// }
void MainWindow::run()
{
    if (currentFile.isEmpty()) {
        saveAs();
    }

    if (!currentFile.isEmpty()) {
        QString command;
        if (currentFile.endsWith(".ino")) {
            command = "avrdude -c arduino -P COM3 -p m328p -b 115200 -U flash:w:" + currentFile + ".hex:i";
        } else if (currentFile.endsWith(".cpp") || currentFile.endsWith(".c")) {
            command = currentFile.left(currentFile.lastIndexOf('.')); // Remove file extension
            QString compiler = currentFile.endsWith(".c") ? "gcc" : "g++";

            QString compilerPath = findCompiler(compiler);
            if (compilerPath.isEmpty()) {
                qDebug() << "Compiler" << compiler << "not found";
                outputWindow->append("Error: Compiler " + compiler + " not found");
                return;
            }

            command = compilerPath + " " + currentFile + " -o " + command;
            qDebug() << "Compilation command:" << command;
            process = new QProcess(this);
            connect(process, &QProcess::readyReadStandardOutput, this, &MainWindow::readProcessOutput);
            connect(process, &QProcess::readyReadStandardError, this, &MainWindow::readProcessError);
            process->start(command);
            return;
        } else {
            command = currentFile;
        }

        process = new QProcess(this);
        connect(process, &QProcess::readyReadStandardOutput, this, &MainWindow::readProcessOutput);
        connect(process, &QProcess::readyReadStandardError, this, &MainWindow::readProcessError);
        process->start(command);
    }
}
void MainWindow::build()
{
    if (currentFile.isEmpty()) {
        saveAs();
    }

    if (!currentFile.isEmpty()) {
        QString command;
        if (currentFile.endsWith(".ino")) {
            command = "avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c " + currentFile + " -o " + currentFile + ".o";
            command += " && avr-gcc -mmcu=atmega328p " + currentFile + ".o -o " + currentFile + ".elf";
            command += " && avr-objcopy -O ihex -R .eeprom " + currentFile + ".elf " + currentFile + ".hex";
        } else if (currentFile.endsWith(".cpp") || currentFile.endsWith(".c")) {
            command = currentFile.left(currentFile.lastIndexOf('.')); // Remove file extension
            QString compiler = currentFile.endsWith(".c") ? "gcc" : "g++";

            QString compilerPath = findCompiler(compiler);
            if (compilerPath.isEmpty()) {
                qDebug() << "Compiler" << compiler << "not found";
                outputWindow->append("Error: Compiler " + compiler + " not found");
                return;
            }

            command = compilerPath + " " + currentFile + " -o " + command;
            qDebug() << "Compilation command:" << command;
        }

        process = new QProcess(this);
        connect(process, &QProcess::readyReadStandardOutput, this, &MainWindow::readProcessOutput);
        connect(process, &QProcess::readyReadStandardError, this, &MainWindow::readProcessError);
        process->start(command);
    }
}


void MainWindow::readProcessOutput()
{
    QByteArray output = process->readAllStandardOutput();
    qDebug() << "Compiler Output:" << output;
    outputWindow->append(output);
}

void MainWindow::readProcessError()
{
    QByteArray error = process->readAllStandardError();
    qDebug() << "Compiler Error:" << error;
    outputWindow->append(error);
}



// #include "mainwindow.h"
// #include <QMenuBar>
// #include <QProcessEnvironment>
// #include <QDir>
// #include <QMenu>
// #include <QAction>
// #include <QFileDialog>
// #include <QMessageBox>
// #include <QApplication>
// #include <QVBoxLayout>
// #include <QSplitter>

// MainWindow::MainWindow(QWidget *parent)
//     : QMainWindow(parent), currentFile("")
// {
//     QSplitter *splitter = new QSplitter(this);
//     QWidget *editorContainer = new QWidget(this);
//     QVBoxLayout *editorLayout = new QVBoxLayout(editorContainer);

//     setupEditor();
//     setupOutputWindow();
//     editorLayout->addWidget(editor);
//     editorContainer->setLayout(editorLayout);

//     splitter->addWidget(editorContainer);
//     splitter->addWidget(outputWindow);
//     setCentralWidget(splitter);

//     setupFileMenu();
//     setupEditMenu();
//     setupCompileMenu();
//     setupHelpMenu();

//     setWindowTitle(tr("Code Editor"));
// }

// void MainWindow::setupEditor()
// {
//     QFont font;
//     font.setFamily("Courier");
//     font.setFixedPitch(true);
//     font.setPointSize(10);

//     editor = new QTextEdit;
//     editor->setFont(font);

//     highlighter = new Highlighter(editor->document());

//     QFile file("mainwindow.cpp");
//     if (file.open(QFile::ReadOnly | QFile::Text))
//         editor->setPlainText(file.readAll());
// }

// void MainWindow::setupOutputWindow()
// {
//     outputWindow = new QTextEdit;
//     outputWindow->setReadOnly(true);
//     outputWindow->setPlainText("Output will be shown here...");
// }

// void MainWindow::setupFileMenu()
// {
//     QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

//     QAction *newAction = new QAction(tr("&New"), this);
//     newAction->setShortcut(QKeySequence::New);
//     connect(newAction, &QAction::triggered, this, &MainWindow::newFile);
//     fileMenu->addAction(newAction);

//     QAction *openAction = new QAction(tr("&Open"), this);
//     openAction->setShortcut(QKeySequence::Open);
//     connect(openAction, &QAction::triggered, this, &MainWindow::openFile);
//     fileMenu->addAction(openAction);

//     QAction *saveAction = new QAction(tr("&Save"), this);
//     saveAction->setShortcut(QKeySequence::Save);
//     connect(saveAction, &QAction::triggered, this, &MainWindow::save);
//     fileMenu->addAction(saveAction);

//     QAction *saveAsAction = new QAction(tr("Save &As"), this);
//     saveAsAction->setShortcut(QKeySequence::SaveAs);
//     connect(saveAsAction, &QAction::triggered, this, &MainWindow::saveAs);
//     fileMenu->addAction(saveAsAction);

//     fileMenu->addSeparator();

//     QAction *exitAction = new QAction(tr("&Exit"), this);
//     exitAction->setShortcut(QKeySequence::Quit);
//     connect(exitAction, &QAction::triggered, this, &MainWindow::exitApp);
//     fileMenu->addAction(exitAction);
// }

// void MainWindow::setupEditMenu()
// {
//     QMenu *editMenu = menuBar()->addMenu(tr("&Edit"));

//     QAction *undoAction = new QAction(tr("&Undo"), this);
//     undoAction->setShortcut(QKeySequence::Undo);
//     connect(undoAction, &QAction::triggered, editor, &QTextEdit::undo);
//     editMenu->addAction(undoAction);

//     QAction *redoAction = new QAction(tr("&Redo"), this);
//     redoAction->setShortcut(QKeySequence::Redo);
//     connect(redoAction, &QAction::triggered, editor, &QTextEdit::redo);
//     editMenu->addAction(redoAction);

//     editMenu->addSeparator();

//     QAction *cutAction = new QAction(tr("Cu&t"), this);
//     cutAction->setShortcut(QKeySequence::Cut);
//     connect(cutAction, &QAction::triggered, editor, &QTextEdit::cut);
//     editMenu->addAction(cutAction);

//     QAction *copyAction = new QAction(tr("&Copy"), this);
//     copyAction->setShortcut(QKeySequence::Copy);
//     connect(copyAction, &QAction::triggered, editor, &QTextEdit::copy);
//     editMenu->addAction(copyAction);

//     QAction *pasteAction = new QAction(tr("&Paste"), this);
//     pasteAction->setShortcut(QKeySequence::Paste);
//     connect(pasteAction, &QAction::triggered, editor, &QTextEdit::paste);
//     editMenu->addAction(pasteAction);

//     editMenu->addSeparator();

//     QAction *selectAllAction = new QAction(tr("Select &All"), this);
//     selectAllAction->setShortcut(QKeySequence::SelectAll);
//     connect(selectAllAction, &QAction::triggered, editor, &QTextEdit::selectAll);
//     editMenu->addAction(selectAllAction);
// }

// void MainWindow::setupCompileMenu()
// {
//     QMenu *compileMenu = menuBar()->addMenu(tr("&Compile"));

//     QAction *runAction = new QAction(tr("&Run"), this);
//     connect(runAction, &QAction::triggered, this, &MainWindow::run);
//     compileMenu->addAction(runAction);

//     QAction *buildAction = new QAction(tr("&Build"), this);
//     connect(buildAction, &QAction::triggered, this, &MainWindow::build);
//     compileMenu->addAction(buildAction);
// }

// void MainWindow::setupHelpMenu()
// {
//     QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));

//     QAction *aboutAction = new QAction(tr("&About"), this);
//     connect(aboutAction, &QAction::triggered, this, &MainWindow::about);
//     helpMenu->addAction(aboutAction);
// }

// void MainWindow::about()
// {
//     QMessageBox::about(this, tr("About"), tr("This is a simple code editor."));
// }

// void MainWindow::newFile()
// {
//     editor->clear();
//     currentFile = "";
// }

// void MainWindow::openFile()
// {
//     QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt);;All Files (*)"));
//     if (!fileName.isEmpty()) {
//         QFile file(fileName);
//         if (file.open(QFile::ReadOnly | QFile::Text)) {
//             QTextStream in(&file);
//             editor->setPlainText(in.readAll());
//             file.close();
//             currentFile = fileName;
//         } else {
//             QMessageBox::warning(this, tr("Error"), tr("Cannot open file %1.").arg(fileName));
//         }
//     }
// }

// void MainWindow::save()
// {
//     if (currentFile.isEmpty()) {
//         saveAs();
//     } else {
//         saveToFile(currentFile);
//     }
// }

// void MainWindow::saveAs()
// {
//     QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt);;All Files (*)"));
//     if (!fileName.isEmpty()) {
//         saveToFile(fileName);
//         currentFile = fileName;
//     }
// }

// void MainWindow::saveToFile(const QString &fileName)
// {
//     QFile file(fileName);
//     if (file.open(QFile::WriteOnly | QFile::Text)) {
//         QTextStream out(&file);
//         out << editor->toPlainText();
//         file.close();
//     } else {
//         QMessageBox::warning(this, tr("Error"), tr("Cannot save file %1.").arg(fileName));
//     }
// }

// void MainWindow::exitApp()
// {
//     QApplication::quit();
// }

// void MainWindow::undo()
// {
//     editor->undo();
// }

// void MainWindow::redo()
// {
//     editor->redo();
// }

// void MainWindow::cut()
// {
//     editor->cut();
// }

// void MainWindow::copy()
// {
//     editor->copy();
// }

// void MainWindow::paste()
// {
//     editor->paste();
// }

// void MainWindow::selectAll()
// {
//     editor->selectAll();
// }

// QString MainWindow::findCompiler(const QString &compilerName)
// {
//     QStringList pathDirs = QProcessEnvironment::systemEnvironment().value("PATH").split(QDir::listSeparator());
//     for (const QString &dir : pathDirs) {
//         QFileInfo fileInfo(dir, compilerName);
//         if (fileInfo.isExecutable()) {
//             return fileInfo.absoluteFilePath();
//         }
//     }
//     return QString();
// }

// void MainWindow::run()
// {
//     if (currentFile.isEmpty()) {
//         QMessageBox::warning(this, tr("Error"), tr("Save your code before running."));
//         return;
//     }

//     QString compiler = findCompiler("g++");
//     if (compiler.isEmpty()) {
//         QMessageBox::warning(this, tr("Error"), tr("g++ compiler not found in PATH."));
//         return;
//     }

//     QString outputFileName = QFileInfo(currentFile).completeBaseName() + ".exe";
//     process = new QProcess(this);
//     process->setProgram(compiler);
//     process->setArguments({currentFile, "-o", outputFileName});
//     connect(process, &QProcess::readyReadStandardOutput, this, &MainWindow::readProcessOutput);
//     connect(process, &QProcess::readyReadStandardError, this, &MainWindow::readProcessError);
//     connect(process, &QProcess::finished, [this, outputFileName](int exitCode, QProcess::ExitStatus exitStatus) {
//         if (exitStatus == QProcess::NormalExit && exitCode == 0) {
//             process->start(outputFileName);
//         }
//     });

//     outputWindow->clear();
//     process->start();
// }

// void MainWindow::build()
// {
//     if (currentFile.isEmpty()) {
//         QMessageBox::warning(this, tr("Error"), tr("Save your code before building."));
//         return;
//     }

//     QString compiler = findCompiler("g++");
//     if (compiler.isEmpty()) {
//         QMessageBox::warning(this, tr("Error"), tr("g++ compiler not found in PATH."));
//         return;
//     }

//     QString outputFileName = QFileInfo(currentFile).completeBaseName() + ".exe";
//     process = new QProcess(this);
//     process->setProgram(compiler);
//     process->setArguments({currentFile, "-o", outputFileName});
//     connect(process, &QProcess::readyReadStandardOutput, this, &MainWindow::readProcessOutput);
//     connect(process, &QProcess::readyReadStandardError, this, &MainWindow::readProcessError);

//     outputWindow->clear();
//     process->start();
// }

// void MainWindow::readProcessOutput()
// {
//     outputWindow->append(process->readAllStandardOutput());
// }

// void MainWindow::readProcessError()
// {
//     outputWindow->append(process->readAllStandardError());
// }
