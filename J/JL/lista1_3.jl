function fatorial(x::Int64)::BigInt
    f = 1
    while x > 0
        f = f * x
        x = x - 1
    end
    return f
end

println(fatorial(parse(Int64, readline())))
