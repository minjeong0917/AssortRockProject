#pragma once
#include <assert.h>


typedef int DataType;

// �ߴ����̳� ������Ҷ� �׳� �ڷ����� 
// ������ �ִ°��� ���Ⱑ �� ���ؼ� �̹���� ���� ����ߴ�.
// template<typename DataType>
class UList
{
public:
    class UListNode
    {
        // friend UList;
        // friend iterator;

    public:
        UListNode* Prev = nullptr;
        UListNode* Next = nullptr;
        DataType Data;
    };

public:
    // ��ȸ�ڶ�� Ŭ������ ���ؼ� 
    class iterator
    {
        friend UList;

    public:
        iterator()
        {

        }

        bool operator!=(const iterator& _Other)
        {
            return CurNode != _Other.CurNode;
        }

        // * ��¥ ���ϱ�ε� ����Ҽ� �ִ�.
        DataType& operator*()
        {
            return CurNode->Data;
        }

        iterator& operator++()
        {
            CurNode = CurNode->Next;
            return *this;
        }

        DataType& GetValue()
        {
            return CurNode->Data;
        }

    private:
        // ��尡 �����Ѵٴ°��� �ܺο� �˸��� ���� �ʴ�.
        iterator(UListNode* _Node)
            : CurNode(_Node)
        {

        }

        // 
        // 3000����
        UListNode* CurNode = nullptr;
    };

public:
    UList()
    {
        // ���̳���� �մϴ�.
        StartNode = new UListNode();
        EndNode = new UListNode();
        StartNode->Data = -1;
        EndNode->Data = -1;

        StartNode->Next = EndNode;
        EndNode->Prev = StartNode;
    }

    ~UList()
    {
        DeleteNew();

        if (nullptr != StartNode)
        {
            delete StartNode;
            StartNode = nullptr;
        }

        if (nullptr != EndNode)
        {
            delete EndNode;
            EndNode = nullptr;
        }
    }

    // �ڷᱸ�� 3����
    // => List Vector Map
    // 
    // push_back�� �������Լ�
    void push_front(const DataType& _Data)
    {
        // ��Ȯ�ϰ� �ٽ� �������� ����������
        // �׷����鼭 Ȯ���غ�����.
        UListNode* ListNode = new UListNode();
        ListNode->Data = _Data;

        // ������� �� ����������
        ListNode->Prev = StartNode;
        ListNode->Next = StartNode->Next;

        // �̳༮�� ���� �Ǹ� 
        StartNode->Next->Prev = ListNode;
        StartNode->Next = ListNode;
    }

    void push_back(const DataType& _Data)
    {
        UListNode* ListNode = new UListNode();
        ListNode->Data = _Data;

        ListNode->Next = EndNode;
        ListNode->Prev = EndNode->Prev;

        // �̳༮�� ���� �Ǹ� 
        EndNode->Prev->Next = ListNode;
        EndNode->Prev = ListNode;
    }

    iterator erase(iterator& _Data)
    {
        UListNode* CurNode = _Data.CurNode;
        if (CurNode == nullptr)
        {
            assert(false);
            return iterator();
        }

        if (CurNode == StartNode)
        {
            assert(false);
            return iterator();
        }

        // C++
        if (CurNode == EndNode)
        {
            assert(false);
            return iterator();
        }

        UListNode* ReturnNode = CurNode->Next;

        CurNode->Prev->Next = CurNode->Next;
        CurNode->Next->Prev = CurNode->Prev;

        delete CurNode;
        CurNode = nullptr;

        return iterator(ReturnNode);
    }

    iterator begin()
    {
        return iterator(StartNode->Next);
    }

    iterator end()
    {
        return iterator(EndNode);
    }


    iterator DeleteNew()
    {
        UListNode* CurNode = StartNode->Next;
        if (CurNode == nullptr)
        {
            assert(false);
            return iterator();
        }

        if (CurNode == StartNode)
        {
            assert(false);
            return iterator();
        }

        // C++
        if (CurNode == EndNode)
        {
            assert(false);
            return iterator();
        }

        while (CurNode != EndNode)
        {
            UListNode* ReturnNode = CurNode->Next;
            if (nullptr != CurNode)
            {
                delete CurNode;
                CurNode = nullptr;
            }
            CurNode = ReturnNode;
        }
    }

private:
    UListNode* StartNode = nullptr;
    UListNode* EndNode = nullptr;

};

