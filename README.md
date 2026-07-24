# 🪢 Hangman in C

> A terminal-based Hangman game built in C — my second project as a self-taught dev.

---

## 📌 About

After finishing my calculator, I wanted a bigger challenge.
Hangman pushed me into new territory: reading files, working with strings, managing game state, and handling user input in a real game loop.

Still terminal. Still C. A lot more going on under the hood.

---

## ⚙️ Features

- 🎯 Two word categories — Fruits and Objects of Kitchen
- 🔀 Random word selection from `.txt` files
- 🔡 Letter-by-letter guessing with live word state display
- ❤️ 5 lives per game
- ❌ Invalid input handling (numbers, symbols, etc.)
- 🔁 Duplicate letter detection — no unfair punishment for repeating
- 🏆 Win and lose messages with automatic return to menu

---

## 📂 Word files

| File | Category | Words |
|------|----------|-------|
| `Fruits.txt` | Fruits | 5 words |
| `Objects.txt` | Objects of Kitchen | 5 words |

> You can add more words by editing the `.txt` files — one word per line.

---

## 🚀 How to run

**Compile:**
```bash
gcc Hangman.c -o hangman.exe
```

**Run:**
```bash
hangman.exe
```

> Requires GCC installed. On Windows, you can use MinGW or WSL.
> Make sure `Fruits.txt` and `Objects.txt` are in the same folder as the executable.

---

## 💡 What I learned building this

- How to **read files** in C with `fopen`, `fgets`, and `fclose`
- How to **randomly select** data using `rand()` and `srand(time(NULL))`
- How to work with **char arrays** and manipulate strings with `<string.h>`
- How to use `strchr` to **search** inside strings
- How to manage **game state** across multiple variables (`state`, `tried`, `lives`)
- How `for` loops work with index-based logic
- How to use `isalpha()` from `<ctype.h>` to validate character input

---

## 🛠️ Built with

![C](https://img.shields.io/badge/C-000000?style=for-the-badge&logo=c&logoColor=white)

---

## 👤 Author

**Miguel Mariano**
[![LinkedIn](https://img.shields.io/badge/LinkedIn-000000?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/miguel-mariano-6a87aa2a0/)
[![Instagram](https://img.shields.io/badge/Instagram-000000?style=for-the-badge&logo=instagram&logoColor=white)](https://www.instagram.com/miiguel.mariano/)

---

<p align="center"><i>Second project. Getting somewhere.</i></p>
