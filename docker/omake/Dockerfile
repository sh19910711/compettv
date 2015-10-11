# gcc + omake
FROM debian:jessie

RUN apt-get update -y && apt-get install -y \
  omake \
  gcc \
  g++ \
  libgamin-dev

RUN useradd user
USER user
CMD omake
