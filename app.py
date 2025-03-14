from flask import Flask, request, send_file, jsonify
import os
import subprocess
import uuid
import tempfile

app = Flask(__name__)

@app.route("/")
def home():
    """Sākumlapa API pārbaudei."""
    return jsonify({"message": "Service is running!"})

@app.route('/generate', methods=['POST'])
def generate_score():
    """Ģenerē notis no MusicXML un atgriež PNG attēlu."""
    try:
        # Validējam, vai ir dati pieprasījumā
        if not request.data:
            return jsonify({"error": "No MusicXML data received"}), 400

        # Izveidojam unikālu faila nosaukumu (novēršam konfliktus)
        unique_id = str(uuid.uuid4())
        input_file = f"input_{unique_id}.musicxml"
        output_file = f"output_{unique_id}.png"

        # Izveidojam pagaidu direktoriju drošībai
        with tempfile.TemporaryDirectory() as temp_dir:
            input_path = os.path.join(temp_dir, input_file)
            output_path = os.path.join(temp_dir, output_file)

            # Saglabājam MusicXML failu
            with open(input_path, "w", encoding="utf-8") as f:
                f.write(request.data.decode("utf-8"))

            # Izpildām MuseScore konvertāciju
            result = subprocess.run(
                ["musescore", "-o", output_path, input_path],
                capture_output=True, text=True
            )

            # Pārbaudām, vai MuseScore bija veiksmīgs
            if result.returncode != 0:
                return jsonify({"error": "MuseScore failed", "details": result.stderr}), 500

            # Nosūtām ģenerēto attēlu
            return send_file(output_path, mimetype="image/png")

    except Exception as e:
        return jsonify({"error": "Server error", "details": str(e)}), 500

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=8080)
