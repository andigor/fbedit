# vi: ft=make MAKEFLAGS += --no-builtin-rules .SUFFIXES:

.PHONY: all clean
all:

makefiles_ := $(wildcard *.makef)

$(warning makefiles found: $(makefiles_))

files_to_clean_ := 
$(foreach mf_,$(makefiles_),\
	$(eval include $(mf_))\
	$(warning EXES: $($(CUR_CUR_DIR).EXES))\
	$(foreach exe_,$($(CUR_CUR_DIR).EXES),\
	  $(warning SRC: $($(exe_).SRC))\
		$(eval obj_ := )\
		$(foreach src_,$($(exe_).SRC),\
	    $(warning src_: $(src_))\
		  $(eval base_name_ := $(basename $(src_)))\
		  $(warning base name: $(base_name_))\
			$(eval target_obj_ := $(exe_)_$(base_name_).o)\
	    $(eval $(target_obj_): $(src_) ; g++ -c -o $$@ $$<)\
			$(eval all: $(target_obj_))\
			$(eval obj_ += $(target_obj_))\
		)\
	  $(eval $(exe_): $(obj_) ; g++ -o $$@ $$^)\
		$(eval all: $(exe_))\
		$(eval files_to_clean_ += $(obj_) $(exe_))\
	)\
)

clean:
	rm $(files_to_clean_)
