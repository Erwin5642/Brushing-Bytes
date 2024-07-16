function isPrime(x::Int64)::Bool
    if x == 0 || x == 1
        return false
    end

    if x == 2 
        return true
    end

    if x % 2 == 0
        return false    
    end

    for i = 3:2:sqrt(x)
        if x == i 
            return true
        end
        if x % i == 0
            return false
        end
    end
    return true
end

resultado::Bool = isPrime(parse(Int64, readline())) 
resultado ? println("O numero é primo") : println("O numero não é primo")