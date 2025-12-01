from flask import Flask, render_template, request
from github import Github
import os

app = Flask(__name__)
app.config['MAX_CONTENT_LENGTH'] = 50 * 1024 * 1024   # 50 MB

GITHUB_TOKEN = "YOUR_TOKEN_HERE"
GITHUB_REPO = "Lyrical-Maven/file"     # your repo name

g = Github(GITHUB_TOKEN)
repo = g.get_repo(GITHUB_REPO)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/upload', methods=['POST'])
def upload():
    if 'file' not in request.files:
        return "No file selected."

    file = request.files['file']

    if file.filename == "":
        return "File has no name."

    content = file.read()
    filename = file.filename

    try:
        repo.create_file(f"uploads/{filename}", f"Upload {filename}", content)
        return f"Uploaded {filename} to GitHub."
    except:
        return f"File {filename} already exists in repo."

if __name__ == '__main__':
    app.run(debug=True)
