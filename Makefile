CXX ?= g++
CXXFLAGS ?= -std=gnu++17 -O2 -Wall -Wextra
OJ := $(shell command -v oj 2>/dev/null)
TESTROOT ?= test
ABC_MAX ?= 385
PROB ?= a

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

.PHONY: build run set test download randa clean help
.PHONY: b r s t d c n h ra
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
	@contest="$$(basename $$(dirname $$(dirname "$(SRC)")))"; \
	prob="$$(basename $$(dirname "$(SRC)"))"; \
	num="$$(basename "$(SRC)" .cpp)"; \
	contest_lc="$$(echo "$$contest" | tr 'A-Z' 'a-z')"; \
	url="$(URL)"; \
	if [ -z "$$url" ]; then \
		if [ "$$contest_lc" = "abc" ] || [ "$$contest_lc" = "arc" ]; then \
			contest_id="$$contest_lc$$num"; \
			url="https://atcoder.jp/contests/$$contest_id/tasks/$$contest_id"_$$prob; \
			echo "Auto URL: $$url"; \
		else \
			echo "URL is required for this SRC. Usage: make download URL=https://atcoder.jp/contests/abc273/tasks/abc273_a"; \
			echo "See: make help"; \
			exit 1; \
		fi; \
	fi; \
	testdir="$(TESTROOT)/$${contest_lc}$${num}_$${prob}"; \
	if [ -n "$(DOWNLOAD_FORCE)" ]; then \
		rm -rf "$$testdir"; \
	fi; \
	mkdir -p "$$testdir"; \
	oj download --directory "$$testdir" "$$url"

test: $(BIN)
	@contest="$$(basename $$(dirname $$(dirname "$(SRC)")))"; \
	prob="$$(basename $$(dirname "$(SRC)"))"; \
	num="$$(basename "$(SRC)" .cpp)"; \
	contest_lc="$$(echo "$$contest" | tr 'A-Z' 'a-z')"; \
	testdir="$(TESTROOT)/$${contest_lc}$${num}_$${prob}"; \
	if [ -n "$(OJ)" ] && [ -d "$$testdir" ]; then \
		oj test -c "$(BIN)" -d "$$testdir"; \
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

randa:
	@attempts=0; \
	while :; do \
		num="$$(awk -v max="$(ABC_MAX)" 'BEGIN{srand(); printf "%d", int(1+rand()*max)}')"; \
		num_padded="$$(printf "%03d" "$$num")"; \
		src="ABC/$(PROB)/$${num_padded}.cpp"; \
		if [ ! -f "$$src" ]; then break; fi; \
		attempts=$$((attempts+1)); \
		if [ "$$attempts" -ge 50 ]; then \
			echo "No available problem found after $$attempts attempts. Try increasing ABC_MAX or changing PROB."; \
			exit 1; \
		fi; \
	done; \
	url="https://atcoder.jp/contests/abc$${num_padded}/tasks/abc$${num_padded}_$(PROB)"; \
	echo "Random ABC $(PROB): $$src"; \
	echo "URL: $$url"; \
	mkdir -p "$$(dirname "$$src")"; \
	cp .vscode/format.cpp "$$src"; \
	$(MAKE) download URL="$$url" SRC="$$src"

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
c: clean
n: new
h: help
ra: randa

help:
	@echo "make targets:"
	@echo "  build (b)    : SRC をビルドして build/main を作成"
	@echo "  run (r)      : 生成済みバイナリを実行"
	@echo "  set (s)      : .vscode/format.cpp を SRC に上書き"
	@echo "  new (n)      : テンプレ生成 (例: make new ABC 999 a)"
	@echo "  download (d) : oj でサンプル取得 (URL=... 省略時は SRC から自動生成)"
	@echo "                 既存を上書きしたい場合は DOWNLOAD_FORCE=1"
	@echo "                 保存先は $(TESTROOT)/<contest><num>_<prob> 形式"
	@echo "  test (t)     : テスト実行 (oj または in/out)"
	@echo "  randa (ra)   : ABC の問題をランダム取得 (PROB=$(PROB), ABC_MAX=$(ABC_MAX))"
	@echo "  clean (c)    : build/ を削除"
