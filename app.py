from flask import Flask, request, send_file
import os
import subprocess

app = Flask(__name__)

@app.route('/generate', methods=['POST'])
def generate_score():
    try:
        # Saglabā saņemto MusicXML failu
        xml_data = request.data.decode("utf-8")
        with open("input.musicxml", "w") as f:
            f.write(xml_data)

        # Konvertē MusicXML uz PNG
        subprocess.run(["musescore3", "-o", "output.png", "input.musicxml"])

        # Nosūta ģenerēto attēlu
        return send_file("output.png", mimetype='image/png')

    except Exception as e:
        return str(e), 500

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=8080)
