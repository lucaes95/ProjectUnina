import "../globals.css";
import Navbar from "@/components/layout/navbar";
import Footer from "@/components/layout/footer";
import { createClient } from "@/utils/supabase/server";

export default async function DashboardLayout({
  children,
}: Readonly<{
  children: React.ReactNode;
}>) {

  const supabaseClient = createClient();

  const { data } = await supabaseClient.auth.getUser();

  return (
    <>
      <Navbar isAdministrator={data.user?.email == "lucaesposito95@outlook.com"} isLoggedIn={!!data.user} userEmail={data.user?.email} />
      {children}
      <Footer />
    </>
  );
}
