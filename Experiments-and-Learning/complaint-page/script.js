document.addEventListener("DOMContentLoaded", () => {
  // --- Theme Toggle Logic ---
  const toggleBtn = document.getElementById("themeToggle");
  const body = document.body;

  if (toggleBtn) {
    if (localStorage.getItem("theme") === "light") {
      body.classList.add("light-mode");
      toggleBtn.textContent = "☀️";
    }

    toggleBtn.addEventListener("click", () => {
      body.classList.toggle("light-mode");

      if (body.classList.contains("light-mode")) {
        localStorage.setItem("theme", "light");
        toggleBtn.textContent = "☀️";
      } else {
        localStorage.setItem("theme", "dark");
        toggleBtn.textContent = "🌙";
      }
    });
  }

  // --- Interactive Parallax Effect ---
  // This makes the blobs move slightly when you move the mouse
  document.addEventListener("mousemove", (e) => {
    const blobs = document.querySelectorAll(".blob");
    const x = e.clientX / window.innerWidth;
    const y = e.clientY / window.innerHeight;

    blobs.forEach((blob, index) => {
      const speed = (index + 1) * 20; // Different speeds for depth
      const xOffset = (window.innerWidth / 2 - e.clientX) / speed;
      const yOffset = (window.innerHeight / 2 - e.clientY) / speed;

      blob.style.transform = `translate(${xOffset}px, ${yOffset}px)`;
    });
  });
});