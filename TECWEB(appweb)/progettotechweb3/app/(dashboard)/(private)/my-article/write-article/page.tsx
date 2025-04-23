"use server"

import ArticleForm from "./_components/article-form";

export default async function WriteMyArticles() {

    return (
        <main className=" flex flex-col justify-start w-full mx-auto items-center text-gray-700 bg-gray-100 py-20" >
            <ArticleForm />
        </main >
    );
};