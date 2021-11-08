
BOOT ?= bins/build13.bc

default: bin/stage3

bin/stage1: src/paka.paka
	./minivm/minivm $(BOOT) src/paka.paka -o $@

bin/stage2: bin/stage1
	./minivm/minivm bin/stage1 src/paka.paka -o $@

bin/stage3: bin/stage2
	./minivm/minivm bin/stage2 src/paka.paka -o $@

clean: .dummy
	$(MAKE) -C minivm clean
	rm -r bin

.dummy:

