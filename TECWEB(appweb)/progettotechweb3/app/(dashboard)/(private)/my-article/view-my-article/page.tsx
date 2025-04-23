"use server"

import { createClient } from "@/utils/supabase/server";
import ViewMyItemArticle from "./_components/view-my-article";
import Link from "next/link";

interface Props {
    searchParams: { [key: string]: string | string[] | undefined };
}

export default async function MyArticles({ searchParams }: Props) {
    const idarticle = searchParams.id_article ?? 0;
    const supabaseClient = createClient();
    const { data } = await supabaseClient.from("Articles").select("*, Profiles(*)").eq("id_article", idarticle);

    if (!data) {

        return "error article";
    }

    return (
        <main className=" flex flex-col justify-start w-full mx-auto items-center text-gray-700 bg-gray-100 py-20" >
            <div className="w-full max-w-4xl">
                <ViewMyItemArticle Articles={data} />
                <div className="flex flex-col text-center">
                    <Link href="/my-article" className="text-primary text-sm pt-4">&#8592; Back to my-article</Link>
                </div>
            </div>
        </main>
    );
}