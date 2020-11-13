#include "header.h"
#include "gtest/gtest.h"
using namespace  std;

TEST(GetChilsTest, fraaaac)
{
    ProperFraction frac(2,5);
    EXPECT_EQ(frac.GetChisl(),2);
}

TEST(GetZnamTest, fraaaac)
{
    ProperFraction frac(2,5);
    EXPECT_EQ(frac.GetZnam(),5);
}

TEST(ConstructorTest, PropFrac1)
{
    ProperFraction frac(1,5);
    EXPECT_EQ(frac.GetChisl(),1);
    EXPECT_EQ(frac.GetZnam(),5);
}
TEST(ConstructorTest_2, PropFrac2)
{
    ProperFraction frac(2,5);
    ProperFraction frac1(frac);
    EXPECT_EQ(frac.GetChisl(),frac1.GetChisl());
    EXPECT_EQ(frac.GetZnam(),frac1.GetZnam());
}
TEST(ReductionTest, PropFrac3)
{
    ProperFraction frac(123123,123123 );
    frac.Sokratit();
    EXPECT_EQ(frac.GetChisl(), 1);
    EXPECT_EQ(frac.GetZnam(), 1);
}


TEST(FunctionTest, Multiplication1)
{
    ProperFraction frac(1,3);
    ProperFraction frac2(-2,3);
    frac.umnozhit_na(frac2);
    EXPECT_EQ(frac.GetChisl(),-2);
    EXPECT_EQ(frac.GetZnam(),9);
}

TEST(FunctionTest, Multiplication2)
{
    ProperFraction frac(0,3);
    ProperFraction frac2(-2,3);
    frac.umnozhit_na(frac2);
    EXPECT_EQ(frac.GetChisl(),0);
}

TEST(FunctionTest, Addition)
{
    ProperFraction frac(1,3);
    ProperFraction frac2(2,3);
    frac.slozhit_s(frac2);
    EXPECT_EQ(frac.GetChisl(),9);
    EXPECT_EQ(frac.GetZnam(),9);
}

TEST(FunctionTest, Addition1)
{
    ProperFraction frac(1,3);
    ProperFraction frac2(-2,3);
    frac.slozhit_s(frac2);
    EXPECT_EQ(frac.GetChisl(),-3);
    EXPECT_EQ(frac.GetZnam(),9);
}

TEST(FunctionTest, Addition2)
{
    ProperFraction frac(2,-3);
    ProperFraction frac2(2,3);
    frac.slozhit_s(frac2);
    EXPECT_EQ(frac.GetChisl(),0);
}

TEST(FunctionTest, Division)
{
    ProperFraction frac(1,3);
    ProperFraction frac2(2,3);
    frac.delit_na(frac2);
    EXPECT_EQ(frac.GetChisl(),3);
    EXPECT_EQ(frac.GetZnam(),6);
}

TEST(FunctionTest, Division1)
{
    ProperFraction frac(0,3);
    ProperFraction frac2(2,3);
    frac.delit_na(frac2);
    EXPECT_EQ(frac.GetChisl(),0);
}

TEST(FunctionTest, Division2)
{
    ProperFraction frac(1,3);
    ProperFraction frac2(2,-3);
    frac.delit_na(frac2);
    EXPECT_EQ(frac.GetChisl(),-3);
    EXPECT_EQ(frac.GetZnam(),6);
}
