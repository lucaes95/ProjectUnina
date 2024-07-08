
#include "test.hpp"

/* ************************************************************************** */

#include <iostream>

using namespace std;

/* ************************************************************************ */

// Random generate dat function

default_random_engine gen(random_device{}());

const int GenerateInt()
{
    uniform_int_distribution<int> dist(-222222, 222222);
    return dist(gen);
}

const uint GenerateUint()
{
    uniform_int_distribution<uint> distuint(1, 9999);
    return distuint(gen);
}

const uint GenerateIntRange(const uint &min, const uint &max)
{
    uniform_int_distribution<int> distrange(min, max);
    return distrange(gen);
}

const uint GenerateUintRange(const uint &max)
{
    uniform_int_distribution<int> distrange(1, max);
    return distrange(gen);
}

const char GenerateChar()
{
    uniform_int_distribution<int> randomchar(97, 122);
    return randomchar(gen);
}

const double GenerateDouble()
{
    return GenerateInt() * 0.01;
}

const string GenerateWord(const uint &lenghtwordmax)
{
    string word = {};

    for (uint index = 0; index < GenerateUintRange(lenghtwordmax); index++)
        word += GenerateChar();

    return word;
}

/* ************************************************************************** */

void mytest()
{
    uint numtest = 0;
    uint toterr = 0;

    // Check EXCERCISE3

    cout << endl;
    cout << " TEST ESERCIZIO3: " << endl
         << endl;

    CheckHashTableClsAdrConstructors<int>(numtest, toterr);
    CheckHashTableOpnAdrConstructors<int>(numtest, toterr);
    CheckHashTableClsAdrConstructors<double>(numtest, toterr);
    CheckHashTableOpnAdrConstructors<double>(numtest, toterr);

    CheckHashTableClsAdrAssigment<int>(numtest, toterr);
    CheckHashTableOpnAdrAssigment<int>(numtest, toterr);
    CheckHashTableClsAdrAssigment<double>(numtest, toterr);
    CheckHashTableOpnAdrAssigment<double>(numtest, toterr);

    CheckHashTableClsAdrComparison<int>(numtest, toterr);
    CheckHashTableOpnAdrComparison<int>(numtest, toterr);
    CheckHashTableClsAdrComparison<double>(numtest, toterr);
    CheckHashTableOpnAdrComparison<double>(numtest, toterr);

    CheckHashTableClsAdrContainerFunctions<int>(numtest, toterr);
    CheckHashTableOpnAdrContainerFunctions<int>(numtest, toterr);
    CheckHashTableClsAdrContainerFunctions<double>(numtest, toterr);
    CheckHashTableOpnAdrContainerFunctions<double>(numtest, toterr);

    CheckHashTableClsAdrDictionaryFunctions<int>(numtest, toterr);
    CheckHashTableOpnAdrDictionaryFunctions<int>(numtest, toterr);
    CheckHashTableClsAdrDictionaryFunctions<double>(numtest, toterr);
    CheckHashTableOpnAdrDictionaryFunctions<double>(numtest, toterr);

    CheckHashTableClsAdrDictionaryFunctionsString(numtest, toterr);
    CheckHashTableOpnAdrDictionaryFunctionsString(numtest, toterr);

    // Check EXCERCISE2

    cout << endl;
    cout << " TEST ESERCIZIO2: " << endl
         << endl;

    CheckBinaryTreeCompare<int>(numtest, toterr);
    CheckBinaryTreeCompare<double>(numtest, toterr);
    CheckBinaryTreeCompare<char>(numtest, toterr);

    CheckBinaryTreeLnkAssignment<int>(numtest, toterr);
    CheckBinaryTreeLnkConstructors<int>(numtest, toterr);
    CheckBinaryTreeLnkFunctionBase<int>(numtest, toterr);
    CheckBinaryTreeLnkNodeLnkFunction<int>(numtest, toterr);
    CheckBinaryTreeLnkAssignment<double>(numtest, toterr);
    CheckBinaryTreeLnkConstructors<double>(numtest, toterr);
    CheckBinaryTreeLnkFunctionBase<double>(numtest, toterr);
    CheckBinaryTreeLnkNodeLnkFunction<double>(numtest, toterr);
    CheckBinaryTreeLnkAssignment<char>(numtest, toterr);
    CheckBinaryTreeLnkConstructors<char>(numtest, toterr);
    CheckBinaryTreeLnkFunctionBase<char>(numtest, toterr);
    CheckBinaryTreeLnkNodeLnkFunction<char>(numtest, toterr);

    CheckBinaryTreeVecFunctionBase<int>(numtest, toterr);
    CheckBinaryTreeVecConstructors<int>(numtest, toterr);
    CheckBinaryTreeVecFunctionTraverse<int>(numtest, toterr);
    CheckBinaryTreeVecNodeVecFunction<int>(numtest, toterr);
    CheckBinaryTreeVecAssignment<int>(numtest, toterr);
    CheckBinaryTreeVecFunctionMap<int>(numtest, toterr);
    CheckBinaryTreeVecFunctionFold<int>(numtest, toterr);
    CheckBinaryTreeVecFunctionBase<double>(numtest, toterr);
    CheckBinaryTreeVecConstructors<double>(numtest, toterr);
    CheckBinaryTreeVecNodeVecFunction<double>(numtest, toterr);
    CheckBinaryTreeVecAssignment<double>(numtest, toterr);
    CheckBinaryTreeVecFunctionTraverse<double>(numtest, toterr);
    CheckBinaryTreeVecFunctionMap<double>(numtest, toterr);
    CheckBinaryTreeVecFunctionFold<double>(numtest, toterr);
    CheckBinaryTreeVecFunctionBase<char>(numtest, toterr);
    CheckBinaryTreeVecConstructors<char>(numtest, toterr);
    CheckBinaryTreeVecNodeVecFunction<char>(numtest, toterr);
    CheckBinaryTreeVecAssignment<char>(numtest, toterr);
    CheckBinaryTreeVecFunctionTraverse<char>(numtest, toterr);
    CheckBinaryTreeVecFunctionMap<char>(numtest, toterr);
    CheckBinaryTreeVecFunctionFold<char>(numtest, toterr);

    CheckBSTConstructors<int>(numtest, toterr);
    CheckBSTFunctionBase<int>(numtest, toterr);
    CheckBSTMemberFunction<int>(numtest, toterr);
    CheckBSTMemberFunctionDictionary<int>(numtest, toterr);
    CheckBSTFunctionMap<int>(numtest, toterr);
    CheckBSTFunctionFold<int>(numtest, toterr);
    CheckBSTAssignment<int>(numtest, toterr);
    CheckBSTFunctionTraverse<int>(numtest, toterr);
    CheckBSTConstructors<double>(numtest, toterr);
    CheckBSTFunctionBase<double>(numtest, toterr);
    CheckBSTMemberFunction<double>(numtest, toterr);
    CheckBSTMemberFunctionDictionary<double>(numtest, toterr);
    CheckBSTFunctionTraverse<double>(numtest, toterr);
    CheckBSTFunctionMap<double>(numtest, toterr);
    CheckBSTFunctionFold<double>(numtest, toterr);
    CheckBSTAssignment<double>(numtest, toterr);
    CheckBSTConstructors<char>(numtest, toterr);
    CheckBSTMemberFunction<char>(numtest, toterr);
    CheckBSTFunctionBase<char>(numtest, toterr);
    CheckBSTMemberFunctionDictionary<char>(numtest, toterr);
    CheckBSTFunctionTraverse<char>(numtest, toterr);
    CheckBSTFunctionMap<char>(numtest, toterr);
    CheckBSTFunctionFold<char>(numtest, toterr);
    CheckBSTAssignment<char>(numtest, toterr);

    CheckBTIterator<int>(numtest, toterr);
    CheckBTIterator<double>(numtest, toterr);
    CheckBTIterator<char>(numtest, toterr);

    CheckBTMutableIterator<int>(numtest, toterr);
    CheckBTMutableIterator<double>(numtest, toterr);
    CheckBTMutableIterator<char>(numtest, toterr);

    CheckBTIteratorAssignment<int>(numtest, toterr);
    CheckBTIteratorAssignment<double>(numtest, toterr);
    CheckBTIteratorAssignment<char>(numtest, toterr);

    CheckBTIteratorConstructors<int>(numtest, toterr);
    CheckBTIteratorConstructors<double>(numtest, toterr);
    CheckBTIteratorConstructors<char>(numtest, toterr);

    // Check EXCERCISE1

    cout << endl;
    cout << " TEST ESERCIZIO1: " << endl
         << endl;

    CheckExistsLinearContainer<int>(toterr, numtest);
    CheckExistsLinearContainerString(toterr, numtest);
    CheckExistsLinearContainer<double>(toterr, numtest);
    CheckExistsLinearContainer<char>(toterr, numtest);

    TestCheckFuctionContainer<int>(toterr, numtest);
    TestCheckMemberFunctionLinearContainer<int>(toterr, numtest);
    TestCheckMemberFunctionDictionary<int>(toterr, numtest);
    TestCheckMemberFunctionStack<int>(toterr, numtest);
    TestCheckMemberFunctionQueue<int>(toterr, numtest);

    TestCheckFuctionContainer<char>(toterr, numtest);
    TestCheckMemberFunctionLinearContainer<char>(toterr, numtest);
    TestCheckMemberFunctionDictionary<char>(toterr, numtest);
    TestCheckMemberFunctionStack<char>(toterr, numtest);
    TestCheckMemberFunctionQueue<char>(toterr, numtest);

    TestCheckFuctionContainer<double>(toterr, numtest);
    TestCheckMemberFunctionLinearContainer<double>(toterr, numtest);
    TestCheckMemberFunctionDictionary<double>(toterr, numtest);
    TestCheckMemberFunctionStack<double>(toterr, numtest);
    TestCheckMemberFunctionQueue<double>(toterr, numtest);

    TestCheckFuctionContainer<string>(toterr, numtest);
    TestCheckMemberFunctionQueueString(toterr, numtest);
}

template <typename Data>
void CheckHashTableClsAdrConstructors(uint &numtest, uint &toterr)
{
    CheckHashTableClsAdrConstructorSize<Data>(numtest, toterr);
    CheckHashTableClsAdrConstructorTraversable<Data>(numtest, toterr);
    CheckHashTableClsAdrConstructorTraversableSize<Data>(numtest, toterr);
    CheckHashTableClsAdrConstructorMappable<Data>(numtest, toterr);
    CheckHashTableClsAdrConstructorMappableSize<Data>(numtest, toterr);
    CheckHashTableClsAdrConstructorCopy<Data>(numtest, toterr);
    CheckHashTableClsAdrConstructorMove<Data>(numtest, toterr);
}

template <typename Data>
void CheckHashTableOpnAdrConstructors(uint &numtest, uint &toterr)
{
    CheckHashTableOpnAdrConstructorSize<Data>(numtest, toterr);
    CheckHashTableOpnAdrConstructorTraversable<Data>(numtest, toterr);
    CheckHashTableOpnAdrConstructorTraversableSize<Data>(numtest, toterr);
    CheckHashTableOpnAdrConstructorMappable<Data>(numtest, toterr);
    CheckHashTableOpnAdrConstructorMappableSize<Data>(numtest, toterr);
    CheckHashTableOpnAdrConstructorCopy<Data>(numtest, toterr);
    CheckHashTableOpnAdrConstructorMove<Data>(numtest, toterr);
}

/* ************************************************************************** */

template <typename Data>
void CheckHashTableClsAdrConstructorSize(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        HashTableClsAdr<Data> htc1(63);
        HashTableClsAdr<Data> htc2(65);
        HashTableClsAdr<Data> htc3(0);

        chk &= (htc1.Size() == htc2.Size());
        chk &= (htc1.Size() == htc3.Size());

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Constructor HashTableCloseAddress Size " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckHashTableClsAdrConstructorTraversable(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;
        List<Data> lst;

        PopularVectorData(vec1, 100);

        HashTableClsAdr<Data> htc1(vec1);

        HashTableClsAdr<Data> htc2(lst);

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= htc1.Exists(vec1[index]);
        }

        chk &= htc2.Size() == 0;

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Constructor HashTableCloseAddress Traversable " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckHashTableClsAdrConstructorTraversableSize(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;
        List<Data> lst;

        PopularVectorData(vec1, 100);

        HashTableClsAdr<Data> htc1(100, vec1);

        HashTableClsAdr<Data> htc2(512, lst);

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= htc1.Exists(vec1[index]);
        }

        chk &= htc2.Size() == 0;

        HashTableClsAdr<Data> htc3(200, vec1);

        chk &= (htc3.Size() == htc1.Size());

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Constructor HashTableCloseAddress Traversable Size " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckHashTableClsAdrConstructorMappable(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;

        List<Data> lst;

        PopularVectorData(vec1, 100);

        HashTableClsAdr<Data> htc1(move(vec1));

        HashTableClsAdr<Data> htc2(move(lst));

        chk &= htc2.Size() == 0;

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Constructor HashTableCloseAddress Mappable " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckHashTableClsAdrConstructorMappableSize(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;

        List<Data> lst;

        PopularVectorData(vec1, 100);

        Vector<Data> vec2(vec1);
        Vector<Data> vec3(vec1);

        HashTableClsAdr<Data> htc1(100, move(vec2));

        HashTableClsAdr<Data> htc2(512, move(lst));

        chk &= htc2.Size() == 0;

        HashTableClsAdr<Data> htc3(200, move(vec3));

        chk &= (htc3.Size() == htc1.Size());

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Constructor HashTableCloseAddress Mappable Size " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckHashTableClsAdrConstructorCopy(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;

        PopularVectorData(vec1, 100);

        HashTableClsAdr<Data> htc1(vec1);

        HashTableClsAdr<Data> htc2(htc1);

        chk &= htc1.Size() == htc2.Size();

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= htc2.Exists(vec1[index]);
        }

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Constructor HashTableCloseAddress Copy " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckHashTableClsAdrConstructorMove(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;

        PopularVectorData(vec1, 100);

        HashTableClsAdr<Data> htc1(vec1);

        HashTableClsAdr<Data> htc2(move(htc1));

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= htc2.Exists(vec1[index]);
        }

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Constructor HashTableCloseAddress Move " << " TOT Error: " << toterr << endl;
}

/* **************************************************************************** */

template <typename Data>
void CheckHashTableOpnAdrConstructorSize(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        HashTableOpnAdr<Data> hto1(63);
        HashTableOpnAdr<Data> hto2(65);
        HashTableOpnAdr<Data> hto3(0);

        chk &= (hto1.Size() == hto2.Size());
        chk &= (hto1.Size() == hto3.Size());

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Constructor HashTableOpenAddress Size " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckHashTableOpnAdrConstructorTraversable(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;
        List<Data> lst;

        PopularVectorData(vec1, 100);

        HashTableOpnAdr<Data> hto1(vec1);

        HashTableOpnAdr<Data> hto2(lst);

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= hto1.Exists(vec1[index]);
        }

        chk &= hto2.Size() == 0;

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Constructor HashTableOpenAddress Traversable " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckHashTableOpnAdrConstructorTraversableSize(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;
        List<Data> lst;

        PopularVectorData(vec1, 100);

        HashTableOpnAdr<Data> hto1(100, vec1);

        HashTableOpnAdr<Data> hto2(512, lst);

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= hto1.Exists(vec1[index]);
        }

        chk &= hto2.Size() == 0;

        HashTableOpnAdr<Data> hto3(200, vec1);

        chk &= (hto3.Size() == hto1.Size());

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Constructor HashTableOpenAddress Traversable Size " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckHashTableOpnAdrConstructorMappable(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;

        List<Data> lst;

        PopularVectorData(vec1, 100);

        HashTableOpnAdr<Data> hto1(move(vec1));

        HashTableOpnAdr<Data> hto2(move(lst));

        chk &= hto2.Size() == 0;

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Constructor HashTableOpenAddress Mappable " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckHashTableOpnAdrConstructorMappableSize(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;
        List<Data> lst;

        PopularVectorData(vec1, 100);

        HashTableOpnAdr<Data> hto1(100, move(vec1));

        HashTableOpnAdr<Data> hto2(512, move(lst));

        chk &= hto2.Size() == 0;

        HashTableOpnAdr<Data> hto3(200, move(vec1));

        chk &= (hto3.Size() == hto1.Size());

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Constructor HashTableOpenAddress Mappable Size " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckHashTableOpnAdrConstructorCopy(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;

        PopularVectorData(vec1, 100);

        HashTableOpnAdr<Data> hto1(vec1);

        HashTableOpnAdr<Data> hto2(hto1);

        chk &= hto1.Size() == hto2.Size();

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= hto2.Exists(vec1[index]);
        }

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Constructor HashTableOpenAddress Copy " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckHashTableOpnAdrConstructorMove(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;

        PopularVectorData(vec1, 100);

        HashTableOpnAdr<Data> hto1(vec1);

        HashTableOpnAdr<Data> hto2(move(hto1));

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= hto2.Exists(vec1[index]);
        }

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Constructor HashTableOpenAddress Move " << " TOT Error: " << toterr << endl;
}

/* **************************************************************************** */

template <typename Data>
void CheckHashTableClsAdrAssigment(uint &numtest, uint &toterr)
{
    CheckHashTableClsAdrAssigmentCopy<Data>(numtest, toterr);
    CheckHashTableClsAdrAssigmentMove<Data>(numtest, toterr);
}

template <typename Data>
void CheckHashTableOpnAdrAssigment(uint &numtest, uint &toterr)
{
    CheckHashTableOpnAdrAssigmentCopy<Data>(numtest, toterr);
    CheckHashTableOpnAdrAssigmentMove<Data>(numtest, toterr);
}

/* **************************************************************************** */

template <typename Data>
void CheckHashTableClsAdrAssigmentCopy(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;

        PopularVectorData(vec1, 100);

        HashTableClsAdr<Data> htc1(vec1);

        HashTableClsAdr<Data> htc2;

        htc2 = htc1;

        chk &= htc1.Size() == htc2.Size();

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= htc2.Exists(vec1[index]);
        }

        HashTableClsAdr<Data> htc3(0);

        htc2 = htc3;

        chk &= htc1.Size() != htc2.Size();

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Assignment HashTableCloseAddress Copy " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckHashTableClsAdrAssigmentMove(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;

        PopularVectorData(vec1, 100);

        HashTableClsAdr<Data> htc1(vec1);

        HashTableClsAdr<Data> htc2;

        htc2 = move(htc1);

        chk &= htc1.Size() != htc2.Size();

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= htc2.Exists(vec1[index]);
        }

        HashTableClsAdr<Data> htc3(0);

        htc2 = move(htc3);

        chk &= htc1.Size() == htc2.Size();

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Assignment HashTableCloseAddress Move " << " TOT Error: " << toterr << endl;
}

/* **************************************************************************** */

template <typename Data>
void CheckHashTableOpnAdrAssigmentCopy(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;

        PopularVectorData(vec1, 100);

        HashTableOpnAdr<Data> hto1(vec1);

        HashTableOpnAdr<Data> hto2;

        hto2 = hto1;

        chk &= hto1.Size() == hto2.Size();

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= hto2.Exists(vec1[index]);
        }

        HashTableOpnAdr<Data> hto3(0);

        hto2 = hto3;

        chk &= hto1.Size() != hto2.Size();

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Assignment HashTableOpenAddress Copy " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckHashTableOpnAdrAssigmentMove(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;

        PopularVectorData(vec1, 100);

        HashTableOpnAdr<Data> hto1(vec1);

        HashTableOpnAdr<Data> hto2;

        hto2 = move(hto1);

        chk &= hto1.Size() != hto2.Size();

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= hto2.Exists(vec1[index]);
        }

        HashTableOpnAdr<Data> hto3(0);

        hto2 = move(hto3);

        chk &= hto1.Size() == hto2.Size();

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Assignment HashTableOpenAddress Move " << " TOT Error: " << toterr << endl;
}

/* **************************************************************************** */

template <typename Data>
void CheckHashTableClsAdrComparison(uint &numtest, uint &toterr)
{
    CheckHashTableClsAdrEquals<Data>(numtest, toterr);
    CheckHashTableClsAdrNotEquals<Data>(numtest, toterr);
}

template <typename Data>
void CheckHashTableOpnAdrComparison(uint &numtest, uint &toterr)
{
    CheckHashTableOpnAdrEquals<Data>(numtest, toterr);
    CheckHashTableOpnAdrNotEquals<Data>(numtest, toterr);
}

/* **************************************************************************** */

template <typename Data>
void CheckHashTableClsAdrEquals(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;

        PopularVectorData(vec1, 100);

        Vector<Data> vec2(vec1);

        HashTableClsAdr<Data> htc1(vec1);
        HashTableClsAdr<Data> htc2(vec2);

        chk &= htc1 == htc2;

        htc1.Clear();
        htc2.Clear();

        chk &= htc1 == htc2;

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Compare HashTableCloseAddress Equals " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckHashTableClsAdrNotEquals(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;

        PopularVectorData(vec1, 100);

        HashTableClsAdr<Data> htc1(vec1);

        ++vec1.Front();
        --vec1.Back();

        HashTableClsAdr<Data> htc2(vec1);

        chk &= htc1 != htc2;

        htc1.Clear();

        chk &= htc1 != htc2;

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Compare HashTableCloseAddress Not Equals " << " TOT Error: " << toterr << endl;
}

/* **************************************************************************** */

template <typename Data>
void CheckHashTableOpnAdrEquals(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;

        PopularVectorData(vec1, 100);

        Vector<Data> vec2(vec1);

        HashTableOpnAdr<Data> hto1(vec1);
        HashTableOpnAdr<Data> hto2(vec2);

        chk &= hto1 == hto2;

        hto1.Clear();
        hto2.Clear();

        chk &= hto1 == hto2;

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Compare HashTableOpenAddress Equals " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckHashTableOpnAdrNotEquals(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;

        PopularVectorData(vec1, 100);

        HashTableOpnAdr<Data> hto1(vec1);

        ++vec1.Front();
        --vec1.Back();

        HashTableOpnAdr<Data> hto2(vec1);

        chk &= hto1 != hto2;

        hto1.Clear();

        chk &= hto1 != hto2;

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Compare HashTableOpenAddress Not Equals " << " TOT Error: " << toterr << endl;
}

/* **************************************************************************** */

template <typename Data>
void CheckHashTableClsAdrContainerFunctions(uint &numtest, uint &toterr)
{
    CheckHashTableClsAdrExists<Data>(numtest, toterr);
    CheckHashTableClsAdrClear<Data>(numtest, toterr);
    CheckHashTableClsAdrResize<Data>(numtest, toterr);
}

template <typename Data>
void CheckHashTableOpnAdrContainerFunctions(uint &numtest, uint &toterr)
{
    CheckHashTableOpnAdrExists<Data>(numtest, toterr);
    CheckHashTableOpnAdrClear<Data>(numtest, toterr);
    CheckHashTableOpnAdrResize<Data>(numtest, toterr);
}

