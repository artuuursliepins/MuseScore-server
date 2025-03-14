# Izmanto Ubuntu kā bāzi
FROM ubuntu:22.04

# Iestatām, lai laika josla netiktu interaktīvi pieprasīta
ENV DEBIAN_FRONTEND=noninteractive

# Izveidojam laika joslas simbolisko saiti uz noklusēto servera laiku
RUN ln -sf /usr/share/zoneinfo/Etc/UTC /etc/localtime && \
    dpkg-reconfigure -f noninteractive tzdata

# Atjauninām pakotnes un instalējam MuseScore un nepieciešamos rīkus
RUN apt-get update && apt-get install -y \
    musescore3 \
    python3 \
    python3-pip \
    xvfb \
    tzdata

# Iestatām darba mapi
WORKDIR /app

# Kopējam kodu repozitorijā
COPY . /app

# Instalējam Python atkarības
RUN pip3 install -r requirements.txt

# Norādām, ka jāpievieno 8080 ports
EXPOSE 8080

# Palaiž Flask API serveri
CMD ["python3", "app.py"]



