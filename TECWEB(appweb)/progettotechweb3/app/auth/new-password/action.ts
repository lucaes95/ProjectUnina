"use server";

import { createClient } from "@/utils/supabase/server";

export type FormState = {
    message: string;
    error: string;
};

export const changePasswordAction = async (
    prevState: FormState,
    formData: FormData
) => {

    const password = formData.get("password") as string;
    const confirmPassword = formData.get("confirm-password") as string;

    if (!password || password != confirmPassword) {
      return {message: "", error: "Password is different"};
    }
    
    const supabaseClient = createClient();
    const { error } = await supabaseClient.auth.updateUser({ password: confirmPassword })

    if(error){
        return {message: "", error: error.message}
    }
    
    return {message: "Password is valid", error: ""};
        
  };