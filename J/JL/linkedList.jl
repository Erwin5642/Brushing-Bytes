module MyDataStructures

export LinkedList, Node, push!, pop!, show

const null = nothing

mutable struct Node{T}
    data::T
    prev::Union{Node{T},Nothing}
    next::Union{Node{T},Nothing}
end

mutable struct LinkedList{T}
    head::Union{Nothing,Node{T}}
    tail::Union{Nothing,Node{T}}
end

LinkedList{T}() where {T} = LinkedList{T}(null, null)

function Base.push!(ll::LinkedList{T}, el::T) where {T}
    if ll.head === ll.tail === null
        ll.head = ll.tail = Node{T}(el, null, null)
    else
        ll.tail.next = Node{T}(el, null, null)
        ll.tail.next.prev = ll.tail
        ll.tail = ll.tail.next
    end
    ll.n += 1
    ll
end

function Base.pop!(ll::LinkedList{T}) where {T}
    ll.n == 0 && throw(ArgumentError("LinkedList must be non-empty"))
    el = ll.tail.el
    ll.tail = ll.tail.prev
    ll.n -= 1
    ll.n == 0 && (ll.head = null)
    el
end

Base.length(ll::LinkedList{T}) where {T} = ll.n

function Base.iterate(ll::LinkedList{T}, node::Union{Node{T},Nothing}=ll.head) where {T}
    node === null ? null : (node.el, node.next)
end

function Base.show(io::IO, ll::LinkedList)
    for el in ll
        print(el, " ")
    end
end

end