const form = document.getElementById('complaintForm');
const toast = document.getElementById('toast');
const toggle = document.getElementById('darkToggle');
const body = document.body;

// Dark Mode Toggle
toggle.addEventListener('change', () => {
    body.classList.toggle('dark');
});

// Form Submission
form.addEventListener('submit', function(e){
    e.preventDefault();

    // Show toast
    toast.style.opacity = '1';
    setTimeout(() => { toast.style.opacity = '0'; }, 2500);

    form.reset();
});
