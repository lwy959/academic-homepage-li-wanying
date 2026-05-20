export function appPath(path: string) {
  if (
    path.startsWith("http://") ||
    path.startsWith("https://") ||
    path.startsWith("mailto:") ||
    path.startsWith("tel:")
  ) {
    return path;
  }

  const base = import.meta.env.BASE_URL;
  const cleanBase = base.endsWith("/") ? base.slice(0, -1) : base;
  if (path === "/") return base;
  return `${cleanBase}${path}`;
}

export function routeFromLocation(pathname: string) {
  const base = import.meta.env.BASE_URL;
  if (base !== "/" && pathname.startsWith(base)) {
    const stripped = pathname.slice(base.length);
    return `/${stripped}`.replace(/\/$/, "") || "/";
  }
  return pathname.replace(/\/$/, "") || "/";
}
