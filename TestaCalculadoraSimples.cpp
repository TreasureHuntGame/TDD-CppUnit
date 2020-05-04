#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include "CalculadoraSimples.hpp"

using namespace CppUnit;

class TestaCalculadoraSimples : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(TestaCalculadoraSimples);
    CPPUNIT_TEST(testaSoma);
    CPPUNIT_TEST(testaSubtrai);
    CPPUNIT_TEST(testaMultiplicacao);
    CPPUNIT_TEST(testaDivisaoInteira);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void testaSoma(void);
    void testaSubtrai(void);
    void testaMultiplicacao(void);
    void testaDivisaoInteira(void);

private:
    CalculadoraSimples *objetoDeTeste;
};

void TestaCalculadoraSimples::testaSoma(void) {
    CPPUNIT_ASSERT(5 == objetoDeTeste -> Soma (2, 3));
}

void TestaCalculadoraSimples::testaSubtrai(void) {
    CPPUNIT_ASSERT(-1 == objetoDeTeste -> Subtrai (2, 3));
}

void TestaCalculadoraSimples::testaMultiplicacao(void) {
    CPPUNIT_ASSERT(6 == objetoDeTeste -> Multiplicacao(2, 3));
}

void TestaCalculadoraSimples::testaDivisaoInteira(void) {
    CPPUNIT_ASSERT(0 == objetoDeTeste -> DivisaoInteira(2, 3));
}

void TestaCalculadoraSimples::setUp(void) {
    objetoDeTeste = new CalculadoraSimples();
}

void TestaCalculadoraSimples::tearDown(void) {
    delete objetoDeTeste;
}

CPPUNIT_TEST_SUITE_REGISTRATION(TestaCalculadoraSimples);

int main() {

    CPPUNIT_NS::TestResult testresult;

    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener(&collectedresults);

    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener(&progress);

    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
    testrunner.run(testresult);

    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();

    return collectedresults.wasSuccessful() ? 0 : 1;
}