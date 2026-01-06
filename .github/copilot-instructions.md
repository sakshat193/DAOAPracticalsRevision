# Copilot instructions (DAOA practical docs)

## Repo purpose (big picture)
- This workspace is a **documentation repo** for DAOA practical exam prep.
- The canonical, structured guide is [Prompt List.md](../Prompt List.md): it defines the **unique (non-redundant) experiment set**, the **C-compatible filename** for each experiment, and a consistent per-experiment template.
- [DAOA Experiment List for Practical Exam.md](../DAOA Experiment List for Practical Exam.md) is a raw/converted list aligned to a referenced PDF (via footnote) and may include conversion artifacts.

## Editing conventions (match existing structure)
- Preserve the section taxonomy used in [Prompt List.md](../Prompt List.md):
  - Category heading (e.g., `## I. Sorting Algorithms`)
  - Per-experiment heading with number (e.g., `### 1. Merge Sort`)
  - Fields in this order: **File Name**, **Description & Prompt**, **Examiner’s Expectations**, **How to Perform**
- Keep numbering stable; avoid renumbering unless explicitly requested (the numbering maps to “PDF Q…” references in the “Code Reusability Guide” section).
- Keep filenames **C-compatible** and formatted exactly like the guide (e.g., `merge_sort.c`, `tsp_dp.c`).
- Use GitHub-flavored Markdown:
  - Inline math is already used (e.g., `$m \times n$`); don’t replace math with plain text.
  - Code identifiers and filenames stay in backticks.

## Content rules specific to this repo
- Don’t invent additional experiments or categories beyond what the docs already enumerate.
- When updating/adding an experiment entry, also update the “Code Reusability Guide” mapping in [Prompt List.md](../Prompt List.md) so reuse claims stay consistent.
- If asked to create implementations, create C files using the **exact** filenames listed in [Prompt List.md](../Prompt List.md) and keep the implementation aligned to the listed “Examiner’s Expectations” and “How to Perform” bullets.

## C implementation style (when generating code)
- Prefer **short, simple variable names** (exam-friendly): `i`, `j`, `k`, `n`, `m`, `u`, `v`, `w`, `src`, `dst`, `dp`, `adj`.
- Keep code **naively optimized**: choose the standard optimal approach for the algorithm (e.g., DP/greedy/backtracking as specified) without over-engineering (no heavy abstractions, no fancy libraries).
- Use **CLI user input** wherever reasonable:
  - Prompt clearly (what to enter, expected format), accept sizes + values, and print outputs in a readable way.
  - Prefer simple, predictable I/O (scanf/printf) over hard-coded examples.

## Graph-code conventions (vertex labels + manual matrix fallback)
- For graph-related questions, display vertices as **chars** by default: `A, B, C, ...` (i.e., vertex 0 = `A`, 1 = `B`, etc.).
- Prompts may accept either a **char** (e.g., `A`) or a **0-based index** (e.g., `0`).
- For adjacency-matrix based graph codes, include a **toggleable manual matrix fallback** inside the C file so users can edit an `n x n` matrix directly in code:
  - Example pattern: `#define USE_MANUAL_MATRIX 0` and a `#if USE_MANUAL_MATRIX` block with a sample `manual[n][n]` matrix.
  - When enabled, the program should skip reading the matrix from stdin and use the hard-coded matrix.

## “Relevant questions” header in every generated C file
- For any created C file (per [Prompt List.md](../Prompt List.md) file names), add a short top-of-file comment block listing **all relevant question variants** from:
  - The mapping in “VII. Code Reusability Guide” in [Prompt List.md](../Prompt List.md) (PDF Q… mapping).
  - The scenario list in [DAOA Experiment List for Practical Exam.md](../DAOA Experiment List for Practical Exam.md) (item numbers) that correspond to those mapped questions.
  - **Include the full text of each relevant DAOA Experiment List question (not just the number), exactly as written.**
- Example (format only):
  // Relevant questions: PDF Q14/Q22/Q42/Q43 (Job Sequencing variants)
  // Also matches DAOA list items: 14, 22, 42, 43
  // Full text:
  // 14. Implementation of Job Sequencing with deadline using greedy approach.
  // 22. Implement a greedy algorithm to schedule delivery jobs for a courier company to maximize total profit before deadlines.
  // 42. A software company receives several client tasks, each with a fixed deadline and payment amount. The company can complete only one task per time slot. Design and implement a program using the Greedy approach to determine the most profitable job sequence.
  // 43. A data processing center must execute a set of tasks where each task has a deadline and an associated profit. Only one task can be done at a time. Implement the Job Sequencing with Deadlines algorithm using a Greedy strategy to get the maximum profit.

## Complexity & classification comment in every generated C file
- At the end of every generated C file, add a short comment block that includes:
  - Time complexity (best/average/worst where applicable)
  - Space complexity
  - Problem type / classification (e.g., P / NP-hard / NP-complete (decision))
  - Notes about the *implementation as written* if it differs from the optimal textbook bound (e.g., bubble sort used)

## What not to assume
- There is currently **no build system, tests, or source tree** in this repo; don’t reference `make`, CI, or directories that don’t exist unless the user asks to add them.
