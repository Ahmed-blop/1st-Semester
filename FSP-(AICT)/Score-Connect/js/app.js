// Class-wide student marks data (Hardcoded for simulation)
const CLASS_DATA = [
    { id: "25-SE-053", name: "Muhammad Ahmed Hassan", assign: 10, quiz: 10, mid: 30, final: 40, total: 100, avatar: "https://api.dicebear.com/7.x/avataaars/svg?seed=ahmed&backgroundColor=random" },
    { id: "25-SE-091", name: "Muhammad Haseeb", assign: 8, quiz: 7, mid: 22, final: 30, total: 67, avatar: "https://api.dicebear.com/7.x/avataaars/svg?seed=haseeb&backgroundColor=random" },
    { id: "25-SE-026", name: "Muhammad Sarim", assign: 10, quiz: 9, mid: 28, final: 21, total: 70, avatar: "https://api.dicebear.com/7.x/avataaars/svg?seed=sarim&backgroundColor=random" },
    { id: "25-SE-101", name: "Ayesha", assign: 7, quiz: 6, mid: 18, final: 25, total: 56, avatar: "https://api.dicebear.com/7.x/avataaars/svg?seed=ayesha_female&sex=female&backgroundColor=random" },
    { id: "25-SE-104", name: "Bilal Ahmed", assign: 5, quiz: 4, mid: 12, final: 0, total: 21, avatar: "https://api.dicebear.com/7.x/avataaars/svg?seed=bilal&backgroundColor=random" },
    { id: "25-SE-130", name: "Abdul Rafay", assign: 6, quiz: 5, mid: 15, final: 20, total: 46, avatar: "https://api.dicebear.com/7.x/avataaars/svg?seed=rafay&backgroundColor=random" },
    { id: "25-SE-145", name: "Abdullah Jaffar", assign: 8, quiz: 7, mid: 24, final: 32, total: 71, avatar: "https://api.dicebear.com/7.x/avataaars/svg?seed=jaffar&backgroundColor=random" },
    { id: "25-SE-160", name: "Sara Khan", assign: 9, quiz: 8, mid: 26, final: 35, total: 78, avatar: "https://api.dicebear.com/7.x/avataaars/svg?seed=sara_female&sex=female&backgroundColor=random" },
    { id: "25-SE-175", name: "Eman Fatima", assign: 10, quiz: 10, mid: 30, final: 40, total: 90, avatar: "https://api.dicebear.com/7.x/avataaars/svg?seed=eman_female&sex=female&backgroundColor=random" },
    { id: "25-SE-190", name: "Tanzeela Malik", assign: 7, quiz: 6, mid: 20, final: 28, total: 61, avatar: "https://api.dicebear.com/7.x/avataaars/svg?seed=tanzeela_female&sex=female&backgroundColor=random" }
];

// Predefined user credentials for simulated authentication
// ⚠️ SIMULATED AUTHENTICATION - Frontend Only
const USERS = {
    student: {
        id: "25-SE-053",
        pass: "ahmed123",
        name: "Muhammad Ahmed Hassan",
        role: "Student",
        email: "25-se-053@student.hitecuni.edu.pk",
        avatar: "https://api.dicebear.com/7.x/avataaars/svg?seed=ahmed&backgroundColor=random",
        marks: [
            { title: "Assignment 1 (Word)", obtain: 10, total: 10 },
            { title: "Quiz 1 (Topic A)", obtain: 10, total: 10 },
            { title: "Midterm Exam", obtain: 30, total: 30 },
            { title: "Final Project", obtain: 40, total: 40 }
        ]
    },
    teacher: {
        id: "teacher01",
        pass: "teach123",
        name: "Ms. Noor Saba",
        role: "Course Instructor",
        email: "noor.saba@hitec.edu.pk",
        avatar: "https://api.dicebear.com/7.x/avataaars/svg?seed=noorsaba_female&sex=female&backgroundColor=random"
    }
};

