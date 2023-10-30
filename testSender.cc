#include "Sender.h"
#include "gtest/gtest.h"

class SenderTest : public testing::Test {
    protected:
        Sender* w_;
    void SetUp()  override {
        w_ = new Sender();
    }
    void TearDown() override {
        delete w_;
    }
};

TEST_F(SenderTest, )
