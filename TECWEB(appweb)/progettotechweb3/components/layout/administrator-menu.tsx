"use client"

import {
    DropdownMenu,
    DropdownMenuContent,
    DropdownMenuItem,
    DropdownMenuLabel,
    DropdownMenuSeparator,
    DropdownMenuTrigger,
} from "@/components/ui/dropdown-menu"

import Link from "next/link";
import { createClient } from "@/utils/supabase/client";
import { useRouter } from "next/navigation";

const AdministratorMenu = () => {
    const ruoter = useRouter();
    const logout = async () => {
        const supabaseClient = createClient();
        const { error } = await supabaseClient.auth.signOut();

        if (!error) {
            ruoter.refresh();
        }
    };

    return (
        <div>
            {

                // data.map((Profile) => (
                //     <>
                <DropdownMenu>
                    <DropdownMenuTrigger>Hello, Admin !</DropdownMenuTrigger>
                    <DropdownMenuContent>
                        <DropdownMenuLabel>My Account Admin</DropdownMenuLabel>
                        <DropdownMenuSeparator />
                        <DropdownMenuItem><Link href="/auth/register">Register Users</Link></DropdownMenuItem>
                        <DropdownMenuSeparator />
                        <DropdownMenuItem><Link href={"/my-article"}>My Articles</Link></DropdownMenuItem>
                        <DropdownMenuItem><Link href={"/my-article/write-article"}>Write Article</Link></DropdownMenuItem>
                        <DropdownMenuItem><Link href={"/auth/new-password"}>Modify Password</Link></DropdownMenuItem>
                        <DropdownMenuSeparator />
                        <DropdownMenuItem onClick={logout}>Logout</DropdownMenuItem>
                    </DropdownMenuContent>
                </DropdownMenu>
                //     </>
                // ))

            }
        </div>
    );
};

export default AdministratorMenu;