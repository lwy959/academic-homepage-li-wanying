type SectionProps = {
  id?: string;
  eyebrow?: string;
  title: string;
  children: React.ReactNode;
};

export function Section({ id, eyebrow, title, children }: SectionProps) {
  return (
    <section id={id} className="section">
      <div className="section-heading">
        {eyebrow ? <span>{eyebrow}</span> : null}
        <h2>{title}</h2>
      </div>
      {children}
    </section>
  );
}
