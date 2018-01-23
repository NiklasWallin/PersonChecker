#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QString>

class Person : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString Signum READ Signum WRITE setSignum NOTIFY SignumChanged)
    Q_PROPERTY(int Age READ Age WRITE setAge NOTIFY AgeChanged)
    Q_PROPERTY(QString Gender READ Gender WRITE setGender NOTIFY GenderChanged)
    Q_PROPERTY(QString IsValidSignum READ IsValidSignum WRITE setIsValidSignum NOTIFY IsValidSignumChanged)

public:
    explicit Person(QObject *parent = nullptr);

    QString Signum();
    void setSignum(const QString m_Signal);
    int Age();
    void setAge(const int m_Age);


    QString Gender() const
    {
        return m_Gender;
    }

    QString IsValidSignum() const
    {
        return m_IsValidSignum;
    }

public slots:
    int calcAge(QString m_Signum);
    QString getGender(QString m_Signum);
    QString checkIfValid(QString m_Signum);

    void setGender(QString Gender)
    {
        m_Gender = Gender;
    }

    void setIsValidSignum(QString IsValidSignum)
    {
        m_IsValidSignum = IsValidSignum;
    }

signals:
    void SignumChanged();
    void AgeChanged();
    void GenderChanged();
    void IsValidSignumChanged();

private:
    QString m_Signum;
    int m_Age;
    QString m_Gender;
    QString m_IsValidSignum;
};

#endif // PERSON_H