/* **************************************************************************** */
template <typename Data>
void CheckHashTableClsAdrExists(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;

        PopularVectorData(vec1, 100);

        HashTableClsAdr<Data> htc1(vec1);

        Data num = 99999;

        chk &= !htc1.Exists(num);

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= htc1.Exists(vec1[index]);
        }

        htc1.Insert(num);

        chk &= htc1.Exists(num);

        htc1.Clear();

        chk &= !htc1.Exists(num);

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Container Functions HashTableCloseAddress Exists " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckHashTableClsAdrClear(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;

        PopularVectorData(vec1, 100);

        HashTableClsAdr<Data> htc1(vec1);

        htc1.Clear();

        chk &= htc1.Size() == 0;

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Container Functions HashTableCloseAddress Clear " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckHashTableClsAdrResize(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;

        PopularVectorData(vec1, 100);

        HashTableClsAdr<Data> htc1(vec1);

        for (uint index = 0; index < htc1.Size(); index++)
        {
            chk &= htc1.Exists(vec1[index]);
        }

        htc1.Resize(200);

        for (uint index = 0; index < htc1.Size(); index++)
        {
            chk &= htc1.Exists(vec1[index]);
        }

        htc1.Resize(2000);

        for (uint index = 0; index < htc1.Size(); index++)
        {
            chk &= htc1.Exists(vec1[index]);
        }

        htc1.Resize(50);

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= htc1.Exists(vec1[index]);
        }

        htc1.Resize(0);

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= !htc1.Exists(vec1[index]);
        }

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Container Functions HashTableCloseAddress Resize " << " TOT Error: " << toterr << endl;
}

/* **************************************************************************** */

template <typename Data>
void CheckHashTableOpnAdrExists(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;

        PopularVectorData(vec1, 100);

        HashTableOpnAdr<Data> hto1(vec1);

        Data num = 99999;

        chk &= !hto1.Exists(num);

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= hto1.Exists(vec1[index]);
        }

        hto1.Insert(num);

        chk &= hto1.Exists(num);

        hto1.Clear();

        chk &= !hto1.Exists(num);

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Container Functions HashTableOpenAddress Exists " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckHashTableOpnAdrClear(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;

        PopularVectorData(vec1, 100);

        HashTableOpnAdr<Data> hto1(vec1);

        hto1.Clear();

        chk &= hto1.Size() == 0;

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Container Functions HashTableOpenAddress Clear " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckHashTableOpnAdrResize(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;

        PopularVectorData(vec1, 100);

        HashTableOpnAdr<Data> hto1(vec1);

        for (uint index = 0; index < hto1.Size(); index++)
        {
            chk &= hto1.Exists(vec1[index]);
        }

        hto1.Resize(200);

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= hto1.Exists(vec1[index]);
        }

        hto1.Resize(2000);

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= hto1.Exists(vec1[index]);
        }

        hto1.Resize(50);

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= hto1.Exists(vec1[index]);
        }

        hto1.Resize(0);

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= !hto1.Exists(vec1[index]);
        }

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Container Functions HashTableOpenAddress Resize " << " TOT Error: " << toterr << endl;
}

/* **************************************************************************** */

template <typename Data>
void CheckHashTableClsAdrDictionaryFunctions(uint &numtest, uint &toterr)
{
    CheckHashTableClsAdrInsertCopy<Data>(numtest, toterr);
    CheckHashTableClsAdrInsertMove<Data>(numtest, toterr);
    CheckHashTableClsAdrRemove<Data>(numtest, toterr);
}

template <typename Data>
void CheckHashTableOpnAdrDictionaryFunctions(uint &numtest, uint &toterr)
{
    CheckHashTableOpnAdrInsertCopy<Data>(numtest, toterr);
    CheckHashTableOpnAdrInsertMove<Data>(numtest, toterr);
    CheckHashTableOpnAdrRemove<Data>(numtest, toterr);
}

void CheckHashTableClsAdrDictionaryFunctionsString(uint &numtest, uint &toterr)
{
    CheckHashTableClsAdrInsertCopyString(numtest, toterr);
    CheckHashTableClsAdrInsertMoveString(numtest, toterr);
    CheckHashTableClsAdrRemoveString(numtest, toterr);
}

void CheckHashTableOpnAdrDictionaryFunctionsString(uint &numtest, uint &toterr)
{
    CheckHashTableOpnAdrInsertCopyString(numtest, toterr);
    CheckHashTableOpnAdrInsertMoveString(numtest, toterr);
    CheckHashTableOpnAdrRemoveString(numtest, toterr);
}

/* **************************************************************************** */

template <typename Data>
void CheckHashTableClsAdrInsertCopy(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;

        PopularVectorData(vec1, 100);

        HashTableClsAdr<Data> htc1;

        vec1.Traverse([&htc1](const Data dat)
                      { htc1.Insert(dat); });

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= htc1.Exists(vec1[index]);
        }

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Dictionary Functions HashTableCloseAddress Insert Copy " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckHashTableClsAdrInsertMove(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;

        PopularVectorData(vec1, 100);

        Vector<Data> vec2(vec1);

        HashTableClsAdr<Data> htc1;

        vec1.Map([&htc1](const Data dat)
                 { htc1.Insert(move(dat)); });

        for (uint index = 0; index < vec2.Size(); index++)
        {
            chk &= htc1.Exists(vec2[index]);
        }

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Dictionary Functions HashTableCloseAddress Insert Move " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckHashTableClsAdrRemove(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;

        PopularVectorData(vec1, 100);

        HashTableClsAdr<Data> htc1;

        vec1.Traverse([&htc1](const Data dat)
                      { htc1.Insert(dat); });

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= htc1.Exists(vec1[index]);
        }

        for (uint index = 0; index < vec1.Size(); index++)
        {
            htc1.Remove(vec1[index]);
        }

        chk &= !htc1.Remove(23);
        chk &= htc1.Size() == 0;

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= !htc1.Exists(vec1[index]);
        }

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Dictionary Functions HashTableCloseAddress Remove String " << " TOT Error: " << toterr << endl;
}

/* **************************************************************************** */

template <typename Data>
void CheckHashTableOpnAdrInsertCopy(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;

        PopularVectorData(vec1, 100);

        HashTableOpnAdr<Data> hto1;

        vec1.Traverse([&hto1](const Data dat)
                      { hto1.Insert(dat); });

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= hto1.Exists(vec1[index]);
        }

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Dictionary Functions HashTableOpenAddress Insert Copy " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckHashTableOpnAdrInsertMove(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;

        PopularVectorData(vec1, 100);

        HashTableOpnAdr<Data> hto1;

        vec1.Traverse([&hto1](const Data dat)
                      { hto1.Insert(move(dat)); });

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= hto1.Exists(vec1[index]);
        }

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Dictionary Functions HashTableOpenAddress Insert Move " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckHashTableOpnAdrRemove(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<Data> vec1;

        PopularVectorData(vec1, 100);

        HashTableClsAdr<Data> htc1;

        vec1.Traverse([&htc1](const Data dat)
                      { htc1.Insert(dat); });

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= htc1.Exists(vec1[index]);
        }

        for (uint index = 0; index < vec1.Size(); index++)
        {
            htc1.Remove(vec1[index]);
        }

        chk &= !htc1.Remove(23);
        chk &= htc1.Size() == 0;

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= !htc1.Exists(vec1[index]);
        }

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Dictionary Functions HashTableOpenAddress Remove " << " TOT Error: " << toterr << endl;
}

/* **************************************************************************** */

void CheckHashTableClsAdrInsertCopyString(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<string> vec1;

        PopularVectorString(vec1, 100);

        HashTableClsAdr<string> htc1;

        vec1.Traverse([&htc1](const string dat)
                      { htc1.Insert(dat); });

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= htc1.Exists(vec1[index]);
        }

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Dictionary Functions HashTableCloseAddress Insert Copy String" << " TOT Error: " << toterr << endl;
}

void CheckHashTableClsAdrInsertMoveString(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<string> vec1;

        PopularVectorString(vec1, 100);

        Vector<string> vec2(vec1);

        HashTableClsAdr<string> htc1;

        vec1.Map([&htc1](const string dat)
                 { htc1.Insert(move(dat)); });

        for (uint index = 0; index < vec2.Size(); index++)
        {
            chk &= htc1.Exists(vec2[index]);
        }

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Dictionary Functions HashTableCloseAddress Insert Move String" << " TOT Error: " << toterr << endl;
}

void CheckHashTableClsAdrRemoveString(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<string> vec1;

        PopularVectorString(vec1, 100);

        HashTableClsAdr<string> htc1;

        vec1.Traverse([&htc1](const string dat)
                      { htc1.Insert(dat); });

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= htc1.Exists(vec1[index]);
        }

        for (uint index = 0; index < vec1.Size(); index++)
        {
            htc1.Remove(vec1[index]);
        }

        chk &= !htc1.Remove("abcdef");
        chk &= htc1.Size() == 0;

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= !htc1.Exists(vec1[index]);
        }

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Dictionary Functions HashTableCloseAddress Remove " << " TOT Error: " << toterr << endl;
}

/* **************************************************************************** */

void CheckHashTableOpnAdrInsertCopyString(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<string> vec1;

        PopularVectorString(vec1, 100);

        HashTableOpnAdr<string> hto1;

        vec1.Traverse([&hto1](const string dat)
                      { hto1.Insert(dat); });

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= hto1.Exists(vec1[index]);
        }

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Dictionary Functions HashTableOpenAddress Insert Copy String " << " TOT Error: " << toterr << endl;
}

void CheckHashTableOpnAdrInsertMoveString(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<string> vec1;

        PopularVectorString(vec1, 100);

        HashTableOpnAdr<string> hto1;

        vec1.Traverse([&hto1](const string dat)
                      { hto1.Insert(move(dat)); });

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= hto1.Exists(vec1[index]);
        }

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Dictionary Functions HashTableOpenAddress Insert Move String " << " TOT Error: " << toterr << endl;
}

void CheckHashTableOpnAdrRemoveString(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        Vector<string> vec1;

        PopularVectorString(vec1, 100);

        HashTableClsAdr<string> htc1;

        vec1.Traverse([&htc1](const string dat)
                      { htc1.Insert(dat); });

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= htc1.Exists(vec1[index]);
        }

        for (uint index = 0; index < vec1.Size(); index++)
        {
            htc1.Remove(vec1[index]);
        }

        chk &= !htc1.Remove("abcdef");
        chk &= htc1.Size() == 0;

        for (uint index = 0; index < vec1.Size(); index++)
        {
            chk &= !htc1.Exists(vec1[index]);
        }

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Dictionary Functions HashTableOpenAddress Remove String " << " TOT Error: " << toterr << endl;
}

/* ************************************************************************** */
/* ************************** EXERCISE 2 ************************************ */
/* ************************************************************************** */

// assignment test BinaryTreeLnk & BinaryTreeVec & BST
template <typename Data>
void CheckBinaryTreeLnkAssignment(uint &numtest, uint &toterr)
{
    List<Data> lst;

    lst.InsertAtBack(25);
    lst.InsertAtBack(15);
    lst.InsertAtBack(50);
    lst.InsertAtBack(8);
    lst.InsertAtBack(12);
    lst.InsertAtBack(40);
    lst.InsertAtBack(52);
    lst.InsertAtBack(6);
    lst.InsertAtBack(9);
    lst.InsertAtBack(14);
    lst.InsertAtBack(30);
    lst.InsertAtBack(42);
    lst.InsertAtBack(51);
    lst.InsertAtBack(58);
    lst.InsertAtBack(5);
    lst.InsertAtBack(7);
    lst.InsertAtBack(10);
    lst.InsertAtBack(13);
    lst.InsertAtBack(35);
    lst.InsertAtBack(48);
    lst.InsertAtBack(3);
    lst.InsertAtBack(11);
    lst.InsertAtBack(36);
    lst.InsertAtBack(46);
    lst.InsertAtBack(1);
    lst.InsertAtBack(4);

    BinaryTreeLnk<Data> btl(lst);

    CheckBinaryTreeLnkAssignmentCopy(btl, numtest, toterr);
    CheckBinaryTreeLnkAssignmentMove(btl, numtest, toterr);
}

template <typename Data>
void CheckBinaryTreeLnkAssignmentCopy(BinaryTreeLnk<Data> &btl, uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        BinaryTreeLnk<Data> btl2;

        BinaryTreeLnk<Data> btl3;

        BTPreOrderIterator<Data> itr(btl);

        btl2 = btl;

        btl.Traverse([&itr, &chk](const Data dat)
                     { chk &= *itr==dat;
                 ++itr; });

        btl2 = btl3;

        if (!btl2.Empty() && !btl2.Size() == 0)
            chk = false;

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }
    cout << numtest << " - " << "Check Copy Assignmet BinaryTreeLnk " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeLnkAssignmentMove(BinaryTreeLnk<Data> &btl, uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        BinaryTreeLnk<Data> btl2;
        BinaryTreeLnk<Data> btl3;

        BTPreOrderIterator<Data> itr(btl);

        btl3 = btl;

        btl2 = move(btl3);

        btl.Traverse([&itr, &chk](const Data dat)
                     { chk &= *itr==dat;
                 ++itr; });

        if (!btl3.Empty() && !btl3.Size() == 0)
            chk = false;

        btl2 = move(btl3);

        if (!btl2.Empty() && !btl2.Size() == 0)
            chk = false;

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }
    cout << numtest << " - " << "Check Move Assignmet BinaryTreeLnk " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeVecAssignment(uint &numtest, uint &toterr)
{
    List<Data> lst;

    lst.InsertAtBack(25);
    lst.InsertAtBack(15);
    lst.InsertAtBack(50);
    lst.InsertAtBack(8);
    lst.InsertAtBack(12);
    lst.InsertAtBack(40);
    lst.InsertAtBack(52);
    lst.InsertAtBack(6);
    lst.InsertAtBack(9);
    lst.InsertAtBack(14);
    lst.InsertAtBack(30);
    lst.InsertAtBack(42);
    lst.InsertAtBack(51);
    lst.InsertAtBack(58);
    lst.InsertAtBack(5);
    lst.InsertAtBack(7);
    lst.InsertAtBack(10);
    lst.InsertAtBack(13);
    lst.InsertAtBack(35);
    lst.InsertAtBack(48);
    lst.InsertAtBack(3);
    lst.InsertAtBack(11);
    lst.InsertAtBack(36);
    lst.InsertAtBack(46);
    lst.InsertAtBack(1);
    lst.InsertAtBack(4);

    BinaryTreeVec<Data> btv(lst);

    CheckBinaryTreeVecAssignmentCopy(btv, numtest, toterr);
    CheckBinaryTreeVecAssignmentMove(btv, numtest, toterr);
}

template <typename Data>
void CheckBinaryTreeVecAssignmentCopy(BinaryTreeVec<Data> &btv, uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        BinaryTreeVec<Data> btv2;

        BinaryTreeVec<Data> btv3;

        BTPreOrderIterator<Data> itr(btv);

        btv2 = btv;

        btv.Traverse([&itr, &chk](const Data dat)
                     { chk &= *itr==dat;
                 ++itr; });

        btv2 = btv3;

        if (!btv2.Empty() && !btv2.Size() == 0)
            chk = false;

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }
    cout << numtest << " - " << "Check Copy Assignmet BinaryTreeVec " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeVecAssignmentMove(BinaryTreeVec<Data> &btv, uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        BinaryTreeVec<Data> btv2;
        BinaryTreeVec<Data> btv3;

        BTPreOrderIterator<Data> itr(btv);

        btv3 = btv;

        btv2 = move(btv3);

        btv.Traverse([&itr, &chk](const Data dat)
                     { chk &= *itr==dat;
                 ++itr; });

        if (!btv3.Empty() && !btv3.Size() == 0)
            chk = false;

        btv2 = move(btv3);

        if (!btv2.Empty() && !btv2.Size() == 0)
            chk = false;

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }
    cout << numtest << " - " << "Check Move Assignmet BinaryTreeVec " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTAssignment(uint &numtest, uint &toterr)
{
    List<Data> lst;

    lst.InsertAtBack(25);
    lst.InsertAtBack(15);
    lst.InsertAtBack(50);
    lst.InsertAtBack(8);
    lst.InsertAtBack(12);
    lst.InsertAtBack(40);
    lst.InsertAtBack(52);
    lst.InsertAtBack(6);
    lst.InsertAtBack(9);
    lst.InsertAtBack(14);
    lst.InsertAtBack(30);
    lst.InsertAtBack(42);
    lst.InsertAtBack(51);
    lst.InsertAtBack(58);
    lst.InsertAtBack(5);
    lst.InsertAtBack(7);
    lst.InsertAtBack(10);
    lst.InsertAtBack(13);
    lst.InsertAtBack(35);
    lst.InsertAtBack(48);
    lst.InsertAtBack(3);
    lst.InsertAtBack(11);
    lst.InsertAtBack(36);
    lst.InsertAtBack(46);
    lst.InsertAtBack(1);
    lst.InsertAtBack(4);

    BST<Data> bst(lst);

    CheckBSTAssignmentCopy(bst, numtest, toterr);
    CheckBSTAssignmentMove(bst, numtest, toterr);
}

template <typename Data>
void CheckBSTAssignmentCopy(BST<Data> &bst, uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        BST<Data> bst2;

        BST<Data> bst3;

        BTPreOrderIterator<Data> itr(bst);

        bst2 = bst;

        bst.Traverse([&itr, &chk](const Data dat)
                     { chk &= *itr==dat;
                 ++itr; });

        bst2 = bst3;

        if (!bst2.Empty() && !bst2.Size() == 0)
            chk = false;

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }
    cout << numtest << " - " << "Check Copy Assignmet BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTAssignmentMove(BST<Data> &bst, uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        BST<Data> bst2;
        BST<Data> bst3;

        BTPreOrderIterator<Data> itr(bst);

        bst3 = bst;

        bst2 = move(bst3);

        bst.Traverse([&itr, &chk](const Data dat)
                     { chk &= *itr==dat;
                 ++itr; });

        if (!bst3.Empty() && !bst3.Size() == 0)
            chk = false;

        bst2 = move(bst3);

        if (!bst2.Empty() && !bst2.Size() == 0)
            chk = false;

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }
    cout << numtest << " - " << "Check Move Assignmet BST " << " TOT Error: " << toterr << endl;
}

/* ************************************************************************** */

// compare test BinaryTree BinaryTreeLnk & BinaryTreeVec & BST
template <typename Data>
void CheckBinaryTreeCompare(uint &numtest, uint &toterr)
{
    List<Data> lst;
    List<Data> lst2;

    lst.InsertAtBack(1);
    lst.InsertAtBack(3);
    lst.InsertAtBack(10);
    lst.InsertAtBack(5);
    lst.InsertAtBack(2);
    lst.InsertAtBack(7);
    lst.InsertAtBack(9);
    lst.InsertAtBack(20);

    lst2 = lst;

    lst2.InsertAtBack(6);

    BinaryTreeLnk<Data> btl(lst);
    BinaryTreeLnk<Data> btl2(lst2);

    CheckBinaryTreeLnkCompare<Data>(btl, btl2, numtest, toterr);

    BinaryTreeVec<Data> btv(lst);
    BinaryTreeVec<Data> btv2(lst2);

    CheckBinaryTreeVecCompare<Data>(btv, btv2, numtest, toterr);

    BST<Data> bst(lst);
    BST<Data> bst2(lst2);

    CheckBSTCompare<Data>(bst, bst2, numtest, toterr);

    BinaryTreeLnk<Data> btl3(lst);
    BinaryTreeVec<Data> btv3(lst);
    BinaryTreeVec<Data> bts3(lst);

    CheckBTCompare<Data>(btl3, btv3, numtest, toterr);
    CheckBTCompare<Data>(btv3, btl3, numtest, toterr);
    CheckBTCompare<Data>(bts3, bts3, numtest, toterr);
}

template <typename Data>
void CheckBTCompare(BinaryTree<Data> &bt, BinaryTree<Data> &bt2, uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        (bt == bt2) ? chk &= true : chk &= false;
        (bt != bt2) ? chk &= false : chk &= true;

        (bt == bt) ? chk &= true : chk &= false;
        (bt != bt) ? chk &= false : chk &= true;

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        toterr++;
        cout << "Warning Error" << endl;
    }

    cout << numtest << " - " << "Check Compare BinaryTree " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeLnkCompare(BinaryTreeLnk<Data> &btl, BinaryTreeLnk<Data> &btl2, uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        (btl == btl2) ? chk &= false : chk &= true;
        (btl != btl2) ? chk &= true : chk &= false;

        (btl == btl) ? chk &= true : chk &= false;
        (btl != btl) ? chk &= false : chk &= true;

        btl.Clear();
        btl2.Clear();

        (btl == btl2) ? chk &= true : chk &= false;
        (btl != btl2) ? chk &= false : chk &= true;

        (btl == btl) ? chk &= true : chk &= false;
        (btl != btl) ? chk &= false : chk &= true;

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        toterr++;
        cout << "Warning Error" << endl;
    }

    cout << numtest << " - " << "Check Compare BinaryTreeLnk " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeVecCompare(BinaryTreeVec<Data> &btv, BinaryTreeVec<Data> &btv2, uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        (btv == btv2) ? chk &= false : chk &= true;
        (btv != btv2) ? chk &= true : chk &= false;

        (btv == btv) ? chk &= true : chk &= false;
        (btv != btv) ? chk &= false : chk &= true;

        btv.Clear();
        btv2.Clear();

        (btv == btv2) ? chk &= true : chk &= false;
        (btv != btv2) ? chk &= false : chk &= true;

        (btv == btv) ? chk &= true : chk &= false;
        (btv != btv) ? chk &= false : chk &= true;

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        toterr++;
        cout << "Warning Error" << endl;
    }

    cout << numtest << " - " << "Check Compare BinaryTreeVec " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTCompare(BST<Data> &bst, BST<Data> &bst2, uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    try
    {
        (bst == bst2) ? chk &= false : chk &= true;
        (bst != bst2) ? chk &= true : chk &= false;

        (bst == bst) ? chk &= true : chk &= false;
        (bst != bst) ? chk &= false : chk &= true;

        bst.Clear();
        bst2.Clear();

        (bst == bst2) ? chk &= true : chk &= false;
        (bst != bst2) ? chk &= false : chk &= true;

        (bst == bst) ? chk &= true : chk &= false;
        (bst != bst) ? chk &= false : chk &= true;

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        toterr++;
        cout << "Warning Error" << endl;
    }

    cout << numtest << " - " << "Check Compare BST " << " TOT Error: " << toterr << endl;
}

/* ************************************************************************** */

// function test BinaryTreeLnk

template <typename Data>
void CheckBinaryTreeLnkConstructors(uint &numtest, uint &toterr)
{
    CheckBinaryTreeLnkConstructorTraversable<Data>(numtest, toterr);
    CheckBinaryTreeLnkConstructorMappable<Data>(numtest, toterr);
    CheckBinaryTreeLnkConstructorCopy<Data>(numtest, toterr);
    CheckBinaryTreeLnkConstructorMove<Data>(numtest, toterr);
}

