export type ProjectType = "Research Training" | "National Innovation Project" | "Course Project";

export type Project = {
  slug: string;
  title: string;
  shortTitle: string;
  type: ProjectType;
  time: string;
  status?: string;
  keywords: string[];
  summary: string;
  background: string[];
  methods: string[];
  myWork: string[];
  outcomes: string[];
  reflections: string[];
  links?: { label: string; href: string }[];
  codeSnippet?: string;
};

export const basicInfo = {
  nameZh: "李宛莹",
  nameEn: "Wanying Li",
  school: "中山大学（珠海）数学学院",
  major: "信息与计算科学",
  grade: "2023级本科生",
  email: "liwy266@mail2.sysu.edu.cn",
  headline:
    "中山大学数学学院信息与计算科学本科生，具有数学统计、数值计算与程序设计基础，关注统计机器学习、大数据分析、工程智能与可靠 AI 系统中的建模和算法问题。",
  cvUrl: "/files/Li-Wanying-CV.pdf",
  portraitUrl: "/images/li-wanying-profile.png",
  github: "https://github.com/lwy959",
};

export const about =
  "我是李宛莹，中山大学数学学院（珠海）信息与计算科学专业本科生。我的本科训练以数学、统计和计算为主，核心课程包括数理统计、概率论、数值分析、偏微分方程和数据结构与算法。自 2025 年 9 月起，我在中山大学人工智能学院副教授常晓斌课题组进行科研实习，参与持续学习与模型稳定性相关课题，主要关注参数重要性识别、mask 机制和稳定性-可塑性平衡；也曾参与基于 CTT 与 IRT 的教材评估项目，使用隐变量建模和 EM 参数估计方法分析习题质量。未来我希望继续在可靠 AI 推理、统计机器学习和模型稳定性方向接受系统训练。";

export const education = {
  degree: "理学学士，信息与计算科学专业",
  institution: "中山大学（珠海）数学学院",
  period: "2023.09 - 2027.06",
  gpa: "3.92 / 5.0",
  rank: "15 / 88",
  english: "CET-6 556",
  coursework: [
    ["数学分析", "92"],
    ["高等代数", "91"],
    ["概率论", "91"],
    ["数理统计", "97"],
    ["数值分析", "95"],
    ["偏微分方程", "99"],
    ["C++ 程序设计", "92"],
    ["数据结构与算法", "课程项目"],
  ],
};

export const researchInterests = [
  {
    title: "Reliable AI & Continual Learning",
    items: ["可靠 AI 推理", "持续学习", "模型稳定性", "稳定性-可塑性平衡", "参数重要性评估"],
  },
  {
    title: "Statistical Machine Learning & Data Science",
    items: ["统计机器学习", "高维统计", "隐变量模型", "EM 参数估计", "不确定性估计"],
  },
  {
    title: "Engineering Intelligence & Digital Twin",
    items: ["数字孪生", "工程智能", "AI for Engineering", "数值计算", "优化思想"],
  },
];

export const skills = [
  {
    title: "Programming",
    items: ["Python", "C++", "MATLAB", "Git", "Linux", "LaTeX"],
  },
  {
    title: "Machine Learning",
    items: ["PyTorch", "训练流程阅读", "loss 构建", "mask 机制", "剪枝", "实验复现与调参"],
  },
  {
    title: "Mathematical Modeling",
    items: ["概率统计", "数值计算", "优化思想", "隐变量模型", "IRT/CTT", "EM 参数估计"],
  },
  {
    title: "Research Tools",
    items: ["英文文献阅读", "源码剖析", "算法验证", "技术报告写作"],
  },
];

export const awards = [
  "中山大学优秀学生一等奖学金（2023）",
  "中山大学优秀学生二等奖学金（2024）",
  "第十七届全国大学生数学竞赛广东省三等奖",
  "全国大学生数学建模广东省三等奖（2024, 2025）",
  "第六届“华数杯”国赛本科组三等奖",
  "第十七届“电工杯”数学建模三等奖",
];

