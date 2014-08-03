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

#include "workdaymodel.h"
#include "../workday.h"

WorkDayModel::WorkDayModel(QObject* p_parent)
    : QAbstractListModel(p_parent)
    , m_dataSource(nullptr)
{
}

void
WorkDayModel::setDataSource(QDomDocument* p_dataSource)
{
    beginResetModel();
    m_dataSource = p_dataSource;
    endResetModel();
}

int
WorkDayModel::rowCount(const QModelIndex& /* ignored */) const
{
    if (nullptr != m_dataSource) {
        return WorkDay::count(m_dataSource);
    }

    return 0;
}

QVariant
WorkDayModel::data(const QModelIndex& p_index, int p_role) const
{
    if (!p_index.isValid()) {
        return QVariant();
    }

    if (Qt::DisplayRole == p_role || Qt::EditRole == p_role) {
        // Descending order means treating the last item in the tree as "0"
        int reversedIndex = rowCount() - 1 - p_index.row();
        WorkDay workday = WorkDay::at(reversedIndex, m_dataSource);
        if (workday.isNull()) {
            return QVariant();
        }

        QVariant value;
        value.setValue(workday);
        return value;
    }

    return QVariant();
}