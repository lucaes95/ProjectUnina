#ifndef MYTEST_HPP
#define MYTEST_HPP

#include "../container/container.hpp"
#include "../container/dictionary.hpp"
#include "../container/linear.hpp"
#include "../container/mappable.hpp"
#include "../container/testable.hpp"
#include "../container/traversable.hpp"

#include "../vector/vector.hpp"
#include "../list/list.hpp"

#include "../queue/queue.hpp"
#include "../queue/lst/queuelst.hpp"
#include "../queue/vec/queuevec.hpp"

#include "../stack/stack.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../stack/vec/stackvec.hpp"

#include "../iterator/iterator.hpp"
#include "../binarytree/binarytree.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../binarytree/vec/binarytreevec.hpp"

#include "../bst/bst.hpp"

#include "../hashtable/hashtable.hpp"
#include "../hashtable/clsadr/htclsadr.hpp"
#include "../hashtable/opnadr/htopnadr.hpp"

#include <random>
#include <string>

/* ************************************************************************** */

typedef unsigned int uint;
typedef unsigned long ulong;

/* ************************************************************************** */

const int GenerateInt();

const uint GenerateUint();

const uint GenerateUintRange(const uint &max);

const uint GenerateintRange(const uint &min, const uint &max);

const char GenerateChar();

const double GenerateDouble();

const string GenerateWord(const uint &lenghtwordmax);

/* ************************************************************************** */

using namespace lasd;

void mytest();

/* ************************************************************************** */

// Group Test call function check

template <typename Data>
void CheckHashTableClsAdrConstructors(uint &, uint &);

template <typename Data>
void CheckHashTableOpnAdrConstructors(uint &, uint &);

template <typename Data>
void CheckHashTableClsAdrAssigment(uint &, uint &);

template <typename Data>
void CheckHashTableOpnAdrAssigment(uint &, uint &);

template <typename Data>
void CheckHashTableClsAdrComparison(uint &, uint &);

template <typename Data>
void CheckHashTableOpnAdrComparison(uint &, uint &);

template <typename Data>
void CheckHashTableClsAdrContainerFunctions(uint &, uint &);

template <typename Data>
void CheckHashTableOpnAdrContainerFunctions(uint &, uint &);

template <typename Data>
void CheckHashTableClsAdrDictionaryFunctions(uint &, uint &);

template <typename Data>
void CheckHashTableOpnAdrDictionaryFunctions(uint &, uint &);

void CheckHashTableClsAdrDictionaryFunctionsString(uint &, uint &);

void CheckHashTableOpnAdrDictionaryFunctionsString(uint &, uint &);

/* ************************************************************************** */

// // Check Test Constructors

template <typename Data>
void CheckHashTableClsAdrConstructorSize(uint &, uint &);

template <typename Data>
void CheckHashTableClsAdrConstructorTraversable(uint &, uint &);

template <typename Data>
void CheckHashTableClsAdrConstructorTraversableSize(uint &, uint &);

template <typename Data>
void CheckHashTableClsAdrConstructorMappable(uint &, uint &);

template <typename Data>
void CheckHashTableClsAdrConstructorMappableSize(uint &, uint &);

template <typename Data>
void CheckHashTableClsAdrConstructorCopy(uint &, uint &);

template <typename Data>
void CheckHashTableClsAdrConstructorMove(uint &, uint &);

template <typename Data>
void CheckHashTableOpnAdrConstructorSize(uint &, uint &);

template <typename Data>
void CheckHashTableOpnAdrConstructorTraversable(uint &, uint &);

template <typename Data>
void CheckHashTableOpnAdrConstructorTraversableSize(uint &, uint &);

template <typename Data>
void CheckHashTableOpnAdrConstructorMappable(uint &, uint &);

template <typename Data>
void CheckHashTableOpnAdrConstructorMappableSize(uint &, uint &);

template <typename Data>
void CheckHashTableOpnAdrConstructorCopy(uint &, uint &);

template <typename Data>
void CheckHashTableOpnAdrConstructorMove(uint &, uint &);

