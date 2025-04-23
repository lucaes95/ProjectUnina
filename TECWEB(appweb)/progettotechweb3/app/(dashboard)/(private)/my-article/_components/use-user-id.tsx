import { createClient } from "@/utils/supabase/server";

const UseUserId = async () => {

    const supabaseClient = createClient();

    const { data } = await supabaseClient.auth.getUser();

    const userId: string = String(data.user?.id);

    return userId;

}

export default UseUserId;