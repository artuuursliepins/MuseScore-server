# Izmanto oficiālo Ubuntu kā bāzi
FROM ubuntu:22.04

# Izveidojam lietotāju (drošībai)
RUN useradd -m appuser

# Instalējam nepieciešamās pakotnes
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
    python3 \
    python3-pip \
    tzdata \
    curl \
    wget && \
    apt-get clean && rm -rf /var/lib/apt/lists/*

# Iestatām darba mapi un kopējam failus
WORKDIR /app
COPY --chown=appuser:appuser . /app

# Pārejam uz non-root lietotāju
USER appuser

# Instalējam atkarības
RUN pip3 install --no-cache-dir -r requirements.txt && pip3 install gunicorn

# Atveram 8080 portu
EXPOSE 8080

# Palaižam Flask API ar `gunicorn`
CMD ["gunicorn", "--workers", "4", "--bind", "0.0.0.0:8080", "app:app"]