/**
 * Initialize shared features across all pages
 * - Theme toggle (Light/Dark mode)
 * - Profile modal
 * - Logout functionality
 */
function initSharedFeatures() {
    // Get saved theme from localStorage or default to light
    const savedTheme = localStorage.getItem("theme") || "light";
    document.body.setAttribute("data-theme", savedTheme);
    
    // Initialize theme toggle button
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

    // Profile modal functionality
    const profileBtn = document.getElementById("profile-btn");
    const modal = document.getElementById("profile-modal");
    const closeModal = document.getElementById("close-modal");

    if (profileBtn && modal) {
        profileBtn.addEventListener("click", () => {
            const role = localStorage.getItem("userRole");
            const user = role === "student" ? USERS.student : USERS.teacher;
            
            // Populate modal with user data
            document.getElementById("modal-name").innerText = user.name;
            document.getElementById("modal-id").innerText = user.id;
            document.getElementById("modal-role").innerText = user.role;
            document.getElementById("modal-email").innerText = user.email;
            
            // Set modal avatar - use direct image if available
            const modalAvatarImg = document.getElementById("modal-avatar-img");
            const modalAvatarContainer = document.querySelector('.modal-avatar');
            if (modalAvatarImg && user.avatar) {
                modalAvatarImg.src = user.avatar;
                modalAvatarImg.alt = user.name;
                modalAvatarImg.style.display = "block";
                modalAvatarImg.onerror = () => {
                    // Fallback: show initials or default icon
                    modalAvatarImg.style.display = "none";
                    if (!modalAvatarContainer.querySelector('.avatar-fallback')) {
                        const fallback = document.createElement('div');
                        fallback.className = 'avatar-fallback';
                        fallback.style.cssText = 'width: 100%; height: 100%; display: flex; align-items: center; justify-content: center; font-size: 2rem; color: white;';
                        fallback.textContent = user.name.charAt(0).toUpperCase();
                        modalAvatarContainer.appendChild(fallback);
                    }
                };
                modalAvatarImg.onload = () => {
                    // Remove fallback if image loads successfully
                    const fallback = modalAvatarContainer.querySelector('.avatar-fallback');
                    if (fallback) fallback.remove();
                };
            }
            
            modal.style.display = "flex";
        });

        // Close modal on button click
        closeModal.onclick = () => modal.style.display = "none";
        
        // Close modal when clicking outside
        window.onclick = (e) => {
            if (e.target === modal) modal.style.display = "none";
        };
    }

    // Logout functionality - clears session and redirects to login
    const logoutBtn = document.getElementById("logout-btn");
    if(logoutBtn) {
        logoutBtn.addEventListener("click", () => {
            localStorage.removeItem("userRole");
            window.location.href = "login.html";
        });
    }
}

/**
 * Handle login form submission
 * ⚠️ SIMULATED AUTHENTICATION - This is frontend-only for demonstration
 * In a real application, this would communicate with a backend server
 */
function handleLogin(event) {
    event.preventDefault();
    const userId = document.getElementById("user-id").value;
    const userPass = document.getElementById("password").value;
    const errorMsg = document.getElementById("error-msg");

    // Check against predefined student credentials
    if (userId === USERS.student.id && userPass === USERS.student.pass) {
        localStorage.setItem("userRole", "student");
        window.location.href = "student.html";
    } 
    // Check against predefined teacher credentials
    else if (userId === USERS.teacher.id && userPass === USERS.teacher.pass) {
        localStorage.setItem("userRole", "teacher");
        window.location.href = "teacher.html";
    } 
    // Invalid credentials
    else {
        errorMsg.style.display = "block";
        errorMsg.innerText = "Invalid ID or Password";
    }
}

/**
 * Initialize Student Dashboard
 * Displays:
 * - Student profile information
 * - Marks table (Assignments, Quizzes, Mids, Finals)
 * - Total marks and percentage
 * - Progress bar
 * - Pass/Fail status
 */
