"use server"

import { createClient } from "@/utils/supabase/server";
import ViewItemArticle from "./_components/view-article";

interface Props {
    searchParams: { [key: string]: string | string[] | undefined };
}

export default async function Home({ searchParams }: Props) {
    const idarticle = searchParams.id_article ?? 0;
    const supabaseClient = createClient();
    const { data } = await supabaseClient.from("Articles").select("*,Profiles(*)").eq("id_article", idarticle);

    if (!data) {

        return "error article";
    }

    return (
        <main className=" flex flex-col justify-start w-full mx-auto items-center text-gray-700 bg-gray-100 py-20" >
            <div className="w-full max-w-4xl">
                <ViewItemArticle Articles={data} />
            </div>
        </main>
    );
}