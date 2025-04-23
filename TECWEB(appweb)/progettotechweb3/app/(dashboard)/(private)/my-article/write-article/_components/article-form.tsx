"use client"

import "@uiw/react-md-editor/markdown-editor.css";
import "@uiw/react-markdown-preview/markdown.css";
import dynamic from "next/dynamic";
import { Button } from "@/components/ui/button"
import Link from "next/link";
import { FormState, confirmAction } from "./action";
import { useFormState } from "react-dom";
import { useState, useEffect } from "react";


// Carica MDEditor in modo dinamico, ma senza renderizzare immediatamente
const MDEditor = dynamic(() => import('@uiw/react-md-editor'), {
    ssr: false, // Disabilita il server-side rendering
});

const initialState: FormState = {
    message: "",
    error: "",
};

const ArticleForm = () => {

    const [state, formAction] = useFormState(confirmAction, initialState)
    const [value, setValue] = useState("Inserisci il testo");

    useEffect(() => {
        const timer = setTimeout(() => {
            document.body.style.overflow = 'auto';
        }, 1);

        return () => {
            clearTimeout(timer);
            document.body.style.overflow = '';
        };
    }, []);

    return (

        <div className="w-3/4 max-w-4xl ">
            <form action={formAction}>
                <div className="mb-4">
                    <label htmlFor="title" className="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-2">Titolo</label>
                    <input type="text" name="title" id="title" className="shadow-sm rounded-md w-full px-3 py-2 border border-gray-300 focus:outline-none focus:ring-indigo-500 focus:border-indigo-500" placeholder={"Scrivi il titolo"} required />
                </div>
                <div className="mb-4">
                    <label htmlFor="title" className="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-2">Sottotitolo</label>
                    <input type="text" name="subtitle" id="subtitle" className="shadow-sm rounded-md w-full px-3 py-2 border border-gray-300 focus:outline-none focus:ring-indigo-500 focus:border-indigo-500" placeholder={"Scrivi il sottotitolo"} required />
                </div>
                <input type="hidden" name="content" id="content" value={value} />
                <MDEditor name="content" id="content" className="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-2" value={value} onChange={setValue} />
                <div className="mb-4">
                    <input type="hidden" name="date" id="date" className="shadow-sm rounded-md w-full px-3 py-2 border border-gray-300 focus:outline-none focus:ring-indigo-500 focus:border-indigo-500" value="`now`" required />
                </div>
                <div className="mb-4">
                    <label htmlFor="tags" className="block text-sm font-medium text-gray-700">
                        Tags (devono essere separati con la virgola)
                    </label>
                    <input type="text" id="tags" name="tags" className="shadow-sm rounded-md w-full px-3 py-2 border border-gray-300" placeholder="Inserisci i tag, devono essere separati con la virgola" />
                </div>
                <div className="text-green-700 text-center">
                    {state.message}
                </div>
                <div className="text-red-700 text-center">
                    {state.error}
                </div>
                <Button type="submit" variant={"outline"} className="w-full mt-4">Conferma Articolo</Button>
                <div className="flex flex-col text-center">
                    <Link href="/my-article" className="text-primary text-sm pt-4">&#8592; Back to my-article</Link>
                </div>
            </form>
        </div>

    );
}

export default ArticleForm;