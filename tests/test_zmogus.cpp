/**
 * @file test_zmogus.cpp
 * @brief Unit testai Zmogus bazinei klasei
 * @details Testuoja abstrakčią klasę per Studentas išvestinę klasę
 */

#include <gtest/gtest.h>
#include "../zmogus.h"
#include "../studentas.h"

using namespace std;

// 1. ABSTRAKČIOS KLASĖS TESTAS
/**
 * @test Testuoja ar Zmogus yra tikrai abstrakti klasė (negalima instancijuoti)
 * @note Šis testas patikrina, kad sistema veikia per išvestinę klasę
 */
TEST(ZmogusTest, AbstrakciKlase_VeikiaTikPerStudenta) {
    // Zmogus z; // Ši eilutė sukeltų kompiliavimo klaidą

    // Bet galima sukurti per išvestinę klasę
    Studentas s("Vardas", "Pavarde");
    
    EXPECT_EQ(s.vard(), "Vardas");
    EXPECT_EQ(s.pav(), "Pavarde");
}

// 2. PAVELDĖJIMO TESTAI
/**
 * @test Testuoja ar vardas paveldimas iš Zmogus klasės
 */
TEST(ZmogusTest, VardoPaveldejimasIsZmogus) {
    Studentas s;
    s.setVard("Petras");
    
    EXPECT_EQ(s.vard(), "Petras");
}

/**
 * @test Testuoja ar pavardė paveldima iš Zmogus klasės
 */
TEST(ZmogusTest, PavardesPaveldejimasIsZmogus) {
    Studentas s;
    s.setPav("Petraitis");
    
    EXPECT_EQ(s.pav(), "Petraitis");
}

/**
 * @test Testuoja ar set'eriai veikia per paveldėjimą
 */
TEST(ZmogusTest, SeteriaiVeikiaPaveldejimu) {
    Studentas s;
    s.setVard("Antanas");
    s.setPav("Antanaitis");
    
    EXPECT_EQ(s.vard(), "Antanas");
    EXPECT_EQ(s.pav(), "Antanaitis");
}