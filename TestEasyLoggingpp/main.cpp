#include "MainWindow.h"

#include <QApplication>

// Already defined in .pro
//#define ELPP_NO_DEFAULT_LOG_FILE
//#define ELPP_QT_LOGGING

#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // Load conf setting
    el::Configurations conf("log.conf");
    el::Loggers::reconfigureAllLoggers(conf);

    /// Fatal level do not stop program
    el::Loggers::addFlag(el::LoggingFlag::DisableApplicationAbortOnFatalLog);

    // Init log level for output
//    el::Loggers::addFlag(el::LoggingFlag::HierarchicalLogging);
//    el::Loggers::setLoggingLevel(el::Level::Trace);

    // Init Verbose level
    el::Loggers::setVerboseLevel(9);
    // Get Verbose level
    int verboseLevel = el::Loggers::verboseLevel();
    LOG(INFO) << "Verbose Level = " << verboseLevel;

    LOG(INFO) << "My first info log using default logger";
    LOG(WARNING) << "My first warning log using default logger";
    LOG(ERROR) << "My first error log using default logger";
    LOG(FATAL) << "My first fatal log using default logger";
    LOG(DEBUG) << "My first debug log using default logger";
    LOG(TRACE) << "My first trace log using default logger";

    VLOG(0) << "My first verbose log using default logger";
    VLOG(1) << "My first verbose log using default logger";

    QString str = "Qt string 中文";
    LOG(TRACE) << str;

    return a.exec();
}
