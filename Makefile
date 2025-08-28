# Makefile for cleaning up Windows build artifacts

# Use Windows delete command
DEL = del /S /Q /F
# Use Windows shell command to suppress errors
IGNORE_ERRORS = 2>nul

.PHONY: clean

clean:
	@echo Cleaning up all .exe and .pdb files...
	-@$(DEL) *.exe $(IGNORE_ERRORS)
	-@$(DEL) *.pdb $(IGNORE_ERRORS)
	@echo Done.