export const projects: Project[] = [
  {
    slug: "continual-learning",
    title: "Parameter Importance and Model Stability in Continual Learning",
    shortTitle: "Continual Learning & Parameter Importance",
    type: "Research Training",
    time: "2025.09 - 至今",
    status: "中山大学人工智能学院常晓斌副教授课题组科研实习；Ongoing; 未正式发表",
    keywords: [
      "Continual Learning",
      "Catastrophic Forgetting",
      "Lottery Ticket Hypothesis",
      "Mask Mechanism",
      "Parameter Importance",
      "PyTorch",
    ],
    summary:
      "自 2025 年 9 月起，在中山大学人工智能学院副教授常晓斌课题组进行科研实习，参与持续学习与模型稳定性相关课题，围绕参数重要性识别、重要参数保护与稳定性-可塑性平衡展开训练。目前重点在源码阅读、训练流程梳理、mask 与剪枝机制理解，以及对参数重要性判定规则的分析。",
    background: [
      "科研实习依托中山大学人工智能学院常晓斌副教授课题组展开，当前作为 ongoing research training 展示，不写作正式发表成果。",
      "持续学习场景中，模型需要在任务流中学习新任务，同时尽量保留旧任务能力，核心挑战是灾难性遗忘。",
      "参数隔离、剪枝、Lottery Ticket Hypothesis 与 winning tickets 等思路，为理解模型容量受限条件下的稳定更新提供了切入点。",
    ],
    methods: [
      "阅读课题组 Continual Winning Tickets 相关 PyTorch 代码，梳理训练循环、mask 更新、软掩码惩罚项和剪枝稀疏度设置。",
      "对照论文推导与代码实现，记录 loss 构建、参数筛选和任务间保护机制的实现路径。",
      "从参数贡献度、任务相关性、稳定性-可塑性平衡角度理解参数重要性判定标准。",
    ],
    myWork: [
      "整理 PyTorch 训练流程与关键模块调用关系。",
      "核查 mask 机制、剪枝稀疏度与损失函数中的约束项。",
      "参与基线复现实验的超参数调试与结果检查。",
      "形成关于参数重要性规则局限性的阅读和分析笔记。",
    ],
    outcomes: [
      "加深了对持续学习、灾难性遗忘与模型稳定更新问题的理解。",
      "训练了从源码到算法假设的反向验证能力。",
      "目前作为正在进行的研究训练展示，不写作正式发表成果。",
    ],
    reflections: [
      "这段训练让我意识到，可靠 AI 不只是提高平均指标，也包括理解模型为何在任务变化后失稳。",
      "后续希望继续学习大模型机理分析、参数重要性评估和更系统的统计机器学习方法。",
    ],
  },
  {
    slug: "irt-textbook-evaluation",
    title: "CTT/IRT-based Quantitative Evaluation Framework for Advanced Mathematics Textbooks",
    shortTitle: "CTT/IRT-based Textbook Evaluation System",
    type: "National Innovation Project",
    time: "2024.12 - 2025.12",
    status: "国家级大创优秀结项",
    keywords: ["CTT", "IRT", "Logistic Model", "EM Algorithm", "ICC", "TIF", "AHP", "Education Measurement"],
    summary:
      "该项目针对教材习题评价依赖主观经验、缺乏量化依据的问题，引入经典测验理论与项目反应理论，基于学生作答数据构建教材习题质量评估框架。",
    background: [
      "现有高等数学教材评价往往依赖专家经验，系统化、可量化的指标体系相对不足。",
      "项目希望将教育测量、统计建模与教材分析结合，为教材选择和教学侧重点提供更客观的参考。",
    ],
    methods: [
      "使用 CTT 中的相关系数法、临界比值法、Cronbach's alpha 系数法与因子分析筛选指标。",
      "通过内容效度、探索性因子分析与验证性因子分析检验量表结构。",
      "使用 AHP 初步分配指标权重，并引入 IRT 三参数 logistic 模型分析学生潜在能力与题目参数。",
      "结合 ICC 与 TIF 分析题目质量、难度分布和章节适配度。",
    ],
    myWork: [
      "参与教材评估指标体系与项目技术路线整理。",
      "完成 IRT 逻辑斯蒂模型、对数似然与参数估计框架的推导梳理。",
      "参与 EM 参数估计框架设计，并整理题目质量分析指标。",
      "协助将项目材料组织为答辩展示和结项材料。",
    ],
    outcomes: [
      "形成 6 个维度、若干核心指标的教材评估体系草案与权重分析思路。",
      "完成国家级大创优秀结项。",
      "强化了隐变量建模、参数推断和统计建模在教育测量场景中的应用训练。",
    ],
    reflections: [
      "相比单纯给教材打分，这个项目更重要的训练在于把抽象评价标准转化为可检验的统计问题。",
      "后续还需要在真实数据规模、评分一致性和模型假设检验方面做更扎实的补充。",
    ],
  },
  {
    slug: "k-shortest-paths",
    title: "Graph Algorithms and K-Shortest Paths in C++",
    shortTitle: "Graph Algorithms and K-Shortest Paths Course Project",
    type: "Course Project",
    time: "2024.12",
    keywords: ["C++", "Data Structures", "Adjacency Matrix", "BFS", "DFS", "Dijkstra", "Yen's KSP", "Priority Queue"],
    summary:
      "数据结构与算法课程项目，使用 C++ 实现自定义线性表、链式栈、链式队列、邻接矩阵图结构，并在图上实现 Dijkstra 与 Yen 风格的 K 条最短路径搜索。",
    background: [
      "课程要求围绕图结构与路径算法完成综合实现，既考察基础数据结构，也考察路径规划算法的组合使用。",
      "项目还加入了中继点黑名单和最大中继点数限制，使最短路径搜索需要处理额外约束。",
    ],
    methods: [
      "实现 `VecList`, `LinkStack`, `LinkQueue` 作为基础容器。",
      "使用邻接矩阵表示无向带权图，支持边的添加、删除与原始权重恢复。",
      "将 Dijkstra 改造成两点最短路径函数，并加入黑名单与中继点数量限制。",
      "参考 Yen's Algorithm 的 root/spur 思路生成候选路径，并使用优先队列选出当前最短候选。",
    ],
    myWork: [
      "完成图结构、路径权重计算、路径去重和候选路径选择逻辑。",
      "补充 `operator=` 与 `operator==` 以支持自定义路径容器复制和比较。",
      "将原始单文件整理为 `include/` 与 `src/` 结构，并补充 README、复杂度分析和示例输入输出。",
    ],
    outcomes: [
      "整理后的代码位于 `projects/dsa-k-shortest-paths/`。",
      "保留原始代码备份于 `raw/大作业2.cpp`。",
      "该项目展示的是课程训练中的 C++ 数据结构与图算法实现能力。",
    ],
    reflections: [
      "这个项目让我更直观地理解了路径算法不仅是公式，也依赖图结构、边恢复、候选集合管理等实现细节。",
      "代码仍保留课程作业风格，后续若继续完善，可加入更系统的单元测试和异常输入处理。",
    ],
    links: [
      { label: "整理版 README", href: "/files/dsa-k-shortest-paths-README.md" },
      { label: "课程报告 PDF", href: "/files/DSA-Project-2-KSP.pdf" },
    ],
    codeSnippet: `paths A; candidates B
first = Dijkstra(start, end)
for each path in A:
  for each spur node:
    remove edges sharing the same root path
    spur = Dijkstra(spurNode, end)
    restore removed edges
    push root + spur into B
select the shortest non-duplicate candidate`,
  },
  {
    slug: "data-structure-assignment-1",
    title: "DPLL-based Boolean Satisfiability Solver",
    shortTitle: "Data Structures & Algorithms Course Project I",
    type: "Course Project",
    time: "2024",
    keywords: ["C++", "3-CNF", "SAT", "DPLL", "Unit Propagation", "Backtracking", "Branching Heuristic"],
    summary:
      "数据结构与算法课程项目，针对 3-CNF 布尔可满足性问题实现 DPLL 求解流程，包括子句简化、单子句传播、变量选择与递归回溯。",
    background: [
      "题目要求判断由多个三文字子句构成的布尔表达式是否存在满足赋值。",
      "项目报告中将该问题归类为 Boolean Satisfiability Problem，并选择 DPLL 作为核心算法。",
    ],
    methods: [
      "使用 `Clause` 结构体与 `vector<Clause>` 表示 CNF 公式。",
      "使用长度为 n 的赋值向量表示变量状态：1 为真，0 为未赋值，-1 为假。",
      "在每轮递归中先简化子句，若出现单子句则直接赋值并继续传播。",
      "当没有更多单子句时，选择出现频率最高的未赋值变量进行真假分支搜索。",
    ],
    myWork: [
      "完成输入校验、子句生成、公式简化与 DPLL 递归逻辑。",
      "使用临时赋值向量进行分支尝试，避免递归过程中直接污染当前赋值。",
      "将原始代码和报告整理为课程项目材料，并补充 README。",
    ],
    outcomes: [
      "整理后的代码位于 `projects/dsa-sat-dpll/`。",
      "保留原始代码备份于 `raw/23339050_proj1.cpp`。",
      "该项目作为课程作业展示算法实现过程，不包装为研究型 SAT 求解器。",
    ],
    reflections: [
      "这个项目帮助我理解递归搜索中状态复制、剪枝和变量选择策略对正确性与效率的影响。",
      "后续可以补充更完整的 DIMACS 输入兼容和测试样例，但当前页面保留课程作业的原始实现思路。",
    ],
    links: [
      { label: "整理版 README", href: "/files/dsa-sat-dpll-README.md" },
      { label: "课程报告 PDF", href: "/files/DSA-Project-1-DPLL.pdf" },
    ],
  },
];
