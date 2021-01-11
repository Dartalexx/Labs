#include "List.h"
Node::Node()
{
    next = nullptr;
}
Node::Node(const Complex& b)
{
    next = nullptr;
    data = b;
}
Node::Node(const child& b)
{
    next = nullptr;
    data = b;
}
