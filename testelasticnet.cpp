#include <QtTest/QtTest>
#include "VertexController.cpp"
#include "Iterator.cpp"

class TestElasticNet: public QObject
{
  Q_OBJECT
 private slots:
  void Temperature();
  void TempCurve();
};


void TestElasticNet::Temperature()
{
	Iterator a {0,0,0,0,0};
	QCOMPARE(a.temperatur(0), 0.002);
}

void TestElasticNet::TempCurve()
{
	Iterator a {0,0,0,0,0};
	QCOMPARE(a.temp_curve(50000), 0.00004317124);
}


QTEST_MAIN(TestElasticNet)
#include "testelasticnet.moc"