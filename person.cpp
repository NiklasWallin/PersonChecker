#include "person.h"
#include <QDebug>
#include <QString>
#include <QDateTime>
#include <QDate>

Person::Person(QObject *parent) :
    QObject(parent)
{
}

QString Person::Signum()
{
    return m_Signum;
}

int Person::Age()
{
    return m_Age;
}

void Person::setSignum(const QString Signum)
{
    if (Signum == m_Signum)
        return;

    m_Signum = Signum;
    emit SignumChanged();
}

void Person::setAge(const int Age)
{
    if (m_Age == Age)
        return;

    m_Age = Age;
    qDebug() << "Age = " << m_Age;
    emit AgeChanged();
}

int Person::calcAge(QString signum)
{
    int birthDay = signum.mid(0,2).toInt();
    int birthMonths = signum.mid(2,2).toInt();
    int birthYear = signum.mid(4,2).toInt();

    int century;
    QString centuryChecker = signum.mid(6,1);

    if(centuryChecker == "-"){
        century = 1900 + birthYear;
    }else if (centuryChecker == "a" || centuryChecker == "A"){
        century = 2000 + birthYear;
    }
    else{
        return -1;
    }

    QDate today;
    today = today.currentDate();
    int testYear = today.year();
    int testMonth = today.month();
    int testDay = today.day();

    if(testMonth > birthMonths)
        setAge(testYear - century);
    else if(testMonth == birthMonths){
        if(testDay >= birthDay)
           setAge(testYear - century);
        else
            setAge(testYear - (century+1));
    }else
        setAge(testYear - (century+1));

    emit AgeChanged();
    return Age();
}

QString Person::getGender(QString signum)
{
    int number = signum.mid(9,1).toInt();
    if(number % 2 == 1)
       setGender("man");
    else
        setGender("woman");

    emit GenderChanged();

    return Gender();
}

QString Person::checkIfValid(QString signum)
{
    QString sNumber = signum.left(6);
    QString sNumber2 = signum.mid(7,3);

    //checks the 3 last digits before the last control character
    if(!sNumber2.toInt()){
        setIsValidSignum("invalid");
        emit IsValidSignumChanged();
        return 0;
    }else{

        sNumber = sNumber.append(sNumber2);

        int iNumber = sNumber.toInt();
        int rest = iNumber % 31;

        QString checker = "0123456789ABCDEFHJKLMNPRSTUVWXY";

        if(signum.right(1) == checker.mid(rest,1))
            setIsValidSignum("Yes");
        else
            setIsValidSignum("No");

        emit IsValidSignumChanged();
    }

    return IsValidSignum();
}
