#include "Sender.h"
#include "SlidingWindow.h"
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
    SlidingWindow* w_;
    w_ = new SlidingWindow(1);

    w_->setWinSize(1);
    ASSERT_FALSE(w_->canAddNew());

    delete w_;
}

TEST(testSender, addNewTest){
    SlidingWindow* w_;
    w_ = new SlidingWindow(3);

    w_->setWinSize(2);
    EXPECT_EQ(w_->addNew(), 0);
    EXPECT_EQ(w_->nrSeqInWin(), 1);

    std::cout << "HASJHAOBHROA" << std::endl;
    w_->acknowledge(0);
    EXPECT_EQ(w_->addNew(), 1);
    EXPECT_EQ(w_->addNew(), -1);
    EXPECT_EQ(w_->nrSeqInWin(), 2);

    delete w_;
}

TEST(testSender, testAck){
    SlidingWindow* w_;
    w_ = new SlidingWindow(0);

    w_->setWinSize(2);
    EXPECT_EQ(w_->addNew(), 0);
    EXPECT_EQ(w_->nrSeqInWin(), 1);
    EXPECT_EQ(w_->addNew(), 1);
    EXPECT_EQ(w_->nrSeqInWin(), 2);
    w_->acknowledge(1);
    EXPECT_EQ(w_->nrSeqInWin(), 1);

    delete w_;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}