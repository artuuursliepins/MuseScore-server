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

FROM ubuntu:20.04

RUN apt-get update && apt-get install -y musescore3 xvfb python3 python3-pip

WORKDIR /app

COPY . /app

RUN pip3 install -r requirements.txt

CMD ["python3", "app.py"]
