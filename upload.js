const USERNAME = "Lyrical-Maven";
const REPO = "file";
const BRANCH = "main";

// 🔥 IMPORTANT: paste your personal access token here
const TOKEN = "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";

async function uploadFile() {
    const fileInput = document.getElementById("fileInput");
    const file = fileInput.files[0];

    if (!file) {
        alert("Please select a file first");
        return;
    }

    document.getElementById("status").innerText = "Uploading...";

    const filePath = `storage/${file.name}`;

    const content = await file.arrayBuffer();
    const base64Content = btoa(String.fromCharCode(...new Uint8Array(content)));

    const url = `https://api.github.com/repos/${USERNAME}/${REPO}/contents/${filePath}`;

    const body = {
        message: `Upload ${file.name}`,
        content: base64Content,
        branch: BRANCH
    };

    const response = await fetch(url, {
        method: "PUT",
        headers: {
            "Content-Type": "application/json",
            Authorization: `Bearer ${TOKEN}`
        },
        body: JSON.stringify(body)
    });

    if (response.ok) {
        document.getElementById("status").innerText = "Upload successful!";
        loadFiles();
    } else {
        document.getElementById("status").innerText = "Upload failed!";
    }
}

async function loadFiles() {
    const url = `https://api.github.com/repos/${USERNAME}/${REPO}/contents/storage`;

    const response = await fetch(url);
    const files = await response.json();

    const list = document.getElementById("fileList");
    list.innerHTML = "";

    files.forEach(file => {
        const li = document.createElement("li");
        li.innerHTML = `<a href="${file.download_url}" target="_blank">${file.name}</a>`;
        list.appendChild(li);
    });
}

window.onload = loadFiles;
