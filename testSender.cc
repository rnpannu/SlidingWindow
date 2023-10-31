#include "Sender.h"
#include "gtest/gtest.h"

/*
class SenderTest : public testing::Test {
    protected:
        Sender* w_;
    void SetUp()  override {
        w_ = new Sender(0);
    }
    void TearDown() override {
        delete w_;
    }
};*/

TEST(testSender, setSizeTest){
    Sender* w_;
    w_ = new Sender(0);

    w_->setWinSize(0);
    ASSERT_FALSE(w_->canAddNew());

    delete w_;
}

TEST(testSender, addNewTest){
    Sender* w_;
    w_ = new Sender(0);

    w_->setWinSize(2);
    EXPECT_EQ(w_->addNew(), 0);
    EXPECT_EQ(w_->nrSeqInWin(), 1);
    EXPECT_EQ(w_->addNew(), 1);
    EXPECT_EQ(w_->addNew(), -1);
    EXPECT_EQ(w_->nrSeqInWin(), 2);

    delete w_;
}

TEST(testSender, testAck){
    Sender* w_;
    w_ = new Sender(0);

    w_->setWinSize(2);
    EXPECT_EQ(w_->addNew(), 0);
    EXPECT_EQ(w_->nrSeqInWin(), 1);
    EXPECT_EQ(w_->addNew(), 1);
    EXPECT_EQ(w_->nrSeqInWin(), 2);
    w_->acknowledge(1);
    EXPECT_EQ(w_->nrSeqInWin(), 1);

    delete w_;
}
