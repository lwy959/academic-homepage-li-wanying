import { ArrowRight } from "lucide-react";
import { Layout } from "../components/Layout";
import { projects } from "../data/profile";
import { appPath } from "../utils/paths";

export function ProjectsPage() {
  return (
    <Layout>
      <section className="page-title">
        <p className="kicker">Projects</p>
        <h1>Research Training, Innovation Project, and Course Work</h1>
        <p>项目页按性质明确区分科研训练、国家级大创与课程项目，避免把未发表工作或课程作业包装成正式科研成果。</p>
      </section>

      <div className="project-list">
        {projects.map((project) => (
          <article className="project-row" key={project.slug}>
            <div>
              <span className="project-type">{project.type}</span>
              <h2>{project.title}</h2>
              <p>{project.summary}</p>
              <ul className="tag-list compact">
                {project.keywords.slice(0, 6).map((keyword) => <li key={keyword}>{keyword}</li>)}
              </ul>
            </div>
            <a className="button secondary" href={appPath(`/projects/${project.slug}`)}>
              Details <ArrowRight size={17} />
            </a>
          </article>
        ))}
      </div>
    </Layout>
  );
}
