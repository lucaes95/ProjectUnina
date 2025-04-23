"use client"
import {
    Pagination,
    PaginationContent,
    PaginationItem,
    PaginationLink,
    PaginationNext,
    PaginationPrevious,
} from "@/components/ui/pagination"

interface Props {
    totalPages: number;
    currentPages: number;
    route?: string;
}

const PaginationContainer = ({ route, totalPages, currentPages }: Props) => {

    return (
        <Pagination>
            <PaginationContent>
                <PaginationItem>
                    {totalPages >= currentPages && currentPages > 0 ? (<PaginationPrevious href={`${route}?pagenum=${currentPages - 1}`} />) : <></>}
                </PaginationItem>
                <PaginationItem>
                    {totalPages >= currentPages && currentPages > 0 ? (<PaginationLink href={`${route}?pagenum=${currentPages - 1}`}>{currentPages - 1}</PaginationLink>) : <></>}
                    <PaginationLink isActive>{currentPages}</PaginationLink>
                    {currentPages < totalPages - 1 ? (<PaginationLink href={`${route}?pagenum=${currentPages + 1}`}>{currentPages + 1}</PaginationLink>) : <></>}
                    {currentPages < totalPages - 2 ? (<PaginationLink href={`${route}?pagenum=${totalPages - 1}`}> . . {totalPages - 1}</PaginationLink>) : <></>}
                </PaginationItem>
                <PaginationItem>
                    {totalPages - 1 > currentPages ? (<PaginationNext href={`${route}?pagenum=${currentPages + 1}`} />) : <></>}
                </PaginationItem>
            </PaginationContent>
        </Pagination>
    );
}

export default PaginationContainer;