import { HomePage } from "./pages/HomePage";
import { ProjectsPage } from "./pages/ProjectsPage";
import { ProjectPage } from "./pages/ProjectPage";
import { NotFoundPage } from "./pages/NotFoundPage";
import { appPath, routeFromLocation } from "./utils/paths";

function normalizePath() {
  const params = new URLSearchParams(window.location.search);
  const redirected = params.get("redirect");
  if (redirected) {
    window.history.replaceState({}, "", appPath(redirected));
    const route = redirected.split(/[?#]/)[0];
    return route.replace(/\/$/, "") || "/";
  }
  return routeFromLocation(window.location.pathname);
}

export function App() {
  const path = normalizePath();

  if (path === "/") return <HomePage />;
  if (path === "/projects") return <ProjectsPage />;
  if (path.startsWith("/projects/")) {
    const slug = path.replace("/projects/", "");
    return <ProjectPage slug={slug} />;
  }
  return <NotFoundPage />;
}
