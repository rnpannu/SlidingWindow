#include "SlidingWindow.h"
#include "Receiver.h"
#include "gtest/gtest.h"


class ReceiverTest : public testing::Test {
protected:
    SlidingWindow* w_;

    void SetUp() override {
        w_ = new Receiver(3);
    }
    void TearDown() override {
        delete w_;
    }
};

TEST_F(ReceiverTest, ReceiversetSizeTest){
    w_->setWinSize(0);
    ASSERT_FALSE(w_->canAddNew());
}

TEST_F(ReceiverTest, ReceiveraddNewTest){
    w_->setWinSize(2);
    EXPECT_EQ(w_->addNew(), 0);
    EXPECT_EQ(w_->nrSeqInWin(), 1);
    EXPECT_EQ(w_->addNew(), 1);
    EXPECT_EQ(w_->addNew(), -1);
    EXPECT_EQ(w_->nrSeqInWin(), 2);
}

TEST_F(ReceiverTest, ReceivertestAck){
    w_->setWinSize(2);
    EXPECT_EQ(w_->addNew(), 0);
    EXPECT_EQ(w_->nrSeqInWin(), 1);
    EXPECT_EQ(w_->addNew(), 1);
    EXPECT_EQ(w_->nrSeqInWin(), 2);
    w_->acknowledge(1);
    EXPECT_EQ(w_->nrSeqInWin(), 1);
}
