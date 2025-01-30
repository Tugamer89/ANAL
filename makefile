ZIP_DIRS = autovalori errori sistemi svd
EXCLUDE = bin

.PHONY: all clean

all: $(ZIP_DIRS:=.zip)

%.zip:
	@echo "Creating archive for $@"
	@zip -r $@ $* -x "$*/$(EXCLUDE)/*"

clean:
	rm -f $(ZIP_DIRS:=.zip)
