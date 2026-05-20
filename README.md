# 李宛莹个人学术主页

面向保研/联系导师场景的静态个人主页，使用 Vite + React + TypeScript 构建，内容以数学统计基础、科研训练、国家级大创和数据结构课程项目为主。

## Local Development

```bash
npm install
npm run dev
```

## Build

```bash
npm run build
npm run lint
```

## Deploy

仓库包含 GitHub Pages Actions 配置：

```text
.github/workflows/deploy.yml
```

推送到 `main` 后，GitHub Actions 会构建 `dist` 并部署到 GitHub Pages。

## Content Notes

- 持续学习课题表述为 ongoing research training，不写作正式发表论文。
- 国家级大创项目表述为 innovation project，不包装为论文发表。
- 数据结构与算法作业表述为 course project，并保留原始材料备份。
