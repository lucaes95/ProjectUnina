"use server";

import { createClient } from "@/utils/supabase/server";
import { redirect } from "next/navigation";
import  UseUserId  from "../../_components/use-user-id"

export type FormState = {
  message: string;
  error: string;
};

export const confirmAction = async (
  prevState: FormState,
  formData : FormData
) => {
  "use server"
    const title = formData.get("title") as string;
    const subtitle = formData.get("subtitle") as string;
    const content = formData.get("content") as string;
    const date = formData.get("date") as string;
    const tagsString = formData.get("tags") as string;
    const userId = await UseUserId();

      // Convertiamo la stringa dei tag in un array di tag
  const tags = tagsString.split(",").map(tag => tag.trim().replace(/#/g, ''));

    
    const supabaseClient = createClient();
    const { error } = await supabaseClient.from("Articles").insert({id_user: userId, title: title, subtitle: subtitle, content: content, date: date, tags: tags})

    if(error){
      return {message: "", error: error.message}
    }  

    redirect("/my-article");
    
  };