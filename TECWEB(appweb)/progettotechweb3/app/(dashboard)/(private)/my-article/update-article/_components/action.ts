"use server";

import { createClient } from "@/utils/supabase/server";
import { redirect} from "next/navigation";
export type FormState = {
  message: string;
  error: string;
};

export const confirmAction = async ( prevState: FormState, formData : FormData) => {
  
    const title = formData.get("title") as string;
    const subtitle = formData.get("subtitle") as string;
    const content = formData.get("content") as string;
    const lastdate = formData.get("lastdate") as string;
    const tagsString = formData.get("tags") as string;
    const articleId = formData.get("id_article") as string;

      // Convertiamo la stringa dei tag in un array di tag
    const tags = tagsString.split(",").map(tag => tag.trim());

    const supabaseClient = createClient();

    const { error } = await supabaseClient.from("Articles").update({title: title, subtitle: subtitle, content: content, lastdate: lastdate, tags: tags}).eq("id_article", articleId).select();

    if(error){
      return {message: "", error: error.message}
    }  

    redirect("/my-article");
  };