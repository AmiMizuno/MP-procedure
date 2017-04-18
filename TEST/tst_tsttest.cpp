#include <QString>
#include <QtTest>
#include "plant.h"
#include "tree.h"
#include "bush.h"
#include "flower.h"
#include "container.h"
#include <fstream>
#include <iostream>
using namespace std;

class TstTest : public QObject
{
    Q_OBJECT

public:
    TstTest();

private Q_SLOTS:
    void testIn();
    void testOut();
//   void testOutWarning();
    void sortSort();
    void sortAsort();
    void sortAlone();
    void sortZero();
    void testZero();
    void testAlone();
    void testOnlyTree();
    void TestConsonant_count();
    void TestConsonant_count2();
    void TestConsonant_count3();
    void TestConsonant_count4();
    void TestCompare();
//     void testOut_data();
    void testIn2();
    void ContainerClear();
    void ContainerInit();
};

TstTest::TstTest()
{
}
//тест ф-и ввода
void TstTest::testIn()
{
    container c;
    init(c);
    ifstream ifst;
    ifst.open("in.txt");
    ofstream ofst;
    ofst.open("out1.txt");
    In(c, ifst);
    Out(c, ofst);
    ifst.close();
    ofst.close();
    ifstream actual;
    actual.open("out1.txt");
    ifstream expected;
    expected.open("out_v.txt");
    char act;
    char exp;
    while(!actual.eof())
    {
        actual >> act;
        expected >> exp;
        QCOMPARE(act, exp);
    }
    actual.close();
    expected.close();
}





//void TstTest::testOut_data()
//{
//    QTest::addColumn<string>("in");
//    QTest::addColumn<string>("expected");
//    QTest::newRow("out01") <<'in.txt' <<'out1.txt';
//}


//тест ф-и вывода
//void TstTest::testOutWarning()
//{
//    QFETCH(string, act);
//    QFETCH(string, expected);
//    container c;
//    init(c);
//    ifstream ifst;
//    ifst.open(in);
//    ofstream ofst;
//    ofst.open(expected);
//    In(c, ifst);
//    sort(c);
//    Out(c, ofst);
//    outTrees(c, ofst);
//    ifst.close();
//    ofst.close();
//    ifstream actual;
//    actual.open(expected);
//    ifstream expected;
//    expected.open("out.txt");
//    QCOMPARE(act, expected);

// //   actual.close();
//  //  expected.close();
//}



//тест ф-и ввода
void TstTest::testOut()
{
    container c;
    init(c);
    ifstream ifst;
    ifst.open("in.txt");
    ofstream ofst;
    ofst.open("out2.txt");
    In(c, ifst);
    sort(c);
    Out(c, ofst);
    outTrees(c, ofst);
    ifst.close();
    ofst.close();
    ifstream actual;
    actual.open("out2.txt");
    ifstream expected;
    expected.open("out_vv.txt");
    char act;
    char exp;
    while(!actual.eof())
    {
        actual >> act;
        expected >> exp;
        QCOMPARE(act, exp);
    }
    actual.close();
    expected.close();
}

//сортировка  отсортированного файла
void TstTest::sortSort()
{
    container c;
    init(c);
    ifstream ifst;
    ifst.open("to_sort.txt");
    ofstream ofst;
    ofst.open("sort.txt");
    In(c, ifst);
    sort(c);
    Out(c, ofst);
    ifst.close();
    ofst.close();
    ifstream actual;
    actual.open("sort.txt");
    ifstream expected;
    expected.open("yes_sort.txt");
    char act;
    char exp;
    while(!actual.eof())
    {
        actual >> act;
        expected >> exp;
        QCOMPARE(act, exp);
    }
    actual.close();
    expected.close();
}


//сортировка  файла отсортированного в обратном порядке
void TstTest::sortAsort()
{
    container c;
    init(c);
    ifstream ifst;
    ifst.open("to_asort.txt");
    ofstream ofst;
    ofst.open("sort2.txt");
    In(c, ifst);
    sort(c);
    Out(c, ofst);
    ifst.close();
    ofst.close();
    ifstream actual;
    actual.open("sort2.txt");
    ifstream expected;
    expected.open("yes_sort.txt");
    char act;
    char exp;
    while(!actual.eof())
    {
        actual >> act;
        expected >> exp;
        QCOMPARE(act, exp);
    }
    actual.close();
    expected.close();
}
//сортировка  файла с одним элементом

void TstTest::sortAlone()
{
    container c;
    init(c);
    ifstream ifst;
    ifst.open("to_alone.txt");
    ofstream ofst;
    ofst.open("sort3.txt");
    In(c, ifst);
    sort(c);
    Out(c, ofst);
    ifst.close();
    ofst.close();
    ifstream actual;
    actual.open("sort3.txt");
    ifstream expected;
    expected.open("yes_alone_sort.txt");
    char act;
    char exp;
    while(!actual.eof())
    {
        actual >> act;
        expected >> exp;
        QCOMPARE(act, exp);
    }
    actual.close();
    expected.close();
}

