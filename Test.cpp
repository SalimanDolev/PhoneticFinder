#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;


/////////////////////////////////////////////////////////////////////
////////////////////////Upper case Lower case////////////////////////
/////////////////////////////////////////////////////////////////////


TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    /* Add more checks here */
    CHECK(find(text, "HAPpI") == string("Happi"));
    
    string text2 = "worry xxx yyy";
    CHECK(find(text2, "Worry") == string("worry"));
    CHECK(find(text2, "WOrRy") == string("worry"));
    CHECK(find(text2, "woRry") == string("worry"));
    CHECK(find(text2, "WorRY") == string("worry"));
    CHECK(find(text2, "worrY") == string("worry"));
    

    string text3 = "be xxx yyy";
    CHECK(find(text3, "Be") == string("be"));
    CHECK(find(text3, "BE") == string("be"));
    CHECK(find(text3, "bE") == string("be"));

    string text4 = "Dont xxx yyy";
    CHECK(find(text4, "dont") == string("Dont"));
    CHECK(find(text4, "DoNt") == string("Dont"));
    CHECK(find(text4, "DONT") == string("Dont"));
    CHECK(find(text4, "DOnt") == string("Dont"));

    string text5 = "step xxx yyy";
    CHECK(find(text5, "Step") == string("step"));
    CHECK(find(text5, "STEP") == string("step"));
    CHECK(find(text5, "stEP") == string("step"));
    CHECK(find(text5, "SteP") == string("step"));

    string text6 = "basketBall xxx yyy";
    CHECK(find(text6, "BasketBAll") == string("basketBall"));
    CHECK(find(text6, "baskEtbAll") == string("basketBall"));
    CHECK(find(text6, "BaSketball") == string("basketBall"));
    CHECK(find(text6, "bAsKeTbAlL") == string("basketBall"));
    CHECK(find(text6, "BASKETBAlL") == string("basketBall"));

    string text7 = "Skateboard xxx yyy";
    CHECK(find(text7, "SkateBoarD") == string("Skateboard"));
    CHECK(find(text7, "SkAteboArd") == string("Skateboard"));
    CHECK(find(text7, "SKateboaRD") == string("Skateboard"));
    CHECK(find(text7, "SkateBOARD") == string("Skateboard"));
    CHECK(find(text7, "SKATEBOARD") == string("Skateboard"));

    string text8 = "SyStem xxx yyy";
    CHECK(find(text8, "System") == string("SyStem"));
    CHECK(find(text8, "system") == string("SyStem"));
    CHECK(find(text8, "SYStem") == string("SyStem"));
    CHECK(find(text8, "SYSTEM") == string("SyStem"));
    CHECK(find(text8, "SYSTEm") == string("SyStem"));

     string text9 = "ComPUTER xxx yyy";
    CHECK(find(text9, "ComPUTEr") == string("ComPUTER"));
    CHECK(find(text9, "COmPuTER") == string("ComPUTER"));
    CHECK(find(text9, "COMPUTER") == string("ComPUTER"));
    CHECK(find(text9, "ComPUTer") == string("ComPUTER"));
    CHECK(find(text9, "CompuTER") == string("ComPUTER"));
    CHECK(find(text9, "CoMpuTER") == string("ComPUTER"));

}
/////////////////////////////////////////////////////////////////////
////////////////////////Replacement//////////////////////////////////
/////////////////////////////////////////////////////////////////////


TEST_CASE("Test replacement of p and b") {
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
    /* Add more checks here */

    string text2 = "basketball xxx yyy";
    CHECK(find(text2, "pasketball") == string("basketball"));
    CHECK(find(text2, "basketpall") == string("basketball"));
    CHECK(find(text2, "pasketpall") == string("basketball"));
}

TEST_CASE("Test replacement of w and v") {
    string text = "xxx worry yyy";
    CHECK(find(text, "worry") == string("worry"));
    CHECK(find(text, "vorry") == string("worry"));

     string text2 = "xxx window yyy";
    CHECK(find(text2, "vindow") == string("window"));
    CHECK(find(text2, "windov") == string("window"));
    CHECK(find(text2, "vindov") == string("window"));
}

