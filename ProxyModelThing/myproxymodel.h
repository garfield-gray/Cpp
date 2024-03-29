#ifndef MYPROXYMODEL_H
#define MYPROXYMODEL_H

#include <QObject>
#include <QSortFilterProxyModel>

class MyProxyModel: public QSortFilterProxyModel
{
    Q_OBJECT
    Q_PROPERTY(bool myFilterEnabled READ myFilterEnabled WRITE setMyFilterEnabled NOTIFY myFilterEnabledChanged FINAL)
    Q_PROPERTY(QString searchedWord READ searchedWord WRITE setSearchedWord NOTIFY searchedWordChanged FINAL)

public:
    explicit MyProxyModel(QObject *parent = nullptr);

    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;

    bool myFilterEnabled() const;
    void setMyFilterEnabled(bool newMyFilterEnabled);

    QString searchedWord() const;
    void setSearchedWord(const QString &newSearchedWord);

    void removeRowByModelIndex(const QModelIndex &index);

//    void mapToSource(const QModelIndex &proxyIndex) const override;

//    void mapFromSource(const QModelIndex &sourceIndex) const override;

signals:
    void myFilterEnabledChanged();

    void searchedWordChanged();

private:
    bool m_myFilterEnabled;
    QString m_searchedWord;

    // QSortFilterProxyModel interface
protected:
    bool lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const override;
};

#endif // MYPROXYMODEL_H
