SOURCES = $(wildcard **/*.c)
REPORTS = $(subst src/,reports/,${SOURCES:.c=.txt})

.PHONY: reports

tidy: ${REPORTS}

reports/%.txt: src/%.c | reports
	clang-tidy $< | tee $@

reports:
	mkdir -p reports