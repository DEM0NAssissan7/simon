v=1.0

simon: src/main.c src/simon.h
	gcc -g -o out/simon -Wall src/main.c

install:
	make
	cp out/simon /usr/bin/simon

rpm: rpm/simon.spec
	# Setup bulid environment
	cp rpm/simon.spec ~/rpmbuild/SPECS/simon.spec
	rsync -av --exclude=".*" . simon-$v

	rm ~/rpmbuild/SOURCES/simon-$v.tar.gz
	tar --create --file ~/rpmbuild/SOURCES/simon-$v.tar.gz simon-$v
	rm -r simon-$v

	# Build
	export CFLAGS="${RPM_OPT_FLAGS}"
	export CXXFLAGS="${RPM_OPT_FLAGS}"
	rpmbuild -bs ~/rpmbuild/SPECS/simon.spec
	rpmbuild -bb ~/rpmbuild/SPECS/simon.spec

cleanup:
	rm -f out/simon
