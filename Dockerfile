FROM ubuntu:latest
RUN apt update && apt -y upgrade
ARG DEBIAN_FRONTEND=noninteractive
RUN apt install -y g++ make cmake valgrind cppcheck clang clang-tidy\
 catch2 doxygen libopencv-dev
ARG CXX_SNIPPETS_VERSION
ENV CXX_SNIPPETS_VERSION=$CXX_SNIPPETS_VERSION
WORKDIR /home