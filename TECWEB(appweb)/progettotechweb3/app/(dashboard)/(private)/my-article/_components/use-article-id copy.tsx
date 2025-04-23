interface Props {
    searchParams: { [key: string]: string | string[] | undefined };
}

const ArticleId = ({ searchParams }: Props) => {
    const idarticle = searchParams.id_article ?? 0;

    console.log(idarticle);

    return idarticle;
}

const UseArticleId = async () => {

    console.log(ArticleId);


    return ArticleId;
}

export default UseArticleId;


