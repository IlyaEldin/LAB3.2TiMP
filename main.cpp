#include <UnitTest++/UnitTest++.h>
#include </home/ilya/Lab1/Lab1/modAlphaCipher.h>
#include </home/ilya/Lab1/Lab1/modAlphaCipher.cpp>
#include </home/ilya/Lab1/Lab12/CesarDop.h>
#include </home/ilya/Lab1/Lab12/CesarDop.cpp>

string wstost (int k, wstring ws1) //переводит широкую строку в обычную для использования макроса CHECK_EQUAL
{
    Cs w(k);
    wstring wsw=w.Coder(w,ws1);
    const string a1( wsw.begin(), wsw.end() );
    return a1;
}
string wstost1 (int k, wstring ws2) //переводит широкую строку в обычную для использования макроса CHECK_EQUAL
{
    Cs w(k);
    wstring wsw=w.Decoder(k,ws2);
    const string a1( wsw.begin(), wsw.end() );
    return a1;
}
SUITE(KeyTest)
{
    TEST(ValidKey) {
        CHECK_EQUAL(wstost(3,L"HELLOCODE"),"HLOEODLCE");
    }
    TEST(NULLKEY) {
        int k=0;
        Cs w(k);
        wstring testtext=L"HELLOCODE";
        CHECK_THROW(w.Coder(w,testtext),cipher_error);
    }
    TEST(LongKEY) {
        int k=7;
        Cs w(k);
        wstring testtext=L"HELLOCODE";
        CHECK_THROW(w.Coder(w,testtext),cipher_error);
    }

}
SUITE(EncryptTest)
{
    TEST(ValidTEXT) {
        CHECK_EQUAL(wstost(3,L"HELLOCODE"),"HLOEODLCE");
    }
    TEST(LowTEXT) {
        CHECK_EQUAL(wstost(3,L"HelloCode"),"HLOEODLCE");
    }
    TEST(SpaceTEXT) {
        CHECK_EQUAL(wstost(3,L"HELLO CODE"),"HLOEODLCE");
    }
    TEST(NULLTEXT) {
        int k=3;
        Cs w(k);
        wstring testtext=L"";
        CHECK_THROW(w.Coder(w,testtext),cipher_error);
    }
}

SUITE(DecryptText)
{
    TEST(ValidTEXT) {
        CHECK_EQUAL(wstost1(3,L"HLOEODLCE"),"HELLOCODE");
    }
    TEST(LowTEXT) {
        CHECK_EQUAL(wstost1(3,L"HloeODlce"),"HELLOCODE");
    }
    TEST(SpaceTEXT) {
        CHECK_EQUAL(wstost1(3,L"HLOEO DLCE"),"HELLOCODE");
    }
    TEST(NULLTEXT) {
        int k=3;
        Cs w(k);
        wstring testtext=L"";
        CHECK_THROW(w.Decoder(k,testtext),cipher_error);
    }
}
int main(int argc, char **argv)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    return UnitTest::RunAllTests();
}
