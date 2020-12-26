SET PATH=%PATH%;%GOPATH%\bin;

SET QT_DIR=C:\Qt\Qt5.12.0
SET QT_VERSION=5.12.0

SET GOARCH=amd64

qtdeploy build desktop ./

.\deploy\windows\MainPrj.exe