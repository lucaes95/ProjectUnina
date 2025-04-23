import Logo from "../icon/logo";
import { Button } from "../ui/button";
import UserMenu from "./user-menu";
import AdministratorMenu from "./administrator-menu";
import Link from "next/link";

interface NavbarProps {
    isAdministrator: boolean
    isLoggedIn: boolean
    userEmail: string | undefined

}

const Navbar = ({ isAdministrator, isLoggedIn, userEmail }: NavbarProps) => {

    return (
        <div className="bg-white">
            <div>
                <div className="flex max-w-7xl mx-auto p-8">
                    <div className="flex-1">
                        <Link href={"/"}>
                            <Logo width={260} height={145} />
                        </Link>
                    </div>
                    <div>

                    </div>
                    <div className="mt-2">
                        <p className="text-gray-400 text-xs">{userEmail}</p>

                        {
                            isLoggedIn ? (isAdministrator ? (<AdministratorMenu />) : (<UserMenu />)) : (<Button variant="outline" asChild>
                                <Link href="/auth/login">Login </Link></Button>)
                        }
                    </div>
                </div>
            </div>
        </div >
    );
};

export default Navbar;