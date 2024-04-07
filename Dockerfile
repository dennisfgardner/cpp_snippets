FROM alpine:latest
RUN apk update && apk upgrade
RUN apk add g++ make git cmake ccache valgrind cppcheck clang clang-extra-tools catch2
WORKDIR /home