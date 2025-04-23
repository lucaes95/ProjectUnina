"use client"

import {
    DropdownMenu,
    DropdownMenuContent,
    DropdownMenuItem,
    DropdownMenuLabel,
    DropdownMenuSeparator,
    DropdownMenuTrigger,
} from "@/components/ui/dropdown-menu"
import { createClient } from "@/utils/supabase/client";
import { useRouter } from "next/navigation";
import Link from "next/link";


const UserMenu = () => {
    const router = useRouter();

    const logout = async () => {
        const supabaseClient = createClient();
        const { error } = await supabaseClient.auth.signOut();
        if (!error) {
            router.refresh();
        }
    };

    return (
        <DropdownMenu>
            <DropdownMenuTrigger>Hello, User !</DropdownMenuTrigger>
            <DropdownMenuContent>
                <DropdownMenuLabel>My Account</DropdownMenuLabel>
                <DropdownMenuSeparator />
                <DropdownMenuItem><Link href={"/my-article"}>My Articles</Link></DropdownMenuItem>
                <DropdownMenuItem><Link href={"/my-article/write-article"}>Write Article</Link></DropdownMenuItem>
                <DropdownMenuItem><Link href={"/auth/new-password"}>Modify Password</Link></DropdownMenuItem>
                <DropdownMenuSeparator />
                <DropdownMenuItem onClick={logout}>Logout</DropdownMenuItem>
            </DropdownMenuContent>
        </DropdownMenu>
    );
};

export default UserMenu;