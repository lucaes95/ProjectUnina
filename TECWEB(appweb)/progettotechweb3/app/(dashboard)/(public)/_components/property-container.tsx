"use client"
import PaginationContainer from "@/components/layout/pagination-container";

interface MyProps {
    totalPages: number;
    currentPages: number;
};

const PropertyContainer = ({ totalPages, currentPages }: MyProps) => {
    return (

        <div>
            <PaginationContainer route="" currentPages={currentPages} totalPages={totalPages} />
        </div>
    )
}

export default PropertyContainer;