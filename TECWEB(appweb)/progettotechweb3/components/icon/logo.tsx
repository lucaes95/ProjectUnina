import Image from "next/image";
import srcLogo from '../icon/logopressportal.png'


interface SizeLogo {
    width: number;
    height: number;
}

const Logo = ({ width, height }: SizeLogo) => {

    return (
        <Image alt="Logo PressPortal" src={srcLogo} width={width} height={height} />
    );
};

export default Logo;
