FROM alpine:latest
RUN apk update && apk upgrade
RUN apk add g++ make cmake ccache valgrind cppcheck clang clang-extra-tools\
 catch2 opencv doxygen
ARG CXX_SNIPPETS_VERSION
ENV CXX_SNIPPETS_VERSION=$CXX_SNIPPETS_VERSION
WORKDIR /home