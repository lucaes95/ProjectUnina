
import { createClient } from "@/utils/supabase/server";
import UseUserId from "./use-user-id";

const countAllArticles = async () => {

    const userId = await UseUserId();

    const supabaseClient = createClient();

    const { count } = await supabaseClient.from("Articles").select("*", { count: "exact" }).eq("id_user", userId);

    const totalPages: number = count || 0;

    return totalPages;

}

export default countAllArticles;