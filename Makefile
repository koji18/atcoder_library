CXX ?= g++
CXXFLAGS ?= -std=gnu++17 -O2 -Wall -Wextra
OJ := $(shell command -v oj 2>/dev/null)
OJ_PREPARE := $(shell command -v oj-prepare 2>/dev/null)
TESTDIR ?= test

ifeq ($(firstword $(MAKECMDGOALS)),new)
NEW_CONTEST := $(word 2,$(MAKECMDGOALS))
NEW_NUM := $(word 3,$(MAKECMDGOALS))
NEW_PROB := $(word 4,$(MAKECMDGOALS))
endif

ifdef ACTIVE_FILE
SRC ?= $(ACTIVE_FILE)
endif
SRC ?= $(shell find ABC ARC paiza -name '*.cpp' -type f -printf '%T@ %p\n' 2>/dev/null | sort -nr | head -n1 | cut -d' ' -f2-)
BIN ?= build/main
INPUT ?=

ifeq ($(strip $(SRC)),)
$(error SRC is not set and no .cpp files were found)
endif

.PHONY: build run set test download prepare clean help
.PHONY: b r s t d p c n h
.PHONY: new

build: $(BIN)

$(BIN): $(SRC)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $< -o $@

run: $(BIN)
	@echo "Running: $(SRC)"
	@if [ -n "$(INPUT)" ]; then $(BIN) < "$(INPUT)"; else $(BIN); fi

set:
	@mkdir -p .vscode
	cp .vscode/format.cpp "$(SRC)"

download:
	@if [ -z "$(OJ)" ]; then \
		echo "oj not found. Install with: pip3 install online-judge-tools"; \
		echo "See: make help"; \
		exit 1; \
	fi
	@if [ -z "$(URL)" ]; then \
		contest="$$(basename $$(dirname $$(dirname "$(SRC)")))"; \
		prob="$$(basename $$(dirname "$(SRC)"))"; \
		num="$$(basename "$(SRC)" .cpp)"; \
		contest_lc="$$(echo "$$contest" | tr 'A-Z' 'a-z')"; \
		if [ "$$contest_lc" = "abc" ] || [ "$$contest_lc" = "arc" ]; then \
			contest_id="$$contest_lc$$num"; \
			URL="https://atcoder.jp/contests/$$contest_id/tasks/$$contest_id"_$$prob; \
			echo "Auto URL: $$URL"; \
		else \
			echo "URL is required for this SRC. Usage: make download URL=https://atcoder.jp/contests/abc273/tasks/abc273_a"; \
			echo "See: make help"; \
			exit 1; \
		fi; \
	fi
	@mkdir -p "$(TESTDIR)"
	oj download --directory "$(TESTDIR)" "$(URL)"

test: $(BIN)
	@if [ -n "$(OJ)" ] && [ -d "$(TESTDIR)" ]; then \
		oj test -c "$(BIN)" -d "$(TESTDIR)"; \
	elif ls in/*.txt >/dev/null 2>&1; then \
		for f in in/*.txt; do \
			b="$${f##*/}"; \
			o="out/$${b}"; \
			echo "==> $$f"; \
			if [ -f "$$o" ]; then \
				"$(BIN)" < "$$f" | diff -u "$$o" - || exit $$?; \
			else \
				"$(BIN)" < "$$f"; \
			fi; \
		done; \
	else \
		echo "No tests found. Use: make download URL=... or place files in in/ and out/"; \
		echo "See: make help"; \
		exit 1; \
	fi

prepare:
	@if [ -z "$(OJ_PREPARE)" ]; then \
		echo "oj-prepare not found. Install from: https://github.com/online-judge-tools/template-generator"; \
		echo "See: make help"; \
		exit 1; \
	fi
	@if [ -z "$(URL)" ]; then \
		contest="$$(basename $$(dirname $$(dirname "$(SRC)")))"; \
		num="$$(basename "$(SRC)" .cpp)"; \
		contest_lc="$$(echo "$$contest" | tr 'A-Z' 'a-z')"; \
		if [ "$$contest_lc" = "abc" ] || [ "$$contest_lc" = "arc" ]; then \
			contest_id="$$contest_lc$$num"; \
			URL="https://atcoder.jp/contests/$$contest_id"; \
			echo "Auto URL: $$URL"; \
		else \
			echo "URL is required for this SRC. Usage: make prepare URL=https://atcoder.jp/contests/abc273"; \
			echo "See: make help"; \
			exit 1; \
		fi; \
	fi
	oj-prepare "$(URL)"

new:
	@if [ -z "$(NEW_CONTEST)" ] || [ -z "$(NEW_NUM)" ] || [ -z "$(NEW_PROB)" ]; then \
		echo "Usage: make new ABC 999 a"; \
		exit 1; \
	fi
	@mkdir -p "$(NEW_CONTEST)/$(NEW_PROB)"
	@if [ -e "$(NEW_CONTEST)/$(NEW_PROB)/$(NEW_NUM).cpp" ]; then \
		echo "Already exists: $(NEW_CONTEST)/$(NEW_PROB)/$(NEW_NUM).cpp"; \
		exit 1; \
	fi
	cp .vscode/format.cpp "$(NEW_CONTEST)/$(NEW_PROB)/$(NEW_NUM).cpp"

clean:
	rm -rf build

$(NEW_CONTEST) $(NEW_NUM) $(NEW_PROB):
	@:

# Single-letter aliases
b: build
r: run
s: set
t: test
d: download
p: prepare
c: clean
n: new
h: help

help:
	@echo "make targets:"
	@echo "  build (b)    : SRC をビルドして build/main を作成"
	@echo "  run (r)      : 生成済みバイナリを実行"
	@echo "  set (s)      : .vscode/format.cpp を SRC に上書き"
	@echo "  new (n)      : テンプレ生成 (例: make new ABC 999 a)"
	@echo "  download (d) : oj でサンプル取得 (URL=... 省略時は SRC から自動生成)"
	@echo "  test (t)     : テスト実行 (oj または in/out)"
	@echo "  prepare (p)  : oj-prepare でコンテスト一括準備 (URL=... 省略時は SRC から自動生成)"
	@echo "  clean (c)    : build/ を削除"
