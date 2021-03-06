/**
 ******************************************************************************
 *
 * @file       serialpluginoptionspage.h
 * @author     The LibrePilot Project, http://www.librepilot.org Copyright (C) 2017.
 *             The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @see        The GNU Public License (GPL) Version 3
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup SerialPlugin Serial Connection Plugin
 * @{
 * @brief Impliments serial connection to the flight hardware for Telemetry
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef SERIALPLUGINOPTIONSPAGE_H
#define SERIALPLUGINOPTIONSPAGE_H

#include "coreplugin/dialogs/ioptionspage.h"

#include "QString"

class SerialPluginConfiguration;

namespace Ui {
class SerialPluginOptionsPage;
}

using namespace Core;

class SerialPluginOptionsPage : public IOptionsPage {
    Q_OBJECT
public:
    explicit SerialPluginOptionsPage(SerialPluginConfiguration *config, QObject *parent = 0);

    QString id() const
    {
        return QLatin1String("settings");
    }
    QString trName() const
    {
        return tr("settings");
    }
    QString category() const
    {
        return "Telemetry - Serial";
    }
    QString trCategory() const
    {
        return "Serial Telemetry";
    }
    QWidget *createPage(QWidget *parent);
    void apply();
    void finish();

signals:
    void availableDevChanged();

private:
    Ui::SerialPluginOptionsPage *m_page;
    SerialPluginConfiguration *m_config;
};

#endif // SERIALPLUGINOPTIONSPAGE_H
