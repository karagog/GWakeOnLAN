/*Copyright 2010 George Karagoulis

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.*/

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QMap>
#include <QString>

namespace GUtil
{
    namespace Qt
    {

        // This encapsulates persistent settings for your application

        // This class is NOT thread-safe, so don't share the same Settings object
        //  between several threads.  However, you CAN use several 'Settings'
        //  objects and access the same settings identifier from different threads
        //  at the same time.  It implements a file-locking mechanism to make sure
        //  that the writer has exclusive access, and the others block until the
        //  the lock is released, but they never hold the lock for long so the blocking
        //  time is minimal.

        class Settings : QObject
        {
            Q_OBJECT
        public:
            Settings();

            // note about paramter:
            bool Initialize(const QString &settings_dir);

            bool Export();

            bool SetValue(const QString &key, const QString& value);
            bool SetValues(const QMap<QString, QString> &);

            QString Value(const QString &key);
            QStringList Values(const QStringList &);

            bool IsLoaded() const;
            bool Contains(const QString &key);

            QString Error();

            QString FileName();

        signals:
            void NotifySaved();

        private slots:
            void clear_error();
            bool save_settings();
            bool load_settings(const QString &);

        private:
            QString _error;
            QMap<QString, QString> _values;
            QString _identity_string;
            QString _settings_filename;

            bool _loaded;

            QString get_settings_location();

            void set_error(const QString &err = "");
        };

    }
}

#endif // SETTINGS_H
