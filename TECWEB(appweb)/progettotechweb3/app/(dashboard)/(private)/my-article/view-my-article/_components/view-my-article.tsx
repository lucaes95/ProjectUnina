"use client"

import { Database } from "@/types/supabase";
import { useRouter } from 'next/navigation';
import MDEditor from "@uiw/react-md-editor";

interface MyArticlesProps {
    Articles: Database["public"]["Tables"]["Articles"]["Row"][];
}

const ViewMyItemArticle = ({ Articles }: MyArticlesProps) => {

    const router = useRouter();

    const handleEditClick = (article: Database['public']['Tables']['Articles']['Row']) => {
        // Salva i dati dell'articolo nel localStorage
        localStorage.setItem('articleData', JSON.stringify(article));
        // Naviga verso la pagina di modifica
        Articles.map((Article) => (
            router.push(`/my-article/update-article/?id_article=${Article.id_article}`)));
    };

    const handleDeleteClick = (article: Database['public']['Tables']['Articles']['Row']) => {
        // Salva i dati dell'articolo nel localStorage
        localStorage.setItem('articleData', JSON.stringify(article));
        // Naviga verso la pagina di modifica
        Articles.map((Article) => (
            router.push(`/my-article/delete-article/?id_article=${Article.id_article}`)));
    };


    return (
        <div className="w-full max-w-4xl">
            {
                Articles.map((Article) => (
                    <>
                        <div className="max-w-4xl px-10 my-4 py-6 bg-white rounded-lg " key={Article.id_user}>
                            <div className="flex justify-between items-center">
                                <span className="font-light text-gray-600">{Article.date}</span>
                                {(Article.lastdate != null) && (Article.lastdate != Article.date) ? <span className="font-light text-gray-600">Ultima Modifica: {Article.lastdate}</span> : ""}
                            </div>
                            <div className="mt-2">
                                <h1 className="text-2xl text-gray-700 font-bold">{Article.title}</h1>
                                <h3 className="mt-2 text-gray-700 font-bold">{Article.subtitle}</h3>
                                <div id="contentArticle" className="mt-2 mb-4 text-gray-600"><MDEditor.Markdown source={Article.content} /></div>
                                <p>{Article.tags && Article.tags.length > 0 ? (Article.tags.map((tag: string, tagIndex: number) => (
                                    <a key={tagIndex} className="text-blue-600 pr-3 text-primary">{tag ? `#${tag}` : ""}</a>
                                ))) : ("")} </p>
                            </div>
                            <div className="mt-6 flex justify-center item-center">
                                {/* Usa handleEdit per inviare i dati */}
                                <button className="mt-2 text-black-600 hover:underline" onClick={() => handleEditClick(Article)}>Modifica Articolo </button>
                                <button className="mt-2 ml-6 text-red-600 hover:underline" onClick={() => handleDeleteClick(Article)}> Elimina Articolo</button>
                            </div>
                        </div >
                    </>
                ))
            }
        </div >
    );
};

export default ViewMyItemArticle;