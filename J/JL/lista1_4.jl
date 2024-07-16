function fibonacci(x::Int64)::BigInt
    f = 1
    aux = 1
    while x > 1
        f = f + aux 
        aux = f - aux
        x = x - 1 
    end
    return f
end

println(fibonacci(parse(Int64, readline())))
