SOURCES = $(wildcard **/*.cpp)
REPORTS = $(subst src/,reports/,${SOURCES:.cpp=.txt})

.PHONY: reports

tidy: ${REPORTS}

reports/%.txt: src/%.cpp | reports
	clang-tidy $< | tee $@

reports:
	mkdir -p reports