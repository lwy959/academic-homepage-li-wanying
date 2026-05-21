import { Mail, FileText } from "lucide-react";
import { basicInfo } from "../data/profile";
import { appPath } from "../utils/paths";

type LayoutProps = {
  children: React.ReactNode;
};

export function Layout({ children }: LayoutProps) {
  return (
    <div className="site-shell">
      <header className="site-header">
        <a className="brand" href={appPath("/")}>
          <span>{basicInfo.nameZh}</span>
          <small>{basicInfo.nameEn}</small>
        </a>
        <nav aria-label="Main navigation">
          <a href={appPath("/")}>Home</a>
          <a href={appPath("/projects")}>Projects</a>
          <a href={appPath(basicInfo.cvUrl)}>CV</a>
          <a href={`mailto:${basicInfo.email}`}>Contact</a>
        </nav>
      </header>
      <main>{children}</main>
      <footer className="site-footer">
        <div>
          <strong>{basicInfo.nameZh}</strong>
          <span>{basicInfo.school} · {basicInfo.major}</span>
        </div>
        <div className="footer-links">
          <a href={`mailto:${basicInfo.email}`}><Mail size={16} />{basicInfo.email}</a>
          <a href={appPath(basicInfo.cvUrl)}><FileText size={16} />Download CV</a>
        </div>
      </footer>
    </div>
  );
}
