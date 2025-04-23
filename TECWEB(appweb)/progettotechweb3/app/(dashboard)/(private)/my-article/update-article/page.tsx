"use server"

import ArticleFormUpdate from "./_components/article-form-update";

interface Props {
    searchParams: { [key: string]: string | string[] | undefined };
}

export default async function WriteMyArticles({ searchParams }: Props) {

    const articleId = String(searchParams.id_article ?? 0);

    return (

        <main className=" flex flex-col justify-start w-full mx-auto items-center text-gray-700 bg-gray-100 py-20" >
            <ArticleFormUpdate id_article={articleId} />
        </main >
    );
};