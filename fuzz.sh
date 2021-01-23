CYAN='\033[1;36m'
WHITE='\033[1;37m'
NO_COLOR='\033[0m'
STEP=1
msg () {
  printf "\n${CYAN}[${STEP}]${WHITE} $1 ${NO_COLOR}\n\n"
  let "STEP += 1"
}

### CONFIGURATION
DURATION=20s

### COMMANDS

msg "Remove stale cmake artifacts"
rm CMakeCache.txt Makefile cmake_install.cmake fuzzing_api_executable
rm -r CMakeFiles

msg "cmake"
export CC=afl-clang
export CXX=afl-clang++
# export AFL_USE_ASAN=1
cmake .

msg "make"
make

msg "Start AFL"
timeout ${DURATION} afl-fuzz -i inputs/ -o outputs/ ./fuzzing_api_executable
