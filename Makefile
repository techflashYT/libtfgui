WARN=-Wall -Wextra -std=gnu2x
CFLAGS=-fpic $(WARN) -Iinclude -MMD -MP
LDFLAGS=-shared -flto
LDFLAGS_TEST=-ltfgui -Lbin -Wl,-rpath=bin -Wl,-rpath=./
CC=gcc
LD=gcc
OUT=bin/libtfgui.so
BIN=bin/test

CFILES = $(shell find src/ -name '*.c')
CFILES_TEST = $(shell find test/ -name '*.c')
DEPENDS := $(patsubst src/%.c,build/lib/%.d,$(CFILES))
DEPENDS_TEST := $(patsubst test/%.c,build/test/%.d,$(CFILES))

OBJ = $(patsubst src/%.c,build/lib/%.o,$(CFILES))
OBJ_TEST = $(patsubst test/%.c,build/test/%.o,$(CFILES_TEST))

.PHONY: all clean
all: $(OUT) $(BIN)

-include $(DEPENDS)
$(BIN): $(OBJ_TEST)
	@mkdir -p $(@D)
	@$(info $s  LD $(patsubst build/test/%.o,%.o,$^) ==> $@)
	$(LD) $(LDFLAGS_TEST) $^ -o $@

$(OUT): $(OBJ)
	@mkdir -p $(@D)
	@$(info $s  LD $(patsubst build/lib/%.o,%.o,$^) ==> $@)
	@$(LD) $(LDFLAGS) $^ -o $@

build/lib/%.o: src/%.c
	@mkdir -p $(@D)
	@$(info $s  CC $(patsubst src/%.c,%.c,$<) ==> $(patsubst build/%.o,%.o,$@))
	@$(CC) $(CFLAGS) -flto -c $< -o $@

build/test/%.o: test/%.c
	@mkdir -p $(@D)
	@$(info $s  CC $(patsubst test/%.c,%.c,$<) ==> $(patsubst build/%.o,%.o,$@))
	@$(CC) $(CFLAGS) -c $< -o $@


clean:
	@rm -rf $(OUT) build





