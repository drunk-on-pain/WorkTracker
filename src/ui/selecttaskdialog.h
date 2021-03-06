/*
 * Copyright 2014 Robert Lohr
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SELECTTASKDIALOG_H
#define SELECTTASKDIALOG_H

#include "../model/datasource.h"

#include <QDialog>
#include <QDomDocument>

namespace Ui {
    class SelectTaskDialog;
}

/*!
 * A simple dialog with just one line-edit in which the user can search for existing 
 * tasks or enter a new one.
 */
class SelectTaskDialog : public QDialog
{
    Q_OBJECT
public:
    /*!
     * Create a new dialog. The data-source is needed to create the model that the 
     * completer uses.
     */
    SelectTaskDialog(DataSource dataSource, QWidget* parent = nullptr);
    
    /*!
     * Releases the ui resources.
     */
    ~SelectTaskDialog();
    
    /*!
     * \return 
     * Returns the name of the task the user selected or entered.
     */
    QString taskName() const;
    
protected slots:
    /*!
     * Evaluates the current content of the line-edit and enables or disables the OK
     * button accordingly.
     */
    void textChanged(const QString& text);
    
private:
    Ui::SelectTaskDialog* ui;
};

#endif // SELECTTASKDIALOG_H
