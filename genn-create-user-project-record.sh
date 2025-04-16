#!/bin/bash

# display genn-create-user-project.sh help
genn_help () {
    echo "genn-create-user-project script usage:"
    echo "genn-create-user-project.sh [ih] project sources..."
    echo "-h                shows this help message"
    echo "-i includepath    add additional include directory"
    echo "-u                add userproject/include directory"
}

# Parse flags
while getopts ":i:hu" option; do
    case $option in
        i) INCLUDES="$INCLUDES -I$OPTARG";;
        u) INCLUDES="$INCLUDES -I\$(GENN_USERPROJECT_INCLUDE)"; INCLUDE_USERPROJECT=1;;
        h) genn_help; exit;;
        ?) genn_help; exit;;
        :) genn_help; exit;;
    esac
done

# Shift off arguments already processed
shift $((OPTIND - 1))

# Treat first remaining argument as project name
PROJECT_NAME="$1"

# Shift THAT away and treat all remaining arguments as source files
shift
SOURCE_FILES="$@"

# Generate object file names
OBJECT_FILES=$(echo "$SOURCE_FILES" | sed 's/\.cc/.o/g')

# Write out Makefile
echo "GENERATED_CODE_DIR        := ${PROJECT_NAME}_CODE" > Makefile
if [[ -n "$INCLUDE_USERPROJECT" ]]; then
    echo "GENN_USERPROJECT_INCLUDE  := \$(abspath \$(dir \$(shell which genn-buildmodel.sh))../userproject/include)" >> Makefile
fi
echo "CXXFLAGS                  += -std=c++11 -Wall -Wpedantic -Wextra" >> Makefile
echo -en "\n" >> Makefile

echo ".PHONY: all clean generated_code" >> Makefile
echo -en "\n" >> Makefile

# Specify object files
echo "OBJS                      := $OBJECT_FILES" >> Makefile
echo -en "\n" >> Makefile

# Define "all" target
echo "all: $PROJECT_NAME" >> Makefile
echo -en "\n" >> Makefile

# Define the linking step
echo "$PROJECT_NAME: \$(OBJS) generated_code" >> Makefile
echo "	\$(CXX) \$(CXXFLAGS) \$(OBJS) -o $PROJECT_NAME -L\$(GENERATED_CODE_DIR) -lrunner -Wl,-rpath \$(GENERATED_CODE_DIR)" >> Makefile
echo -en "\n" >> Makefile

# Define the compilation rule
echo "%.o: %.cc" >> Makefile
echo "	\$(CXX) \$(CXXFLAGS) -c \$< -o \$@" >> Makefile
echo -en "\n" >> Makefile

# Define generated_code rule
echo "generated_code:" >> Makefile
echo "	\$(MAKE) -C \$(GENERATED_CODE_DIR)" >> Makefile
echo -en "\n" >> Makefile

# Define clean rule
echo "clean:" >> Makefile
echo "	\$(MAKE) -C \$(GENERATED_CODE_DIR) clean" >> Makefile
echo "	rm -f \$(OBJS) $PROJECT_NAME" >> Makefile
