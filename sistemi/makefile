CC=g++
CFLAGS= -O3 \
		--std=c++14 \
		-DSINGLE
BIN_DIR=bin

ES1_OBJ=$(BIN_DIR)/es1.o
ES2_OBJ=$(BIN_DIR)/es2.o
ES3_OBJ=$(BIN_DIR)/es3.o
UTILS_OBJ=$(BIN_DIR)/utils.o

EXE1=$(BIN_DIR)/es1.out
EXE2=$(BIN_DIR)/es2.out
EXE3=$(BIN_DIR)/es3.out

.PHONY: all clean

all: $(EXE1) $(EXE2) $(EXE3)

$(EXE1): $(ES1_OBJ) $(UTILS_OBJ) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(EXE2): $(ES2_OBJ) $(UTILS_OBJ) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(EXE3): $(ES3_OBJ) $(UTILS_OBJ) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^


$(UTILS_OBJ): utils.cpp utils.h | $(BIN_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(ES1_OBJ): es1.cpp utils.h | $(BIN_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(ES2_OBJ): es2.cpp utils.h | $(BIN_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(ES3_OBJ): es3.cpp utils.h | $(BIN_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<


clean:
	rm -f $(BIN_DIR)/*.o $(EXE1) $(EXE2) $(EXE3)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)
