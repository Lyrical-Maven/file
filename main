import base64
import requests
from flask import Flask, render_template, request

app = Flask(__name__)

GITHUB_USERNAME = "Lyrical-Maven"
REPO_NAME = "file"
TOKEN = "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"

def upload_to_github(filename, content):
    url = f"https://api.github.com/repos/{GITHUB_USERNAME}/{REPO_NAME}/contents/uploads/{filename}"

    encoded = base64.b64encode(content).decode('utf-8')

    data = {
        "message": f"Upload {filename}",
        "content": encoded
    }

    response = requests.put(url, json=data, auth=(GITHUB_USERNAME, TOKEN))
    return response

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/upload", methods=["POST"])
def upload():
    file = request.files["file"]
    response = upload_to_github(file.filename, file.read())

    if response.status_code in [200, 201]:
        return "File uploaded successfully!"
    else:
        return f"Error: {response.text}"

if __name__ == "__main__":
    app.run(debug=True)
