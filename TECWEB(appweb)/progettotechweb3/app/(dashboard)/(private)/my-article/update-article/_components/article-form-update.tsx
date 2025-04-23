"use client";

import "@uiw/react-md-editor/markdown-editor.css";
import "@uiw/react-markdown-preview/markdown.css";
import dynamic from "next/dynamic";
import { Button } from "@/components/ui/button";
import Link from "next/link";
import { FormState, confirmAction } from "./action";
import { useFormState } from "react-dom";
import { useEffect, useState } from "react";

const MDEditor = dynamic(() => import("@uiw/react-md-editor"), { ssr: false });

const initialState: FormState = {
    message: "",
    error: "",
};

interface Article {
    title: string;
    subtitle: string;
    content: string;
    date: string;
    tags: string;
}

interface Props {
    id_article: string;
}

const ArticleFormUpdate = ({ id_article }: Props) => {
    const [articleData, setArticleData] = useState<Article | null>(null);
    const [isLoading, setIsLoading] = useState(true);
    const [state, formAction] = useFormState(confirmAction, initialState);
    const [value, setValue] = useState("");

    useEffect(() => {

        if (typeof window !== "undefined") {
            const storedArticle = localStorage.getItem("articleData");
            if (storedArticle) {
                const parsedArticle = JSON.parse(storedArticle);
                setArticleData(parsedArticle);
                setValue(parsedArticle.content);
            }
            setIsLoading(false);
        }

    }, []);

    if (isLoading) {
        return <div>Caricamento dati...</div>;
    }

    if (!articleData) {
        return <div>Nessun articolo trovato.</div>;
    }

    return (
        <div className="w-3/4 max-w-4xl">
            <form action={formAction}>
                <div className="mb-4">
                    <label htmlFor="title" className="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-2">Titolo</label>
                    <input
                        type="text"
                        name="title"
                        id="title"
                        className="shadow-sm rounded-md w-full px-3 py-2 border border-gray-300 focus:outline-none focus:ring-indigo-500 focus:border-indigo-500"
                        value={articleData.title}
                        required
                        onChange={(select) => setArticleData(prev => prev ? { ...prev, title: select.target.value } : prev)}
                    />
                </div>
                <div className="mb-4">
                    <label htmlFor="subtitle" className="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-2">Sottotitolo</label>
                    <input
                        type="text"
                        name="subtitle"
                        id="subtitle"
                        className="shadow-sm rounded-md w-full px-3 py-2 border border-gray-300 focus:outline-none focus:ring-indigo-500 focus:border-indigo-500"
                        value={articleData.subtitle}
                        required
                        onChange={(select) => setArticleData(prev => prev ? { ...prev, subtitle: select.target.value } : prev)}
                    />
                </div>
                <MDEditor
                    className="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-2"
                    value={value}
                    onChange={setValue}
                />
                <input type="hidden" name="content" id="content" value={value} />
                <div className="mb-4">
                    <input type="hidden" name="lastdate" id="lastdate" className="shadow-sm rounded-md w-full px-3 py-2 border border-gray-300 focus:outline-none focus:ring-indigo-500 focus:border-indigo-500" value="`now`" required />
                </div>
                <div className="mb-4">
                    <label htmlFor="tags" className="block text-sm font-medium text-gray-700">Tags (devono essere separati con la virgola)</label>
                    <input
                        type="text"
                        id="tags"
                        name="tags"
                        className="shadow-sm rounded-md w-full px-3 py-2 border border-gray-300"
                        value={articleData.tags}
                        onChange={(select) => setArticleData(prev => prev ? { ...prev, tags: select.target.value } : prev)}
                    />
                </div>
                <div className="text-green-700 text-center">{state.message}</div>
                <div className="text-red-700 text-center">{state.error}</div>
                <div className="invisibile">
                    <input type="hidden" id="id_article" name="id_article" value={id_article} />
                </div>
                <Button type="submit" variant={"outline"} className="w-full mt-4">Aggiorna Articolo</Button>
                <div className="flex flex-col text-center">
                    <Link href="/my-article" className="text-primary text-sm pt-4">&#8592; Back to my-article</Link>
                </div>
            </form>
        </div>
    );
};

export default ArticleFormUpdate;