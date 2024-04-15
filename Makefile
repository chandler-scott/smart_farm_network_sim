.PHONY: all report presentation clean

all: report presentation

report:
	@echo "Building report"
	@$(MAKE) -C report > /dev/null

presentation:
	@echo "Building presentation"
	@$(MAKE) -C presentation > /dev/null

clean:
	@$(MAKE) -C report clean > /dev/null
	@$(MAKE) -C presentation clean > /dev/null
