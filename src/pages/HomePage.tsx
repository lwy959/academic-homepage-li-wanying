import { ArrowRight, Download, Mail, MapPin } from "lucide-react";
import { Layout } from "../components/Layout";
import { Section } from "../components/Section";
import { about, awards, basicInfo, education, projects, researchInterests, skills } from "../data/profile";
import { appPath } from "../utils/paths";

export function HomePage() {
  return (
    <Layout>
      <section className="hero">
        <div className="hero-copy">
          <p className="kicker">Academic Homepage</p>
          <h1>{basicInfo.nameZh}</h1>
          <h2>{basicInfo.nameEn}</h2>
          <p>{basicInfo.headline}</p>
          <div className="hero-actions">
            <a className="button primary" href={appPath(basicInfo.cvUrl)}><Download size={18} />Download CV</a>
            <a className="button secondary" href={appPath("/projects")}><ArrowRight size={18} />View Projects</a>
            <a className="button ghost" href={`mailto:${basicInfo.email}`}><Mail size={18} />Email Me</a>
          </div>
        </div>
        <aside className="hero-panel" aria-label="Profile facts">
          <figure className="portrait-frame">
            <img src={appPath(basicInfo.portraitUrl)} alt="李宛莹 portrait" />
          </figure>
          <div><span>School</span><strong>{basicInfo.school}</strong></div>
          <div><span>Major</span><strong>{basicInfo.major}</strong></div>
          <div><span>GPA / Rank</span><strong>{education.gpa} · {education.rank}</strong></div>
          <div><span>Focus</span><strong>Reliable AI · Continual Learning · Statistics</strong></div>
        </aside>
      </section>

      <Section id="about" eyebrow="About" title="About Me">
        <p className="lead">{about}</p>
      </Section>

      <Section id="interests" eyebrow="Research" title="Research Interests">
        <div className="three-column">
          {researchInterests.map((group) => (
            <article className="plain-card" key={group.title}>
              <h3>{group.title}</h3>
              <ul className="tag-list">
                {group.items.map((item) => <li key={item}>{item}</li>)}
              </ul>
            </article>
          ))}
        </div>
      </Section>

      <Section id="projects" eyebrow="Selected" title="Selected Projects">
        <div className="project-grid">
          {projects.map((project) => (
            <a className="project-card" href={appPath(`/projects/${project.slug}`)} key={project.slug}>
              <div>
                <span className="project-type">{project.type}</span>
                {project.status ? <span className="status">{project.status}</span> : null}
              </div>
              <h3>{project.shortTitle}</h3>
              <p>{project.summary}</p>
              <span className="text-link">Read project details <ArrowRight size={15} /></span>
            </a>
          ))}
        </div>
      </Section>

      <Section id="education" eyebrow="Education" title="Education & Coursework">
        <div className="education-layout">
          <article className="plain-card">
            <h3>{education.institution}</h3>
            <p>{education.degree}</p>
            <p className="muted">{education.period}</p>
            <dl className="facts">
              <div><dt>GPA</dt><dd>{education.gpa}</dd></div>
              <div><dt>Rank</dt><dd>{education.rank}</dd></div>
              <div><dt>English</dt><dd>{education.english}</dd></div>
            </dl>
          </article>
          <div className="course-list">
            {education.coursework.map(([course, score]) => (
              <div key={course}>
                <span>{course}</span>
                <strong>{score}</strong>
              </div>
            ))}
          </div>
        </div>
      </Section>

      <Section id="skills" eyebrow="Skills" title="Skills">
        <div className="four-column">
          {skills.map((group) => (
            <article className="plain-card" key={group.title}>
              <h3>{group.title}</h3>
              <ul>
                {group.items.map((item) => <li key={item}>{item}</li>)}
              </ul>
            </article>
          ))}
        </div>
      </Section>

      <Section id="awards" eyebrow="Awards" title="Awards">
        <ul className="award-list">
          {awards.map((award) => <li key={award}>{award}</li>)}
        </ul>
      </Section>

      <Section id="contact" eyebrow="Contact" title="Contact">
        <div className="contact-panel">
          <p><MapPin size={17} /> {basicInfo.school}</p>
          <p><Mail size={17} /> <a href={`mailto:${basicInfo.email}`}>{basicInfo.email}</a></p>
          <p>GitHub: <a href={basicInfo.github}>{basicInfo.github}</a></p>
        </div>
      </Section>
    </Layout>
  );
}
