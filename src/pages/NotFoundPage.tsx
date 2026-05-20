import { Layout } from "../components/Layout";
import { appPath } from "../utils/paths";

export function NotFoundPage() {
  return (
    <Layout>
      <section className="page-title">
        <p className="kicker">404</p>
        <h1>Page Not Found</h1>
        <p>这个页面暂时不存在。可以返回首页或项目列表继续浏览。</p>
        <div className="hero-actions">
          <a className="button primary" href={appPath("/")}>Home</a>
          <a className="button secondary" href={appPath("/projects")}>Projects</a>
        </div>
      </section>
    </Layout>
  );
}
