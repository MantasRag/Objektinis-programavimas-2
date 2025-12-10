/**
 * @file test_studentas.cpp
 * @brief Unit testai Studentas klasei
 * @details Demonstruoja TDD (Test Driven Development) principą:
 *          Pirma rašomi testai, paskui realizuojamos funkcijos.
 */

#include <gtest/gtest.h>
#include "../studentas.h"
#include "../pagalbines_funkcijos.h"
#include <vector>

using namespace std;

//  Testavimo aplinka Studentas klasės testavimui
class StudentasTest : public ::testing::Test {
protected:
    Studentas studentas;
    
    void SetUp() override {
        // Vykdoma prieš kiekvieną testą
        studentas = Studentas("Jonas", "Jonaitis");
    }
};

// 1. KONSTRUKTORIŲ TESTAI
/**
 * @test Testuoja ar tuščias konstruktorius sukuria objektą su tuščiais laukais
 */
TEST_F(StudentasTest, TusciasKonstruktorius) {
    Studentas s;
    
    EXPECT_EQ(s.vard(), "");
    EXPECT_EQ(s.pav(), "");
    EXPECT_EQ(s.egzas(), 0);
    EXPECT_TRUE(s.paz().empty());
}

/**
 * @test Testuoja ar konstruktorius su parametrais teisingai priskiria vardą ir pavardę
 */
TEST_F(StudentasTest, KonstruktoriusSuParametrais) {
    EXPECT_EQ(studentas.vard(), "Jonas");
    EXPECT_EQ(studentas.pav(), "Jonaitis");
}

// 2. PAŽYMIŲ PRIDĖJIMO TESTAI
/**
 * @test Testuoja ar pažymys teisingai pridedamas į vektorių
 */
TEST_F(StudentasTest, PazymioPridejimas) {
    studentas.addPazymys(8);

    ASSERT_EQ(studentas.paz().size(), 1);
    EXPECT_EQ(studentas.paz()[0], 8);
}

/**
 * @test Testuoja ar keli pažymiai teisingai pridedami
 */
TEST_F(StudentasTest, KeliuPazymiuPridejimas) {
    studentas.addPazymys(7);
    studentas.addPazymys(8);
    studentas.addPazymys(9);
    
    EXPECT_EQ(studentas.paz().size(), 3);
    EXPECT_EQ(studentas.paz()[0], 7);
    EXPECT_EQ(studentas.paz()[1], 8);
    EXPECT_EQ(studentas.paz()[2], 9);
}

// 3. REZULTATŲ SKAIČIAVIMO TESTAI
/**
 * @test Testuoja ar galutinis rezultatas teisingai skaičiuojamas pagal vidurkį
 * Formulė: galutinis = 0.6 * egzaminas + 0.4 * vidurkis
 */
TEST_F(StudentasTest, RezultatoSkaiciavimas_Vidurkis) {
    studentas.addPazymys(8);
    studentas.addPazymys(9);
    studentas.addPazymys(7);
    studentas.setEgzas(10);
    
    vector<int> paz_copy = studentas.paz();
    float mediana = sk_mediana(paz_copy);
    studentas.skaiciuotiRezultatus(1, mediana); // 1 = vidurkis
    
    // Tikėtinas rezultatas: 9.2
    EXPECT_NEAR(studentas.rez_vid(), 9.2, 0.01);
}

/**
 * @test Testuoja ar galutinis rezultatas teisingai skaičiuojamas pagal medianą
 * Formulė: galutinis = 0.6 * egzaminas + 0.4 * mediana
 */
TEST_F(StudentasTest, RezultatoSkaiciavimas_Mediana) {
    studentas.addPazymys(6);
    studentas.addPazymys(8);
    studentas.addPazymys(10);
    studentas.setEgzas(9);
    
    vector<int> paz_copy = studentas.paz();
    float mediana = sk_mediana(paz_copy); // mediana = 8
    studentas.skaiciuotiRezultatus(2, mediana); // 2 = mediana
    
    // Tikėtinas rezultatas: 8.6
    EXPECT_NEAR(studentas.rez_med(), 8.6, 0.01);
}

// 4. KOPIJAVIMO TESTAI (Rule of Three)
/**
 * @test Testuoja ar kopijavimo konstruktorius teisingai kopijuoja duomenis
 */
TEST_F(StudentasTest, KopijavimoKonstruktorius) {
    studentas.addPazymys(7);
    studentas.setEgzas(9);
    
    Studentas kopija(studentas);
    
    EXPECT_EQ(kopija.vard(), studentas.vard());
    EXPECT_EQ(kopija.egzas(), studentas.egzas());
    EXPECT_EQ(kopija.paz().size(), studentas.paz().size());
}

/**
 * @test Testuoja ar kopijavimo operatorius veikia teisingai
 */
TEST_F(StudentasTest, KopijavimoOperatorius) {
    studentas.addPazymys(8);
    studentas.setEgzas(10);
    
    Studentas kopija;
    kopija = studentas;
    
    EXPECT_EQ(kopija.vard(), studentas.vard());
    EXPECT_EQ(kopija.egzas(), studentas.egzas());
}
