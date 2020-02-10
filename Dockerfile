FROM debian:10.2

RUN apt-get update -y && \
    apt-get install -y qtdeclarative5-dev cmake gcc g++ bash
RUN apt-get install -y clang-tidy gcovr

VOLUME /arcade
WORKDIR /arcade

