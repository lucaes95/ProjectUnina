"use client"

import { useSearchParams } from 'next/navigation';

export default function UseArticleId() {
  const searchParams = useSearchParams();

  // Estrai il parametro id_article
  const id_article = searchParams.get('id_article'); // Ritorna string o null

  // Verifica se l'ID è disponibile
  return { id_article };
}