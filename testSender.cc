#include "SlidingWindow.h"
#include "Sender.h"
#include "gtest/gtest.h"


class SenderTest : public testing::Test {
protected:
    SlidingWindow* w_;

    void SetUp() override {
        w_ = new Sender(3);
    }
    void TearDown() override {
        delete w_;
    }
};

TEST_F(SenderTest, SendersetSizeTest){
    w_->setWinSize(0);
    ASSERT_FALSE(w_->canAddNew());
}

TEST_F(SenderTest, SenderaddNewTest){
    w_->setWinSize(2);
    EXPECT_EQ(w_->addNew(), 0);
    EXPECT_EQ(w_->nrSeqInWin(), 1);
    EXPECT_EQ(w_->addNew(), 1);
    EXPECT_EQ(w_->addNew(), -1);
    EXPECT_EQ(w_->nrSeqInWin(), 2);
}

TEST_F(SenderTest, SendertestAck){
    w_->setWinSize(2);
    EXPECT_EQ(w_->addNew(), 0);
    EXPECT_EQ(w_->nrSeqInWin(), 1);
    EXPECT_EQ(w_->addNew(), 1);
    EXPECT_EQ(w_->nrSeqInWin(), 2);
    w_->acknowledge(1);
    EXPECT_EQ(w_->nrSeqInWin(), 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
