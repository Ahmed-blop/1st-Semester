# 🔹 Reverse a number
**Logic:** Extract each digit and build reversed number
while(n > 0)
{
    rev = (rev * 10) + (n % 10);// Extract last digit and add to rev
    n /= 10;
}

# 🔹 Factorial
**Logic:** Multiply numbers from 1 to n
int fact = 1;
for(int i = 1; i <= n; i++)
    fact *= i;// Multiply i to fact

    int a = 0, b = 1, c;
for(int i = 1; i <= n; i++)// Loop n times
{
    cout << a << " ";
    c = a + b;
    a = b;
    b = c;
}

# 🔹 Fibonacci
**Logic:** Print first n Fibonacci numbers
int a = 0, b = 1, c;
for(int i = 1; i <= n; i++)// Loop n times
{
    cout << a << " ";// Print current Fibonacci number
    c = a + b;
    a = b;
    b = c;
}

# 🔹 Largest of three numbers
**Logic:** Compare three numbers to find the largest
if(a >= b && a >= c)
    largest = a;
else if(b >= a && b >= c)
    largest = b;
else
    largest = c;

# 🔹 Palindrome check
**Logic:** Reverse number and compare with original
int rev = 0, temp = n;
while(temp > 0)
{
    rev = (rev * 10) + (temp % 10); // Extract last digit and add to rev
    temp /= 10;
}
if(rev == n) // Check if reversed number is equal to original
    cout << "Palindrome";
else
    cout << "Not a Palindrome";

# 🔹 Star triangle
**Logic:** Print stars row-wise
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= i; j++)// Print stars in each row
        cout << "* ";
    cout << endl;
}

# 🔹 Number pattern
**Logic:** Print numbers from 1 to i in each row
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= i; j++) // Print numbers from 1 to i
        cout << j << " ";// Print numbers from 1 to i
    cout << endl;// Move to the next line
}

# 🔹 Find maximum
**Logic:** Compare each element to find maximum
int max = arr[0];
for(int i = 1; i < n; i++)
{
    if(arr[i] > max)// Compare current element with max
        max = arr[i];
}

# 🔹 Sum & average
**Logic:** Sum all elements and calculate average
int sum = 0;
for(int i = 0; i < n; i++)// Loop through the array
    sum += arr[i];// Add each element to sum

float avg = (float)sum / n;// Calculate average

# 🔹 Vowel count
**Logic:** Loop through string and check each character
int count = 0;
for(int i = 0; str[i] != '\0'; i++)// Loop through the string
{
    if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')// Check for vowels
        count++;
}

# 🔹 Reverse a string
**Logic:** Loop from end to start and print characters
for(int i = length-1; i >= 0; i--)// Loop from end to start
    cout << str[i];// Print each character

# 🔹 Headings with color
**Logic:** Highlight headings with color for presentation
    void printHeading()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 11); // Cyan
    cout << "\n---- PROGRAM OUTPUT ----\n";
    SetConsoleTextAttribute(h, 15); // White
}




