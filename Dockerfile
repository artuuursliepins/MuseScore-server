# Izmanto Ubuntu kā pamata sistēmu
FROM ubuntu:22.04

# Iestata laika joslu, lai izvairītos no interaktīvas izvēles
ENV TZ=Europe/Riga
RUN ln -fs /usr/share/zoneinfo/$TZ /etc/localtime && \
    apt-get update && \
    apt-get install -y tzdata && \
    echo $TZ > /etc/timezone

# Izmantojam Ubuntu kā bāzi
FROM ubuntu:20.04

# Atjauninām pakotnes un instalējam MuseScore
RUN apt-get update && apt-get install -y musescore3 xvfb

# Iestatām darba mapi
WORKDIR /app

# Kopējam kodu repozitorijā
COPY . /app

# Norādām noklusējuma komandu, lai serveris vienmēr paliktu dzīvs
CMD ["tail", "-f", "/dev/null"]


