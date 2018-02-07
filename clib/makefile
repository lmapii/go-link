# dummy MAKE

PROJECT_NAME := testlib

# change to you own settings (e.g., windows paths)
CC     = gcc
ECHO   = echo
MKDIR  = mkdir
RM     = rm
silent =@

CFLAGS  = -Wall -O2 -g
LDFLAGS = -shared

PRJ_BLD     := ./bld
GEN_DIRS     = $(PRJ_BLD)
OUTPUT_FILE  = $(PRJ_BLD)/$(PROJECT_NAME)

CC_FILES  :=
INCDIRS   :=
OBJ_FILES :=

INCDIRS += -I ./
INCDIRS += -I ./
CC_FILES  += ./wrap_lib.c

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

SKIP_FOR := clean
ifeq (,$(filter $(SKIP_FOR), $(MAKECMDGOALS)))
$(info .                                                 )
$(foreach dir, $(GEN_DIRS),\
    $(info create/update directory $(dir)) \
    $(eval $(shell $(MKDIR) -p $(dir) )) )
endif

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

.DEFAULT_GOAL := all
.PHONY: prebuild postbuild clean build

# build without project specific post-processing/rules
build: prebuild postbuild

# full build process
all : prebuild postbuild

prebuild :
	$(silent)$(ECHO) '** building project $(PROJECT_NAME)  '

postbuild : $(OUTPUT_FILE).so
	$(silent)$(ECHO) ""
	$(silent)$(ECHO) '*                                   '
	$(silent)$(ECHO) '* make done for $(PROJECT_NAME).    '

clean :
	$(silent)$(ECHO) "### removing directory $(GEN_PATH)"
	$(RM) -rf $(GEN_DIRS)

$(OUTPUT_FILE).so : $(CC_FILES)
	$(CC) $(CFLAGS) $(LDFLAGS) $(INCDIRS) -o $@ $^
