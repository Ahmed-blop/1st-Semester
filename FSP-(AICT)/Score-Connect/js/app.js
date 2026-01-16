const CLASS_DATA = [
    { id: "25-SE-053", name: "Muhammad Ahmed Hassan", assign: 9, quiz: 9, mid: 28, final: 40, total: 85 },
    { id: "25-SE-091", name: "Muhammad Haseeb", assign: 8, quiz: 7, mid: 22, final: 30, total: 67 },
    { id: "25-SE-026", name: "Muhammad Sarim", assign: 10, quiz: 9, mid: 28, final: 21, total: 70 },
    { id: "25-SE-101", name: "Ayesha", assign: 7, quiz: 6, mid: 18, final: 25, total: 56 },
    { id: "25-SE-104", name: "Bilal Ahmed", assign: 5, quiz: 4, mid: 12, final: 0, total: 21 } 
];

const USERS = {
    student: {
        id: "25-SE-053",
        pass: "ahmed123",
        name: "Muhammad Ahmed Hassan",
        role: "Student",
        email: "25-se-053@student.hitecuni.edu.pk",
        marks: [
            { title: "Assignment 1 (Word)", obtain: 9, total: 10 },
            { title: "Quiz 1 (Topic A)", obtain: 9, total: 10 },
            { title: "Midterm Exam", obtain: 28, total: 30 },
            { title: "Final Project", obtain: 40, total: 40 }
        ]
    },
    teacher: {
        id: "teacher01",
        pass: "teach123",
        name: "Ms. Noor Saba",
        role: "Course Instructor",
        email: "noor.saba@hitec.edu.pk"
    }
};

function initSharedFeatures() {
    const savedTheme = localStorage.getItem("theme") || "light";
    document.body.setAttribute("data-theme", savedTheme);
    
    const themeBtn = document.getElementById("theme-btn");
    if(themeBtn) {
        themeBtn.innerText = savedTheme === "dark" ? "☀️" : "🌙";
        themeBtn.onclick = () => {
            const current = document.body.getAttribute("data-theme");
            const newTheme = current === "dark" ? "light" : "dark";
            document.body.setAttribute("data-theme", newTheme);
            localStorage.setItem("theme", newTheme);
            themeBtn.innerText = newTheme === "dark" ? "☀️" : "🌙";
        };
    }

    const profileBtn = document.getElementById("profile-btn");
    const modal = document.getElementById("profile-modal");
    const closeModal = document.getElementById("close-modal");

    if (profileBtn && modal) {
        profileBtn.addEventListener("click", () => {
            const role = localStorage.getItem("userRole");
            const user = role === "student" ? USERS.student : USERS.teacher;
            
            document.getElementById("modal-name").innerText = user.name;
            document.getElementById("modal-id").innerText = user.id;
            document.getElementById("modal-role").innerText = user.role;
            document.getElementById("modal-email").innerText = user.email;
            
            modal.style.display = "flex";
        });

        closeModal.onclick = () => modal.style.display = "none";
        
        window.onclick = (e) => {
            if (e.target === modal) modal.style.display = "none";
        };
    }

    const logoutBtn = document.getElementById("logout-btn");
    if(logoutBtn) {
        logoutBtn.addEventListener("click", () => {
            localStorage.removeItem("userRole");
            window.location.href = "login.html";
        });
    }
}

function handleLogin(event) {
    event.preventDefault();
    const userId = document.getElementById("user-id").value;
    const userPass = document.getElementById("password").value;
    const errorMsg = document.getElementById("error-msg");

    if (userId === USERS.student.id && userPass === USERS.student.pass) {
        localStorage.setItem("userRole", "student");
        window.location.href = "student.html";
    } else if (userId === USERS.teacher.id && userPass === USERS.teacher.pass) {
        localStorage.setItem("userRole", "teacher");
        window.location.href = "teacher.html";
    } else {
        errorMsg.style.display = "block";
        errorMsg.innerText = "Invalid ID or Password";
    }
}

function initStudentDashboard() {
    const studentData = USERS.student;
    
    document.getElementById("student-name").innerText = studentData.name;
    document.getElementById("student-id").innerText = studentData.id;

    const tableBody = document.getElementById("marks-body");
    let totalObtain = 0;
    let totalMax = 0;

    studentData.marks.forEach(item => {
        totalObtain += item.obtain;
        totalMax += item.total;
        
        const row = `
            <tr>
                <td>${item.title}</td>
                <td>${item.obtain}</td>
                <td>${item.total}</td>
                <td>${((item.obtain/item.total)*100).toFixed(1)}%</td>
            </tr>
        `;
        tableBody.innerHTML += row;
    });

    const percentage = ((totalObtain / totalMax) * 100).toFixed(1);
    const status = percentage >= 50 ? "PASS" : "FAIL";
    const statusClass = percentage >= 50 ? "status-pass" : "status-fail";

    document.getElementById("total-marks").innerText = `${totalObtain} / ${totalMax}`;
    document.getElementById("percentage").innerText = `${percentage}%`;
    document.getElementById("grade-status").innerHTML = `<span class="${statusClass}">${status}</span>`;

    setTimeout(() => {
        document.getElementById("progress-fill").style.width = `${percentage}%`;
    }, 500);
}

function initTeacherDashboard() {
    const setupUpload = (inputId, btnId) => {
        const input = document.getElementById(inputId);
        const btn = document.getElementById(btnId);
        
        btn.onclick = () => {
            if (input.files.length > 0) {
                const fileName = input.files[0].name;
                alert(`✅ Success!\nFile "${fileName}" uploaded successfully.`);
                input.value = ""; 
            } else {
                alert("⚠️ Please select a file first.");
            }
        };
    };

    setupUpload("assign-file", "upload-assign-btn");
    setupUpload("marks-file", "upload-marks-btn");
}

function initLeaderboard() {
    const tableBody = document.getElementById("leaderboard-body");
    
    const sortedData = [...CLASS_DATA].sort((a, b) => b.total - a.total);

    sortedData.forEach((student, index) => {
        const grade = calculateGrade(student.total);
        const rowClass = student.total < 50 ? "status-fail" : "status-pass";
        
        const isMe = localStorage.getItem("userRole") === "student" && 
                     student.id === USERS.student.id;
        const highlightStyle = isMe ? "background: rgba(37, 99, 235, 0.2); font-weight: bold;" : "";

        const row = `
            <tr style="${highlightStyle}">
                <td>#${index + 1}</td>
                <td>${student.name}</td>
                <td>${student.id}</td>
                <td>${student.total} / 100</td>
                <td>${student.total}%</td>
                <td class="${rowClass}">${grade}</td>
            </tr>
        `;
        tableBody.innerHTML += row;
    });
}

function calculateGrade(score) {
    if (score >= 85) return "A";
    if (score >= 70) return "B";
    if (score >= 50) return "C";
    return "F";
}

document.addEventListener("DOMContentLoaded", () => {
    initSharedFeatures();
    
    const path = window.location.pathname;

    if (path.includes("login.html")) {
        const loginForm = document.getElementById("login-form");
        if(loginForm) loginForm.addEventListener("submit", handleLogin);
    } 
    else {
        if (!localStorage.getItem("userRole")) {
            window.location.href = "login.html";
            return;
        }

        if (path.includes("student.html")) {
            initStudentDashboard();
        } 
        else if (path.includes("teacher.html")) {
            initTeacherDashboard();
        } 
        else if (path.includes("leaderboard.html")) {
            initLeaderboard();
        }
    }
});