template <typename Data>
void CheckBinaryTreeLnkConstructorTraversable(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;
    Vector<Data> vec(lst);

    try
    {
        BinaryTreeLnk<Data> bstl(lst);
        BinaryTreeLnk<Data> bstl2(vec);
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Traversable Constructor BinaryTreeLnk " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeLnkConstructorMappable(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;
    Vector<Data> vec(lst);

    try
    {
        BinaryTreeLnk<Data> btl(move(lst));
        BinaryTreeLnk<Data> btl2(move(vec));
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Mappable Constructor BinaryTreeLnk " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeLnkConstructorCopy(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;
    BinaryTreeLnk<Data> btl(lst);

    try
    {
        BinaryTreeLnk<Data> btl2(btl);
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Copy Constructor BinaryTreeLnk " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeLnkConstructorMove(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;
    BinaryTreeLnk<Data> btl(lst);

    try
    {
        BinaryTreeLnk<Data> btl2(move(btl));
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }

    cout << numtest << " - " << "Check Copy Constructor BinaryTreeLnk " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeLnkFunctionBase(uint &numtest, uint &toterr)
{
    CheckBinaryTreeLnkRoot<Data>(numtest, toterr);
    CheckBinaryTreeLnkMutableRoot<Data>(numtest, toterr);
    CheckBinaryTreeLnkClear<Data>(numtest, toterr);
}

template <typename Data>
void CheckBinaryTreeLnkRoot(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;

    lst.Insert(1);
    lst.Insert(2);
    lst.Insert(3);
    lst.Insert(4);
    lst.Insert(5);
    lst.Insert(6);
    lst.Insert(7);
    lst.Insert(8);

    BinaryTreeLnk<Data> btl;
    BinaryTreeLnk<Data> btl2(lst);

    bool check = false;

    try
    {
        btl.Root();
    }
    catch (...)
    {
        check = true;
    }

    try
    {
        if (check && btl2.Root().Element() != lst.Front())
        {
            toterr++;
            check = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }

    cout << numtest << " - " << "Check Root BinaryTreeLnk " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeLnkMutableRoot(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;

    lst.Insert(1);
    lst.Insert(2);
    lst.Insert(3);
    lst.Insert(4);
    lst.Insert(5);
    lst.Insert(6);
    lst.Insert(7);
    lst.Insert(8);

    BinaryTreeLnk<Data> btl(lst);

    bool chk = true;

    try
    {
        if (btl.Root().Element() != lst.Front())
        {
            toterr++;
            chk = false;
        }

        btl.Root().Element() = 99;

        if (chk && btl.Root().Element() != 99)
        {
            toterr++;
        }
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }

    cout << numtest << " - " << "Check Mutable Root BinaryTreeLnk " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeLnkClear(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    List<Data> lst;

    lst.Insert(1);
    lst.Insert(2);
    lst.Insert(3);
    lst.Insert(4);
    lst.Insert(5);
    lst.Insert(6);
    lst.Insert(7);
    lst.Insert(8);

    BinaryTreeLnk<Data> btl(lst);

    try
    {

        if (btl.Size() == 0 || btl.Empty())
        {
            chk = false;
        }

        btl.Clear();

        if (chk && !(btl.Size() == 0 && btl.Empty()))
        {
            chk = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error ";
        chk = false;
    }

    if (!chk)
        toterr++;

    cout << numtest << " - " << "Check Clear BinaryTreeLnk " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeLnkNodeLnkFunction(uint &numtest, uint &toterr)
{
    CheckBinaryTreeLnkIsLeaf<Data>(numtest, toterr);
    CheckBinaryTreeLnkHasLeftChild<Data>(numtest, toterr);
    CheckBinaryTreeLnkHasRightChild<Data>(numtest, toterr);
    CheckBinaryTreeLnkLeftChild<Data>(numtest, toterr);
    CheckBinaryTreeLnkRightChild<Data>(numtest, toterr);
    CheckBinaryTreeLnkMutableLeftChild<Data>(numtest, toterr);
    CheckBinaryTreeLnkMutableRightChild<Data>(numtest, toterr);
}

/* ******************************************************************************* */

// function test Node & MutableNode
template <typename Data>
void CheckBinaryTreeLnkIsLeaf(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;

    lst.Insert(1);

    BinaryTreeLnk<Data> btl(lst);

    bool chk = true;

    try
    {

        if (!btl.Root().IsLeaf())
        {
            chk = false;
            toterr++;
        }

        lst.Insert(2);
        lst.Insert(3);

        BinaryTreeLnk<Data> btl2(lst);

        if (chk && btl2.Root().IsLeaf())
        {
            chk = false;
            toterr++;
        }
    }
    catch (...)
    {
        cout << "Warning error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check NodeLnk IsLeaf BinaryTreeLnk " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeLnkHasLeftChild(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;

    lst.Insert(1);

    BinaryTreeLnk<Data> btl(lst);

    bool chk = true;

    try
    {

        if (btl.Root().HasLeftChild())
        {
            chk = false;
            toterr++;
        }

        lst.Insert(2);
        lst.Insert(3);

        BinaryTreeLnk<Data> btl2(lst);

        if (chk && !btl2.Root().HasLeftChild())
        {
            chk = false;
            toterr++;
        }
    }
    catch (...)
    {
        cout << "Warning error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check NodeLnk HasLeftChild BinaryTreeLnk " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeLnkHasRightChild(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;

    lst.Insert(1);

    BinaryTreeLnk<Data> btl(lst);

    bool chk = true;

    try
    {

        if (btl.Root().HasRightChild())
        {
            chk = false;
            toterr++;
        }

        lst.Insert(2);
        lst.Insert(3);

        BinaryTreeLnk<Data> btl2(lst);

        if (chk && !btl2.Root().HasRightChild())
        {
            chk = false;
            toterr++;
        }
    }
    catch (...)
    {
        cout << "Warning error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check NodeLnk HasRightChild BinaryTreeLnk " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeLnkLeftChild(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;

    lst.Insert(1);

    BinaryTreeLnk<Data> btl(lst);

    bool chk = true;

    try
    {

        try
        {
            if (btl.Root().LeftChild().Element())
            {
                chk = false;
                toterr++;
            }
        }
        catch (...)
        {
            chk = true;
        }

        lst.Insert(2);
        lst.Insert(3);

        BinaryTreeLnk<Data> btl2(lst);

        if (chk && (btl2.Root().LeftChild().Element() != 2))
        {
            chk = false;
            toterr++;
        }
    }
    catch (...)
    {
        cout << "Warning error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check NodeLnk LeftChild BinaryTreeLnk " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeLnkRightChild(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;

    lst.Insert(1);

    BinaryTreeLnk<Data> btl(lst);

    bool chk = true;

    try
    {

        try
        {
            if (btl.Root().RightChild().Element())
            {
                chk = false;
                toterr++;
            }
        }
        catch (...)
        {
            chk = true;
        }

        lst.Insert(2);
        lst.Insert(3);

        BinaryTreeLnk<Data> btl2(lst);

        if (chk && (btl2.Root().RightChild().Element() != 3))
        {
            chk = false;
            toterr++;
        }
    }
    catch (...)
    {
        cout << "Warning error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check NodeLnk RightChild BinaryTreeLnk " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeLnkMutableLeftChild(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;

    lst.Insert(1);
    lst.Insert(2);
    lst.Insert(3);

    BinaryTreeLnk<Data> btl(lst);

    try
    {
        btl.Root().LeftChild().Element() = 5;

        if (btl.Root().LeftChild().Element() != 5)
        {
            toterr++;
        }
    }
    catch (...)
    {
        cout << "Warning error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check NodeLnk MutableLeftChild BinaryTreeLnk " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeLnkMutableRightChild(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;

    lst.Insert(1);
    lst.Insert(2);
    lst.Insert(3);

    BinaryTreeLnk<Data> btl(lst);

    try
    {

        btl.Root().RightChild().Element() = 4;

        if ((btl.Root().RightChild().Element() != 4))
        {
            toterr++;
        }
    }
    catch (...)
    {
        cout << "Warning error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check NodeLnk MutableRightChild BinaryTreeLnk " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeVecIsLeaf(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;

    lst.Insert(1);

    BinaryTreeVec<Data> btv(lst);

    bool chk = true;

    try
    {

        if (!btv.Root().IsLeaf())
        {
            chk = false;
            toterr++;
        }

        lst.Insert(2);
        lst.Insert(3);

        BinaryTreeVec<Data> btv2(lst);

        if (chk && btv2.Root().IsLeaf())
        {
            chk = false;
            toterr++;
        }
    }
    catch (...)
    {
        cout << "Warning error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check NodeLnk IsLeaf BinaryTreeVec " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeVecHasLeftChild(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;

    lst.Insert(1);

    BinaryTreeVec<Data> btv(lst);

    bool chk = true;

    try
    {

        if (btv.Root().HasLeftChild())
        {
            chk = false;
            toterr++;
        }

        lst.Insert(2);
        lst.Insert(3);

        BinaryTreeVec<Data> btv2(lst);

        if (chk && !btv2.Root().HasLeftChild())
        {
            chk = false;
            toterr++;
        }
    }
    catch (...)
    {
        cout << "Warning error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check NodeLnk HasLeftChild BinaryTreeVec " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeVecHasRightChild(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;

    lst.Insert(1);

    BinaryTreeVec<Data> btv(lst);

    bool chk = true;

    try
    {

        if (btv.Root().HasRightChild())
        {
            chk = false;
            toterr++;
        }

        lst.Insert(2);
        lst.Insert(3);

        BinaryTreeVec<Data> btv2(lst);

        if (chk && !btv2.Root().HasRightChild())
        {
            chk = false;
            toterr++;
        }
    }
    catch (...)
    {
        cout << "Warning error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check NodeLnk HasRightChild BinaryTreeVec " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeVecLeftChild(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;

    lst.Insert(1);

    BinaryTreeVec<Data> btv(lst);

    bool chk = true;

    try
    {

        try
        {
            if (btv.Root().LeftChild().Element())
            {
                chk = false;
                toterr++;
            }
        }
        catch (...)
        {
            chk = true;
        }

        lst.Insert(2);
        lst.Insert(3);

        BinaryTreeVec<Data> btv2(lst);

        if (chk && (btv2.Root().LeftChild().Element() != 2))
        {
            chk = false;
            toterr++;
        }
    }
    catch (...)
    {
        cout << "Warning error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check NodeLnk LeftChild BinaryTreeVec " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeVecRightChild(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;

    lst.Insert(1);

    BinaryTreeVec<Data> btv(lst);

    bool chk = true;

    try
    {

        try
        {
            if (btv.Root().RightChild().Element())
            {
                chk = false;
                toterr++;
            }
        }
        catch (...)
        {
            chk = true;
        }

        lst.Insert(2);
        lst.Insert(3);

        BinaryTreeVec<Data> btv2(lst);

        if (chk && (btv2.Root().RightChild().Element() != 3))
        {
            chk = false;
            toterr++;
        }
    }
    catch (...)
    {
        cout << "Warning error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check NodeLnk RightChild BinaryTreeVec " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeVecMutableLeftChild(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;

    lst.Insert(1);
    lst.Insert(2);
    lst.Insert(3);

    BinaryTreeVec<Data> btv(lst);

    try
    {
        btv.Root().LeftChild().Element() = 5;

        if (btv.Root().LeftChild().Element() != 5)
        {
            toterr++;
        }
    }
    catch (...)
    {
        cout << "Warning error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check NodeLnk MutableLeftChild BinaryTreeVec " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeVecMutableRightChild(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;

    lst.Insert(1);
    lst.Insert(2);
    lst.Insert(3);

    BinaryTreeVec<Data> btv(lst);

    try
    {

        btv.Root().RightChild().Element() = 4;

        if ((btv.Root().RightChild().Element() != 4))
        {
            toterr++;
        }
    }
    catch (...)
    {
        cout << "Warning error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check NodeLnk MutableRightChild BinaryTreeVec " << " TOT Error: " << toterr << endl;
}

/* ************************************************************************************************ */

// function test BinaryTreeVec
template <typename Data>
void CheckBinaryTreeVecConstructors(uint &numtest, uint &toterr)
{
    CheckBinaryTreeVecConstructorTraversable<Data>(numtest, toterr);
    CheckBinaryTreeVecConstructorMappable<Data>(numtest, toterr);
    CheckBinaryTreeVecConstructorCopy<Data>(numtest, toterr);
    CheckBinaryTreeVecConstructorMove<Data>(numtest, toterr);
}

template <typename Data>
void CheckBinaryTreeVecConstructorTraversable(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;
    Vector<Data> vec(lst);

    try
    {
        BinaryTreeVec<Data> btv(lst);
        BinaryTreeVec<Data> btv2(vec);
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Traversable Constructor BinaryTreeVec " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeVecConstructorMappable(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;
    Vector<Data> vec(lst);

    try
    {
        BinaryTreeVec<Data> btv(move(lst));
        BinaryTreeVec<Data> btv2(move(vec));
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Mappable Constructor BinaryTreeVec " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeVecConstructorCopy(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;
    BinaryTreeVec<Data> btv(lst);

    try
    {
        BinaryTreeVec<Data> btv2(btv);
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Copy Constructor BinaryTreeVec " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeVecConstructorMove(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;
    BinaryTreeVec<Data> btv(lst);

    try
    {
        BinaryTreeVec<Data> btv2(move(btv));
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }

    cout << numtest << " - " << "Check Move Constructor BinaryTreeVec " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeVecFunctionBase(uint &numtest, uint &toterr)
{
    CheckBinaryTreeVecRoot<Data>(numtest, toterr);
    CheckBinaryTreeVecMutableRoot<Data>(numtest, toterr);
    CheckBinaryTreeVecClear<Data>(numtest, toterr);
}

template <typename Data>
void CheckBinaryTreeVecRoot(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;

    lst.Insert(1);
    lst.Insert(2);
    lst.Insert(3);
    lst.Insert(4);
    lst.Insert(5);
    lst.Insert(6);
    lst.Insert(7);
    lst.Insert(8);

    BinaryTreeVec<Data> btv;
    BinaryTreeVec<Data> btv2(lst);

    bool check = false;

    try
    {
        btv.Root();
    }
    catch (...)
    {
        check = true;
    }

    try
    {
        if (check && btv2.Root().Element() != lst.Front())
        {
            toterr++;
            check = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }

    cout << numtest << " - " << "Check Root BinaryTreeVec " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeVecMutableRoot(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;

    lst.Insert(1);
    lst.Insert(2);
    lst.Insert(3);
    lst.Insert(4);
    lst.Insert(5);
    lst.Insert(6);
    lst.Insert(7);
    lst.Insert(8);

    BinaryTreeVec<Data> btv(lst);

    bool chk = true;

    try
    {
        if (btv.Root().Element() != lst.Front())
        {
            toterr++;
            chk = false;
        }

        btv.Root().Element() = 99;

        if (chk && btv.Root().Element() != 99)
        {
            toterr++;
        }
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }

    cout << numtest << " - " << "Check Mutable Root BinaryTreeLnk " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeVecClear(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    List<Data> lst;

    lst.Insert(1);
    lst.Insert(2);
    lst.Insert(3);
    lst.Insert(4);
    lst.Insert(5);
    lst.Insert(6);
    lst.Insert(7);
    lst.Insert(8);

    BinaryTreeVec<Data> btv(lst);

    try
    {

        if (btv.Size() == 0 || btv.Empty())
        {
            chk = false;
        }

        btv.Clear();

        if (chk && !(btv.Size() == 0 && btv.Empty()))
        {
            chk = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error ";
        chk = false;
    }

    if (!chk)
        toterr++;

    cout << numtest << " - " << "Check Clear BinaryTreeVec " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeVecNodeVecFunction(uint &numtest, uint &toterr)
{
    CheckBinaryTreeVecIsLeaf<Data>(numtest, toterr);
    CheckBinaryTreeVecHasLeftChild<Data>(numtest, toterr);
    CheckBinaryTreeVecHasRightChild<Data>(numtest, toterr);
    CheckBinaryTreeVecLeftChild<Data>(numtest, toterr);
    CheckBinaryTreeVecRightChild<Data>(numtest, toterr);
    CheckBinaryTreeVecMutableLeftChild<Data>(numtest, toterr);
    CheckBinaryTreeVecMutableRightChild<Data>(numtest, toterr);
}

// function BinaryTreeVec Traverse Rircorsive & Iterative

template <typename Data>
void CheckBinaryTreeVecFunctionTraverse(uint &numtest, uint &toterr)
{
    List<Data> lst;

    lst.InsertAtBack(25);
    lst.InsertAtBack(15);
    lst.InsertAtBack(50);
    lst.InsertAtBack(8);
    lst.InsertAtBack(12);
    lst.InsertAtBack(40);
    lst.InsertAtBack(52);
    lst.InsertAtBack(6);
    lst.InsertAtBack(9);
    lst.InsertAtBack(14);
    lst.InsertAtBack(30);
    lst.InsertAtBack(42);
    lst.InsertAtBack(51);
    lst.InsertAtBack(58);
    lst.InsertAtBack(5);
    lst.InsertAtBack(7);
    lst.InsertAtBack(10);
    lst.InsertAtBack(13);
    lst.InsertAtBack(35);
    lst.InsertAtBack(48);
    lst.InsertAtBack(3);
    lst.InsertAtBack(11);
    lst.InsertAtBack(36);
    lst.InsertAtBack(46);
    lst.InsertAtBack(1);
    lst.InsertAtBack(4);

    BinaryTreeVec<Data> btv(lst);

    CheckBinaryTreeVecTraverse<Data>(btv, numtest, toterr);
    CheckBinaryTreeVecPreOrderTraverse<Data>(btv, numtest, toterr);
    CheckBinaryTreeVecInOrderTraverse<Data>(btv, numtest, toterr);
    CheckBinaryTreeVecPostOrderTraverse<Data>(btv, numtest, toterr);
    CheckBinaryTreeVecBreadthTraverse<Data>(btv, numtest, toterr);
}

template <typename Data>
void CheckBinaryTreeVecTraverse(BinaryTreeVec<Data> &btv, uint &numtest, uint &toterr)
{
    numtest++;

    Data vec[26] = {25, 15, 8, 6, 7, 10, 9, 13, 35, 12, 14, 48, 3, 30, 11, 36, 50, 40, 42, 46, 1, 51, 4, 52, 58, 5};

    bool chk = true;

    uint index = 0;

    try
    {

        btv.Traverse([&chk, &vec, &index](const Data dat)
                     { chk &= vec[index++] == dat; });

        if (!chk)
        {
            toterr++;
            chk = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check Traverse BinaryTreeVec " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeVecPreOrderTraverse(BinaryTreeVec<Data> &btv, uint &numtest, uint &toterr)
{
    numtest++;

    Data vec[26] = {25, 15, 8, 6, 7, 10, 9, 13, 35, 12, 14, 48, 3, 30, 11, 36, 50, 40, 42, 46, 1, 51, 4, 52, 58, 5};

    bool chk = true;

    uint index = 0;

    try
    {
        BTPreOrderIterator<Data> itr(btv);

        btv.PreOrderTraverse([&chk, &vec, &index, &itr](const Data dat)
                             { chk &= (vec[index++] == dat) && (dat == *itr);
                             ++itr; });

        if (!chk)
        {
            toterr++;
            chk = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check PreOrderTraverse BinaryTreeVec " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeVecInOrderTraverse(BinaryTreeVec<Data> &btv, uint &numtest, uint &toterr)
{
    numtest++;

    Data vec[26] = {7, 6, 10, 8, 13, 9, 35, 15, 48, 14, 3, 12, 11, 30, 36, 25, 46, 42, 1, 40, 4, 51, 50, 58, 52, 5};

    bool chk = true;

    uint index = 0;

    try
    {
        BTInOrderIterator<Data> itr(btv);

        btv.InOrderTraverse([&chk, &vec, &index, &itr](const Data dat)
                            { chk &= (vec[index++] == dat) && (dat == *itr);
                            ++itr; });

        if (!chk)
        {
            toterr++;
            chk = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check InOrderTraverse BinaryTreeVec " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeVecPostOrderTraverse(BinaryTreeVec<Data> &btv, uint &numtest, uint &toterr)
{
    numtest++;

    Data vec[26] = {7, 10, 6, 13, 35, 9, 8, 48, 3, 14, 11, 36, 30, 12, 15, 46, 1, 42, 4, 51, 40, 58, 5, 52, 50, 25};

    bool chk = true;

    uint index = 0;

    try
    {

        BTPostOrderIterator<Data> itr(btv);

        btv.PostOrderTraverse([&chk, &vec, &index, &itr](const Data dat)
                              { chk &= (vec[index++] == dat) && (dat == *itr);
                            ++itr; });

        if (!chk)
        {
            toterr++;
            chk = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check PostOrderTraverse BinaryTreeVec " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeVecBreadthTraverse(BinaryTreeVec<Data> &btv, uint &numtest, uint &toterr)
{
    numtest++;

    Data vec[26] = {25, 15, 50, 8, 12, 40, 52, 6, 9, 14, 30, 42, 51, 58, 5, 7, 10, 13, 35, 48, 3, 11, 36, 46, 1, 4};

    bool chk = true;

    uint index = 0;

    try
    {
        BTBreadthIterator<Data> itr(btv);

        btv.BreadthTraverse([&chk, &vec, &index, &itr](const Data dat)
                            { chk &= (vec[index++] == dat) && (dat == *itr);
                            ++itr; });

        if (!chk)
        {
            toterr++;
            chk = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check BreadthTraverse BinaryTreeVec " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeVecFunctionMap(uint &numtest, uint &toterr)
{
    List<Data> lst;

    lst.InsertAtBack(25);
    lst.InsertAtBack(15);
    lst.InsertAtBack(50);
    lst.InsertAtBack(8);
    lst.InsertAtBack(12);
    lst.InsertAtBack(40);
    lst.InsertAtBack(52);
    lst.InsertAtBack(6);
    lst.InsertAtBack(9);
    lst.InsertAtBack(14);
    lst.InsertAtBack(30);
    lst.InsertAtBack(42);
    lst.InsertAtBack(51);
    lst.InsertAtBack(58);
    lst.InsertAtBack(5);
    lst.InsertAtBack(7);
    lst.InsertAtBack(10);
    lst.InsertAtBack(13);
    lst.InsertAtBack(35);
    lst.InsertAtBack(48);
    lst.InsertAtBack(3);
    lst.InsertAtBack(11);
    lst.InsertAtBack(36);
    lst.InsertAtBack(46);
    lst.InsertAtBack(1);
    lst.InsertAtBack(4);

    BinaryTreeVec<Data> btv(lst);

    CheckBinaryTreeVecMap<Data>(btv, numtest, toterr);
}

template <typename Data>
void CheckBinaryTreeVecMap(BinaryTreeVec<Data> &btv, uint &numtest, uint &toterr)
{
    numtest++;

    Data vec[26] = {25, 15, 8, 6, 7, 10, 9, 13, 35, 12, 14, 48, 3, 30, 11, 36, 50, 40, 42, 46, 1, 51, 4, 52, 58, 5};

    uint index = 0;
    bool chk = true;

    try
    {
        btv.Map([](Data &dat)
                { dat = dat * 2; });

        btv.Traverse([&vec, &index, &chk](const Data dat)
                     { chk &= ((vec[index] * 2) == dat);
                     index++; });

        // BTPreOrderMutableIterator<Data> itr(bst);

        // index = 0;

        // bst.Traverse([&vec, &itr, &chk, &index](const Data dat)
        //              { *itr = (dat/2);
        //              chk &=(vec[index]==dat);
        //              ++itr; });

        if (!chk)
        {
            toterr++;
            chk = false;
        }
    }

    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check Map BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBinaryTreeVecFunctionFold(uint &numtest, uint &toterr)
{
    List<Data> lst;

    lst.InsertAtBack(25);
    lst.InsertAtBack(15);
    lst.InsertAtBack(50);
    lst.InsertAtBack(8);
    lst.InsertAtBack(12);
    lst.InsertAtBack(40);
    lst.InsertAtBack(52);
    lst.InsertAtBack(6);
    lst.InsertAtBack(9);
    lst.InsertAtBack(14);
    lst.InsertAtBack(30);
    lst.InsertAtBack(42);
    lst.InsertAtBack(51);
    lst.InsertAtBack(58);
    lst.InsertAtBack(5);
    lst.InsertAtBack(7);
    lst.InsertAtBack(10);
    lst.InsertAtBack(13);
    lst.InsertAtBack(35);
    lst.InsertAtBack(48);
    lst.InsertAtBack(3);
    lst.InsertAtBack(11);
    lst.InsertAtBack(36);
    lst.InsertAtBack(46);
    lst.InsertAtBack(1);
    lst.InsertAtBack(4);

    BinaryTreeVec<Data> btv(lst);

    CheckBinaryTreeVecFold<Data>(btv, numtest, toterr);
}

template <typename Data>
void CheckBinaryTreeVecFold(BinaryTreeVec<Data> &btv, uint &numtest, uint &toterr)
{
    numtest++;

    uint val = 0;

    try
    {
        val = btv.Fold(&FoldTotal<Data>, 0);

        val = 631 % 100;

        if (val != 31)
        {
            toterr++;
        }
    }

    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check Fold BST " << " TOT Error: " << toterr << endl;
}

/* ************************************************************************************************ */

// function test BST
template <typename Data>
void CheckBSTConstructors(uint &numtest, uint &toterr)
{
    CheckBSTConstructorTraversable<Data>(numtest, toterr);
    CheckBSTConstructorMappable<Data>(numtest, toterr);
    CheckBSTConstructorCopy<Data>(numtest, toterr);
    CheckBSTConstructorMove<Data>(numtest, toterr);
}

template <typename Data>
void CheckBSTConstructorTraversable(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;
    Vector<Data> vec(lst);

    try
    {
        BST<Data> bstl(lst);
        BST<Data> bstl2(vec);
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Traversable Constructor BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTConstructorMappable(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;
    Vector<Data> vec(lst);

    try
    {
        BST<Data> bstl(move(lst));
        BST<Data> bstl2(move(vec));
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Mappable Constructor BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTConstructorCopy(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;
    BST<Data> bstl(lst);

    try
    {
        BST<Data> bstl2(bstl);
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }
    cout << numtest << " - " << "Check Copy Constructor BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTConstructorMove(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;
    BST<Data> bstl(lst);

    try
    {
        BST<Data> bstl2(move(bstl));
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }

    cout << numtest << " - " << "Check Move Constructor BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTFunctionBase(uint &numtest, uint &toterr)
{
    CheckBSTRoot<Data>(numtest, toterr);
    CheckBSTExists<Data>(numtest, toterr);
    CheckBSTClear<Data>(numtest, toterr);
}

template <typename Data>
void CheckBSTRoot(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;

    lst.Insert(1);
    lst.Insert(2);
    lst.Insert(3);
    lst.Insert(4);
    lst.Insert(5);
    lst.Insert(6);
    lst.Insert(7);
    lst.Insert(8);

    BST<Data> bst;
    BST<Data> bst2(lst);

    bool check = false;

    try
    {
        bst.Root();
    }
    catch (...)
    {
        check = true;
    }

    try
    {
        if (check && bst2.Root().Element() != lst.Front())
        {
            toterr++;
            check = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error ";
        toterr++;
    }

    cout << numtest << " - " << "Check Root BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTExists(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;

    lst.Insert(5);
    lst.Insert(2);
    lst.Insert(7);
    lst.Insert(4);
    lst.Insert(1);
    lst.Insert(6);
    lst.Insert(3);
    lst.Insert(8);

    BST<Data> btv(lst);

    bool chk = true;

    try
    {
        for (uint index = 1; index < 9; index++)
        {
            chk &= btv.Exists(index);
        }

        for (uint index = 10; index < 19; index++)
        {
            chk &= !(btv.Exists(index));
        }
    }
    catch (...)
    {
        cout << "Warning Error ";
        chk = false;
    }

    if (!chk)
        toterr++;

    cout << numtest << " - " << "Check Exists BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTClear(uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    List<Data> lst;

    lst.Insert(1);
    lst.Insert(2);
    lst.Insert(3);
    lst.Insert(4);
    lst.Insert(5);
    lst.Insert(6);
    lst.Insert(7);
    lst.Insert(8);

    BinaryTreeVec<Data> bst(lst);

    try
    {

        if (bst.Size() == 0 || bst.Empty())
        {
            chk = false;
        }

        bst.Clear();

        if (chk && !(bst.Size() == 0 && bst.Empty()))
        {
            chk = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error ";
        chk = false;
    }

    if (!chk)
        toterr++;

    cout << numtest << " - " << "Check Clear BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTMemberFunction(uint &numtest, uint &toterr)
{
    CheckBSTMin<Data>(numtest, toterr);
    CheckBSTMinNRemove<Data>(numtest, toterr);
    CheckBSTRemoveMin<Data>(numtest, toterr);
    CheckBSTMax<Data>(numtest, toterr);
    CheckBSTMaxNRemove<Data>(numtest, toterr);
    CheckBSTRemoveMax<Data>(numtest, toterr);
    CheckBSTPredecessor<Data>(numtest, toterr);
    CheckBSTPredecessorNRemove<Data>(numtest, toterr);
    CheckBSTRemovePredecessor<Data>(numtest, toterr);
    CheckBSTSuccessor<Data>(numtest, toterr);
    CheckBSTSuccessorNRemove<Data>(numtest, toterr);
    CheckBSTRemoveSuccessor<Data>(numtest, toterr);
}

template <typename Data>
void CheckBSTMin(uint &numtest, uint &toterr)
{
    numtest++;

    BST<Data> bst;

    bool chk = false;

    try
    {
        bst.Min();
    }
    catch (...)
    {
        chk = true;
    }

    List<Data> lst;

    lst.Insert(5);
    lst.Insert(2);
    lst.Insert(7);
    lst.Insert(4);
    lst.Insert(5);
    lst.Insert(6);
    lst.Insert(3);
    lst.Insert(8);

    BST<Data> bst2(lst);

    try
    {

        if (chk && bst2.Min() != 2)
        {
            toterr++;
            chk = false;
        }

        bst2.RemoveMin();

        if (chk && bst2.Min() != 3)
        {
            toterr++;
            chk = false;
        }

        bst2.RemoveMin();

        if (chk && bst2.Min() != 4)
        {
            toterr++;
            chk = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check Min BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTMinNRemove(uint &numtest, uint &toterr)
{
    numtest++;

    BST<Data> bst;

    bool chk = false;

    try
    {
        bst.Min();
    }
    catch (...)
    {
        chk = true;
    }

    List<Data> lst;

    lst.Insert(5);
    lst.Insert(2);
    lst.Insert(7);
    lst.Insert(4);
    lst.Insert(5);
    lst.Insert(6);
    lst.Insert(3);
    lst.Insert(8);

    BST<Data> bst2(lst);

    try
    {

        if (chk && bst2.MinNRemove() != 2)
        {
            toterr++;
            chk = false;
        }

        if (chk && bst2.MinNRemove() != 3)
        {
            toterr++;
            chk = false;
        }

        if (chk && bst2.MinNRemove() != 4)
        {
            toterr++;
            chk = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check MinNRemove BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTRemoveMin(uint &numtest, uint &toterr)
{
    numtest++;

    BST<Data> bst;

    bool chk = false;

    try
    {
        bst.RemoveMin();
    }
    catch (...)
    {
        chk = true;
    }

    List<Data> lst;

    lst.Insert(5);
    lst.Insert(2);
    lst.Insert(7);
    lst.Insert(4);
    lst.Insert(5);
    lst.Insert(6);
    lst.Insert(3);
    lst.Insert(8);

    BST<Data> bst2(lst);

    try
    {

        if (chk && bst2.Min() != 2)
        {
            toterr++;
            chk = false;
        }

        bst2.RemoveMin();

        if (chk && bst2.Min() != 3)
        {
            toterr++;
            chk = false;
        }

        bst2.RemoveMin();

        if (chk && bst2.Min() != 4)
        {
            toterr++;
            chk = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check RemoveMin BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTMax(uint &numtest, uint &toterr)
{
    numtest++;

    BST<Data> bst;

    bool chk = false;

    try
    {
        bst.Max();
    }
    catch (...)
    {
        chk = true;
    }

    List<Data> lst;

    lst.Insert(5);
    lst.Insert(2);
    lst.Insert(7);
    lst.Insert(4);
    lst.Insert(5);
    lst.Insert(6);
    lst.Insert(3);
    lst.Insert(8);

    BST<Data> bst2(lst);

    try
    {

        if (chk && bst2.Max() != 8)
        {
            toterr++;
            chk = false;
        }

        bst2.RemoveMax();

        if (chk && bst2.Max() != 7)
        {
            toterr++;
            chk = false;
        }

        bst2.RemoveMax();

        if (chk && bst2.Max() != 6)
        {
            toterr++;
            chk = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check Max BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTMaxNRemove(uint &numtest, uint &toterr)
{
    numtest++;

    BST<Data> bst;

    bool chk = false;

    try
    {
        bst.Max();
    }
    catch (...)
    {
        chk = true;
    }

    List<Data> lst;

    lst.Insert(5);
    lst.Insert(2);
    lst.Insert(7);
    lst.Insert(4);
    lst.Insert(5);
    lst.Insert(6);
    lst.Insert(3);
    lst.Insert(8);

    BST<Data> bst2(lst);

    try
    {

        if (chk && bst2.MaxNRemove() != 8)
        {
            toterr++;
            chk = false;
        }

        if (chk && bst2.MaxNRemove() != 7)
        {
            toterr++;
            chk = false;
        }

        if (chk && bst2.MaxNRemove() != 6)
        {
            toterr++;
            chk = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check MaxNRemove BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTRemoveMax(uint &numtest, uint &toterr)
{
    numtest++;

    BST<Data> bst;

    bool chk = false;

    try
    {
        bst.RemoveMax();
    }
    catch (...)
    {
        chk = true;
    }

    List<Data> lst;

    lst.Insert(5);
    lst.Insert(2);
    lst.Insert(7);
    lst.Insert(4);
    lst.Insert(5);
    lst.Insert(6);
    lst.Insert(3);
    lst.Insert(8);

    BST<Data> bst2(lst);

    try
    {

        if (chk && bst2.Max() != 8)
        {
            toterr++;
            chk = false;
        }

        bst2.RemoveMax();

        if (chk && bst2.Max() != 7)
        {
            toterr++;
            chk = false;
        }

        bst2.RemoveMax();

        if (chk && bst2.Max() != 6)
        {
            toterr++;
            chk = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check RemoveMax BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTSuccessor(uint &numtest, uint &toterr)
{
    numtest++;

    BST<Data> bst;

    bool chk = false;

    try
    {
        bst.Successor(6);
    }
    catch (...)
    {
        chk = true;
    }

    List<Data> lst;

    lst.Insert(5);
    lst.Insert(2);
    lst.Insert(1);
    lst.Insert(-1);
    lst.Insert(7);
    lst.Insert(4);
    lst.Insert(5);
    lst.Insert(6);
    lst.Insert(3);
    lst.Insert(-3);
    lst.Insert(8);

    BST<Data> bst2(lst);

    try
    {

        try
        {
            bst2.Successor(8);
        }
        catch (...)
        {
            chk &= true;
        }

        if (chk && bst2.Successor(7) != 8)
        {
            toterr++;
            chk = false;
        }

        if (chk && bst2.Successor(-4) != -3)
        {
            toterr++;
            chk = false;
        }

        if (chk && bst2.Successor(0) != 1)
        {
            toterr++;
            chk = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check Successor BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTSuccessorNRemove(uint &numtest, uint &toterr)
{
    numtest++;

    BST<Data> bst;

    bool chk = false;

    try
    {
        bst.SuccessorNRemove(6);
    }
    catch (...)
    {
        chk = true;
    }

    List<Data> lst;

    lst.Insert(5);
    lst.Insert(2);
    lst.Insert(1);
    lst.Insert(-1);
    lst.Insert(7);
    lst.Insert(4);
    lst.Insert(5);
    lst.Insert(6);
    lst.Insert(3);
    lst.Insert(-3);
    lst.Insert(8);

    BST<Data> bst2(lst);

    try
    {

        try
        {
            bst2.SuccessorNRemove(8);
        }
        catch (...)
        {
            chk &= true;
        }

        if (chk && bst2.SuccessorNRemove(7) != 8)
        {
            toterr++;
            chk = false;
        }

        if (chk && bst2.SuccessorNRemove(-4) != -3)
        {
            toterr++;
            chk = false;
        }

        if (chk && bst2.SuccessorNRemove(0) != 1)
        {
            toterr++;
            chk = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check SuccessorNRemove BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTRemoveSuccessor(uint &numtest, uint &toterr)
{
    numtest++;

    BST<Data> bst;

    bool chk = false;

    try
    {
        bst.RemoveSuccessor(6);
    }
    catch (...)
    {
        chk = true;
    }

    List<Data> lst;

    lst.Insert(5);
    lst.Insert(2);
    lst.Insert(1);
    lst.Insert(-1);
    lst.Insert(7);
    lst.Insert(4);
    lst.Insert(5);
    lst.Insert(6);
    lst.Insert(3);
    lst.Insert(-3);
    lst.Insert(8);

    BST<Data> bst2(lst);

    try
    {

        try
        {
            bst2.RemoveSuccessor(8);
        }
        catch (...)
        {
            chk &= true;
        }

        bst2.RemoveSuccessor(7);

        if (chk && bst2.Exists(8))
        {
            toterr++;
            chk = false;
        }

        bst2.RemoveSuccessor(-4);

        if (chk && bst2.Exists(-3))
        {
            toterr++;
            chk = false;
        }

        bst2.RemoveSuccessor(0);

        if (chk && bst2.Exists(0))
        {
            toterr++;
            chk = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check RemoveSuccessor BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTPredecessor(uint &numtest, uint &toterr)
{
    numtest++;

    BST<Data> bst;

    bool chk = false;

    try
    {
        bst.Predecessor(6);
    }
    catch (...)
    {
        chk = true;
    }

    List<Data> lst;

    lst.Insert(5);
    lst.Insert(2);
    lst.Insert(1);
    lst.Insert(-1);
    lst.Insert(7);
    lst.Insert(4);
    lst.Insert(6);
    lst.Insert(3);
    lst.Insert(-3);
    lst.Insert(8);

    BST<Data> bst2(lst);

    try
    {
        bst2.Predecessor(-3);
    }
    catch (...)
    {
        chk &= true;
    }

    try
    {
        if (chk && bst2.Predecessor(8) != 7)
        {
            toterr++;
            chk = false;
        }

        if (chk && bst2.Predecessor(-1) != -3)
        {
            toterr++;
            chk = false;
        }

        if (chk && bst2.Predecessor(1) != -1)
        {
            toterr++;
            chk = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check Predecessor BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTPredecessorNRemove(uint &numtest, uint &toterr)
{
    numtest++;

    BST<Data> bst;

    bool chk = false;

    try
    {
        bst.PredecessorNRemove(6);
    }
    catch (...)
    {
        chk = true;
    }

    List<Data> lst;

    lst.Insert(5);
    lst.Insert(2);
    lst.Insert(1);
    lst.Insert(-1);
    lst.Insert(7);
    lst.Insert(4);
    lst.Insert(6);
    lst.Insert(3);
    lst.Insert(-3);
    lst.Insert(8);

    BST<Data> bst2(lst);

    try
    {
        bst2.PredecessorNRemove(-3);
    }
    catch (...)
    {
        chk &= true;
    }

    try
    {

        if (chk && bst2.PredecessorNRemove(9) != 8)
        {
            toterr++;
            chk = false;
        }

        if (chk && bst2.PredecessorNRemove(-2) != -3)
        {
            toterr++;
            chk = false;
        }

        if (chk && bst2.PredecessorNRemove(0) != -1)
        {
            toterr++;
            chk = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check PredecessorNRemove BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTRemovePredecessor(uint &numtest, uint &toterr)
{
    numtest++;

    BST<Data> bst;

    bool chk = false;

    try
    {
        bst.RemovePredecessor(6);
    }
    catch (...)
    {
        chk = true;
    }

    List<Data> lst;

    lst.Insert(5);
    lst.Insert(2);
    lst.Insert(1);
    lst.Insert(-1);
    lst.Insert(7);
    lst.Insert(4);
    lst.Insert(5);
    lst.Insert(6);
    lst.Insert(3);
    lst.Insert(-3);
    lst.Insert(8);

    BST<Data> bst2(lst);

    try
    {

        try
        {
            bst2.RemovePredecessor(-4);
        }
        catch (...)
        {
            chk &= true;
        }

        bst2.RemovePredecessor(9);

        if (chk && bst2.Exists(8))
        {
            toterr++;
            chk = false;
        }

        bst2.RemovePredecessor(-2);

        if (chk && bst2.Exists(-3))
        {
            toterr++;
            chk = false;
        }

        bst2.RemovePredecessor(0);

        if (chk && bst2.Exists(-1))
        {
            toterr++;
            chk = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check RemovePredecessor BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTMemberFunctionDictionary(uint &numtest, uint &toterr)
{
    CheckBSTInsertCopy<Data>(numtest, toterr);
    CheckBSTInsertMove<Data>(numtest, toterr);
    CheckBSTRemove<Data>(numtest, toterr);
}

template <typename Data>
void CheckBSTInsertCopy(uint &numtest, uint &toterr)
{
    numtest++;

    BST<Data> bst;
    List<Data> lst;
    Vector<Data> vec(100);

    bool chk = true;
    Data elem = 0;

    try
    {
        while (lst.Size() < 100)
        {
            lst.InsertAtBack(GenerateIntRange(1, 100));
        }

        uint index = 0;

        while (lst.Size() != 0)
        {
            elem = lst.FrontNRemove();

            if (bst.Insert(elem))
                vec[index++] = elem;
        }

        for (uint i = 0; i < index; ++i)
        {
            chk &= !bst.Insert(vec[i]);
        }

        elem = 101;

        chk &= bst.Insert(elem);
        chk &= !bst.Insert(elem);

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check InsertCopy BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTInsertMove(uint &numtest, uint &toterr)
{
    numtest++;

    BST<Data> bst;
    List<Data> lst;
    Vector<Data> vec(100);

    bool chk = true;
    Data elem = 0;
    Data melem = 0;

    try
    {
        while (lst.Size() < 100)
        {
            lst.InsertAtBack(GenerateIntRange(1, 100));
        }

        uint index = 0;

        while (lst.Size() != 0)
        {
            elem = lst.FrontNRemove();
            melem = elem;

            if (bst.Insert(move(melem)))
            {
                vec[index++] = elem;
            }
        }

        for (uint i = 0; i < index; ++i)
        {
            chk &= !bst.Exists(vec[index]);
        }

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check InsertMove BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTRemove(uint &numtest, uint &toterr)
{
    numtest++;

    BST<Data> bst;
    List<Data> lst;
    Vector<Data> vec(100);

    bool chk = true;
    Data elem = 0;

    try
    {
        while (lst.Size() < 100)
        {
            lst.InsertAtBack(GenerateIntRange(1, 100));
        }

        uint index = 0;

        while (lst.Size() != 0)
        {
            elem = lst.FrontNRemove();

            if (bst.Insert(elem))
                vec[index++] = elem;
        }

        chk &= !bst.Remove(101);
        chk &= !bst.Remove(102);
        chk &= !bst.Remove(103);

        for (uint i = 0; i < index; ++i)
        {
            chk &= bst.Remove(vec[i]);
        }

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check Remove BST " << " TOT Error: " << toterr << endl;
}

// function BST Traverse Rircorsive & Iterative

template <typename Data>
void CheckBSTFunctionTraverse(uint &numtest, uint &toterr)
{
    List<Data> lst;

    lst.InsertAtBack(25);
    lst.InsertAtBack(15);
    lst.InsertAtBack(50);
    lst.InsertAtBack(8);
    lst.InsertAtBack(12);
    lst.InsertAtBack(40);
    lst.InsertAtBack(52);
    lst.InsertAtBack(6);
    lst.InsertAtBack(9);
    lst.InsertAtBack(14);
    lst.InsertAtBack(30);
    lst.InsertAtBack(42);
    lst.InsertAtBack(51);
    lst.InsertAtBack(58);
    lst.InsertAtBack(5);
    lst.InsertAtBack(7);
    lst.InsertAtBack(10);
    lst.InsertAtBack(13);
    lst.InsertAtBack(35);
    lst.InsertAtBack(48);
    lst.InsertAtBack(3);
    lst.InsertAtBack(11);
    lst.InsertAtBack(36);
    lst.InsertAtBack(46);
    lst.InsertAtBack(1);
    lst.InsertAtBack(4);

    BST<Data> bst(lst);

    CheckBSTTraverse<Data>(bst, numtest, toterr);
    CheckBSTPreOrderTraverse<Data>(bst, numtest, toterr);
    CheckBSTInOrderTraverse<Data>(bst, numtest, toterr);
    CheckBSTPostOrderTraverse<Data>(bst, numtest, toterr);
    CheckBSTBreadthTraverse<Data>(bst, numtest, toterr);
}

template <typename Data>
void CheckBSTTraverse(BST<Data> &bst, uint &numtest, uint &toterr)
{
    numtest++;

    Data vec[26] = {25, 15, 8, 6, 5, 3, 1, 4, 7, 12, 9, 10, 11, 14, 13, 50, 40, 30, 35, 36, 42, 48, 46, 52, 51, 58};

    bool chk = true;

    uint index = 0;

    try
    {
        bst.Traverse([&chk, &vec, &index](const Data dat)
                     { chk &= vec[index++] == dat; });

        if (!chk)
        {
            toterr++;
            chk = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check Traverse BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTPreOrderTraverse(BST<Data> &bst, uint &numtest, uint &toterr)
{
    numtest++;

    Data vec[26] = {25, 15, 8, 6, 5, 3, 1, 4, 7, 12, 9, 10, 11, 14, 13, 50, 40, 30, 35, 36, 42, 48, 46, 52, 51, 58};

    bool chk = true;

    uint index = 0;

    try
    {
        BTPreOrderIterator<Data> itr(bst);

        bst.PreOrderTraverse([&chk, &vec, &index, &itr](const Data dat)
                             { chk &= (vec[index++] == dat) && (dat == *itr);
                             ++itr; });

        if (!chk)
        {
            toterr++;
            chk = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check PreOrderTraverse BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTInOrderTraverse(BST<Data> &bst, uint &numtest, uint &toterr)
{
    numtest++;

    Data vec[26] = {1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 25, 30, 35, 36, 40, 42, 46, 48, 50, 51, 52, 58};

    bool chk = true;

    uint index = 0;

    try
    {
        BTInOrderIterator<Data> itr(bst);

        bst.InOrderTraverse([&chk, &vec, &index, &itr](const Data dat)
                            { chk &= (vec[index++] == dat) && (dat == *itr);
                            ++itr; });

        if (!chk)
        {
            toterr++;
            chk = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check InOrderTraverse BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTPostOrderTraverse(BST<Data> &bst, uint &numtest, uint &toterr)
{
    numtest++;

    Data vec[26] = {1, 4, 3, 5, 7, 6, 11, 10, 9, 13, 14, 12, 8, 15, 36, 35, 30, 46, 48, 42, 40, 51, 58, 52, 50, 25};

    bool chk = true;

    uint index = 0;

    try
    {
        BTPostOrderIterator<Data> itr(bst);

        bst.PostOrderTraverse([&chk, &vec, &index, &itr](const Data dat)
                              { chk &= (vec[index++] == dat) && (dat == *itr);
                            ++itr; });

        if (!chk)
        {
            toterr++;
            chk = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check PostOrderTraverse BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTBreadthTraverse(BST<Data> &bst, uint &numtest, uint &toterr)
{
    numtest++;

    Data vec[26] = {25, 15, 50, 8, 40, 52, 6, 12, 30, 42, 51, 58, 5, 7, 9, 14, 35, 48, 3, 10, 13, 36, 46, 1, 4, 11};

    bool chk = true;

    uint index = 0;

    try
    {
        BTBreadthIterator<Data> itr(bst);

        bst.BreadthTraverse([&chk, &vec, &index, &itr](const Data dat)
                            { chk &= (vec[index++] == dat) && (dat == *itr);
                            ++itr; });

        if (!chk)
        {
            toterr++;
            chk = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check BreadthTraverse BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTFunctionMap(uint &numtest, uint &toterr)
{
    List<Data> lst;

    lst.InsertAtBack(25);
    lst.InsertAtBack(15);
    lst.InsertAtBack(50);
    lst.InsertAtBack(8);
    lst.InsertAtBack(12);
    lst.InsertAtBack(40);
    lst.InsertAtBack(52);
    lst.InsertAtBack(6);
    lst.InsertAtBack(9);
    lst.InsertAtBack(14);
    lst.InsertAtBack(30);
    lst.InsertAtBack(42);
    lst.InsertAtBack(51);
    lst.InsertAtBack(58);
    lst.InsertAtBack(5);
    lst.InsertAtBack(7);
    lst.InsertAtBack(10);
    lst.InsertAtBack(13);
    lst.InsertAtBack(35);
    lst.InsertAtBack(48);
    lst.InsertAtBack(3);
    lst.InsertAtBack(11);
    lst.InsertAtBack(36);
    lst.InsertAtBack(46);
    lst.InsertAtBack(1);
    lst.InsertAtBack(4);

    BST<Data> bst(lst);

    CheckBSTMap<Data>(bst, numtest, toterr);
    CheckBSTPreOrderMap<Data>(bst, numtest, toterr);
    CheckBSTInOrderMap<Data>(bst, numtest, toterr);
    CheckBSTPostOrderMap<Data>(bst, numtest, toterr);
    CheckBSTBreadthMap<Data>(bst, numtest, toterr);
}

template <typename Data>
void CheckBSTMap(BST<Data> &bst, uint &numtest, uint &toterr)
{
    numtest++;

    Data vec[26] = {25, 15, 8, 6, 5, 3, 1, 4, 7, 12, 9, 10, 11, 14, 13, 50, 40, 30, 35, 36, 42, 48, 46, 52, 51, 58};

    uint index = 0;
    bool chk = true;

    try
    {
        bst.Map([](Data &dat)
                { dat = dat * 2; });

        bst.Traverse([&vec, &index, &chk](const Data dat)
                     { chk &= ((vec[index] * 2) == dat);
                     index++; });

        if (!chk)
        {
            toterr++;
            chk = false;
        }
    }

    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check Map BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTPreOrderMap(BST<Data> &bst, uint &numtest, uint &toterr)
{
    numtest++;

    Data vec[26] = {25, 15, 8, 6, 5, 3, 1, 4, 7, 12, 9, 10, 11, 14, 13, 50, 40, 30, 35, 36, 42, 48, 46, 52, 51, 58};

    uint index = 0;
    bool chk = true;

    try
    {

        bst.PreOrderMap([](Data &dat)
                        { dat = dat / 2; });

        bst.PreOrderTraverse([&vec, &index, &chk](const Data dat)
                             { chk &= ((vec[index]) == dat);
                     index++; });

        if (!chk)
        {
            toterr++;
            chk = false;
        }
    }

    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check PreOrderMap BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTInOrderMap(BST<Data> &bst, uint &numtest, uint &toterr)
{
    numtest++;

    Data vec[26] = {1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 25, 30, 35, 36, 40, 42, 46, 48, 50, 51, 52, 58};

    uint index = 0;
    bool chk = true;

    try
    {
        bst.InOrderMap([](Data &dat)
                       { dat = dat * 2; });

        bst.InOrderTraverse([&vec, &index, &chk](const Data dat)
                            { chk &= ((vec[index] * 2) == dat);
                     index++; });

        if (!chk)
        {
            toterr++;
            chk = false;
        }
    }

    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check InOrderMap BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTPostOrderMap(BST<Data> &bst, uint &numtest, uint &toterr)
{
    numtest++;

    Data vec[26] = {1, 4, 3, 5, 7, 6, 11, 10, 9, 13, 14, 12, 8, 15, 36, 35, 30, 46, 48, 42, 40, 51, 58, 52, 50, 25};

    uint index = 0;
    bool chk = true;

    try
    {
        bst.PostOrderMap([](Data &dat)
                         { dat = dat / 2; });

        bst.PostOrderTraverse([&vec, &index, &chk](const Data dat)
                              { chk &= ((vec[index]) == dat);
                     index++; });

        if (!chk)
        {
            toterr++;
            chk = false;
        }
    }

    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check PostOrderMap BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTBreadthMap(BST<Data> &bst, uint &numtest, uint &toterr)
{
    numtest++;

    Data vec[26] = {25, 15, 50, 8, 40, 52, 6, 12, 30, 42, 51, 58, 5, 7, 9, 14, 35, 48, 3, 10, 13, 36, 46, 1, 4, 11};

    uint index = 0;
    bool chk = true;

    try
    {
        bst.BreadthMap([](Data &dat)
                       { dat = dat * 2; });

        bst.BreadthTraverse([&vec, &index, &chk](const Data dat)
                            { chk &= ((vec[index] * 2) == dat);
                     index++; });

        if (!chk)
        {
            toterr++;
            chk = false;
        }
    }

    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check BreadthMap BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTFunctionFold(uint &numtest, uint &toterr)
{
    List<Data> lst;

    lst.InsertAtBack(25);
    lst.InsertAtBack(15);
    lst.InsertAtBack(50);
    lst.InsertAtBack(8);
    lst.InsertAtBack(12);
    lst.InsertAtBack(40);
    lst.InsertAtBack(52);
    lst.InsertAtBack(6);
    lst.InsertAtBack(9);
    lst.InsertAtBack(14);
    lst.InsertAtBack(30);
    lst.InsertAtBack(42);
    lst.InsertAtBack(51);
    lst.InsertAtBack(58);
    lst.InsertAtBack(5);
    lst.InsertAtBack(7);
    lst.InsertAtBack(10);
    lst.InsertAtBack(13);
    lst.InsertAtBack(35);
    lst.InsertAtBack(48);
    lst.InsertAtBack(3);
    lst.InsertAtBack(11);
    lst.InsertAtBack(36);
    lst.InsertAtBack(46);
    lst.InsertAtBack(1);
    lst.InsertAtBack(4);

    BST<Data> bst(lst);

    CheckBSTFold<Data>(bst, numtest, toterr);
    CheckBSTPreOrderFold<Data>(bst, numtest, toterr);
    CheckBSTInOrderFold<Data>(bst, numtest, toterr);
    CheckBSTPostOrderFold<Data>(bst, numtest, toterr);
    CheckBSTBreadthFold<Data>(bst, numtest, toterr);
}

template <typename Data>
void CheckBSTFold(BST<Data> &bst, uint &numtest, uint &toterr)
{
    numtest++;

    uint val = 0;

    try
    {
        val = bst.Fold(&FoldTotal<Data>, 0);

        val = 631 % 100;

        if (val != 31)
        {
            toterr++;
        }
    }

    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check Fold BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTPreOrderFold(BST<Data> &bst, uint &numtest, uint &toterr)
{
    numtest++;

    uint val = 0;

    try
    {
        val = bst.PreOrderFold(&FoldTotal<Data>, 0);

        val = 631 % 100;

        if (val != 31)
        {
            toterr++;
        }
    }

    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check PreOrderFold BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTInOrderFold(BST<Data> &bst, uint &numtest, uint &toterr)
{
    numtest++;

    uint val = 0;

    try
    {
        val = bst.InOrderFold(&FoldTotal<Data>, 0);

        val = 631 % 100;

        if (val != 31)
        {
            toterr++;
        }
    }

    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check InOrderFold BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTPostOrderFold(BST<Data> &bst, uint &numtest, uint &toterr)
{
    numtest++;

    uint val = 0;

    try
    {
        val = bst.PostOrderFold(&FoldTotal<Data>, 0);

        val = 631 % 100;

        if (val != 31)
        {
            toterr++;
        }
    }

    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check PostOrderFold BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBSTBreadthFold(BST<Data> &bst, uint &numtest, uint &toterr)
{
    numtest++;

    uint val = 0;

    try
    {
        val = bst.BreadthFold(&FoldTotal<Data>, 0);

        val = 631 % 100;

        if (val != 31)
        {
            toterr++;
        }
    }

    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check BreadthFold BST " << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBTIterator(uint &numtest, uint &toterr)
{
    List<Data> lst;

    lst.InsertAtBack(25);
    lst.InsertAtBack(15);
    lst.InsertAtBack(50);
    lst.InsertAtBack(8);
    lst.InsertAtBack(12);
    lst.InsertAtBack(40);
    lst.InsertAtBack(52);
    lst.InsertAtBack(6);
    lst.InsertAtBack(9);
    lst.InsertAtBack(14);
    lst.InsertAtBack(30);
    lst.InsertAtBack(42);
    lst.InsertAtBack(51);
    lst.InsertAtBack(58);
    lst.InsertAtBack(5);
    lst.InsertAtBack(7);
    lst.InsertAtBack(10);
    lst.InsertAtBack(13);
    lst.InsertAtBack(35);
    lst.InsertAtBack(48);
    lst.InsertAtBack(3);
    lst.InsertAtBack(11);
    lst.InsertAtBack(36);
    lst.InsertAtBack(46);
    lst.InsertAtBack(1);
    lst.InsertAtBack(4);
    lst.InsertAtBack(61);
    lst.InsertAtBack(59);
    lst.InsertAtBack(76);
    lst.InsertAtBack(80);
    lst.InsertAtBack(53);
    lst.InsertAtBack(91);
    lst.InsertAtBack(17);
    lst.InsertAtBack(31);
    lst.InsertAtBack(42);
    lst.InsertAtBack(51);
    lst.InsertAtBack(58);
    lst.InsertAtBack(63);
    lst.InsertAtBack(71);
    lst.InsertAtBack(23);
    lst.InsertAtBack(100);
    lst.InsertAtBack(33);
    lst.InsertAtBack(49);
    lst.InsertAtBack(19);
    lst.InsertAtBack(87);

    BinaryTreeLnk<Data> btl(lst);

    CheckBTPreIterator<Data>(btl, numtest, toterr);
    CheckBTInIterator<Data>(btl, numtest, toterr);
    CheckBTPostIterator<Data>(btl, numtest, toterr);
    CheckBTBreadthIterator<Data>(btl, numtest, toterr);
}

template <typename Data>
void CheckBTPreIterator(BinaryTree<Data> &bt, uint &numtest, uint &toterr)
{
    numtest++;

    Data vec[45] = {25, 15, 8, 6, 7, 91, 17, 10, 31, 42, 9, 13, 51, 58, 35, 63, 71, 12, 14,
                    48, 23, 100, 3, 33, 49, 30, 11, 19, 87, 36, 50, 40, 42, 46, 1, 51, 4, 61,
                    52, 58, 59, 76, 5, 80, 53};

    bool chk = true;

    uint index = 0;

    try
    {
        BTPreOrderIterator<Data> itr(bt);

        while (!itr.Terminated())
        {
            chk &= vec[index++] == *itr;
            ++itr;
        }

        try
        {
            ++itr;
        }
        catch (...)
        {
            chk &= true;
        }

        try
        {
            *itr;
        }
        catch (...)
        {
            chk &= true;
        }

        itr.Reset();

        index = 0;

        bt.PreOrderTraverse([&chk, &vec, &index, &itr](const Data dat)
                            { chk &= (vec[index++] == dat) && (dat == *itr);
                             ++itr; });

        if (!chk)
        {
            toterr++;
            chk = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check PreIterator" << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBTInIterator(BinaryTree<Data> &bt, uint &numtest, uint &toterr)
{
    numtest++;

    Data vec[45] = {91, 7, 17, 6, 31, 10, 42, 8, 51, 13, 58, 9, 63, 35, 71, 15, 23, 48, 100,
                    14, 33, 3, 49, 12, 19, 11, 87, 30, 36, 25, 46, 42, 1, 40, 4, 51, 61, 50,
                    59, 58, 76, 52, 80, 5, 53};

    bool chk = true;

    uint index = 0;

    try
    {

        BTInOrderIterator<Data> itr(bt);

        while (!itr.Terminated())
        {
            chk &= vec[index++] == *itr;
            ++itr;
        }

        try
        {
            ++itr;
        }
        catch (...)
        {
            chk &= true;
        }

        try
        {
            *itr;
        }
        catch (...)
        {
            chk &= true;
        }

        itr.Reset();

        index = 0;

        bt.InOrderTraverse([&chk, &vec, &index, &itr](const Data dat)
                           { chk &= (vec[index++] == dat) && (dat == *itr);
                             ++itr; });

        if (!chk)
        {
            toterr++;
            chk = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check InIterator" << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBTPostIterator(BinaryTree<Data> &bt, uint &numtest, uint &toterr)
{
    numtest++;

    Data vec[45] = {91, 17, 7, 31, 42, 10, 6, 51, 58, 13, 63, 71, 35, 9, 8, 23, 100, 48,
                    33, 49, 3, 14, 19, 87, 11, 36, 30, 12, 15, 46, 1, 42, 4, 61, 51, 40,
                    59, 76, 58, 80, 53, 5, 52, 50, 25};

    bool chk = true;

    uint index = 0;

    try
    {

        BTPostOrderIterator<Data> itr(bt);

        while (!itr.Terminated())
        {
            chk &= vec[index++] == *itr;
            ++itr;
        }

        try
        {
            ++itr;
        }
        catch (...)
        {
            chk &= true;
        }

        try
        {
            *itr;
        }
        catch (...)
        {
            chk &= true;
        }

        itr.Reset();

        index = 0;

        bt.PostOrderTraverse([&chk, &vec, &index, &itr](const Data dat)
                             { chk &= (vec[index++] == dat) && (dat == *itr);
                             ++itr; });

        if (!chk)
        {
            toterr++;
            chk = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check PostIterator" << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBTBreadthIterator(BinaryTree<Data> &bt, uint &numtest, uint &toterr)
{
    numtest++;

    Data vec[45] = {25, 15, 50, 8, 12, 40, 52, 6, 9, 14, 30, 42, 51, 58, 5, 7, 10, 13, 35, 48, 3, 11, 36, 46, 1, 4, 61, 59, 76, 80, 53, 91, 17, 31, 42, 51, 58, 63, 71, 23, 100, 33, 49, 19, 87};

    bool chk = true;

    uint index = 0;

    try
    {

        BTBreadthIterator<Data> itr(bt);

        while (!itr.Terminated())
        {
            chk &= vec[index++] == *itr;
            ++itr;
        }

        try
        {
            ++itr;
        }
        catch (...)
        {
            chk &= true;
        }

        try
        {
            *itr;
        }
        catch (...)
        {
            chk &= true;
        }

        itr.Reset();

        index = 0;

        bt.BreadthTraverse([&chk, &vec, &index, &itr](const Data dat)
                           { chk &= (vec[index++] == dat) && (dat == *itr);
                             ++itr; });

        if (!chk)
        {
            toterr++;
            chk = false;
        }
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check BreadthIterator" << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBTMutableIterator(uint &numtest, uint &toterr)
{
    List<Data> lst;

    lst.InsertAtBack(25);
    lst.InsertAtBack(15);
    lst.InsertAtBack(5);
    lst.InsertAtBack(8);
    lst.InsertAtBack(12);
    lst.InsertAtBack(4);

    BinaryTreeVec<Data> btv(lst);

    CheckBTPreOrderMutableIterator<Data>(btv, numtest, toterr);
    CheckBTInOrderMutableIterator<Data>(btv, numtest, toterr);
    CheckBTPostOrderMutableIterator<Data>(btv, numtest, toterr);
    CheckBTBreadthMutableIterator<Data>(btv, numtest, toterr);
}

template <typename Data>
void CheckBTPreOrderMutableIterator(MutableBinaryTree<Data> &btv, uint &numtest, uint &toterr)
{
    numtest++;

    lasd::BTPreOrderMutableIterator<Data> mitr(btv);

    Data vec[6];

    bool chk = true;

    uint index = 0;

    try
    {
        while (!mitr.Terminated())
        {
            vec[index++] = *mitr;
            *mitr = *mitr * 2;
            ++mitr;
        }

        index = 0;

        btv.PreOrderTraverse([&vec, &chk, &index](const Data dat)
                             { chk &= dat == vec[index++] * 2; });
        mitr.Reset();

        while (!mitr.Terminated())
        {
            chk &= *mitr == *mitr;
            ++mitr;
        }

        try
        {
            ++mitr;
        }
        catch (...)
        {
            chk &= true;
        }

        try
        {
            *mitr;
        }
        catch (...)
        {
            chk &= true;
        }

        if (!chk)
        {
            toterr++;
        }
    }
    catch (...)
    {
        toterr++;
        cout << "Warning Error " << endl;
    }

    cout << numtest << " - " << "Check PreOrderMutableIterator" << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBTInOrderMutableIterator(MutableBinaryTree<Data> &btv, uint &numtest, uint &toterr)
{
    numtest++;

    lasd::BTInOrderMutableIterator<Data> mitr(btv);

    Data vec[6];

    bool chk = true;

    uint index = 0;

    try
    {
        while (!mitr.Terminated())
        {
            vec[index++] = *mitr;
            *mitr = *mitr / 2;
            ++mitr;
        }

        index = 0;

        btv.InOrderTraverse([&vec, &chk, &index](const Data dat)
                            { chk &= dat == vec[index++] / 2; });

        mitr.Reset();

        while (!mitr.Terminated())
        {
            chk &= *mitr == *mitr;
            ++mitr;
        }

        try
        {
            ++mitr;
        }
        catch (...)
        {
            chk &= true;
        }

        try
        {
            *mitr;
        }
        catch (...)
        {
            chk &= true;
        }

        if (!chk)
        {
            toterr++;
        }
    }
    catch (...)
    {
        toterr++;
        cout << "Warning Error " << endl;
    }

    cout << numtest << " - " << "Check InOrderMutableIterator" << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBTPostOrderMutableIterator(MutableBinaryTree<Data> &btv, uint &numtest, uint &toterr)
{
    numtest++;

    lasd::BTPostOrderMutableIterator<Data> mitr(btv);

    Data vec[6];

    bool chk = true;

    uint index = 0;

    try
    {
        while (!mitr.Terminated())
        {
            vec[index++] = *mitr;
            *mitr = *mitr * 2;
            ++mitr;
        }

        index = 0;

        btv.PostOrderTraverse([&vec, &chk, &index](const Data dat)
                              { chk &= dat == vec[index++] * 2; });

        mitr.Reset();

        while (!mitr.Terminated())
        {
            chk &= *mitr == *mitr;
            ++mitr;
        }

        try
        {
            ++mitr;
        }
        catch (...)
        {
            chk &= true;
        }

        try
        {
            *mitr;
        }
        catch (...)
        {
            chk &= true;
        }

        if (!chk)
        {
            toterr++;
        }
    }
    catch (...)
    {
        toterr++;
        cout << "Warning Error " << endl;
    }

    cout << numtest << " - " << "Check PostOrderMutableIterator" << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBTBreadthMutableIterator(MutableBinaryTree<Data> &btv, uint &numtest, uint &toterr)
{
    numtest++;

    lasd::BTBreadthMutableIterator<Data> mitr(btv);

    Data vec[6];

    bool chk = true;

    uint index = 0;

    try
    {
        while (!mitr.Terminated())
        {
            vec[index++] = *mitr;
            *mitr = *mitr / 2;
            ++mitr;
        }

        index = 0;

        btv.BreadthTraverse([&vec, &chk, &index](const Data dat)
                            { chk &= dat == vec[index++] / 2; });

        mitr.Reset();

        while (!mitr.Terminated())
        {
            chk &= *mitr == *mitr;
            ++mitr;
        }

        try
        {
            ++mitr;
        }
        catch (...)
        {
            chk &= true;
        }

        try
        {
            *mitr;
        }
        catch (...)
        {
            chk &= true;
        }

        if (!chk)
        {
            toterr++;
        }
    }
    catch (...)
    {
        toterr++;
        cout << "Warning Error " << endl;
    }

    cout << numtest << " - " << "Check BreadthMutableIterator" << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBTIteratorAssignment(uint &numtest, uint &toterr)
{
    List<Data> lst;

    lst.InsertAtBack(25);
    lst.InsertAtBack(15);
    lst.InsertAtBack(50);
    lst.InsertAtBack(8);
    lst.InsertAtBack(12);
    lst.InsertAtBack(40);
    lst.InsertAtBack(52);
    lst.InsertAtBack(6);
    lst.InsertAtBack(9);
    lst.InsertAtBack(14);
    lst.InsertAtBack(30);
    lst.InsertAtBack(42);
    lst.InsertAtBack(51);
    lst.InsertAtBack(58);
    lst.InsertAtBack(5);
    lst.InsertAtBack(7);
    lst.InsertAtBack(10);
    lst.InsertAtBack(13);
    lst.InsertAtBack(35);
    lst.InsertAtBack(48);
    lst.InsertAtBack(3);
    lst.InsertAtBack(11);
    lst.InsertAtBack(36);
    lst.InsertAtBack(46);
    lst.InsertAtBack(1);
    lst.InsertAtBack(4);

    BinaryTreeLnk<Data> btl(lst);

    CheckBTIteratorAssignmentCopy<Data>(btl, numtest, toterr);
    CheckBTIteratorAssignmentMove(btl, numtest, toterr);
}

template <typename Data>
void CheckBTIteratorAssignmentCopy(BinaryTreeLnk<Data> &btl, uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    BinaryTreeVec<Data> tmpbt;
    BinaryTreeLnk<Data> tmpbtv;

    try
    {
        BTPreOrderIterator<Data> preitr(btl);
        BTPreOrderIterator<Data> preitr2(tmpbt);

        preitr2 = preitr;

        while (!preitr.Terminated())
        {

            if (chk && (*preitr != *preitr2))
            {
                chk = false;
            }

            ++preitr;
            ++preitr2;
        }

        BTPostOrderIterator<Data> postitr(btl);
        BTPostOrderIterator<Data> postitr2(tmpbt);

        postitr2 = postitr;

        while (!postitr.Terminated())
        {
            if (chk && (*postitr != *postitr2))
            {
                chk = false;
            }

            ++postitr;
            ++postitr2;
        }

        BTInOrderIterator<Data> initr(btl);
        BTInOrderIterator<Data> initr2(tmpbt);

        initr2 = initr;

        while (!initr.Terminated())
        {
            if (*initr != *initr2)
            {
                chk = false;
            }

            ++initr;
            ++initr2;
        }

        BTInOrderIterator<Data> initr3(tmpbt);

        initr2 = initr3;

        if (!initr2.Terminated())
        {
            chk = false;
        }

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check BTIteratorAssignmetCopy" << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBTIteratorAssignmentMove(BinaryTreeLnk<Data> &btl, uint &numtest, uint &toterr)
{
    numtest++;

    bool chk = true;

    BinaryTreeVec<Data> tmpbt;
    BinaryTreeLnk<Data> tmpbtv;

    try
    {
        BinaryTreeLnk<Data> tmpbtl(btl);
        BTPreOrderIterator<Data> tmpitr(tmpbtl);

        BTPreOrderIterator<Data> preitr(btl);
        BTPreOrderIterator<Data> preitr2(tmpbt);

        preitr2 = move(preitr);

        while (!preitr2.Terminated())
        {

            if (chk && (*tmpitr != *preitr2))
            {
                chk = false;
            }

            ++tmpitr;
            ++preitr2;
        }

        BTPostOrderIterator<Data> tmpitr2(tmpbtl);

        BTPostOrderIterator<Data> postitr(btl);
        BTPostOrderIterator<Data> postitr2(tmpbt);

        postitr2 = move(postitr);

        while (!postitr2.Terminated())
        {

            if (chk && (*tmpitr2 != *postitr2))
            {
                chk = false;
            }

            ++tmpitr2;
            ++postitr2;
        }

        BTInOrderIterator<Data> tmpitr3(tmpbtl);

        BTInOrderIterator<Data> initr(btl);
        BTInOrderIterator<Data> initr2(tmpbt);

        initr2 = move(initr);

        while (!initr2.Terminated())
        {

            if (chk && (*tmpitr3 != *initr2))
            {
                chk = false;
            }

            ++tmpitr3;
            ++initr2;
        }

        BTBreadthIterator<Data> tmpitr4(tmpbtl);

        BTBreadthIterator<Data> breadthitr(btl);
        BTBreadthIterator<Data> breadthitr2(tmpbt);

        breadthitr2 = move(breadthitr);

        while (!breadthitr2.Terminated())
        {

            if (chk && (*tmpitr4 != *breadthitr2))
            {
                chk = false;
            }

            ++tmpitr4;
            ++breadthitr2;
        }

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check BTIteratorAssignmetMove" << " TOT Error: " << toterr << endl;
}

template <typename Data>
void CheckBTIteratorConstructors(uint &numtest, uint &toterr)
{
    numtest++;

    List<Data> lst;

    lst.InsertAtBack(25);
    lst.InsertAtBack(15);
    lst.InsertAtBack(50);
    lst.InsertAtBack(8);
    lst.InsertAtBack(12);
    lst.InsertAtBack(40);
    lst.InsertAtBack(52);
    lst.InsertAtBack(6);

    BinaryTreeLnk<Data> btl(lst);

    bool chk = true;

    try
    {
        BTPreOrderIterator<Data> itr(btl);
        BTPreOrderIterator<Data> itr2(itr);
        BTPreOrderIterator<Data> itr3(move(itr2));

        while (!itr.Terminated())
        {

            chk &= *itr == *itr3;

            ++itr;
            ++itr3;
        }

        BTPostOrderIterator<Data> postitr(btl);
        BTPostOrderIterator<Data> postitr2(postitr);
        BTPostOrderIterator<Data> postitr3(move(postitr2));

        while (!postitr.Terminated())
        {

            chk &= *postitr == *postitr3;

            ++postitr;
            ++postitr3;
        }

        BTInOrderIterator<Data> initr(btl);
        BTInOrderIterator<Data> initr2(initr);
        BTInOrderIterator<Data> initr3(move(initr2));

        while (!initr.Terminated())
        {

            chk &= *initr == *initr3;

            ++initr;
            ++initr3;
        }

        if (!chk)
            toterr++;
    }
    catch (...)
    {
        cout << "Warning Error" << endl;
        toterr++;
    }

    cout << numtest << " - " << "Check BTIteratorContructors" << " TOT Error: " << toterr << endl;
}

/* ************************************************************************** */
/* *************************** EXERCISE 1 *********************************** */
/* ************************************************************************** */

// Popular with map function
template <typename Data>
void PopularVectorData(Vector<Data> &vec, const uint &dim)
{
    Vector<Data> tmpvec(dim);

    vec = move(tmpvec);

    vec.Map(&MyInsertData<Data>);
}

// Popular with map function vector of words
void PopularVectorString(Vector<string> &vec, const uint &dim)
{
    Vector<string> tmpvec(dim);

    vec = move(tmpvec);

    vec.Map(&MyInsertStringData<string>);
}

template <typename Data>
void PopularDataList(List<Data> &con, const uint &dim)
{
    Vector<Data> tmp(dim);

    List<Data> tmplst(move(tmp));

    con = move(tmplst);

    con.Map(&MyInsertData<Data>);
}

template <typename Data>
void PopularDataListString(List<Data> &con, const uint &dim)
{
    Vector<Data> tmp(dim);

    List<Data> tmplst(move(tmp));

    con = move(tmplst);

    con.Map(&MyInsertStringData<string>);
}

template <typename Data>
void PopularDataQueueLst(QueueLst<Data> &con, const uint &dim)
{

    List<Data> tmplst;

    PopularDataList(tmplst, dim);

    con = move(tmplst);
}

template <typename Data>
void PopularDataQueueLstString(QueueLst<Data> &con, const uint &dim)
{
    List<Data> tmplst;

    PopularDataListString(tmplst, dim);

    con = move(tmplst);
}

template <typename Data>
void PopularDataQueueVec(QueueVec<Data> &con, const uint &dim)
{

    List<Data> tmplst;

    PopularDataList(tmplst, dim);

    con = move(tmplst);
}

template <typename Data>
void PopularDataQueueVecString(QueueVec<Data> &con, const uint &dim)
{
    List<Data> tmplst;

    PopularDataListString(tmplst, dim);

    con = move(tmplst);
}

template <typename Data>
void PopularDataStackLst(StackLst<Data> &con, const uint &dim)
{

    List<Data> tmplst;

    PopularDataList(tmplst, dim);

    con = move(tmplst);
}

template <typename Data>
void PopularDataStackLstString(StackLst<Data> &con, const uint &dim)
{
    List<Data> tmplst;

    PopularDataListString(tmplst, dim);

    con = move(tmplst);
}

template <typename Data>
void PopularDataStackVec(StackVec<Data> &con, const uint &dim)
{

    List<Data> tmplst;

    PopularDataList(tmplst, dim);

    con = move(tmplst);
}

template <typename Data>
void PopularDataStackVecString(StackVec<Data> &con, const uint &dim)
{
    List<Data> tmplst;

    PopularDataListString(tmplst, dim);

    con = move(tmplst);
}

/* *************************************************************************** */

// Counter function with traverse
template <typename Data>
uint CounterDataLinearContainer(const LinearContainer<Data> &con)
{
    uint counter = 0;

    con.Traverse([&counter](const Data &dat)
                 { counter++; });

    return move(counter);
}

/* *************************************************************************** */

// Fold accumulation add
template <typename Data>
Data AccumulationDataLinearContainer(const LinearContainer<Data> &con)
{
    return con.Fold(&FoldTotal<Data>, 0);
}

// Fold Counter Accumulation
template <typename Data>
Data CounterFoldLinearContainer(const LinearContainer<Data> &con)
{
    return con.Fold(&MyFoldCount<Data>, 0);
}

/* *************************************************************************** */

// Print Stack&Queue
template <typename Data>
void PrintStackLst(const StackLst<Data> &con)
{

    StackLst<Data> tmpstk(con);

    ulong dim = tmpstk.Size();

    for (ulong index = 0; index < dim; index++)
    {
        cout << tmpstk.TopNPop() << " ";
    }
}

template <typename Data>
void PrintStackVec(const StackVec<Data> &con)
{

    StackVec<Data> tmpstk(con);

    ulong dim = tmpstk.Size();

    for (ulong index = 0; index < dim; index++)
    {
        cout << tmpstk.TopNPop() << " ";
    }
}

template <typename Data>
void PrintQueueLst(const QueueLst<Data> &con)
{

    QueueLst<Data> tmpque(con);

    ulong dim = tmpque.Size();

    for (ulong index = 0; index < dim; index++)
    {
        cout << tmpque.HeadNDequeue() << " ";
    }
}

template <typename Data>
void PrintQueueVec(const QueueVec<Data> &con)
{

    QueueVec<Data> tmpque(con);

    ulong dim = tmpque.Size();

    for (ulong index = 0; index < dim; index++)
    {
        cout << tmpque.HeadNDequeue() << " ";
    }
}

/* *************************************************************************** */

// Check function LinearContainer

// check Size() + test traverse
template <typename Data>
void CheckSize(const LinearContainer<Data> &con, uint &err, uint &numtest)
{
    ++numtest;

    cout << "TEST '" << numtest << "' ";

    (CounterDataLinearContainer(con) == con.Size()) ? cout << "Size Correct "
                                                           << "ERR: " << err << endl
                                                    : cout << "Size Error " << ++err << endl;
}

// check Empty()
template <typename Data>
void CheckEmpty(const LinearContainer<Data> &con, uint &err, uint &numtest)
{
    ++numtest;

    cout << "TEST '" << numtest << "' ";
    ((CounterDataLinearContainer(con) == 0) && (con.Empty())) || ((CounterDataLinearContainer(con) > 0) && !(con.Empty())) ? cout << "Empty Correct"
                                                                                                                                  << "ERR: " << err << endl
                                                                                                                           : cout << "Empty Error " << ++err << endl;
}

// check Clear() (copy vector constructor)
template <typename Data>
void CheckClear(const LinearContainer<Data> &con, uint &err, uint &numtest)
{
    ++numtest;

    Vector<Data> tmpvec(con);
    tmpvec.Clear();

    cout << "TEST '" << numtest << "' ";
    (CounterDataLinearContainer(tmpvec) == 0 && (tmpvec.Empty())) ? cout << "Clear Correct "
                                                                         << "ERR: " << err << endl
                                                                  : cout << "Clear Error " << ++err << endl;
}

// check Comparison Linear Container
template <typename Data>
void CheckComparisonLinearContainer(const LinearContainer<Data> &con, const LinearContainer<Data> &con2, uint &err, uint &numtest)
{
    ++numtest;

    cout << "TEST '" << numtest << "' ";
    if (con != con2)
        con != con2 ? cout << "Operator '!=' Correct "
                           << "ERR: " << err << endl
                    : cout << "Operator '!=' Error " << ++err << endl;
    else
        con == con2 ? cout << "Operator '==' Correct "
                           << "ERR: " << err << endl
                    : cout << "Operator '==' Error " << ++err << endl;
}

// check Comparison with copy & move constructor, copy & move assgnment
template <typename Data>
void CheckEqualsLinearContainer(const LinearContainer<Data> &con, uint &err, uint &numtest)
{
    ++numtest;

    bool chk = true;

    SortableVector<Data> tmpvec(con);
    tmpvec == con &&chk ? chk = true : chk = false;

    SortableVector<Data> tmpvec2(move(con));
    tmpvec2 == con &&chk ? chk = true : chk = false;

    CheckComparisonLinearContainer(tmpvec, tmpvec2, err, numtest);

    tmpvec2 = tmpvec;
    tmpvec == tmpvec2 &&chk ? chk = true : chk = false;

    SortableVector<Data> tmpvec3(con);
    tmpvec3 = move(tmpvec2);
    tmpvec3 == tmpvec &&chk ? chk = true : chk = false;

    CheckComparisonLinearContainer(tmpvec3, tmpvec, err, numtest);

    cout << "TEST '" << numtest << "' ";
    chk ? cout << "Comparison Correct "
               << "ERR: " << err << endl
        : cout << "Comparison Error " << ++err << endl;
}

template <typename Data>
void CheckExistsLinearContainer(uint &err, uint &numtest)
{

    ++numtest;

    bool chk = true;

    SortableVector<Data> sortvec(1000);

    for (uint index = 0; index < sortvec.Size(); index++)
    {
        sortvec.operator[](index) = index + 1;
    }

    for (uint index = 0; index < sortvec.Size() && chk; index++)
    {
        chk &= sortvec.Exists(index + 1);
    }

    sortvec.Clear();

    chk &= !sortvec.Exists(0);

    cout << "TEST '" << numtest << "' ";
    chk ? cout << "Exists Correct "
               << "ERR: " << err << endl
        : cout << "Exists Error " << ++err << endl;
}

void CheckExistsLinearContainerString(uint &err, uint &numtest)
{
    ++numtest;

    bool chk = true;

    Vector<string> tmpvec(1000);
    Vector<string> sortvec(1000);

    for (uint index = 0; index < 1000; index++)
    {
        tmpvec.operator[](index) = GenerateWord(20);
        sortvec.operator[](index) = tmpvec.operator[](index);
    }

    for (uint index = 0; index < 1000 && chk; index++)
    {
        chk &= sortvec.Exists(tmpvec.operator[](index));
    }

    sortvec.Clear();

    chk &= !sortvec.Exists("__stringnotexist__");

    cout << "TEST '" << numtest << "' ";
    chk ? cout << "Exists Correct "
               << "ERR: " << err << endl
        : cout << "Exists Error " << ++err << endl;
}

/* **************************************************************************** */

// check function vector

// check Resize() (Vector)
template <typename Data>
void CheckResize(const Vector<Data> &vec, uint &err, uint &numtest)
{
    ++numtest;

    Vector<Data> tmpvec(vec);

    uint newsize = GenerateUint();

    tmpvec.Resize(newsize);

    cout << "TEST '" << numtest << "' ";
    CounterDataLinearContainer(tmpvec) == newsize ? cout << "Resize Correct "
                                                         << "ERR: " << err << endl
                                                  : cout << "Resize Error " << ++err << endl;
}

/* **************************************************************************** */

// check function member list

// check insertatfront
template <typename Data>
void CheckInserAtFront(List<Data> &lst, uint &err, uint &numtest)
{
    ++numtest;
    cout << "TEST '" << numtest << "' ";

    lst.Clear();
    bool chk = true;

    Data dat1 = GenerateInt();
    Data dat2 = GenerateInt();
    Data dat3 = GenerateInt();

    lst.InsertAtFront(dat1);

    if (lst.Front() == lst.Back() && lst.Size() == 1)
        chk = true;
    else
        chk = false;

    lst.InsertAtFront(dat2);

    if (lst.Front() == dat2 && lst.Back() == dat1 && lst.Size() == 2 && chk)
        chk = true;
    else
        chk = false;

    lst.InsertAtFront(dat3);

    if (lst.Front() == dat3 && lst.Back() == dat1 && lst.Size() == 3 && chk)
        chk = true;
    else
        chk = false;

    chk ? cout << "InsertAtFront "
               << "ERR: " << err << endl
        : cout << "InsertAtFront Error " << ++err << endl;
}

// check insertatfrontmove
template <typename Data>
void CheckInserAtFrontMove(List<Data> &lst, uint &err, uint &numtest)
{
    ++numtest;
    cout << "TEST '" << numtest << "' ";

    lst.Clear();
    bool chk = true;

    Data dat1 = GenerateInt();
    Data dat2 = GenerateInt();
    Data dat3 = GenerateInt();

    Data copydat1 = dat1;
    Data copydat2 = dat2;
    Data copydat3 = dat3;

    lst.InsertAtFront(move(dat1));

    if (lst.Front() == lst.Back() && lst.Size() == 1)
        chk = true;
    else
        chk = false;

    lst.InsertAtFront(move(dat2));

    if (lst.Front() == copydat2 && lst.Back() == copydat1 && lst.Size() == 2 && chk)
        chk = true;
    else
        chk = false;

    lst.InsertAtFront(move(dat3));

    if (lst.Front() == copydat3 && lst.Back() == copydat1 && lst.Size() == 3 && chk)
        chk = true;
    else
        chk = false;

    chk ? cout << "InsertAtFrontMove "
               << "ERR: " << err << endl
        : cout << "InsertAtFrontMove Error " << ++err << endl;
}

// check removefromfront
template <typename Data>
void CheckRemoveFromFront(List<Data> &lst, uint &err, uint &numtest)
{
    ++numtest;

    cout << "TEST '" << numtest << "' ";

    lst.Clear();
    bool chk = false;

    try
    {
        lst.RemoveFromFront();
    }
    catch (...)
    {
        chk = true;
    }

    Data dat1 = GenerateInt();
    Data dat2 = GenerateInt();
    Data dat3 = GenerateInt();

    lst.InsertAtFront(dat1);
    lst.InsertAtFront(dat2);
    lst.RemoveFromFront();

    (lst.Front() == dat1 && chk) ? chk = true : chk = false;

    PopularDataList(lst, 100);

    for (uint index = 0; index < 100; index++)
        lst.RemoveFromFront();

    try
    {
        lst.RemoveFromFront();
    }
    catch (...)
    {
        chk = true;
    }

    lst.InsertAtBack(dat3);
    lst.InsertAtBack(dat2);
    lst.InsertAtBack(dat1);

    (lst.Front() == dat3 && chk) ? chk = true : chk = false;

    lst.RemoveFromFront();
    lst.RemoveFromFront();

    (lst.Front() == dat1 && chk) ? chk = true : chk = false;

    lst.RemoveFromFront();

    try
    {
        lst.RemoveFromFront();
    }
    catch (...)
    {
        chk = true;
    }

    chk
        ? cout << "RemoveFromFront "
               << "ERR: " << err << endl
        : cout << "RemoveFromFront Error " << ++err << endl;
}

// check frontnremove
template <typename Data>
void CheckFrontNRemove(List<Data> &lst, uint &err, uint &numtest)
{
    ++numtest;

    cout << "TEST '" << numtest << "' ";

    lst.Clear();
    bool chk = false;

    try
    {
        lst.FrontNRemove();
    }
    catch (...)
    {
        chk = true;
    }

    Data dat1 = GenerateInt();
    Data dat2 = GenerateInt();

    lst.InsertAtFront(dat1);
    lst.InsertAtFront(dat2);
    Data dat3 = lst.FrontNRemove();

    (lst.Front() == dat1 && chk) ? chk = true : chk = false;
    (dat3 == lst.Front() && chk) ? chk = true : chk = false;

    PopularDataList(lst, 100);

    for (uint index = 0; index < 100; index++)
        lst.FrontNRemove();

    try
    {
        lst.RemoveFromFront();
    }
    catch (...)
    {
        chk = true;
    }

    lst.InsertAtBack(dat3);
    lst.InsertAtBack(dat2);
    lst.InsertAtBack(dat1);

    Data dat4 = lst.FrontNRemove();

    (lst.Front() == dat3 && chk) ? chk = true : chk = false;
    (dat4 == lst.Front() && chk) ? chk = true : chk = false;

    lst.FrontNRemove();

    (lst.Front() == dat1 && chk) ? chk = true : chk = false;

    dat4 = lst.FrontNRemove();
    (dat4 == dat1 && chk) ? chk = true : chk = false;

    try
    {
        lst.FrontNRemove();
    }
    catch (...)
    {
        chk = true;
    }

    chk
        ? cout << "FrontNRemove "
               << "ERR: " << err << endl
        : cout << "FrontNRemove Error " << ++err << endl;
};

// check insertatback
template <typename Data>
void CheckInserAtBack(List<Data> &lst, uint &err, uint &numtest)
{
    ++numtest;
    cout << "TEST '" << numtest << "' ";

    lst.Clear();
    bool chk = true;

    Data dat1 = GenerateInt();
    Data dat2 = GenerateInt();
    Data dat3 = GenerateInt();

    lst.InsertAtBack(dat1);

    if (lst.Front() == lst.Back() && lst.Size() == 1)
        chk = true;
    else
        chk = false;

    lst.InsertAtBack(dat2);

    if (lst.Front() == dat1 && lst.Back() == dat2 && lst.Size() == 2 && chk)
        chk = true;
    else
        chk = false;

    lst.InsertAtBack(dat3);

    if (lst.Front() == dat1 && lst.Back() == dat3 && lst.Size() == 3 && chk)
        chk = true;
    else
        chk = false;

    chk ? cout << "InsertAtBack "
               << "ERR: " << err << endl
        : cout << "InsertAtBack Error " << ++err << endl;
}

// check insertatbackmove
template <typename Data>
void CheckInserAtBackMove(List<Data> &lst, uint &err, uint &numtest)
{
    ++numtest;
    cout << "TEST '" << numtest << "' ";

    lst.Clear();
    bool chk = true;

    Data dat1 = GenerateInt();
    Data dat2 = GenerateInt();
    Data dat3 = GenerateInt();

    Data copydat1 = dat1;
    Data copydat2 = dat2;
    Data copydat3 = dat3;

    lst.InsertAtBack(dat1);

    if (lst.Front() == lst.Back() && lst.Size() == 1)
        chk = true;
    else
        chk = false;

    lst.InsertAtBack(dat2);

    if (lst.Front() == copydat1 && lst.Back() == copydat2 && lst.Size() == 2 && chk)
        chk = true;
    else
        chk = false;

    lst.InsertAtBack(dat3);

    if (lst.Front() == copydat1 && lst.Back() == copydat3 && lst.Size() == 3 && chk)
        chk = true;
    else
        chk = false;

    chk ? cout << "InsertAtBackMove "
               << "ERR: " << err << endl
        : cout << "InsertAtBackMove Error " << ++err << endl;
};

/* **************************************************************************** */

// member function Dictionary

template <typename Data>
void CheckInsert(List<Data> &lst, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    for (uint index = 0; index < 100; index++)
    {
        chk = lst.Insert(Data(index));
    }

    for (uint index = 0; index < 100 && chk; index++)
    {
        chk = (lst.Insert(Data(50)) == !chk);
    }

    for (uint index = 0; index < 100 && chk; index++)
    {
        chk = (lst.Insert(Data(101 + index)) == chk);
    }

    lst.Clear();

    chk ? cout << "Insert "
               << "ERR: " << err << endl
        : cout << "Insert Error " << ++err << endl;
}

template <typename Data>
void CheckInsertMove(List<Data> &lst, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    for (uint index = 0; index < 100; index++)
    {
        chk = lst.Insert(move(Data(index)));
    }

    for (uint index = 0; index < 100 && chk; index++)
    {
        chk = (lst.Insert(move(Data(50))) == !chk);
    }

    for (uint index = 0; index < 100 && chk; index++)
    {
        chk = (lst.Insert(move(Data(101 + index))) == chk);
    }

    lst.Clear();

    chk ? cout << "Insert Move "
               << "ERR: " << err << endl
        : cout << "Insert Move Error " << ++err << endl;
}

template <typename Data>
void CheckInsertAll(List<Data> &lst, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    Vector<Data> vec(100);

    for (uint index = 0; index < vec.Size(); index++)
    {
        vec[index] = index;
    }

    chk = lst.InsertAll(vec);

    for (uint index = 0; index < lst.Size(); index++)
    {
        chk &= lst.Exists(index);
    }

    chk &= !(lst.InsertAll(vec));

    lst.Clear();

    chk ? cout << "Insert All "
               << "ERR: " << err << endl
        : cout << "Insert All Error " << ++err << endl;
}

template <typename Data>
void CheckInsertAllMove(List<Data> &lst, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    Vector<Data> vec(100);

    for (uint index = 0; index < vec.Size(); index++)
    {
        vec[index] = index;
    }

    chk = lst.InsertAll(move(vec));

    for (uint index = 0; index < lst.Size(); index++)
    {
        chk &= lst.Exists(index);
    }

    Vector<Data> vec2(100);

    for (uint index = 0; index < vec2.Size(); index++)
    {
        vec2[index] = index;
    }

    chk &= !(lst.InsertAll(move(vec2)));

    lst.Clear();

    chk ? cout << "Insert All Move "
               << "ERR: " << err << endl
        : cout << "Insert All Move Error " << ++err << endl;
}

template <typename Data>
void CheckInsertSome(List<Data> &lst, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    Vector<Data> vec(100);

    for (uint index = 0; index < vec.Size(); index++)
    {
        vec[index] = index;
    }

    chk = lst.InsertSome(vec);

    Vector<Data> vec2(10);

    for (uint index = 0; index < vec2.Size(); index++)
    {
        vec2[index] = index + 97;
    }

    chk &= lst.InsertSome(vec2);

    Vector<Data> vec3(10);

    for (uint index = 0; index < vec2.Size(); index++)
    {
        vec2[index] = index + 117;
    }

    chk &= !(lst.InsertSome(vec3));

    lst.Clear();

    chk ? cout << "Insert Some "
               << "ERR: " << err << endl
        : cout << "Insert Some Error " << ++err << endl;
}

template <typename Data>
void CheckInsertSomeMove(List<Data> &lst, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    Vector<Data> vec(100);

    for (uint index = 0; index < vec.Size(); index++)
    {
        vec[index] = index;
    }

    chk = lst.InsertSome(move(vec));

    Vector<Data> vec2(10);

    for (uint index = 0; index < vec2.Size(); index++)
    {
        vec2[index] = index + 97;
    }

    chk &= lst.InsertSome(move(vec2));

    Vector<Data> vec3(10);

    for (uint index = 0; index < vec2.Size(); index++)
    {
        vec2[index] = index + 117;
    }

    chk &= !(lst.InsertSome(move(vec3)));

    lst.Clear();

    chk ? cout << "Insert Some Move "
               << "ERR: " << err << endl
        : cout << "Insert Some Move Error " << ++err << endl;
}

template <typename Data>
void CheckRemove(List<Data> &lst, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    for (uint index = 0; index < 100; index++)
    {
        chk = lst.Insert(Data(index));
    }

    for (uint index = 0; index < 99 && chk; index++)
    {
        chk &= lst.Remove(Data(index));
    }

    lst.Clear();

    chk ? cout << "Remove "
               << "ERR: " << err << endl
        : cout << "Remove Error " << ++err << endl;
}

template <typename Data>
void CheckRemoveAll(List<Data> &lst, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    Vector<Data> vec(100);

    for (uint index = 0; index < vec.Size(); index++)
    {
        vec[index] = index;
    }

    lst.InsertAll(vec);

    chk = lst.RemoveAll(vec);

    lst.InsertAll(vec);

    Vector<Data> vec2(10);

    for (uint index = 0; index < vec2.Size(); index++)
    {
        vec2[index] = index + 10;
    }

    chk &= lst.RemoveAll(vec2);

    chk &= !(lst.RemoveAll(vec2));

    lst.Clear();

    chk ? cout << "Remove All "
               << "ERR: " << err << endl
        : cout << "Remove All Error " << ++err << endl;
}

template <typename Data>
void CheckRemoveSome(List<Data> &lst, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    Vector<Data> vec(100);

    for (uint index = 0; index < vec.Size(); index++)
    {
        vec[index] = index;
    }

    lst.InsertAll(vec);

    chk = lst.RemoveSome(vec);

    lst.InsertAll(vec);

    Vector<Data> vec2(10);

    for (uint index = 0; index < vec2.Size(); index++)
    {
        vec2[index] = index + 10;
    }

    chk &= lst.RemoveSome(vec2);

    chk &= !(lst.RemoveSome(vec2));

    lst.Clear();

    chk ? cout << "Remove Some "
               << "ERR: " << err << endl
        : cout << "Remove Some Error " << ++err << endl;
}

/* **************************************************************************** */

// Check member function StackLst & StackVec
template <typename Data>
void CheckTopNotMutableStackList(StackLst<Data> &stk, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    Data dat = GenerateUint();

    try
    {
        stk.Top();
    }
    catch (...)
    {
        chk = true;
    }

    stk.Push(dat);

    chk &= stk.Top() == dat;

    stk.Clear();

    chk ? cout << "Top Not Mutable "
               << "ERR: " << err << endl
        : cout << "Top Not Mutable Error " << ++err << endl;
}

template <typename Data>
void CheckTopMutableStackList(StackLst<Data> &stk, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    Data dat = GenerateUint();
    Data dat2 = GenerateUint();

    try
    {
        stk.Top() = dat;
    }
    catch (...)
    {
        chk = true;
    }

    stk.Push(dat);

    chk &= stk.Top() == dat;

    stk.Top() = dat2;

    chk &= stk.Top() == dat2;

    stk.Clear();

    chk ? cout << "Top Mutable "
               << "ERR: " << err << endl
        : cout << "Top Mutable Error " << ++err << endl;
}

template <typename Data>
void CheckPopStackList(StackLst<Data> &stk, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    try
    {
        stk.Pop();
    }
    catch (...)
    {
        chk = true;
    }

    Data dat = 0;

    for (uint index = 1; index < 1000; index++)
    {
        dat = index % 120;
        stk.Push(Data(dat));
    }

    for (uint index = 1000; index > 1; index--)
    {
        dat = (index - 1) % 120;
        chk &= stk.Top() == Data(dat);
        stk.Pop();
    }

    try
    {
        stk.Pop();
    }
    catch (...)
    {
        chk &= true;
    }

    for (uint index = 1; index < 1000; index++)
    {
        stk.Push(Data(index));
        stk.Pop();
    }

    try
    {
        stk.Pop();
    }
    catch (...)
    {
        chk &= true;
    }

    stk.Clear();

    chk ? cout << "Pop "
               << "ERR: " << err << endl
        : cout << "Pop Error " << ++err << endl;
}

template <typename Data>
void CheckTopNPopStackList(StackLst<Data> &stk, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    Data dat = 0;

    try
    {
        stk.TopNPop();
    }
    catch (...)
    {
        chk = true;
    }

    for (uint index = 1; index < 1000; index++)
    {
        dat = index % 120;
        stk.Push(dat);
    }

    for (uint index = 1000; index > 1; index--)
    {
        dat = (index - 1) % 120;
        chk &= stk.TopNPop() == dat;
    }

    try
    {
        stk.TopNPop();
    }
    catch (...)
    {
        chk &= true;
    }

    for (uint index = 1; index < 1000; index++)
    {
        dat = index % 120;
        stk.Push(dat);
        chk &= stk.TopNPop() == dat;
    }

    try
    {
        stk.TopNPop();
    }
    catch (...)
    {
        chk &= true;
    }

    stk.Clear();

    chk ? cout << "TopNPop "
               << "ERR: " << err << endl
        : cout << "TopNPop Error " << ++err << endl;
}

template <typename Data>
void CheckPushStackList(StackLst<Data> &stk, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    Data dat = GenerateUint();

    stk.Push(dat);

    chk = stk.Top() == dat;

    stk.Clear();

    chk ? cout << "Push "
               << "ERR: " << err << endl
        : cout << "Push Error " << ++err << endl;
}

template <typename Data>
void CheckPushMoveStackList(StackLst<Data> &stk, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    Data dat = GenerateUint();
    Data dat2 = dat;

    stk.Push(move(dat));

    chk = stk.Top() == dat2;

    stk.Clear();

    chk ? cout << "Push Move "
               << "ERR: " << err << endl
        : cout << "Push Move Error " << ++err << endl;
}

template <typename Data>
void CheckTopNotMutableStackVec(StackVec<Data> &stk, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    Data dat = GenerateUint();

    try
    {
        stk.Top();
    }
    catch (...)
    {
        chk = true;
    }

    stk.Push(dat);

    chk &= stk.Top() == dat;

    stk.Clear();

    chk ? cout << "Top Not Mutable "
               << "ERR: " << err << endl
        : cout << "Top Not Mutable Error " << ++err << endl;
}

template <typename Data>
void CheckTopMutableStackVec(StackVec<Data> &stk, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    Data dat = GenerateUint();
    Data dat2 = GenerateUint();

    try
    {
        stk.Top() = dat;
    }
    catch (...)
    {
        chk = true;
    }

    stk.Push(dat);

    chk &= stk.Top() == dat;

    stk.Top() = dat2;

    chk &= stk.Top() == dat2;

    stk.Clear();

    chk ? cout << "Top Mutable "
               << "ERR: " << err << endl
        : cout << "Top Mutable Error " << ++err << endl;
}

template <typename Data>
void CheckPopStackVec(StackVec<Data> &stk, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    try
    {
        stk.Pop();
    }
    catch (...)
    {
        chk = true;
    }

    Data dat = 0;

    for (uint index = 1; index < 1000; index++)
    {
        dat = index % 120;
        stk.Push(dat);
    }

    for (uint index = 1000; index > 1; index--)
    {
        dat = (index - 1) % 120;
        chk &= stk.Top() == dat;
        stk.Pop();
    }

    try
    {
        stk.Pop();
    }
    catch (...)
    {
        chk &= true;
    }

    for (uint index = 1; index < 1000; index++)
    {
        stk.Push(index);
        stk.Pop();
    }

    try
    {
        stk.Pop();
    }
    catch (...)
    {
        chk &= true;
    }

    stk.Clear();

    chk ? cout << "Pop "
               << "ERR: " << err << endl
        : cout << "Pop Error " << ++err << endl;
}

template <typename Data>
void CheckTopNPopStackVec(StackVec<Data> &stk, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    try
    {
        stk.TopNPop();
    }
    catch (...)
    {
        chk = true;
    }

    Data dat = 0;

    for (uint index = 1; index < 1000; index++)
    {
        dat = index % 120;
        stk.Push(dat);
    }

    for (uint index = 1000; index > 1; index--)
    {
        dat = (index - 1) % 120;
        chk &= stk.TopNPop() == dat;
    }

    try
    {
        stk.TopNPop();
    }
    catch (...)
    {
        chk &= true;
    }

    for (uint index = 1; index < 1000; index++)
    {
        dat = index % 120;
        stk.Push(dat);
        chk &= stk.TopNPop() == dat;
    }

    try
    {
        stk.TopNPop();
    }
    catch (...)
    {
        chk &= true;
    }

    stk.Clear();

    chk ? cout << "TopNPop "
               << "ERR: " << err << endl
        : cout << "TopNPop Error " << ++err << endl;
}

template <typename Data>
void CheckPushStackVec(StackVec<Data> &stk, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    Data dat = GenerateUint();

    stk.Push(dat);

    chk = stk.Top() == dat;

    stk.Clear();

    chk ? cout << "Push "
               << "ERR: " << err << endl
        : cout << "Push Error " << ++err << endl;
}

template <typename Data>
void CheckPushMoveStackVec(StackVec<Data> &stk, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    Data dat = GenerateUint();
    Data dat2 = dat;

    stk.Push(move(dat));

    chk = stk.Top() == dat2;

    stk.Clear();

    chk ? cout << "Push Move "
               << "ERR: " << err << endl
        : cout << "Push Move Error " << ++err << endl;
}

/* **************************************************************************** */

// member function LinearContainer

template <typename Data>
void CheckFrontMutable(LinearContainer<Data> &tmpcon, uint &err, uint &numtest)
{
    ++numtest;
    cout << "TEST '" << numtest << "' ";

    bool chk = false;

    if (!tmpcon.Empty())
    {

        Data dat = GenerateUint();
        Data dat2 = GenerateUint();
        Data dat3 = GenerateUint();

        tmpcon.operator[](0) = dat;

        tmpcon.operator[](1) = dat2;

        chk = tmpcon.Front() == dat;
        tmpcon.Front() = dat3;
        chk &= tmpcon.Front() == dat3;
    }
    else
    {
        try
        {
            tmpcon.Front();
        }
        catch (...)
        {
            chk = true;
        }

        try
        {
            tmpcon.Front() = 1;
        }
        catch (...)
        {
            chk &= true;
        }
    }

    chk ? cout << "Front Mutable "
               << "ERR: " << err << endl
        : cout << "Front Mutable Error " << ++err << endl;
}

template <typename Data>
void CheckFrontNotMutable(LinearContainer<Data> &tmpcon, uint &err, uint &numtest)
{
    ++numtest;
    cout << "TEST '" << numtest << "' ";

    bool chk = false;

    if (!tmpcon.Empty())
    {

        Data dat = GenerateUint();
        Data dat2 = GenerateUint();

        tmpcon.operator[](0) = dat;
        tmpcon.operator[](1) = dat2;

        chk = tmpcon.Front() == dat;
    }
    else
    {

        try
        {
            tmpcon.Front();
        }
        catch (...)
        {
            chk = true;
        }
    }

    chk ? cout << "Front Not Mutable "
               << "ERR: " << err << endl
        : cout << "Front Not Mutable Error " << ++err << endl;
}

template <typename Data>
void CheckBackMutable(LinearContainer<Data> &tmpcon, uint &err, uint &numtest)
{
    ++numtest;
    cout << "TEST '" << numtest << "' ";

    bool chk = false;

    if (!tmpcon.Empty())
    {

        Data dat = GenerateUint();
        Data dat2 = GenerateUint();
        Data dat3 = GenerateUint();

        tmpcon.operator[](0) = dat;
        tmpcon.operator[](1) = dat2;
        tmpcon.operator[](2) = dat3;

        chk = tmpcon.Back() == dat3;
        tmpcon.Back() = dat2;
        chk &= tmpcon.Back() == dat2;
    }
    else
    {
        try
        {
            tmpcon.Back();
        }
        catch (...)
        {
            chk = true;
        }

        try
        {
            tmpcon.Back();
        }
        catch (...)
        {
            chk &= true;
        }
    }

    chk ? cout << "Back Mutable"
               << "ERR: " << err << endl
        : cout << "Back Mutable " << ++err << endl;
}

template <typename Data>
void CheckBackNotMutable(LinearContainer<Data> &tmpcon, uint &err, uint &numtest)
{
    ++numtest;
    cout << "TEST '" << numtest << "' ";

    bool chk = false;

    if (!tmpcon.Empty())
    {

        Data dat = GenerateUint();
        Data dat2 = GenerateUint();
        Data dat3 = GenerateUint();

        tmpcon.operator[](0) = dat;
        tmpcon.operator[](1) = dat2;
        tmpcon.operator[](2) = dat3;

        chk = tmpcon.Back() == dat3;
    }
    else
    {
        try
        {
            tmpcon.Back();
        }
        catch (...)
        {
            chk = true;
        }
    }

    try
    {
        tmpcon.Front() = 1;
    }
    catch (...)
    {
        chk &= true;
    }

    chk ? cout << "Back Not Mutable "
               << "ERR: " << err << endl
        : cout << "Back Not Mutable " << ++err << endl;
}

template <typename Data>
void CheckFrontMutableVector(Vector<Data> &tmpcon, uint &err, uint &numtest)
{
    ++numtest;
    cout << "TEST '" << numtest << "' ";

    bool chk = false;

    Data dat = GenerateUint();
    Data dat2 = GenerateUint();
    Data dat3 = GenerateUint();

    tmpcon.operator[](0) = dat;
    tmpcon.operator[](1) = dat2;

    chk = tmpcon.Front() == dat;
    tmpcon.Front() = dat3;
    chk &= tmpcon.Front() == dat3;

    Vector<Data> newcon(tmpcon);

    newcon.Clear();

    try
    {
        newcon.Front();
    }
    catch (...)
    {
        chk &= true;
    }

    chk ? cout << "Front Mutable "
               << "ERR: " << err << endl
        : cout << "Front Mutable Error " << ++err << endl;
}

template <typename Data>
void CheckFrontNotMutableVector(Vector<Data> &tmpcon, uint &err, uint &numtest)
{
    ++numtest;
    cout << "TEST '" << numtest << "' ";

    bool chk = false;

    Data dat = GenerateUint();
    Data dat2 = GenerateUint();

    tmpcon.operator[](0) = dat;
    tmpcon.operator[](1) = dat2;

    chk = tmpcon.Front() == dat;

    Vector<Data> newcon(tmpcon);

    newcon.Clear();

    try
    {
        newcon.Front();
    }
    catch (...)
    {
        chk &= true;
    }

    chk ? cout << "Front Not Mutable "
               << "ERR: " << err << endl
        : cout << "Front Not Mutable Error " << ++err << endl;
}

template <typename Data>
void CheckBackMutableVector(Vector<Data> &tmpcon, uint &err, uint &numtest)
{
    ++numtest;
    cout << "TEST '" << numtest << "' ";

    bool chk = false;

    Data dat = GenerateUint();
    Data dat2 = GenerateUint();
    Data dat3 = GenerateUint();

    tmpcon.operator[](0) = dat;
    tmpcon.operator[](1) = dat2;
    tmpcon.operator[](2) = dat3;

    chk = tmpcon.Back() == dat3;
    tmpcon.Back() = dat2;
    chk &= tmpcon.Back() == dat2;

    Vector<Data> newcon(tmpcon);

    newcon.Clear();

    try
    {
        newcon.Back();
    }
    catch (...)
    {
        chk &= true;
    }

    chk ? cout << "Back Mutable"
               << "ERR: " << err << endl
        : cout << "Back Mutable " << ++err << endl;
}

template <typename Data>
void CheckBackNotMutableVector(Vector<Data> &tmpcon, uint &err, uint &numtest)
{
    ++numtest;
    cout << "TEST '" << numtest << "' ";

    bool chk = false;

    Data dat = GenerateUint();
    Data dat2 = GenerateUint();
    Data dat3 = GenerateUint();

    tmpcon.operator[](0) = dat;
    tmpcon.operator[](1) = dat2;
    tmpcon.operator[](2) = dat3;

    chk = tmpcon.Back() == dat3;

    Vector<Data> newcon(tmpcon);

    newcon.Clear();

    try
    {
        newcon.Back();
    }
    catch (...)
    {
        chk &= true;
    }

    chk ? cout << "Back Not Mutable "
               << "ERR: " << err << endl
        : cout << "Back Not Mutable " << ++err << endl;
}

template <typename Data>
void CheckFrontMutableList(List<Data> &tmpcon, uint &err, uint &numtest)
{
    ++numtest;
    cout << "TEST '" << numtest << "' ";

    bool chk = false;

    Data dat = GenerateUint();
    Data dat2 = GenerateUint();
    Data dat3 = GenerateUint();

    tmpcon.InsertAtFront(dat);
    tmpcon.InsertAtFront(dat2);

    chk = tmpcon.Front() == dat2;
    tmpcon.Front() = dat3;
    chk &= tmpcon.Front() == dat3;

    tmpcon.Clear();

    try
    {
        tmpcon.Front() = 1;
    }
    catch (...)
    {
        chk &= true;
    }

    chk ? cout << "Front Mutable "
               << "ERR: " << err << endl
        : cout << "Front Mutable Error " << ++err << endl;
}

template <typename Data>
void CheckFrontNotMutableList(List<Data> &tmpcon, uint &err, uint &numtest)
{
    ++numtest;
    cout << "TEST '" << numtest << "' ";

    bool chk = false;

    Data dat = GenerateUint();
    Data dat2 = GenerateUint();

    tmpcon.InsertAtFront(dat);
    tmpcon.InsertAtFront(dat2);

    chk = tmpcon.Front() == dat2;

    tmpcon.Clear();

    try
    {
        tmpcon.Front();
    }
    catch (...)
    {
        chk &= true;
    }

    chk ? cout << "Front Not Mutable "
               << "ERR: " << err << endl
        : cout << "Front Not Mutable Error " << ++err << endl;
}

template <typename Data>
void CheckBackMutableList(List<Data> &tmpcon, uint &err, uint &numtest)
{
    ++numtest;
    cout << "TEST '" << numtest << "' ";

    bool chk = false;

    Data dat = GenerateUint();
    Data dat2 = GenerateUint();
    Data dat3 = GenerateUint();

    tmpcon.InsertAtFront(dat);
    tmpcon.InsertAtFront(dat2);
    tmpcon.InsertAtFront(dat3);

    chk = tmpcon.Back() == dat;
    tmpcon.Back() = dat3;
    chk &= tmpcon.Back() == dat3;

    tmpcon.Clear();

    try
    {
        tmpcon.Back();
    }
    catch (...)
    {
        chk &= true;
    }

    chk ? cout << "Back Mutable"
               << "ERR: " << err << endl
        : cout << "Back Mutable " << ++err << endl;
}

template <typename Data>
void CheckBackNotMutableList(List<Data> &tmpcon, uint &err, uint &numtest)
{
    ++numtest;
    cout << "TEST '" << numtest << "' ";

    bool chk = false;

    Data dat = GenerateUint();
    Data dat2 = GenerateUint();
    Data dat3 = GenerateUint();

    tmpcon.InsertAtFront(dat);
    tmpcon.InsertAtFront(dat2);
    tmpcon.InsertAtFront(dat3);

    chk = tmpcon.Back() == dat;

    tmpcon.Clear();

    try
    {
        tmpcon.Back();
    }
    catch (...)
    {
        chk &= true;
    }

    chk ? cout << "Back Not Mutable "
               << "ERR: " << err << endl
        : cout << "Back Not Mutable " << ++err << endl;
}

/* ************************************************************************** */

// insert dat map function
template <typename Data>
void MyInsertData(Data &dat)
{
    dat = move(GenerateInt() * 0.01);
}

// insert string map function
template <typename Data>
void MyInsertStringData(string &dat)
{
    // lunghezza parola max 12
    dat = move(GenerateWord(12));
}

// cout number total dat with fold
template <typename Data>
Data MyFoldCount(const Data &dat, const Data &acc)
{
    return (acc + 1);
}

template <typename Data>
void MyExistsData(const TraversableContainer<Data> &con)
{
    Data dat;
    cout << "Inserisci dato: " << endl;
    cin >> dat;
    con.Exists(dat) ? cout << "Il dato e' presente nella struttura " : cout << "Il dato non e' presente nella struttura ";
    cout << endl
         << endl;
}

/* **************************************************************************** */

// Order Vector (copy constructor SortableVector -> Sort() -> copy Constructor Vector -> copy assignment in vec)
template <typename Data>
void MyOrderVector(Vector<Data> &vec)
{
    if (vec.Size() > 0)
    {

        SortableVector<Data> sortvector(vec);

        sortvector.Sort();

        Vector<Data> tmpvector(sortvector);

        vec = tmpvector;
    }
    else
        cout << "Impossibile ordinare vettore vuoto " << endl
             << endl;
}

// Order List (copy constructor SortableVector -> Sort() -> copy Constructor List -> copy assignment in lst)
template <typename Data>
void MyOrderList(List<Data> &lst)
{
    if (lst.Size() > 0)
    {
        SortableVector<Data> sortvector(lst);

        sortvector.Sort();

        List<Data> tmplst(sortvector);

        lst = tmplst;
    }
    else
        cout << "Impossibile ordinare lista vuota " << endl
             << endl;
}

// check order over with vector
template <typename Data>
bool CheckOrderOver(const LinearContainer<Data> &con, uint &err, uint &numtest)
{
    ++numtest;

    Vector<Data> tmpcon(con);

    OrderVector(tmpcon);

    cout << "TEST '" << numtest << "' ";

    for (ulong index = 1; index < tmpcon.Size(); index++)
    {
        if (tmpcon.operator[](index) < tmpcon.operator[](index - 1))
        {
            cout << "Sort Error " << ++err << endl;
            return false;
        }
    }

    cout << "Sort Correct "
         << "ERR: " << err << endl;

    return true;
}

/* **************************************************************************** */

// Check member function QueueLst & QueueVec
template <typename Data>
void CheckHeadNotMutableQueueList(QueueLst<Data> &que, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    Data dat = GenerateUint();

    try
    {
        que.Head();
    }
    catch (...)
    {
        chk = true;
    }

    que.Enqueue(dat);

    chk &= que.Head() == dat;

    que.Clear();

    chk ? cout << "Head Not Mutable "
               << "ERR: " << err << endl
        : cout << "Head Not Mutable Error " << ++err << endl;
}

template <typename Data>
void CheckHeadMutableQueueList(QueueLst<Data> &que, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    Data dat = GenerateUint();
    Data dat2 = GenerateUint();

    try
    {
        que.Head() = dat;
    }
    catch (...)
    {
        chk = true;
    }

    que.Enqueue(dat);

    chk &= que.Head() == dat;

    que.Head() = dat2;

    chk &= que.Head() == dat2;

    que.Clear();

    chk ? cout << "Head Mutable "
               << "ERR: " << err << endl
        : cout << "Head Mutable Error " << ++err << endl;
}

template <typename Data>
void CheckDequeueQueueList(QueueLst<Data> &que, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    Data dat = 0;

    try
    {
        que.Dequeue();
    }
    catch (...)
    {
        chk = true;
    }

    for (uint index = 1; index < 1000; index++)
    {
        dat = index % 120;
        que.Enqueue(dat);
    }

    for (uint index = 1; index < 1000; index++)
    {
        dat = index % 120;
        chk &= que.Head() == dat;
        que.Dequeue();
    }

    try
    {
        que.Dequeue();
    }
    catch (...)
    {
        chk &= true;
    }

    for (uint index = 1; index < 1000; index++)
    {
        que.Enqueue(index);
        que.Dequeue();
    }

    try
    {
        que.Dequeue();
    }
    catch (...)
    {
        chk &= true;
    }

    que.Clear();

    chk ? cout << "Dequeue "
               << "ERR: " << err << endl
        : cout << "Dequeue Error " << ++err << endl;
}

template <typename Data>
void CheckHeadNDequeueQueueList(QueueLst<Data> &que, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    try
    {
        que.HeadNDequeue();
    }
    catch (...)
    {
        chk = true;
    }

    Data dat = 0;

    for (uint index = 1; index < 1000; index++)
    {
        dat = index % 120;
        que.Enqueue(dat);
    }

    for (uint index = 1; index < 1000; index++)
    {
        dat = index % 120;
        chk &= que.HeadNDequeue() == dat;
    }

    try
    {
        que.HeadNDequeue();
    }
    catch (...)
    {
        chk &= true;
    }

    for (uint index = 1; index < 1000; index++)
    {
        dat = index % 120;
        que.Enqueue(dat);
        chk &= que.HeadNDequeue() == dat;
    }

    try
    {
        que.HeadNDequeue();
    }
    catch (...)
    {
        chk &= true;
    }

    que.Clear();

    chk ? cout << "HeadNDequeue "
               << "ERR: " << err << endl
        : cout << "HeadNDequeue Error " << ++err << endl;
}

template <typename Data>
void CheckEnqueueQueueList(QueueLst<Data> &que, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    Data dat = GenerateUint();

    que.Enqueue(dat);

    chk = que.Head() == dat;

    que.Clear();

    chk ? cout << "Enqueue "
               << "ERR: " << err << endl
        : cout << "Enqueue Error " << ++err << endl;
}

template <typename Data>
void CheckEnqueueMoveQueueList(QueueLst<Data> &que, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    Data dat = GenerateUint();
    Data dat2 = dat;

    que.Enqueue(move(dat));

    chk = que.Head() == dat2;

    que.Clear();

    chk ? cout << "Enqueue Move "
               << "ERR: " << err << endl
        : cout << "Enqueue Move Error " << ++err << endl;
}

template <typename Data>
void CheckHeadNotMutableQueueVec(QueueVec<Data> &que, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    Data dat = GenerateUint();

    try
    {
        que.Head();
    }
    catch (...)
    {
        chk = true;
    }

    que.Enqueue(dat);

    chk &= que.Head() == dat;

    que.Clear();

    chk ? cout << "Head Not Mutable "
               << "ERR: " << err << endl
        : cout << "Head Not Mutable Error " << ++err << endl;
}

template <typename Data>
void CheckHeadMutableQueueVec(QueueVec<Data> &que, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    Data dat = GenerateUint();
    Data dat2 = GenerateUint();

    try
    {
        que.Head() = dat;
    }
    catch (...)
    {
        chk = true;
    }

    que.Enqueue(dat);

    chk &= que.Head() == dat;

    que.Head() = dat2;

    chk &= que.Head() == dat2;

    que.Clear();

    chk ? cout << "Head Mutable "
               << "ERR: " << err << endl
        : cout << "Head Mutable Error " << ++err << endl;
}

template <typename Data>
void CheckDequeueQueueVec(QueueVec<Data> &que, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    try
    {
        que.Dequeue();
    }
    catch (...)
    {
        chk = true;
    }

    Data dat = 0;

    for (uint index = 1; index < 1000; index++)
    {
        dat = index % 120;
        que.Enqueue(dat);
    }

    for (uint index = 1; index < 1000; index++)
    {
        dat = index % 120;
        chk &= que.Head() == dat;
        que.Dequeue();
    }

    try
    {
        que.Dequeue();
    }
    catch (...)
    {
        chk &= true;
    }

    for (uint index = 1; index < 1000; index++)
    {
        que.Enqueue(index);
        que.Dequeue();
    }

    try
    {
        que.Dequeue();
    }
    catch (...)
    {
        chk &= true;
    }

    que.Clear();

    chk ? cout << "Dequeue "
               << "ERR: " << err << endl
        : cout << "Dequeue Error " << ++err << endl;
}

template <typename Data>
void CheckHeadNDequeueQueueVec(QueueVec<Data> &que, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    Data dat = 0;

    try
    {
        que.HeadNDequeue();
    }
    catch (...)
    {
        chk = true;
    }

    for (uint index = 1; index < 1000; index++)
    {
        dat = index % 120;
        que.Enqueue(dat);
    }

    for (uint index = 1; index < 1000; index++)
    {
        dat = index % 120;
        chk &= que.HeadNDequeue() == dat;
    }

    try
    {
        que.HeadNDequeue();
    }
    catch (...)
    {
        chk &= true;
    }

    for (uint index = 1; index < 1000; index++)
    {
        dat = index % 120;
        que.Enqueue(dat);
        chk &= que.HeadNDequeue() == dat;
    }

    try
    {
        que.HeadNDequeue();
    }
    catch (...)
    {
        chk &= true;
    }

    que.Clear();

    chk ? cout << "HeadNDequeue "
               << "ERR: " << err << endl
        : cout << "HeadNDequeue Error " << ++err << endl;
}

template <typename Data>
void CheckEnqueueQueueVec(QueueVec<Data> &que, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    Data dat = GenerateUint();

    que.Enqueue(dat);

    chk = que.Head() == dat;

    que.Clear();

    chk ? cout << "Enqueue "
               << "ERR: " << err << endl
        : cout << "Enqueue Error " << ++err << endl;
}

template <typename Data>
void CheckEnqueueMoveQueueVec(QueueVec<Data> &que, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    Data dat = GenerateUint();
    Data dat2 = dat;

    que.Enqueue(move(dat));

    chk = que.Head() == dat2;

    que.Clear();

    chk ? cout << "Enqueue Move "
               << "ERR: " << err << endl
        : cout << "Enqueue Move Error " << ++err << endl;
}

/* **************************************************************************** */

// Check member function QueueLst & QueueVec for String type

void CheckHeadNotMutableQueueListString(QueueLst<string> &que, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    string dat = GenerateWord(20);

    try
    {
        que.Head();
    }
    catch (...)
    {
        chk = true;
    }

    que.Enqueue(dat);

    chk &= que.Head() == dat;

    que.Clear();

    chk ? cout << "Head Not Mutable "
               << "ERR: " << err << endl
        : cout << "Head Not Mutable Error " << ++err << endl;
}

void CheckHeadMutableQueueListString(QueueLst<string> &que, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    string dat = GenerateWord(20);
    string dat2 = GenerateWord(20);

    try
    {
        que.Head() = dat;
    }
    catch (...)
    {
        chk = true;
    }

    que.Enqueue(dat);

    chk &= que.Head() == dat;

    que.Head() = dat2;

    chk &= que.Head() == dat2;

    que.Clear();

    chk ? cout << "Head Mutable "
               << "ERR: " << err << endl
        : cout << "Head Mutable Error " << ++err << endl;
}

void CheckDequeueQueueListString(QueueLst<string> &que, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    QueueLst<string> tmpque;

    string dat = {};

    try
    {
        que.Dequeue();
    }
    catch (...)
    {
        chk = true;
    }

    for (uint index = 1; index < 1000; index++)
    {
        dat = GenerateWord(20);
        que.Enqueue(dat);
        tmpque.Enqueue(dat);
    }

    for (uint index = 1; index < 1000; index++)
    {
        chk &= que.Head() == tmpque.Head();
        que.Dequeue();
        tmpque.Dequeue();
    }

    try
    {
        que.Dequeue();
    }
    catch (...)
    {
        chk &= true;
    }

    for (uint index = 1; index < 1000; index++)
    {
        dat = GenerateWord(20);
        que.Enqueue(dat);
        que.Dequeue();
    }

    try
    {
        que.Dequeue();
    }
    catch (...)
    {
        chk &= true;
    }

    que.Clear();

    chk ? cout << "Dequeue "
               << "ERR: " << err << endl
        : cout << "Dequeue Error " << ++err << endl;
}

void CheckHeadNDequeueQueueListString(QueueLst<string> &que, uint &err, uint &numtest)
{
    bool chk = false;

    QueueLst<string> tmpque;

    string dat = {};

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    try
    {
        que.HeadNDequeue();
    }
    catch (...)
    {
        chk = true;
    }

    for (uint index = 1; index < 1000; index++)
    {
        dat = GenerateWord(20);
        que.Enqueue(dat);
        tmpque.Enqueue(dat);
    }

    for (uint index = 1; index < 1000; index++)
    {
        chk &= que.HeadNDequeue() == tmpque.Head();
        tmpque.Dequeue();
    }

    try
    {
        que.HeadNDequeue();
    }
    catch (...)
    {
        chk &= true;
    }

    for (uint index = 1; index < 1000; index++)
    {
        dat = GenerateWord(20);
        que.Enqueue(dat);
        chk &= que.HeadNDequeue() == dat;
    }

    try
    {
        que.HeadNDequeue();
    }
    catch (...)
    {
        chk &= true;
    }

    que.Clear();

    chk ? cout << "HeadNDequeue "
               << "ERR: " << err << endl
        : cout << "HeadNDequeue Error " << ++err << endl;
}

void CheckEnqueueQueueListString(QueueLst<string> &que, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    string dat = {};

    que.Enqueue(dat);

    chk = que.Head() == dat;

    que.Clear();

    chk ? cout << "Enqueue "
               << "ERR: " << err << endl
        : cout << "Enqueue Error " << ++err << endl;
}

void CheckEnqueueMoveQueueListString(QueueLst<string> &que, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    string dat = GenerateWord(29);
    string dat2 = dat;

    que.Enqueue(move(dat));

    chk = que.Head() == dat2;

    que.Clear();

    chk ? cout << "Enqueue Move "
               << "ERR: " << err << endl
        : cout << "Enqueue Move Error " << ++err << endl;
}

void CheckHeadNotMutableQueueVecString(QueueVec<string> &que, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    string dat = GenerateWord(20);

    try
    {
        que.Head();
    }
    catch (...)
    {
        chk = true;
    }

    que.Enqueue(dat);

    chk &= que.Head() == dat;

    que.Clear();

    chk ? cout << "Head Not Mutable "
               << "ERR: " << err << endl
        : cout << "Head Not Mutable Error " << ++err << endl;
}

void CheckHeadMutableQueueVecString(QueueVec<string> &que, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    string dat = GenerateWord(20);
    string dat2 = GenerateWord(20);

    try
    {
        que.Head() = dat;
    }
    catch (...)
    {
        chk = true;
    }

    que.Enqueue(dat);

    chk &= que.Head() == dat;

    que.Head() = dat2;

    chk &= que.Head() == dat2;

    que.Clear();

    chk ? cout << "Head Mutable "
               << "ERR: " << err << endl
        : cout << "Head Mutable Error " << ++err << endl;
}

void CheckDequeueQueueVecString(QueueVec<string> &que, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    QueueLst<string> tmpque;

    string dat = {};

    try
    {
        que.Dequeue();
    }
    catch (...)
    {
        chk = true;
    }

    for (uint index = 1; index < 1000; index++)
    {
        dat = GenerateWord(20);
        que.Enqueue(dat);
        tmpque.Enqueue(dat);
    }

    for (uint index = 1; index < 1000; index++)
    {
        chk &= que.Head() == tmpque.HeadNDequeue();
        que.Dequeue();
    }

    try
    {
        que.Dequeue();
    }
    catch (...)
    {
        chk &= true;
    }

    for (uint index = 1; index < 1000; index++)
    {
        que.Enqueue(GenerateWord(29));
        que.Dequeue();
    }

    try
    {
        que.Dequeue();
    }
    catch (...)
    {
        chk &= true;
    }

    que.Clear();

    chk ? cout << "Dequeue "
               << "ERR: " << err << endl
        : cout << "Dequeue Error " << ++err << endl;
}

void CheckHeadNDequeueQueueVecString(QueueVec<string> &que, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    QueueLst<string> tmpque;

    string dat = {};

    try
    {
        que.HeadNDequeue();
    }
    catch (...)
    {
        chk = true;
    }

    for (uint index = 1; index < 1000; index++)
    {
        dat = GenerateWord(29);
        que.Enqueue(dat);
        tmpque.Enqueue(dat);
    }

    for (uint index = 1; index < 1000; index++)
    {
        chk &= que.HeadNDequeue() == tmpque.HeadNDequeue();
    }

    try
    {
        que.HeadNDequeue();
    }
    catch (...)
    {
        chk &= true;
    }

    for (uint index = 1; index < 1000; index++)
    {
        dat = GenerateWord(20);

        que.Enqueue(dat);
        tmpque.Enqueue(dat);

        chk &= que.HeadNDequeue() == tmpque.Head();
        tmpque.Dequeue();
    }

    try
    {
        que.HeadNDequeue();
    }
    catch (...)
    {
        chk &= true;
    }

    que.Clear();

    chk ? cout << "HeadNDequeue "
               << "ERR: " << err << endl
        : cout << "HeadNDequeue Error " << ++err << endl;
}

void CheckEnqueueQueueVecString(QueueVec<string> &que, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    string dat = GenerateWord(20);

    que.Enqueue(dat);

    chk = que.Head() == dat;

    que.Clear();

    chk ? cout << "Enqueue "
               << "ERR: " << err << endl
        : cout << "Enqueue Error " << ++err << endl;
}

void CheckEnqueueMoveQueueVecString(QueueVec<string> &que, uint &err, uint &numtest)
{
    bool chk = false;

    ++numtest;
    cout << "TEST '" << numtest << "' ";

    string dat = GenerateWord(20);
    string dat2 = dat;

    que.Enqueue(move(dat));

    chk = que.Head() == dat2;

    que.Clear();

    chk ? cout << "Enqueue Move "
               << "ERR: " << err << endl
        : cout << "Enqueue Move Error " << ++err << endl;
}

/**************************************************************************/

// Group Test call function check

template <typename Data>
void TestCheckFuctionContainer(uint &err, uint &numtest)
{
    Vector<Data> vec1;

    PopularVectorData(vec1, 100);

    SortableVector<Data> vec2(vec1);

    CheckSize(vec1, err, numtest);
    CheckSize(vec2, err, numtest);
    CheckEmpty(vec1, err, numtest);
    CheckEmpty(vec2, err, numtest);
    CheckClear(vec1, err, numtest);
    CheckClear(vec2, err, numtest);
    CheckResize(vec1, err, numtest);
    CheckResize(vec2, err, numtest);
}

template <typename Data>
void TestCheckMemberFuctionList(List<Data> &lst, uint &err, uint &numtest)
{
    List<Data> tmplst(lst);

    CheckInserAtFront(tmplst, err, numtest);
    CheckInserAtFrontMove(tmplst, err, numtest);

    CheckRemoveFromFront(tmplst, err, numtest);
    CheckFrontNRemove(tmplst, err, numtest);

    CheckInserAtBack(tmplst, err, numtest);
    CheckInserAtBackMove(tmplst, err, numtest);
}

template <typename Data>
void TestCheckMemberFunctionLinearContainer(uint &err, uint &numtest)
{
    Vector<Data> con;

    cout << endl
         << "Test check member function on linearcontainer empty: " << endl;

    CheckFrontNotMutable(con, err, numtest);
    CheckFrontMutable(con, err, numtest);

    CheckBackNotMutable(con, err, numtest);
    CheckBackMutable(con, err, numtest);

    con.Resize(3);

    cout << endl
         << "Test check member function on linearcontainer not empty: " << endl;

    CheckFrontNotMutable(con, err, numtest);
    CheckFrontMutable(con, err, numtest);

    CheckBackNotMutable(con, err, numtest);
    CheckBackMutable(con, err, numtest);

    Vector<Data> tmpcon(con);

    cout << endl
         << "Test check member function on vector: " << endl;

    CheckFrontNotMutableVector(tmpcon, err, numtest);
    CheckFrontMutableVector(tmpcon, err, numtest);

    CheckBackNotMutableVector(tmpcon, err, numtest);
    CheckBackMutableVector(tmpcon, err, numtest);

    List<Data> tmpcon2;

    cout << endl
         << "Test check member function on list: " << endl;

    CheckFrontNotMutableList(tmpcon2, err, numtest);
    CheckFrontMutableList(tmpcon2, err, numtest);

    CheckBackNotMutableList(tmpcon2, err, numtest);
    CheckBackMutableList(tmpcon2, err, numtest);
}

template <typename Data>
void TestCheckMemberFunctionDictionary(uint &err, uint &numtest)
{
    cout << endl
         << "Test function of Dictionary on list" << endl;

    List<Data> tmplst;

    CheckInsert(tmplst, err, numtest);
    CheckInsertMove(tmplst, err, numtest);

    CheckInsertAll(tmplst, err, numtest);
    CheckInsertAllMove(tmplst, err, numtest);

    CheckInsertSome(tmplst, err, numtest);
    CheckInsertSomeMove(tmplst, err, numtest);

    CheckRemove(tmplst, err, numtest);
    CheckRemoveAll(tmplst, err, numtest);
    CheckRemoveSome(tmplst, err, numtest);
}

template <typename Data>
void TestCheckMemberFunctionStack(uint &err, uint &numtest)
{
    cout << endl
         << "Test function of Stack list" << endl;

    StackLst<Data> stklst;

    CheckTopNotMutableStackList(stklst, err, numtest);
    CheckTopMutableStackList(stklst, err, numtest);

    CheckPopStackList(stklst, err, numtest);
    CheckTopNPopStackList(stklst, err, numtest);

    CheckPushStackList(stklst, err, numtest);
    CheckPushMoveStackList(stklst, err, numtest);

    StackVec<Data> stkvec;

    cout << endl
         << "Test function of Stack vec" << endl;

    CheckTopNotMutableStackVec(stkvec, err, numtest);
    CheckTopMutableStackVec(stkvec, err, numtest);

    CheckPopStackVec(stkvec, err, numtest);
    CheckTopNPopStackVec(stkvec, err, numtest);

    CheckPushStackVec(stkvec, err, numtest);
    CheckPushMoveStackVec(stkvec, err, numtest);
}

template <typename Data>
void TestCheckMemberFunctionQueue(uint &err, uint &numtest)
{
    cout << endl
         << "Test function of Queue list" << endl;

    QueueLst<Data> quelst;

    CheckHeadNotMutableQueueList(quelst, err, numtest);
    CheckHeadMutableQueueList(quelst, err, numtest);

    CheckDequeueQueueList(quelst, err, numtest);
    CheckHeadNDequeueQueueList(quelst, err, numtest);

    CheckEnqueueQueueList(quelst, err, numtest);
    CheckEnqueueMoveQueueList(quelst, err, numtest);

    QueueVec<Data> quevec;

    cout << endl
         << "Test function of Queue vec" << endl;

    CheckHeadNotMutableQueueVec(quevec, err, numtest);
    CheckHeadMutableQueueVec(quevec, err, numtest);

    CheckDequeueQueueVec(quevec, err, numtest);
    CheckHeadNDequeueQueueVec(quevec, err, numtest);

    CheckEnqueueQueueVec(quevec, err, numtest);
    CheckEnqueueMoveQueueVec(quevec, err, numtest);
}

void TestCheckMemberFunctionQueueString(uint &err, uint &numtest)
{
    cout << endl
         << "Test function of Queue list string" << endl;

    QueueLst<string> quelst;

    CheckHeadNotMutableQueueListString(quelst, err, numtest);
    CheckHeadMutableQueueListString(quelst, err, numtest);

    CheckDequeueQueueListString(quelst, err, numtest);
    CheckHeadNDequeueQueueListString(quelst, err, numtest);

    CheckEnqueueQueueListString(quelst, err, numtest);
    CheckEnqueueMoveQueueListString(quelst, err, numtest);

    QueueVec<string> quevec;

    cout << endl
         << "Test function of Queue vec" << endl;

    CheckHeadNotMutableQueueVecString(quevec, err, numtest);
    CheckHeadMutableQueueVecString(quevec, err, numtest);

    CheckDequeueQueueVecString(quevec, err, numtest);
    CheckHeadNDequeueQueueVecString(quevec, err, numtest);

    CheckEnqueueQueueVecString(quevec, err, numtest);
    CheckEnqueueMoveQueueVecString(quevec, err, numtest);
}