CC = g++
TESTLIBS = -lgtest  -lgtest_main -lpthread
OBJS = SlidingWindow.o testSender.o testReceiver.o Sender.o Receiver.o
# HEADERDIRS =
# CCFLAGS = -I $(HEADERDIRS)

testSH: $(OBJS)
	$(CC) -o $@  $(OBJS) $(TESTLIBS)

%.o : %.cc
	$(CC) $(CCFLAGS) -c $<
	$(CC) $(CCFLAGS) -MM -MP -MT $@ $< > $(basename $@).d


.PHONY : clean
clean :
	rm -f *.o *~ *.d


## include the generated dependency files
-include $(addsuffix .d,$(basename $(OBJS)))

