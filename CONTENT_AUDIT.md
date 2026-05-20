# CONTENT_AUDIT

> Source directory reviewed: `E:\大作业`  
> Build directory used: `C:\Users\86150\academic-homepage-li-wanying`

## 1. Found Materials

| File | Type | Useful Website Content | Notes |
| --- | --- | --- | --- |
| `简历.pdf` | CV | Education, GPA, rank, CET-6, coursework, research training, national innovation project, skills, awards | Primary source for profile data. CV copied to `public/files/Li-Wanying-CV.pdf`. |
| `23339050_proj1.cpp` | C++ source | DPLL SAT solver implementation for 3-CNF satisfiability | This is Data Structures & Algorithms Course Project 1. Not missing. |
| `23339050_proj1.pdf` | Course report | Project 1 motivation, DPLL algorithm explanation, unit clause simplification, branching heuristic, implementation difficulty | Copied to `raw/` and `public/files/DSA-Project-1-DPLL.pdf`. |
| `大作业2.cpp` | C++ source | Custom `VecList`, `LinkStack`, `LinkQueue`, adjacency-matrix graph, Dijkstra, Yen-style K shortest paths | Course project only; suitable for a structured README and project page. |
| `proj2_23339050_20241224145819.pdf` | Course report | K shortest paths report, command interface, blacklisted transfer nodes, max transfer limit, priority queue candidates | Copied to `raw/` and `public/files/DSA-Project-2-KSP.pdf`. |
| `立项书草稿.docx` | Project proposal | Motivation, six-step technical route: CTT, item analysis, reliability/validity, AHP, IRT, output | Some platform claims are broad; use conservatively. |
| `中期.docx` | Midterm material | 6 dimensions, 20 retained indicators, CTT screening, CVI/EFA/AHP progress, project difficulties | Useful for the national innovation project page. |
| `附件.docx` | Appendix | Detailed CTT/AHP/IRT steps, sample scoring tables, ICC/logistic model description | Useful as supporting detail, but avoid overloading homepage. |
| `答辩2(1).pptx` | Defense slides | Project overview, background, technical route, CTT/IRT/AHP explanation | Text extracted from slides; supports project structure. |

## 2. Extracted Profile Facts

- Name: 李宛莹 / Wanying Li.
- School: 中山大学（珠海）数学学院.
- Major: 信息与计算科学.
- Grade: 2023级本科生; expected B.S. 2027.06.
- GPA: 3.92 / 5.0; rank 15 / 88.
- CET-6: 556.
- Core courses: 数学分析 92, 高等代数 91, 概率论 91, 数理统计 97, 数值分析 95, 偏微分方程 99, C++ 程序设计 92, 数据结构与算法.
- Skills: Python, C++, MATLAB, PyTorch, Git, Linux, LaTeX; deep learning training workflow, loss construction, mask mechanism, pruning, parameter importance analysis; probability/statistics, latent variable modeling, EM parameter estimation, numerical computation, optimization.
- Awards: 中山大学优秀学生一等奖学金（2023）, 中山大学优秀学生二等奖学金（2024）, 第十七届全国大学生数学竞赛广东省三等奖, 全国大学生数学建模广东省三等奖（2024, 2025）, 第六届“华数杯”国赛本科组三等奖, 第十七届“电工杯”数学建模三等奖.

## 3. Project Assessment

### A. Continual Learning & Parameter Importance

- Source: CV.
- Usable content: ongoing research training with 常晓斌副教授; catastrophic forgetting, Lottery Ticket Hypothesis, Continual Winning Tickets, mask mechanism, loss terms, pruning sparsity, baseline reproduction, parameter importance and stability-plasticity analysis.
- Boundary: Must be described as ongoing research training / participation. No publication claim. Do not write that the student proposed CWT.

### B. CTT/IRT-based Textbook Evaluation

- Source: CV, `立项书草稿.docx`, `中期.docx`, `附件.docx`, `答辩2(1).pptx`.
- Usable content: national innovation project; CTT, IRT, AHP, reliability/validity, Cronbach's alpha, EFA/CFA, ICC/TIF/logistic model, latent ability estimation, EM-style parameter estimation framework from CV.
- Boundary: It is a National Innovation Project and excellent completion, not a formal paper. Keep claims at “framework design / statistical modeling / educational measurement”.

### C. Graph Algorithms and K-Shortest Paths in C++

- Source: `大作业2.cpp`, `proj2_23339050_20241224145819.pdf`.
- Usable content: custom linear list, stack, queue, adjacency matrix graph, Dijkstra from one point to another, blacklist transfer node constraints, max transfer count, Yen-style KSP candidate generation with priority queue, edge removal and restoration.
- Boundary: Course project. Do not describe as production-grade routing system or research contribution.

### D. Data Structures & Algorithms Course Project 1

- Source: `23339050_proj1.cpp`, `23339050_proj1.pdf`.
- Status: Found. It is a 3-CNF SAT / Boolean satisfiability course project using DPLL.
- Usable content: unit clause propagation, clause simplification, most frequent unassigned variable branching, recursive backtracking, assignment output.
- Boundary: Course project. The project can be shown, but not packaged as a research SAT solver.

## 4. Missing / To Be Supplemented

- GitHub URL is not provided. The site uses a TODO placeholder.
- Formal English name spelling is inferred from “Wanying Li”; confirm if a preferred English name exists.
- Exact personal photo/headshot is not provided; the site intentionally avoids using an invented image.
- Continual learning project artifacts are not present as standalone notes/code in this folder. The site only uses the CV-level description.
- No published paper information is present. The site does not include a publications section.

## 5. Recommended Display List

1. Parameter Importance and Model Stability in Continual Learning — Research Training / Ongoing.
2. CTT/IRT-based Quantitative Evaluation Framework for Advanced Mathematics Textbooks — National Innovation Project.
3. Graph Algorithms and K-Shortest Paths in C++ — Course Project.
4. DPLL-based Boolean Satisfiability Solver — Course Project.

## 6. Content Risk Controls

- “持续学习课题” is written as “参与 / ongoing research training”, not as a published paper.
- “大创” is written as “国家级大创优秀结项”, not as a journal/conference publication.
- “数据结构与算法大作业” is written as “Course Project”.
- Benchmarks, performance improvements, and external validation results are not invented.
- Unconfirmed fields are marked as TODO.
