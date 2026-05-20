import { HomePage } from "./pages/HomePage";
import { ProjectsPage } from "./pages/ProjectsPage";
import { ProjectPage } from "./pages/ProjectPage";
import { NotFoundPage } from "./pages/NotFoundPage";

function normalizePath() {
  const params = new URLSearchParams(window.location.search);
  const redirected = params.get("redirect");
  if (redirected) {
    window.history.replaceState({}, "", redirected);
    return redirected;
  }
  return window.location.pathname;
}

export function App() {
  const path = normalizePath().replace(/\/$/, "") || "/";

  if (path === "/") return <HomePage />;
  if (path === "/projects") return <ProjectsPage />;
  if (path.startsWith("/projects/")) {
    const slug = path.replace("/projects/", "");
    return <ProjectPage slug={slug} />;
  }
  return <NotFoundPage />;
}
