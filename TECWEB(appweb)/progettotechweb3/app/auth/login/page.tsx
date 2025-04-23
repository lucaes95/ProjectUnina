"use client"

import { Button } from "@/components/ui/button"
import Link from "next/link";
import { loginAction, FormState } from "./action";
import { useFormState } from "react-dom";

const initialState: FormState = {
  message: "",
  error: "",
};

export default function Login() {

  const [state, formAction] = useFormState(loginAction, initialState)
  return (
    <main className=" flex flex-col justify-start w-full mx-auto items-center text-gray-700 bg-gray-100" >
      <div className="min-h-screen flex items-center justify-center w-full dark:bg-gray-950">
        <div className="bg-white dark:bg-gray-900 shadow-md rounded-lg px-8 py-6 max-w-md">
          <h1 className="text-2xl font-bold text-center mb-4 dark:text-gray-200 pb-2">Welcome Back!</h1>
          <form action={formAction}>
            <div className="mb-4">
              <label htmlFor="email" className="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-2">User</label>
              <input type="email" name="email" id="email" className="shadow-sm rounded-md w-full px-3 py-2 border border-gray-300 focus:outline-none focus:ring-indigo-500 focus:border-indigo-500" placeholder="Enter your e-mail" required />
            </div>
            <div className="mb-4">
              <label htmlFor="password" className="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-2">Password</label>
              <input type="password" name="password" id="password" className="shadow-sm rounded-md w-full px-3 py-2 border border-gray-300 focus:outline-none focus:ring-indigo-500 focus:border-indigo-500" placeholder="Enter your password" required />
            </div>
            <div className="text-red-700 text-center">
              {state.error}
            </div>
            <Button type="submit" variant={"outline"} className="w-full mt-4">Login</Button>
            <div className="flex flex-col text-center">
              <Link href="../../" className="text-primary text-sm pt-4">&#8592; Back to home</Link>
            </div>
          </form>
        </div>
      </div>
    </main >
  );
};
