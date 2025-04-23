"use server"

import ItemMyArticle from "./_components/items-my-articles";
import { createClient } from "@/utils/supabase/server";
import PropertyContainer from "./_components/property-container";
import countAllMyArticles from "./_components/count-all-my-articles";
import UseUserId from "./_components/use-user-id";

const PAGE_SIZE = 10;

interface Props {
  searchParams: { [key: string]: string | string[] | undefined };
}

export default async function MyArticles({ searchParams }: Props) {
  const pagenum = searchParams.pagenum ?? 0;
  const supabaseClient = createClient();

  const userId = await UseUserId();

  const { data } = await supabaseClient.from("Articles").select("*, Profiles(*)").eq("id_user", userId).order("date", { ascending: false }).range(Number(pagenum) * PAGE_SIZE, ((Number(pagenum) + 1) * PAGE_SIZE) - 1);

  const totalArticles = await countAllMyArticles();
  const totalPages = Math.ceil(totalArticles / PAGE_SIZE);

  if (!data) {
    return "error article";
  }

  return (

    <main className=" flex flex-col justify-start w-full mx-auto items-center text-gray-700 bg-gray-100 py-20" >
      <ItemMyArticle Articles={data} />
      {totalArticles > PAGE_SIZE ? (<PropertyContainer totalPages={totalPages} currentPages={+pagenum} />) : <></>}
    </main >
  );
};