function initStudentDashboard() {
    const studentData = USERS.student;
    
    // Display student information
    document.getElementById("student-name").innerText = studentData.name;
    document.getElementById("student-id").innerText = studentData.id;
    
    // Display student avatar - direct image assignment
    const avatarImg = document.getElementById("student-avatar");
    const avatarContainer = document.querySelector('.profile-avatar');
    if (avatarImg && studentData.avatar) {
        avatarImg.src = studentData.avatar;
        avatarImg.alt = studentData.name;
        avatarImg.style.display = "block";
        avatarImg.onerror = () => {
            // Fallback: show initials
            avatarImg.style.display = "none";
            if (!avatarContainer.querySelector('.avatar-fallback')) {
                const fallback = document.createElement('div');
                fallback.className = 'avatar-fallback';
                fallback.style.cssText = 'width: 100%; height: 100%; display: flex; align-items: center; justify-content: center; font-size: 3rem; color: white; font-weight: bold;';
                fallback.textContent = studentData.name.charAt(0).toUpperCase();
                avatarContainer.appendChild(fallback);
            }
        };
        avatarImg.onload = () => {
            // Remove fallback if image loads successfully
            const fallback = avatarContainer.querySelector('.avatar-fallback');
            if (fallback) fallback.remove();
        };
    }

    // Populate marks table and calculate totals
    const tableBody = document.getElementById("marks-body");
    let totalObtain = 0;
    let totalMax = 0;
    let assignmentObtain = 0;
    let quizObtain = 0;

    studentData.marks.forEach(item => {
        totalObtain += item.obtain;
        totalMax += item.total;
        
        // Track assignment and quiz marks separately
        if (item.title.includes("Assignment")) assignmentObtain += item.obtain;
        if (item.title.includes("Quiz")) quizObtain += item.obtain;
        
        // Calculate percentage for each assessment
        const percentage = ((item.obtain/item.total)*100).toFixed(1);
        
        const row = `
            <tr>
                <td>${item.title}</td>
                <td>${item.obtain}</td>
                <td>${item.total}</td>
                <td>${percentage}%</td>
            </tr>
        `;
        tableBody.innerHTML += row;
    });

    // Calculate overall performance
    const percentage = ((totalObtain / totalMax) * 100).toFixed(1);
    const status = percentage >= 50 ? "PASS ✅" : "FAIL ❌";
    const statusClass = percentage >= 50 ? "status-pass" : "status-fail";
    const gradeValue = calculateGrade(percentage);

    // Display summary stats
    document.getElementById("total-marks").innerText = `${totalObtain} / ${totalMax}`;
    document.getElementById("percentage").innerText = `${percentage}%`;
    document.getElementById("assignment-marks").innerText = `${assignmentObtain}/30`;
    document.getElementById("quiz-marks").innerText = `${quizObtain}/40`;
    document.getElementById("progress-percentage").innerText = `${percentage}%`;
    document.getElementById("grade-status").innerHTML = `<span class="${statusClass}">${gradeValue}</span>`;

    // Animate progress bar
    setTimeout(() => {
        document.getElementById("progress-fill").style.width = `${percentage}%`;
    }, 500);
}

/**
 * Initialize Teacher Dashboard
 * Allows teachers to upload:
 * - Assignments (Word/PDF)
 * - Marks sheets (Excel/CSV)
 * ⚠️ SIMULATED FILE UPLOAD - No actual file processing or storage
 */
