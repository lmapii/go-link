# dummy MAKE

# notice that a lib-prefix is REQUIRED otherwise it won't work with -l<name-without-lib-prefix>
PROJECT_NAME := libcustom

# change to you own settings (e.g., windows paths)
CC     = gcc
AR     = ar
ECHO   = echo
MKDIR  = mkdir
RM     = rm
CP     = cp
silent =@

CFLAGS  = -Wall -g -static -Os -fno-asynchronous-unwind-tables
LFLAGS  =

PRJ_BLD     := ./bld
GEN_DIRS     = $(PRJ_BLD)
GEN_DIRS     = $(PRJ_BLD)
GEN_DIRS_SUB = $(OBJ_PATH) $(OUT_PATH)

OUTPUT_FILE  = $(PRJ_BLD)/$(PROJECT_NAME)

CC_FILES  :=
INCDIRS   :=
OBJ_FILES :=

INCDIRS += -I ./
INCDIRS += -I ./
CC_FILES  += ./wrap_lib.c

OBJ_FILES = $(CC_FILES:.c=.o)

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

SKIP_FOR := clean
ifeq (,$(filter $(SKIP_FOR), $(MAKECMDGOALS)))
$(info .                                                 )

$(foreach dir, $(GEN_DIRS),\
    $(info create/update directory $(dir)) \
    $(eval $(shell $(MKDIR) -p $(dir) )) )

$(foreach dir, $(GEN_DIRS_SUB),\
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

postbuild : $(OUTPUT_FILE).a
	$(silent)$(ECHO) ""
	$(silent)$(ECHO) '*                                   '
	$(silent)$(ECHO) '* make done for $(PROJECT_NAME).    '

clean :
	$(silent)$(ECHO) "### removing directory $(GEN_PATH)"
	$(RM) -rf $(GEN_DIRS)

$(OUTPUT_FILE).a : $(OUTPUT_FILE).o
	$(AR) rcs $(OUTPUT_FILE).a $(OUTPUT_FILE).o
	# $(CP) $(OUTPUT_FILE).o $(OUTPUT_FILE).lib

$(OUTPUT_FILE).o : $(CC_FILES)
	$(CC) -g -c $(INCDIRS) $(CFLAGS) $(LFLAGS) $(CC_FILES) -o $(OUTPUT_FILE).o
