CC=gcc

SRC_DIR = src
BIN_DIR = bin

# Binaries
INTEGRITY = $(BIN_DIR)/integrity_vuln
PASSWORD = $(BIN_DIR)/password_vuln
INTEGRITY_PROTECTED = $(BIN_DIR)/integrity_vuln_protected
PASSWORD_PROTECTED = $(BIN_DIR)/password_vuln_protected

all: $(INTEGRITY) $(PASSWORD)

# Compile
$(INTEGRITY): $(SRC_DIR)/integrity_vuln.c
	$(CC) -fno-stack-protector -o $(INTEGRITY) $(SRC_DIR)/integrity_vuln.c
$(PASSWORD): $(SRC_DIR)/password_vuln.c
	$(CC) -fno-stack-protector -o $(PASSWORD) $(SRC_DIR)/password_vuln.c

stacksafe: $(INTEGRITY_PROTECTED) $(PASSWORD_PROTECTED)

# Compile
$(INTEGRITY_PROTECTED): $(SRC_DIR)/integrity_vuln.c
	$(CC) -fstack-protector -o $(INTEGRITY_PROTECTED) $(SRC_DIR)/integrity_vuln.c
$(PASSWORD_PROTECTED): $(SRC_DIR)/password_vuln.c
	$(CC) -fstack-protector -o $(PASSWORD_PROTECTED) $(SRC_DIR)/password_vuln.c

clean:
	rm -f $(BIN_DIR)/*