TEST_CASE("Test replacement of i and y") {
    string text = "xxx init yyy";
    CHECK(find(text, "ynit") == string("init"));
    CHECK(find(text, "inyt") == string("init"));
    CHECK(find(text, "ynyt") == string("init"));

     string text2 = "xxx information yyy";
    CHECK(find(text2, "informatyon") == string("information"));
    CHECK(find(text2, "ynformation") == string("information"));
    CHECK(find(text2, "ynformatyon") == string("information"));
}

TEST_CASE("Test replacement of o and u") {
    string text = "xxx organization yyy";
    CHECK(find(text, "urganization") == string("organization"));
    CHECK(find(text, "organizatiun") == string("organization"));
    CHECK(find(text, "urganizatiun") == string("organization"));

     string text2 = "xxx option yyy";
    CHECK(find(text2, "uption") == string("option"));
    CHECK(find(text2, "optiun") == string("option"));
    CHECK(find(text2, "uptiun") == string("option"));
}

TEST_CASE("Test replacement of c and q and k") {
    string text = "xxx conqueror yyy";
    CHECK(find(text, "qoncueror") == string("conqueror"));
    CHECK(find(text, "concueror") == string("conqueror"));
    CHECK(find(text, "konkueror") == string("conqueror"));
    CHECK(find(text, "konqueror") == string("conqueror"));
    CHECK(find(text, "qonkueror") == string("conqueror"));

     string text2 = "xxx control yyy";
    CHECK(find(text2, "kontrol") == string("control"));
    CHECK(find(text2, "qontrol") == string("control"));
}

TEST_CASE("Test replacement of g and j") {
    string text = "xxx judge yyy";
    CHECK(find(text, "gudge") == string("judge"));
    CHECK(find(text, "judje") == string("judge"));
    CHECK(find(text, "gudje") == string("judge"));

     string text2 = "xxx google yyy";
    CHECK(find(text2, "goojle") == string("google"));
    CHECK(find(text2, "joojle") == string("google"));
    CHECK(find(text2, "joogle") == string("google"));
}


TEST_CASE("Test replacement of f and p") {
    string text = "xxx fluffy yyy";
    CHECK(find(text, "flufpy") == string("fluffy"));
    CHECK(find(text, "fluppy") == string("fluffy"));
    CHECK(find(text, "pluppy") == string("fluffy"));
    CHECK(find(text, "pluffy") == string("fluffy"));

     string text2 = "xxx pop yyy";
    CHECK(find(text2, "fop") == string("pop"));
    CHECK(find(text2, "fof") == string("pop"));
    CHECK(find(text2, "pof") == string("pop"));
}

TEST_CASE("Test replacement of d and t") {
    string text = "xxx dictionary yyy";
    CHECK(find(text, "tictionary") == string("dictionary"));
    CHECK(find(text, "dicdionary") == string("dictionary"));
    CHECK(find(text, "ticdionary") == string("dictionary"));

     string text2 = "xxx dedicated yyy";
    CHECK(find(text2, "teticated") == string("dedicated"));
    CHECK(find(text2, "deticated") == string("dedicated"));
    CHECK(find(text2, "dedicaded") == string("dedicated"));
    CHECK(find(text2, "deticadet") == string("dedicated"));


    string text3 = "xxx tradition yyy";
    CHECK(find(text3, "dradition") == string("tradition"));
    CHECK(find(text3, "tratition") == string("tradition"));
    CHECK(find(text3, "dradidion") == string("tradition"));
    CHECK(find(text3, "tradidion") == string("tradition"));

     string text4 = "xxx trasition yyy";
    CHECK(find(text4, "drasition") == string("trasition"));
    CHECK(find(text4, "drasidion") == string("trasition"));
    CHECK(find(text4, "trasidion") == string("trasition"));
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////Wrong word//////////////////////////////
//////////////////////////////////////////////////////////////////////////

TEST_CASE("Test if the word is in the sentence") {
    
    string text = "xxx happy yyy";
    CHECK_THROWS(find(text, "happ"));
    
    string text2 = "xxx worry yyy";
    CHECK_THROWS(find(text, "worr"));
    
    string text3 = "xxx worry yyy";
    CHECK_THROWS(find(text, "dont"));
}
