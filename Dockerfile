FROM alpine:latest

RUN apk update &&     \
    apk upgrade &&     \
    apk --update add         \
      gcc         \
      g++         \
      build-base         \
      cmake         \
      bash         \
      libstdc++  \
      ncurses-dev &&     \
    rm -rf /var/cache/apk/*

VOLUME ["/app"]
WORKDIR /app
COPY ./src .