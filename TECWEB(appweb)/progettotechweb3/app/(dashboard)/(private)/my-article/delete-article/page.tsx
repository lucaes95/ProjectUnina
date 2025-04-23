"use server"

import { createClient } from "@/utils/supabase/server";

interface Props {
    searchParams: { [key: string]: string | string[] | undefined };
}

export default async function deleteArticle({ searchParams }: Props) {

    const idarticle = searchParams.id_article ?? 0;
    const supabaseClient = createClient();
    const response = await supabaseClient.from("Articles").delete().eq("id_article", idarticle);

    return (
        <main className=" flex flex-col justify-start w-full mx-auto items-center text-gray-700 bg-gray-100" >
            <div className="m-24 flex items-center justify-center dark:bg-gray-950">
                <form>
                    <div className="bg-white dark:bg-gray-900 shadow-md rounded-lg px-8 py-6 max-w-md">
                        {response ? (<p>L&#39;articolo è stato eliminato correttamente.</p>) : (<p>L&#39;articolo non è stato eliminato.</p>)}
                    </div>
                </form>
            </div>
        </main >
    )
}