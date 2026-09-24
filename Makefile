SUBDIR = src

all:
	$(MAKE) -C $(SUBDIR)

clean:
	$(MAKE) -C $(SUBDIR) clean

install: all
	sudo cp bin/client /usr/local/bin/client
	sudo mkdir -p /usr/local/share/man/man3
	sudo cp man/man3/mystrlen.1 /usr/local/share/man/man3/mystrlen.3
