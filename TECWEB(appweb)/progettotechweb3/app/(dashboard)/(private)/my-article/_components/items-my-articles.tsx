"use client"

import CutArticle from "@/components/function/cut-text-article";
import { Database } from "@/types/supabase";
import Link from "next/link";

interface MyArticlesProps {
    Articles: Database["public"]["Tables"]["Articles"]["Row"][];
}

const ItemMyArticle = ({ Articles }: MyArticlesProps) => {
    return (

        <div className="w-full max-w-4xl">
            {
                Articles.map((Article) => (
                    <div className="max-w-4xl px-10 my-4 py-6 bg-white rounded-lg" key={Article.id_user}>
                        <div className="flex justify-between items-center">
                            <span className="font-light text-gray-600">{Article.date}</span>
                            {(Article.lastdate != null) && (Article.lastdate != Article.date) ? <span className="font-light text-gray-600">Ultima Modifica: {Article.lastdate}</span> : ""}
                        </div>
                        <div className="mt-2">
                            <Link className="text-2xl text-gray-700 font-bold hover:text-gray-600" href={`/my-article/view-my-article/?id_article=${Article.id_article}`}>{Article.title}</Link>
                            <div id="contentArticle" className="mt-2 mb-2 text-gray-600"><CutArticle text={Article.content} maxLength={50} /></div>
                            <p className="mt-2">{Article.tags && Article.tags.length > 0 ? (Article.tags.map((tag: string, tagIndex: number) => (
                                <Link key={tagIndex} className="mt-2 text-blue-600 pr-3 hover:underline text-primary" href={`/?tag=${tag}`}>{tag ? `#${tag}` : ""}</Link>
                            ))) : ("")} </p>
                        </div>
                    </div>
                ))
            }
        </div>

    );
};

export default ItemMyArticle;