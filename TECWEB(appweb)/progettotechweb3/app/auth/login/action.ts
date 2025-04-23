"use server";

import { createClient } from "@/utils/supabase/server";
import { redirect } from "next/navigation";

export type FormState = {
  message: string;
  error: string;
};


export const loginAction = async (
  prevState: FormState,
  formData : FormData
) => {
  "use server"
    const email = formData.get("email") as string;
    const password = formData.get("password") as string;
    
    const supabaseClient = createClient();
    const {error} = await supabaseClient.auth.signInWithPassword({
      email,
      password,
    })

    if(error){
      return {message: "", error: error.message}
    }  

    redirect("/");
  };