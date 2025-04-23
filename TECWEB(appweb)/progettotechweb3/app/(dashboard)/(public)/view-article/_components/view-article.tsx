"use client"

import { Database } from "@/types/supabase";
import MDEditor from "@uiw/react-md-editor";

interface MyArticlesProps {
    Articles: Database["public"]["Tables"]["Articles"]["Row"][];
}

const ViewItemArticle = ({ Articles }: MyArticlesProps) => {
    return (
        <div className="w-full max-w-4xl">
            {
                Articles.map((Article) => (
                    <>
                        <div className="max-w-4xl px-10 my-4 py-6 bg-white rounded-lg " key={Article.id_user}>
                            <div className="flex justify-between items-center">
                                <span className="font-light text-gray-600">{Article.date}</span>

                            </div>
                            <div className="mt-2">
                                <h1 className="text-2xl text-gray-700 font-bold">{Article.title}</h1>
                                <h3 className="mt-2 text-gray-700 font-bold">{Article.subtitle}</h3>
                                <p id="contentArticle" className="mt-2 mb-4 text-gray-600"><MDEditor.Markdown source={Article.content} /></p>
                                <p>{Article.tags && Article.tags.length > 0 ? (Article.tags.map((tag: string, tagIndex: number) => (
                                    <a key={tagIndex} className="text-blue-600 pr-3 text-primary">{tag ? `#${tag}` : ""}</a>
                                ))) : ("")} </p>
                            </div>
                            <div className="flex justify-end items-center mt-4">
                                <h1 className="flex items-center text-gray-700 font-bold">{Article.Profiles.nome} {Article.Profiles.cognome}</h1>
                            </div>
                        </div>
                    </>
                ))
            }
        </div>
    );
};

export default ViewItemArticle;