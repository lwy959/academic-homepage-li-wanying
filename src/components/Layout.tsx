import { Mail, Phone, FileText } from "lucide-react";
import { basicInfo } from "../data/profile";

type LayoutProps = {
  children: React.ReactNode;
};

export function Layout({ children }: LayoutProps) {
  return (
    <div className="site-shell">
      <header className="site-header">
        <a className="brand" href="/">
          <span>{basicInfo.nameZh}</span>
          <small>{basicInfo.nameEn}</small>
        </a>
        <nav aria-label="Main navigation">
          <a href="/">Home</a>
          <a href="/projects">Projects</a>
          <a href={basicInfo.cvUrl}>CV</a>
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
          <a href={`tel:${basicInfo.phone}`}><Phone size={16} />{basicInfo.phone}</a>
          <a href={basicInfo.cvUrl}><FileText size={16} />Download CV</a>
        </div>
      </footer>
    </div>
  );
}
