// Replace below with your Render URL after deployment
const API = "https://file-backend-6lst.onrender.com/"; // e.g. https://your-service.onrender.com

async function uploadFile() {
    const fileInput = document.getElementById("fileInput");
    const file = fileInput.files[0];

    if (!file) {
        alert("Please select a file");
        return;
    }

    const formData = new FormData();
    formData.append("file", file);

    document.getElementById("status").innerText = "Uploading...";

    try {
        const response = await fetch(`${API}/upload`, {
            method: "POST",
            body: formData
        });

        const text = await response.text();
        document.getElementById("status").innerText = text;
    } catch (err) {
        document.getElementById("status").innerText = "Upload failed: " + err.message;
    }
}
