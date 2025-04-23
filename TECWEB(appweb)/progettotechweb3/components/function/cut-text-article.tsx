import React from 'react';
import { cutText } from "../../utils/cut-text";
import MDEditor from '@uiw/react-md-editor';

interface CutArticleProps {
  text: string | null;
  maxLength: number;
}

const CutArticle: React.FC<CutArticleProps> = ({ text, maxLength }) => {
  const cutTextArticle = cutText(text, maxLength);

  return <MDEditor.Markdown source={cutTextArticle} />;
};

export default CutArticle;