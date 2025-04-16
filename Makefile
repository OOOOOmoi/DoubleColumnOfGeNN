GENERATED_CODE_DIR        := DoubleColumn_CODE
CXXFLAGS                  += -std=c++11 -Wall -Wpedantic -Wextra

.PHONY: all clean generated_code

OBJS                      := DoubleColumnSim.o RecordFunc.o

all: DoubleColumn

DoubleColumn: $(OBJS) generated_code
	$(CXX) $(CXXFLAGS) $(OBJS) -o DoubleColumn -L$(GENERATED_CODE_DIR) -lrunner -Wl,-rpath $(GENERATED_CODE_DIR)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

generated_code:
	$(MAKE) -C $(GENERATED_CODE_DIR)

clean:
	$(MAKE) -C $(GENERATED_CODE_DIR) clean
	rm -f $(OBJS) DoubleColumn