/* ************************************************************************** */

// Check Test Assigment

template <typename Data>
void CheckHashTableClsAdrAssigmentCopy(uint &, uint &);

template <typename Data>
void CheckHashTableClsAdrAssigmentMove(uint &, uint &);

template <typename Data>
void CheckHashTableOpnAdrAssigmentCopy(uint &, uint &);

template <typename Data>
void CheckHashTableOpnAdrAssigmentMove(uint &, uint &);

/* ************************************************************************** */

// Check Test Comparison

template <typename Data>
void CheckHashTableClsAdrEquals(uint &, uint &);

template <typename Data>
void CheckHashTableClsAdrNotEquals(uint &, uint &);

template <typename Data>
void CheckHashTableOpnAdrEquals(uint &, uint &);

template <typename Data>
void CheckHashTableOpnAdrNotEquals(uint &, uint &);

/* ************************************************************************** */

// Check Test Functions Container

template <typename Data>
void CheckHashTableClsAdrExists(uint &, uint &);

template <typename Data>
void CheckHashTableClsAdrResize(uint &, uint &);

template <typename Data>
void CheckHashTableClsAdrClear(uint &, uint &);

template <typename Data>
void CheckHashTableOpnAdrExists(uint &, uint &);

template <typename Data>
void CheckHashTableOpnAdrResize(uint &, uint &);

template <typename Data>
void CheckHashTableOpnAdrClear(uint &, uint &);

/* ************************************************************************** */

// Check Test Functions Dictionary

template <typename Data>
void CheckHashTableClsAdrInsertCopy(uint &, uint &);

template <typename Data>
void CheckHashTableClsAdrInsertMove(uint &, uint &);

template <typename Data>
void CheckHashTableClsAdrRemove(uint &, uint &);

template <typename Data>
void CheckHashTableOpnAdrInsertCopy(uint &, uint &);

template <typename Data>
void CheckHashTableOpnAdrInsertMove(uint &, uint &);

template <typename Data>
void CheckHashTableOpnAdrRemove(uint &, uint &);

/* ************************************************************************** */

/* ************************************************************************** */

// Check Test Functions Dictionary

void CheckHashTableClsAdrInsertCopyString(uint &, uint &);

void CheckHashTableClsAdrInsertMoveString(uint &, uint &);

void CheckHashTableClsAdrRemoveString(uint &, uint &);

void CheckHashTableOpnAdrInsertCopyString(uint &, uint &);

void CheckHashTableOpnAdrInsertMoveString(uint &, uint &);

void CheckHashTableOpnAdrRemoveString(uint &, uint &);

/* ************************************************************************** */
/* ************************** EXERCISE 2 ************************************ */
/* ************************************************************************** */

// assignment test BinaryTreeLnk & BinaryTreeVec & BST
template <typename Data>
void CheckBinaryTreeLnkAssignment(uint &, uint &);

template <typename Data>
void CheckBinaryTreeLnkAssignmentCopy(BinaryTreeLnk<Data> &, uint &, uint &);