function initTeacherDashboard() {
    // Calculate class statistics
    let totalStudents = CLASS_DATA.length;
    let totalScore = 0;
    let passCount = 0;
    let maxScore = 0;
    
    CLASS_DATA.forEach(student => {
        totalScore += student.total;
        if (student.total >= 50) passCount++;
        if (student.total > maxScore) maxScore = student.total;
    });
    
    const avgScore = Math.round(totalScore / totalStudents);
    const passRate = Math.round((passCount / totalStudents) * 100);
    
    // Display class statistics
    document.getElementById("avg-score").innerText = `${avgScore}%`;
    document.getElementById("pass-rate").innerText = `${passRate}%`;
    document.getElementById("highest-score").innerText = `${maxScore}/100`;
    
    // Setup file upload functionality
    const setupUpload = (inputId, btnId) => {
        const input = document.getElementById(inputId);
        const btn = document.getElementById(btnId);
        
        btn.onclick = () => {
            if (input.files.length > 0) {
                const fileName = input.files[0].name;
                // Simulated upload - show success message
                alert(`✅ Success!\nFile "${fileName}" uploaded successfully.`);
                input.value = ""; // Clear file input
            } else {
                alert("⚠️ Please select a file first.");
            }
        };
    };

    // Initialize assignment upload
    setupUpload("assign-file", "upload-assign-btn");
    
    // Initialize marks upload
    setupUpload("marks-file", "upload-marks-btn");
}

/**
 * Initialize Leaderboard
 * Displays class performance ranking sorted by total marks
 * Highlights current student's row
 */
function initLeaderboard() {
    const tableBody = document.getElementById("leaderboard-body");
    
    // Sort students by total marks in descending order
    const sortedData = [...CLASS_DATA].sort((a, b) => b.total - a.total);

    // Generate leaderboard rows
    sortedData.forEach((student, index) => {
        const grade = calculateGrade(student.total);
        const rowClass = student.total < 50 ? "status-fail" : "status-pass";
        
        // Highlight current student's row if viewing as student
        const isMe = localStorage.getItem("userRole") === "student" && 
                     student.id === USERS.student.id;
        const highlightStyle = isMe ? "background: rgba(37, 99, 235, 0.2); font-weight: bold;" : "";

        const row = `
            <tr style="${highlightStyle}">
                <td>#${index + 1}</td>
                <td>
                    <div style="display: flex; align-items: center; gap: 10px;">
                        <div style="width: 40px; height: 40px; border-radius: 50%; overflow: hidden; flex-shrink: 0; background: rgba(59, 130, 246, 0.1); border: 2px solid rgba(59, 130, 246, 0.3); display: flex; align-items: center; justify-content: center;">
                            <img src="${student.avatar}" alt="${student.name}" style="width: 100%; height: 100%; object-fit: cover; display: block;" onerror="this.style.display='none'; this.parentElement.innerHTML='<span style=\\'color: #3b82f6; font-weight: bold; font-size: 1.2rem;\\'>${student.name.charAt(0).toUpperCase()}</span>'">
                        </div>
                        <span>${student.name}</span>
                    </div>
                </td>
                <td>${student.id}</td>
                <td>${student.total} / 100</td>
                <td>${student.total}%</td>
                <td class="${rowClass}">${grade}</td>
            </tr>
        `;
        tableBody.innerHTML += row;
    });
}

/**
 * Calculate grade based on total score
 * Grading scale:
 * A+: 95+
 * A: 85-94
 * A-: 80-84
 * B+: 75-79
 * B: 70-74
 * C: 50-69
 * F: Below 50
 */
function calculateGrade(score) {
    const num = parseFloat(score);
    if (num >= 95) return "A+";
    if (num >= 85) return "A";
    if (num >= 80) return "A-";
    if (num >= 75) return "B+";
    if (num >= 70) return "B";
    if (num >= 50) return "C";
    return "F";
}

/**
 * Main initialization on page load
 * Detects current page and initializes appropriate features
 */
document.addEventListener("DOMContentLoaded", () => {
    // Initialize shared features on all pages
    initSharedFeatures();
    
    const path = window.location.pathname;

    // Login page logic
    if (path.includes("login.html")) {
        const loginForm = document.getElementById("login-form");
        if(loginForm) loginForm.addEventListener("submit", handleLogin);
    } 
    // Dashboard pages - check if user is authenticated
    else {
        if (!localStorage.getItem("userRole")) {
            // Redirect to login if not authenticated
            window.location.href = "login.html";
            return;
        }

        // Initialize appropriate dashboard based on page
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