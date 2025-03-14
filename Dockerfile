# Izmanto Ubuntu kā bāzi
FROM ubuntu:22.04

# Iestatām, lai instalācijas laikā nepieprasītu ievadi
ENV DEBIAN_FRONTEND=noninteractive

# Atjauninām pakotnes un instalējam MuseScore un nepieciešamos rīkus
RUN apt-get update && apt-get install -y --no-install-recommends \
    musescore3 \
    python3 \
    python3-pip \
    xvfb \
    tzdata && \
    apt-get clean && rm -rf /var/lib/apt/lists/*

# Iestatām darba mapi
WORKDIR /app

# Kopējam kodu repozitorijā (pārliecinies, ka failus ir ko kopēt!)
COPY . /app

# Instalējam Python atkarības
RUN if [ -f requirements.txt ]; then pip3 install -r requirements.txt; fi

# Norādām, ka jāpievieno 8080 ports
EXPOSE 8080

# Palaiž Flask API serveri
CMD ["python3", "app.py"]