//сортировка пустого файла
void TstTest::sortZero()
{
    container c;
    init(c);
    ifstream ifst;
    ifst.open("to_zero.txt");
    ofstream ofst;
    ofst.open("sort4.txt");
    In(c, ifst);
    sort(c);
    Out(c, ofst);
    ifst.close();
    ofst.close();
    ifstream actual;
    actual.open("sort4.txt");
    ifstream expected;
    expected.open("yes_zero_sort.txt");
    char act;
    char exp;
    while(!actual.eof())
    {
        actual >> act;
        expected >> exp;
        QCOMPARE(act, exp);
    }
    actual.close();
    expected.close();
}
//тест с пустым файлом
void TstTest::testZero()
{
    container c;
    init(c);
    ifstream ifst;
    ifst.open("to_zero.txt");
    ofstream ofst;
    ofst.open("out_zero.txt");
    In(c, ifst);
    Out(c, ofst);
    ifst.close();
    ofst.close();
    ifstream actual;
    actual.open("out_zero.txt");
    ifstream expected;
    expected.open("yes_zero.txt");
    char act;
    char exp;
    while(!actual.eof())
    {
        actual >> act;
        expected >> exp;
        QCOMPARE(act, exp);
    }
    actual.close();
    expected.close();
}

//тест с одним элементом
void TstTest::testAlone()
{
    container c;
    init (c);
    ifstream ifst;
    ifst.open("to_alone.txt");
    ofstream ofst;
    ofst.open("out_alone.txt");
    In(c, ifst);
    Out(c, ofst);
    ifst.close();
    ofst.close();
    ifstream actual;
    actual.open("out_alone.txt");
    ifstream expected;
    expected.open("yes_alone.txt");
    char act;
    char exp;
    while(!actual.eof())
    {
        actual >> act;
        expected >> exp;
        QCOMPARE(act, exp);
    }
    actual.close();
    expected.close();
}


////тест функции вывода только деревьев
void TstTest::testOnlyTree()
{
    container c;
    init(c);
    ifstream ifst;
    ifst.open("in.txt");
    ofstream ofst;
    ofst.open("out_tree.txt");
    In(c, ifst);
    outTrees(c, ofst);
    ifst.close();
    ofst.close();
    ifstream actual;
    actual.open("out_tree.txt");
    ifstream expected;
    expected.open("yes_tree.txt");
    char act;
    char exp;
    while(!actual.eof())
    {
        actual >> act;
        expected >> exp;
        QCOMPARE(act, exp);
    }
    actual.close();
    expected.close();
}



//тесты функции cогласных
//разного регистра
void TstTest::TestConsonant_count()
{
    plant p;
    p.name="Beresa";
    int act=consonant_count(p);
    int exp=3;
    QCOMPARE(act, exp);
    }
//без согласных
void TstTest::TestConsonant_count2()
{
    plant p;
    p.name="Aea";
    int act=consonant_count(p);
    int exp=0;
    QCOMPARE(act, exp);
    }
//с повторяющейся буквой
void TstTest::TestConsonant_count3()
{
    plant p;
    p.name="kaktus";
    int act=consonant_count(p);
    int exp=4;
    QCOMPARE(act, exp);
    }
//только согласные
void TstTest::TestConsonant_count4()
{
    plant p;
    p.name="qwrtypsdfghklzxcvbnm";
    int act=consonant_count(p);
    int exp=20;
    QCOMPARE(act, exp);
    }
//тест сравнения
void TstTest::TestCompare()
{
    plant *a;
    a=new plant;
    a->name="beresa";
    plant *b;
    b=new plant;
    b->name="romashka";
    bool act= compare(a,b);
    bool exp = true;
    QCOMPARE(act, exp);
    a->name="romashka";
    b->name="beresa";
    bool act1= compare(a,b);
    bool exp1 = false;
    QCOMPARE(act1, exp1);
    a->name="romashka";
    b->name="romashka";
    bool act2= compare(a,b);
    bool exp2 = false;
    QCOMPARE(act2, exp2);

}




//тест на определение количества элементов в файле
void TstTest::testIn2()
{
    container c;
    init (c);
    ifstream ifst;
    ifst.open("in.txt");
    In(c,ifst);
    int actuallen = c.len;
    int expectedlen = 7;
    QCOMPARE(actuallen, expectedlen);

}



//тест на очистку контейнера
void TstTest::ContainerClear()
{
    container c;
    init (c);
    ifstream ifst;
    ifst.open("in.txt");
    In(c,ifst);
    clear (c);
    int act = c.len;
    int exp = 0;
    QCOMPARE(act, exp);
}

//тест инициализации контейнера
void TstTest::ContainerInit()
{
    container c;
    init (c);
    int actualLen = c.len;
    int expectedLen = 0;
    QCOMPARE(actualLen, expectedLen);
}





QTEST_APPLESS_MAIN(TstTest)

#include "tst_tsttest.moc"
