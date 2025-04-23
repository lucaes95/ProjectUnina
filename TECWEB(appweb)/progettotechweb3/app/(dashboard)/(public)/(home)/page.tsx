"use server"

import { createClient } from "@/utils/supabase/server";
import ItemArticle from "../_components/item-article";
import PropertyContainer from "../_components/property-container";

const PAGE_SIZE = 10;

interface Props {
  searchParams: { [key: string]: string | string[] | undefined };
}

export default async function Home({ searchParams }: Props) {
  const pagenum = searchParams.pagenum ?? 0;
  const selectedTag = searchParams.tag ?? null;
  const supabaseClient = createClient();

  let query = supabaseClient
    .from(`Articles`)
    .select(`*, Profiles(*)`)
    .order('date', { ascending: false })

  let querycount;

  if (selectedTag) {
    query = query.contains("tags", [selectedTag]); // Filtra gli articoli che contengono il tag
    query = query.range(0, ((Number(pagenum) + 1) * PAGE_SIZE) - 1);

    querycount = supabaseClient
      .from("Articles")
      .select("*", { count: "exact" })
      .contains("tags", [selectedTag]);

  } else {
    query = query.range(Number(pagenum) * PAGE_SIZE, ((Number(pagenum) + 1) * PAGE_SIZE) - 1);

    querycount = supabaseClient
      .from("Articles")
      .select("*", { count: "exact" });
  }

  const { count } = await querycount;

  const countItems: number = count || 0;

  const totalPages = Math.ceil(countItems / PAGE_SIZE);

  const { data } = await query;

  if (!data) {
    return "error null";
  }

  return (
    <main className=" flex flex-col justify-start w-full mx-auto items-center text-gray-700 bg-gray-100 py-20" >
      <ItemArticle Articles={data} />
      {totalPages > 1 ? (<PropertyContainer totalPages={totalPages} currentPages={+pagenum} />) : <></>}
    </main>
  );
}