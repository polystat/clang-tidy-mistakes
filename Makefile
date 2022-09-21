FN = $(wildcard false-negative/**.cpp)
FNR = $(subst false-negative/,fnr/,${FN:.cpp=.txt})
FP = $(wildcard false-positive/**.cpp)
FPR = $(subst false-positive/,fpr/,${FP:.cpp=.txt})

.PHONY: fpr fnr clean

tidy: ${FPR} ${FNR}

fpr/%.txt: false-positive/%.cpp | fpr
	clang-tidy $< | tee $@

fnr/%.txt: false-negative/%.cpp | fnr
	clang-tidy $< | tee $@

fpr:
	mkdir -p fpr

fnr:
	mkdir -p fnr

clean:
	rm -rf fpr
	rm -rf fnr