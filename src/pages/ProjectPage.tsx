import { ArrowLeft, ExternalLink } from "lucide-react";
import { Layout } from "../components/Layout";
import { projects } from "../data/profile";
import { NotFoundPage } from "./NotFoundPage";
import { appPath } from "../utils/paths";

type ProjectPageProps = {
  slug: string;
};

export function ProjectPage({ slug }: ProjectPageProps) {
  const project = projects.find((item) => item.slug === slug);
  if (!project) return <NotFoundPage />;

  return (
    <Layout>
      <article className="project-detail">
        <a className="back-link" href={appPath("/projects")}><ArrowLeft size={16} />Back to projects</a>
        <header className="detail-header">
          <span className="project-type">{project.type}</span>
          <h1>{project.title}</h1>
          <p>{project.summary}</p>
          <dl className="meta-grid">
            <div><dt>Time</dt><dd>{project.time}</dd></div>
            <div><dt>Status</dt><dd>{project.status ?? "Completed"}</dd></div>
            <div><dt>Keywords</dt><dd>{project.keywords.join(" · ")}</dd></div>
          </dl>
        </header>

        <DetailSection title="Background" items={project.background} />
        <DetailSection title="Methods & Implementation" items={project.methods} />
        <DetailSection title="My Work" items={project.myWork} />
        <DetailSection title="Outcomes" items={project.outcomes} />
        <DetailSection title="Reflection" items={project.reflections} />

        {project.codeSnippet ? (
          <section className="detail-section">
            <h2>Algorithm Sketch</h2>
            <pre><code>{project.codeSnippet}</code></pre>
          </section>
        ) : null}

        {project.links?.length ? (
          <section className="detail-section">
            <h2>Materials</h2>
            <div className="material-links">
              {project.links.map((link) => (
                <a href={appPath(link.href)} key={link.href}>
                  {link.label}<ExternalLink size={15} />
                </a>
              ))}
            </div>
          </section>
        ) : null}
      </article>
    </Layout>
  );
}

function DetailSection({ title, items }: { title: string; items: string[] }) {
  return (
    <section className="detail-section">
      <h2>{title}</h2>
      <ul>
        {items.map((item) => <li key={item}>{item}</li>)}
      </ul>
    </section>
  );
}