template <typename Data>
void CheckBinaryTreeLnkAssignmentMove(BinaryTreeLnk<Data> &, uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecAssignment(uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecAssignmentCopy(BinaryTreeVec<Data> &, uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecAssignmentMove(BinaryTreeVec<Data> &, uint &, uint &);

template <typename Data>
void CheckBSTAssignment(uint &, uint &);

template <typename Data>
void CheckBSTAssignmentCopy(BST<Data> &, uint &, uint &);

template <typename Data>
void CheckBSTAssignmentMove(BST<Data> &, uint &, uint &);

/* ************************************************************************** */

// compare test BinaryTree BinaryTreeLnk & BinaryTreeVec & BST
template <typename Data>
void CheckBinaryTreeCompare(uint &, uint &);

template <typename Data>
void CheckBTCompare(BinaryTree<Data> &, BinaryTree<Data> &, uint &, uint &);

template <typename Data>
void CheckBinaryTreeLnkCompare(BinaryTreeLnk<Data> &, BinaryTreeLnk<Data> &, uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecCompare(BinaryTreeVec<Data> &, BinaryTreeVec<Data> &, uint &, uint &);

template <typename Data>
void CheckBSTCompare(BST<Data> &, BST<Data> &, uint &, uint &);

/* ************************************************************************** */

// function test BinaryTreeLnk & NodeLnk

template <typename Data>
void CheckBinaryTreeLnkConstructors(uint &, uint &);

template <typename Data>
void CheckBinaryTreeLnkConstructorTraversable(uint &, uint &);

template <typename Data>
void CheckBinaryTreeLnkConstructorMappable(uint &, uint &);

template <typename Data>
void CheckBinaryTreeLnkConstructorCopy(uint &, uint &);

template <typename Data>
void CheckBinaryTreeLnkConstructorMove(uint &, uint &);

template <typename Data>
void CheckBinaryTreeLnkFunctionBase(uint &, uint &);

template <typename Data>
void CheckBinaryTreeLnkRoot(uint &, uint &);

template <typename Data>
void CheckBinaryTreeLnkMutableRoot(uint &, uint &);

template <typename Data>
void CheckBinaryTreeLnkClear(uint &, uint &);

template <typename Data>
void CheckBinaryTreeLnkNodeLnkFunction(uint &, uint &);

/* ******************************************************************************* */

// function test BinaryTreeVec & NodeVec

template <typename Data>
void CheckBinaryTreeVecConstructors(uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecConstructorTraversable(uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecConstructorMappable(uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecConstructorCopy(uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecConstructorMove(uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecFunctionBase(uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecRoot(uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecMutableRoot(uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecClear(uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecNodeVecFunction(uint &, uint &);

/* ******************************************************************************* */

// function test Node & MutableNode
template <typename Data>
void CheckBinaryTreeLnkIsLeaf(uint &, uint &);

template <typename Data>
void CheckBinaryTreeLnkHasLeftChild(uint &, uint &);

template <typename Data>
void CheckBinaryTreeLnkHasRightChild(uint &, uint &);

template <typename Data>
void CheckBinaryTreeLnkLeftChild(uint &, uint &);

template <typename Data>
void CheckBinaryTreeLnkRightChild(uint &, uint &);

template <typename Data>
void CheckBinaryTreeLnkMutableLeftChild(uint &, uint &);

template <typename Data>
void CheckBinaryTreeLnkMutableRightChild(uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecIsLeaf(uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecHasLeftChild(uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecHasRightChild(uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecLeftChild(uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecRightChild(uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecMutableLeftChild(uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecMutableRightChild(uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecFunctionTraverse(uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecTraverse(BinaryTreeVec<Data> &, uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecPreOrderTraverse(BinaryTreeVec<Data> &, uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecInOrderTraverse(BinaryTreeVec<Data> &, uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecPostOrderTraverse(BinaryTreeVec<Data> &, uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecBreadthTraverse(BinaryTreeVec<Data> &, uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecFunctionMap(uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecMap(BinaryTreeVec<Data> &, uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecFunctionFold(uint &, uint &);

template <typename Data>
void CheckBinaryTreeVecFold(BinaryTreeVec<Data> &, uint &, uint &);

/* ******************************************************************************* */

// function test BST

template <typename Data>
void CheckBSTConstructors(uint &, uint &);

template <typename Data>
void CheckBSTConstructorTraversable(uint &, uint &);

template <typename Data>
void CheckBSTConstructorMappable(uint &, uint &);

template <typename Data>
void CheckBSTConstructorCopy(uint &, uint &);

template <typename Data>
void CheckBSTConstructorMove(uint &, uint &);

template <typename Data>
void CheckBSTFunctionBase(uint &, uint &);

template <typename Data>
void CheckBSTRoot(uint &, uint &);

template <typename Data>
void CheckBSTClear(uint &, uint &);

template <typename Data>
void CheckBSTExists(uint &, uint &);

template <typename Data>
void CheckBSTMemberFunction(uint &, uint &);

template <typename Data>
void CheckBSTMin(uint &, uint &);

template <typename Data>
void CheckBSTMinNRemove(uint &, uint &);

template <typename Data>
void CheckBSTRemoveMin(uint &, uint &);

template <typename Data>
void CheckBSTMax(uint &, uint &);

template <typename Data>
void CheckBSTMaxNRemove(uint &, uint &);

template <typename Data>
void CheckBSTRemoveMax(uint &, uint &);

template <typename Data>
void CheckBSTPredecessor(uint &, uint &);

template <typename Data>
void CheckBSTPredecessorNRemove(uint &, uint &);

template <typename Data>
void CheckBSTRemovePredecessor(uint &, uint &);

template <typename Data>
void CheckBSTSuccessor(uint &, uint &);

template <typename Data>
void CheckBSTSuccessorNRemove(uint &, uint &);

template <typename Data>
void CheckBSTRemoveSuccessor(uint &, uint &);

template <typename Data>
void CheckBSTMemberFunctionDictionary(uint &, uint &);

template <typename Data>
void CheckBSTInsertCopy(uint &, uint &);

template <typename Data>
void CheckBSTInsertMove(uint &, uint &);

template <typename Data>
void CheckBSTRemove(uint &, uint &);

template <typename Data>
void CheckBSTFunctionTraverse(uint &, uint &);

template <typename Data>
void CheckBSTTraverse(BST<Data> &, uint &, uint &);

template <typename Data>
void CheckBSTPreOrderTraverse(BST<Data> &, uint &, uint &);

template <typename Data>
void CheckBSTInOrderTraverse(BST<Data> &, uint &, uint &);

template <typename Data>
void CheckBSTPostOrderTraverse(BST<Data> &, uint &, uint &);

template <typename Data>
void CheckBSTBreadthTraverse(BST<Data> &, uint &, uint &);

template <typename Data>
void CheckBSTFunctionMap(uint &, uint &);

template <typename Data>
void CheckBSTMap(BST<Data> &, uint &, uint &);

template <typename Data>
void CheckBSTPreOrderMap(BST<Data> &, uint &, uint &);

template <typename Data>
void CheckBSTInOrderMap(BST<Data> &, uint &, uint &);

template <typename Data>
void CheckBSTPostOrderMap(BST<Data> &, uint &, uint &);

template <typename Data>
void CheckBSTBreadthMap(BST<Data> &, uint &, uint &);

template <typename Data>
void CheckBSTFunctionFold(uint &, uint &);

template <typename Data>
void CheckBSTFold(BST<Data> &, uint &, uint &);

template <typename Data>
void CheckBSTPreOrderFold(BST<Data> &, uint &, uint &);

template <typename Data>
void CheckBSTInOrderFold(BST<Data> &, uint &, uint &);

template <typename Data>
void CheckBSTPostOrderFold(BST<Data> &, uint &, uint &);

template <typename Data>
void CheckBSTBreadthFold(BST<Data> &, uint &, uint &);

/* ************************************************************************** */

template <typename Data>
void CheckBTIterator(uint &, uint &);

template <typename Data>
void CheckBTPreIterator(BinaryTree<Data> &, uint &, uint &);

template <typename Data>
void CheckBTInIterator(BinaryTree<Data> &, uint &, uint &);

template <typename Data>
void CheckBTPostIterator(BinaryTree<Data> &, uint &, uint &);

template <typename Data>
void CheckBTBreadthIterator(BinaryTree<Data> &, uint &, uint &);

template <typename Data>
void CheckBTMutableIterator(uint &, uint &);

template <typename Data>
void CheckBTPreOrderMutableIterator(MutableBinaryTree<Data> &, uint &, uint &);

template <typename Data>
void CheckBTInOrderMutableIterator(MutableBinaryTree<Data> &, uint &, uint &);

template <typename Data>
void CheckBTPostOrderMutableIterator(MutableBinaryTree<Data> &, uint &, uint &);

template <typename Data>
void CheckBTBreadthMutableIterator(MutableBinaryTree<Data> &, uint &, uint &);

template <typename Data>
void CheckBTIteratorAssignment(uint &, uint &);

template <typename Data>
void CheckBTIteratorAssignmentCopy(BinaryTreeLnk<Data> &, uint &, uint &);

template <typename Data>
void CheckBTIteratorAssignmentMove(BinaryTreeLnk<Data> &, uint &, uint &);

template <typename Data>
void CheckBTIteratorConstructors(uint &, uint &);

/* ************************************************************************** */
/* ********************************************** OLD EXERCISE ************** */
/* ************************************************************************** */

// member function LinearContainer

template <typename Data>
void CheckFrontMutable(LinearContainer<Data> &, uint &, uint &);

template <typename Data>
void CheckFrontNotMutable(LinearContainer<Data> &, uint &, uint &);

template <typename Data>
void CheckBackMutable(LinearContainer<Data> &, uint &, uint &);

template <typename Data>
void CheckBackNotMutable(LinearContainer<Data> &, uint &, uint &);

template <typename Data>
void CheckFrontMutableVector(Vector<Data> &, uint &, uint &);

template <typename Data>
void CheckFrontNotMutableVector(Vector<Data> &, uint &, uint &);

template <typename Data>
void CheckBackMutableVector(Vector<Data> &, uint &, uint &);

template <typename Data>
void CheckBackNotMutableVector(Vector<Data> &, uint &, uint &);

template <typename Data>
void CheckFrontMutableList(List<Data> &, uint &, uint &);

template <typename Data>
void CheckFrontNotMutableList(List<Data> &, uint &, uint &);

template <typename Data>
void CheckBackMutableList(List<Data> &, uint &, uint &);

template <typename Data>
void CheckBackNotMutableList(List<Data> &, uint &, uint &);

/* ************************************************************************** */

// insert dat map function
template <typename Data>
void MyInsertData(Data &);

// insert string map function
template <typename Data>
void MyInsertStringData(string &);

// cout number total dat with fold
template <typename Data>
Data MyFoldCount(const Data &, const Data &);

template <typename Data>
void MyExistsData(const TraversableContainer<Data> &);

/* ************************************************************************** */

// Order Vector (copy constructor SortableVector -> Sort() -> copy Constructor Vector -> copy assignment in vec)
template <typename Data>
void MyOrderVector(Vector<Data> &);

// Order List (copy constructor SortableVector -> Sort() -> copy Constructor List -> copy assignment in lst)
template <typename Data>
void MyOrderList(List<Data> &);

// check order over with vector
template <typename Data>
bool CheckOrderOver(const LinearContainer<Data> &, uint &, uint &);

/* ************************************************************************** */

// Popular with map function
template <typename Data>
void PopularVectorData(Vector<Data> &, const uint &);

// Popular with map function vector of words
void PopularVectorString(Vector<string> &, const uint &);

template <typename Data>
void PopularDataList(List<Data> &, const uint &);

template <typename Data>
void PopularDataListString(List<Data> &, const uint &);

template <typename Data>
void PopularDataQueueLst(QueueLst<Data> &, const uint &);

template <typename Data>
void PopularDataQueueLstString(QueueLst<Data> &, const uint &);

template <typename Data>
void PopularDataQueueVec(QueueVec<Data> &, const uint &);

template <typename Data>
void PopularDataQueueVecString(QueueVec<Data> &, const uint &);

template <typename Data>
void PopularDataStackLst(StackLst<Data> &, const uint &);

template <typename Data>
void PopularDataStackLstString(StackLst<Data> &, const uint &);

template <typename Data>
void PopularDataStackVec(StackVec<Data> &, const uint &);

template <typename Data>
void PopularDataStackVecString(StackVec<Data> &, const uint &);

/* *************************************************************************** */

// Counter function with traverse
template <typename Data>
uint CounterDataLinearContainer(const LinearContainer<Data> &);

/* *************************************************************************** */

// Fold accumulation add
template <typename Data>
Data AccumulationDataLinearContainer(const LinearContainer<Data> &);

// Fold Counter Accumulation
template <typename Data>
Data CounterFoldLinearContainer(const LinearContainer<Data> &);

/* *************************************************************************** */

// Print Stack&Queue
template <typename Data>
void PrintStackLst(const StackLst<Data> &);

template <typename Data>
void PrintStackVec(const StackVec<Data> &);

template <typename Data>
void PrintQueueLst(const QueueLst<Data> &);

template <typename Data>
void PrintQueueVec(const QueueVec<Data> &);

/* *************************************************************************** */

// Check function LinearContainer

// check Size() + test traverse
template <typename Data>
void CheckSize(const LinearContainer<Data> &, uint &, uint &);

// check Empty()
template <typename Data>
void CheckEmpty(const LinearContainer<Data> &, uint &, uint &);

// check Clear() (copy vector constructor)
template <typename Data>
void CheckClear(const LinearContainer<Data> &, uint &, uint &n);

// check Comparison Linear Container
template <typename Data>
void CheckComparisonLinearContainer(const LinearContainer<Data> &, const LinearContainer<Data> &, uint &, uint &);

// check Comparison with copy & move constructor, copy & move assgnment
template <typename Data>
void CheckEqualsLinearContainer(const LinearContainer<Data> &, uint &, uint &);

template <typename Data>
void CheckExistsLinearContainer(uint &, uint &);

void CheckExistsLinearContainerString(uint &, uint &);

/* **************************************************************************** */

// check function vector

// check Resize() (Vector)
template <typename Data>
void CheckResize(const Vector<Data> &, uint &, uint &);

/* **************************************************************************** */

// check function member list

// check insertatfront
template <typename Data>
void CheckInserAtFront(List<Data> &, uint &, uint &);

// check insertatfrontmove
template <typename Data>
void CheckInserAtFrontMove(List<Data> &, uint &, uint &);

// check removefromfront
template <typename Data>
void CheckRemoveFromFront(List<Data> &, uint &, uint &);

// check frontnremove
template <typename Data>
void CheckFrontNRemove(List<Data> &, uint &, uint &);

// check insertatback
template <typename Data>
void CheckInserAtBack(List<Data> &, uint &, uint &);

// check insertatbackmove
template <typename Data>
void CheckInserAtBackMove(List<Data> &, uint &, uint &);

/* **************************************************************************** */

template <typename Data>
void CheckInsert(List<Data> &, uint &, uint &);

template <typename Data>
void CheckInsertMove(List<Data> &, uint &, uint &);

template <typename Data>
void CheckInsertAll(List<Data> &, uint &, uint &);

template <typename Data>
void CheckInsertAllMove(List<Data> &, uint &, uint &);

template <typename Data>
void CheckInsertSome(List<Data> &, uint &, uint &);

template <typename Data>
void CheckInsertSomeMove(List<Data> &, uint &, uint &);

template <typename Data>
void CheckRemove(List<Data> &, uint &, uint &);

template <typename Data>
void CheckRemoveAll(List<Data> &, uint &, uint &);

template <typename Data>
void CheckRemoveSome(List<Data> &, uint &, uint &);

/* **************************************************************************** */

// Check member function StackLst & StackVec
template <typename Data>
void CheckTopNotMutableStackList(StackLst<Data> &, uint &, uint &);

template <typename Data>
void CheckTopMutableStackList(StackLst<Data> &, uint &, uint &);

template <typename Data>
void CheckPopStackList(StackLst<Data> &, uint &, uint &);

template <typename Data>
void CheckTopNPopStackList(StackLst<Data> &, uint &, uint &);

template <typename Data>
void CheckPushStackList(StackLst<Data> &, uint &, uint &);

template <typename Data>
void CheckPushMoveStackList(StackLst<Data> &, uint &, uint &);

template <typename Data>
void CheckTopNotMutableStackVec(StackVec<Data> &, uint &, uint &);

template <typename Data>
void CheckTopMutableStackVec(StackVec<Data> &, uint &, uint &);

template <typename Data>
void CheckPopStackVec(StackVec<Data> &, uint &, uint &);

template <typename Data>
void CheckTopNPopStackVec(StackVec<Data> &, uint &, uint &);

template <typename Data>
void CheckPushStackVec(StackVec<Data> &, uint &, uint &);

template <typename Data>
void CheckPushMoveStackVec(StackVec<Data> &, uint &, uint &);

/* **************************************************************************** */

// Check member function QueueLst & QueueVec
template <typename Data>
void CheckHeadNotMutableQueueList(QueueLst<Data> &, uint &, uint &);

template <typename Data>
void CheckHeadMutableQueueList(QueueLst<Data> &, uint &, uint &);

template <typename Data>
void CheckDequeueQueueList(QueueLst<Data> &, uint &, uint &);

template <typename Data>
void CheckHeadNDequeueQueueList(QueueLst<Data> &, uint &, uint &);

template <typename Data>
void CheckEnqueueQueueList(QueueLst<Data> &, uint &, uint &);

template <typename Data>
void CheckEnqueueMoveQueueList(QueueLst<Data> &, uint &, uint &);

template <typename Data>
void CheckHeadNotMutableQueueVec(QueueVec<Data> &, uint &, uint &);

template <typename Data>
void CheckHeadMutableQueueVec(QueueVec<Data> &, uint &, uint &);

template <typename Data>
void CheckDequeueQueueVec(QueueVec<Data> &, uint &, uint &);

template <typename Data>
void CheckHeadNDequeueQueueVec(QueueVec<Data> &, uint &, uint &);

template <typename Data>
void CheckEnqueueQueueVec(QueueVec<Data> &, uint &, uint &);

template <typename Data>
void CheckEnqueueMoveQueueVec(QueueVec<Data> &, uint &, uint &);

/* **************************************************************************** */

// Check member function QueueLst & QueueVec for String type
void CheckHeadNotMutableQueueListString(QueueLst<string> &, uint &, uint &);

void CheckHeadMutableQueueListString(QueueLst<string> &, uint &, uint &);

void CheckDequeueQueueListString(QueueLst<string> &, uint &, uint &);

void CheckHeadNDequeueQueueListString(QueueLst<string> &, uint &, uint &);

void CheckEnqueueQueueListString(QueueLst<string> &, uint &, uint &);

void CheckEnqueueMoveQueueListString(QueueLst<string> &, uint &, uint &);

void CheckHeadNotMutableQueueVecString(QueueVec<string> &, uint &, uint &);

void CheckHeadMutableQueueVecString(QueueVec<string> &, uint &, uint &);

void CheckDequeueQueueVecString(QueueVec<string> &, uint &, uint &);

void CheckHeadNDequeueQueueVecString(QueueVec<string> &, uint &, uint &);

void CheckEnqueueQueueVecString(QueueVec<string> &, uint &, uint &);

void CheckEnqueueMoveQueueVecString(QueueVec<string> &, uint &, uint &);

/* **************************************************************************** */

// Group Test call function check

template <typename Data>
void TestCheckFuctionContainer(uint &, uint &);

template <typename Data>
void TestCheckMemberFuctionList(List<Data> &, uint &, uint &);

template <typename Data>
void TestCheckMemberFunctionLinearContainer(uint &, uint &);

template <typename Data>
void TestCheckMemberFunctionDictionary(uint &, uint &);

template <typename Data>
void TestCheckMemberFunctionStack(uint &, uint &);

template <typename Data>
void TestCheckMemberFunctionQueue(uint &, uint &);

void TestCheckMemberFunctionQueueString(uint &, uint &);

/*******************************************************************************/

// Auxiliar add

template <typename Data>
Data FoldTotal(const Data &dat, const Data &acc)
{
    return (acc + dat);
}

#endif
