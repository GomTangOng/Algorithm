#include "RingBuffer.h"



CRingBuffer::CRingBuffer()
{
	m_pQueue = new char[MAX_QUEUE_SIZE];
	ZeroMemory(&m_pQueue[0], MAX_QUEUE_SIZE);

	m_head = m_tail = 0;

	m_nEmptySize   = m_nTotalSize = MAX_QUEUE_SIZE;
	m_nCurrentSize = 0;
}


CRingBuffer::~CRingBuffer()
{
	delete[] m_pQueue;
	m_pQueue = nullptr;
}

int CRingBuffer::Enqueue(char * pBuf, const int nSize)
{
	if (IsFull()) return -1;

	for (int i = 0; i < nSize; ++i)
	{
		*(m_pQueue + m_tail) = *(pBuf + i);
		m_tail = ( m_tail + 1 ) % MAX_QUEUE_SIZE;
	}
	m_nCurrentSize += nSize;
	m_nEmptySize   -= nSize;

	return nSize;
}

int CRingBuffer::Dequeue(char * pOut, const int nSize)
{
	if (IsEmpty()) return -1;

	for (int i = 0; i < nSize; ++i)
	{
		*(pOut + i) = *(m_pQueue + m_head);
		*(m_pQueue + m_head) = 0;
		m_head = (m_head + 1) % MAX_QUEUE_SIZE;
	}
	
	m_nCurrentSize -= nSize;
	m_nEmptySize   += nSize;

	return nSize;
}

void CRingBuffer::ReSize()
{
	// Note : �ϴ��� ����X... ����ũ�⸦ �ִ�� Ű����
	//		  ReSize�� ���� �ʰ� ������ -> ���� Copy Overhead�� ������ ����
}

void CRingBuffer::Clear()
{
	ZeroMemory(&m_pQueue[0], MAX_QUEUE_SIZE);
	m_nCurrentSize = 0;
	m_nEmptySize = m_nTotalSize = MAX_QUEUE_SIZE;	// Warning : ReSize�� �����ϰ� �Ǹ� �� �ڵ� �����ؾ��Ѵ�.
}

bool CRingBuffer::IsPacket()
{
	if (m_pQueue[0] < m_nCurrentSize) return false;

	return true;
}

bool CRingBuffer::IsFull()
{
	if (!m_nEmptySize) return true;
	return false;
}

bool CRingBuffer::IsEmpty()
{
	if (m_nEmptySize) return true;
	return false;
}
