export default function AuthLayout({
  children,
}: Readonly<{
  children: React.ReactNode;
}>) {
  return (
    <main className="min-h-screen flex item-center justify-center w-full">
      {children}
    </main>
  );
}
