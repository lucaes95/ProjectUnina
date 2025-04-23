export const cutText = (text: string | null, wordLimit: number): string => {
  if(text !=null){
  const words = text.split(' '); // Dividi il testo in parole
  if (words.length <= wordLimit) {
    return text; // Se il numero di parole è inferiore o uguale al limite, restituisci il testo intero
  }
  return words.slice(0, wordLimit).join(' ') + '...'; // Tronca le parole e aggiungi '...'
}
else 
  return "error text-empty"
};