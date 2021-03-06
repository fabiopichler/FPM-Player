/*******************************************************************************

  Omicron Player Classic

  Author: Fábio Pichler
  Website: http://fabiopichler.net
  License: BSD 3-Clause License

  Copyright (c) 2015-2019, Fábio Pichler
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this
    list of conditions and the following disclaimer.

  * Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

  * Neither the name of Omicron Player Classic nor the names of its
    contributors may be used to endorse or promote products derived from
    this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*******************************************************************************/

/*!
 *
 * \author Fábio Pichler
 * \copyright (c) 2015-2019, Fábio Pichler
 *
 */

#pragma once

#include "Core/Database.h"
#include "Core/Global.h"
#include "Core/Update.h"

#include <QApplication>
#include <QDir>
#include <QFile>
#include <QSettings>
#include <QFontDatabase>
#include <QSystemTrayIcon>

//! Classe responsável pelo processamento inicial e principal do programa.
/*!
 * Esta classe é responsável por inicializar a biblioteca BASS, plugins, Banco de Dados,
 * arquivos de configurações e etc.
 *
 * Também é responsável pelo processamento principal e por finalizar o programa.
 */

class WindowBase;

class Main : public QObject
{
    Q_OBJECT

public:
    Main();
    ~Main();
    bool init(const int &argc);

public slots:
    void startMusicMode();
    void startRadioMode();
    void startRecorderMode();
    void setWindowTitle(QString);
    void showError(QString);
    void showNotification(QString);
    void restart();

private:
    void setupRadiolist();
    void updateTrayIconMenu();

private slots:

    void trayIconActivated(QSystemTrayIcon::ActivationReason);
    void checkUpdate();
    void receiveMessage(QVector<QString>);
    void defaultConfig();

signals:
    //! Abrir músicas no "modo música"
    void openMusic(QVector<QString>);

    //! Adiciona músicas ao playlist do "modo músicas"
    void addMusic(QVector<QString>);

    //! Reproduzir o stream.
    void playStream();

    //! Pausa o stream atual.
    void pauseStream();

    //! Para o stream atual.
    void stopStream();

    //! Stream anteiror.
    void prevStream();

    //! Próximo stream.
    void nextStream();

public:
    UpdateApp *updateApp;
    bool continueRunning;

private:
    QSystemTrayIcon *trayIcon;
    QSettings *iniSettings;
    WindowBase *window;
};
